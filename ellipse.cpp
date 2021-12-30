#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define ROUND(a) ((int)(a+0.5))
void ellipseplotpoints(int xc, int yc, int x, int y)
{
putpixel(xc + x, yc + y, WHITE);
putpixel(xc - x, yc + y, WHITE);
putpixel(xc + x, yc - y, WHITE);
putpixel(xc - x, yc - y, WHITE);
}
void ellipsemidpoint(int xc, int yc, int rx, int ry)
{
int rx2 = rx*rx;
int ry2 = ry*ry;
int drx2 = 2*rx2;
int dry2 = 2*ry2;
int p, x=0, y=ry, px=0, py=drx2*y;
ellipseplotpoints(xc, yc, x, y);
p = ROUND (ry2 - (rx2*ry) + (0.25*rx2));
while(px < py)
{
x++;
px += dry2;
if(p<0)
{
p += ry2 + px;
}
else
{
y--;
py -= drx2;
p += ry2 + px - py;
}
ellipseplotpoints(xc, yc, x, y);
delay(100);
}
p = ROUND (ry2 * (x + 0.5) * (x + 0.5) + rx2 *(y-1)*(y-1) - rx2*ry2);
while(y>0)
{
y--;
py -= drx2;
if(p>0)
{
p += rx2 - py;
}
else
{
x++;
px += drx2;
p += rx2 - py +px;
}
ellipseplotpoints(xc, yc, x ,y);
delay(100);
}
delay(1000);
}
int main()
{
int xcent, ycent, x, y,gd,gm;
printf("Enter value for x-center :-");
scanf("%d" ,&xcent);
printf("Enter value for y-center :-");
scanf("%d" ,&ycent);
printf("Enter value for radius from x :-");
scanf("%d" ,&x);
printf("Enter value for radius from y :-");
scanf("%d" ,&y);
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"");
ellipsemidpoint(xcent, ycent, x, y);
closegraph();
}
