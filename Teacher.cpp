#include"Teacher.h"
#include "OrderFile.h"
#include <vector>


//构造函数
Teacher::Teacher()
{

}

//有参构造
Teacher::Teacher(int EmpId, string Name, string Pwd)
{
	this->m_EmpId = EmpId;
	this->m_Name = Name;
	this->m_Pwd = Pwd;
}

//菜单
void Teacher::operMenu()
{
	cout << "欢迎老师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t————————————\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|    1、查看机房预约   |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|    2、审核机房预约   |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|    0、注销用户登录    \n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t————————————\n";
	cout << "请选择你要进行的操作：" << endl;
}

//查看所有预约信息
void Teacher::showAllOrder()
{
	OrderFile Order;
	if (Order.m_Size == 0)
	{
		cout << "无记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < Order.m_Size; i++)
	{
		cout << "记录" << i + 1 << endl;
		cout << "预约学生id：" << Order.m_Orderdate[i]["预约学生id"] << "\t"
			<< "预约学生姓名：" << Order.m_Orderdate[i]["预约学生姓名"] << "\t"
			<< "预约机房类型：" << Order.m_Orderdate[i]["预约机房类型"] << "\t"
			<< "预约日期：周" << Order.m_Orderdate[i]["预约日期"] << "\t"
			<< "预约时间段：" << (Order.m_Orderdate[i]["预约时间段"] == "1" ? "上午" : "下午") << "\t"; //三目运算符  ？ ：
		string state = Order.m_Orderdate[i]["预约状态"];
		if (state == "1")
			cout << "预约状态:审核中" << endl;
		else if (state == "2")
			cout << "预约状态:已预约成功" << endl;
		else if (state == "3")
			cout << "预约状态:预约失败" << endl;
		else if (state == "4")
			cout << "预约状态:已取消预约" << endl;
	}
	system("pause");
	system("cls");
	return;
}

//审核预约信息
void Teacher::ValidOrder()
{
	OrderFile Order;
	if (Order.m_Size == 0)
	{
		cout << "无记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	int index = 1;
	vector<int> v;
	cout << "待审核的预约如下:" << endl;
	
	for (int i = 0; i < Order.m_Size; i++)
	{
		if (Order.m_Orderdate[i]["预约状态"] == "1")
		{
			v.push_back(i);
			cout << "记录" << index << endl;
			cout << "预约学生id：" << Order.m_Orderdate[i]["预约学生id"] << "\t"
				<< "预约学生姓名：" << Order.m_Orderdate[i]["预约学生姓名"] << "\t"
				<< "预约机房类型：" << Order.m_Orderdate[i]["预约机房类型"] << "\t"
				<< "预约日期：周" << Order.m_Orderdate[i]["预约日期"] << "\t"
				<< "预约时间段：" << (Order.m_Orderdate[i]["预约时间段"] == "1" ? "上午" : "下午") << endl; //三目运算符  ？ 
			index++;
		}
	}
	while (true)
	{
		cout << "请输入准备审核的预约记录：（0代表返回）" << endl;
		int select;
		int choose;
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
				break;
			else
			{
				cout << "请确认信息：" << endl;
				cout << "预约学生id：" << Order.m_Orderdate[v[select - 1]]["预约学生id"] << "\t"
					<< "预约学生姓名：" << Order.m_Orderdate[v[select - 1]]["预约学生姓名"] << "\t"
					<< "预约机房类型：" << Order.m_Orderdate[v[select - 1]]["预约机房类型"] << "\t"
					<< "预约日期：周" << Order.m_Orderdate[v[select - 1]]["预约日期"] << "\t"
					<< "预约时间段：" << (Order.m_Orderdate[v[select - 1]]["预约时间段"] == "1" ? "上午" : "下午") << endl; //三目运算符  ？ 
				cout << "请选择预约结果：" << endl;
				cout << "1——审核通过：" << endl;
				cout << "2——审核不通过" << endl;
				cin >> choose;
				if (choose == 1)
				{
					Order.m_Orderdate[v[select-1]]["预约状态"] = "2";
					/*Order.Updatadata();
					cout << "审核成功" << endl;
					system("pause");
					system("cls");
					return;*/
				}
				else
				{
					Order.m_Orderdate[v[select - 1]]["预约状态"] = "3";
				}
				Order.Updatadata();
				system("pause");
				system("cls");
				return;
			}
		}
		else
		{
			cout << "输入错误，请重新输入" << endl;
		}
	}
}
