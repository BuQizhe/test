#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int STDtaType;
typedef struct Sack
{
	STDtaType* a;
	int top;
	int capacity;
}ST;

//
void STInit(ST* ps);
void STDestroy(ST* ps);

//Õ»¶¥
void STPush(ST* ps, STDtaType x);
void STPop(ST* ps);
STDtaType STTop(ST* ps);
int STSize(ST* ps);
bool STEmpty(ST* ps);
