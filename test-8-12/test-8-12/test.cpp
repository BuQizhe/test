#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include <conio.h> 
#include "windows.h"
#include<iostream>
using namespace std;
#include <iomanip>
using std::setw;
#define MAX 1000//���ѧ������
string HelloKey;

//ѧ���ṹ��
typedef struct Student
{
	int  StuId;//ѧ��ѧ��
	char StuName[20];//ѧ������
	char StuGender[10];//ѧ���Ա�
	int  StuAge;//ѧ������
	char StuClass[40];//ѧ�������༶
	int StuRoom;//ѧ�������
}Student;

//����ָ��
typedef struct Points
{
	int a;
	Points* points;
}Points;

char Revise[10] = "�޸�";
char Search[10] = "��ѯ";
char Id[] = "ѧ��";
char Name[] = "����";
char Gender[] = "�Ա�";
char Age[] = "����";
char Class[] = "�༶";
char Room[] = "����";

//�������˵�
void Pause()
{
	int i;
	cout << "\n���س����������˵�!" << endl;
	_getch();
}

//���
void Print(Student stu[], int point)
{
	cout << "\n\nѧ��:" << stu[point].StuId << "����:" << stu[point].StuName << "�Ա�:" << stu[point].StuGender
		<< "����:" << stu[point].StuAge << "�༶:" << stu[point].StuClass << "�����:" << stu[point].StuRoom << endl;
}

//����ʧ��
void PrintNotFound()
{
	cout << "����ʧ�ܣ��Ҳ���������" << endl;
}

//������ҽ��
void PrintSearch(Student stu[], int i)
{
	cout << std::left << "      " << setw(12) << stu[i].StuId << setw(13) << stu[i].StuName << setw(12) << stu[i].StuGender <<
		setw(10) << stu[i].StuAge << setw(15) << stu[i].StuClass << setw(10) << stu[i].StuRoom << endl;
}

//�����ͷ
void PrintHead()
{
	cout << "*******************************************************************************" << endl;
	cout << "      ѧ�ţ�      ������      �Ա�      ���䣺      �༶��      ����ţ�" << endl;
	cout << "*******************************************************************************" << endl;
}

//���������򷵻����˵�
int a = 1;//Ĭ�ϼ���
//���������밴1,�������˵��밴0
void SelectOperate()
{
button:

	cout << "���������밴1,�������˵��밴0" << endl;
	cin >> a;
	if (!(a == 1 || a == 0))
	{
		cout << "�����������������" << endl;
		//	_getch();
		goto button;
	}
}

//��ȡ�ļ��������ܸ���
int ReadFile(Student stu[])
{
	FILE* fp;
	int point = -1;
	if ((fp = fopen("Student.txt", "r")) == NULL)
	{
		cout << "\nѧ�������ļ������ڣ��봴��" << endl;
		return 0;
	}
	while (!feof(fp))
	{
		point++;
		fread(&stu[point], sizeof(Student), 1, fp);
	}
	fclose(fp);
	return point;
}

//�洢���ݵ��ļ��� 
void SaveFile(Student stu[], int sum)//sum���ܸ��� 
{
	FILE* fp;
	int i;
	if ((fp = fopen("Temp.txt", "w")) == NULL)
	{
		printf("д�ļ�����!\n");
		return;
	}
	for (i = 0; i < sum; i++)
		if (fwrite(&stu[i], sizeof(Student), 1, fp) != 1)
			printf("д�ļ�����!\n");

	fclose(fp);
	remove("Student.txt");
	rename("Temp.txt", "Student.txt");

}

