#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROW 11
#define COL 11


void init_board(char mine[ROW][COL], char show[ROW][COL]);//��ʼ��	
void display_board(char show[ROW][COL]);//չʾ����
void set_board(char mine[ROW][COL]);//����
void show_board(char mine[ROW][COL]);//չʾ����
void my_step(char mine[ROW][COL], char show[ROW][COL]);//����ж�
int get_mine(char mine[ROW][COL]);//֪̽����
void open_board(char mine[ROW][COL], char show[ROW][COL], int i, int j);//չ��
void safe_board(char mine[ROW][COL], int i, int j);//��һ����ȫ���
void menu_board();//�ڶ����˵�
