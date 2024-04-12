#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
#include"list.h"//list必须放在这，list.h中有需要以上头文件的地方，不改变其它代码的前提下放在上面几行会报错

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