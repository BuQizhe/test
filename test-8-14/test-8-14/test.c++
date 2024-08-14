#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define OK 1
#define ERROR 0
#define Incerment 10
#define StackInitSize 100
typedef int Status;
typedef int SElemtype;
typedef struct
{
	SElemtype* top;
	SElemtype* base;
	int StackSize;
}path;
typedef struct mp
{
	SElemtype up;
	SElemtype down;
	SElemtype left;
	SElemtype right;
}maze_path[10][10];
int maze[10][10] =
{ {1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};
void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void color(const unsigned short textColor)
{
	if (textColor >= 0 && textColor <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
Status Search(maze_path& pat)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (maze[i][j] == 1)
			{
				pat[i][j].up = 0;
				pat[i][j].down = 0;
				pat[i][j].left = 0;
				pat[i][j].right = 0;
				continue;
			}
			else
			{
				if (maze[i - 1][j] == 1) pat[i][j].up = 0;
				else pat[i][j].up = 1;
				if (maze[i + 1][j] == 1) pat[i][j].down = 0;
				else pat[i][j].down = 1;
				if (maze[i][j - 1] == 1) pat[i][j].left = 0;
				else pat[i][j].left = 1;
				if (maze[i][j + 1] == 1) pat[i][j].right = 0;
				else pat[i][j].right = 1;
			}
		}
	}
}
Status InitSize(path& S)
{
	S.base = (SElemtype*)malloc(StackInitSize * sizeof(SElemtype));
	if (!S.base) return ERROR;
	S.top = S.base;
	S.StackSize = StackInitSize;
	return OK;
}
Status Pop(path& S, char& e)
{
	if (S.top == S.base) return ERROR;
	e = *--S.top;
	return e;
}
Status Push(path& S, char ch)
{
	if (S.top - S.base >= S.StackSize)
	{
		S.base = (SElemtype*)realloc(S.base, (S.StackSize + Incerment) * sizeof(SElemtype));
		if (!S.base) return ERROR;
		S.top = S.base + S.StackSize;
		S.StackSize += Incerment;
	}
	*S.top++ = ch;
	return OK;
}
Status Try(maze_path& pat)
{
	path pa;
	char ch, x;
	int i = 1, j = 1;
	InitSize(pa);
	Push(pa, 'y');
	system("cls");
	while (i < 10 && j < 10)
	{
		if (i == 8 && j == 8)
		{
			maze[i][j] = 9;
			break;
		}
		if (pat[i][j].right == 1)
		{
			Push(pa, 'r');
			maze[i][j] = 6;
			pat[i][j].right = 0;
			pat[i - 1][j].down = 0;
			pat[i + 1][j].up = 0;
			pat[i][j - 1].right = 0;
			pat[i][j + 1].left = 0;
			gotoxy(0, 0);
			printf("\n||- - - - - - - - - 菜单 - - - - - - - - -||\n");
			printf("|| - - - - - - - 1.迷宫求解 - - - - - - - ||\n");
			printf("|| - - - - - - - 2.输出迷宫 - - - - - - - ||\n\n");
			printf("请输入要执行的操作：1\n");
			printf("迷宫求解过程如下：\n\n");
			for (int m = 0; m < 10; m++)
			{
				for (int n = 0; n < 10; n++)
				{
					if (maze[m][n] == 8) printf("↑");
					if (maze[m][n] == 2) printf("↓");
					if (maze[m][n] == 4) printf("←");
					if (maze[m][n] == 6) printf("→");
					if (maze[m][n] == 5) printf("×");
					if (maze[m][n] == 1) printf("■");
					if (maze[m][n] == 0) printf(" ");
				}
				printf("\n");
			}
			Sleep(500);
			j++;
			continue;
		}
		if (pat[i][j].down == 1)
		{
			Push(pa, 'd');
			maze[i][j] = 2;
			pat[i][j].down = 0;
			pat[i - 1][j].down = 0;
			pat[i + 1][j].up = 0;
			pat[i][j - 1].right = 0;
			pat[i][j + 1].left = 0;
			gotoxy(0, 0);
			printf("\n||- - - - - - - - - 菜单 - - - - - - - - -||\n");
			printf("|| - - - - - - - 1.迷宫求解 - - - - - - - ||\n");
			printf("|| - - - - - - - 2.输出迷宫 - - - - - - - ||\n\n");
			printf("请输入要执行的操作：1\n");
			printf("迷宫求解过程如下：\n\n");
			for (int m = 0; m < 10; m++)
			{
				for (int n = 0; n < 10; n++)
				{
					if (maze[m][n] == 8) printf("↑");
					if (maze[m][n] == 2) printf("↓");
					if (maze[m][n] == 4) printf("←");
					if (maze[m][n] == 6) printf("→");
					if (maze[m][n] == 5) printf("×");
					if (maze[m][n] == 1) printf("■");
					if (maze[m][n] == 0) printf(" ");
				}
				printf("\n");
			}
			Sleep(500);
			i++;
			continue;
		}
		if (pat[i][j].left == 1)
		{
			Push(pa, 'l');
			maze[i][j] = 4;
			pat[i][j].left = 0;
			pat[i - 1][j].down = 0;
			pat[i + 1][j].up = 0;
			pat[i][j - 1].right = 0;
			pat[i][j + 1].left = 0;
			gotoxy(0, 0);
			printf("\n||- - - - - - - - - 菜单 - - - - - - - - -||\n");
			printf("|| - - - - - - - 1.迷宫求解 - - - - - - - ||\n");
			printf("|| - - - - - - - 2.输出迷宫 - - - - - - - ||\n\n");
			printf("请输入要执行的操作：1\n");
			printf("迷宫求解过程如下：\n\n");
			for (int m = 0; m < 10; m++)
			{
				for (int n = 0; n < 10; n++)
				{
					if (maze[m][n] == 8) printf("↑");
					if (maze[m][n] == 2) printf("↓");
					if (maze[m][n] == 4) printf("←");
					if (maze[m][n] == 6) printf("→");
					if (maze[m][n] == 5) printf("×");
					if (maze[m][n] == 1) printf("■");
					if (maze[m][n] == 0) printf(" ");
				}
				printf("\n");
			}
			Sleep(500);
			j--;
			continue;
		}
		if (pat[i][j].up == 1)
		{
			Push(pa, 'u');
			maze[i][j] = 8;
			pat[i][j].up = 0;
			pat[i - 1][j].down = 0;
			pat[i + 1][j].up = 0;
			pat[i][j - 1].right = 0;
			pat[i][j + 1].left = 0;
			gotoxy(0, 0);
			printf("\n||- - - - - - - - - 菜单 - - - - - - - - -||\n");
			printf("|| - - - - - - - 1.迷宫求解 - - - - - - - ||\n");
			printf("|| - - - - - - - 2.输出迷宫 - - - - - - - ||\n\n");
			printf("请输入要执行的操作：1\n");
			printf("迷宫求解过程如下：\n\n");
			for (int m = 0; m < 10; m++)
			{
				for (int n = 0; n < 10; n++)
				{
					if (maze[m][n] == 8) printf("↑");
					if (maze[m][n] == 2) printf("↓");
					if (maze[m][n] == 4) printf("←");
					if (maze[m][n] == 6) printf("→");
					if (maze[m][n] == 5) printf("×");
					if (maze[m][n] == 1) printf("■");
					if (maze[m][n] == 0) printf(" ");
				}
				printf("\n");
			}
			Sleep(500);
			i--;
			continue;
		}
		if (pat[i][j].up == 0 && pat[i][j].down == 0 && pat[i][j].left == 0 && pat[i][j].right == 0)
		{
			pat[i - 1][j].down = 0;
			maze[i][j] = 5;
			pat[i + 1][j].up = 0;
			pat[i][j - 1].right = 0;
			pat[i][j + 1].left = 0;
		}
		while (pat[i][j].up == 0 && pat[i][j].down == 0 && pat[i][j].left == 0 && pat[i][j].right == 0)
		{
			maze[i][j] = 5;
			pat[i - 1][j].down = 0;
			pat[i + 1][j].up = 0;
			pat[i][j - 1].right = 0;
			pat[i][j + 1].left = 0;
			x = Pop(pa, ch);
			if (x == 'r')
			{
				maze[i][j] == 5;
				gotoxy(0, 0);
				printf("\n||- - - - - - - - - 菜单 - - - - - - - - -||\n");
				printf("|| - - - - - - - 1.迷宫求解 - - - - - - - ||\n");
				printf("|| - - - - - - - 2.输出迷宫 - - - - - - - ||\n\n");
				printf("请输入要执行的操作：1\n");
				printf("迷宫求解过程如下：\n\n");
				for (int m = 0; m < 10; m++)
				{
					for (int n = 0; n < 10; n++)
					{
						if (maze[m][n] == 8) printf("↑");
						if (maze[m][n] == 2) printf("↓");
						if (maze[m][n] == 4) printf("←");
						if (maze[m][n] == 6) printf("→");
						if (maze[m][n] == 5) printf("×");
						if (maze[m][n] == 1) printf("■");
						if (maze[m][n] == 0) printf(" ");
					}
					printf("\n");
				}
				Sleep(500);
				j--;
			}
			if (x == 'd')
			{
				maze[i][j] == 5;
				gotoxy(0, 0);
				printf("\n||- - - - - - - - - 菜单 - - - - - - - - -||\n");
				printf("|| - - - - - - - 1.迷宫求解 - - - - - - - ||\n");
				printf("|| - - - - - - - 2.输出迷宫 - - - - - - - ||\n\n");
				printf("请输入要执行的操作：1\n");
				printf("迷宫求解过程如下：\n\n");
				for (int m = 0; m < 10; m++)
				{
					for (int n = 0; n < 10; n++)
					{
						if (maze[m][n] == 8) printf("↑");
						if (maze[m][n] == 2) printf("↓");
						if (maze[m][n] == 4) printf("←");
						if (maze[m][n] == 6) printf("→");
						if (maze[m][n] == 5) printf("×");
						if (maze[m][n] == 1) printf("■");
						if (maze[m][n] == 0) printf(" ");
					}
					printf("\n");
				}
				Sleep(500);
				i--;
			}
			if (x == 'l')
			{
				maze[i][j] == 5;
				gotoxy(0, 0);
				printf("\n||- - - - - - - - - 菜单 - - - - - - - - -||\n");
				printf("|| - - - - - - - 1.迷宫求解 - - - - - - - ||\n");
				printf("|| - - - - - - - 2.输出迷宫 - - - - - - - ||\n\n");
				printf("请输入要执行的操作：1\n");
				printf("迷宫求解过程如下：\n\n");
				for (int m = 0; m < 10; m++)
				{
					for (int n = 0; n < 10; n++)
					{
						if (maze[m][n] == 8) printf("↑");
						if (maze[m][n] == 2) printf("↓");
						if (maze[m][n] == 4) printf("←");
						if (maze[m][n] == 6) printf("→");
						if (maze[m][n] == 5) printf("×");
						if (maze[m][n] == 1) printf("■");
						if (maze[m][n] == 0) printf(" ");
					}
					printf("\n");
				}
				Sleep(500);
				j++;
			}
			if (x == 'u')
			{
				maze[i][j] == 5;
				gotoxy(0, 0);
				printf("\n||- - - - - - - - - 菜单 - - - - - - - - -||\n");
				printf("|| - - - - - - - 1.迷宫求解 - - - - - - - ||\n");
				printf("|| - - - - - - - 2.输出迷宫 - - - - - - - ||\n\n");
				printf("请输入要执行的操作：1\n");
				printf("迷宫求解过程如下：\n\n");
				for (int m = 0; m < 10; m++)
				{
					for (int n = 0; n < 10; n++)
					{
						if (maze[m][n] == 8) printf("↑");
						if (maze[m][n] == 2) printf("↓");
						if (maze[m][n] == 4) printf("←");
						if (maze[m][n] == 6) printf("→");
						if (maze[m][n] == 5) printf("×");
						if (maze[m][n] == 1) printf("■");
						if (maze[m][n] == 0) printf(" ");
					}
					printf("\n");
				}
				Sleep(500);
				i++;
			}
		}
	}
	gotoxy(0, 0);
	printf("\n||- - - - - - - - - 菜单 - - - - - - - - -||\n");
	printf("|| - - - - - - - 1.迷宫求解 - - - - - - - ||\n");
	printf("|| - - - - - - - 2.输出迷宫 - - - - - - - ||\n\n");
	printf("请输入要执行的操作：1\n");
	printf("迷宫求解过程如下：\n\n");
	for (int m = 0; m < 10; m++)
	{
		for (int n = 0; n < 10; n++)
		{
			if (maze[m][n] == 8) printf("↑");
			if (maze[m][n] == 2) printf("↓");
			if (maze[m][n] == 4) printf("←");
			if (maze[m][n] == 6) printf("→");
			if (maze[m][n] == 5) printf("×");
			if (maze[m][n] == 1) printf("■");
			if (maze[m][n] == 9) printf("★");
			if (maze[m][n] == 0) printf(" ");
		}
		printf("\n");
	}
	printf("\nover!\n");
	char w[30];
	int t = 0;
	w[t] = Pop(pa, ch);
	while (w[t] != 'y')
	{
		t++;
		w[t] = Pop(pa, ch);
	}
	printf("迷宫线路：");
	for (int k = t - 1; k >= 0; k--)
	{
		if (k == 0)
		{
			if (w[k] == 'r') printf("右");
			if (w[k] == 'd') printf("下");
			if (w[k] == 'l') printf("左");
			if (w[k] == 'u') printf("上");
			break;
		}
		if (w[k] == 'r') printf("右→");
		if (w[k] == 'd') printf("下→");
		if (w[k] == 'l') printf("左→");
		if (w[k] == 'u') printf("上→");
	}
	Sleep(500);
}
int main()
{
	int c;
	system("color F0");
	printf("\n||- - - - - - - - - 菜单 - - - - - - - - -||\n");
	printf("|| - - - - - - - 1.迷宫求解 - - - - - - - ||\n");
	printf("|| - - - - - - - 2.输出迷宫 - - - - - - - ||\n\n");
	printf("请输入要执行的操作：");
	scanf_s("%d", &c);
	if (c == 1)
	{
		printf("迷宫求解：\n");
		maze_path pat;
		Search(pat);
		Try(pat);
	}
	if (c == 2)
	{
		printf("输出迷宫图：\n");
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (maze[i][j] == 1) printf("■");
				else printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}