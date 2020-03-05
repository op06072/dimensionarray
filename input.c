#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

COORD golr(int lr)
{
    COORD Cur;
    CONSOLE_SCREEN_BUFFER_INFO a;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &a);
    Cur.X = a.dwCursorPosition.X;
    Cur.Y = a.dwCursorPosition.Y;
    COORD Pos = { Cur.X + lr, Cur.Y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
    return Pos;
}

char* input(void)
{
    int key, p = 0, P, tmp, l = 10;
    char* s;
    COORD Pos;
    s = (char*)calloc(l, sizeof(char));
    if (s == NULL)
    {
        printf("프로그램 수행을 위한 메모리 확보에 실패하여 프로그램을 종료합니다.");
        halt();
    }
    while (1)
    {
        if (p < l)
        {
            if ((key = _getch()) == 13)
            {
                s[strlen(s)] = 0;
                break;
            }
            else if (key == 28 || key == 0xE0 || key == 0 || key == 224)
            {
                switch (key = _getch())
                {
                case 75:
                    if (p > 0) { --p; golr(-1); }
                    break;
                case 77:
                    if (s[p] != 0) { ++p; golr(1); }
                    break;
                default:
                    break;
                }
            }
            else if (key == 8 && p > 0) //입력값이 백스페이스인가?
            {
                P = --p;
                Pos = golr(-1);
                do
                {
                    s[p] = s[p + 1];
                    if (s[p] != 0) printf("%c", (char)s[p]);
                    else printf(" ");
                } while (s[p++] != 0);
                p = P;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
            }
            else
            {
                P = p;
                Pos = golr(1);
                golr(-1);
                do
                {
                    tmp = key;
                    key = s[p];
                    s[p] = tmp;
                    printf("%c", (char)s[p]);
                } while (s[p++] != 0);
                p = P + 1;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
            }
        }
        else
        {
            s = (char*)realloc(s, sizeof(char) * (l += 100));
            s[p] = 0;
        }
    }
    s = (char*)realloc(s, sizeof(char) * (strlen(s) + 1));
    printf("\n");
    return s;
}