//����ѧ����Ϣ�����ص�������
int InPut(Student stu[], int sum)
{
	int x;
	for (; sum < MAX; sum++)
	{
		system("cls");//����
		cout << "\t\t\t" << "**********************************" << endl;
		cout << "\t\t\t" << "*                                *" << endl;
		cout << "\t\t\t" << "*        ����ѧ��������Ϣ        *" << endl;
		cout << "\t\t\t" << "*                                *" << endl;
		cout << "\t\t\t" << "**********************************" << endl;
		cout << endl << endl;
		cout << "           ��¼���" << sum + 1 << "ѧ����Ϣ  (���" << MAX << "��)" << endl;
		cout << "������ѧ����ѧ��:";
		cin >> stu[sum].StuId;
		cout << "������ѧ��������:";
		cin >> stu[sum].StuName;
		cout << "������ѧ�����Ա�:";
		cin >> stu[sum].StuGender;
		cout << "������ѧ��������:";
		cin >> stu[sum].StuAge;
		cout << "������ѧ���İ༶:";
		cin >> stu[sum].StuClass;
		cout << "������ѧ���������:";
		cin >> stu[sum].StuRoom;
		cout << "�����ɹ���" << endl;

		//ѡ�����
		SelectOperate();
		if (a == 0)
		{
			return sum + 1;
		}
	}
	return sum + 1;
}

//��ӡѧ����Ϣ
void OutPut(Student stu[], int sum)
{
	int i;
	system("cls");
	cout << "\t\t\t" << "**********************************" << endl;
	cout << "\t\t\t" << "*                                *" << endl;
	cout << "\t\t\t" << "*        ��ӡѧ��������Ϣ        *" << endl;
	cout << "\t\t\t" << "*                                *" << endl;
	cout << "\t\t\t" << "**********************************" << endl;
	PrintHead();
	for (i = 0; i < sum; i++)
	{
		PrintSearch(stu, i);
	}
	Pause();

}

//����
//����Student,�źõ�װ��һ���µ�students������ ����Ҫ�浽�ļ���
void CopyStu(Student stu0[], Student stu[], int sum)
{
	int i;
	for (i = 0; i < sum; i++)
	{
		stu[i].StuId = stu0[i].StuId;
		strcpy(stu[i].StuName, stu0[i].StuName);
		strcpy(stu[i].StuGender, stu0[i].StuGender);
		stu[i].StuAge = stu0[i].StuAge;
		strcpy(stu[i].StuClass, stu0[i].StuClass);
		stu[i].StuRoom = stu0[i].StuRoom;
	}
}

//��������Ԫ��
void ExchangeData(Student* stu1, Student* stu2)
{
	stu1->StuId = stu2->StuId;
	stu1->StuRoom = stu2->StuRoom;
	stu1->StuAge = stu2->StuAge;
	strcpy(stu1->StuName, stu2->StuName);
	strcpy(stu1->StuGender, stu2->StuGender);
	strcpy(stu1->StuClass, stu2->StuClass);
}

//����˵�
int SelectSort()
{
	int ch;
	cout << "\t\t\t" << "**************************************" << endl;
	cout << "\t\t\t" << "*        ����ѡ��������������        *" << endl;
	cout << "\t\t\t" << "*             1. ѧ��                *" << endl;
	cout << "\t\t\t" << "*             2. �༶                *" << endl;
	cout << "\t\t\t" << "*             3. �����              *" << endl;
	cout << "\t\t\t" << "*             4. ����                *" << endl;
	cout << "\t\t\t" << "*             0. �������˵�          *" << endl;
	cout << "\t\t\t" << "**************************************" << endl;
	cin >> ch;
	return ch;
}

//��������Ŵ�С��������ð�ݣ�
void Sort_Room(Student stu0[], int sum, Student stup[])
{
	Student stu1;//�����м�ֵ
	int i, j;
	CopyStu(stu0, stup, sum);
	for (i = 0; i < sum - 1; i++)
	{
		for (j = 0; j < sum - 1 - i; j++)
		{
			if (stup[j].StuRoom > stup[j + 1].StuRoom)
			{
				ExchangeData(&stu1, &stup[j]);
				ExchangeData(&stup[j], &stup[j + 1]);
				ExchangeData(&stup[j + 1], &stu1);
			}
		}
	}
}

