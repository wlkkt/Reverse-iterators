#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
#include"list.h"//list��������⣬list.h������Ҫ����ͷ�ļ��ĵط������ı����������ǰ���·������漸�лᱨ��

int main()
{
	bit::list<int> lt = { 1,2,3,4 };
	bit::list<int>::reverse_iterator rit = lt.rbegin();
	while (rit != lt.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	return 0;
}