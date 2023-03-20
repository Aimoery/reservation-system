#include<fstream>
#include"Student.h"
#include"GlobalFile.h"
#include"OrderFile.h"


//构造函数
Student::Student()
{

}

//有参构造
Student::Student(int Id, string Name, string Pwd)
{
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_Pwd = Pwd;

	//初始化机房信息
	this->initComVector();
	//OrderFile order;
	
}


//获取机房信息
void Student::initComVector()
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

//菜单
 void Student::operMenu()
{
	 cout << "欢迎学生：" << this->m_Name << "登录！" << endl;
	 cout << "\t\t————————————\n";
	 cout << "\t\t|                      |\n";
	 cout << "\t\t|    1、预约机房申请   |\n";
	 cout << "\t\t|                      |\n";
	 cout << "\t\t|    2、查看本人预约   |\n";
	 cout << "\t\t|                      |\n";
	 cout << "\t\t|    3、查看所有预约   |\n";
	 cout << "\t\t|                      |\n";
	 cout << "\t\t|    4、取消机房预约   |\n";
	 cout << "\t\t|                      |\n";
	 cout << "\t\t|    0、注销用户登录    \n";
	 cout << "\t\t|                      |\n";
	 cout << "\t\t|                      |\n";
	 cout << "\t\t————————————\n";
	 cout << "请选择你要进行的操作：" << endl;
}

//申请
void Student::applyOrder()
{
	int data;
	cout << "机房的开放时间为：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	cout << "请选择你想预约的时间(数字)" << endl;
	cin >> data;

	if (!(data > 0 && data < 6))
	{
		cout << "输入错误,预约失败" << endl;
		return;
	}

	int time;//时间段
	cout << "请选择你想预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	cin >> time;

	if (time != 1 && time != 2)
	{
		cout << "输入错误,预约失败" << endl;
		return;
	}

	int room;
	cout << "请选择你想预约的机房容量：" << endl;
	for (vector<Computer>::iterator it = VCom.begin(); it != VCom.end(); it++)
	{
		cout << it->m_ComId << "、机房的容量为：" << it->m_MaxNum << endl;
	}
	cin >> room;
	if (room != 1 && room != 2&&room!=3)
	{
		cout << "输入错误,预约失败" << endl;
		return;
	}
	cout << "预约成功，审核中" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	if(!ofs.is_open())
	{
		cout << "文件打开失败，预约信息未保存，请联系管理员" << endl;
		ofs.close();
		system("pause");
		system("cls");
		return;
	}
	ofs << "预约日期:" << data << " "
		<< "预约时间段:" << time << "  "
		<<"预约学生id:"<<this->m_Id<<" "
		<<"预约学生姓名:"<<this->m_Name<<"  "
		<< "预约机房类型:" << room << "  " 
		<<"预约状态:"<<1<< endl;  //1在此次代表审核中
	ofs.close();
	system("pause");
	system("cls");
	return;
}

//查看自己预约信息
void Student::showOrder()
{
	OrderFile order;
	if (order.m_Size == 0)
	{
		cout << "无记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < order.m_Size; i++)
	{
		//string 转int
		//string 利用 .c_str() 转 const char *
		//利用atoi（const char *） 转int
		/*cout << atoi(order.m_Orderdate[i]["预约学生id"].c_str()) << endl;
		cout<<order.m_Orderdate[i]["预约学生id"].c_str() << endl;
		cout << "预约日期：周" << order.m_Orderdate[0]["预约日期"] << "\t";*/
		/*bool m = this->m_Id == atoi(order.m_Orderdate[i]["预约学生id"].c_str());
		cout <<m<< endl;*/
		if (this->m_Id == atoi(order.m_Orderdate[i]["预约学生id"].c_str()))  //尝试stoi
		{
			cout << "预约日期：周" << order.m_Orderdate[i]["预约日期"] << "\t"
				<< "预约机房类型：" << order.m_Orderdate[i]["预约机房类型"] << "\t"
				<< "预约时间段：" << (order.m_Orderdate[i]["预约时间段"] == "1" ? "上午" : "下午") << "\t";
			string staute = order.m_Orderdate[i]["预约状态"];
			//1-审核中  2-已预约成功 3-预约失败  4-已取消预约
			if (staute == "1")
				cout << "预约状态:审核中" << endl;
			else if (staute == "2")
				cout << "预约状态:已预约成功" << endl;
			else if (staute == "3")
				cout << "预约状态:预约失败" << endl;
			else if (staute == "4")
				cout << "预约状态:已取消预约" << endl;
		}
	}
	system("pause");
	system("cls");
	return;
}

//查看所有预约信息
void Student::showAllOrder()
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
		cout <<"记录" <<i + 1 << endl;
		cout << "预约学生id：" << Order.m_Orderdate[i]["预约学生id"] << "\t"
			<< "预约学生姓名：" << Order.m_Orderdate[i]["预约学生姓名"] << "\t"
			<< "预约机房类型：" << Order.m_Orderdate[i]["预约机房类型"] << "\t"
			<< "预约日期：周" << Order.m_Orderdate[i]["预约日期"] << "\t"
			<< "预约时间段：" << (Order.m_Orderdate[i]["预约时间段"] == "1" ? "上午" : "下午") << "\t"; //三目运算符  ？ ：
		string state= Order.m_Orderdate[i]["预约状态"];
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

//取消预约
void Student::CancelOrder()
{
	OrderFile Order;
	if (Order.m_Size == 0)
	{
		cout << "无记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "Note:只能修改审核中或者审核通过的预约信息" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0; i < Order.m_Size; i++)
	{
		if (this->m_Id == atoi(Order.m_Orderdate[i]["预约学生id"].c_str()))
		{
			
			if (Order.m_Orderdate[i]["预约状态"] == "1" || Order.m_Orderdate[i]["预约状态"] == "2")
				v.push_back(i);
			cout << "记录" << index << endl;
			cout<< "预约机房类型：" << Order.m_Orderdate[i]["预约机房类型"] << "\t"
				<< "预约日期：周" << Order.m_Orderdate[i]["预约日期"] << "\t"
				<< "预约时间段：" << (Order.m_Orderdate[i]["预约时间段"] == "1" ? "上午" : "下午") << "\t"; //三目运算符  ？ ：
			string state = Order.m_Orderdate[i]["预约状态"];
			if (state == "1")
				cout << "预约状态:审核中" << endl;
			else if (state == "2")
				cout << "预约状态:已预约成功" << endl;
			index++;
		}
	}
	while (true)
	{
		cout << "请确认你要取消的预约记录号,0可退出" << endl;
		int choose;
		cin >> choose;
		if (choose >= 0 && choose <= v.size())
		{
			if (choose == 0)
				break;
			else
			{
				Order.m_Orderdate[v[choose-1]]["预约状态"] = "4";  //用v容器来记录存放筛选出来的数据的索引号
				Order.Updatadata();
				cout << "预约取消成功" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
		cout << "输入错误，请重试：" << endl;
	}
		

	

}