//���ݰ༶��С��������ѡ��
void Sort_Class(Student stu0[], int sum, Student stup[])
{
	Student stu1;
	int i, j, k = 0;
	CopyStu(stu0, stup, sum);
	for (i = 0; i < sum - 1; i++)
	{
		k = i;
		for (j = i + 1; j < sum; j++)
		{
			if (strcmp(stup[k].StuClass, stup[j].StuClass) > 0)
			{
				k = j;
			}
		}
		if (i != k)
		{
			ExchangeData(&stu1, &stup[i]);
			ExchangeData(&stup[i], &stup[k]);
			ExchangeData(&stup[k], &stu1);
		}
	}
}

//���������Ӵ�С�����۰��������
//��Ϊ�����Ǵ�stu[1]��ʼ������,���Ե��ٴ����м����
void Sort_Name(Student stu0[], int sum, Student stup[])
{
	Student stu1;//�м����
	Student stu[1000];
	int i, j, low, high, mid;
	for (i = 0; i < sum; i++) {
		stu[i + 1].StuId = stu0[i].StuId;
		strcpy(stu[i + 1].StuName, stu0[i].StuName);
		strcpy(stu[i + 1].StuGender, stu0[i].StuGender);
		stu[i + 1].StuAge = stu0[i].StuAge;
		strcpy(stu[i + 1].StuClass, stu0[i].StuClass);
		stu[i + 1].StuRoom = stu0[i].StuRoom;
	}

	for (i = 2; i < sum + 1; i++) {
		ExchangeData(&stu1, &stu[i]);    //���������Ԫ�ص�stu1
		low = 1; high = i - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (strcmp(stu1.StuName, stu[mid].StuName) > 0)
				low = mid + 1;
			else
				high = mid - 1;
		}

		for (j = i - 1; j >= high + 1; j--)
			ExchangeData(&stu[j + 1], &stu[j]);//����Ԫ�أ����������λ 
		ExchangeData(&stu[high + 1], &stu1);
	}

	for (i = 0; i < sum; i++) {
		stup[i].StuId = stu[i + 1].StuId;
		strcpy(stup[i].StuName, stu[i + 1].StuName);
		strcpy(stup[i].StuGender, stu[i + 1].StuGender);
		stup[i].StuAge = stu[i + 1].StuAge;
		strcpy(stup[i].StuClass, stu[i + 1].StuClass);
		stup[i].StuRoom = stu[i + 1].StuRoom;
	}

}

//����ѧ�Ŵ�С�������򣨲���ϣ������
void ShellInsert(Student stup[], int sum, int dk)
{
	int i, j, k;
	Student stu1;//�м����
	for (k = 0; k < dk; k++)
		for (i = dk + k; i < sum; i = i + dk)
			if (stup[i].StuId < stup[i - dk].StuId)
			{
				ExchangeData(&stu1, &stup[i]);
				for (j = i - dk; j >= 0 && stu1.StuId < stup[j].StuId; j = j - dk)//��¼�����    			
					ExchangeData(&stup[j + dk], &stup[j]);
				ExchangeData(&stup[j + dk], &stu1);
			}
}
void Sort_Id(Student stu[], int sum, Student stup[])
{
	int i, x;
	CopyStu(stu, stup, sum);
	int dlta[5] = { 5,4,3,2,1 };
	for (x = 0; x < 5; x++)
		ShellInsert(stup, sum, dlta[x]);
}

