#pragma once
#include"identity.h"

class Teacher :public Identity
{
public:
//��������

	//���캯��
	Teacher();

	//�вι���
	Teacher(int EmpId, string Name, string Pwd);

	//�˵�
	virtual void operMenu();

	//�鿴����ԤԼ��Ϣ
	void showAllOrder();

	//���ԤԼ��Ϣ
	void ValidOrder();

	//�Լ��Ķ�������
	int m_EmpId;
};