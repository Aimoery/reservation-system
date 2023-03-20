#pragma once
#include"identity.h"
#include<vector>
#include"Student.h"
#include"Teacher.h"
#include"Computer.h"

class Manager:public Identity
{
public:
//函数部分
	//构造函数
	Manager();

	//有参构造
	Manager(string Name, string Pwd);

	//菜单
	virtual void operMenu();

	//添加账号
	void AddPerson();

	//查看账号
	void ShowPerson();

	//查看机房信息
	void ShowComputer();

	//清空操作
	void ClearFile();

	//初始化容器
	void initVector();

	//初始化机房容器
	void initComVector();

	//去重操作
	bool checkReport(int id,int type);

	
	//存放学生信息
	vector<Student> Vstu;

	//存放教师信息
	vector<Teacher> VTea;

	//存放机房信息
	vector<Computer> VCom;

	
};