//����������
void SortStudent(Student stu[], int sum)
{
	Student stup[1000];//���ź���ķ�������
	int ch, x, i;
	do {
		system("cls");//����
		cout << "\t\t\t" << "**********************************" << endl;
		cout << "\t\t\t" << "*                                *" << endl;
		cout << "\t\t\t" << "*        ѧ��������Ϣ����        *" << endl;
		cout << "\t\t\t" << "*                                *" << endl;
		cout << "\t\t\t" << "**********************************" << endl;
	select:
		ch = SelectSort();//����˵�

		system("cls");
		cout << "\t\t\t" << "**********************************" << endl;
		cout << "\t\t\t" << "*                                *" << endl;
		cout << "\t\t\t" << "*        ѧ��������Ϣ����        *" << endl;
		cout << "\t\t\t" << "*                                *" << endl;
		cout << "\t\t\t" << "**********************************" << endl;

		switch (ch)
		{
		case 1:Sort_Id(stu, sum, stup); break;//��ѧ������
		case 2:Sort_Class(stu, sum, stup); break;//���༶����
		case 3:Sort_Room(stu, sum, stup); break;//����������
		case 4:Sort_Name(stu, sum, stup); break;//����������
		case 0:return;
		default:cout << "�����������������" << endl; goto select;
		}
		//������ӡ���
		PrintHead();
		for (i = 0; i < sum; i++)
		{
			PrintSearch(stup, i);
		}
		if (ch == 1 || ch == 2 || ch == 3 || ch == 4)
		{
			cout << endl << endl;
		button:
			cout << "���������밴1,�������˵��밴0 " << endl;
			cin >> x;
			if (x == 1)
				x = 1;
			else if (x == 0)
				continue;
			else
			{
				cout << "�����������������" << endl;
				goto button;
			}
		}
		else if (ch == 0)
			x = 0;
		else
		{
			cout << "�����������������" << endl;
			goto select;
		}

	} while (x == 1);//x==1ѭ����x==0�������˵�
}

//��ѯ���޸ĵ�ѡ��˵�
int SelectChoice(char condition[20])
{
	int choice;
	cout << "\t\t\t" << "**************************************" << endl;
	cout << "\t\t\t" << "*        ����ѡ����������" << condition << "        *" << endl;
	cout << "\t\t\t" << "*             1. ѧ��                *" << endl;
	cout << "\t\t\t" << "*             2. ����                *" << endl;
	cout << "\t\t\t" << "*             3. �Ա�                *" << endl;
	cout << "\t\t\t" << "*             4. ����                *" << endl;
	cout << "\t\t\t" << "*             5. �༶                *" << endl;
	cout << "\t\t\t" << "*             6. �����              *" << endl;
	cout << "\t\t\t" << "*             0. �������˵�          *" << endl;
	cout << "\t\t\t" << "**************************************" << endl;
	cin >> choice;
	return choice;
}

Points* ConnectPoint(Points* r, Points* p, int i) {
	p = new Points;
	p->a = i;
	r->points = p;
	r = p;
	return r;
}

//choiceΪ����ѡ��conditionΪ������ѧ�ţ��������Ա����䣬�༶������ţ�
Points* FindPoint(Student stu[], int sum, int choice, char condition[])
{
	int i, j = 0; Points* p, * q, * r; q = new Points; p = new Points; r = q;
	int StuId, StuAge, StuRoom; char StuClass[20], StuGender[5], StuName[20];
	cout << "��������Ҫ���ҵ�ѧ����" << condition;
	switch (choice)
	{
	case 1:
		cin >> StuId;
		for (i = 0; i < sum; i++)
		{
			if (StuId == stu[i].StuId)
			{
				r = ConnectPoint(r, p, i);
			}
		}
		break;

	case 2:
		cin >> StuName;
		for (i = 0; i < sum; i++)
		{
			if (strcmp(StuName, stu[i].StuName) == 0)
			{
				r = ConnectPoint(r, p, i);
			}
		}
		break;

	case 3:
		cin >> StuGender;
		for (i = 0; i < sum; i++)
		{
			if (strcmp(StuGender, stu[i].StuGender) == 0)
			{
				r = ConnectPoint(r, p, i);
			}
		}
		break;
	case 4:
		cin >> StuAge;
		for (i = 0; i < sum; i++)
		{
			if (StuAge == stu[i].StuAge)
			{
				r = ConnectPoint(r, p, i);
			}
		}
		break;
	case 5:
		cin >> StuClass;
		for (i = 0; i < sum; i++)
		{
			if (strcmp(StuClass, stu[i].StuClass) == 0)
			{
				r = ConnectPoint(r, p, i);
			}
		}
		break;
	case 6:
		cin >> StuRoom;
		for (i = 0; i < sum; i++)
		{
			if (StuRoom == stu[i].StuRoom)
			{
				r = ConnectPoint(r, p, i);
			}
		}
		break;
	}
	r->points = NULL;
	return q;
}

