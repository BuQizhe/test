#include"Date.h"

int main()
{
	Date d1(2024, 9, 1);
	Date d2 = d1 + 50; 

	d1.Print();
	d2.Print();

	return 0;
}