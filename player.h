#pragma once
#include<iostream>
using namespace std;

#include<string>

class competitor
{
public:
	competitor(int uid,string name,float score);
	int m_uid;
	string m_name;
	float m_score;
};
