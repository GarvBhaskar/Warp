#include<iostream>
#include<graphics.h>
#include<conio.h>

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
};
class Circle{
	public:
	int xval,yval,radii;
	void setval(int a, int b, int c){
	xval=a;
	yval=b;
	radii=c;}
	void draw()
	{
	circle(xval,yval,radii);
	}
};
int main(){
	//Creating the graphical window
	initwindow(600,600);
	//creating lines
	setcolor(CYAN);
	line(100,150,100,350);
	setcolor(MAGENTA);
	line(500,250,500,450);
	//Creating circles
	Circle C1,C2,C3,C4;
	setcolor(LIGHTGREEN);
	setfillstyle(HATCH_FILL, LIGHTGREEN);
	C1.setval(150,150,20);
	C2.setval(400,70,20);
	C3.setval(275,30,20);
	C4.setval(555,180,20);
	C1.draw();
	C2.draw();
	C3.draw();
	C4.draw();
	floodfill(150,150,LIGHTGREEN);
	floodfill(400,70,LIGHTGREEN);
	floodfill(275,30,LIGHTGREEN);
	floodfill(555,180,LIGHTGREEN);
	Goal G1,G2;
	//Creating the goals
	G1.setup(50,100,25,100,25,500,50,500);
	G2.setup(550,100,575,100,575,500,550,500);
	setcolor(RED);
	G1.goaldraw();
	G2.goaldraw();
	getch();
return 0;
}
