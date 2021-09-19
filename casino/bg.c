#include "준비중.h"

void opening()
{
	star();
	//건물사각형
	build();
	//
	//문
	door();
	human(51, 29);
	//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	board_t();

	for (int j = 0; j < 6; j++)
	{
		if (j == 0)
		{
			star();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			board();
			human(51, 29);
			gotoxy(59, 21);

		}
		else if (j == 1)
		{
			star();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			board();
			//건물 사각형
			build();
			human(53, 28);
			//
			//문
			line();
			//
			gotoxy(57, 21);
			printf("┬");
			gotoxy(62, 21);
			printf("┬");
			for (int i = 0; i < 9; i++)
			{
				gotoxy(57, 22 + i);
				puts("│");
			}
			for (int i = 0; i < 9; i++)
			{
				gotoxy(62, 22 + i);
				puts("│");
			}
			gotoxy(57, 31);
			printf("┴");
			gotoxy(62, 31);
			printf("┴");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else if (j == 2)
		{
			star();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			board();
			//건물 사각형
			build();
			human(54, 27);
			//
			//문
			line();
			//
			gotoxy(55, 21);
			printf("┬");
			gotoxy(64, 21);
			printf("┬");
			for (int i = 0; i < 9; i++)
			{
				gotoxy(55, 22 + i);
				puts("│");
			}
			for (int i = 0; i < 9; i++)
			{
				gotoxy(64, 22 + i);
				puts("│");
			}
			gotoxy(55, 31);
			printf("┴");
			gotoxy(64, 31);
			printf("┴");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else if (j == 3)
		{
			star();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			board();
			//건물 사각형
			build();
			human(55, 26);
			//
			//문
			line();
			//
			gotoxy(53, 21);
			printf("┬");
			gotoxy(65, 21);
			printf("┬");
			for (int i = 0; i < 9; i++)
			{
				gotoxy(53, 22 + i);
				puts("│");
			}
			for (int i = 0; i < 9; i++)
			{
				gotoxy(65, 22 + i);
				puts("│");
			}
			gotoxy(53, 31);
			printf("┴");
			gotoxy(65, 31);
			printf("┴");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else if (j == 4)
		{
			star();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			board();
			//건물 사각형
			build();
			human(56, 25);
			//
			//문
			line();
			//
			gotoxy(51, 21);
			printf("┬");
			gotoxy(67, 21);
			printf("┬");
			for (int i = 0; i < 9; i++)
			{
				gotoxy(51, 22 + i);
				puts("│");
			}
			for (int i = 0; i < 9; i++)
			{
				gotoxy(67, 22 + i);
				puts("│");
			}
			gotoxy(51, 31);
			printf("┴");
			gotoxy(67, 31);
			printf("┴");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else if (j == 5)
		{
			star();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			board();
			//건물 사각형
			build();
			human(57, 24);
			//
			//문
			line();
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		Sleep(700);
		system("cls");
	}


}

void ending()
{
	star();
	//건물사각형
	build();
	//
	//문
	line();
	//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	board();



	for (int j = 0; j < 6; j++)
	{
		if (j == 0)
		{
			star();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			board();
			//건물 사각형
			build();
			human(57, 24);
			//
			//문
			line();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			//

		}
		else if (j == 1)
		{
			star();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			board();
			//건물 사각형
			build();
			human(56, 25);
			//
			//문
			line();
			//

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else if (j == 2)
		{
			star();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			board();
			//건물 사각형
			build();
			human(55, 26);

			//
			//문
			line();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			//

		}
		else if (j == 3)
		{
			star();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			board();
			//건물 사각형
			build();
			human(54, 27);
			gotoxy(53, 29);
			//
			//문
			line();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else if (j == 4)
		{
			star();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			board();
			//건물 사각형
			build();
			human(53, 28);
			gotoxy(52, 30);
			//
			//문
			line();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			//


		}
		else if (j == 5)
		{

			//건물 사각형
			build();
			door();
			star();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			board();
			human(51, 29);
			gotoxy(59, 21);

		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		Sleep(700);
		system("cls");
	}

	for (int i = 0; i < 7; i++)
	{
		if (i == 0)
		{
			star();
			human(51, 29);
			gotoxy(50, 31);
			puts("/│  /│ ");
			gotoxy(50, 33);
			puts("  / /");
		}
		else if (i == 1)
		{
			star();
			human(51, 24);
			gotoxy(50, 26);
			puts("/│  /│ ");
			gotoxy(50, 28);
			puts("  / /");
		}
		else if (i == 2)
		{
			star();
			human(51, 19);
			gotoxy(50, 21);
			puts("/│  /│ ");
			gotoxy(50, 23);
			puts("  / /");
		}
		else if (i == 3)
		{
			star();
			human(51, 15);
			gotoxy(50, 17);
			puts("/│  /│ ");
			gotoxy(50, 19);
			puts("  / /");
		}
		else if (i == 4)
		{
			star();
			human(51, 10);
			gotoxy(50, 12);
			puts("/│  /│ ");
			gotoxy(50, 14);
			puts("  / /");
		}
		else if (i == 5)
		{
			star();
			human(51, 5);
			gotoxy(50, 7);
			puts("/│  /│ ");
			gotoxy(50, 9);
			puts("  / /");
		}
		else if (i == 6)
		{
			star();
			gotoxy(51, 5);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			puts("*");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		Sleep(700);
		system("cls");
	}
	star();
	gotoxy(51, 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	puts("*");

	game_over();
}


//사람
void human(int a, int b)
{
	gotoxy(a, b);
	puts("  ●");
	gotoxy(a - 1, b + 1);
	puts(" ┌───┐");
	gotoxy(a - 1, b + 2);
	puts("/│   │/");
	gotoxy(a - 1, b + 3);
	puts(" └───┘");
	gotoxy(a - 1, b + 4);
	puts("  │ │");
}

//건물 사각형
void build()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	gotoxy(20, 5);
	puts("┌───────────────────────────────────────────────────────────────────────────┐");

	for (int i = 0; i < 25; i++)
	{
		gotoxy(20, 6 + i);
		puts("│");
	}
	for (int i = 0; i < 25; i++)
	{
		gotoxy(96, 6 + i);
		puts("│");
	}
	gotoxy(20, 31);
	puts("└─────────────────────────────┴─────────────────┴───────────────────────────┘");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
//문
void door()
{
	line();
	gotoxy(59, 21);
	printf("┬");
	for (int i = 0; i < 9; i++)
	{
		gotoxy(59, 22 + i);
		puts("│");
	}
	gotoxy(59, 31);
	printf("┴");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
//간판
void board_t()
{
	gotoxy(21, 7);
	puts("┌─────────────────────────────────────────────────────────────────────────┐");
	for (int i = 0; i < 7; i++)
	{
		gotoxy(21, 8 + i);
		puts("│");
	}
	for (int i = 0; i < 7; i++)
	{
		gotoxy(95, 8 + i);
		puts("│");
	}
	gotoxy(21, 15);
	puts("└─────────────────────────────────────────────────────────────────────────┘");
	//8
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	gotoxy(23, 8);
	puts("□□□□        □        □□□□□  □□□□□  □□  □□   □□□□");
	Sleep(500);

	//9
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	gotoxy(23, 9);
	puts("□             □□       □              □       □    □   □      □");
	Sleep(500);

	//10
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoxy(23, 10);
	puts("□            □  □      □              □       □□  □   □      □");
	Sleep(500);

	//11
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(23, 11);
	puts("□           □□□□     □□□□□      □       □ □ □   □      □");
	Sleep(500);

	//12
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	gotoxy(23, 12);
	puts("□          □      □            □      □       □  □□   □      □");
	Sleep(500);

	//13
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	gotoxy(23, 13);
	puts("□         □        □           □      □       □    □   □      □");
	Sleep(500);

	//14
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(23, 14);
	puts("□□□□  □□      □□  □□□□□  □□□□□  □□  □□   □□□□");
	Sleep(500);
}

void board()
{
	gotoxy(21, 7);
	puts("┌─────────────────────────────────────────────────────────────────────────┐");
	for (int i = 0; i < 7; i++)
	{
		gotoxy(21, 8 + i);
		puts("│");
	}
	for (int i = 0; i < 7; i++)
	{
		gotoxy(95, 8 + i);
		puts("│");
	}
	gotoxy(21, 15);
	puts("└─────────────────────────────────────────────────────────────────────────┘");
	//8
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	gotoxy(23, 8);
	puts("□□□□        □        □□□□□  □□□□□  □□  □□   □□□□");

	//9
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	gotoxy(23, 9);
	puts("□             □□       □              □       □    □   □      □");

	//10
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoxy(23, 10);
	puts("□            □  □      □              □       □□  □   □      □");

	//11
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(23, 11);
	puts("□           □□□□     □□□□□      □       □ □ □   □      □");

	//12
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	gotoxy(23, 12);
	puts("□          □      □            □      □       □  □□   □      □");

	//13
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	gotoxy(23, 13);
	puts("□         □        □           □      □       □    □   □      □");

	//14
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(23, 14);
	puts("□□□□  □□      □□  □□□□□  □□□□□  □□  □□   □□□□");
}

void star()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	gotoxy(0, 2);
	printf("*");
	gotoxy(10, 3);
	printf("*");
	gotoxy(15, 6);
	printf("*");
	gotoxy(26, 1);
	printf("*");
	gotoxy(34, 3);
	printf("*");
	gotoxy(47, 1);
	printf("*");
	gotoxy(59, 2);
	printf("*");
	gotoxy(68, 4);
	printf("*");
	gotoxy(72, 3);
	printf("*");
	gotoxy(84, 4);
	printf("*");
	gotoxy(96, 1);
	printf("*");
	gotoxy(100, 4);
	printf("*");
	gotoxy(105, 2);
	printf("*");
	gotoxy(115, 3);
	printf("*");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
void line()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(50, 21);
	puts("┌─────────────────┐");
	for (int i = 0; i < 9; i++)
	{
		gotoxy(50, 22 + i);
		puts("│");

	}
	for (int i = 0; i < 9; i++)
	{
		gotoxy(68, 22 + i);
		puts("│");
	}
}
void game_over()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

	gotoxy(2, 10);
	puts("□□□□□□□□             □□             □□          □□    □□□□□□□□□");
	Sleep(300);
	gotoxy(2, 11);
	puts("□□□□□□□□            □□□          □□□□      □□□□  □□□□□□□□□");
	Sleep(300);
	gotoxy(2, 12);
	puts("□□                       □□□□         □□  □□  □□  □□  □□");
	Sleep(300);
	gotoxy(2, 13);
	puts("□□                      □□□□□        □□  □□  □□  □□  □□");
	Sleep(300);
	gotoxy(2, 14);
	puts("□□      □□□□       □□    □□       □□  □□  □□  □□  □□□□□□□□□");
	Sleep(300);
	gotoxy(2, 15);
	puts("□□      □□□□      □□      □□      □□   □□□□   □□  □□□□□□□□□");
	Sleep(300);
	gotoxy(2, 16);
	puts("□□        □□       □□□□□□□□     □□     □□     □□  □□");
	Sleep(300);
	gotoxy(2, 17);
	puts("□□        □□      □□□□□□□□□    □□              □□  □□");
	Sleep(300);
	gotoxy(2, 18);
	puts("□□□□□□□□     □□            □□   □□              □□  □□□□□□□□□");
	Sleep(300);
	gotoxy(2, 19);
	puts("□□□□□□□□    □□□          □□□  □□              □□  □□□□□□□□□");
	Sleep(300);
	gotoxy(43, 22);
	puts(" □□□□□□      □□          □□  □□□□□□□□□  □□□□□□□");
	Sleep(300);
	gotoxy(42, 23);
	puts("□□□□□□□□     □□        □□   □□□□□□□□□  □□□□□□□□");
	Sleep(300);
	gotoxy(40, 24);
	puts(" □□          □□    □□        □□   □□                □□        □□");
	Sleep(300);
	gotoxy(40, 25);
	puts(" □□          □□     □□      □□    □□                □□       □□");
	Sleep(300);
	gotoxy(40, 26);
	puts(" □□          □□     □□      □□    □□□□□□□□□  □□□□□□□");
	Sleep(300);
	gotoxy(40, 27);
	puts(" □□          □□      □□    □□     □□□□□□□□□  □□□□□□□");
	Sleep(300);
	gotoxy(40, 28);
	puts(" □□          □□      □□    □□     □□                □□     □□");
	Sleep(300);
	gotoxy(40, 29);
	puts(" □□          □□       □□  □□      □□                □□      □□");
	Sleep(300);
	gotoxy(42, 30);
	puts("□□□□□□□□          □□□        □□□□□□□□□  □□       □□");
	Sleep(300);
	gotoxy(43, 31);
	puts(" □□□□□□             □□         □□□□□□□□□  □□        □□");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}


void developer() {
	system("cls");
	design();
	gotoxy(0, 3);
	printf("# 보유 토큰의 수 : %d", token);
	color(9);
	gotoxy(40, 10);
	printf("버전");
	color(15);
	gotoxy(54, 10);
	printf("0.0.1");
	color(9);
	gotoxy(40, 12);
	printf("제작자");
	color(15);
	gotoxy(54, 12);
	printf("***");
	gotoxy(54, 13);
	printf("***");
	gotoxy(54, 14);
	printf("유수연");
	color(9);
	gotoxy(40, 16);
	printf("제작기간");
	color(15);
	gotoxy(54, 16);
	printf("2019.07.11 - 2019.09.17");
	color(9);
	gotoxy(40, 18);
	printf("공간 제공");
	color(15);
	gotoxy(54, 18);
	printf("카카오톡");
	gotoxy(54, 19);
	printf("투썸 충정로점");
	gotoxy(54, 20);
	printf("투썸 냅킨");
	gotoxy(54, 21);
	printf("*** 메모장");
	color(8);
	gotoxy(40, 25);
	printf("아무 키를 누르면 메인 메뉴로 돌아갑니다.");
	getch();
	color(15);
}

void lucky_box() {
	int box, choice;
	system("cls");
	gotoxy(30, 15);
	printf("토큰이 0개가 되어 마지막 선택지 3개가 주어집니다.\n");
	gotoxy(30, 25);
	system("pause");
	system("cls");
	box = rand() % 3;
	CursorView(0);
	gotoxy(40, 8);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("행운의 상자를 고르십시오. : ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(15, 11);
	printf("  ■■■■■■■■■■■");
	gotoxy(15, 12);
	printf("■■■■■■■■■■■■■");
	gotoxy(15, 13);
	printf("■■■■■□□□■■■■■");
	gotoxy(15, 14);
	printf("■■■■■□□□■■■■■");
	gotoxy(15, 15);
	printf("■■□□■■□■■□□■■");
	gotoxy(15, 16);
	printf("■■□□■■□■■□□■■");
	gotoxy(15, 17);
	printf("■■■■■■■■■■■■■");
	gotoxy(15, 20);
	printf("        1번 상자      ");

	gotoxy(49, 10);
	printf("■■■■■■■■■■");
	gotoxy(49, 11);
	printf("■■■■■■■■□■");
	gotoxy(49, 12);
	printf("■■■■■■■■□■");
	gotoxy(49, 13);
	printf("■ □□ ■■■■□■");
	gotoxy(49, 14);
	printf("■□□□■■■■□■");
	gotoxy(49, 15);
	printf("■ □□ ■■■■□■");
	gotoxy(49, 16);
	printf("■■■■■■■■□■");
	gotoxy(49, 17);
	printf("■■■■■■■■□■");
	gotoxy(49, 18);
	printf("■■■■■■■■■■");
	gotoxy(49, 20);
	printf("        2번 상자      ");

	gotoxy(79, 11);
	printf("□□□□□□□□□□□□□");
	gotoxy(79, 12);
	printf("□■■□■■■■■□■■□");
	gotoxy(79, 13);
	printf("□■■□■■■■■□■■□");
	gotoxy(79, 14);
	printf("□□□□□□□□□□□□□");
	gotoxy(79, 15);
	printf("□■■■■□□■■■■■□");
	gotoxy(79, 16);
	printf("□■■■■■■■■■■■□");
	gotoxy(79, 17);
	printf("□□□□□□□□□□□□□");
	gotoxy(79, 20);
	printf("        3번 상자      ");
	gotoxy(70, 8);
	scanf("%d", &choice);
	gotoxy(40, 26);
	if (choice == ++box) {
		token += 100;
		printf("100토큰의 주인공이 되셨습니다! 축하드립니다.\n");
		gotoxy(40, 29);
		system("pause");
	}
	else {
		printf("토큰 0개를 얻어 거지가 되었습니다.\n");
		gotoxy(40, 29);
		system("pause");
		system("cls");
		beg();
		Sleep(1000);
		out();
		game_over();
	}
}

void beg() {
	star();
	build();
	door();
	board();
	gotoxy(85, 29);
	puts("  ●");
	gotoxy(84, 30);
	puts(" ┌───┐");
	gotoxy(84, 31);
	puts("/│  /│ ");
	gotoxy(84, 32);
	puts(" └───┘");
	gotoxy(84, 33);
	puts("  <  >");
	gotoxy(80, 32);
	puts("│  │");
	gotoxy(80, 33);
	puts("└──┘");
}