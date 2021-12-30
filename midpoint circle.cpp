//mangsir 27
#include<stdio.h>
#include<graphics.h>
#include<math.h>

void Midpointcircle(int xc, int yc, int r);
 int main()
 {
 	int xc, yc, r;
 	printf("Enter the value of x center : \t");
 	scanf("%d", &xc);
 	printf("Enter the value of y center : \t");
 	scanf("%d", &yc);
 	printf("Enter the value of redius: \t");
 	scanf("%d", &r);
 	Midpointcircle(xc, yc, r);
 	return 0;
 }
 
 void Midpointcircle(int xc, int yc, int r){
 	int gd, gm , x, y, p;
 	
 	detectgraph(&gd, &gm);
 	initgraph(&gd, &gm, " ");
 	 x = 0;
 	 y = r;
 	 p = 1-r;
 	 do
 	 {
 	 	putpixel(xc+x, yc+y, 15);
 	 	putpixel(xc+y, yc+x, 15);
 	 	putpixel(xc+x, yc-y, 15);
 	 	putpixel(xc+y, yc-x, 15);
 	 	putpixel(xc-x, yc-y, 15);
 	 	putpixel(xc-x, yc+y, 15);
 	 	putpixel(xc-y, yc+x, 15);
 	 	putpixel(xc-y, yc-x, 15);
 	 	
 	 	if(p<0){
 	 		x = x+1;
 	 		y = y;
 	 		p = p + 2*x + 1;
 	 	}
 	 	else
 	 	{
 	 		x = x+1;
 	 		y = y-1;
 	 		p = p + 2*(x-y) + 1;
 	 	}
 	 	delay(200);
 	 }
 	 while(x<y);
 	 getch();
 	 closegraph();
 }
