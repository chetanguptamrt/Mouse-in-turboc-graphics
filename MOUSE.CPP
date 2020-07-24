#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<iostream.h>
void main()
{
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	rectangle(0,0,getmaxx(),getmaxy());
	union REGS in,out;
	in.x.ax=1;
	int86(0x33,&in,&out);
	while(!kbhit())
	{
		in.x.ax=3;
		int86(0x33,&in,&out);
		gotoxy(10,10);
		cout<<out.x.bx;
	}
	getch();
}