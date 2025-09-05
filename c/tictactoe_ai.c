#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BOARD_SIZE 3

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    int player1_wins;
    int player2_wins;
    int draws;
    int total_games;
} Game;

// 初始化游戏板
void initialize_board(Game *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game->board[i][j] = ' ';
        }
    }
}

// 打印游戏板
void print_board(const Game *game) {
    printf("\n");
    printf("    1   2   3\n");
    printf("  +---+---+---+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c |", 'A' + i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c |", game->board[i][j]);
        }
        printf("\n");
        printf("  +---+---+---+\n");
    }
    printf("\n");
}

// 检查是否获胜
int check_win(const Game *game, char player) {
    // 检查行和列
    for (int i = 0; i < BOARD_SIZE; i++) {
        if ((game->board[i][0] == player && game->board[i][1] == player && game->board[i][2] == player) ||
            (game->board[0][i] == player && game->board[1][i] == player && game->board[2][i] == player)) {
            return 1;
        }
    }
    
    // 检查对角线
    if ((game->board[0][0] == player && game->board[1][1] == player && game->board[2][2] == player) ||
        (game->board[0][2] == player && game->board[1][1] == player && game->board[2][0] == player)) {
        return 1;
    }
    
    return 0;
}

// 检查是否平局
int check_draw(const Game *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// 打印游戏统计
void print_stats(const Game *game) {
    printf("\nGame Statistics:\n");
    printf("+-----------------+-------+\n");
    printf("| Total Games     | %5d |\n", game->total_games);
    printf("+-----------------+-------+\n");
    printf("| Player X Wins   | %5d |\n", game->player1_wins);
    printf("| Player O Wins   | %5d |\n", game->player2_wins);
    printf("| Draws           | %5d |\n", game->draws);
    printf("+-----------------+-------+\n");
}

// 清除输入缓冲区
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 获取玩家输入
void get_player_input(int *row, int *col) { 
    char input[10];
    char row_char, col_char;
    
    while (1) {
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input. Please try again: ");
            continue;
        }
        
        // 去除换行符
        input[strcspn(input, "\n")] = 0;
        
        // 检查输入长度
        if (strlen(input) != 2) {
            printf("Invalid input. Please enter exactly two characters (e.g. A1): ");
            continue;
        }
        
        row_char = toupper(input[0]);
        col_char = input[1];
        
        // 验证行
        if (row_char < 'A' || row_char > 'C') {
            printf("Invalid row '%c'. Please enter A, B, or C: ", input[0]);
            continue;
        }
        
        // 验证列
        if (col_char < '1' || col_char > '3') {
            printf("Invalid column '%c'. Please enter 1, 2, or 3: ", input[1]);
            continue;
        }
        
        *row = row_char - 'A';
        *col = col_char - '1';
        return;
    }
}

// 主游戏循环
void play_game(Game *game) {
    char current_player = 'X';
    int game_over = 0;
    int row, col;
    
    initialize_board(game);
    game->total_games++;
    
    printf("\nNew Game Started!\n");
    printf("Player X goes first\n\n");
    
    while (!game_over) {
        print_board(game);
        
        // 获取玩家输入
        printf("Player %c, enter your move (e.g. A1): ", current_player);
        get_player_input(&row, &col);
        
        // 检查位置是否可用
        if (game->board[row][col] != ' ') {
            printf("Position %c%c is already taken. Please choose another.\n", 'A'+row, '1'+col);
            continue;
        }
        
        // 放置棋子
        game->board[row][col] = current_player;
        
        // 检查游戏是否结束
        if (check_win(game, current_player)) {
            print_board(game);
            printf("\n********************************\n");
            printf("  Player %c wins! Congratulations!\n", current_player);
            printf("********************************\n");
            
            if (current_player == 'X') {
                game->player1_wins++;
            } else {
                game->player2_wins++;
            }
            
            game_over = 1;
        } else if (check_draw(game)) {
            print_board(game);
            printf("\n****************\n");
            printf("  It's a draw!\n");
            printf("****************\n");
            game->draws++;
            game_over = 1;
        } else {
            // 切换玩家
            current_player = (current_player == 'X') ? 'O' : 'X';
        }
    }
    
    print_stats(game);
}

// 显示主菜单
int main_menu() {
    int choice;
    printf("\nTIC-TAC-TOE GAME\n");
    printf("================\n");
    printf("1. Play Game\n");
    printf("2. View Instructions\n");
    printf("3. View Statistics\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");

    while (1) {
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number: ");
            clear_input_buffer();
            continue;
        }
        
        if (choice >= 1 && choice <= 4) {
            clear_input_buffer();
            return choice;
        }
        
        printf("Invalid choice. Please enter 1-4: ");
        clear_input_buffer();
    }
}

// 显示游戏说明
void show_instructions() {
    printf("\nHOW TO PLAY TIC-TAC-TOE\n");
    printf("-----------------------\n");
    printf("1. The game is played on a 3x3 grid.\n");
    printf("2. Players take turns marking a square.\n");
    printf("3. Player X goes first, then Player O.\n");
    printf("4. Enter moves using the grid references:\n\n");
    
    printf("    1   2   3\n");
    printf("  +---+---+---+\n");
    printf("A |   |   |   |\n");
    printf("  +---+---+---+\n");
    printf("B |   |   |   |\n");
    printf("  +---+---+---+\n");
    printf("C |   |   |   |\n");
    printf("  +---+---+---+\n\n");
    
    printf("Example: To play in the center, enter 'B2'\n");
    printf("The first player to get 3 in a row wins!\n\n");
}

int main() {
    // 初始化游戏统计
    Game game = {0};
    int choice; 
    
    printf("Welcome to Tic-Tac-Toe!\n");
    
    while (1) {
        choice = main_menu();
        
        switch (choice) {
            case 1: // 开始游戏
                play_game(&game);
                break;
                
            case 2: // 显示游戏说明
                show_instructions();
                break;
                
            case 3: // 显示统计
                print_stats(&game);
                break;

            case 4: // 退出
                printf("\nThank you for playing Tic-Tac-Toe!\n");
                return 0;
        }
        
        printf("\nPress Enter to return to the main menu...");
        getchar(); // 等待用户按下回车
    }
    
    return 0;
}