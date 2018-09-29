#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("*****************************************\n");
	printf("***************1.开始游戏****************\n");
	printf("************   0.退出游戏   *************\n");
	printf("*****************************************\n");
}

void game()
{
	char mine[ROW][COL];
	char show[ROW][COL];
	init_board(mine, show);
	display_board(show);
	set_board(mine);
//	show_board(mine);
	my_step(mine, show);
}

void test()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
