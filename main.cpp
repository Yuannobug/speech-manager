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
		case 0:cout << "��ӭ�´�ʹ��" << endl; break;
		case 1:op.begin(); break;
		case 2:op.scan(); break;
		case 3:op.clean(); break;
		default:cout << "���뷽ʽ����������������" << endl;
		}

	}
	system("pause");
	return 0;
}

