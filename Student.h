#pragma once
#include"identity.h"
#include<vector>
#include"Computer.h"


//Identity��������students
class Student :public Identity
{
public:
//��������
// 
	//���캯��
	Student();

	//�вι���
	Student(int Id, string Name, string Pwd);
	//��ȡ������Ϣ
	void initComVector();

	//�˵�
	virtual void operMenu();

	//����
	void applyOrder();

	//�鿴�Լ�ԤԼ��Ϣ
	void showOrder();
 
	//�鿴����ԤԼ��Ϣ
	void showAllOrder();

	//ȡ��ԤԼ
	void CancelOrder();

	//�Լ��Ķ�������
	int m_Id;

	//������Ϣ
	vector<Computer> VCom;
};