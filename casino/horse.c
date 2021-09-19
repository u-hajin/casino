#include "준비중.h" /// 처음부터 말들이 시작점에서 출발할것
int horse_s[5], rank_s[6], luckyhorse;  // horse_s[] = 말이 달린 거리, rank=등수
int lucky_num[5] = { 1,1,1,0,0 };

void horse() {

	int h, winner, select_num, money, i;
	CursorView(0);
	horse_design();
	luckyhorse = (rand() % 5) + 1;

	gotoxy(50, 8);
	printf("경주마 게임");
	gotoxy(50, 13);
	printf("  ●");
	gotoxy(50, 14);
	printf(" ┌──┐/");
	gotoxy(50, 15);
	printf("/│  │ ");
	gotoxy(50, 16);
	printf(" └──┘");
	gotoxy(50, 17);
	printf("  ││");

	gotoxy(60, 13);
	printf("오늘의 행운 말");
	gotoxy(60, 15);
	printf("%d번 말!", luckyhorse);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(60, 17);
	printf("행운말이 [무조건] 승리하진 않습니다.");


	gotoxy(0, 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("# 보유한 토큰의 개수 : %d", token);
	select_num = select_horse();
	gotoxy(0, 3);
	printf("# 선택한 말의 번호 : %d", select_num);


	while (1) {
		gotoxy(53, 21);
		printf("배팅할 토큰의 개수를 입력하시오: ");
		scanf("%d", &money); getchar();
		if (money > token) {
			gotoxy(53, 23);
			printf("(system) 토큰의 개수가 부족합니다.");
			gotoxy(72, 21);
			printf("                                                         ");
		}
		else {
			gotoxy(53, 23);
			printf("(system) 배팅할 토큰의 개수가 결정되었습니다. ");
			break;
		}
	}
	token -= money;
	gotoxy(0, 1);
	printf("# 보유한 토큰의 개수 : %d", token);
	gotoxy(0, 5);
	printf("# 베팅한 토큰의 수 : %d", money);
	gotoxy(40, 28);
	printf("enter 키를 누르면 경주가 시작됩니다.");
	getchar();
	for (i = 0; i < 3; i++) {
		gotoxy(80, 28);
		printf("%d", i + 1);
		Sleep(1000);
		printf("\b ");
	}

	winner = run_horse(select_num, money);
	gotoxy(70, 15);
	printf("%d번 말이 우승하였습니다!", winner);
	if (select_num == winner) {
		gotoxy(70, 17);
		printf("축하드립니다.선택한 말이 우승하였습니다.");
		token += (2 * money);
		gotoxy(70, 19);
		printf("베팅금액의 2배를 얻습니다.");
	}
	else {
		gotoxy(70, 17);
		printf("선택한 말이 우승하지 못하였습니다.");
		gotoxy(70, 19);
		printf("배팅금액을 전부를 잃었습니다.");
	}
	gotoxy(40, 30);
	printf("아무 키나 누르면 게임이 종료됩니다.");
	getchar();

}

int select_horse() {
	int i = 0;
	gotoxy(53, 21);
	printf("1번  2번  3번  4번  5번");
	gotoxy(53, 23);
	printf("말을 선택해주십시오. ");
	scanf("%d", &i);
	while (i < 1 || i>5) {
		gotoxy(53, 25);
		printf("잘못 선택하셨습니다.");
		gotoxy(53, 21);
		printf("1번  2번  3번  4번  5번");
		gotoxy(53, 23);
		printf("말을 다시 선택해주십시오. ");
		scanf("%d", &i);
	}
	gotoxy(53, 25);
	printf("                                ");
	gotoxy(53, 23);
	printf("                                  ");
	return i;
}


int run_horse(a, b) {
	int i, cnt = 0, num, dis, w, j; // cnt=횟수, num = 말 번호, dis=말이 달린 거리
	system("cls");

	gotoxy(0, 1);
	printf("# 보유한 토큰의 개수 : %d", token);
	gotoxy(0, 3);
	printf("# 선택한 말의 번호 : %d", a);
	gotoxy(0, 5);
	printf("# 베팅한 토큰의 수 : %d", b);

	gotoxy(68, 3);
	printf("♬♪♬♪♬♪");
	gotoxy(48, 5);
	printf("      ●           ○            ●           ●");
	gotoxy(48, 6);
	printf("    ─┌──┐/     』（  )『      |┌──┐|       ┌（  )┐         ");
	gotoxy(48, 7);
	printf("┌────────────────────────────────────────────────────┐");


	gotoxy(10, 13);
	printf("──────────────────────────────────────────────────────");
	gotoxy(55, 11); printf("<end>");
	for (i = 0; i < 5; i++) {
		gotoxy(10, 15 + i * 3);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i + 9);
		printf("# %d번 말  ▷ %d", i + 1, i + 1);
		gotoxy(10, 16 + i * 3);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf("──────────────────────────────────────────────────────");
		rank_s[i] = 0;
		horse_s[i] = 0;
	}
	while (cnt != 5) {
		num = rand() % 5;
		if (rank_s[num] != 0)continue;
		dis = rand() % 2 + 2;
		if (lucky_num[luckyhorse] == 1) horse_s[num] += (dis + 2);
		else horse_s[num] += dis;
		Sleep(300);
		if (horse_s[num] > 39) {
			horse_s[num] = 40;
			if (!rank_s[num]) {
				cnt++;
				rank_s[num] = cnt;
				gotoxy(18, 15 + num * 3);
				for (i = 0; i < horse_s[num]; i++)
					printf(" ");
				if (horse_s[num])
					printf("▷ %d", num + 1);
				gotoxy(57, 15 + num * 3);
				printf("   %d등", cnt);
				if (cnt == 1)w = (num + 1);
			}
		}
		else {
			gotoxy(18, 15 + num * 3);
			for (i = 0; i < horse_s[num]; i++)
				printf(" ");
			if (horse_s[num])
				printf("▷ %d", num + 1);
		}
	}
	return w;
}


void horse_design() {
	system("cls");
	gotoxy(1, 10);
	printf("                       sss        ");
	gotoxy(1, 11);
	printf("                    ssssssssss  ");
	gotoxy(1, 12);
	printf("                    sssssssssss ");
	gotoxy(1, 13);
	printf("                  sssssssssssss ");
	gotoxy(1, 14);
	printf("                 sssssssssssssssss ");
	gotoxy(1, 15);
	printf("                sssssssssssssssssssss");
	gotoxy(1, 16);
	printf("               sssssssssssssssssssssss");
	gotoxy(1, 17);
	printf("               sssssssssssssssssssssssso ");
	gotoxy(1, 18);
	printf("             ssssssssssooossssss   ssssss          ");
	gotoxy(1, 19);
	printf("          osssssssssos    sssssso  ssss              ");
	gotoxy(1, 20);
	printf("         osssssssos    sosssssso   sss     ");
	gotoxy(1, 21);
	printf("          'sssssso     ssssssssso  ssss      ");
	gotoxy(1, 22);
	printf("                      ssssssssss+  ssssss        ");
	gotoxy(1, 23);
	printf("                    sssssssssso   ssssss.      ");
	gotoxy(1, 24);
	printf("                   sssssssssssso  ssss  ");
	gotoxy(1, 25);
	printf("                  ssssssssssssssssssss     ");
	gotoxy(1, 26);
	printf("                 sssssssssssssssssssss    ");



}