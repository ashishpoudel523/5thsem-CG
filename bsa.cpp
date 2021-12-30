#include<stdio.h>
#include<graphics.h> #include<math.h>
void lineBRESENHAM(int x1,int y1,int x2,int y2);
int main()
{
int x1,y1,x2,y2;
/* Read two end points of line ---------------------------------- */
printf("Enter the value of x1 :\t");
scanf("%d",&x1);
printf("Enter the value of y1 :\t");
scanf("%d",&y1);
printf("Enter the value of x2 :\t");
scanf("%d",&x2);
printf("Enter the value of y2 :\t");
scanf("%d",&y2);
/* Function Calling for line drawing ---------------------------------- */
lineBRESENHAM(x1,y1,x2,y2);
}
void lineBRESENHAM(int x1,int y1,int x2,int y2)
{
int gd,gm,i;
int dx,dy,x,y,p,two_dy,two_dy_dx,xend;
/* Initialise graphics mode ---------------------------------- */
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"");
dx=abs(x2-x1);
dy=abs(y2-y1);
/* Initialise decision variable -------------------------------- */
p = 2 * dy-dx;
/* Calculating Constants -------------------------------*/
two_dy=2*dy;
two_dy_dx=2*(dy-dx);
/* Initialise loop counter -------------------------------- */
i = 1;
/* Initialise starting point by finding left side point -------------------------------- */


if(x1>x2)
{
x=x2;
y=y2;
xend=x1;
}
else
{
x=x1;
y=y1;
xend=x2;
}
putpixel(x,y,WHITE);
while(x<xend)
{
x++;
if(p<0)
{
p=p+two_dy;
}
else
{
y++;
p=p+two_dy_dx;
}
putpixel(x,y,WHITE);
delay(200);
}
getch();
closegraph();
}
