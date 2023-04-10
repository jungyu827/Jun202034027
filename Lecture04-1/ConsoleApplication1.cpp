#include <iostream>
#include <conio.h>
#include <Windows.h>
//과제 :1번 눌렀을때 가로 세로 정하기!! 2번 게임설명 넣기. 3번 밑에 텍스트 지우기
// game_state == 0 일때
int print_title_screen()
{
    std::cout << "******************************************" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*              지렁이 게임               *" << std::endl;
    std::cout << "*             (Snake Bite)               *" << std::endl;

#ifdef DEBUG
    std::cout << "*            - 디버그 모드 -             *" << std::endl;
#else
    std::cout << "*                                        *" << std::endl;
#endif  
    std::cout << "*   1. 게임 시작                         *" << std::endl;
    std::cout << "*   2. 게임 설명                         *" << std::endl;
    std::cout << "*   3. 게임 랭킹 보기                    *" << std::endl;
    std::cout << "*   4. 게임 종료 (esc)                   *" << std::endl;
    std::cout << "******************************************" << std::endl;

    return 0;
}

void gotoxy(int x, int y) {
    //x, y 좌표 설정
    COORD pos = { x,y };
    //커서 이동
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

int print_game_screen(int stage_width, int stage_height)
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        std::cout << "#";
    std::cout << std::endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                std::cout << "#";
            if (i == y && j == x)
                std::cout << "O";
            else if (i == fruitY && j == fruitX)
                std::cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        std::cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    std::cout << " ";
            }

            if (j == width - 1)
                std::cout << "#";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < width + 2; i++)
        std::cout << "#";
    std::cout << std::endl;
    std::cout << "Score:" << score << std::endl;



    return 0;
}


// game_state == 2 일때
int print_introduction_screen()
{
    std::cout << "******************************************" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*      지렁이가 움직이는 게임입니다.     *" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "******************************************" << std::endl;
    std::cout << "타이틀화면으로 돌아갈까요? (Y/N)" << std::endl;
    return 0;
}

int main()
{

    int game_state = 0;
    int is_game_running = 1;

    while (is_game_running)
    {
        char key_input = '0';

        switch (game_state)
        {
        case 0:
            print_title_screen();
            key_input = _getch();
            
        goto1: switch (key_input)
            {
            case '1':
                game_state = 1;
                break;

            case '2':
                game_state = 2;
                break;

            case '3':
                break;

            case '4':
                is_game_running = 0;
                break;

            case 27:
                is_game_running = 0;
                break;
            default:
                while (key_input != 49 && key_input != 50 && key_input != 51 && key_input != 52 && key_input != 27)
                {
                    key_input = _getch();
                }
                goto goto1;
            }
            break;

        case 1:
            print_game_screen(10, 10);
            key_input = _getch();

        case 2:
            system("cls");
            print_introduction_screen();
            key_input = _getch();

    goto2:  switch (key_input)
            {
            case 'y':
                game_state = 0;
                break;

            case 'n':
                break;

            default:
                while (key_input != 89 && key_input != 121 && key_input != 78 && key_input != 110)
                {
                    key_input = _getch();
                }
                goto goto2;
            }
            break;

        default:
            break;
        }


    }

    return 0;
}