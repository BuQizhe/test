#include<stdio.h>
int main()
{
	int i, n, m, j, k, x, y, z;
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf_s("%d%d%d", &x, &y, &z);
		if (y == 9 && z == 30)
			printf("YES\n");
		else if (y == 11 && z == 30)
			printf("YES\n");
		else if ((y + z) % 2 == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
