#include "준비중.h"

void gotoxy(int x, int y) {
	COORD Pos = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void color(int color_number) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

void CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

int main() {
	system("mode con cols=120 lines=35");
	int menu;
	srand((unsigned)time(0));
	CursorView(0);
	Sleep(5000);
	opening();
	user_menu();
	gotoxy(40, 22);
	printf("enter키를 누르면 게임메뉴로 넘어갑니다.");
	getch();
	while (1) {

		system("cls");
		design();
		gotoxy(0, 3);
		printf("# 보유 토큰의 수 : %d", token);
		do {
			gotoxy(50, 11);
			printf("+ l 메인 메뉴 ㅣ +");
			gotoxy(51, 14);
			printf("1) 카지노 게임");
			gotoxy(51, 16);
			printf("2) 순위 보기");
			gotoxy(51, 18);
			printf("3) 게임 정보 ⓘ");
			gotoxy(51, 20);
			printf("4) 프로그램 종료");
			gotoxy(50, 23);
			printf("메뉴를 선택하세요: ");
			scanf("%d", &menu);
			getchar();
		} while (menu < 1 || menu>4);

		if (menu == 4) {
			end_rank();
			break;
		}

		switch (menu) {
		case 1:
			menu2();
			break;
		case 2:
			rank();
			break;
		case 3:
			developer();
			break;
		}
		if (token == 0)break;
	}
	return 0;
}

void menu2() {
	int menu;
	while (1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		if (token == 0) {
			lucky_box();
			if (token == 0)break;
		}
		CursorView(1);
		system("cls");
		design();
		gotoxy(0, 3);
		printf("# 보유 토큰의 수 : %d", token);
		do {
			gotoxy(50, 10);
			printf("+ l 카지노 게임 ㅣ +");
			gotoxy(53, 12);
			printf("1) 경주마\n");
			gotoxy(53, 14);
			printf("2) 슬롯머신\n");
			gotoxy(53, 16);
			printf("3) 블랙잭\n");
			gotoxy(53, 18);
			printf("4) 룰렛\n");
			gotoxy(53, 20);
			printf("5) 다이사이\n");
			gotoxy(53, 22);
			printf("6) 메인 메뉴로 돌아가기\n");
			gotoxy(51, 25);
			printf("메뉴를 선택하세요: ");
			scanf("%d", &menu);
			getchar();
		} while (menu < 1 || menu>6);

		if (menu == 6) {
			system("cls");
			break;
		}
		if (show_rule(menu)) {
			switch (menu) {
			case 1:
				horse();
				break;
			case 2:
				slot();
				break;
			case 3:
				black();
				break;
			case 4:
				roulette();
				break;
			case 5:
				taisai();
				break;
			}
		}
	}
}

int show_rule(int m) {
	char ch;
	system("cls");
	gotoxy(0, 3);
	printf("# 보유 토큰의 수 : %d", token);
	switch (m) {
	case 1:
		gotoxy(13, 11);
		printf("    `.`");
		gotoxy(13, 12);
		printf("     -//:--.`");
		gotoxy(13, 13);
		printf("    `::++++++/:.");
		gotoxy(13, 14);
		printf(" `-/++++++++++++/.");
		gotoxy(13, 15);
		printf(" :+++:-::/++++++++:");
		gotoxy(13, 16);
		printf(" `::`    -+++++++++/`");
		gotoxy(13, 17);
		printf(" `..`     -+++++++++/`");
		gotoxy(13, 18);
		printf("           ````````````");
		gotoxy(39, 11);
		printf("+ 경주마 게임 +");
		gotoxy(39, 13);
		printf("총 5마리의 말이 경주를 하게 됩니다.\n");
		gotoxy(39, 15);
		printf("베팅할 말을 선택한 후 베팅 금액을 입력합니다.\n");
		gotoxy(39, 17);
		printf("배팅을 한 말이 우승하면 베팅금액의 2배를 얻습니다.");
		gotoxy(39, 19);
		printf("반대로, 배팅을 한 말이 우승하지 못했을 시, 베팅 금액의 전부를 잃습니다.\n\n");
		break;
	case 2:
		gotoxy(10, 9);
		puts("    hy/y:oo+o+/+o//oo+y+sm");
		gotoxy(10, 10);
		puts("    hy/y:oo+o+/+o//oo+y+sm");
		gotoxy(9, 11);
		puts("  o-osssyyos/sooo+sossdshy+o-o");
		gotoxy(9, 12);
		puts("::hdhhhhhhhhhhhhhhhhhhhhhddy++h::");
		gotoxy(9, 13);
		puts(":+hmd       │       │        hy/:");
		gotoxy(9, 14);
		printf(":+ymh hhhhhh│ hhhhhh│ hhhhhh hy/:");
		gotoxy(9, 15);
		printf("/+hmd     //│     //│     // lmho");
		gotoxy(9, 16);
		printf("/+ydd    // │    // │    //  ddy:");
		gotoxy(9, 17);
		printf(":/s/s   //  │   //  │   //   s+y+");
		gotoxy(9, 18);
		printf(".+o//       │       │        ooy+");
		gotoxy(7, 19);
		printf(" :ohyyhddhhhddhyyhhhhhddddddddhhhho:");
		gotoxy(7, 20);
		printf(" +:+o++++++++++++++++++++++++++oo+:+");
		gotoxy(7, 21);
		printf(" +:+o++++++++++++++++++++++++++oo+:+");
		gotoxy(47, 11);
		printf("+ 슬롯머신 +");
		gotoxy(47, 13);
		printf("가로 혹은 대각선 방향으로 조건을 만족하면 정해진 배당률에 의해");
		gotoxy(47, 14);
		printf("배당금을 얻게 됩니다.");
		gotoxy(47, 16);
		printf("[토큰 획득 방법]");
		gotoxy(47, 18);
		printf("슬롯머신을 돌려 가로 혹은 대각선 방향으로 조건에 만족하는 기호가");
		gotoxy(47, 19);
		printf("나오면 최소 1배, 최대 7배를 얻게 됩니다.\n\n\n\n");
		break;
	case 3:
		gotoxy(10, 6);
		printf("            ■■■■■   ");
		gotoxy(10, 7);
		printf("          ■          ■     ");
		gotoxy(10, 8);
		printf("        ■              ■     ");
		gotoxy(10, 9);
		printf("        ■              ■     ");
		gotoxy(10, 10);
		printf("        ■              ■     ");
		gotoxy(10, 11);
		printf("        ■      ■      ■     ");
		gotoxy(10, 12);
		printf("        ■     ■■     ■     ");
		gotoxy(10, 13);
		printf("        ■   ■■■■   ■     ");
		gotoxy(10, 14);
		printf("        ■ ■■■■■■ ■     ");
		gotoxy(10, 15);
		printf("        ■   ■■■■   ■     ");
		gotoxy(10, 16);
		printf("        ■     ■■     ■     ");
		gotoxy(10, 17);
		printf("        ■      ■      ■     ");
		gotoxy(10, 18);
		printf("        ■              ■     ");
		gotoxy(10, 19);
		printf("        ■              ■     ");
		gotoxy(10, 20);
		printf("        ■              ■     ");
		gotoxy(10, 21);
		printf("          ■          ■     ");
		gotoxy(10, 22);
		printf("            ■■■■■");
		gotoxy(45, 6);
		printf("블랙잭");
		gotoxy(45, 8);
		printf("Ace = 1 or 11    2 ~ 10 = 각 숫자 값    J, Q, K = 10");
		gotoxy(45, 10);
		printf("딜러와 플레이어가 각각 2장을 나눠 가집니다");
		gotoxy(45, 12);
		printf("딜러의 두장의 카드가 16을 넘어가면 그대로 멈춥니다.");
		gotoxy(45, 14);
		printf("[토큰 획득 방법]");
		gotoxy(45, 16);
		printf("플레이어의 숫자 합이 21을 넘어가면 베팅금액을 전부 잃습니다.");
		gotoxy(45, 18);
		printf("딜러보다 카드숫자의 합이 21에 가깝다면, 베팅금액의 1.5배를 얻습니다.");
		gotoxy(45, 21);
		printf("딜러와 숫자 합이 비기면 베팅금액의 0.5배를 잃습니다.");
		break;
	case 4:
		gotoxy(12, 9);
		puts("         .--:--:--.         ");
		gotoxy(12, 10);
		puts("     -+shysoo/+oosyys+-     ");
		gotoxy(12, 11);
		puts("   /sysosysNd/+ydmo++syy/`  ");
		gotoxy(12, 12);
		puts(" .sys/syds:-:/:-:/+dNs/shy. ");
		gotoxy(12, 13);
		puts(" sys-hNd---:///:---:sys:shy ");
		gotoxy(12, 14);
		puts("`yyo-ddo----:::::---sNM/+yh.");
		gotoxy(12, 15);
		puts("`yyy:sdh+:---------ohyo-yhh.");
		gotoxy(12, 16);
		puts(" +yys/+d//yo////syyhdo:shhs ");
		gotoxy(12, 17);
		puts("  +hsys+/+yysddsyyo/+ssyho  ");
		gotoxy(12, 18);
		puts("   `+hhhhhysooooosyyhhh+.   ");
		gotoxy(12, 19);
		puts("      ./oyhhhhhhhhys+-      ");
		gotoxy(12, 20);
		puts("            ````            ");
		gotoxy(46, 8);
		printf("+ 룰렛 +");
		gotoxy(46, 10);
		printf("딜러가 숫자가 표시된 휠(Wheel)을 회전시킨 후, 그 반대 방향으로");
		gotoxy(46, 11);
		puts("볼을 회전시켜 볼이 낙착되는 숫자(0~36)나 색깔에 베팅한 플레이어에게");
		gotoxy(46, 12);
		printf("정해진 액수를 지급하는 게임입니다.");
		gotoxy(46, 14);
		printf("단일 배팅: 1가지 숫자에 배팅\n");
		gotoxy(46, 15);
		printf("이중 배팅: 2가지 숫자에 배팅\n");
		gotoxy(46, 16);
		printf("색깔 배팅: 셋 중 하나의 색깔에 배팅\n");
		gotoxy(46, 18);
		puts("[토큰 획득 방법]");
		gotoxy(46, 20);
		puts("배팅 방법을 선택해서 맞추면 단일 배팅은 배팅 금액의 35배,");
		gotoxy(46, 21);
		puts("이중 배팅은 17배, 색깔 배팅은 5배를 얻게 됩니다.");
		break;
	case 5:
		gotoxy(14, 10);
		printf(" :+ooooooooosssssooss+:");
		gotoxy(14, 11);
		printf(" oo+   :oooossss:   +ss");
		gotoxy(14, 12);
		printf(":oo-   `osoossso.   :ss:");
		gotoxy(14, 13);
		printf(":ooo/:/+oooosssso//+sss:");
		gotoxy(14, 14);
		printf(":ooooooooo- -:ossssssss:");
		gotoxy(14, 15);
		printf(":oooooooo/    +ssssssss:");
		gotoxy(14, 16);
		printf(":ooooooooo/:/+sssssssss:");
		gotoxy(14, 17);
		printf(":oo+-../oooossss/--:oss:");
		gotoxy(14, 18);
		printf(":oo-   `ooosssso`  `:ss:");
		gotoxy(14, 19);
		printf(" ooo:-:+oooossss+../oss");
		gotoxy(14, 20);
		printf(" :/+ooooooooooooooooo+:");
		gotoxy(47, 10);
		printf("+ 다이사이 +");
		gotoxy(47, 12);
		printf("주사위 3개를 흔들어 결정된 주사위들의 합을 예측하거나 주사위 3개의");
		gotoxy(47, 13);
		printf("숫자를 예측해 적중하면 정해진 배당률에 의해 배당금이 지급되는 게임");
		gotoxy(47, 14);
		printf("입니다.");
		gotoxy(47, 16);
		printf("[토큰 획든 방법]");
		gotoxy(47, 18);
		printf("선택할 수 있는 베팅의 종류는 4가지이며 베팅이 적중하면 최소 1.2배,");
		gotoxy(47, 19);
		printf("최대 150배를 얻게 됩니다.\n\n");
		break;
	}
	gotoxy(28, 26);
	printf("카지노 게임 특성 상 한번 게임을 시작하면 중간에 멈출 수 없습니다.");
	gotoxy(27, 28);
	printf("게임을 시작하시려면 아무 키를 누르시고, 돌아가시려면 esc를 누르세요.");
	ch = getch();
	if (ch == 27) return 0;
	else system("cls");
	return 1;
}
