#include "준비중.h"
int arrow = 0, newbie = 0;


void user_menu() {
	int menu;
	int t, test, X, Y, color = 8;
	CursorView(0);

	if (color == 15)color = 8;
	gotoxy(13, 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color++);
	printf("□□□□□□         □□        □□□□□□□  □□□□□  □□□   □□□   □□□□□\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color++);
	gotoxy(13, 6);
	printf("□□    □□        □□□       □□      □□     □□      □□     □□  □□      □□\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color++);
	gotoxy(13, 7);
	printf("□□               □□□□      □□               □□      □□□   □□  □□      □□\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color++);
	gotoxy(13, 8);
	printf("□□              □□  □□     □□□□□□□     □□      □□ □  □□  □□      □□\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color++);
	gotoxy(13, 9);
	printf("□□             □□    □□    □□□□□□□     □□      □□  □ □□  □□      □□\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color++);
	gotoxy(13, 10);
	printf("□□            □□□□□□□             □□     □□      □□   □□□  □□      □□\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color++);
	gotoxy(13, 11);
	printf("□□    □□   □□        □□  □□      □□     □□      □□     □□  □□      □□\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color++);
	gotoxy(13, 12);
	printf("□□□□□□  □□□      □□□ □□□□□□□  □□□□□  □□□  □□□□  □□□□□");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(40, 17);
	printf("----------[사용자 이름 설정]----------");
	gotoxy(40, 18);
	printf("l                                    l");
	gotoxy(40, 19);
	printf("l           1)사용자 선택            l");
	gotoxy(40, 20);
	printf("l                                    l");
	gotoxy(40, 21);
	printf("l           2) 신규 등록             l");
	gotoxy(40, 22);
	printf("l                                    l");
	gotoxy(40, 23);
	printf("--------------------------------------");

	X = 49;
	Y = 19;
	gotoxy(X, Y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("▷ 1) 사용자 선택");

	while (1) {
		test = getch();
		switch (test) {
		case 80:
			if (Y == 21)break;
			else {
				gotoxy(X, 19);
				printf(" ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("  1) 사용자 선택");
				gotoxy(X, 21);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				printf("▷ 2) 신규 등록");
				Y = 21;
				break;
			}

		case 72:
			if (Y == 19)break;
			else {
				gotoxy(X, 21);
				printf(" ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("  2) 신규 등록");
				gotoxy(X, 19);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				printf("▷ 1) 사용자 선택");
				Y = 19;
				break;
			}
		case 13:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			design();
			if (Y == 19)list();
			else if (Y == 21)user();
			break;
		}
		if (arrow == 1)break;
	}
	return;
}


int list() {
	int Y;
	struct user u[5];
	FILE* fb = NULL;
	int i = 0, n, end;

	gotoxy(48, 12);
	printf("+ ㅣ 사용자 선택 ㅣ +");

	fb = fopen("list.txt", "r");
	if (fb == NULL) {
		gotoxy(50, 15);
		printf("FILE OPEN ERROR\n");
		exit(0);
	}
	arrow = 1;

	fseek(fb, 0, 2);   //파일의 마지막으로 이동
	end = ftell(fb);
	if (end < 2) {
		fclose(fb);
		gotoxy(47, 15);
		printf("등록된 사용자가 없습니다.\n");
		gotoxy(40, 17);
		printf("enter 키를 누르면 신규 등록으로 넘어갑니다.");
		getch();
		newbie = 1;
		user();
		return 0;
	}

	rewind(fb);
	Y = 15;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	while (ftell(fb) != end) {
		fscanf(fb, "%s %d\n", u[i].name, &u[i].score);
		gotoxy(50, Y++);
		printf("%d: %s", i + 1, u[i].name);
		i++;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	Y += 2;
	while (1) {
		gotoxy(43, Y + 2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		puts("(신규 등록하려면 0을 입력하세요)");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		gotoxy(43, Y);
		printf("사용자 이름의 번호를 선택하세요: ");
		scanf("%d", &n);
		getchar();
		if (n < 0 || n>i) {
			gotoxy(43, Y + 2);
			puts("                                             ");
			gotoxy(46, 24);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			printf("잘못된 값을 입력하셨습니다.");
			Sleep(1000);
			gotoxy(42, Y);
			puts("                                                   ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else if (n == 0) {
			user();
			return 0;
		}
		else {
			strcpy(name, u[n - 1].name);
			token = u[n - 1].score;
			break;
		}

	}
	fclose(fb);
	system("cls");
	design();
	gotoxy(33, 12);
	printf("현재 사용자의 이름은 ");
	color(6);
	printf("%s, ", name);
	color(15);
	printf("토큰은 ");
	color(6);
	printf("%d", token);
	color(15);
	printf("개 있습니다.");
	gotoxy(33, 15);
	printf("프로그램 기록은 5순위까지만 기록되고,");
	gotoxy(33, 16);
	printf("임의로 프로그램을 종료시키면 순위에 반영되지 않습니다.");
	return 0;

}

int user() {
	struct user u[5] = { 0, };
	FILE* fb = NULL;
	int k = 0, i = 0, z = 0, n, end, w;
	char g;
	system("cls");
	while (1) {
		design();
		gotoxy(48, 12);
		printf("+ ㅣ 신규  등록 ㅣ +           ");
		if (newbie == 1) {
			gotoxy(47, 15); printf("                            ");
			gotoxy(40, 17); printf("                                            ");
		}
		gotoxy(40, 15);
		printf("이름을 입력하시오(공백 없이 최대 20자)");
		CursorView(1);
		gotoxy(44, 20);
		color(6);
		puts("───────────────────────────── ");
		color(15);
		gotoxy(46, 19);
		fgets(name, 22, stdin);
		CursorView(0);
		while (1) {
			if (name[i] == ' ') {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
				gotoxy(46, 22);
				printf("공백은 사용할 수 없습니다.");
				Sleep(500);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				i = 0;
				break;
			}
			else if (name[i] == '\n' || name[i] == '\0') {
				name[i] = 0;
				if (i == 21) {
					color(8);
					gotoxy(47, 22);
					puts("글자 수가 초과되었습니다.");
					color(15);
					Sleep(500);
					while ((g = getchar()) != '\n');
					break;
				}
				break;
			}
			i++;
		}
		if (i == 21) {
			i = 0;
			continue;
		}
		else if (name[i] == 0) break;
	}
	i = 0;

	fb = fopen("list.txt", "r");
	if (fb == NULL) {
		printf("FILE OPEN ERROR");
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
	fclose(fb);
	while (1) {
		if (!(strcmp(name, u[k].name))) {
			while (1) {
				gotoxy(45, 18);
				printf("동일한 이름이 기록에 있습니다.");
				gotoxy(25, 19);
				printf("해당 기록을 사용하시려면 1을, 다른 이름으로 시작하시려면 0을 입력하세요: ");
				scanf("%d", &w);
				while ((g = getchar()) != '\n');
				if (w == 0) {
					strcpy(name, "");
					user();      //재입력
					return 0;
				}
				else if (w == 1) {
					token = u[k].score;
					system("cls");
					design();
					gotoxy(33, 12);
					printf("현재 사용자의 이름은 ");
					color(6);
					printf("%s, ", name);
					color(15);
					printf("토큰은 ");
					color(6);
					printf("%d", token);
					color(15);
					printf("개 있습니다.");
					gotoxy(33, 15);
					printf("프로그램 기록은 5순위까지만 기록되고,");
					gotoxy(33, 16);
					printf("임의로 프로그램을 종료시키면 순위에 반영되지 않습니다.");

					arrow = 1;
					return 0;
				}
				else {
					color(8);
					gotoxy(47, 22);
					puts("잘못된 값을 입력하셨습니다.");
					Sleep(500);
					gotoxy(55, 19);
					puts("here                                                    ");
					color(15);
				}
			}

		}
		k++;
		if (k == n) break;
	}
	token = 25;
	system("cls");
	design();
	gotoxy(33, 10);
	printf("토큰은 기본적으로 25개 주어집니다.");
	gotoxy(33, 12);
	printf("현재 사용자의 이름은 ");
	color(6);
	printf("%s, ", name);
	color(15);
	printf("토큰은 ");
	color(6);
	printf("%d", token);
	color(15);
	printf("개 있습니다.");
	gotoxy(33, 15);
	printf("프로그램 기록은 5순위까지만 기록되고,");
	gotoxy(33, 16);
	printf("임의로 프로그램을 종료시키면 순위에 반영되지 않습니다.");

	arrow = 1; //왓??

	return 0;
}

void design() {
	system("cls");
	color(3);
	gotoxy(22, 6);
	puts("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(22, 7);
	puts("■                                                                        ■");
	gotoxy(22, 8);
	puts("■                                                                        ■");
	gotoxy(22, 9);
	puts("■                                                                        ■");
	gotoxy(22, 10);
	puts("■                                                                        ■");
	gotoxy(22, 11);
	puts("■                                                                        ■");
	gotoxy(22, 12);
	puts("■                                                                        ■");
	gotoxy(22, 13);
	puts("■                                                                        ■");
	gotoxy(22, 14);
	puts("■                                                                        ■");
	gotoxy(22, 15);
	puts("■                                                                        ■");
	gotoxy(22, 16);
	puts("■                                                                        ■");
	gotoxy(22, 17);
	puts("■                                                                        ■");
	gotoxy(22, 18);
	puts("■                                                                        ■");
	gotoxy(22, 19);
	puts("■                                                                        ■");
	gotoxy(22, 20);
	puts("■                                                                        ■");
	gotoxy(22, 21);
	puts("■                                                                        ■");
	gotoxy(22, 22);
	puts("■                                                                        ■");
	gotoxy(22, 23);
	puts("■                                                                        ■");
	gotoxy(22, 24);
	puts("■                                                                        ■");
	gotoxy(22, 25);
	puts("■                                                                        ■");
	gotoxy(22, 26);
	puts("■                                                                        ■");
	gotoxy(22, 27);
	puts("■                                                                        ■");
	gotoxy(22, 28);
	puts("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	color(15);
}


int rank() {   //총 3가지 경우
			//기록으로 5등 안에 든 경우, 순위로는 꼴찌지만 순위가 다 차있지 않은 경우(랭킹등록)
			//순위에 못드는 경우(순위가 다 차있는 경우.등록안됨)
	struct user u[5];
	FILE* fb = NULL;
	int k = 0, i = 0, j = 0, z = 0, e = 0, n, end, tmp;

	system("cls");
	gotoxy(0, 2);
	printf("# 보유 토큰의 수 : %d", token);

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

	//이미 랭킹 등록자 선별
	while (1) {
		if (!(strcmp(name, u[k].name))) {
			fb = fopen("list.txt", "w+"); //데이터 쓰기 모드, 데이터가 있으면 다 지우고 입력한다
			if (fb == NULL) {
				printf("FILE OPEN ERROR\n");
				exit(0);
			}
			for (z = 0; z < n; z++) {      //원래 있는 기록은 지워서 갱신
				if (z != k) {
					fprintf(fb, "%s %d\n", u[z].name, u[z].score);
				}
			}

			/*
			for (z = 0; z < 5; z++) {         //배열 초기화
			   strcpy(u[z].name, "\0");
			   u[z].score = 0;
			}
			*/
			fseek(fb, 0, 2);   //파일의 마지막으로 이동
			end = ftell(fb);

			rewind(fb);
			i = 0;
			while (ftell(fb) != end) {
				fscanf(fb, "%s %d\n", u[i].name, &u[i].score);
				i++;
			}
			n = i; //등록된 사용자 수(1~5)
			fclose(fb);
			break;
		}
		k++;
		if (k == n) break;
	}

	i = 0;
	while (1) {
		if (token >= u[i].score) {   //마지막 순위로 들어가지 않는 이상 어떤 것보단 클 것
							 //만약 동점자가 있으면 최신 등록자가 더 높은 순위를 가져감
			if (n == 5) { //마지막 순위(5등) 기록은 삭제
				j = 4;
			}
			else {
				j = n;   //등록된 사용자 수보다 1개 더 등록해야 하므로 --n이 아닌 그냥 n
				n++;   //등록된 기록 개수 추가됨
			}
			while (j != i) {
				u[j].score = u[j - 1].score;
				strcpy(u[j].name, u[j - 1].name);
				j--;
			}
			u[i].score = token;
			strcpy(u[i].name, name);

			//파일 갱신
			fb = fopen("list.txt", "w"); //데이터 쓰기 모드, 데이터가 있으면 다 지우고 입력한다
			if (fb == NULL) {
				printf("FILE OPEN ERROR\n");
				exit(0);
			}

			for (z = 0; z < n; z++) {      //갱신된 기록 새로 입력
				fprintf(fb, "%s %d\n", u[z].name, u[z].score);
			}
			fclose(fb);

			//순위 출력
			draw_rank(1);
			for (z = 0, e = 7; z < n; z++, e += 3) {
				gotoxy(37, e);
				printf("%d: %s", z + 1, u[z].name);
				gotoxy(68, e);
				printf("토큰 %d 개", u[z].score);
			}
			gotoxy(35, 31);
			color(8);
			printf("---아무 키를 누르면 메인 메뉴로 돌아갑니다.--- ");
			getch();
			color(15);

			//러시안 룰렛
			if ((token > 300 && token < 400) || (token > 900 && token < 1000) || (token > 100000 && token < 200000) || (token > 100000000 && token < 200000000))
				Russian_roulette();
			//

			return 0;   //함수 끝~
		}
		else {
			if (i + 1 == n) break;
		}
		i++;
	}

	//어느 순위보다 높지 않았을 경우
	if (n < 5) {   //순위에 자리가 남았을 경우
		fb = fopen("list.txt", "a"); //데이터 추가 모드로 열기
		if (fb == NULL) {
			printf("FILE OPEN ERROR\n");
			exit(0);
		}
		fprintf(fb, "%s %d\n", name, token);   //마지막 순위에 기록 추가하기
		fclose(fb);

		//순위 출력
		draw_rank(1);
		for (z = 0, e = 7; z < n; z++, e += 3) {
			gotoxy(37, e);
			printf("%d: %s", z + 1, u[z].name);
			gotoxy(68, e);
			printf("토큰 %d 개", u[z].score);
		}
		gotoxy(37, e);
		printf("%d: %s", z + 1, name);
		gotoxy(68, e);
		printf("토큰 %d 개", token);

		gotoxy(35, 31);
		color(8);
		printf("---아무 키를 누르면 메인 메뉴로 돌아갑니다.--- ");
		getch();
		color(15);
	}
	else {         //순위가 5등까지 꽉 차있는 경우
		draw_rank(0);
		for (z = 0, e = 7; z < n; z++, e += 3) {
			gotoxy(37, e);
			printf("%d: %s", z + 1, u[z].name);
			gotoxy(68, e);
			printf("토큰 %d 개", u[z].score);
		}
		gotoxy(35, 29);
		color(8);
		printf("---아무 키를 누르면 메인 메뉴로 돌아갑니다.--- ");
		getch();
		color(15);
	}
	if ((token > 300 && token < 400) || (token > 900 && token < 1000) || (token > 100000 && token < 200000) || (token > 100000000 && token < 200000000))
		Russian_roulette();
	return 0;
}

int end_rank() {
	struct user u[5];
	FILE* fb = NULL;
	int k = 0, i = 0, j = 0, z = 0, n, end, tmp;

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
			fb = fopen("list.txt", "w+"); //데이터 쓰기 모드, 데이터가 있으면 다 지우고 입력한다
			if (fb == NULL) {
				printf("FILE OPEN ERROR\n");
				exit(0);
			}
			for (z = 0; z < n; z++) {      //원래 있는 기록은 지워서 갱신
				if (z != k) {
					fprintf(fb, "%s %d\n", u[z].name, u[z].score);
				}
			}
			fseek(fb, 0, 2);   //파일의 마지막으로 이동
			end = ftell(fb);
			rewind(fb);
			while (ftell(fb) != end) {
				fscanf(fb, "%s %d\n", u[i].name, &u[i].score);
				i++;
			}
			n = i; //등록된 사용자 수(1~5)
			fclose(fb);
			break;
		}
		k++;
		if (k == n) break;
	}
	i = 0;
	while (1) {
		if (token >= u[i].score) {   //마지막 순위로 들어가지 않는 이상 어떤 것보단 클 것
							 //만약 동점자가 있으면 최신 등록자가 더 높은 순위를 가져감
			if (n == 5) { //마지막 순위(5등) 기록은 삭제
				j = 4;
			}
			else {
				j = n;   //등록된 사용자 수보다 1개 더 등록해야 하므로 --n이 아닌 그냥 n
				n++;   //등록된 기록 개수 추가됨
			}
			while (j != i) {
				u[j].score = u[j - 1].score;
				strcpy(u[j].name, u[j - 1].name);
				j--;
			}
			u[i].score = token;
			strcpy(u[i].name, name);

			//파일 갱신
			fb = fopen("list.txt", "w"); //데이터 쓰기 모드, 데이터가 있으면 다 지우고 입력한다
			if (fb == NULL) {
				printf("FILE OPEN ERROR\n");
				exit(0);
			}

			for (z = 0; z < n; z++) {      //갱신된 기록 새로 입력
				fprintf(fb, "%s %d\n", u[z].name, u[z].score);
			}
			fclose(fb);
			//
			return 0;   //함수 끝~
		}
		else {
			if (i + 1 == n) break;
		}
		i++;
	}

	//어느 순위보다 높지 않았을 경우
	if (n < 5) {   //순위에 자리가 남았을 경우
		fb = fopen("list.txt", "a"); //데이터 추가 모드로 열기
		if (fb == NULL) {
			printf("FILE OPEN ERROR\n");
			exit(0);
		}
		fprintf(fb, "%s %d\n", name, token);   //마지막 순위에 기록 추가하기
		fclose(fb);
	}
	return 0;
}

void draw_rank(int k) {
	color(3);
	gotoxy(53, 3);
	puts("▶ 순위표 ◀");
	color(6);
	gotoxy(30, 5);
	printf("┌───────────────────────────────────────────────────────┐ ");
	gotoxy(30, 6);
	printf("│                                                       │ ");
	gotoxy(30, 7);
	printf("│                                                       │ ");
	gotoxy(30, 8);
	printf("│                                                       │ ");
	gotoxy(30, 9);
	printf("│                                                       │ ");
	gotoxy(30, 10);
	printf("│                                                       │ ");
	gotoxy(30, 11);
	printf("│                                                       │ ");
	gotoxy(30, 12);
	printf("│                                                       │ ");
	gotoxy(30, 13);
	printf("│                                                       │ ");
	gotoxy(30, 14);
	printf("│                                                       │ ");
	gotoxy(30, 15);
	printf("│                                                       │ ");
	gotoxy(30, 16);
	printf("│                                                       │ ");
	gotoxy(30, 17);
	printf("│                                                       │ ");
	gotoxy(30, 18);
	printf("│                                                       │ ");
	gotoxy(30, 19);
	printf("│                                                       │ ");
	gotoxy(30, 20);
	printf("│                                                       │ ");
	gotoxy(30, 21);
	printf("└───────────────────────────────────────────────────────┘ ");

	if (k) {
		gotoxy(30, 25);
		puts("♬");
		gotoxy(25, 24);
		puts("♬");
		gotoxy(90, 24);
		puts("♬");
		gotoxy(85, 26);
		puts("♬");

		color(15);
		gotoxy(35, 23);
		puts("＼ ● ／  ＼ ●        ●        ● ／  ＼ ● ／ ");
		gotoxy(35, 24);
		puts(" ┌───┐     ┌───┐     ┌───┐     ┌───┐     ┌───┐ ");
		gotoxy(35, 25);
		puts(" │   │     │   │＼   │| |│   ／│   │     │   │ ");
		gotoxy(35, 26);
		puts(" │   │     │   │     │   │     │   │     │   │ ");
		gotoxy(35, 27);
		puts(" └───┘     └───┘     └───┘     └───┘     └───┘ ");
		gotoxy(35, 28);
		puts(" ／  ＼    ／  |      |  |      |  ＼    ／  ＼ ");
	}
	else {
		color(15);
		gotoxy(35, 24);
		printf("아쉽게도 순위에 들지 못했습니다.");
		gotoxy(73, 23);
		puts("┌──────┐  ");
		gotoxy(71, 24);
		puts("●│      │   ");
		gotoxy(73, 25);
		puts("└──────┘ ");
		gotoxy(73, 26);
		puts(" │     └─ ");
	}
}