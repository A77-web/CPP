#ifndef __MY_SERVER__
#define __MY_SERVER__ 
#include "data.hpp"
#include "httplib.h"
#include  <sstream>
extern cloud::DataManager *_data;

namespace cloud 
{
  class Server 
  {
    private:
      int _srv_port=9090;//服务器的绑定监听端口
      std::string _url_prefix="/download/";
      std::string _backup_dir="./backup_dir/";//上传文件的备份存储路径
      httplib::Server _srv;
    private:
      static void Upload(const httplib::Request &req,httplib::Response &rsp)
      {
        std::string _backup_dir="./backup_dir/";//上传文件的备份存储路径
        std::cout<<req.path<<std::endl;
        //判断有没有对应标识的文件上传区域数据
        if(req.has_file("file")==false)
        {
          //判断有没有name字段值是file的标识区域
          std::cout<<"upload file data format error!\n";
          rsp.status=400;
          return;
        }
        //获取解析后的区域数据
        httplib::MultipartFormData data=req.get_file_value("file");
        //组织文件的实际储存路径名
        std::string realpath=_backup_dir+data.filename;
        //向文件中写入数据，实际上就是把文件备份起来了
        std::cout<<realpath<<std::endl;
        if(FileUtil(realpath).Write(data.content)==false)
        {
          std::cout<<"back file failed!\n";
          rsp.status=500;
          return;
        }
        //新增备份信息
        if(_data->Insert(realpath)==false)
        {
          std::cout<<"insert back info failed!\n";
          rsp.status=500;
          return;
        }
        rsp.status=200;
        std::cout<<"new backup:"<<realpath<<std::endl;
        return;
      }
      static std::string StrTime(time_t t)
      {
        return std::asctime(std::localtime(&t));
      }
      static void List(const httplib::Request &req,httplib::Response &rsp)
      {
        //获取所有历史备份信息，并且根据这些信息组织出来一个html页面，作为响应正文
        std::vector<FileInfo> arry;
        if(_data->SelectAll(&arry)==false)
        {
          std::cout<<"SelectAll back info failed!\n";
          rsp.status=500;
          return;
        }
        std::stringstream ss;
        ss<<"<html>";
        ss<<  "<head>";
        ss<<      "<meta http-equiv='Content-type' contect='text/html;charset=utf-8'>";
        ss<<      "<title>Download</title>";
        ss<<  "</head>";
        ss<<  "<body>";
        ss<<      "<h1>Download<h1>";
        ss<<      "<table>";
        for(auto a : arry)
        {
          //组织每一行的页面标签
          ss<<        "<tr>";
          ss<<             "<td><a href='"<<a.url_path<<"'>"<<a.filename<<"</a></td>";
          ss<<             "<td align='right'>"<<StrTime(a.back_time)<<"</td>";
          ss<<             "<td align='right'>"<<a.file_size/1024<<"KB</td>";
          ss<<        "</tr>";
        }
        ss<<      "</table>";
        ss<<  "</body>";
        ss<<"</html>";
        rsp.set_content(ss.str(),"text/html");
        rsp.status=200;
        return;
      }
      static std::string StrETag(const std::string &filename)
      {
        //etag是一个文件的唯一标识，当文件修改时则会改变
        //这里etag不用计算 ：文件大小+最后一次修改时间
        time_t mtime=FileUtil(filename).Mtime();
        size_t fsize=FileUtil(filename).Size();
        std::stringstream ss;
        ss<<fsize<<"-"<<mtime;
        return ss.str();
      }
      static void Download(const httplib::Request &req,httplib::Response &rsp)
      {
        std::cout<<req.path<<std::endl;
        FileInfo info;
        if(_data->SelectOne(req.path,&info)==false)
        {
          std::cout<<"select one back info failed!\n";
          rsp.status=404;
          return;
        }
        //如果文件已经被压缩了，则要先解压缩，然后再去源文件读取数据
        if(info.pack_flag==true)
        {
          FileUtil(info.pack_path).UnCompress(info.real_path);
        }
        if(req.has_header("If-Range"))
        {
          std::string old_etag=req.get_header_value("If-Range");//If-Range:ETag信息
          std::string cur_etag=StrETag(info.real_path);
          if(old_etag==cur_etag)
          {
            //文件没有改变，可以断点续传
            FileUtil(info.real_path).Read(&rsp.body);
            rsp.set_header("Content-Type","application/octet-stream");//设置正文类型为二进制流
            rsp.set_header("Accept-Ranges","bytes");//告诉客户端我们的服务器支持断点续传
            rsp.set_header("ETag",cur_etag);
            return;
          }
        }
        FileUtil(info.real_path).Read(&rsp.body);
        rsp.set_header("Content-Type","application/octet-stream");//设置正文类型为二进制流
        rsp.set_header("Accept-Ranges","bytes");//告诉客户端我们的服务器支持断点续传
        rsp.set_header("ETag",StrETag(info.real_path));
        rsp.status=200;
        return;
      }
    public:
      Server()
      {
        FileUtil(_backup_dir).CreateDirectory();
      }
      bool RunModule()
      {
        //搭建http服务器
        //建立请求-处理函数映射关系
        //Post（请求的资源路径，对应的业务处理回调函数）
        _srv.Post("/upload",Upload);
        _srv.Get("/list",List);
        std::string regex_download_path=_url_prefix+"(.*)";
        std::cout<<regex_download_path<<std::endl;
        _srv.Get(regex_download_path,Download);
        //启动服务器
        _srv.listen("0.0.0.0",_srv_port);
        return true;
      }
  };
}






#endif
