#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	//n��������
	int n = 0;
	//s��ִ�е�up/down����
	string s;
	while (cin >> n >> s)
	{
		//index���
		int index = 1;
		//������С��5��ʾ���и�����ͬһҳ
		//����ӡ�б��ʱ��ʹ�ӡ1-n
		if (n < 5)
		{
			for (int i = 0; i < s.size(); i++)
			{
				//��������1ִ��U����
				if (index == 1 && s[i] == 'U')
					index = n;
				else if (s[i] == 'U')
					index--;
				//�����nִ��D����
				else if (index == n && s[i] == 'D')
					index = 1;
				else if (s[i] == 'D')
					index++;
			}
			//��ӡ�б�
			for (int i = 0; i < n - 1; i++)
				cout << i + 1 << " ";
			cout << n << endl;
			cout << index << endl;
		}
		else
		{
			//������������ڵ���5
			//table��ʾ�����б�
			vector<int> table(4);
			//�ʼ��1234
			for (int i = 0; i < 4; i++)
				table[i] = i + 1;
			for (int i = 0; i < s.size(); i++)
			{
				//�����1ִ��up���������޸Ĺ��λ�ã����޸��б�
				if (index == 1 && s[i] == 'U')
				{
					index = n;
					for (int i = 0; i < s.size(); i++)
						table[3 - i] = n - i;
				}
				//��ͬһ���б���up
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
						//�޸�table�������
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
			// ��ӡ���
			cout << index << endl;
		}
	}

	return 0;
}