#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>

// 游戏区域尺寸
#define WIDTH 60
#define HEIGHT 20

// 方向控制
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

// 蛇和食物结构体
typedef struct {
    int x;
    int y;
} Point;

// 全局变量
Point snake[100];  // 蛇身体数组
int length;        // 蛇的长度
int direction;     // 当前移动方向
Point food;        // 食物位置
bool gameOver;     // 游戏结束标志
int score;         // 游戏分数
HANDLE hConsole;   // 控制台句柄

// 设置光标位置
void setCursorPosition(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(hConsole, coord);
}

// 隐藏光标
void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

// 初始化游戏
void initGame() {
    // 获取控制台句柄
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    hideCursor();
    
    // 初始化蛇的位置（居中）
    length = 3;
    for (int i = 0; i < length; i++) {
        snake[i].x = WIDTH / 2 - i;
        snake[i].y = HEIGHT / 2;
    }
    
    // 初始方向向右
    direction = RIGHT;
    
    // 生成第一个食物
    srand(time(NULL));
    food.x = rand() % (WIDTH - 2) + 1;
    food.y = rand() % (HEIGHT - 2) + 1;
    
    // 重置游戏状态
    gameOver = false;
    score = 0;
    
    // 绘制初始边界
    setCursorPosition(0, 0);
    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    
    setCursorPosition(0, HEIGHT + 1);
    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    
    for (int i = 1; i <= HEIGHT; i++) {
        setCursorPosition(0, i);
        printf("#");
        setCursorPosition(WIDTH + 1, i);
        printf("#");
    }
    
    // 绘制分数信息
    setCursorPosition(WIDTH + 5, 2);
    printf("Score: %d", score);
    setCursorPosition(WIDTH + 5, 4);
    printf("Press 'X' to quit");
}

// 绘制游戏元素
void draw() {
    // 绘制蛇
    for (int i = 0; i < length; i++) {
        setCursorPosition(snake[i].x + 1, snake[i].y + 1);
        if (i == 0) printf("O");
        else printf("o");
    }
    
    // 绘制食物
    setCursorPosition(food.x + 1, food.y + 1);
    printf("*");
    
    // 更新分数
    setCursorPosition(WIDTH + 12, 2);
    printf("%d", score);
    
    // 清除蛇尾
    setCursorPosition(snake[length].x + 1, snake[length].y + 1);
    printf(" ");
}

// 处理输入
void input() {
    // 检查键盘输入
    if (_kbhit()) {
        switch (_getch()) {
            case 'w':
            case UP:
                if (direction != DOWN)
                    direction = UP;
                break;
            case 's':
            case DOWN:
                if (direction != UP)
                    direction = DOWN;
                break;
            case 'a':
            case LEFT:
                if (direction != RIGHT)
                    direction = LEFT;
                break;
            case 'd':
            case RIGHT:
                if (direction != LEFT)
                    direction = RIGHT;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

// 更新游戏逻辑
void update() {
    // 保存蛇尾位置（用于可能的增长）
    Point prevTail = snake[length - 1];
    
    // 移动蛇身（从尾部向前更新）
    for (int i = length - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }
    
    // 根据方向移动蛇头
    switch (direction) {
        case UP:
            snake[0].y--;
            break;
        case DOWN:
            snake[0].y++;
            break;
        case LEFT:
            snake[0].x--;
            break;
        case RIGHT:
            snake[0].x++;
            break;
    }
    
    // 检查是否吃到食物
    if (snake[0].x == food.x && snake[0].y == food.y) {
        // 增加蛇的长度
        length++;
        snake[length - 1] = prevTail;
        
        // 生成新食物
        bool validPosition;
        do {
            validPosition = true;
            food.x = rand() % (WIDTH - 2) + 1;
            food.y = rand() % (HEIGHT - 2) + 1;
            
            // 确保食物不在蛇身上
            for (int i = 0; i < length; i++) {
                if (food.x == snake[i].x && food.y == snake[i].y) {
                    validPosition = false;
                    break;
                }
            }
        } while (!validPosition);
        
        // 增加分数
        score += 10;
    }
    
    // 检查碰撞边界
    if (snake[0].x < 0 || snake[0].x >= WIDTH || 
        snake[0].y < 0 || snake[0].y >= HEIGHT) {
        gameOver = true;
    }
    
    // 检查碰撞自身
    for (int i = 1; i < length; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            gameOver = true;
            break;
        }
    }
}

// 主函数
int main() {
    initGame();
    
    while (!gameOver) {
        draw();
        input();
        update();
        
        // 控制游戏速度
        Sleep(100);
    }
    
    setCursorPosition(0, HEIGHT + 3);
    printf("Game Over! Final Score: %d\n", score);
    return 0;
}