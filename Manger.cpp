#include "Manager.h"
#include"GlobalFile.h"
#include<fstream>
#include<algorithm>



//Alt+Enter ֱ�����ɶ�Ӧ���ຯ������/����
//���캯��
Manager::Manager()
{

}


//�вι���
Manager::Manager(string Name, string Pwd)
{
	this->m_Name = Name;
	this->m_Pwd = Pwd;

	//��ʼ������
	this->initVector();

	//��ʼ����������
	this->initComVector();

}


//�˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա��"<<this->m_Name<<"��¼��" << endl;
	cout << "\t\t������������������������\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      1������˺�     |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      2���鿴�˺�     |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      3���鿴����     |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      4�����ԤԼ     |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      0��ע����¼     |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t������������������������\n";
	cout << "��ѡ����Ҫ���еĲ�����" << endl;
}


//����˺�
void Manager::AddPerson()
{
	cout << "����������˺ŵ����ͣ�" << endl;
	cout << "1��ѧ��" << endl;
	cout << "2����ʦ" << endl;

	int select = 0;
	cin>>select;
	string tip;
	string fileName;
	string Errortip;//������ʾ
	switch (select)
	{
	case 1:
	{
		//ѧ��
		fileName = STUDENT_FILE;
		tip = "������ѧ��ѧ�ţ�";
		Errortip = "ѧ���ظ�������������";
		break;
	}
	case 2:
	{
		//��ʦ
		fileName = TEACHER_FILE;
		tip = "�������ʦ���ţ�";
		Errortip = "ѧ���ظ�������������";
		break;
	}
	default:
		cout << "���ѡ�����������ѡ��" << endl;
		return;
	}

	string name;
	string Pwd;
	int num;
	bool ret;//�½�����ֵ�����ڷ����Ƿ����ظ�Ԫ��
	ofstream ofs;
	ofs.open(fileName, ios::out | ios::app);
	if (!ofs.is_open())
	{
		cout << "�ļ������ڣ��봴����" << endl;
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
	cout << "�����봴���û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> Pwd;
	ofs << num << " " << name << " " << Pwd << " " << endl;
	cout << "�����ɹ�" << endl;
	
	//�������� 
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
		cout << "ѧ��ѧ��Ϊ��" << s.m_Id << "ѧ������Ϊ��" << s.m_Name << endl;
	}
};

//ȫ�ֺ���or�º���
void PrintTeacher(Teacher& tea)
{
	cout << "��ʦѧ��Ϊ��" << tea.m_EmpId << "��ʦ����Ϊ��" << tea.m_Name << endl;
}



//�鿴�˺�
void Manager::ShowPerson()
{
	////����ע��Ϊû����Vectorʱ��Ĳ���  ���ļ���
	cout << "������鿴�˺ŵ����ͣ�" << endl;
	cout << "1��ѧ��" << endl;
	cout << "2����ʦ" << endl;
	int select = 0;
	//string fileName;
	cin >> select;
	//int num;
	//string name;
	//string Pwd;
	switch (select)
	{
	case 1:
		//ѧ��	
	{
		cout << "ѧ����Ϣ���£�" << endl;
		for_each(Vstu.begin(), Vstu.end(), PrintStudent());  //PrintStudent()�º���
	//	fileName = STUDENT_FILE;
		break;
	}
	case 2:
		//��ʦ	
	{
		cout << "��ʦ��Ϣ���£�" << endl;
		for_each(VTea.begin(), VTea.end(), PrintTeacher);  //��Ա��������ȫ�ֺ���
	//	fileName = TEACHER_FILE;
		break;
	}
	default:
		cout << "����������������룻" << endl;
		break;
	 }
	//ifstream ifs;
	//ifs.open(fileName, ios::in);
	//while (!ifs.is_open())
	//{
	//	cout << "�ļ���ʧ�ܣ����飡" << endl;
	//	ifs.close();
	//	system("pause");
	//	system("cls");
	//	return;
	//}
	////���һֱ���ļ��������
	//while (ifs >> num && ifs >> name && ifs >> Pwd)
	//{
	//	cout << "�û����Ϊ��" << num << "�û�����Ϊ��" << name << "����Ϊ��" << Pwd << endl;
	//}
	//ifs.close();
	system("pause");
	system("cls");
}


//�鿴������Ϣ
void Manager::ShowComputer()
{
	for (vector<Computer>::iterator it = VCom.begin(); it != VCom.end(); it++)
	{
		cout << "��������Ϊ��" << it->m_ComId << "�����������Ϊ��" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}


//��ղ���
void Manager::ClearFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	//ofs.open(ORDER_FILE, ios::trunc);//���ļ���������ڲ�
	//�������ȷ����Ϣ�����Ƿ�ȷ����գ�
	ofs.close();
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}


//��ʼ��ѧ���ͽ�ʦ��Ϣ�ļ�
void Manager::initVector()
{
	//��ղ���
	Vstu.clear();
	VTea.clear();

	/*string name;
	string Pwd;
	int num;*/
	ifstream ifs;
	//ѧ����ز���
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�������" << endl;
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
	cout << "��ǰѧ������������" << Vstu.size() << endl;
	ifs.close();

	//��ʦ����
	ifs.open(TEACHER_FILE,ios::in);
	while (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�����" << endl;
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
	cout << "��ǰ��ʦ����������" << VTea.size() << endl;
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

bool Manager::checkReport(int id, int type)
{
	//��������1Ϊѧ��������2Ϊ��ʦ
	switch (type)
	{
	case 1:
	{
		//find(Vstu.begin(), Vstu.end(), id);
		for (vector<Student>::iterator it = Vstu.begin(); it != Vstu.end(); it++)
		{
			if (it->m_Id == id)
				return true;//���ظ�
		}
		break;
	}
	case 2:
	{
		for (vector<Teacher>::iterator it = VTea.begin(); it != VTea.end(); it++)
		{
			if (it->m_EmpId == id)
				return true;//���ظ�
		}
		break;
	}	
	default:
		cout << "�ж�ʧ�ܣ��������ж�" << endl;
		break;
	}
	return false;
}
