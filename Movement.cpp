#include <graphics.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
using namespace std;
class Goal{
	public:
	int xval1,yval1,xval2,yval2,xval3,yval3,xval4,yval4;
	void setup(int a,int b,int c,int d,int e,int f,int g,int h){
		xval1=a;
		yval1=b;
		xval2=c;
		yval2=d;
		xval3=e;
		yval3=f;
		xval4=g;
		yval4=h;
	}
	void goaldraw(){
		line(xval1,yval1,xval2,yval2);
		line(xval2,yval2,xval3,yval3);
		line(xval3,yval3,xval4,yval4);
	}
//	void wcondition(){}
};
class Line{
	public:
	int x1,y1,x2,y2,yvel;
	char ch;
	void setl(int a,int b,int c, int d){
		x1=a;
		y1=b;
		x2=c;
		y2=d;
	}
	void ldraw(){
		line(x1,y1,x2,y2);
	}
};
class Circle:public Line,public Goal{
	public:
	char ch;
	int xval,yval,radii,p1x,p1y1,p1y2,p2x,p2y1,p2y2,xvel,yvel,doax,doay,lyvel;
	void setval(int a, int b, int c){
	xval=a;
	yval=b;
	xvel=5;
	doax=0;
	yvel=5;
	doay=0;
	radii=c;
	p1x=100;
	p1y1=150;
	p1y2=300;
	p2x=500;
	p2y1=150;
	p2y2=300;
	lyvel=10;
	}
	void draw(){
	circle(xval,yval,radii);
	}

	void move(){
		while(1){
			cleardevice();
			Line l1,l2;
			//Drawing the bricks
			l1.setl(p1x,p1y1,p1x,p1y2);
			l2.setl(p2x,p2y1,p2x,p2y2);
			//Getting player inputs
			if(kbhit()){
			ch=getch();
			//Player 1 controls
			if(int(ch)==119){
				if(p1y2>0){
					p1y1-=15;
					p1y2-=15;
				}
			}
			else if(int(ch)==115){
				if(p1y1<600){
				p1y1+=15;
				p1y2+=15;}
			}
			}
			
			Goal G1,G2;
			//Drawing the Goals
			setcolor(LIGHTBLUE);
			G1.setup(50,100,25,100,25,500,50,500);
			G2.setup(550,100,575,100,575,500,550,500);
			G1.goaldraw();
			G2.goaldraw();
			//Moving the ball
			xval+=xvel;
			doax=xvel;
			yval+=yvel;
			doay=yvel;
			//Moving the second brick
			p2y1+=lyvel;
			p2y2+=lyvel;
			//Win Screens
			if((xval>25&&xval<50)&&(yval>100&&yval<500)){
				settextstyle(4,0,5);
				cleardevice();
				setcolor(MAGENTA);
				outtextxy(100,300,"Side 2 Wins !!!");
				break;
			}
			if((xval>550&&xval<575)&&(yval>100&&yval<500)){
				settextstyle(4,0,5);
				cleardevice();
				setcolor(CYAN);
				outtextxy(100,300,"Side 1 Wins !!!");
				break;
			}
			//Bouncing mechanics
			if((xval+20==l1.x1||xval-20==l1.x2)&&(yval<l1.y2&&yval>l1.y1)){
				xvel*=-1;
			}
			if((xval+20==l2.x1||xval-20==l2.x2)&&(yval<l2.y2&&yval>l2.y1)){
				xvel*=-1;
			}
			if(xval>=580||xval<=20){
				xvel*=-1;
			}
			if(yval>=580||yval<=20){
				yvel*=-1;
			}
			//CPU mechanics
			if(p2y1<=50||p2y2>=550){
				lyvel*=-1;
			}
			//Drawing the figures
			setcolor(CYAN);
			l1.ldraw();
			setcolor(MAGENTA);
			l2.ldraw();
			setcolor(LIGHTGREEN);
			setfillstyle(HATCH_FILL,LIGHTGREEN);
			circle(xval,yval,radii);
			floodfill(xval,yval,LIGHTGREEN);
			delay(35);
		}
	}
};

int main(){
	//Creating the graphical window
	initwindow(600,600);
	//Creating the cirle
	Circle C1;
	C1.setval(300,300,20);
	//Initializing the main program
	C1.move();		
	getch();
return 0;
}
