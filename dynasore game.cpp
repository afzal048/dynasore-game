//                 game is made by afzal ahmad //
//            this is a dynasor game(google chrome game while not connected to internet)  //
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

int speed=100,sc=0,k=0;
int display(char a[2][2000],int n);
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void gotoXY(int x, int y) 
{ 
CursorPosition.X = x; // Locates column
CursorPosition.Y = y; // Locates Row
SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}
int dis(char a[2][2000],int n)
{
gotoXY(25,9);
	for(int i=0;i<2;i++)
	{for(int j=0;j<n;j++)
		printf("%c",a[i][j]);
		gotoXY(25,10);
		//	_sleep(200);
	}
	gotoXY(46,1);
printf("                                 this is dynasor game");
	_sleep(100);
	//a[1][0]='_';
}
void rot(char a[2][2000],int b,int c)
{char temp;
gotoXY(46,1);
printf("                                 this is dynasor game");
	for(int i=0;i<b;i++)
	{//int j=0;
		temp=a[1][i];
		for(int j=0;j<c-1;j++)
		{
			a[1][j]=a[1][j+1];	
		}
		a[1][c-1]=temp;
	}
}
 void update(char a[2][2000],char key,int n)
{
	if(key=='p')
	{
		a[0][0]='$';
		a[1][0]='_';
		//gotoXY(25,9);
		dis( a, n);
		gotoXY(46,1);
printf("                                 this is dynasor game");
for(int i=0;i<4;i++)
{
	rot(a,1,n);
	dis(a,n);
	sc++;
	gotoXY(21,6);
	printf("SCORE: %d",sc);
	_sleep(100);
}
	//	_sleep(500);
		//rot(a,4,n);
		a[0][0]=' ';
		a[1][0]='_';
	}
}
 int display(char a[2][2000],int n)
{char temp;
	gotoXY(25,10);
	//printf("%c",'@');
	temp=a[1][0];
	a[1][0]='$';
	dis(a,n);
	a[1][0]=temp;
}
int main()
{o:
	
	if(sc>=k)
	{
		k=sc;
	}
	sc=0;
gotoXY(75,5);
//system("color a4");
	printf("1:press any key to start....");
	gotoXY(75,6);
	printf("2:press 'P' for jumping");
	getch();
	
int i,n=100;
char a[2][2000],key,replay;
//scanf("%d",&n);
for(i=0;i<2;i++)
	{
		for(int j=0;j<n;j++)
		{
		if(i==0)
		{
			a[i][j]=' ';
			continue;
		}
		if(j%37==0)
		{
			a[i][j]='#';
			continue;
		}
		if(j%13==0)
		{
			a[i][j]='|';
			continue;
		}
		a[i][j]='_';
	}
}
	while(1)
	{gotoXY(21,4);
	printf("HIGH SCORE=%d",k);
	sc++;
	if(sc>=k)
	{
		k=sc;
	}
	
	if(kbhit())
	{
		update(a,key=getch(),n);
	}
	
	rot(a,1,n);
	
	gotoXY(25,10);
	if(a[1][0]=='|'||a[1][0]=='O'||a[1][0]=='#')
	{
	system("cls");
	gotoXY(75,2);
	printf("      !!!GAME OVER!!!");
	gotoXY(75,5);
	k=sc;
	printf("       YOUR SCORE IS  %d",sc);
	gotoXY(75,8);
	printf("enter 'r' for replay otherwise press  another key");
	replay=getch();
	if(replay=='r')
	{system("cls");
		goto  o;
	}
	else{
		exit(0);
	}
			}
	display(a,n);
	system("cls");
	gotoXY(21,6);
	printf("SCORE: %d",sc);
	gotoXY(21,3);
	printf("VERSION :2.6");
}}
