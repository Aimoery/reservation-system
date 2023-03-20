#pragma once
#include"identity.h"
#include<vector>
#include"Student.h"
#include"Teacher.h"
#include"Computer.h"

class Manager:public Identity
{
public:
//��������
	//���캯��
	Manager();

	//�вι���
	Manager(string Name, string Pwd);

	//�˵�
	virtual void operMenu();

	//����˺�
	void AddPerson();

	//�鿴�˺�
	void ShowPerson();

	//�鿴������Ϣ
	void ShowComputer();

	//��ղ���
	void ClearFile();

	//��ʼ������
	void initVector();

	//��ʼ����������
	void initComVector();

	//ȥ�ز���
	bool checkReport(int id,int type);

	
	//���ѧ����Ϣ
	vector<Student> Vstu;

	//��Ž�ʦ��Ϣ
	vector<Teacher> VTea;

	//��Ż�����Ϣ
	vector<Computer> VCom;

	
};