#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>

void DDA(int x1,int y1,int x2,int y2){
	int dx=x2-x1;
	int dy=y2-y1;
	int steps;

	if(abs(dx)>abs(dy)){
		steps=abs(dx);
	}
	else{
		steps=dy;
	}

	if(steps==0){
		putpixel(x1,y1,WHITE);
		return;
	}

	float xinc=(float)dx/steps;
	float yinc=(float)dy/steps;
	
	float x=x1;
	float y=y1;
	for(int i=0;i<=steps;i++){
		putpixel((int)x+0.5,(int)y+0.5,RED);
		x=x+xinc;
		y=y+yinc;
	}
};

int main(){
	int gd =DETECT, gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	
	int left=100;
	int right=500;
	int top=100;
	int bottom=350;

	int cx=(left+right)/2;
	int cy=(top+bottom)/2;

	DDA(left,top,left,bottom);
	DDA(left,top,right,top);
	DDA(right,top,right,bottom);
	DDA(left,bottom,right,bottom);

	int topX=cx,topY=top;
	int bottomX=cx,bottomY=bottom;
	int rightX=right,rightY=cy;
	int leftX=left,leftY=cy;

	DDA(topX,topY,leftX,leftY);
	DDA(leftX,leftY,bottomX,bottomY);
	DDA(topX,topY,rightX,rightY);
	DDA(bottomX,bottomY,rightX,rightY);

	getch();
	closegraph();
	return 0;
}