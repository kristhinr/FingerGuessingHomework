#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>

int win=0;
int los=0;
int equ=0;

void homepage();
void page();
void read_record();
void del_record();
void game();

void judge(int x, int y)
{
	int j = x - y;
	switch(j)
	{
		case 0:
		{goto_xy(6,5);printf("平局");equ++;}break;
		case -1:
		case 2:
		{goto_xy(6,5);printf("获胜");win++;}break;
		case -2:
		case 1:
		{goto_xy(6,5);printf("失败");los++;}break;
	}
}

void goto_xy(int x, int y)//定位光标位置到指定坐标
{
	HANDLE hOut;  
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
	COORD pos = { x,y };   
	SetConsoleCursorPosition(hOut, pos);
}

read_record()
{
	fflush(stdin);
	system("cls");
	homepage();
	if((win + los + equ) == 0)
	{
		goto_xy(2,5);printf("没有比赛记录");
		goto_xy(2,8);printf(" 任意键返回"); 
	}
	else
	{
		goto_xy(4,4);printf("胜利：%d",win);
		goto_xy(4,5);printf("平局：%d",equ);
		goto_xy(4,6);printf("失败：%d",los);
		goto_xy(2,8);printf(" 任意键返回"); 
	}
	getch();
	page(); 
}

game()
{
	char *str1[3] = {
						"石头",
						"剪刀", 
						" 布 "
					};
	
	fflush(stdin);
	system("cls");
	homepage();
	goto_xy(3,4);printf("0 表示石头");
	goto_xy(3,5);printf("1 表示剪刀");
	goto_xy(3,6);printf("2 表示布");
	goto_xy(3,8);printf("  3 返回"); 
	int d;	
	int com;//电脑随机出手 
	srand(time(NULL));
	while(1)
	{
		com=(rand()%31 )/10;
		if(com != 3)
			break;
	}	
	fflush(stdin);
	goto_xy(4,10);
	printf(">>> ");
	scanf("%d",&d);
	system("cls");
	homepage();
	if(d!=3) 
	{
		if(d>=0 && d<=2)
		{
			goto_xy(6,4);printf("%s",str1[d]);
			goto_xy(6,6);printf("%s",str1[com]);
			judge(d, com);
		}
		else
		{
			goto_xy(2,5);printf("  输入错误"); 
		}
		goto_xy(2,8);printf(" 任意键返回"); 
		getch();
		game(); 
	}
	else
		page();
}

del_record()
{
	fflush(stdin);
	win = 0;
	los = 0;
	equ = 0;
	system("cls");
	homepage();
	goto_xy(2,5);printf("记录删除完成");
	goto_xy(2,8);printf(" 任意键返回");
	getch();
	page(); 
}

homepage()
{
	fflush(stdin);
	system("cls");
	puts("|==============|");
	puts("|剪刀石头布游戏|");
	puts("|              |");
	puts("|              |");
	puts("|              |");
	puts("|              |");
	puts("|              |");
	puts("|              |");
	puts("|              |");
	puts("|==============|");		
}

page()
{	
	fflush(stdin);
	char c;
	homepage();
	goto_xy(2,4);printf(" a.进入比赛");
	goto_xy(2,5);printf(" b.查看记录");
	goto_xy(2,6);printf(" c.删除记录");
	goto_xy(2,7);printf(" d.退出比赛");
	while(1)
	{
		goto_xy(4,10);
		printf(">>> ");
		fflush(stdin);
		scanf("%c",&c);
		if(c=='a' || c  =='A')
			{getchar();game();break;} 
		else if(c=='b' || c =='B')
			{getchar();read_record();break;} 
		else if(c=='c' || c =='C')
			{getchar();del_record();break;} 
		else if(c=='d' || c =='D')
			exit(0);
		else 
			{getchar();printf("重新输入");}
	}	
}

void main()
{
	SetConsoleTitle("猜拳游戏") ; 
	system("mode con cols=30 lines=20");
	page();	
}
