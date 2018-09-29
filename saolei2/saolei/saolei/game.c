#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void init_board(char mine[ROW][COL], char show[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 1; i < ROW - 1; i++)
	{
		for (j = 1; j < COL - 1; j++)
		{
			mine[i][j] = '0';
		}
	}
	for (i = 1; i < ROW - 1; i++)
	{
		for (j = 1; j < COL - 1; j++)
		{
			show[i][j] = '*';
		}
	}
}

void display_board(char show[ROW][COL])
{
	int i, j;
	for (i = 0; i<ROW - 1; i++)
	{
		printf("%d ", i);
	}
	for (i = 1; i<ROW - 1; i++)
	{
		printf("\n");
		printf("%d ", i);
		for (j = 1; j<COL - 1; j++)
		{
			printf("%c ", show[i][j]);
		}
	}
	printf("\n");
}

void set_board(char mine[ROW][COL])
{
	int i, j;
	int count = 10;
	while (count)
	{
		i = rand() % 8 + 1;
		j = rand() % 8 + 1;
		if (mine[i][j] == '0')
		{
			mine[i][j] = '1';
			count--;
		}
	}
}

void show_board(char mine[ROW][COL])
{
	int i, j;
	for (i = 0; i<ROW - 1; i++)
	{
		printf("%d ", i);
	}
	for (i = 1; i<ROW - 1; i++)
	{
		printf("\n");
		printf("%d ", i);
		for (j = 1; j<COL - 1; j++)
		{
			printf("%c ", mine[i][j]);
		}
	}
	printf("\n");
}

void my_step(char mine[ROW][COL], char show[ROW][COL])
{
	int i = 0;
	int j = 0;
	int count = 71;
	int input = 0;
	while (count)
	{
		do
		{
			menu_board();
			printf("请选择\n");
			scanf("%d", &input);
			switch (input)
			{
			case 1:
				printf("请输入坐标\n");
				scanf("%d%d", &i, &j);
				if (count == 71)
				{
					safe_board(mine, i, j);
				}
				if (mine[i][j] == '1')
				{
					printf("踩到雷了：\n");
					show_board(mine);
					return;
				}
				else
				{
					open_board(mine, show, i, j);
					display_board(show);
					count--;
				}
				break;
			case 0:
				printf("输入坐标\n");
				scanf("%d%d", &i, &j);
				if (show[i][j] == '*')
				{
					show[i][j] = '!';
				}
				else
					show[i][j] = '*';
				display_board(show);
				break;
			default:
				printf("请重新选择\n");
				break;
			}
			break;
		} while (input);
	}
	printf("扫雷成功\n");
}

int get_mine(char mine[ROW][COL], int i, int j)
{
	int count = 0;
	if (mine[i - 1][j] == '1')
	{
		count++;
	}
	if (mine[i - 1][j - 1] == '1')
	{
		count++;
	}
	if (mine[i - 1][j + 1] == '1')
	{
		count++;
	}
	if (mine[i][j + 1] == '1')
	{
		count++;
	}
	if (mine[i][j - 1] == '1')
	{
		count++;
	}
	if (mine[i + 1][j - 1] == '1')
	{
		count++;
	}
	if (mine[i + 1][j] == '1')
	{
		count++;
	}
	if (mine[i + 1][j + 1] == '1')

	{
		count++;
	}
	return count;
}

void open_board(char mine[ROW][COL], char show[ROW][COL], int i, int j)
{
	if (mine[i][j] == '0'&&i >= 0 && j >= 0 && show[i][j] == '*')
	{
		show[i][j] = get_mine(mine, i, j) + '0';
	}
	if (mine[i][j - 1] == '0'&&i >= 0 && j - 1 >= 0 && show[i][j - 1] == '*')
	{
		show[i][j - 1] = get_mine(mine, i, j - 1) + '0';
		if (get_mine(mine, i, j - 1) == 0)
		{
			open_board(mine, show, i, j - 1);
		}
	}
	if (mine[i][j + 1] == '0'&&i >= 0 && j + 1 >= 0 && show[i][j + 1] == '*')
	{
		show[i][j + 1] = get_mine(mine, i, j + 1) + '0';
		if (get_mine(mine, i, j + 1) == 0)
		{
			open_board(mine, show, i, j + 1);
		}
	}
	if (mine[i - 1][j] == '0'&&i - 1 >= 0 && j >= 0 && show[i - 1][j] == '*')
	{
		show[i - 1][j] = get_mine(mine, i - 1, j) + '0';
		if (get_mine(mine, i - 1, j) == 0)
		{
			open_board(mine, show, i - 1, j);
		}
	}
	if (mine[i - 1][j - 1] == '0'&&i - 1 >= 0 && j - 1 >= 0 && show[i - 1][j - 1] == '*')
	{
		show[i - 1][j - 1] = get_mine(mine, i - 1, j - 1) + '0';
		if (get_mine(mine, i - 1, j - 1) == 0)
		{
			open_board(mine, show, i - 1, j - 1);
		}
	}
	if (mine[i - 1][j + 1] == '0'&&i - 1 >= 0 && j + 1 >= 0 && show[i - 1][j + 1] == '*')
	{
		show[i - 1][j + 1] = get_mine(mine, i - 1, j + 1) + '0';
		if (get_mine(mine, i - 1, j + 1) == 0)
		{
			open_board(mine, show, i - 1, j + 1);
		}
	}
	if (mine[i + 1][j + 1] == '0'&&i + 1 >= 0 && j + 1 >= 0 && show[i + 1][j + 1] == '*')
	{
		show[i + 1][j + 1] = get_mine(mine, i + 1, j + 1) + '0';
		if (get_mine(mine, i + 1, j + 1) == 0)
		{
			open_board(mine, show, i + 1, j + 1);
		}
	}
	if (mine[i + 1][j] == '0'&&i + 1 >= 0 && j >= 0 && show[i + 1][j] == '*')
	{
		show[i + 1][j] = get_mine(mine, i + 1, j) + '0';
		if (get_mine(mine, i + 1, j) == 0)
		{
			open_board(mine, show, i + 1, j);
		}
	}
	if (mine[i + 1][j - 1] == '0'&&i + 1 >= 0 && j - 1 >= 0 && show[i + 1][j - 1] == '*')
	{
		show[i + 1][j - 1] = get_mine(mine, i + 1, j - 1) + '0';
		if (get_mine(mine, i + 1, j - 1) == 0)
		{
			open_board(mine, show, i + 1, j - 1);
		}
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
}

void menu_board()
{
	printf("**** 1.扫雷    0.标雷与撤销 ***\n");
}
