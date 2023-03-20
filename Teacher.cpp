#include"Teacher.h"
#include "OrderFile.h"
#include <vector>


//���캯��
Teacher::Teacher()
{

}

//�вι���
Teacher::Teacher(int EmpId, string Name, string Pwd)
{
	this->m_EmpId = EmpId;
	this->m_Name = Name;
	this->m_Pwd = Pwd;
}

//�˵�
void Teacher::operMenu()
{
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t������������������������\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|    1���鿴����ԤԼ   |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|    2����˻���ԤԼ   |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|    0��ע���û���¼    \n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t������������������������\n";
	cout << "��ѡ����Ҫ���еĲ�����" << endl;
}

//�鿴����ԤԼ��Ϣ
void Teacher::showAllOrder()
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
		cout << "��¼" << i + 1 << endl;
		cout << "ԤԼѧ��id��" << Order.m_Orderdate[i]["ԤԼѧ��id"] << "\t"
			<< "ԤԼѧ��������" << Order.m_Orderdate[i]["ԤԼѧ������"] << "\t"
			<< "ԤԼ�������ͣ�" << Order.m_Orderdate[i]["ԤԼ��������"] << "\t"
			<< "ԤԼ���ڣ���" << Order.m_Orderdate[i]["ԤԼ����"] << "\t"
			<< "ԤԼʱ��Σ�" << (Order.m_Orderdate[i]["ԤԼʱ���"] == "1" ? "����" : "����") << "\t"; //��Ŀ�����  �� ��
		string state = Order.m_Orderdate[i]["ԤԼ״̬"];
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

//���ԤԼ��Ϣ
void Teacher::ValidOrder()
{
	OrderFile Order;
	if (Order.m_Size == 0)
	{
		cout << "�޼�¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	int index = 1;
	vector<int> v;
	cout << "����˵�ԤԼ����:" << endl;
	
	for (int i = 0; i < Order.m_Size; i++)
	{
		if (Order.m_Orderdate[i]["ԤԼ״̬"] == "1")
		{
			v.push_back(i);
			cout << "��¼" << index << endl;
			cout << "ԤԼѧ��id��" << Order.m_Orderdate[i]["ԤԼѧ��id"] << "\t"
				<< "ԤԼѧ��������" << Order.m_Orderdate[i]["ԤԼѧ������"] << "\t"
				<< "ԤԼ�������ͣ�" << Order.m_Orderdate[i]["ԤԼ��������"] << "\t"
				<< "ԤԼ���ڣ���" << Order.m_Orderdate[i]["ԤԼ����"] << "\t"
				<< "ԤԼʱ��Σ�" << (Order.m_Orderdate[i]["ԤԼʱ���"] == "1" ? "����" : "����") << endl; //��Ŀ�����  �� 
			index++;
		}
	}
	while (true)
	{
		cout << "������׼����˵�ԤԼ��¼����0�����أ�" << endl;
		int select;
		int choose;
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
				break;
			else
			{
				cout << "��ȷ����Ϣ��" << endl;
				cout << "ԤԼѧ��id��" << Order.m_Orderdate[v[select - 1]]["ԤԼѧ��id"] << "\t"
					<< "ԤԼѧ��������" << Order.m_Orderdate[v[select - 1]]["ԤԼѧ������"] << "\t"
					<< "ԤԼ�������ͣ�" << Order.m_Orderdate[v[select - 1]]["ԤԼ��������"] << "\t"
					<< "ԤԼ���ڣ���" << Order.m_Orderdate[v[select - 1]]["ԤԼ����"] << "\t"
					<< "ԤԼʱ��Σ�" << (Order.m_Orderdate[v[select - 1]]["ԤԼʱ���"] == "1" ? "����" : "����") << endl; //��Ŀ�����  �� 
				cout << "��ѡ��ԤԼ�����" << endl;
				cout << "1�������ͨ����" << endl;
				cout << "2������˲�ͨ��" << endl;
				cin >> choose;
				if (choose == 1)
				{
					Order.m_Orderdate[v[select-1]]["ԤԼ״̬"] = "2";
					/*Order.Updatadata();
					cout << "��˳ɹ�" << endl;
					system("pause");
					system("cls");
					return;*/
				}
				else
				{
					Order.m_Orderdate[v[select - 1]]["ԤԼ״̬"] = "3";
				}
				Order.Updatadata();
				system("pause");
				system("cls");
				return;
			}
		}
		else
		{
			cout << "�����������������" << endl;
		}
	}
}
