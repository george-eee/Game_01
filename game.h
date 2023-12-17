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

void menu();//选择菜单

void initboard(char chessboard[Row][Col], int row, int col);//初始化棋盘

void printboard(char chessboard[Row][Col], int row, int col);//打印棋盘(用空格覆盖初始化棋盘的空值)

void playermove(char chessboard[Row][Col], int row, int col);//玩家下棋(用'*'覆盖空格)

void computermove(char chessboard[Row][Col], int row, int col);//电脑下棋(用'#'覆盖空格)

char ionwin(char chessboard[Row][Col]);//判断是否有胜者或者是否平局

void game();//游戏主体封装