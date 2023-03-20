#include<fstream>
#include"Student.h"
#include"GlobalFile.h"
#include"OrderFile.h"


//���캯��
Student::Student()
{

}

//�вι���
Student::Student(int Id, string Name, string Pwd)
{
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_Pwd = Pwd;

	//��ʼ��������Ϣ
	this->initComVector();
	//OrderFile order;
	
}


//��ȡ������Ϣ
void Student::initComVector()
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	while (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
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
	cout << "��ǰ��������������" << VCom.size() << endl;
}

//�˵�
 void Student::operMenu()
{
	 cout << "��ӭѧ����" << this->m_Name << "��¼��" << endl;
	 cout << "\t\t������������������������\n";
	 cout << "\t\t|                      |\n";
	 cout << "\t\t|    1��ԤԼ��������   |\n";
	 cout << "\t\t|                      |\n";
	 cout << "\t\t|    2���鿴����ԤԼ   |\n";
	 cout << "\t\t|                      |\n";
	 cout << "\t\t|    3���鿴����ԤԼ   |\n";
	 cout << "\t\t|                      |\n";
	 cout << "\t\t|    4��ȡ������ԤԼ   |\n";
	 cout << "\t\t|                      |\n";
	 cout << "\t\t|    0��ע���û���¼    \n";
	 cout << "\t\t|                      |\n";
	 cout << "\t\t|                      |\n";
	 cout << "\t\t������������������������\n";
	 cout << "��ѡ����Ҫ���еĲ�����" << endl;
}

//����
void Student::applyOrder()
{
	int data;
	cout << "�����Ŀ���ʱ��Ϊ��" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	cout << "��ѡ������ԤԼ��ʱ��(����)" << endl;
	cin >> data;

	if (!(data > 0 && data < 6))
	{
		cout << "�������,ԤԼʧ��" << endl;
		return;
	}

	int time;//ʱ���
	cout << "��ѡ������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	cin >> time;

	if (time != 1 && time != 2)
	{
		cout << "�������,ԤԼʧ��" << endl;
		return;
	}

	int room;
	cout << "��ѡ������ԤԼ�Ļ���������" << endl;
	for (vector<Computer>::iterator it = VCom.begin(); it != VCom.end(); it++)
	{
		cout << it->m_ComId << "������������Ϊ��" << it->m_MaxNum << endl;
	}
	cin >> room;
	if (room != 1 && room != 2&&room!=3)
	{
		cout << "�������,ԤԼʧ��" << endl;
		return;
	}
	cout << "ԤԼ�ɹ��������" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	if(!ofs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�ԤԼ��Ϣδ���棬����ϵ����Ա" << endl;
		ofs.close();
		system("pause");
		system("cls");
		return;
	}
	ofs << "ԤԼ����:" << data << " "
		<< "ԤԼʱ���:" << time << "  "
		<<"ԤԼѧ��id:"<<this->m_Id<<" "
		<<"ԤԼѧ������:"<<this->m_Name<<"  "
		<< "ԤԼ��������:" << room << "  " 
		<<"ԤԼ״̬:"<<1<< endl;  //1�ڴ˴δ��������
	ofs.close();
	system("pause");
	system("cls");
	return;
}

