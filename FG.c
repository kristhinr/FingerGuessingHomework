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
		{goto_xy(6,5);printf("ƽ��");equ++;}break;
		case -1:
		case 2:
		{goto_xy(6,5);printf("��ʤ");win++;}break;
		case -2:
		case 1:
		{goto_xy(6,5);printf("ʧ��");los++;}break;
	}
}

void goto_xy(int x, int y)//��λ���λ�õ�ָ������
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
		goto_xy(2,5);printf("û�б�����¼");
		goto_xy(2,8);printf(" ���������"); 
	}
	else
	{
		goto_xy(4,4);printf("ʤ����%d",win);
		goto_xy(4,5);printf("ƽ�֣�%d",equ);
		goto_xy(4,6);printf("ʧ�ܣ�%d",los);
		goto_xy(2,8);printf(" ���������"); 
	}
	getch();
	page(); 
}

game()
{
	char *str1[3] = {
						"ʯͷ",
						"����", 
						" �� "
					};
	
	fflush(stdin);
	system("cls");
	homepage();
	goto_xy(3,4);printf("0 ��ʾʯͷ");
	goto_xy(3,5);printf("1 ��ʾ����");
	goto_xy(3,6);printf("2 ��ʾ��");
	goto_xy(3,8);printf("  3 ����"); 
	int d;	
	int com;//����������� 
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
			goto_xy(2,5);printf("  �������"); 
		}
		goto_xy(2,8);printf(" ���������"); 
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
	goto_xy(2,5);printf("��¼ɾ�����");
	goto_xy(2,8);printf(" ���������");
	getch();
	page(); 
}

homepage()
{
	fflush(stdin);
	system("cls");
	puts("|==============|");
	puts("|����ʯͷ����Ϸ|");
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
	goto_xy(2,4);printf(" a.�������");
	goto_xy(2,5);printf(" b.�鿴��¼");
	goto_xy(2,6);printf(" c.ɾ����¼");
	goto_xy(2,7);printf(" d.�˳�����");
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
			{getchar();printf("��������");}
	}	
}

void main()
{
	SetConsoleTitle("��ȭ��Ϸ") ; 
	system("mode con cols=30 lines=20");
	page();	
}
