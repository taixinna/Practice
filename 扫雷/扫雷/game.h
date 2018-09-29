#ifndef __GAME_H__
#define __GAME_H__
#define EASY_COUNT 80
#define ROW 9
#define COL 9
#include <tx.h>

#define ROWS ROW+2
#define COLS COL+2
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set); //初始化
void SetMine(char board[ROWS][COLS], int row, int col);//布置雷
void PrintBoard(char board[ROWS][COLS], int row, int col);//打印棋盘
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//排雷
void safe_board(char mine[ROW][COL], int i, int j);//第一步安全检查
#endif  //__GAME_H__