//��ѯѧ����Ϣ
void Inquire(Student stu[], int sum)
{
	int choice;
	Points* p;
	do {
		system("cls");//����
		cout << "\t\t\t" << "**********************************" << endl;
		cout << "\t\t\t" << "*                                *" << endl;
		cout << "\t\t\t" << "*        ��ѯѧ��������Ϣ        *" << endl;
		cout << "\t\t\t" << "*                                *" << endl;
		cout << "\t\t\t" << "**********************************" << endl;
	button:
		choice = SelectChoice(Search);
		system("cls");//����
		cout << "\t\t\t" << "**********************************" << endl;
		cout << "\t\t\t" << "*                                *" << endl;
		cout << "\t\t\t" << "*        ��ѯѧ��������Ϣ        *" << endl;
		cout << "\t\t\t" << "*                                *" << endl;
		cout << "\t\t\t" << "**********************************" << endl;
		switch (choice)
		{
		case 1: p = FindPoint(stu, sum, choice, Id); break;
		case 2: p = FindPoint(stu, sum, choice, Name); break;
		case 3: p = FindPoint(stu, sum, choice, Gender); break;
		case 4: p = FindPoint(stu, sum, choice, Age); break;
		case 5: p = FindPoint(stu, sum, choice, Class); break;
		case 6: p = FindPoint(stu, sum, choice, Room); break;
		case 0: return;
		default:
			cout << "���������������ȷ��ָ��" << endl; goto button;//��ѯѭ��
		}
		if (p->points != NULL)
		{
			p = p->points;
			PrintHead();
			while (p != NULL)
			{
				PrintSearch(stu, p->a);
				p = p->points;
			}
		}
		else
			PrintNotFound();
		SelectOperate();//���������򷵻����˵�
	} while (a);//Ĭ��a==1ѭ����ѡ��a==0,�򷵻����˵�
}

//���ֲ��ң�Ŀǰ��ѧ�ţ����������ᣩ
Points* FindPoint2(Student stu[], int sum, int choice, char condition[])
{
	int i, j = 0; Points* p, * q, * r; q = new Points; p = new Points; r = q;
	int StuId, StuAge, StuRoom; char StuClass[20], StuGender[5], StuName[20];
	cout << "��������Ҫ���ҵ�ѧ����" << condition;
	switch (choice)
	{
	case 1: cin >> StuId; break;
	case 2: cin >> StuName; break;
	case 3: cin >> StuRoom; break;
	}
	int flag = 0;
	int low = 0, high = sum - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		switch (choice)
		{
		case 1: if (StuId == stu[mid].StuId)
		{
			r = ConnectPoint(r, p, mid);
			flag = 1;
		}
			  else if (stu[mid].StuId > StuId)
		{
			high = mid - 1;
		}
			  else
		{
			low = mid + 1;
		}
			  break;
		case 2: if (strcmp(StuName, stu[mid].StuName) == 0)
		{
			r = ConnectPoint(r, p, mid);
			flag = 1;
		}
			  if (strcmp(stu[mid].StuName, StuName) > 0)
			  {
				  high = mid - 1;
			  }
			  else
			  {
				  low = mid + 1;
			  }
			  break;
		case 3: if (StuRoom == stu[mid].StuRoom)
		{
			r = ConnectPoint(r, p, mid);
			flag = 1;
		}
			  else if (stu[mid].StuRoom > StuRoom)
		{
			high = mid - 1;
		}
			  else
		{
			low = mid + 1;
		}
			  break;
		}
		//�ҵ�������ѭ��
		if (flag)
			break;
	}
	r->points = NULL;
	return q;
}

