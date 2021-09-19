#include "준비중.h"


void draw_gun(int n) {
	color(15);
	gotoxy(0, 1);
	printf("# 보유 토큰의 수 : %d ", token);
	color(6);
	gotoxy(7, 5);
	puts("    ■                    ■■■");
	gotoxy(7, 6);
	puts("  ■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(7, 7);
	puts(" ■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(7, 8);
	puts("■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(7, 9);
	puts(" ■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(7, 10);
	puts("   ■■■■■  ■■■  ■■■■■■■■■■■■■■■");
	gotoxy(7, 11);
	puts("   ■■■■■    ■■    ■");
	gotoxy(7, 12);
	puts("   ■■■■■      ■    ■ ");
	gotoxy(7, 13);
	puts("   ■■■■■■        ■■");
	gotoxy(7, 14);
	puts("   ■■■■■■■■■■■■");
	gotoxy(7, 15);
	puts("   ■■■■■■■");
	gotoxy(7, 16);
	puts("  ■■■■■■■");
	gotoxy(7, 17);
	puts(" ■■■■■■■");
	gotoxy(7, 18);
	puts(" ■■■■■■■");
	gotoxy(7, 19);
	puts("■■■■■■■");
	gotoxy(7, 20);
	puts("■■■■■■■");
	gotoxy(7, 21);
	puts("■■■■■■■");
	gotoxy(7, 22);
	puts("■■■■■■■");
	gotoxy(7, 23);
	color(15);

	if (n) {
		gotoxy(17, 8);
		switch (n) {
		case 7:
			puts("●●●●●● ");
			break;
		case 6:
			puts("●●●●●○ ");
			break;
		case 5:
			puts("●●●●○○ ");
			break;
		case 4:
			puts("●●●○○○ ");
			break;
		case 3:
			puts("●●○○○○ ");
			break;
		case 2:
			puts("●○○○○○ ");
			break;
		case 1:
			puts("○○○○○○ ");
			break;
		}


	}
}

void Russian_roulette() {
	int i = 0, f, n;
	int ch;
	char russ[6] = { 0, };
	system("mode con cols=120 lines=35");
	CursorView(0);
	gotoxy(0, 1);
	printf("# 보유 토큰의 수 : %d", token);
	system("cls");
	gotoxy(50, 7);
	printf("+ 러시안 룰렛 +");
	gotoxy(23, 9);
	printf("사망하면 모든 기록이 사라지고, 성공하면 현재 토큰의 300배를 얻게 됩니다.");
	gotoxy(48, 13);
	printf("받아들이시겠습니까?");
	color(5);
	gotoxy(44, 18);
	puts("┌───────────┬───────────┐ ");
	gotoxy(44, 19);
	puts("│           │           │ ");
	gotoxy(44, 20);
	puts("│           │           │ ");
	gotoxy(44, 21);
	puts("│           │           │ ");
	gotoxy(44, 22);
	puts("└───────────┴───────────┘ ");
	color(15);
	gotoxy(49, 20);
	puts("yes");
	gotoxy(62, 20);
	puts("no");
	while (1) {
		ch = getch();
		if (ch == 224) {
			ch = getch();
			switch (ch) {
			case 75:         //왼쪽
				color(15);
				gotoxy(62, 20);
				puts("no");
				color(6);
				gotoxy(49, 20);
				puts("yes");
				f = 1;
				break;
			case 77:         //오른쪽
				color(15);
				gotoxy(49, 20);
				puts("yes");
				color(6);
				gotoxy(62, 20);
				puts("no");
				f = 0;
				break;
			}
		}
		else if (ch == 13) break;
	}
	system("cls");

	if (f) {
		draw_gun(0);
		gotoxy(55, 13);
		printf("6연발 리볼버가 눈앞에 있습니다.");
		Sleep(1000);
		gotoxy(50, 15);
		printf("총알을 한 발만 장전하고 탄창을 돌립니다");
		Sleep(1000);
		gotoxy(50, 15);
		printf("총알을 한 발만 장전하고 탄창을 돌립니다.");
		Sleep(1000);
		gotoxy(50, 15);
		printf("총알을 한 발만 장전하고 탄창을 돌립니다..");
		Sleep(1000);
		gotoxy(50, 15);
		printf("총알을 한 발만 장전하고 탄창을 돌립니다...");
		Sleep(1000);
		//russ[rand() % 6] = 1;


		gotoxy(56, 19);
		printf("먼저 방아쇠를 당기시겠습니까?");
		color(5);
		gotoxy(57, 21);
		puts("┌───────────┬───────────┐ ");
		gotoxy(57, 22);
		puts("│           │           │ ");
		gotoxy(57, 23);
		puts("│           │           │ ");
		gotoxy(57, 24);
		puts("│           │           │ ");
		gotoxy(57, 25);
		puts("└───────────┴───────────┘ ");
		color(15);
		gotoxy(62, 23);
		puts("yes");
		gotoxy(75, 23);
		puts("no");
		while (1) {
			ch = getch();
			if (ch == 224) {
				ch = getch();
				switch (ch) {
				case 75:         //왼쪽
					color(15);
					gotoxy(75, 23);
					puts("no");
					color(6);
					gotoxy(62, 23);
					puts("yes");
					f = 1;
					break;
				case 77:         //오른쪽
					color(15);
					gotoxy(62, 23);
					puts("yes");
					color(6);
					gotoxy(75, 23);
					puts("no");
					f = 0;
					break;
				}
			}
			else if (ch == 13) break;
		}
		system("cls");
		n = 7;
		draw_gun(n);
		if (f) {
			while (1) {
				if (!(i % 2)) {
					gotoxy(67, 7);
					printf("[%s] 이 방아쇠를 당겼습니다.", name);
					Sleep(2000);
					if (russ[i] == 0) {
						gotoxy(67, 9);
						printf("틱! 불발입니다.");
						n--;
						draw_gun(n);
						Sleep(1000);
					}
					else {
						gotoxy(67, 9);
						printf("탕!");
						n--;
						draw_gun(n);
						Sleep(1000);
						gotoxy(67, 13);
						printf("[%s] 이 사망하였습니다.", name);
						Sleep(1000);
						color(1);
						gotoxy(40, 20);
						printf("모든 정보와 기록들, 토큰이 사라집니다.");
						token = 0;
						Sleep(2000);
						system("cls");
						ending();
						Sleep(1000);
						out();
						break;
					}
				}
				else {
					gotoxy(67, 7);
					printf("[COMPUTER] 가 방아쇠를 당겼습니다.");
					Sleep(2000);
					if (russ[i] == 0) {
						gotoxy(67, 9);
						printf("틱! 불발입니다.");
						n--;
						draw_gun(n);
						Sleep(1000);
					}
					else {
						gotoxy(67, 9);
						printf("탕!");
						n--;
						draw_gun(n);
						Sleep(1000);
						gotoxy(67, 13);
						printf("[COMPUTER] 가 사망하였습니다.");
						color(1);
						gotoxy(58, 19);
						printf("축하합니다.");
						gotoxy(30, 21);
						printf("당신은 단 한번의 기회를 성공시켜 현재 코인의 300배를 얻게 되었습니다.");
						color(8);
						gotoxy(35, 26);
						printf("--아무 키를 누르면 게임이 종료됩니다.--");
						color(15);
						token = token * 300;
						getch();
						break;
					}
				}
				i++;
				system("cls");
				draw_gun(n);
				Sleep(1000);
			}
		}
		else {
			while (1) {
				if (!(i % 2)) {
					gotoxy(67, 7);
					printf("[COMPUTER] 가 방아쇠를 당겼습니다.");
					Sleep(2000);
					if (russ[i] == 0) {
						gotoxy(67, 9);
						printf("틱! 불발입니다.");
						n--;
						draw_gun(n);
						Sleep(1000);
					}
					else {
						gotoxy(67, 9);
						printf("탕!");
						n--;
						draw_gun(n);
						Sleep(1000);
						gotoxy(67, 13);
						printf("[COMPUTER] 가 사망하였습니다.");
						color(1);
						gotoxy(58, 19);
						printf("축하합니다.");
						gotoxy(30, 21);
						printf("당신은 단 한번의 기회를 성공시켜 현재 코인의 300배를 얻게 되었습니다.");
						color(8);
						gotoxy(35, 26);
						printf("--아무 키를 누르면 게임이 종료됩니다.--");
						color(15);
						token = token * 300;
						getch();
						break;
					}
				}
				else {
					gotoxy(67, 7);
					printf("[%s] 이 방아쇠를 당겼습니다.", name);
					Sleep(2000);
					if (russ[i] == 0) {
						gotoxy(67, 9);
						printf("틱! 불발입니다.");
						n--;
						draw_gun(n);
						Sleep(1000);
					}
					else {
						gotoxy(67, 9);
						printf("탕!");
						n--;
						draw_gun(n);
						Sleep(1000);
						gotoxy(67, 13);
						printf("[%s] 이 사망하였습니다.", name);
						Sleep(1000);
						color(1);
						gotoxy(40, 20);
						printf("모든 정보와 기록들, 토큰이 사라집니다.");
						token = 0;
						Sleep(2000);
						system("cls");
						ending();
						Sleep(1000);
						out();
						break;
					}
				}
				i++;
				system("cls");
				draw_gun(n);
				Sleep(1000);
			}
		}
	}
	CursorView(1);
}

void out() {
	struct user u[5];
	FILE* fb = NULL;
	int k = 0, i = 0, z = 0, n, end;

	fb = fopen("list.txt", "r");
	if (fb == NULL) {
		printf("FILE OPEN ERROR\n");
		exit(0);
	}

	fseek(fb, 0, 2);   //파일의 마지막으로 이동
	end = ftell(fb);
	rewind(fb);
	while (ftell(fb) != end) {
		fscanf(fb, "%s %d\n", u[i].name, &u[i].score);
		i++;
	}
	n = i; //등록된 사용자 수(1~5)
	i = 0;
	fclose(fb); //파일 일단 닫아줌

	while (1) {
		if (!(strcmp(name, u[k].name))) {
			fb = fopen("list.txt", "w"); //데이터 쓰기 모드, 데이터가 있으면 다 지우고 입력한다
			if (fb == NULL) {
				printf("FILE OPEN ERROR\n");
				exit(0);
			}
			for (z = 0; z < n; z++) {      //원래 있는 기록은 지워서 갱신
				if (z != k) {
					fprintf(fb, "%s %d\n", u[z].name, u[z].score);
				}
			}
			fclose(fb);
			break;
		}
		k++;
		if (k == n) break;
	}
}