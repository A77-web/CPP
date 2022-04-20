#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string A, B;
    while(cin >> A >> B)
    {
        map<char, int> AA, BB;
        for (int i = 0; i < A.size(); i++)
        {
            AA[A[i]]++;
        }
        for (int i = 0; i < B.size(); i++)
        {
            BB[B[i]]++;
        }
        for (int i = 'A'; i <= 'Z'; i++)
        {
            if (BB[i] > AA[i])
            {
                cout << "No" << endl;
                break;
            }
            if (i == 'Z')
            {
                cout << "Yes" << endl;
            }
        }

    }
}
