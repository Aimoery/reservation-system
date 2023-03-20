#include "OrderFile.h"
#include"GlobalFile.h"
#include<iostream>
#include<fstream>
#include<map>

void OrderFile::Mapchange(map<string, string>& m, string X)
{
	string key;
	string value;
	int pos = X.find(":");
	if (pos != -1)
	{
		key = X.substr(0, pos);
		value = X.substr(pos + 1, X.size() - pos - 1);
		m.insert(make_pair(key, value));
	}
	/*cout << key;
	cout << value;*/
	//

}

OrderFile::OrderFile()
{

	//Updatadata();

	string data, time, id, name, room, state;
	this->m_Size = 0;//��ʼ��ԤԼ����
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	while (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ����Ʋ������ļ�����ȷ�ϣ�" << endl;
		return;
	}
	while (ifs >> data && ifs >> time && ifs >> id && ifs >> name && ifs >> room && ifs >> state)
	{
		map<string, string> m;
		Mapchange(m,data);
		Mapchange(m, time);
		Mapchange(m, id);
		Mapchange(m, name);
		Mapchange(m, room);
		Mapchange(m, state);
		m_Orderdate.insert(make_pair(this->m_Size,m));
		this->m_Size++;
	}
	ifs.close();
	/*for (map<int, map<string, string>>::iterator it = m_Orderdate.begin(); it != m_Orderdate.end(); it++)
	{
		cout << "��" << it->first +1 << "����Ϣ����" << endl;
		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
			cout << mit->first << mit->second << "\t";
		cout << endl;
	}*/
}

void OrderFile::Updatadata()
{
	if (this->m_Size == 0)
		return;
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out |ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
		ofs << "ԤԼѧ��id:" << m_Orderdate[i]["ԤԼѧ��id"]<<"\t"
		<< "ԤԼѧ������:" << m_Orderdate[i]["ԤԼѧ������"]<<"\t"
		<< "ԤԼ��������:" << m_Orderdate[i]["ԤԼ��������"]<<"\t"
		<<"ԤԼ����:" << m_Orderdate[i]["ԤԼ����"] << "\t"
		<< "ԤԼʱ���:" << m_Orderdate[i]["ԤԼʱ���"] << "\t"
		<< "ԤԼ״̬:" << m_Orderdate[i]["ԤԼ״̬"]
		<< endl;
	ofs.close();
	//OrderFile();
}