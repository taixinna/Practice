#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("*****************************************\n");
	printf("***************1.��ʼ��Ϸ****************\n");
	printf("************   0.�˳���Ϸ   *************\n");
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
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("�뿪ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("������ѡ��\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
