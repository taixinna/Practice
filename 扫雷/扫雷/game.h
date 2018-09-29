#ifndef __GAME_H__
#define __GAME_H__
#define EASY_COUNT 80
#define ROW 9
#define COL 9
#include <tx.h>

#define ROWS ROW+2
#define COLS COL+2
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set); //��ʼ��
void SetMine(char board[ROWS][COLS], int row, int col);//������
void PrintBoard(char board[ROWS][COLS], int row, int col);//��ӡ����
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//����
void safe_board(char mine[ROW][COL], int i, int j);//��һ����ȫ���
#endif  //__GAME_H__