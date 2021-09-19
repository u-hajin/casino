#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

#define ROUL_X 65

void gotoxy(int x, int y);

struct user {

	char name[22];
	int score;
};

struct roul {
	int x;
	int y;
	int num;
};


char name[22];

unsigned int token;


void menu2();

int show_rule(int m);

void Russian_roulette();
void draw_gun(int n);
void out();

void user_menu();

int user();

void developer();

void horse();
int select_horse();
int run_horse(int, int);
int list();

int rank();
int end_rank();
void draw_rank(int k);

int draw_roulette(struct roul r[], int);
void card_design(int, int, int);

void black();
void slot();
void roulette();
void taisai();

void roulette_bet(int, int*);
void roul_1(int);
void roul_2(int);
void roul_3(int);
void roul_result(int* g, int* c);
void color(int color_number);

void show_rule2();
int play(int bet);
void show_rule3();
int play_slot();
void draw_machine();


void horse_design();

void vs_card(int* i, int* j);
void player_card(int* i, int* j);

void opening();
void ending();
void human(int a, int b);
void build();
void door();
void board();
void board_t();
void star();
void line();
void game_over();

void design();

void show_dice(int dice[], int n);

void CursorView(char show);

void lucky_box();

void beg();