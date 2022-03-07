#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string str;
    while (getline(cin, str)) {
        bool flag = false;
        vector<string> vec;
        string row;
        for (int i = 0; i < str.size(); i++) {
            if (flag) {//在括号内
                if (str[i] != '\"') row += str[i];
                else flag = false;
            } else {
                if (str[i] == ' ') {
                    vec.push_back(row);
                    row = "";
                } else if (str[i] == '\"') flag = true;
                else row += str[i];
            }
        }
        vec.push_back(row);
        cout << vec.size() << endl;
        for (auto i : vec) cout << i << endl;
    }
    return 0;
}
