#include "준비중.h"
int card[52] = { 1,2,3,4,5,6,7,8,9,10,10,10,10,
			1,2,3,4,5,6,7,8,9,10,10,10,10,
			1,2,3,4,5,6,7,8,9,10,10,10,10,
			1,2,3,4,5,6,7,8,9,10,10,10,10 };
int sum_player, sum_deal;
int deal[21], money;
int player[21];
int black_count;
void black() {
	int i = 2, j = 2;
	system("cls");
	gotoxy(0, 1);
	printf("# 보유 토큰의 수 : %d", token);

	while (1) {
		gotoxy(50, 5);
		printf("배팅할 토큰의 개수를 입력하시오: ");
		scanf("%d", &money); getchar();
		gotoxy(50, 7);
		if (money > token) {
			printf("(system) 토큰의 개수가 부족합니다.");
			gotoxy(50, 5); printf("                                                                ");
		}
		else {
			printf("배팅할 토큰의 개수가 결정되었습니다. ");
			break;
		}
	}
	gotoxy(50, 7); printf("                                         ");
	token -= money;
	gotoxy(0, 1);
	printf("# 보유 토큰의 수 : %d", token);
	gotoxy(0, 3);
	printf("# 배팅한 토큰의 수 : %d", money);
	srand((unsigned)time(0));
	deal[0] = rand() % 52;
	player_card(&i, &j);
	vs_card(&i, &j);
	gotoxy(83, 33);
	printf("아무 키나 누르면 게임이 종료됩니다.");
	getchar();
}

