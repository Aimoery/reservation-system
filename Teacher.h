#pragma once
#include"identity.h"

class Teacher :public Identity
{
public:
//函数部分

	//构造函数
	Teacher();

	//有参构造
	Teacher(int EmpId, string Name, string Pwd);

	//菜单
	virtual void operMenu();

	//查看所有预约信息
	void showAllOrder();

	//审核预约信息
	void ValidOrder();

	//自己的独立属性
	int m_EmpId;
};