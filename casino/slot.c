
#include "준비중.h"

void slot()
{
	system("mode con cols=120 lines=35");

	int wager = 0;

	show_rule3();

	gotoxy(45, 29);
	puts("아무 키나 누르면 시작합니다.");
	getchar();
	system("cls");

	draw_machine();

	while (1) {

		gotoxy(0, 1);
		printf("# 베팅한 토큰의 수 : %d     ", wager);
		printf("# 보유 토큰의 수 : %d", token);

		gotoxy(56, 14);
		printf("배팅할 토큰의 개수를 입력하시오: ");
		scanf("%d", &wager);
		if (wager > token) {
			gotoxy(56, 15);
			printf("(system) 토큰의 개수가 부족합니다.\n\n");
			Sleep(500);
		}
		else {
			gotoxy(56, 15);
			printf("배팅할 토큰의 개수가 결정되었습니다. ");
			Sleep(1000);
			break;
		}
	}

	token -= wager;

	gotoxy(0, 1);
	printf("# 베팅한 토큰의 수 : %d     ", wager);
	printf("# 보유 토큰의 수 : %d", token);

	token += wager * play_slot();

	gotoxy(56, 21);

	printf("아무 키나 누르면 게임이 종료됩니다.");

	getch();
}

int play_slot()
{
	int slot[4][4];
	int mul = 0, min = 0;
	int a[5];
	srand((unsigned)time(NULL));
	for (int i = 0; i < 5; i++)
	{
		a[i] = 20;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			slot[i][j] = rand() % 4 + 1;
		}
	}

	for (int j = 1; j < 4; j++)
	{
		if (slot[0][j - 1] == 1)
		{
			gotoxy(6 * j + 24, 10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("7");
		}
		else if (slot[0][j - 1] == 2)
		{
			gotoxy(6 * j + 24, 10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			printf("★");
		}
		else if (slot[0][j - 1] == 3)
		{
			gotoxy(6 * j + 24, 10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			printf("♠");
		}
		else if (slot[0][j - 1] == 4)
		{
			gotoxy(6 * j + 24, 10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("♥");
		}
	}
	Sleep(1000);
	for (int j = 1; j < 4; j++)
	{
		if (slot[1][j - 1] == 1)
		{
			gotoxy(6 * j + 24, 12);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("7");
		}
		else if (slot[1][j - 1] == 2)
		{
			gotoxy(6 * j + 24, 12);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			printf("★");
		}
		else if (slot[1][j - 1] == 3)
		{
			gotoxy(6 * j + 24, 12);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			printf("♠");
		}
		else if (slot[1][j - 1] == 4)
		{
			gotoxy(6 * j + 24, 12);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("♥");
		}
	}
	Sleep(1000);
	for (int j = 1; j < 4; j++)
	{
		if (slot[2][j - 1] == 1)
		{
			gotoxy(6 * j + 24, 14);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("7");
		}
		else if (slot[2][j - 1] == 2)
		{
			gotoxy(6 * j + 24, 14);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			printf("★");
		}
		else if (slot[2][j - 1] == 3)
		{
			gotoxy(6 * j + 24, 14);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			printf("♠");
		}
		else if (slot[2][j - 1] == 4)
		{
			gotoxy(6 * j + 24, 14);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("♥");
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}

	while (1)
	{
		//가운데 3개 성공(여기서 성공이면 바로 당첨)
		if (slot[1][0] == slot[1][1] && slot[1][1] == slot[1][2])
		{
			if (slot[1][0] == 4)
			{
				mul = 4;
			}
			else if (slot[1][0] == 3)
			{
				mul = 5;
			}
			else if (slot[1][0] == 2)
			{
				mul = 6;
			}
			else if (slot[1][0] = 1)
			{
				mul = 7;
			}
			min = mul;
			break;

		}
		//첫째 줄 2개 성공
		if (slot[0][0] == slot[0][1] || slot[0][1] == slot[0][2])
		{
			if (slot[0][0] == slot[0][1] && slot[0][1] == slot[0][2])
			{
				mul = 0;
			}
			else if (slot[0][1] == 1)
			{
				mul = 3;
			}
			else if (slot[0][1] == 2)
			{
				mul = 2;
			}
			else if (slot[0][1] == 3)
			{
				mul = 1;
			}
			if (mul == 1 || mul == 2 || mul == 3)
			{
				a[0] = mul;
			}
		}
		//두번째 줄 2개 성공
		if (slot[1][0] == slot[1][1] || slot[1][1] == slot[1][2])
		{
			if (slot[1][1] == 1)
			{
				mul = 3;
			}
			else if (slot[1][1] == 2)
			{
				mul = 2;
			}
			else if (slot[1][1] == 3)
			{
				mul = 1;
			}
			if (mul == 1 || mul == 2 || mul == 3)
			{
				a[1] = mul;
			}
		}
		//세번째 줄 2개 성공
		if (slot[2][0] == slot[2][1] || slot[2][1] == slot[2][2])
		{
			if (slot[2][0] == slot[2][1] && slot[2][1] == slot[2][2])
			{
				mul = 0;
			}
			else if (slot[2][1] == 1)
			{
				mul = 3;
			}
			else if (slot[2][1] == 2)
			{
				mul = 2;
			}
			else if (slot[2][1] == 3)
			{
				mul = 1;
			}
			if (mul == 1 || mul == 2 || mul == 3)
			{
				a[2] = mul;
			}
		}
		//오른쪽 대각선으로 2개 성공
		if (slot[0][0] == slot[1][1] || slot[1][1] == slot[2][2])
		{
			if (slot[0][0] == slot[1][1] && slot[1][1] == slot[2][2])
			{
				mul = 0;
			}
			else if (slot[1][1] == 1)
			{
				mul = 3;
			}
			else if (slot[1][1] == 2)
			{
				mul = 2;
			}
			else if (slot[1][1] == 3)
			{
				mul = 1;
			}
			if (mul == 1 || mul == 2 || mul == 3)
			{
				a[3] = mul;
			}
		}
		//왼쪽 대각선으로 2개 성공
		if (slot[0][2] == slot[1][1] || slot[1][1] == slot[2][0])
		{
			if (slot[0][2] == slot[1][1] && slot[1][1] == slot[2][0])
			{
				mul = 0;
			}
			else if (slot[1][1] == 1)
			{
				mul = 3;
			}
			else if (slot[1][1] == 2)
			{
				mul = 2;
			}
			else if (slot[1][1] == 3)
			{
				mul = 1;
			}
			if (mul == 1 || mul == 2 || mul == 3)
			{
				a[4] = mul;
			}
		}
		min = a[0];
		for (int i = 1; i < 5; i++)
		{
			if (min > a[i])
			{
				min = a[i];
			}
		}
		break;
	}
	gotoxy(56, 17);
	if (min == 0 || min == 20)
	{
		puts("!실패! 베팅 금액을 잃습니다.");
		min = 0;
	}
	else
	{
		printf("!성공! 베팅 금액의 %d배를 얻습니다.", min);
	}
	return min;
}
void show_rule3()
{
	gotoxy(15, 10);
	puts("┏━━━━━━━━━━━━━━━━━━━━━━━━┓ ");
	gotoxy(15, 11);
	puts("┃  1. 7 7 7 : 7배\t┃ ");
	gotoxy(15, 12);
	puts("┣━━━━━━━━━━━━━━━━━━━━━━━━┫ ");
	gotoxy(15, 13);
	puts("┃  2. ★ ★ ★ : 6배\t┃ ");
	gotoxy(15, 14);
	puts("┣━━━━━━━━━━━━━━━━━━━━━━━━┫");
	gotoxy(15, 15);
	puts("┃  3. ♠ ♠ ♠ : 5배\t┃ ");
	gotoxy(15, 16);
	puts("┣━━━━━━━━━━━━━━━━━━━━━━━━┫ ");
	gotoxy(15, 17);
	puts("┃  4. ♥ ♥ ♥ : 4배\t┃ ");
	gotoxy(15, 18);
	puts("┣━━━━━━━━━━━━━━━━━━━━━━━━┫ ");
	gotoxy(15, 19);
	puts("┃  5. 7 7 랜덤 : 3배\t┃ ");
	gotoxy(15, 20);
	puts("┣━━━━━━━━━━━━━━━━━━━━━━━━┫ ");
	gotoxy(15, 21);
	puts("┃  6. ★ ★ 랜덤 : 2배\t┃ ");
	gotoxy(15, 22);
	puts("┣━━━━━━━━━━━━━━━━━━━━━━━━┫ ");
	gotoxy(15, 23);
	puts("┃  7. ♠ ♠ 랜덤 : 1배\t┃ ");
	gotoxy(15, 24);
	puts("┗━━━━━━━━━━━━━━━━━━━━━━━━┛ ");

	gotoxy(44, 12);
	puts("*1,2,3,4번이 성공하기 위해서는 가운데 줄에 기호가 출력되어야 합니다.");
	gotoxy(44, 13);
	puts("  예: ? ? ?");
	gotoxy(50, 14);
	puts("7 7 7");
	gotoxy(50, 15);
	puts("? ? ?");
	gotoxy(44, 17);
	puts("*5,6,7번이 성공하기 위해서는 연속으로 기호가 출력되어야 합니다.");
	gotoxy(44, 18);
	puts("  예: ★ ★  ? or ? ★ ★");
	gotoxy(44, 20);
	puts("*중복성공이면 배당금이 더 낮은 순으로 주어집니다.");
	gotoxy(44, 21);
	puts("  예: 5번 6번 중복으로 성공일 때 베팅 금액의 2배를 얻습니다.");

}
void draw_machine()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	for (int i = 0; i < 5; i++)
	{
		gotoxy(33, 10 + i);
		puts("│");
	}
	for (int i = 0; i < 5; i++)
	{
		gotoxy(39, 10 + i);
		puts("│");
	}
	for (int i = 0; i < 17; i++)
	{
		gotoxy(28 + i, 11);
		puts("─");
	}
	for (int i = 0; i < 17; i++)
	{
		gotoxy(28 + i, 13);
		puts("─");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(26, 9);
	puts("┌───────────────────┐ ");
	for (int i = 0; i < 6; i++)
	{
		gotoxy(26, 10 + i);
		printf("│");
	}
	for (int i = 0; i < 6; i++)
	{
		gotoxy(46, 10 + i);
		printf("│");
	}
	gotoxy(26, 15);
	puts("└───────────────────┘ ");
	gotoxy(24, 8);
	puts("┌───────────────────────┐ ");
	for (int i = 0; i < 8; i++)
	{
		gotoxy(24, 9 + i);
		printf("│");
	}
	for (int i = 0; i < 8; i++)
	{
		gotoxy(48, 9 + i);
		printf("│");
	}
	gotoxy(24, 16);
	puts("└───────────────────────┘ ");
	gotoxy(24, 7);
	puts("┌───────────────────────┐ ");
	gotoxy(24, 8);
	printf("│");
	gotoxy(48, 8);
	printf("│");
	gotoxy(24, 5);
	puts("┌───────────────────────┐ ");
	for (int i = 0; i < 2; i++)
	{
		gotoxy(24, 6 + i);
		printf("│");
	}
	for (int i = 0; i < 2; i++)
	{
		gotoxy(48, 6 + i);
		printf("│");
	}
	gotoxy(24, 17);
	puts("└───────────────────────┘ ");
	gotoxy(24, 16);
	printf("│");
	gotoxy(48, 16);
	printf("│");
	for (int i = 0; i < 14; i++)
	{
		gotoxy(24, 17 + i);
		printf("│");
	}
	for (int i = 0; i < 14; i++)
	{
		gotoxy(48, 17 + i);
		printf("│");
	}
	gotoxy(24, 31);
	puts("└───────────────────────┘ ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	gotoxy(29, 6);
	printf("$ SLOT MACHINE $");
	gotoxy(25, 24);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("  ♥    ♥    ♥    x4");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	gotoxy(25, 18);
	printf("   7     7     7    x7");
	gotoxy(25, 26);
	printf("   7     7    $     x3");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	gotoxy(25, 28);
	printf("  ★    ★    $     x2");
	gotoxy(25, 20);
	printf("  ★    ★    ★    x6");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	gotoxy(25, 22);
	printf("  ♠    ♠    ♠    x5");
	gotoxy(25, 30);
	printf("  ♠    ♠    $     x1");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}


