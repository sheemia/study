#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define BOARD_SIZE 3

typedef struct
{
    char board[BOARD_SIZE][BOARD_SIZE];
    int player_X_wins;
    int player_O_wins;
    int draws;
    int total_games;
}Game;

void clear_input_buffer()
{
    int c;
    while((c=getchar())!='\n'&&c!=EOF);
}

void initialize_board(Game *game)
{
    for(int i=0;i<BOARD_SIZE;i++)
    {
        for(int j=0;j<BOARD_SIZE;j++)
        {
            game->board[i][j]=' ';
        }
    }
}

void print_board(Game *game)
{
    printf("\n  ");
    for(int i=0;i<BOARD_SIZE;i++)
    {
        printf("   %d",i+1);
    }
    printf("\n   ");
    for(int j=0;j<BOARD_SIZE;j++)
    {
        printf("+---");
    }
    printf("+\n");
    for(int k=0;k<BOARD_SIZE;k++)
    {
        printf(" %c",'A'+k);
        for(int m=0;m<BOARD_SIZE;m++)
        {
            printf(" | %c",game->board[k][m]);
        }
        printf(" |\n");
        printf("   ");
        for(int n=0;n<BOARD_SIZE;n++)
        {
            printf("+---");
        }
    printf("+\n");
    }
}

void get_player_input(int *row,int *col)
{
    char input[10];
    char row_char,col_char;

    while(1)
    {
        if(fgets(input,sizeof(input),stdin)==NULL)
        {
            printf("Error reading input.\n");
            printf("Please try again:");
            continue;
        }

        input[strcspn(input,"\n")]=0;

        if(strlen(input)!=2)
        {
            printf("Invalid input.\n");
            printf("Please enter exactly two characters(e.g.A1):");
            continue;
        }

        row_char=toupper(input[0]);
        col_char=input[1];

        if(row_char<'A'||row_char>'C')
        {
            printf("Invalid row'%c'.\n",input[0]);
            printf("Please enter A,B or C:");
            continue;
        }

        if(col_char<'1'||col_char>'3')
        {
            printf("Invalid column'%d'\n",input[1]);
            printf("Please enter 1,2 or 3:");
            continue;
        }

        *row=row_char-'A';
        *col=col_char-'1';
        return;
    }
}

int check_win(const Game *game)
{
    for(int i=0;i<BOARD_SIZE;i++)
    {
        if(((game->board[i][0]==game->board[i][1]&&game->board[i][1]==game->board[i][2])||
           (game->board[0][i]==game->board[1][i]&&game->board[1][i]==game->board[2][i]))&&
           (game->board[i][0]!=' ')&&(game->board[0][i]!=' '))
           {
            return 1;
           }
    }

    if(((game->board[0][0]==game->board[1][1]&&game->board[1][1]==game->board[2][2])||
       (game->board[0][2]==game->board[1][1]&&game->board[1][1]==game->board[2][0]))&&
       (game->board[1][1]!=' '))
    {
        return 1;
    }

    return 0;
}

int check_draw(const Game *game)
{
    for(int i=0;i<BOARD_SIZE;i++)
    {
        for(int j=0;j<BOARD_SIZE;j++)
        {
            if(game->board[i][j]==' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

void instruction(Game *game)
{
    printf("\nTHE INSTRUCTION OF THE GAME\n");
    printf("---------------------------\n");
    printf("1.The game is played on a 3x3 grid.\n");
    printf("2.Players take turns marking the square.\n");
    printf("3.Player X goes first, then player O.\n");
    printf("4.Enter moves using the grid references\n");

    print_board(game);

    printf("For example:To play in the center, enter 'B2'\n");
    printf("The first player to get 3 in a row wins!\n");
}

void statistic(const Game *game)
{
    printf("\n   Game Statistic\n");
    printf("+---------------+---+\n");
    printf("|  Total Games  |%3d|\n",game->total_games);
    printf("+---------------+---+\n");
    printf("| Player X Wins |%3d|\n",game->player_X_wins);
    printf("| Player O Wins |%3d|\n",game->player_O_wins);
    printf("|     Draws     |%3d|\n",game->draws);
    printf("+---------------+---+\n");
}

void play_game(Game *game)
{
    char player='X';
    int game_over=0;
    int row,col;

    initialize_board(game);
    game->total_games++;

    printf("\nA new game started!\n");
    printf("player 'X' goes first\n\n");

    while(!game_over)
    {
        print_board(game);

        printf("Player %c ,enter your move(e.g.A1):",player);

        get_player_input(&row,&col);

        if(game->board[row][col]!=' ')
        {
            printf("Position %c%c is already taken.\n",'A'+row,'1'+col);
            printf("Please choose another.\n");
            continue;
        }

        game->board[row][col]=player;
        
        if(check_win(game))
        {
            print_board(game);
            printf("\n******************\n");
            printf("  Player %c wins! \n",player);
            printf("Congratulations!!!\n");
            printf("******************\n");

            if(player=='X')
            {
                game->player_X_wins++;
            }
            else
            {
                game->player_O_wins++;
            }

            game_over=1;
        }
        else if(check_draw(game))
        {
            print_board(game);
            printf("\n****************\n");
            printf(" It's a draw!!! \n");
            printf("****************\n");

            game->draws++;

            game_over=1;
        }
        else
        {
            player=(player=='X')?'O':'X';
        }
    }
    statistic(game);
}

int main_menu()
{
    int choice;
    printf("\nTIC-TAC-TOE GAME\n");
    printf("================\n");
    printf("1.Play Game\n");
    printf("2.View Instruction\n");
    printf("3.View Statistic\n");
    printf("4.Exit\n");
    printf("Please enter the number:");

    while(1)
    {
        if((scanf("%d",&choice))!=1)
        {
            clear_input_buffer();
            printf("Invalid input!\n");
            printf("Please enter the correct number:");
            continue;
        }

        if(choice>=1&&choice<=4)
        {
            clear_input_buffer();
            return choice;
        }
        else
        {
            clear_input_buffer();
            printf("Invalid input!\n");
            printf("Please enter the correct number(1~4):");
        }
    }
}

int main()
{
    Game game={0};
    initialize_board(&game);
    int choice;

    printf("Welcome to Tic-Tac-Toe!\n");

    while(1)
    {
        choice=main_menu();
        switch(choice)
        {
            case 1:
            play_game(&game);
            break;

            case 2:
            instruction(&game);
            break;

            case 3:
            statistic(&game);
            break;

            case 4:
            printf("Thank you for playing Tic-Tac-Toe!");
            return 0;
        }
        printf("\nPress Enter to return the main menu...");
        getchar();
    }
    return 0;
}