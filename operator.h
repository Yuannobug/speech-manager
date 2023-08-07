#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include"player.h"
#include<ctime>
#include<algorithm>
#include<deque>
#include<numeric>
#include<fstream>

class history
{
public:
	int m_index;
	string history_uid;
	string history_name;
	string history_score;
};

class mycompare
{
public:
	bool operator()(const competitor com1, const competitor com2)
	{
		return com1.m_score>com2.m_score;
	}
};


class operate
{
public:
	void menu();//菜单
	void begin();//开始比赛
	void scan();//查看往届
	void clean();//清空
	void showhistory();
	vector<history> m_history;
};

