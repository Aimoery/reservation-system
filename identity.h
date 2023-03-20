#pragma once
#include<iostream>
using namespace std;

//身份抽象基类  抽象出所有类的共性
class Identity
{
public:

	virtual void operMenu() = 0;//纯虚函数  共同类 显示菜单

	//共同属性 用户名和密码
	string m_Name;
	string m_Pwd;

};