#include"Stack.h"

void STInit(ST* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
void STDestroy(ST* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

//Õ»¶¥
void STPush(ST* ps, STDtaType x)
{
	assert(ps);

	//ÂúÁË£¬À©ÈÝ
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDtaType* tmp = (STDtaType*)realloc(ps->a, newcapacity * sizeof(STDtaType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->a = tmp;
		ps->capacity = newcapacity;

	}

	ps->a[ps->top] = x;
	ps->top++;
}
void STPop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));

	ps->top--;
}
STDtaType STTop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));

	return ps->a[ps->top - 1];

}
int STSize(ST* ps)
{
	assert(ps);

	return ps->top;
}
bool STEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}