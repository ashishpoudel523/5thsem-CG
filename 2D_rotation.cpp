//2D rotation
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
	int gm, gd = DETECT;
	int x1, x2, x3, y1, y2, y3, nx1, nx2, nx3, ny1, ny2, ny3;
	int r;
	float t, m;
	printf("\t Program for 2D Rotation:");
	printf("\n Enter the points of triangle: \n");
	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
	printf("\n Enter the angle of rotation: ");
	scanf("%d", &r);
	
	initgraph(&gd, &gm, NULL);
	setcolor(WHITE);
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);
	
	
	
	t = (3.14*r)/180;
	nx1 = abs(x1*cos(t) - y1*sin(t));
	ny1 = abs(x1*sin(t) + y1*cos(t));
	nx2 = abs(x2*cos(t) - y2*sin(t));
	ny2 = abs(x2*sin(t) + y2*cos(t));
	nx3 = abs(x3*cos(t) - y3*sin(t));
	ny3 = abs(x3*sin(t) + y3*cos(t));
	
	delay(1000);
	line(nx1, ny1, nx2, ny2);
	line(nx2, ny2, nx3, ny3);
	line(nx3, ny3, nx1, ny1);
	getch();
	closegraph();
	return 0;
	// (300, 300), (500, 300), (700, 700)
	
//	dda
//	rotation
//	bsa
//	translation
//	circle
//	scaling
	
}
