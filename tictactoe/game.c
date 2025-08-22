#include "game.h"
//棋盘初始化
//void 空型函数，char board[ROW][COL]二维数组接收指针，int row、int col接收ROW\COL的形参
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) //用for循环语句对二维数组进行初始化
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//棋盘打印
//此方式打印出来的棋盘，可以通过对COW和COL宏常量的修改来改变棋盘大小
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		for (j = 0; j < col; j++)
		{
			if (i < row - 1)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}
//玩家回合
void Player_Move(char board[ROW][COL], int row, int col)
{
	printf("玩家回合\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该位置已被占用!!!\n");
			}
		}
		else
		{
			printf("输入错误!!!(请重新输入1 ~ 3)\n");
		}
	}
}
void Computer_Move(char board[ROW][COL], int row, int col)
{
	printf("电脑回合\n");
	while (1)
	{
		int x = rand() % row;  //rand()与之前的主函数中srand()共同调用生成随机数
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
//判断游戏是否结束
char Is_Win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 1; j < col; j++)
		{
			if (board[i][j - 1] == board[i][j] && board[i][j] == board[i][j + 1] && board[i][j] != ' ')
				return board[i][j];
		}
	}
	for (j = 0; j < col; j++)
	{
		for (i = 1; i < row - 1; i++)
			if (board[i - 1][j] == board[i][j] && board[i][j] == board[i + 1][j] && board[i][j] != ' ')
				return board[i][j];
	}
	for (i = 1; i < row - 1; i++)
	{
		for (j = 1; j < col - 1; j++)
		{
			if (board[i - 1][j - 1] == board[i][j] && board[i][j] == board[i + 1][j + 1] && board[i][j] != ' ')
				return board[i][j];
			if (board[i - 1][j + 1] == board[i][j] && board[i][j] == board[i + 1][j - 1] && board[i][j] != ' ')
				return board[i][j];
		}
	}
	if (1 == Is_Full(board, row, col))
		return 'D';
	else
		return 'C';
}

//判断棋盘是否下满
int Is_Full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}