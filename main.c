#include "game.h"

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("Enter the game...\n");
			Sleep(1000);
			game();
			break;
		case 2:
			printf("Exit the game...\n");
			Sleep(1000);
			exit(0);//ÍË³ö
			break;
		default:
			printf("Wrong choice! Please re-select-->\n");
			Sleep(1500);
			break;
		}
	} while (input);
	return 0;
}