void player_card(int* i, int* j) {

	int choose = 2, q, k, ace;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(5, 7);   printf("[딜러]");
	gotoxy(5, 21);   printf("[플레이어]");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


	gotoxy(45, 3);
	printf("딜러와 플레이어, 카드 두장을 나눠 가집니다.");
	do {
		deal[1] = rand() % 52;
	} while (deal[0] == deal[1]);
	do {
		player[0] = rand() % 52;
	} while (player[0] == deal[0] || player[0] == deal[1]);
	do {
		player[1] = rand() % 52;
	} while (player[0] == player[1] || player[0] == deal[0] || player[0] == deal[1]);

	sum_deal = card[deal[0]] + card[deal[1]];
	sum_player = card[player[0]] + card[player[1]];
	card_design(1, card[deal[1]], 0);
	card_design(2, card[player[0]], card[player[1]]);

	gotoxy(45, 5);
	printf("아무키나 누르면 플레이어의 차례로 넘어갑니다.");
	getchar();
	gotoxy(45, 5);
	printf("                                                    ");

	while (1) {
		while (choose != 1 && choose != 0) {
			gotoxy(45, 3);
			printf("카드를 더 뽑으시겠습니까? (맞으면 1, 아니면 0 입력) ");
			black_count++;
			scanf("%d", &choose);
			getchar();
		}
		if (choose == 1) {
			for (q = 0; q < *i; q++) {
				do {
					player[*i] = rand() % 52;
				} while (player[*i] == player[q]);
			}
			gotoxy(45, 5);
			printf("카드 한 장을 더 뽑았습니다. ");
			gotoxy(45, 7);
			printf("아무키나 누르면 카드 결과로 넘어갑니다.");
			getchar();
			gotoxy(45, 3); printf("                                                                ");
			gotoxy(45, 5); printf("                                 ");
			gotoxy(45, 7); printf("                                        ");
			gotoxy(45, 3);
			if (card[player[*i]] == 1) {
				do {
					printf("Ace를 1과 11 중 어떤 숫자로 사용하시겠습니까? ");
					scanf("%d", &ace);
				} while (ace != 1 && ace != 11);
				if (ace == 1)card[player[*i]] = 1;
				else card[player[*i]] = 11;
				card_design(3, card[player[*i]], 0);
			}
			else if (player[*i] == 10 || player[*i] == 23 || player[*i] == 36 || player[*i] == 49)   card_design(3, 10, 1);
			else if (player[*i] == 11 || player[*i] == 24 || player[*i] == 37 || player[*i] == 50)   card_design(3, 10, 2);
			else if (player[*i] == 12 || player[*i] == 25 || player[*i] == 38 || player[*i] == 51) card_design(3, 10, 3);
			else card_design(3, card[player[*i]], 0);
			sum_player += card[player[*i]];
			(*i)++;
		}
		else if (choose == 0)break;
		choose = 2;
	}
	gotoxy(45, 5);
	printf("아무키나 누르면 딜러의 차례로 넘어갑니다.");
	getchar();
	gotoxy(45, 5); printf("                                                ");
	black_count = 0;
	if (sum_deal <= 16) {
		do {
			for (q = 0; q < *j; q++) {
				do {
					deal[*j] = rand() % 52;
				} while (deal[*j] == deal[q]);
			}
			for (q = 0; q < *i; q++) {
				do {
					deal[*j] = rand() % 52;
				} while (deal[*j] == player[q]);
			}
			gotoxy(45, 3);
			printf("딜러가 한장의 카드를 더 뽑습니다.                             ");
			black_count++;
			if (card[deal[*j]] == 1) {
				if (sum_deal + 11 > 21) {
					card[deal[*j]] = 1;
				}
				else card[deal[*j]] = 11;
			}
			else if (deal[*j] == 10 || deal[*j] == 23 || deal[*j] == 36 || deal[*j] == 49)    card_design(4, 10, 1);
			else if (deal[*j] == 11 || deal[*j] == 24 || deal[*j] == 37 || deal[*j] == 50)   card_design(4, 10, 2);
			else if (deal[*j] == 12 || deal[*j] == 25 || deal[*j] == 38 || deal[*j] == 51)   card_design(4, 10, 3);
			else card_design(4, card[deal[*j]], 0);
			sum_deal += card[deal[*j]];
			(*j)++;
		} while (sum_deal <= 16);
	}
	else {
		gotoxy(45, 3);
		printf("딜러 카드의 합이 16을 넘어 더 이상 카드를 뽑지 않습니다.");
	}
	gotoxy(45, 5);
	printf("아무 키나 누르면 게임 합산으로 넘어갑니다.                     ");
	getchar();

}
void vs_card(int* i, int* j) {
	gotoxy(90, 3);
	printf("# 딜러 카드 합산 : %d", sum_deal);
	gotoxy(90, 5);
	printf("# 플레이어 카드 합산 : %d", sum_player);
	card_design(5, card[deal[0]], 0);
	gotoxy(20, 19);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	if (sum_player > 21) printf("플레이어의 카드 합이 21을 넘어섰기에 [딜러의 승!]   베팅 금액 전부를 잃습니다.");
	else if (sum_deal > 21) {
		printf("딜러의 카드 합이 21을 넘어섰기에 [플레이어의 승!]   베팅 금액의 2배를 얻습니다. ");
		token += (money * 2);
	}
	else if (sum_deal == sum_player) {
		printf("[무승부]  베팅금액의 0.5배를 잃습니다.");
		token += (money * 0.5);
	}
	else if (sum_deal > sum_player) printf("[딜러의 승!]  베팅 금액을 전부 잃습니다.");
	else {
		printf("[플레이어의 승!]  베팅 금액의 1.5배를 얻습니다.");
		token += (money * 1.5);
	}
	return;
}