//���ַ���ѯѧ����Ϣ
void Inquire2(Student stu[], int sum)
{
	Student stup1[1000];//���ã����ź���ķ����������ԭ���Ļ��� 
	Student stup2[1000];//���ã����ź���ķ����������ԭ���Ļ��� 
	Student stup3[1000];//���ã����ź���ķ����������ԭ���Ļ��� 
	//�������ٶ���
	Sort_Id(stu, sum, stup1);
	Sort_Name(stu, sum, stup2);
	Sort_Room(stu, sum, stup3);
	int choice;
	Points* p; p = new Points;
	do
	{
		system("cls");//����
		cout << "\t\t\t" << "**********************************" << endl;
		cout << "\t\t\t" << "*                                *" << endl;
		cout << "\t\t\t" << "*        ��ѯѧ��������Ϣ        *" << endl;
		cout << "\t\t\t" << "*                                *" << endl;
		cout << "\t\t\t" << "**********************************" << endl;
	botton:
		cout << "\t\t\t" << "**************************************" << endl;
		cout << "\t\t\t" << "*        ����ѡ���������в�ѯ        *" << endl;
		cout << "\t\t\t" << "*             1. ѧ��                *" << endl;
		cout << "\t\t\t" << "*             2. ����                *" << endl;
		cout << "\t\t\t" << "*             3. �����              *" << endl;
		cout << "\t\t\t" << "*             0. �������˵�          *" << endl;
		cout << "\t\t\t" << "**************************************" << endl;
		cin >> choice;
		system("cls");//����
		cout << "\t\t\t" << "**********************************" << endl;
		cout << "\t\t\t" << "*                                *" << endl;
		cout << "\t\t\t" << "*        ��ѯѧ��������Ϣ        *" << endl;
		cout << "\t\t\t" << "*                                *" << endl;
		cout << "\t\t\t" << "**********************************" << endl;
		switch (choice)
		{
		case 1:p = FindPoint2(stup1, sum, choice, Id); break;//���ַ���ѯ(ѧ��) 
		case 2:p = FindPoint2(stup2, sum, choice, Name); break;//���ַ���ѯ(����)
		case 3:p = FindPoint2(stup3, sum, choice, Room); break;//���ַ���ѯ(�����)
		case 0:return;
		default:cout << "�����������������" << endl; goto botton;//ѭ��
		}
		if (p->points != NULL)
		{
			p = p->points;
			PrintHead();
			while (p != NULL)
			{
				if (choice == 1) {
					PrintSearch(stup1, p->a);
					p = p->points;
				}
				if (choice == 2) {
					PrintSearch(stup2, p->a);
					p = p->points;
				}
				if (choice == 3) {
					PrintSearch(stup3, p->a);
					p = p->points;
				}
			}
		}
		else
			PrintNotFound();
		//ѡ�������ѯ�����˻����˵�
		SelectOperate();
	} while (a);
}

//ѡ����ҷ���
void SelectInquire(Student stu[], int sum)
{
	int ch;
	system("cls");
button:

	cout << "\t\t\t" << "**************************************" << endl;
	cout << "\t\t\t" << "*        ����ѡ�񷽷����в�ѯ        *" << endl;
	cout << "\t\t\t" << "*             1. ˳�����            *" << endl;
	cout << "\t\t\t" << "*             2. ���ֲ���            *" << endl;
	cout << "\t\t\t" << "*             0. �������˵�          *" << endl;
	cout << "\t\t\t" << "**************************************" << endl;
	cin >> ch;
	switch (ch)
	{
	case 1: Inquire(stu, sum); break;//˳�����
	case 2: Inquire2(stu, sum); break;//���ֲ���
	case 0: return;
	default:cout << "�������!����������" << endl; goto button;//ѭ��
	}
}

//�޸ĺ�ɾ���ж�����ѧ������ 
int OperateNum(int sum)
{
	int n;
	cout << "��������Ҫ������ѧ������" << endl;
	cin >> n;
	if (n > sum)
	{
		cout << "����ʧ��!����ѧ����������ѧ������" << endl;
		SelectOperate();
		return 0;
	}
	else if (n <= 0)
	{
		cout << "����ʧ��!����ѧ����������С�ڻ������" << endl;
		SelectOperate();
		return 0;
	}
	return n;
}

