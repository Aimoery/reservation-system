#include "Manager.h"
#include"GlobalFile.h"
#include<fstream>
#include<algorithm>



//Alt+Enter 直接生成对应的类函数定义/声明
//构造函数
Manager::Manager()
{

}


//有参构造
Manager::Manager(string Name, string Pwd)
{
	this->m_Name = Name;
	this->m_Pwd = Pwd;

	//初始化容器
	this->initVector();

	//初始化机房容量
	this->initComVector();

}


//菜单
void Manager::operMenu()
{
	cout << "欢迎管理员："<<this->m_Name<<"登录！" << endl;
	cout << "\t\t————————————\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      1、添加账号     |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      2、查看账号     |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      3、查看机房     |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      4、清空预约     |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      0、注销登录     |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t————————————\n";
	cout << "请选择你要进行的操作：" << endl;
}


//添加账号
void Manager::AddPerson()
{
	cout << "请输入添加账号的类型：" << endl;
	cout << "1、学生" << endl;
	cout << "2、老师" << endl;

	int select = 0;
	cin>>select;
	string tip;
	string fileName;
	string Errortip;//错误提示
	switch (select)
	{
	case 1:
	{
		//学生
		fileName = STUDENT_FILE;
		tip = "请输入学生学号：";
		Errortip = "学号重复，请重新输入";
		break;
	}
	case 2:
	{
		//教师
		fileName = TEACHER_FILE;
		tip = "请输入教师工号：";
		Errortip = "学号重复，请重新输入";
		break;
	}
	default:
		cout << "序号选择错误，请重新选择" << endl;
		return;
	}

	string name;
	string Pwd;
	int num;
	bool ret;//新建返回值，用于返回是否有重复元素
	ofstream ofs;
	ofs.open(fileName, ios::out | ios::app);
	if (!ofs.is_open())
	{
		cout << "文件不存在，请创建：" << endl;
		ofs.close();
		system("pause");
		system("cls");
		return;
	}
	cout << tip << endl;
	cin >> num;
	ret=this->checkReport(num, select);
	while  (ret == true)
	{
		cout << Errortip << endl;
		cout << tip << endl;
		cin >> num;
		ret = this->checkReport(num, select);
	}
	cout << "请输入创建用户名：" << endl;
	cin >> name;
	cout << "请设置密码：" << endl;
	cin >> Pwd;
	ofs << num << " " << name << " " << Pwd << " " << endl;
	cout << "创建成功" << endl;
	
	//更新容器 
	this->initVector();
	ofs.close();
	system("pause");
	system("cls");

}

class PrintStudent
{
public:
	void operator()(Student& s)
	{
		cout << "学生学号为：" << s.m_Id << "学生姓名为：" << s.m_Name << endl;
	}
};

//全局函数or仿函数
void PrintTeacher(Teacher& tea)
{
	cout << "教师学号为：" << tea.m_EmpId << "教师姓名为：" << tea.m_Name << endl;
}



//查看账号
void Manager::ShowPerson()
{
	////以下注释为没创建Vector时候的操作  用文件打开
	cout << "请输入查看账号的类型：" << endl;
	cout << "1、学生" << endl;
	cout << "2、老师" << endl;
	int select = 0;
	//string fileName;
	cin >> select;
	//int num;
	//string name;
	//string Pwd;
	switch (select)
	{
	case 1:
		//学生	
	{
		cout << "学生信息如下：" << endl;
		for_each(Vstu.begin(), Vstu.end(), PrintStudent());  //PrintStudent()仿函数
	//	fileName = STUDENT_FILE;
		break;
	}
	case 2:
		//教师	
	{
		cout << "老师信息如下：" << endl;
		for_each(VTea.begin(), VTea.end(), PrintTeacher);  //成员函数或者全局函数
	//	fileName = TEACHER_FILE;
		break;
	}
	default:
		cout << "输入错误，请重新输入；" << endl;
		break;
	 }
	//ifstream ifs;
	//ifs.open(fileName, ios::in);
	//while (!ifs.is_open())
	//{
	//	cout << "文件打开失败，请检查！" << endl;
	//	ifs.close();
	//	system("pause");
	//	system("cls");
	//	return;
	//}
	////如果一直有文件，即输出
	//while (ifs >> num && ifs >> name && ifs >> Pwd)
	//{
	//	cout << "用户编号为：" << num << "用户姓名为：" << name << "密码为：" << Pwd << endl;
	//}
	//ifs.close();
	system("pause");
	system("cls");
}


//查看机房信息
void Manager::ShowComputer()
{
	for (vector<Computer>::iterator it = VCom.begin(); it != VCom.end(); it++)
	{
		cout << "机房类型为：" << it->m_ComId << "机房最大容量为：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}


//清空操作
void Manager::ClearFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	//ofs.open(ORDER_FILE, ios::trunc);//打开文件，并清空内部
	//可以添加确认信息，如是否确认清空？
	ofs.close();
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}


//初始化学生和教师信息文件
void Manager::initVector()
{
	//清空操作
	Vstu.clear();
	VTea.clear();

	/*string name;
	string Pwd;
	int num;*/
	ifstream ifs;
	//学生相关操作
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败，请重试" << endl;
		ifs.close();
		system("pause");
		system("cls");
		return;
	}
	Student s;
	while (ifs>>s.m_Id&&ifs>>s.m_Name&&ifs>>s.m_Pwd)
	{
		Vstu.push_back(s);
	}
	cout << "当前学生数据数量：" << Vstu.size() << endl;
	ifs.close();

	//老师操作
	ifs.open(TEACHER_FILE,ios::in);
	while (!ifs.is_open())
	{
		cout << "文件打开失败，请检查" << endl;
		ifs.close();
		system("pause");
		system("cls");
		return;
	}
	Teacher tea;
	while (ifs>>tea.m_EmpId&&ifs>>tea.m_Name&&ifs>>tea.m_Pwd)
	{
		VTea.push_back(tea);
	}
	cout << "当前老师数据数量：" << VTea.size() << endl;
	ifs.close();
	/*system("cls");
	system("pause");*/
	return;
}

void Manager::initComVector()
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	while (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		ifs.close();
		system("cls");
		system("pause");
		return;
	}
	Computer Com;
	while (ifs >> Com.m_ComId && ifs >> Com.m_MaxNum)
	{
		VCom.push_back(Com);
	}
	cout << "当前机房数据数量：" << VCom.size() << endl;
}

bool Manager::checkReport(int id, int type)
{
	//假设类型1为学生，类型2为老师
	switch (type)
	{
	case 1:
	{
		//find(Vstu.begin(), Vstu.end(), id);
		for (vector<Student>::iterator it = Vstu.begin(); it != Vstu.end(); it++)
		{
			if (it->m_Id == id)
				return true;//有重复
		}
		break;
	}
	case 2:
	{
		for (vector<Teacher>::iterator it = VTea.begin(); it != VTea.end(); it++)
		{
			if (it->m_EmpId == id)
				return true;//有重复
		}
		break;
	}	
	default:
		cout << "判定失败，请重新判定" << endl;
		break;
	}
	return false;
}
