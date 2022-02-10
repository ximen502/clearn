#include "graphics.h"
#include "conio.h"
void smile(int x,int y,int r)
{
     int c1=YELLOW,c2=BLACK,c3=WHITE;
     int d=r/5;
     setcolor(c1);
     circle(x,y,r);
     setfillstyle(1,c1);
     floodfill(x,y,c1);
     setcolor(c2);
     line(x-d,y-d*3,x-2*d,y-4*d);
     line(x-2*d,y-4*d,x-2.9*d,y-4*d);
     line(x+d,y-d*3,x+2*d,y-4*d);
     line(x+2*d,y-4*d,x+2.9*d,y-4*d);
/*________________________________*/

     line(x-3.5*d,y-2*d,x-2.5*d,y-2.6*d);
     line(x-2.5*d,y-2.6*d,x-1.5*d,y-2*d);
     line(x+3.5*d,y-2*d,x+2.5*d,y-2.6*d);
     line(x+2.5*d,y-2.6*d,x+1.5*d,y-2*d);
/*________________________________*/

     pieslice(x,y,180,360,4*d);
     setfillstyle(1,c3);
     floodfill(x,y+d,c2);
/*_________________________________*/

     line(x-2*d,y,x-2*d,y+3.5*d);
     line(x+2*d,y,x+2*d,y+3.5*d);
     line(x,y,x,y+4*d);
     line(x+3.5*d,y,x+3.5*d,y+1.8*d);
}
main()
{
    int gd=DETECT,gm;
    int i,x,d,y,r,flag=0;
	registerbgidriver(EGAVGA_driver);
	initgraph(&gd,&gm,"D:\tc\tc");
    x=300;y=200;
	d=6;i= 0;
    r=10;
    while(!kbhit())
    {
        smile(x,y+i,r);
        delay(10000);
        setfillstyle(1,0);
	pieslice(x,y+i,0,360,r);
	if(i==d)
	    flag=1;
	if(i==0)
	    flag=0;
	if(flag==0)
	    i++;
	else
	    i--;
    }
}