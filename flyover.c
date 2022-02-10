#include"graphics.h"
#include"conio.h"
#include"stdlib.h"
#include"time.h"
#include"dos.h"
/*the whole flychar game programe*/
/*the over.c is the copy of the flyover.c*/
#define BK_COLOR BLACK
#define CHAR_COLOR GREEN
#define C_COLOR BLUE
#define Esc 27
#define Enter 13
#define Upkey 72
#define Downkey 80
#define MenuX 200
#define MenuY 110
#define MenuWidth 200
#define MenuSinH 40
#define ChoiceX MenuX+15
#define ChoiceY MenuY+10
#define ChoiceWidth 170
#define ChoiceH 25
#define ViewLeft 20
#define ViewTop 20
#define ViewRight 520
#define ViewBottom 460
#define DataViewX ViewRight
#define DataViewY ViewTop+40
#define DataH 40

int nCount =10;
int speed=6000;
struct PlayData
{
    int time;
    int Hit;
    int Lose;
    double ratio;/*float ok too!*/
}result;

void Interface()
{
    int i,j;
    setcolor(CYAN);
    for(i=0;i<60;i++)
    {
        line(i,0,i,500);
	   line((getmaxx()-i),0,(getmaxx()-i),500);
    }
    setcolor(YELLOW);
    for(i=60,j=0;i<85;i++,j++)
    {
        line(i,j,i,500);
	   line((getmaxx()-i),j,(getmaxx()-i),500);
    }
    setcolor(WHITE);
    rectangle(MenuX,MenuY,MenuX+MenuWidth,MenuY+3*MenuSinH);
    line(MenuX,MenuY+MenuSinH,MenuX+MenuWidth,MenuY+MenuSinH);
    line(MenuX,MenuY+2*MenuSinH,MenuX+MenuWidth,MenuY+2*MenuSinH);
}
void Main_Menu()
{
    settextstyle(0,0,2);
    outtextxy(MenuX+20,MenuY+15,"START GAME");
    outtextxy(MenuX+20,MenuY+MenuSinH+15,"GAME SETUP");
    outtextxy(MenuX+20,MenuY+2*MenuSinH+15,"EXIT");
}
void Option_Menu()
{
    settextstyle(0,0,2);
    outtextxy(MenuX+20,MenuY+15,"beginner");
    outtextxy(MenuX+20,MenuY+MenuSinH+15,"advancer");
    outtextxy(MenuX+20,MenuY+2*MenuSinH+15,"senior");
}
void Choice(int c_x,int c_y,int color)
{
    setfillstyle(1,color);
    bar(c_x,c_y,c_x+ChoiceWidth,c_y+ChoiceH);
}
int ChooseMenu(int flag)
{
    int x,y;
    char C_Key;
    x=ChoiceX;
    y=ChoiceY;
    do
    {
        kbhit();
	   C_Key=getch();
	   if(C_Key==Esc)
	   {
	       sound(5000);/*exit game sound!*/
		  delay(6000);
		  nosound();
		  return Esc;
	   }
	   else
	   if(C_Key==Enter)
	   {
	       sound(300);
		  delay(6000);
		  nosound();
		  return y;
	   }
	   else
	   switch(C_Key)
	   {
	   case Upkey:
	          sound(1000);
			delay(10000);
			nosound();
			if(y==ChoiceY)
			    break;
			 else
			 {
			     Choice(x,y,BK_COLOR);
				y-=MenuSinH;
				Choice(x,y,C_COLOR);
			 }
			 break;
	   case Downkey:
	          sound(1000);
			delay(10000);
			nosound();
			if(y==(ChoiceY+2*MenuSinH))
			    break;
			 else
			 {
			     Choice(x,y,BK_COLOR);
				y+=MenuSinH;
				Choice(x,y,C_COLOR);
			 }
			 break;
	   default:break;
	   }
	   if(flag==0)
	       Main_Menu();
	   else
	   if(flag==1)
	       Option_Menu();
    }while(C_Key!=Esc);
}
void Setup()/*set the difficulty!*/
{
    int result;
    result=ChooseMenu(1);
    switch(result)
    {
    case Esc:
		   break;
    case ChoiceY:
           speed=6000;
		 nCount=30;
		 break;
	case ChoiceY+MenuSinH:
           speed=3000;
		 nCount=60;
		 break;
	case ChoiceY+2*MenuSinH:
           speed=1000;
		 nCount=100;
		 break;
    default:break;
    }
}
void Loading()
{
    /*int i;*/
    int j,l;
    Interface();
    setfillstyle(1,0);
    bar(200,110,400,230);
    settextstyle(0,0,1);
    outtextxy(250,207,"Loading");
    for(l=0;l<6;l++)
    {
        setcolor(15);
	   rectangle(237+l*15,225,244+l*15,235);
    }
    l=0;
    j=1;
    while(j!=480-j)
    {
        j++;
	   if(j%40==0)
	   {
	       setfillstyle(1,RED);
		  bar(237+l*15,225,244+l*15,235);
		  l++;
	   }
	   setfillstyle(1,0);
	   bar(0,0,getmaxx(),j);
	   bar(0,480,getmaxx(),480-j);
	   delay(1000);
    }
    delay(60000);
    clearviewport();
}
void DrawChar(int i,int j,char c)
{
    char ch[2];
    ch[0]=c;
    ch[1]='\0';
    moveto(i-7,j-7);
    settextstyle(0,0,2);
    outtext(ch);
}
void AutoDraw_Down(int x,int y,char c,int n)
{
    setcolor(BK_COLOR);
    DrawChar(x,y,c);
    setcolor(CHAR_COLOR);
    DrawChar(x,y+1,c);
    delay(n);
}
void AutoDraw_Up(int x,int y,char c,int n)
{
    setcolor(BK_COLOR);
    DrawChar(x,y,c);
    setcolor(CHAR_COLOR);
    DrawChar(x,y-1,c);
    delay(n);
}
char GenerateChar()
{
    int flag;
    char c;
    flag=random(3);
    switch(flag)
    {
    case 0:c='a'+random(26);break;
    case 1:c='A'+random(26);break;
    case 2:c='0'+random(10);break;
    default:break;
    }
    return c;
}
void PlayViewPort()/*game background!frame*/
{
    int i;
    cleardevice();
    setcolor(CYAN);
    for(i=0;i<3;i++)
        rectangle(ViewLeft-10-i,ViewTop-10-i,ViewRight+110+i,ViewBottom+10+i);
	rectangle(ViewLeft,ViewTop,ViewRight+100,ViewBottom);
	setfillstyle(XHATCH_FILL,YELLOW);
	floodfill(ViewLeft-1,ViewTop-1,CYAN);
	setcolor(WHITE);
	for(i=0;i<3;i++)
	    rectangle(ViewLeft-i,ViewTop-i,ViewRight+100+i,ViewBottom+i);
	line(ViewRight,ViewTop,ViewRight,ViewBottom);
	settextstyle(0,0,0);
	rectangle(DataViewX,DataViewY,DataViewX+100,DataViewY+DataH);
	rectangle(DataViewX,DataViewY+DataH,DataViewX+100,DataViewY+2*DataH);
	rectangle(DataViewX,DataViewY+2*DataH,DataViewX+100,DataViewY+3*DataH);
	outtextxy(DataViewX+10,DataViewY+10,"Hit:");
	outtextxy(DataViewX+10,DataViewY+DataH+10,"Lose:");
	outtextxy(DataViewX+10,DataViewY+2*DataH+10,"PreKey:");
}
void DrawLaugh(int x,int y,int r)
{
     int c1=YELLOW,c2=BLACK,c3=WHITE;
     int d=r/5;/*single unit*/
     setcolor(c1);
     circle(x,y,r);
     setfillstyle(1,c1);
     floodfill(x,y,c1);
     setcolor(c2);
/*-----------Ã¼Ã«brow-----------------*/
     line(x-d,y-d*3,x-2*d,y-4*d);
     line(x-2*d,y-4*d,x-2.9*d,y-4*d);
     line(x+d,y-d*3,x+2*d,y-4*d);
     line(x+2*d,y-4*d,x+2.9*d,y-4*d);
/*---------------ÑÛ¾¦eye---------------*/

     line(x-3.5*d,y-2*d,x-2.5*d,y-2.6*d);
     line(x-2.5*d,y-2.6*d,x-1.5*d,y-2*d);
     line(x+3.5*d,y-2*d,x+2.5*d,y-2.6*d);
     line(x+2.5*d,y-2.6*d,x+1.5*d,y-2*d);
/*-------------*/

     pieslice(x,y,180,360,4*d);
     setfillstyle(1,c3);
     floodfill(x,y+d,c2);
/*____________×ìmouth_____________________*/

     line(x-2*d,y,x-2*d,y+3.5*d);
     line(x+2*d,y,x+2*d,y+3.5*d);
     line(x,y,x,y+4*d);
     line(x+3.5*d,y,x+3.5*d,y+1.8*d);
}
void Laugh(int x,int y)
{
    int i,d,r,flag=0;
    d=6;i=0;
    r=10;
    while(!kbhit())
    {
        DrawLaugh(x,y+i,r);
	   delay(10000);
	   setfillstyle(1,BK_COLOR);
	   setcolor(BK_COLOR);
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
}
void Smile(int x,int y)
{
    int r=10,c1=YELLOW,c2=BLACK;
    int d=r/5;/*miss i*/
    setcolor(c1);
    circle(x,y,r);
    setfillstyle(1,c1);
    floodfill(x,y,c1);
    setcolor(c2);
    setfillstyle(1,c2);
    sector(x-2.5*d,y-2.5*d,0,360,1,1);
    sector(x+2.5*d,y-2.5*d,0,360,1,1);
    setcolor(c2);
    arc(x,y,200,350,3.5*d);
}
void Weep(int x,int y)/*?*/
{
    int r=10,c1=YELLOW,c2=BLACK;
    int d=r/5,i=0;
    while(!kbhit())
    {
        setcolor(c1);
	   circle(x,y,r);
	   setfillstyle(1,c1);
	   floodfill(x,y,c1);
	   setcolor(c2);
	   line(x-2.5*d-1,y-2.5*d,x-2.5*d-1,y-2.5*d+i);
	   line(x-2.5*d,y-2.5*d,x-2.5*d,y-2.5*d+i);
	   line(x-2.5*d+1,y-2.5*d,x-2.5*d+1,y-2.5*d+i);
	   line(x+2.5*d-1,y-2.5*d,x+2.5*d-1,y-2.5*d+i);
	   line(x+2.5*d,y-2.5*d,x+2.5*d,y-2.5*d+i);
	   line(x+2.5*d+1,y-2.5*d,x+2.5*d+1,y-2.5*d+i);
	   arc(x,y+5*d,30,150,4*d);
	   delay(10000);
	   i++;
	   if(i==(3*d))
	   {
	       i=0;
		  setfillstyle(1,c2);
		  pieslice(x,y,0,360,r);
	   }
    }
}
void ShowFace(int flag)
{
    int x,y;
    x=DataViewX+50;
    y=DataViewY-20;
    switch(flag)
    {
    case 1:Laugh(x,y);break;
    case 2:Smile(x,y);break;
    case 3:Weep(x,y);break;
    default:break;
    }
}
void ShowData(int nHit,int nLose,int nPre)
{
    char *str;
    setfillstyle(1,BK_COLOR);
    bar(DataViewX+1,DataViewY+30,DataViewX+99,DataViewY+DataH-1);
    bar(DataViewX+1,DataViewY+DataH+30,DataViewX+99,DataViewY+2*DataH-1);
    bar(DataViewX+1,DataViewY+2*DataH+30,DataViewX+99,DataViewY+3*DataH-1);
    settextstyle(0,0,0);
    setcolor(CHAR_COLOR);
    sprintf(str,"%d",nHit);
    outtextxy(DataViewX+10,DataViewY+30,str);
    sprintf(str,"%d",nLose);
    outtextxy(DataViewX+10,DataViewY+DataH+30,str);
    sprintf(str,"%d",nPre);
    outtextxy(DataViewX+10,DataViewY+2*DataH+30,str);
}
void ShowResult(int t,int Hit,int Lose,float ratio)
{
    int x,y,temp,Char_Count;
    char *str;
    int flag;
    Char_Count=Hit+Lose;
    x=ViewLeft+150;
    y=ViewTop+100;
    setcolor(WHITE);
    rectangle(x,y,x+200,y+120);
    line(x,y+30,x+200,y+30);
    line(x,y+60,x+200,y+60);
    line(x,y+90,x+200,y+90);
    settextstyle(0,0,0);
    setcolor(YELLOW);
    sprintf(str,"Total Time:%d s",t);
    outtextxy(x+20,y+10,str);
    sprintf(str,"Hit: %d",Hit);
    outtextxy(x+20,y+40,str);
    sprintf(str,"Lose:%d",Lose);
    outtextxy(x+20,y+70,str);
    temp=ratio*100;
    sprintf(str,"Hit Ratio:%d\%",temp);
    outtextxy(x+20,y+100,str);
    settextstyle(1,0,2);
    setcolor(WHITE);
    if(temp==100&&Char_Count==nCount)
    {
        flag=1;
        outtextxy(x-5,y+150,"Pretty Good!You got a Gift!");
    }
    else if(temp>=89)
    {
        flag=1;
	   outtextxy(x+50,y+150,"Well Done!");
    }
    else if(temp>=80)
    {
        flag=2;
	   outtextxy(x+70,y+150,"Good!");
    }
    else if(temp>=60)
    {
        flag=2;
	   outtextxy(x+50,y+150,"Not Bad!");
    }
    else
    {
        flag=3;
	   outtextxy(x-5,y+150,"Sorry!You did a bad work!");
    }
    ShowFace(flag);
}
void Play()
{
    int x,y,x1,y1,i,Char_Count=0;
    int e=20,PreKey_Count=0,Hit_Count=0;
    float f;
    char c,key,*str;
    int Start_T,End_T;
    setbkcolor(BK_COLOR);
    PlayViewPort();
    ShowData(Hit_Count,(Char_Count-Hit_Count),PreKey_Count);
    Start_T=time(NULL);
    while(key!=Esc&&Char_Count<nCount)
    {
        randomize();
	   x=ViewLeft+40+random(ViewRight-ViewLeft-60)-10;
	   c=GenerateChar();
	   Char_Count++;
	   for(y=ViewTop+31;y<ViewBottom-30;y++)
	   {
	       AutoDraw_Down(x,y,c,speed);
		  if(kbhit())
		  {
		      key=getch();
			 if(key==Esc)
			 {
			     sound(600);
				delay(10000);
				nosound();
				Char_Count--;
				break;
			 }
			 else
			 {
			     if(key==c)
				{
				    sound(100);
				    delay(10000);
				    nosound();
				    x1=x;
				    for(y1=ViewBottom-10;y1>=y;y1--)
				        AutoDraw_Up(x1,y1,key,100);
				    Hit_Count++;
				    setcolor(RED);
				    for(i=10;i<=30;i++)
				    {
				        circle(x1,y1,i);
					   delay(1000);
				    }
				}
				else
				{
				    sound(3000);
				    delay(10000);
				    nosound();
				    x1=x+e;
					for(y1=ViewBottom-10;y1>=ViewTop+15;y1--)
				        AutoDraw_Up(x1,y1,key,100);
				}
				PreKey_Count++;
			 }
			 break;
		  }
	   }
	   ShowData(Hit_Count,(Char_Count-Hit_Count),PreKey_Count);
	   setfillstyle(1,0);
	   bar(ViewLeft+1,ViewTop+1,ViewRight-1,ViewBottom-1);
    }
    End_T=time(NULL);
    result.time=Start_T-End_T;
    result.Hit=Hit_Count;
    result.Lose=Char_Count-Hit_Count;
    if(Char_Count==0)
        result.ratio=0.0;
    else
        result.ratio=Hit_Count/(float)Char_Count;
	ShowResult(Char_Count,result.Hit,result.Lose,result.ratio);
	getch();
	sound(3000);
	delay(10000);
	nosound();
}
main()
{
    int gd=DETECT,gm;
    int c_x,c_y,result;
    char C_Key;
    c_x=ChoiceX;
    c_y=ChoiceY;
    registerbgidriver(EGAVGA_driver);/*important*/
    initgraph(&gd,&gm,"C:\tc\BGI");
    Begin:
    /*use goto statement here is the sign*/
    cleardevice();
    Interface();
    Choice(c_x,c_y,C_COLOR);
    Main_Menu();
    result=ChooseMenu(0);
    switch(result)
    {
    case Esc:
           closegraph();
		 exit(0);
		 break;
    case ChoiceY:
           cleardevice();
		 Loading();
		 Play();
           goto Begin;/*don't handle now!*/
		 break;
    case ChoiceY+MenuSinH:
           cleardevice();
		 Interface();
		 Choice(c_x,c_y,C_COLOR);
		 Option_Menu();
		 Setup();
		 goto Begin;
		 break;
    case ChoiceY+2*MenuSinH:
           closegraph();
		 exit(0);
		 break;
    default:break;
    }
    /*Option_Menu()*/
    getch();
}