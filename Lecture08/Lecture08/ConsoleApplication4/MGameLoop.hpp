#pragma once
#include <windows.h>
#include <conio.h>

#define KEY_ESC 27
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'
#define KEY_ENTER 13

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"


namespace MuSoeun
{

	void gotoxy(int x, int y)
	{
		COORD pos = { x,y };

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	void SetCursorState(bool visible)
	{
		CONSOLE_CURSOR_INFO consoleCursorInfo;
		consoleCursorInfo.bVisible = visible;
		consoleCursorInfo.dwSize = 1;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorInfo);
	}
	class MGameLoop
	{
	public :
		MGameLoop() {}
		~MGameLoop() {}

		bool isGameRunning = false;

		void Initialize()
		{
			SetCursorState(false);
			gotoxy(3, 15);
			std::cout << ANSI_COLOR_RESET "게임 초기화중" << std::endl;
			isGameRunning = true;
		}
		void Release()
		{
			gotoxy(3, 18);
			std::cout << ANSI_COLOR_RESET "게임 종료중" << std::endl;
			isGameRunning = false;
		}
		void Update()
		{
			std::cout << ANSI_COLOR_RESET "게임 키입력 대기" << std::endl;
			if (_kbhit())
			{
				KeyEvent(_getch());

					
			}
		}
		void Render()
		{
			std::cout << "게임 화면 그리기" << std::endl;
			
		}

		void Run()
		{
			gotoxy(2, 10);
			Initialize();
			while (isGameRunning)
			{
				gotoxy(2, 10);
				Update();
				gotoxy(2, 11);
				Render();
			}
			Release();
		}

		void KeyEvent(char keyInput)
		{
			switch (keyInput)
			{
				/*한번 ESC누르면 일시정지
				*여기서 나가기를 선택하면 나가짐
				*/
			case KEY_ESC:
				isGameRunning = false;
				break;
			case KEY_LEFT:
				gotoxy(5, 5);
				std::cout << ANSI_COLOR_RED "왼쪽 눌림  " << std::endl;
				break;
			case KEY_RIGHT:
				gotoxy(5, 5);
				std::cout << ANSI_COLOR_BLUE"오른쪽 눌림" << std::endl;
				break;
			case KEY_ENTER:
				gotoxy(5, 5);
				std::cout << ANSI_COLOR_YELLOW "엔터 눌림  " << std::endl;
				break;

			default:
				isGameRunning = true;
				break;
			}
		}
	};
	
}
