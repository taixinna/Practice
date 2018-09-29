#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	//int i = 0;
	//int j = 0;
	//for (i = 0; i < rows; i++)
	//{
	//	for (j = 0; j < cols; j++)
	//	{
	//		board[i][j] = set;
	//	}
	//}

	memset(board, set, rows*cols*sizeof(board[0][0]));
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	//
	while (count)
	{
		//������
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';//���û�ף����� 
			count--;
		}
	}
}

void PrintBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//��������
	//������Ч���ж�
	//1.��Ч
	//a->��  ը��
	//b->����	ͳ����Χ�׵ĸ���
	//
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col-EASY_COUNT)
	{
		printf("������Ҫ�Ų�����꣺>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row &&y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("�㱻ը���� !!!\n");
				PrintBoard(mine, row, col);
				break;
			}
			else
			{
				//������Χ�ж�����
				int count = GetMineCount(mine, x, y);
				win++;
				show[x][y] = count+ '0';
				PrintBoard(show, row, col);
			}
		}
		else
		{
			printf("����Ƿ�\n");
		}
	}
	if (win=row*col - EASY_COUNT)
	{
		printf("���׳ɹ���\n");
		PrintBoard(mine, row, col);
	}
}


void safe_board(char mine[ROW][COL], int i, int j)
{
	int count = 1;
	while (count)
	{
		if (mine[i][j] = '1')
		{
			int m = rand() % 8 + 1;
			int n = rand() % 8 + 1;
			mine[i][j] = '0';
			mine[m][n] = '1';
			count--;
		}
		else
			count--;
	}









