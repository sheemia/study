/*下面我们把这 1 个文件拆成一个“真正”的 C 语言工程。
我会先告诉你为什么要拆分、拆成什么样，再给出每一步的具体操作。最后把整个目录结构、编译脚本都摆出来，你照着做就能跑起来。
────────────────────
一、为什么要拆分？
1. 
单文件在初学阶段很方便，但项目一大就“挤爆”：
函数太多，上下翻几百行找不到人。
任何一次小改动都要全量重编译。
多人协作会互相覆盖。
2. 
拆成多文件后：
每个 .c 只干一件事，阅读、调试、单元测试都简单。
只要改一个 .c，就只需重编译这一个目标文件，再链接即可，节省时间。
头文件(.h)提供“接口”，实现细节藏在 .c，别人不用关心。
方便以后做库、做测试框架、做 CI/CD。
────────────────────
二、该拆成什么样？
对井字棋来说，通常划分为：
src/ 源文件（实现）
include/ 公共头文件（接口）
test/ 单元测试（可选，这里先不放）
build/ 编译产物（.o 与可执行文件）
Makefile    告诉编译器怎么把 .o 链接成程序
把原来 300 多行的 tictactoe.c 拆成：
include/game.h      数据结构 + 对外函数声明
src/game.c          游戏核心逻辑（初始化、胜负判断、统计）
src/ui.c            纯粹与用户交互/打印界面
src/main.c          只负责 main 函数 + 主菜单循环
────────────────────
三、具体拆分步骤
1. 
创建目录

tic_tac_toe/
├── include/
├── src/
├── build/
└── Makefile

2. 
把数据结构、函数声明放进 include/game.h
c*/
#ifndef GAME_H
#define GAME_H

#define BOARD_SIZE 3

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    int player1_wins;
    int player2_wins;
    int draws;
    int total_games;
} Game;

/* 游戏核心 API */
void initialize_board(Game *game);
int  check_win   (Game *game, char player);
int  check_draw  (Game *game);
void print_stats (Game *game);

/* UI 相关 API */
void print_board (Game *game);
void get_player_input(int *row, int *col);
void show_instructions(void);
void play_game   (Game *game);
int  main_menu   (void);
void clear_input_buffer(void);

#endif

/*3. 
实现游戏逻辑 → src/game.c
c*/
#include "game.h"
#include <stdio.h>

void initialize_board(Game *game) {
    for (int i = 0; i < BOARD_SIZE; ++i)
        for (int j = 0; j < BOARD_SIZE; ++j)
            game->board[i][j] = ' ';
}

int check_win(Game *game, char player) {
    /* 行、列、对角线判定 */
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if ((game->board[i][0] == player &&
             game->board[i][1] == player &&
             game->board[i][2] == player) ||
            (game->board[0][i] == player &&
             game->board[1][i] == player &&
             game->board[2][i] == player))
            return 1;
    }
    if ((game->board[0][0] == player &&
         game->board[1][1] == player &&
         game->board[2][2] == player) ||
        (game->board[0][2] == player &&
         game->board[1][1] == player &&
         game->board[2][0] == player))
        return 1;
    return 0;
}

int check_draw(Game *game) {
    for (int i = 0; i < BOARD_SIZE; ++i)
        for (int j = 0; j < BOARD_SIZE; ++j)
            if (game->board[i][j] == ' ')
                return 0;
    return 1;
}

void print_stats(Game *game) {
    /* 原代码里的打印统计，直接搬过来 */
}

/*4. 
实现 UI → src/ui.c
c*/
#include "game.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void print_board(Game *game) { /* 原实现 */ }

void clear_input_buffer(void) { /* 原实现 */ }

void get_player_input(int *row, int *col) { /* 原实现 */ }

void show_instructions(void) { /* 原实现 */ }

void play_game(Game *game) {
    /* 把原 play_game 函数搬过来，注意 #include "game.h" 就够了 */
}

int main_menu(void) { /* 原实现 */ }

/*5. 
主函数 → src/main.c
c*/
#include "game.h"
#include <stdio.h>

int main(void) {
    Game game = {0};
    printf("Welcome to Tic-Tac-Toe!\n");
    while (1) {
        int choice = main_menu();
        switch (choice) {
            case 1: play_game(&game);        break;
            case 2: show_instructions();     break;
            case 3: print_stats(&game);      break;
            case 4:
                puts("\nThank you for playing Tic-Tac-Toe!");
                return 0;
        }
        if (choice != 4) {
            puts("\nPress Enter to return to the main menu...");
            clear_input_buffer();
            getchar();
        }
    }
}
/*
────────────────────
四、编译脚本（Makefile）
在 tic_tac_toe/ 目录下：
makefile
CC      := gcc
CFLAGS  := -Wall -Wextra -std=c99 -Iinclude
SRC     := $(wildcard src/*.c)
OBJ     := $(patsubst src/%.c,build/%.o,$(SRC))
TARGET  := build/tictactoe

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ) | build
	$(CC) $^ -o $@

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build

clean:
	rm -rf build

说明：
 CFLAGS  里的  -Iinclude  让编译器能找到  "game.h" 。
目标文件统一放到 build/，保持源码目录干净。
只要敲  make  就会生成 build/tictactoe； make clean  可清掉。
────────────────────
五、最终目录树

tic_tac_toe/
├── include/
│   └── game.h
├── src/
│   ├── main.c
│   ├── game.c
│   └── ui.c
├── build/          （make 后自动生成）
│   ├── main.o
│   ├── game.o
│   ├── ui.o
│   └── tictactoe
└── Makefile

运行：

$ make
gcc -Wall -Wextra -std=c99 -Iinclude -c src/main.c -o build/main.o
gcc -Wall -Wextra -std=c99 -Iinclude -c src/game.c -o build/game.o
gcc -Wall -Wextra -std=c99 -Iinclude -c src/ui.c  -o build/ui.o
gcc build/main.o build/game.o build/ui.o -o build/tictactoe
$ ./build/tictactoe
Welcome to Tic-Tac-Toe!
...

这样你就拥有了一个结构清晰、可扩展、易维护的完整 C 语言工程。*/