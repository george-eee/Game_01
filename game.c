#include "game.h"

int flag = 0;
void menu()
{
	char arr1[] = "            ";
	char arr2[] = "Play or Not?";
	char arr3[] = "                           ";
	char arr4[] = "Play: input 1 exit: input 2";
	int left1 = 0, left2 = 0;
	size_t right1 = strlen(arr1 - 1);
	size_t right2 = strlen(arr3 - 1);
	while (left1 <= right1)
	{
		arr1[left1] = arr2[left1];
		arr1[right1] = arr2[right1];
		printf("%s\n", arr1);
		Sleep(300);
		system("cls");
		left1++;
		right1--;
	}
	while (left2 <= right2)
	{
		arr3[left2] = arr4[left2];
		arr3[right2] = arr4[right2];
		printf("%s\n", arr3);
		Sleep(150);
		system("cls");
		left2++;
		right2--;
	}
	printf("%s\n%s\n", arr1, arr3);
}
void initboard(char chessboard[Row][Col], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			chessboard[i][j] = ' ';
		}
	}
}
void printboard(char chessboard[Row][Col], int row, int col)
{
	int i = 0;
	for (int i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (j < col - 1)
			{
				printf(" %c |", chessboard[i][j]);

			}
			else
				printf(" %c \n", chessboard[i][j]);
		}
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				if (j < col - 1)
				{
					printf("---|");
				}
				else
					printf("---\n");
			}
		}
	}
}
void playermove(char chessboard[Row][Col], int row, int col)
{
	int x, y = 0;
	printf("Player Chess-->input n,n \n");
	scanf("%d,%d", &x, &y);
	while (true)
	{
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (chessboard[x - 1][y - 1] == ' ')
			{
				chessboard[x - 1][y - 1] = '*';
				flag = 0;
				break;
			}
			else
			{
				printf("This coordinate is already occupied,please re-enter it.\n");
				Sleep(2500);
				flag = 1;
				break;
			}
		}
		else
		{
			printf("The coordinates entered are illegal.\nPlease try again.\n");
			Sleep(2500);
			flag = 1;
			break;
		}
	}
}
void computermove(char chessboard[Row][Col], int row, int col)
{
	printf("Computer chess...\n");
	Sleep(2000);
	int x, y = 0;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (chessboard[x][y] == ' ')
		{
			chessboard[x][y] = '#';
			break;
		}
	}
}
char ionwin(char chessboard[Row][Col])
{
	int i, j = 0;
	for (i = 0; i < Row; i++)//行等
	{
		int countp = 0, countc = 0;
		for (j = 0; j < Col; j++)
		{
			if (chessboard[i][j] == '*')
			{
				countp++;
			}
			if (chessboard[i][j] == '#')
			{
				countc++;
			}
		}
		if (countp == 3)
		{
			return 'y';
		}
		if (countc == 3)
		{
			return 'n';
		}
	}
	for (j = 0; j < Col; j++)//列等
	{
		int countp = 0, countc = 0;
		for (i = 0; i < Row; i++)
		{
			if (chessboard[i][j] == '*')
			{
				countp++;
			}
			if (chessboard[i][j] == '#')
			{
				countc++;
			}
		}
		if (countp == 3)
		{
			return 'y';
		}
		if (countc == 3)
		{
			return 'n';
		}
	}
	if (1)//交叉等
	{
		int countp1 = 0, countc1 = 0;
		int countp2 = 0, countc2 = 0;
		for (i = 0, j = 0; i < Row && j < Col; i++ && j++)
		{
			if (chessboard[i][j] == '*')
				countp1++;
			else if (chessboard[i][j] == '#')
				countc1++;
			else
				break;
		}
		for (i = 2, j = 0; i >= 0 && j < Col; i-- && j++)
		{
			if (chessboard[i][j] == '*')
				countp2++;
			else if (chessboard[i][j] == '#')
				countc2++;
			else
				break;
		}
		if (countp1 == 3 || countp2 == 3)
		{
			return 'y';
		}
		if (countc1 == 3 || countc2 == 3)
		{
			return 'n';
		}
	}
	int flag = 1;//判断平局
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (chessboard[i][j] == ' ')
			{
				flag = 0;
			}
		}
	}
	if (flag)
	{
		return 't';
	}
}
void game()
{
	char chessboard[Row][Col] = { 0 };
	initboard(chessboard, Row, Col);
	printboard(chessboard, Row, Col);
	while (1)
	{
		char judge = 0;
		playermove(chessboard, Row, Col);
		printboard(chessboard, Row, Col);
		judge = ionwin(chessboard);
		if (judge == 'y')
		{
			printf("YOU WIN!\n");
			Sleep(1500);
			break;
		}
		else if (judge == 't')
		{
			printf("STALEMATE!\n");
			Sleep(1500);
			break;
		}
		if (flag == 0)
		{
			computermove(chessboard, Row, Col);
			printboard(chessboard, Row, Col);
		}
		judge = ionwin(chessboard);
		if (judge == 'n')
		{
			printf("YOU LOSE!\n");
			Sleep(1500);
			break;
		}
		else if (judge == 't')
		{
			printf("STALEMATE!\n");
			Sleep(1500);
			break;
		}
	}
}
