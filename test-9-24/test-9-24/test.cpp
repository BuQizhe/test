#include<iostream>
#include<malloc.h>
#define MaxL 100
typedef int KeyType;
typedef char InfoType;

typedef struct
{
	KeyType key;
	InfoType data;
}RecType;

void CreateList(RecType R[], KeyType keys[], int n)//����˳���
{
	for (int i = 0; i < n; i++)         //R[0.....n-1]�������˳��
	{
		R[i].key = keys[i];
	}
}

void DispList(RecType R[], int n)   //���
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", R[i].key);
	}
	printf("%d ");
}


int SeqSearch(RecType R[], int n, KeyType k)//˳������㷨
{
	int i = 0;
	while (i < n && R[i].key != k)
	{
		printf("%d ", R[i].key);
		i++;                             //�ӱ�ͷ������
	}
	if (i>=n)
	{
		return 0;
	}
	else
	{
		printf("%d ", R[i].key);
		return i + 1;
	}

}

int main()
{
	RecType R[MaxL];
	int n = 10, i;
	KeyType k = 5;
	int a[] = { 3,6,2,10,1,8,5,7,4,9 };
	CreateList(R, a, n);                    //����˳���
	printf("�ؼ������У�");
	DispList(R, n);
	printf("\n����%d���ȽϵĹؼ��֣�\t", k);
	if ((i=SeqSearch(R,n,k))!=0)
	{
		printf("\nԪ��%d��λ����%d\n",k,i);
	}
	else
	{
		printf("\nԪ�ز��ڱ���\n", k);
	}
	return 1;
}