//����ѧ��ɾ��ѧ����Ϣ
int Delete(Student stu[], int sum)
{
	a = 1;
	system("cls");//����
	int i, j = 0, n = 0, flag = 1;
	Points* p;
	cout << "\t\t\t" << "**********************************" << endl;
	cout << "\t\t\t" << "*                                *" << endl;
	cout << "\t\t\t" << "*        ɾ��ѧ��������Ϣ        *" << endl;
	cout << "\t\t\t" << "*                                *" << endl;
	cout << "\t\t\t" << "**********************************" << endl;
	while (n == 0)
	{
		n = OperateNum(sum);//������ȷ���ظ��������벻��ȷ����0��n=0��,SelectOperate()����ѡ��a��ȡֵ�������򷵻����˵���
		if (a == 0)
			return sum;
	}
	do {
		if (flag) {
			system("cls");
			Points* p;
			cout << "\t\t\t" << "**********************************" << endl;
			cout << "\t\t\t" << "*                                *" << endl;
			cout << "\t\t\t" << "*        ɾ��ѧ��������Ϣ        *" << endl;
			cout << "\t\t\t" << "*                                *" << endl;
			cout << "\t\t\t" << "**********************************" << endl;
		}
		//��һ��ɾһ��
		p = FindPoint(stu, sum, 1, Id);
		p = p->points;
		if (p != NULL)
		{
			i = p->a;
			//�Ѻ����һ�θ��ǵ�ǰ��һ�� 
			for (; i < sum - 1; i++)
			{
				ExchangeData(&stu[i], &stu[i + 1]);
			}
			cout << "������Ϣɾ���ɹ���" << endl;
			flag = 0;
			j++;
			if (j == n)
			{
				cout << "���ȫ��ɾ��������" << endl;
				SelectOperate();//���������밴1,�������˵��밴0
				if (a == 0)
					return sum - n;//ʣ��ѧ����Ϣ����
				else
					Delete(stu, sum - n);
			}
		}
		else
		{
			cout << "�����ѧ�Ų����ڣ�" << endl;
			SelectOperate();
			if (a == 0)
				return sum - j;
		}
	} while (a == 1 && j < n);
}

//����ѧ���޸�ѧ����Ϣ
void Change(Student stu[], int sum)
{
	int choice;
	Points* p;
	do
	{
		system("cls");
		cout << "\t\t\t" << "**********************************" << endl;
		cout << "\t\t\t" << "*                                *" << endl;
		cout << "\t\t\t" << "*        �޸�ѧ��������Ϣ        *" << endl;
		cout << "\t\t\t" << "*                                *" << endl;
		cout << "\t\t\t" << "**********************************" << endl;
		p = FindPoint(stu, sum, 1, Id);//�Ȳ�����ɾ��
		p = p->points;
		if (p != NULL)
		{
			system("cls");
			cout << "\t\t\t" << "**********************************" << endl;
			cout << "\t\t\t" << "*                                *" << endl;
			cout << "\t\t\t" << "*        �޸�ѧ��������Ϣ        *" << endl;
			cout << "\t\t\t" << "*                                *" << endl;
			cout << "\t\t\t" << "**********************************" << endl;
			int i = p->a;
			Print(stu, i);
		button:
			choice = SelectChoice(Revise);
			switch (choice)
			{
			case 1: cout << "��������Ҫ�޸ĵ���ѧ��:";
				cin >> stu[i].StuId;
				break;
			case 2: cout << "��������Ҫ�޸ĵ�������:";
				cin >> stu[i].StuName;
				break;
			case 3: cout << "��������Ҫ�޸ĵ����Ա�:";
				cin >> stu[i].StuGender;
				break;
			case 4: cout << "��������Ҫ�޸ĵ�������:";
				cin >> stu[i].StuAge;
				break;
			case 5: cout << "��������Ҫ�޸ĵ��°༶:";
				cin >> stu[i].StuClass;
				break;
			case 6: cout << "��������Ҫ�޸ĵ��������:";
				cin >> stu[i].StuRoom;
				break;
			case 0:
				return;
			default:
				cout << "�����������������" << endl;
				goto button;
			}
			cout << "�޸ĳɹ�!" << endl;
			Print(stu, i);
		}
		else
			PrintNotFound();
		SelectOperate();
		if (a == 0)
		{
			return;
		}
	} while (a);
}

