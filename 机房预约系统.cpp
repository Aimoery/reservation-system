// 机房预约系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<fstream>
#include"identity.h"
#include"GlobalFile.h"
#include"Manager.h"
#include"Student.h"
#include"Teacher.h"

using namespace std;


//父类指针  以引用的方式调用
void StudentMemu(Identity*& student)
{
	while (true)
	{
		//父虚类调用菜单
		student->operMenu();
		//强转父类为子类
		int select;
		Student* stu = (Student*)student;//student为Identity建立的父虚类，而Student为学生子类
		cin >> select;
		switch (select)
		{
		case 1:
		{
			cout << "申请预约" << endl;
			stu->applyOrder();
			break;
		}
		case 2:
		{
			cout << "显示本人预约" << endl;
			stu->showOrder();
			break;
		}
		case 3:
		{
			cout << "显示所有预约" << endl;
			stu->showAllOrder();
			break;
		}
		case 4:
		{
			cout << "取消预约" << endl;
			stu->CancelOrder();
			break;
		}
		case 0:
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		default:
			cout << "输入错误，请重新输入" << endl;
			break;
		}
	}
}


void TeacherMemu(Identity*& teacher)
{
	while(true)
	{ 
		teacher->operMenu();
		//强转
		Teacher* teach = (Teacher*)teacher;
		int select;
		cin >> select;

		switch (select)
		{
		case 1:
		{
			cout << "查看所有预约信息" << endl;
			teach->showAllOrder();
			//system("cls");
			break;
		}
		case 2:
		{
			cout << "审核预约信息" << endl;
			teach->ValidOrder();
			//system("cls");
			break;
		}
		case 0:
		{
			delete teacher;//删去父类
			system("pause");
			system("cls");
			return;
			break;
		}
		default:
			cout << "输入错误，请重新输入" << endl;
			break;
		}
	}
}


void ManagerMemu(Identity*& manager)//Identity* 纯虚函数类 调用Manager子类然后引用其
{
	while (true)
	{
		//调用父类指针中的函数
		manager->operMenu();
		//将父类指针强转为子类指针
		Manager* man = (Manager*)manager;
		int select ;
		cin >> select;

		switch (select)
		{
		case 1:
		{
			cout << "添加账号" << endl;
			man->AddPerson();
			break;
		}
		case 2:
		{
			cout << "查看账号" << endl;
			man->ShowPerson();
			break;
		}
		case 3:
		{
			cout << "查看机房信息" << endl;
			man->ShowComputer();
			break;
		}
		case 4:
		{
			cout << "清空" << endl;
			man->ClearFile();
			break;
		}
		case 0:
		{
			cout << "注销成功" << endl;
			delete manager;
			system("pause");
			system("cls");
			return;
			break;
		}
		default:
			cout << "输入错误，请重新输入" << endl;
			break;
		}
	}
}

void LoginIn(string FileName, int type)
{
	Identity* person=NULL;  //Note：利用父类指针可以创建子类对象

	//首先读取文件中的元素 以此来判定是否可以运行
	ifstream ifs;
	ifs.open(FileName, ios::in);  //读取文件  

	if (!ifs.is_open())//判定文件是否打开用is_open()语句
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return ;
	}
	//1:学生  2：教师  3、管理员

	int ID=0;  //有可能管理员没有ID，则ID不赋值
	string name;
	string Pwd;
	if (type == 1)  //Note 判定要用两个等号
	{
		cout << "请输入学生学号：" << endl;
		cin >> ID;
	}
	else if (type == 2)
	{
		cout << "请输入教师工号：" << endl;
		cin >> ID;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> Pwd;


	int fid;
	string fname;
	string fPwd;
	switch (type)//Note:switch的速度快于if
	{
	case 1:
	{
		//学生认证操作
		/*int fid;
		string fname;
		string fPwd;*/
		while (ifs >> fid && ifs >> fname && ifs >> fPwd)
		{
			if (fid == ID && fname == name && fPwd == Pwd)
			{
				cout << "验证成功" << endl;
				system("pause");
				system("cls");
				person = new Student(ID, name, Pwd);
				//进入学生子菜单
				StudentMemu(person);
				return;
			}
		}
		break;
	}
	case 2:
		//教师认证操作
	{
		while (ifs >> fid && ifs >> fname && ifs >> fPwd)//
		{
			//cout << fid << fname << fPwd << endl;  乱码解决：打开txt-文件-另存为-编码格式选ANXI-替换原文件
			if (fid == ID && fname == name && fPwd == Pwd)
			{
				cout << "验证成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(ID, name, Pwd);
				//进入教师子菜单
				TeacherMemu(person);
				return;
			}
		}
		break;
	}
	case 3:
	//管理员认证操作
	{
		while (ifs >> fname && ifs >> fPwd)
		{
			if (Pwd == fPwd && fname == name)
			{
				cout << "验证成功" << endl;
				system("pause");
				system("cls");//不太理解以上两行存在的意义
				person = new Manager(name, Pwd);
				//进入管理员子菜单
				ManagerMemu(person);
				return;
			}
			break;
		}
	}
	default:
		cout << "选择错误！" << endl;
		break;
	}
	cout << "登录验证失败" << endl;
	system("pause");
	system("cls");
	return ;
}

int main()
{
	int choose;
	while (true)
	{
		cout << "===========欢迎来到机房预约系统===========" << endl;
		cout << "\t\t————————————\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      1、学生代表     |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      2、老    师     |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      3、管 理 员     |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t|      0、退    出     |\n";
		cout << "\t\t|                      |\n";
		cout << "\t\t————————————\n";
		cout << "请选择你的身份：" << endl;
		cin >> choose;
		//cout << endl;

		switch (choose)
		{
		case 1:
			//学生代表界面
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			//老师界面
			LoginIn(TEACHER_FILE, 2);
			break;

		case 3:
			//管理员界面
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			//退出
		{
			cout << "欢迎下一次使用" << endl;
			/*system("pause");
			return ;*/   //此两行代码约等于exit(0)
			exit(0);
			break;
		}
		default:
			cout << "输入有误请重新输入！" << endl;
			break;
		}
		//system("pause");
		system("cls");
	}	
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