//�鿴�Լ�ԤԼ��Ϣ
void Student::showOrder()
{
	OrderFile order;
	if (order.m_Size == 0)
	{
		cout << "�޼�¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < order.m_Size; i++)
	{
		//string תint
		//string ���� .c_str() ת const char *
		//����atoi��const char *�� תint
		/*cout << atoi(order.m_Orderdate[i]["ԤԼѧ��id"].c_str()) << endl;
		cout<<order.m_Orderdate[i]["ԤԼѧ��id"].c_str() << endl;
		cout << "ԤԼ���ڣ���" << order.m_Orderdate[0]["ԤԼ����"] << "\t";*/
		/*bool m = this->m_Id == atoi(order.m_Orderdate[i]["ԤԼѧ��id"].c_str());
		cout <<m<< endl;*/
		if (this->m_Id == atoi(order.m_Orderdate[i]["ԤԼѧ��id"].c_str()))  //����stoi
		{
			cout << "ԤԼ���ڣ���" << order.m_Orderdate[i]["ԤԼ����"] << "\t"
				<< "ԤԼ�������ͣ�" << order.m_Orderdate[i]["ԤԼ��������"] << "\t"
				<< "ԤԼʱ��Σ�" << (order.m_Orderdate[i]["ԤԼʱ���"] == "1" ? "����" : "����") << "\t";
			string staute = order.m_Orderdate[i]["ԤԼ״̬"];
			//1-�����  2-��ԤԼ�ɹ� 3-ԤԼʧ��  4-��ȡ��ԤԼ
			if (staute == "1")
				cout << "ԤԼ״̬:�����" << endl;
			else if (staute == "2")
				cout << "ԤԼ״̬:��ԤԼ�ɹ�" << endl;
			else if (staute == "3")
				cout << "ԤԼ״̬:ԤԼʧ��" << endl;
			else if (staute == "4")
				cout << "ԤԼ״̬:��ȡ��ԤԼ" << endl;
		}
	}
	system("pause");
	system("cls");
	return;
}

//�鿴����ԤԼ��Ϣ
void Student::showAllOrder()
{
	OrderFile Order;
	if (Order.m_Size == 0)
	{
		cout << "�޼�¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < Order.m_Size; i++)
	{
		cout <<"��¼" <<i + 1 << endl;
		cout << "ԤԼѧ��id��" << Order.m_Orderdate[i]["ԤԼѧ��id"] << "\t"
			<< "ԤԼѧ��������" << Order.m_Orderdate[i]["ԤԼѧ������"] << "\t"
			<< "ԤԼ�������ͣ�" << Order.m_Orderdate[i]["ԤԼ��������"] << "\t"
			<< "ԤԼ���ڣ���" << Order.m_Orderdate[i]["ԤԼ����"] << "\t"
			<< "ԤԼʱ��Σ�" << (Order.m_Orderdate[i]["ԤԼʱ���"] == "1" ? "����" : "����") << "\t"; //��Ŀ�����  �� ��
		string state= Order.m_Orderdate[i]["ԤԼ״̬"];
		if (state == "1")
			cout << "ԤԼ״̬:�����" << endl;
		else if (state == "2")
			cout << "ԤԼ״̬:��ԤԼ�ɹ�" << endl;
		else if (state == "3")
			cout << "ԤԼ״̬:ԤԼʧ��" << endl;
		else if (state == "4")
			cout << "ԤԼ״̬:��ȡ��ԤԼ" << endl;
	}
	system("pause");
	system("cls");
	return;
}

//ȡ��ԤԼ
void Student::CancelOrder()
{
	OrderFile Order;
	if (Order.m_Size == 0)
	{
		cout << "�޼�¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "Note:ֻ���޸�����л������ͨ����ԤԼ��Ϣ" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0; i < Order.m_Size; i++)
	{
		if (this->m_Id == atoi(Order.m_Orderdate[i]["ԤԼѧ��id"].c_str()))
		{
			
			if (Order.m_Orderdate[i]["ԤԼ״̬"] == "1" || Order.m_Orderdate[i]["ԤԼ״̬"] == "2")
				v.push_back(i);
			cout << "��¼" << index << endl;
			cout<< "ԤԼ�������ͣ�" << Order.m_Orderdate[i]["ԤԼ��������"] << "\t"
				<< "ԤԼ���ڣ���" << Order.m_Orderdate[i]["ԤԼ����"] << "\t"
				<< "ԤԼʱ��Σ�" << (Order.m_Orderdate[i]["ԤԼʱ���"] == "1" ? "����" : "����") << "\t"; //��Ŀ�����  �� ��
			string state = Order.m_Orderdate[i]["ԤԼ״̬"];
			if (state == "1")
				cout << "ԤԼ״̬:�����" << endl;
			else if (state == "2")
				cout << "ԤԼ״̬:��ԤԼ�ɹ�" << endl;
			index++;
		}
	}
	while (true)
	{
		cout << "��ȷ����Ҫȡ����ԤԼ��¼��,0���˳�" << endl;
		int choose;
		cin >> choose;
		if (choose >= 0 && choose <= v.size())
		{
			if (choose == 0)
				break;
			else
			{
				Order.m_Orderdate[v[choose-1]]["ԤԼ״̬"] = "4";  //��v��������¼���ɸѡ���������ݵ�������
				Order.Updatadata();
				cout << "ԤԼȡ���ɹ�" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
		cout << "������������ԣ�" << endl;
	}
		

	

}