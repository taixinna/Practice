#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("***************************\n");
	printf("*******    1.play    ******\n");
	printf("*******    0.exit    ******\n");
	printf("***************************\n"); 
}
void game()
{
	char mine[ROWS][COLS] = { 0 };//布置雷的数组
	char show[ROWS][COLS] = { 0 };//存放排查的坐标信息
	InitBoard(mine, ROWS,COLS,'0');//"0"
	InitBoard(show, ROWS,COLS,'*');//"*"

	//布置雷
	SetMine(mine, ROW, COL);
//	PrintBoard(mine, ROW, COL);
	PrintBoard(show, ROW, COL);
	//排查雷
	FindMine(mine, show, ROW, COL);
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择->\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}