void card_design(i, j, k) {
	int x = 0, y = 8, flag = 0;
	if (i == 2)   y = 22;
	if (i == 3) {
		x = 22 + (17 * black_count); y = 22;
	}
	if (i == 4) {
		x = 22 + (17 * black_count); y = 8;
	}
	if (i == 5) x = 17;
	while (1) {
		if (flag == 1) {
			x = 17;  y = 22; i = 3;  j = k;
		}
		if (j == 0) {
			x = 17; y = 8; i = 3;
		}
		gotoxy(5 + x, y++);
		printf("┌───────────────┐");
		gotoxy(5 + x, y++);
		printf("│               │");
		gotoxy(5 + x, y++);
		printf("│               │");
		gotoxy(5 + x, y++);
		printf("│               │");
		gotoxy(5 + x, y++);
		printf("│               │");
		gotoxy(5 + x, y++);
		printf("│               │");
		gotoxy(5 + x, y++);
		printf("│               │");
		gotoxy(5 + x, y++);
		printf("│               │");
		gotoxy(5 + x, y++);
		printf("│               │");
		gotoxy(5 + x, y++);
		printf("│               │");
		gotoxy(5 + x, y++);
		printf("└───────────────┘");
		if (i == 2 || i == 3)y = 24;
		else y = 10;
		switch (j) {
		case 0:
			y = 10;
			gotoxy(7 + x, y++);
			printf("  ■■■■■");
			gotoxy(7 + x, y++);
			printf("          ■");
			gotoxy(7 + x, y++);
			printf("          ■");
			gotoxy(7 + x, y++);
			printf("    ■■■■");
			gotoxy(7 + x, y++);
			printf("    ■");
			gotoxy(7 + x, y++);
			printf("    ■ ");
			gotoxy(7 + x, y++);
			printf("");
			gotoxy(7 + x, y++);
			printf("    ■ ");
			break;
		case 1:
			gotoxy(7 + x, y++);
			printf("      ■");
			gotoxy(7 + x, y++);
			printf("  ■■■");
			gotoxy(7 + x, y++);
			printf("      ■");
			gotoxy(7 + x, y++);
			printf("      ■");
			gotoxy(7 + x, y++);
			printf("      ■");
			gotoxy(7 + x, y++);
			printf("      ■");
			gotoxy(7 + x, y++);
			printf("      ■");
			gotoxy(7 + x, y++);
			printf("  ■■■■■");
			break;
		case 2:
			gotoxy(7 + x, y++);
			printf("■■■■■■");
			gotoxy(7 + x, y++);
			printf("          ■");
			gotoxy(7 + x, y++);
			printf("          ■");
			gotoxy(7 + x, y++);
			printf("■■■■■■");
			gotoxy(7 + x, y++);
			printf("■ ");
			gotoxy(7 + x, y++);
			printf("■");
			gotoxy(7 + x, y++);
			printf("■");
			gotoxy(7 + x, y++);
			printf("■■■■■■");
			break;
		case 3:
			gotoxy(7 + x, y++);
			printf("■■■■■■");
			gotoxy(7 + x, y++);
			printf("          ■");
			gotoxy(7 + x, y++);
			printf("          ■");
			gotoxy(7 + x, y++);
			printf("■■■■■■");
			gotoxy(7 + x, y++);
			printf("          ■");
			gotoxy(7 + x, y++);
			printf("          ■");
			gotoxy(7 + x, y++);
			printf("          ■");
			gotoxy(7 + x, y++);
			printf("■■■■■■");
			break;
		case 4:
			gotoxy(7 + x, y++);
			printf("  ■      ■");
			gotoxy(7 + x, y++);
			printf("  ■      ■");
			gotoxy(7 + x, y++);
			printf("  ■      ■");
			gotoxy(7 + x, y++);
			printf("  ■      ■");
			gotoxy(7 + x, y++);
			printf("  ■■■■■");
			gotoxy(7 + x, y++);
			printf("          ■");
			gotoxy(7 + x, y++);
			printf("          ■");
			gotoxy(7 + x, y++);
			printf("        ■■■");
			break;
		case 5:
			gotoxy(7 + x, y++);
			printf("■■■■■■");
			gotoxy(7 + x, y++);
			printf("■   ");
			gotoxy(7 + x, y++);
			printf("■    ");
			gotoxy(7 + x, y++);
			printf("■■■■■■");
			gotoxy(7 + x, y++);
			printf("          ■");
			gotoxy(7 + x, y++);
			printf("          ■");
			gotoxy(7 + x, y++);
			printf("          ■");
			gotoxy(7 + x, y++);
			printf("■■■■■■");
			break;
		case 6:
			gotoxy(7 + x, y++);
			printf("■■■■■■");
			gotoxy(7 + x, y++);
			printf("■   ");
			gotoxy(7 + x, y++);
			printf("■    ");
			gotoxy(7 + x, y++);
			printf("■■■■■■■");
			gotoxy(7 + x, y++);
			printf("■          ■");
			gotoxy(7 + x, y++);
			printf("■          ■");
			gotoxy(7 + x, y++);
			printf("■          ■");
			gotoxy(7 + x, y++);
			printf("■■■■■■■");
			break;
		case 7:
			gotoxy(7 + x, y++);
			printf(" ■■■■■■");
			gotoxy(7 + x, y++);
			printf(" ■        ■");
			gotoxy(7 + x, y++);
			printf(" ■        ■");
			gotoxy(7 + x, y++);
			printf("           ■");
			gotoxy(7 + x, y++);
			printf("           ■");
			gotoxy(7 + x, y++);
			printf("           ■");
			gotoxy(7 + x, y++);
			printf("           ■");
			gotoxy(7 + x, y++);
			printf("           ■");
			break;
		case 8:
			gotoxy(7 + x, y++);
			printf("  ■■■■■");
			gotoxy(7 + x, y++);
			printf("  ■      ■");
			gotoxy(7 + x, y++);
			printf("  ■      ■");
			gotoxy(7 + x, y++);
			printf("  ■■■■■");
			gotoxy(7 + x, y++);
			printf("  ■      ■");
			gotoxy(7 + x, y++);
			printf("  ■      ■");
			gotoxy(7 + x, y++);
			printf("  ■      ■");
			gotoxy(7 + x, y++);
			printf("  ■■■■■");
			break;
		case 9:
			gotoxy(7 + x, y++);
			printf(" ■■■■■■");
			gotoxy(7 + x, y++);
			printf(" ■        ■");
			gotoxy(7 + x, y++);
			printf(" ■        ■");
			gotoxy(7 + x, y++);
			printf(" ■■■■■■");
			gotoxy(7 + x, y++);
			printf("           ■");
			gotoxy(7 + x, y++);
			printf("           ■");
			gotoxy(7 + x, y++);
			printf("           ■");
			gotoxy(7 + x, y++);
			printf(" ■■■■■■");
			break;
		case 10:
			if (i == 3 || i == 4 && k == 1) {
				gotoxy(7 + x, y++);
				printf(" ■■■■■■");
				gotoxy(7 + x, y++);
				printf("         ■");
				gotoxy(7 + x, y++);
				printf("         ■");
				gotoxy(7 + x, y++);
				printf("         ■");
				gotoxy(7 + x, y++);
				printf("         ■");
				gotoxy(7 + x, y++);
				printf("         ■");
				gotoxy(7 + x, y++);
				printf(" ■      ■");
				gotoxy(7 + x, y++);
				printf("  ■■■■");
				break;
			}
			else if (i == 3 || i == 4 && k == 2) {
				gotoxy(7 + x, y++);
				printf(" ■■■■■■");
				gotoxy(7 + x, y++);
				printf(" ■        ■");
				gotoxy(7 + x, y++);
				printf(" ■        ■");
				gotoxy(7 + x, y++);
				printf(" ■        ■");
				gotoxy(7 + x, y++);
				printf(" ■        ■");
				gotoxy(7 + x, y++);
				printf(" ■   ■   ■");
				gotoxy(7 + x, y++);
				printf(" ■■■■■■");
				gotoxy(7 + x, y++);
				printf("         ■");
				break;
			}
			else if (i == 3 || i == 4 && k == 3) {

				gotoxy(7 + x, y++);
				printf("   ■     ■");
				gotoxy(7 + x, y++);
				printf("   ■   ■");
				gotoxy(7 + x, y++);
				printf("   ■  ■ ");
				gotoxy(7 + x, y++);
				printf("   ■ ■ ");
				gotoxy(7 + x, y++);
				printf("   ■ ■ ");
				gotoxy(7 + x, y++);
				printf("   ■  ■");
				gotoxy(7 + x, y++);
				printf("   ■   ■ ");
				gotoxy(7 + x, y++);
				printf("   ■    ■");
				break;
			}
			else {
				gotoxy(7 + x, y++);
				printf(" ■  ■■■■");
				gotoxy(7 + x, y++);
				printf(" ■  ■    ■");
				gotoxy(7 + x, y++);
				printf(" ■  ■    ■");
				gotoxy(7 + x, y++);
				printf(" ■  ■    ■");
				gotoxy(7 + x, y++);
				printf(" ■  ■    ■");
				gotoxy(7 + x, y++);
				printf(" ■  ■    ■");
				gotoxy(7 + x, y++);
				printf(" ■  ■    ■");
				gotoxy(7 + x, y++);
				printf(" ■  ■■■■");
				break;
			}
		case 11:
			gotoxy(7 + x, y++);
			printf("  ■    ■");
			gotoxy(7 + x, y++);
			printf("■■  ■■");
			gotoxy(7 + x, y++);
			printf("  ■    ■");
			gotoxy(7 + x, y++);
			printf("  ■    ■");
			gotoxy(7 + x, y++);
			printf("  ■    ■");
			gotoxy(7 + x, y++);
			printf("  ■    ■");
			gotoxy(7 + x, y++);
			printf("  ■    ■");
			gotoxy(7 + x, y++);
			printf("  ■    ■");
			break;
		}
		if (i == 1) j = 0;
		else if (i == 3 || i == 4 || i == 5)break;
		else if (i == 2) {
			flag = 1;
			continue;
		}
	}


}