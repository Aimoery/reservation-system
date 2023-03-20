#pragma once
#include<iostream>
#include<map>

using namespace std;

class OrderFile
{
public:
	OrderFile();

	void Mapchange(map<string, string>& m,string X);

	//更新数据
	void Updatadata();

	//建立map键值对
	map<int,map<string,string>> m_Orderdate;

	int m_Size;//更新记录条数
};