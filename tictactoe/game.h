#define _CRT_SECURE_NO_WARNINGS
#pragma once

//头文件声明
#include <stdio.h>
#include<stdlib.h>
#include <time.h>

//定义宏常量
#define ROW 3
#define COL 3

//函数声明
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void Player_Move(char board[ROW][COL], int row, int col);
void Computer_Move(char board[ROW][COL], int row, int col);

//char返回类型
//若返回"*"则玩家获胜
//若返回"#"则玩家获胜
//若返回"D"(draw)则平局
//若返回"C"(continue)游戏继续
char Is_Win(char board[ROW][COL], int row, int col);

int Is_Full(char board[ROW][COL], int row, int col);
