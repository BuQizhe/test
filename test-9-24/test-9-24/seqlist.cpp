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

void CreateList(RecType R[], KeyType keys[], int n)
{
	for (int i = 0; i < n; i++)
	{
		R[i].key = keys[i];
	}
}

void DispList(RecType R[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", R[i].key);
	}
	printf("%d");
}

