// (VS2019)
#include <stdio.h>
#include <windows.h>
#include <conio.h>

//局部字体改变颜色
void color(short x)
{
    if (x >= 0 && x <= 15)//参数在0-15的范围颜色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//只有一个参数，改变字体颜色
    else//默认的颜色白色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

//改变光标位置
void gotoxy(int x, int y)
{
    // 更新光标位置
    COORD pos;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hOutput, pos);
}

//设置进度条
void setProgress(int x, int y, int lenth, short procolor, int progress, int max)
{
    int pro = (progress * lenth) / max;

    gotoxy(x, y);
    color(8);
    for (int i = 0; i < lenth; i++)  //打印进度条背景
    {
        printf("█");
    }

    gotoxy(x, y);
    color(procolor);
    for (int i = 0; i < pro; i++)  //打印进度条进度
    {
        printf("█");
    }

    color(16);
}

int main()
{
    setProgress(3, 3, 24, 6, 4, 10);
    gotoxy(4, 4);
	return 0;
}
