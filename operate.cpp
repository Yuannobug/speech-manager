#include"operator.h"


void operate:: menu()
{
	cout << "——————————————" << endl;
	cout << "——— 演  讲  比  赛 ———" << endl;
	cout << "—    1.  开始演讲比赛    —" << endl;
	cout << "—    2.  查看往届纪录    —" << endl;
	cout << "—    3.  清空往届记录    —" << endl;
	cout << "—    0.  退出演讲比赛    —" << endl;
	cout << "—      请输入您的选择    —" << endl;
}

void create(vector<competitor>& v)
{
	int i = 0; 
	int uid = 10001; 
	string name1 = "选手"; string name2 = "ABCDEFGHIJKL";
	for (i = 0; i < 12; i++)
	{
		name1 = "选手";
		name1 += name2[i];
		competitor com(uid + i, name1, 60.0);
		v.push_back(com);
	}
}

float makescore()
{
	int i = 0; int score = 0;
	deque<float>scorev;
	for (i = 0; i < 10; i++)
	{
		score = rand()%41;
		scorev.push_back(score);
	}
	sort(scorev.begin(), scorev.end());
	scorev.pop_back();
	scorev.pop_front();
	float scoreave=accumulate(scorev.begin(), scorev.end(), 0)/8.0;
	return scoreave;
}

void creatscore(vector<competitor>& v,int choice)
{
	float score = 0; int i = 0;
	if (choice == 1)
	{
		for (i = 0; i < 12; i++)
		{
			score = makescore();
			v[i].m_score += score;
		}
	}
	else
	{
		for (i = 0; i < 6; i++)
		{
			score =60.0+ makescore();
			v[i].m_score = score;
		}
	}
}

void showsequence(vector<competitor> v)
{
	int i = 0;
	for (i = 0; i < 12; i++)
	{
		cout << v[i].m_uid << "  ";
	}
	cout << endl;
}

void showscore(vector<competitor> v, int choice)
{
	int i = 0;
	if (choice == 1)
	{
		for (i = 0; i < 6; i++)
		{
			cout << v[i].m_uid << "  " << v[i].m_name << "  " << v[i].m_score << endl;
		}
	}
	else
	{
		for (i = 6; i < 12; i++)
		{
			cout << v[i].m_uid << "  " << v[i].m_name << "  " << v[i].m_score << endl;
		}
	}
}

void mycopy(vector<competitor> v, vector<competitor>& laterv,int choice)
{
	int i = 0;
	if (choice == 1)
	{
		for (i = 0; i < 3; i++)
		{
			competitor temp(v[i].m_uid, v[i].m_name, v[i].m_score);
			laterv.push_back(temp);
		}
		for (i = 6; i < 9; i++)
		{
			competitor temp(v[i].m_uid, v[i].m_name, v[i].m_score);
			laterv.push_back(temp);
		}
	}
	else
	{
		for (i = 0; i < 3; i++)
		{
			competitor temp(v[i].m_uid, v[i].m_name, v[i].m_score);
			laterv.push_back(temp);
		}
	}
}

void preserve(vector<competitor>& vectory)
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	vector<competitor>::iterator it = vectory.begin();
	for (it = vectory.begin(); it != vectory.end(); it++)
	{
		ofs << it->m_uid << "," << it->m_name << "," << it->m_score << ",";
	}
	ofs << endl;
	ofs.close();
}

void operate::begin()//开始比赛
{
	vector<competitor>v;
	vector<competitor>laterv;
	vector<competitor>vectory;
	create(v);
	cout << "第一轮选手正在抽签" << endl;
	random_shuffle(v.begin(), v.end());
	showsequence(v);
	cout << "————————————" << endl;
	system("pause");
	cout << "—— 第一轮比赛开始 ——" << endl;
	creatscore(v,1);
	system("pause");
	cout << "第一小组比赛名次如下：" << endl;
	sort(v.begin(), v.begin()+6,mycompare());
	showscore(v,1);
	system("pause");
	cout << "第二小组比赛名次如下：" << endl;
	sort(v.begin()+6, v.end(), mycompare());
	showscore(v, 2);
	system("pause");
	cout << "—— 第一轮比赛结束 ——" << endl;
	mycopy(v, laterv,1);
	cout << "——    晋级选手    ——" << endl;
	showscore(laterv, 1);
	cout << "————————————" << endl;
	cout << "—— 第二轮比赛开始 ——" << endl;
	creatscore(laterv,2);
	sort(laterv.begin() , laterv.end(), mycompare());
	system("pause");
	cout << "—— 第二轮比赛结束 ——" << endl;
	system("pause");
	cout << "——    比赛结果    ——" << endl;
	showscore(laterv, 1);
	system("pause");
	mycopy( laterv,vectory,2);
	cout << "——    比赛结束    ——" << endl;
	cout << "冠军" <<vectory[0].m_name<< endl;
	cout << "亚军" << vectory[1].m_name<< endl;
	cout << "季军" << vectory[2].m_name<< endl;
	v.clear();
	laterv.clear();
	preserve(vectory);
	cout << "记录保存成功" << endl;
	vectory.clear();
	system("pause");
	system("cls");
}

void operate::showhistory()
{
	vector<history>::iterator it = m_history.begin();
	for (it = m_history.begin(); it != m_history.end(); it++)
	{
		cout << "第" << it->m_index << "届冠军为" <<it->history_uid<<"  "<< it->history_name << "分数：" << it->history_score << endl;
		it++;
		cout << "第" << it->m_index << "届亚军为" << it->history_uid << "  " << it->history_name << "分数：" << it->history_score << endl;
		it++;
		cout << "第" << it->m_index << "届季军为" << it->history_uid << "  " << it->history_name << "分数：" << it->history_score << endl;
	}

}

void operate::scan()//查看往届
{
	ifstream ifs;
	ifs.open("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		cout << "历史记录不存在" << endl;
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "历史记录为空" << endl;
		return;
	}
	ifs.close();
	ifstream ifs1;
	ifs1.open("speech.csv", ios::in);
	string buf;
	string temp;
	int begin = 0; int j = 0;
	int judge = 0;int index = 0;
	history temphistory;
	while (ifs1 >> buf)
	{
		begin = 0;
		index++;
		for (j = 0; j < 3; j++)
		{
			judge = buf.find(',', begin);
			temphistory.history_uid = buf.substr(begin, judge - begin);
			begin = judge + 1;
			judge = buf.find(',', begin);
			temphistory.history_name = buf.substr(begin, judge - begin);
			begin = judge + 1;
			judge = buf.find(',', begin);
			temphistory.history_score = buf.substr(begin, judge - begin);
			begin = judge + 1;
			temphistory.m_index = index;
			m_history.push_back(temphistory);
		}
	}
	ifs.close();
	showhistory();
}

void operate::clean()//清空
{
	if (m_history.size() == 0)
	{
		cout << "历史数据不存在！" << endl;
		return;
	}
	int choice = 0;
	cout << "请确认是否清空" << endl;
	cout << "1.清除  0.取消" << endl;
	cin >> choice;
	while (choice != 1 && choice != 0)
	{
		cout << "输入不合理，请重新输入" << endl;
		cin >> choice;
	}
	if (choice)
	{
		ofstream ofs;
		ofs.open("speech.csv", ios::trunc);
		ofs.close();
		m_history.clear();
		cout << "清除成功"<<endl;
	}
}