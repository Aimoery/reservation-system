#pragma once
#include<iostream>
#include<map>

using namespace std;

class OrderFile
{
public:
	OrderFile();

	void Mapchange(map<string, string>& m,string X);

	//��������
	void Updatadata();

	//����map��ֵ��
	map<int,map<string,string>> m_Orderdate;

	int m_Size;//���¼�¼����
};