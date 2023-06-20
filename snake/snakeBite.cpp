#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <ncurses.h>

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;

// 속도 조절을 위한 변수 추가
int initialDelayTime = 260000; // 초기 속도 (200ms)
int delayTime; // 현재 속도

void clear_screen()
{
    std::cout << "\033[2J\033[H";
}

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    delayTime = initialDelayTime;
}
void ShowGameOver(int score)
{
    clear_screen();
    std::cout << "Game Over! Your score: " << score << std::endl;
    std::cout << "Play again? (1. yes  2. no)" << std::endl;
    int choice;
    std::cout << "input> ";
    std::cin >> choice;

    if (choice == 1)
        gameOver = false;
    if (choice == 2)
        exit(0);
}

void Draw()
{
    clear();
    for (int i = 0; i < width + 2; i++)
        mvprintw(0, i, "#");
    mvprintw(0, width + 2, "\n");

    for (int i = 0; i < height; i++)
    {
        mvprintw(i + 1, 0, "#");
        for (int j = 0; j < width; j++)
        {
            if (i == y && j == x)
                mvprintw(i + 1, j + 1, "0");
            else if (i == fruitY && j == fruitX)
                mvprintw(i + 1, j + 1, "A");
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        mvprintw(i + 1, j + 1, "o");
                        print = true;
                        break;
                    }
                }
                if (!print)
                    mvprintw(i + 1, j + 1, " ");
            }
        }
        mvprintw(i + 1, width + 1, "#");
    }

    for (int i = 0; i < width + 2; i++)
        mvprintw(height + 1, i, "#");
    mvprintw(height + 1, width + 2, "\n");

    mvprintw(height + 3, 0, "Score: %d\n", score);
    mvprintw(height + 4, 0, "Current Speed: %d ms\n", delayTime / 1000);

    refresh(); // 화면 업데이트
}

void Input()
{
    int keyPressed = getch();

    switch (keyPressed)
    {
    case 'a':
        if (dir != RIGHT)
            dir = LEFT;
        break;
    case 'd':
        if (dir != LEFT)
            dir = RIGHT;
        break;
    case 'w':
        if (dir != DOWN)
            dir = UP;
        break;
    case 's':
        if (dir != UP)
            dir = DOWN;
        break;
    case 'x':
        gameOver = true;
        break;
    }
}

void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if (x >= width || x < 0 || y >= height || y < 0)
        gameOver = true;

    for (int i = 1; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            gameOver = true;
            break;
        }
    }

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
        delayTime -= 5000; // 5ms 단위로 속도 증가
    }
}



void print_title_screen()
{
    clear_screen();
    const int width = 30;
    const int height = 10;
    const std::string menuLines[6] = {
        "         Snake Bite        ",
        "           V.0.1           ",
        "                           ",
        "  1. Start Game            ",
        "  2. How to Play           ",
        "  3. Exit                  "
    };

    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            if (h == 0 || h == height - 1 || w == 0 || w == width - 1) {
                std::cout << "#";
            } else if (h >= (height - 6) / 2 && h < (height - 6) / 2 + 6 &&
                       w >= (width - menuLines[0].length()) / 2 && w < (width - menuLines[0].length()) / 2 + menuLines[0].length()) {
                std::cout << menuLines[h - (height - 6) / 2][w - (width - menuLines[0].length()) / 2];
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

void print_rule_screen()
{
    clear_screen();
    const int width = 38;
    const int height = 9;
    const std::string menuLines[3] = {
        "           How to Play             ",
        "                                   ",
        "  Press the W,S,D,A move to snake  "
    };

    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            if (h == 0 || h == height - 1 || w == 0 || w == width - 1) {
                std::cout << "#";
            } else if (h >= (height - 3) / 2 && h < (height - 3) / 2 + 3 &&
                       w >= (width - menuLines[0].length()) / 2 && w < (width - menuLines[0].length()) / 2 + menuLines[0].length()) {
                std::cout << menuLines[h - (height - 3) / 2][w - (width - menuLines[0].length()) / 2];
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}
void ResetGame()
{
    Setup();
    nTail = 0;
    for (int i = 0; i < 100; i++) {
        tailX[i] = 0;
        tailY[i] = 0;
    }
}

int main()
{
    int game_state = 0;
    int in_screen = 0;

    while (true) {
        if (game_state != 0) {
            clear_screen();
            in_screen = 0;
        }

        print_title_screen();
        std::cout << "input> ";
        std::cin >> game_state;

        if (game_state == 1) {
            while (game_state) {
                if (!in_screen) {
                    srand(time(0));
                    ResetGame();
                    
                    initscr(); // ncurses 초기화
                    cbreak();
                    noecho();
                    nodelay(stdscr, TRUE);
                    keypad(stdscr, TRUE);

                    while (!gameOver)
                    {
                        Draw();
                        Input();
                        Logic();
                        usleep(delayTime); // 사용자가 조절한 속도로 지연
                    }

                    endwin(); // ncurses 정리
                    ShowGameOver(score);
                    game_state = 0;  // Reset game_state to show menu screen
                    break;  // Exit the inner loop and show menu screen
                }
            }
        }  if (game_state == 2) {
            while (game_state) {
                if (!in_screen) {
                    print_rule_screen();
                    in_screen = 1;
                }
                std::cout << "Return to menu? (1. yes  2. no)" << std::endl;
                std::cout << "input> ";
                std::cin >> game_state;
                if (game_state == 1) {
                    break;
                }
            }
        }  if (game_state == 3) {
            clear_screen();
            break;
        }
    }

    return 0;
}