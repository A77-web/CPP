#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	//n：歌曲数
	int n = 0;
	//s：执行的up/down操作
	string s;
	while (cin >> n >> s)
	{
		//index光标
		int index = 1;
		//歌曲数小于5表示所有歌曲在同一页
		//最后打印列表的时候就打印1-n
		if (n < 5)
		{
			for (int i = 0; i < s.size(); i++)
			{
				//如果光标在1执行U操作
				if (index == 1 && s[i] == 'U')
					index = n;
				else if (s[i] == 'U')
					index--;
				//光标在n执行D操作
				else if (index == n && s[i] == 'D')
					index = 1;
				else if (s[i] == 'D')
					index++;
			}
			//打印列表
			for (int i = 0; i < n - 1; i++)
				cout << i + 1 << " ";
			cout << n << endl;
			cout << index << endl;
		}
		else
		{
			//如果歌曲数大于等于5
			//table表示歌曲列表
			vector<int> table(4);
			//最开始是1234
			for (int i = 0; i < 4; i++)
				table[i] = i + 1;
			for (int i = 0; i < s.size(); i++)
			{
				//光标在1执行up操作，先修改光标位置，在修改列表
				if (index == 1 && s[i] == 'U')
				{
					index = n;
					for (int i = 0; i < s.size(); i++)
						table[3 - i] = n - i;
				}
				//在同一个列表中up
				else if (s[i] == 'U')
				{
					if (index == table[0])
					{
						for (int i = 0; i < 4; i++)
							table[i] -= 1;
					}
					index--;
				}
				else if (index == n && s[i] == 'D')
				{
					index = 1;
					for (int i = 0; i < 4; i++)
						table[i] +=  1;
				}
				else if (s[i] == 'D')
				{
					if (index == table[3])
					{
						//修改table里的数字
						for (int i = 0; i < 4; i++)
						{
							table[i] += 1;
						}
					}
					index++;
				}
			}
			for (int i = 0; i < 3; i++)
				cout << table[i] << " ";
			cout << table[3] << endl;
			// 打印光标
			cout << index << endl;
		}
	}

	return 0;
}