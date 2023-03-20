#pragma once
#include"identity.h"
#include<vector>
#include"Computer.h"


//Identity的派生类students
class Student :public Identity
{
public:
//函数部分
// 
	//构造函数
	Student();

	//有参构造
	Student(int Id, string Name, string Pwd);
	//获取机房信息
	void initComVector();

	//菜单
	virtual void operMenu();

	//申请
	void applyOrder();

	//查看自己预约信息
	void showOrder();
 
	//查看所有预约信息
	void showAllOrder();

	//取消预约
	void CancelOrder();

	//自己的独立属性
	int m_Id;

	//机房信息
	vector<Computer> VCom;
};