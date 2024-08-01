//⽂件中写游戏需要的数据类型和函数声明等
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define EASY_COUNT 10

#define _CRT_SECURE_NO_WARNINGS

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

//初始化棋盘
void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set);

//打印棋盘
void DisplayBoard(char arr[ROWS][COLS],int row,int col);

//布置雷
void SetMine(char board[ROWS][COLS], int row, int col);

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

