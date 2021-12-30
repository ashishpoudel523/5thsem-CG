#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int ROUND(float a){
	int b = a + 0.5;
	return b;
}

void lineDDA(int xa, int ya, int xb, int yb)
{
	int dx = xb - xa; int dy = yb -ya; int steps, k;
	float xincrement , yincrement, x =  xa, y = ya;
	if (abs(dx)>abs(dy)){
		steps = abs(dx);
	}
	else{
		steps = abs(dy);
	}
	xincrement = (float)dx/(float)steps;
	yincrement = (float)dy/(float)steps;
	putpixel(round(x), round(y) , WHITE);
	for (k = 0; k<steps; k++)
	{
		x+=xincrement;
		putpixel(round(x), round(y), WHITE);
		delay(50);
	}
}

int main()
{
	int x1, y1, x2, y2, x3 , y3;
	int gd = DETECT, gm;
	int i;
	printf("Enter x1: \n");
	scanf("%d", &x1);
	
	printf("Enter y1: \n");
	scanf("%d", &y1);
	
	printf("Enter x2: \n");
	scanf("%d", &x2);
	
	printf("Enter y1: \n");
	scanf("%d", &y1);
	
	initgraph(&gd , &gm , NULL);
	lineDDA(x1, y1, x2, y2);
	getch();
	closegraph();
	return 0;
}
