#include"operator.h"


void operate:: menu()
{
	cout << "����������������������������" << endl;
	cout << "������ ��  ��  ��  �� ������" << endl;
	cout << "��    1.  ��ʼ�ݽ�����    ��" << endl;
	cout << "��    2.  �鿴�����¼    ��" << endl;
	cout << "��    3.  ��������¼    ��" << endl;
	cout << "��    0.  �˳��ݽ�����    ��" << endl;
	cout << "��      ����������ѡ��    ��" << endl;
}

void create(vector<competitor>& v)
{
	int i = 0; 
	int uid = 10001; 
	string name1 = "ѡ��"; string name2 = "ABCDEFGHIJKL";
	for (i = 0; i < 12; i++)
	{
		name1 = "ѡ��";
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

void operate::begin()//��ʼ����
{
	vector<competitor>v;
	vector<competitor>laterv;
	vector<competitor>vectory;
	create(v);
	cout << "��һ��ѡ�����ڳ�ǩ" << endl;
	random_shuffle(v.begin(), v.end());
	showsequence(v);
	cout << "������������������������" << endl;
	system("pause");
	cout << "���� ��һ�ֱ�����ʼ ����" << endl;
	creatscore(v,1);
	system("pause");
	cout << "��һС������������£�" << endl;
	sort(v.begin(), v.begin()+6,mycompare());
	showscore(v,1);
	system("pause");
	cout << "�ڶ�С������������£�" << endl;
	sort(v.begin()+6, v.end(), mycompare());
	showscore(v, 2);
	system("pause");
	cout << "���� ��һ�ֱ������� ����" << endl;
	mycopy(v, laterv,1);
	cout << "����    ����ѡ��    ����" << endl;
	showscore(laterv, 1);
	cout << "������������������������" << endl;
	cout << "���� �ڶ��ֱ�����ʼ ����" << endl;
	creatscore(laterv,2);
	sort(laterv.begin() , laterv.end(), mycompare());
	system("pause");
	cout << "���� �ڶ��ֱ������� ����" << endl;
	system("pause");
	cout << "����    �������    ����" << endl;
	showscore(laterv, 1);
	system("pause");
	mycopy( laterv,vectory,2);
	cout << "����    ��������    ����" << endl;
	cout << "�ھ�" <<vectory[0].m_name<< endl;
	cout << "�Ǿ�" << vectory[1].m_name<< endl;
	cout << "����" << vectory[2].m_name<< endl;
	v.clear();
	laterv.clear();
	preserve(vectory);
	cout << "��¼����ɹ�" << endl;
	vectory.clear();
	system("pause");
	system("cls");
}

void operate::showhistory()
{
	vector<history>::iterator it = m_history.begin();
	for (it = m_history.begin(); it != m_history.end(); it++)
	{
		cout << "��" << it->m_index << "��ھ�Ϊ" <<it->history_uid<<"  "<< it->history_name << "������" << it->history_score << endl;
		it++;
		cout << "��" << it->m_index << "���Ǿ�Ϊ" << it->history_uid << "  " << it->history_name << "������" << it->history_score << endl;
		it++;
		cout << "��" << it->m_index << "�켾��Ϊ" << it->history_uid << "  " << it->history_name << "������" << it->history_score << endl;
	}

}

void operate::scan()//�鿴����
{
	ifstream ifs;
	ifs.open("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		cout << "��ʷ��¼������" << endl;
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "��ʷ��¼Ϊ��" << endl;
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

void operate::clean()//���
{
	if (m_history.size() == 0)
	{
		cout << "��ʷ���ݲ����ڣ�" << endl;
		return;
	}
	int choice = 0;
	cout << "��ȷ���Ƿ����" << endl;
	cout << "1.���  0.ȡ��" << endl;
	cin >> choice;
	while (choice != 1 && choice != 0)
	{
		cout << "���벻��������������" << endl;
		cin >> choice;
	}
	if (choice)
	{
		ofstream ofs;
		ofs.open("speech.csv", ios::trunc);
		ofs.close();
		m_history.clear();
		cout << "����ɹ�"<<endl;
	}
}