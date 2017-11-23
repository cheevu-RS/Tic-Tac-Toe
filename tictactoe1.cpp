#include<iostream>
#include<windows.h>
#include<conio.h>
#include<process.h>
using namespace std;
int t=8,f=1;
int a[3][3];char c[3][3]={' ',' ',' ',' ',' ',' ',' ',' '};
void gotoxy(int x, int y) 
{ COORD CursorPosition;
CursorPosition.X = x; // Locates column
CursorPosition.Y = y; // Locates Row
SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) ,CursorPosition); // Sets position for next thing to be printed 
}
void square(int x,int y)
{ gotoxy(x,y);
	cout<<".....";gotoxy(x,y+1);
	cout<<".   .";gotoxy(x,y+2);
    cout<<".....";
}
int check(int t1,int t2)
{
	if (a[t1][t2]==1)
	{
	cout<<"Box already full";
return 0;}
	else
	a[t1][t2]=1;
	return 1;
}
void win()
{
if((c[0][0]=='X'&&c[0][1]=='X'&&c[0][2]=='X')||(c[1][0]=='X'&&c[1][1]=='X'&&c[1][2]=='X')||(c[2][0]=='X'&&c[2][1]=='X'&&c[2][2]=='X')
||(c[0][0]=='X'&&c[1][0]=='X'&&c[2][0]=='X')||(c[0][1]=='X'&&c[1][1]=='X'&&c[2][1]=='X')||(c[0][2]=='X'&&c[1][2]=='X'&&c[2][2]=='X')
||(c[0][0]=='X'&&c[1][1]=='X'&&c[2][2]=='X')||(c[2][0]=='X'&&c[1][1]=='X'&&c[0][2]=='X'))
{gotoxy(0,t+2);
f=0;
	cout<<"X Wins!";getch();exit(0);
}
else if((c[0][0]=='O'&&c[0][1]=='O'&&c[0][2]=='O')||(c[1][0]=='O'&&c[1][1]=='O'&&c[1][2]=='O')||(c[2][0]=='O'&&c[2][1]=='O'&&c[2][2]=='O')
||(c[0][0]=='O'&&c[1][0]=='O'&&c[2][0]=='O')||(c[0][1]=='O'&&c[1][1]=='O'&&c[2][1]=='O')||(c[0][2]=='O'&&c[1][2]=='O'&&c[2][2]=='O')
||(c[0][0]=='O'&&c[1][1]=='O'&&c[2][2]=='O')||(c[2][0]=='O'&&c[1][1]=='O'&&c[0][2]=='O'))
{
	gotoxy(0,t+2);f=0;
	cout<<"O Wins";getch();exit(0);
}

}
void play1ip()
{
	int t1,t2;
	gotoxy(0,t);t++;
	cout<<"Enter Row,Column X";
	cin>>t1>>t2;
	int x=check(t1,t2);
	if(x==0)
	play1ip();
	else
{	c[t1-1][t2-1]='X';
	switch(t2)
	{case 1:if(t1==1){gotoxy(2,2);}
			else if(t1==2){gotoxy(2,4);}
			else if(t1==3){gotoxy(2,6);}
			break;
	 case 2:if(t1==1){gotoxy(6,2);}
			else if(t1==2){gotoxy(6,4);}
			else if(t1==3){gotoxy(6,6);}
			break;
	 case 3:if(t1==1){gotoxy(10,2);}
			else if(t1==2){gotoxy(10,4);}
			else if(t1==3){gotoxy(10,6);}
			break;
}
cout<<"X";
}
}

void play2ip()
{
	int t1,t2;gotoxy(0,t);t++;
	cout<<"Enter Row,Column O";
	cin>>t1>>t2;
	int x=check(t1,t2);
	if(x==0)
	play2ip();
	else
{
c[t1-1][t2-1]='O';
switch(t2)
{case 1:if(t1==1){gotoxy(2,2);}
			else if(t1==2){gotoxy(2,4);}
			else if(t1==3){gotoxy(2,6);}
			break;
	 case 2:if(t1==1){gotoxy(6,2);}
			else if(t1==2){gotoxy(6,4);}
			else if(t1==3){gotoxy(6,6);}
			break;
	 case 3:if(t1==1){gotoxy(10,2);}
			else if(t1==2){gotoxy(10,4);}
			else if(t1==3){gotoxy(10,6);}
			break;
}
cout<<"O";
}
}

int main()
{
	cout<<"Wanna Play Tic Tac Toe??\n";

	square(0,1);
square(4,1);square(8,1);square(0,3);square(4,3);square(8,3);
square(0,5);square(4,5);square(8,5);
play1ip();
play2ip();
play1ip();
play2ip();
play1ip();win();
play2ip();win();
play1ip();win();
play2ip();win();
play1ip();win();
if(f==1)
{gotoxy(0,t+2);
	cout<<"Match Draw!";
}

	
return 0;
}