void SystemMain();
//��ӭ���������������
int HelloKey_Result()
{
	int n = 5;//����������
	for (int i = 1; i <= n; i++)
	{
		if (HelloKey == "admin123")//Ĭ��ϵͳ����
		{
			return 1;
		}
		else
		{
			if (i < n)
			{
				cout << "����������������롣"
					<< "���Ѿ�������" << i << "��," << "ʣ��" << n - i << "�λ���" << endl;
				cin >> HelloKey;

			}
			if (i == n)
			{
				cout << "����������Ѿ�����" << i << "��,�Զ��˳��������ϵͳ��" << endl;
				exit(0);
			}

		}
	}

}

//�˳�����
void Bye()
{
	cout << "�ɹ��˳�!��л����ʹ��" << endl;
	cout << "��ӭ���´�ʹ���������ϵͳ��" << endl;
}

//��ӭ����
void Hello()
{
	cout << "\t\t\t" << "**********************************" << endl;
	cout << "\t\t\t" << "*        ���������ѯ����        *" << endl;
	cout << "\t\t\t" << "*          �����:               *" << endl;
	cout << "\t\t\t" << "*        ָ����ʦ:               *" << endl;
	cout << "\t\t\t" << "*           רҵ:                *" << endl;
	cout << "\t\t\t" << "*        2024��XX��XX��          *" << endl;
	cout << "\t\t\t" << "**********************************" << endl;
	cout << endl;
	cout << "������ϵͳ����:(admin123)" << endl;
	cin >> HelloKey;
	HelloKey_Result();
}

//�������ϵͳ��ҳ��
void SystemMain()
{
	Student stu[20];
	int choice, sum;
	sum = ReadFile(stu);
	if (sum == 0)
	{
		//		cout << "������Ϣ¼��ϵͳ,���س�������" << endl;
		//		_getch();
		cout << "3����Զ�������Ϣ¼��ϵͳ..." << endl;
		Sleep(3000);
		sum = InPut(stu, sum);
	}
	system("cls");
	do
	{
		system("cls");//����
	button:
		cout << "��ӭ�������������ϵͳ" << endl;
		cout << "\t\t\t" << "********************************************" << endl;
		cout << "\t\t\t" << "*          ������˵���ѡ�����Ĳ���        *" << endl;
		cout << "\t\t\t" << "*              1.¼��ѧ��������Ϣ          *" << endl;
		cout << "\t\t\t" << "*              2.��ӡѧ��������Ϣ          *" << endl;
		cout << "\t\t\t" << "*              3.��ѯѧ��������Ϣ          *" << endl;
		cout << "\t\t\t" << "*              4.�޸�ѧ��������Ϣ          *" << endl;
		cout << "\t\t\t" << "*              5.ɾ��ѧ��������Ϣ          *" << endl;
		cout << "\t\t\t" << "*              6.����ѧ��������Ϣ          *" << endl;
		cout << "\t\t\t" << "*              0.�˳��������ϵͳ          *" << endl;
		cout << "\t\t\t" << "********************************************" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: sum = InPut(stu, sum); break;//¼��ѧ����Ϣ
		case 2: OutPut(stu, sum); break;//��ӡѧ����Ϣ
		case 3: SelectInquire(stu, sum); break;//��ѯѧ����Ϣ
		case 4: Change(stu, sum); break;//�޸�ѧ����Ϣ
		case 5: sum = Delete(stu, sum); break;//ɾ��ѧ����Ϣ
		case 6: SortStudent(stu, sum);//����ѧ����Ϣ
		case 0: Bye(); break;
		default:cout << "�������!����������" << endl;
			goto button;
		}
		SaveFile(stu, sum);
	} while (choice != 0);
}

int main()
{
	Hello();
	SystemMain();

}