#pragma once
#include<iostream>
using namespace std;

//��ݳ������  �����������Ĺ���
class Identity
{
public:

	virtual void operMenu() = 0;//���麯��  ��ͬ�� ��ʾ�˵�

	//��ͬ���� �û���������
	string m_Name;
	string m_Pwd;

};