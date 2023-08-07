#include<iostream>
using namespace std;

#include"operator.h"



int main()
{
	srand((unsigned char)time(NULL));
	operate op;
	int choice = 1;
	while (choice)
	{
		op.menu();
		cin >> choice;
		switch (choice)
		{
		case 0:cout << "欢迎下次使用" << endl; break;
		case 1:op.begin(); break;
		case 2:op.scan(); break;
		case 3:op.clean(); break;
		default:cout << "输入方式不合理，请重新输入" << endl;
		}

	}
	system("pause");
	return 0;
}

