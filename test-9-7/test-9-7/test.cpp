#include"Date.h"

int main()
{
	Date d1(2024, 9, 1);
	Date d2 = d1 + 50;

	d1.Print();
	d2.Print();

	Date d3(2024, 9, 1);
	Date d4 = d3- 50;

	d3.Print();
	d4.Print();


	Date d5(2024, 9, 9);
	d5 += -5000;
	d5.Print();


	return 0;
}