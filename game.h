#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#define Row 3
#define Col 3

void menu();//ѡ��˵�

void initboard(char chessboard[Row][Col], int row, int col);//��ʼ������

void printboard(char chessboard[Row][Col], int row, int col);//��ӡ����(�ÿո񸲸ǳ�ʼ�����̵Ŀ�ֵ)

void playermove(char chessboard[Row][Col], int row, int col);//�������(��'*'���ǿո�)

void computermove(char chessboard[Row][Col], int row, int col);//��������(��'#'���ǿո�)

char ionwin(char chessboard[Row][Col]);//�ж��Ƿ���ʤ�߻����Ƿ�ƽ��

void game();//��Ϸ�����װ