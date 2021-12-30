#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
int gd=DETECT,gm;
int n,i,p[20],q[20];
int convertx(int x);
int converty(int y);
void axis(void);
void init(void);
void shear(void);
void reflect(void);
int main()
{
int ch;
printf("\b");
printf("Enter the number of vertices:");
scanf("%d",&n);
printf("Enter the co-ordinate of polygon (Enter the first vertex at the end again)");
for(i=0;i<2*n+2;i++)
{
scanf("%d",&p[i]);
}
do
{
printf("\n \t\t2D-Transformation \n1.reflection\n2.shearing\n3.exit");
printf("\n\nEnter yuor choice:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
reflect();
break;
case 2:
shear();
break;
case 3: break;
default:
printf("Wrong choice enter again");
break;
}
}while(ch!=3);
}
void axis(void)
{
cleardevice();
setlinestyle(SOLID_LINE,1,1);
line(320,0,320,getmaxy());
line(0,240,getmaxx(),240);
outtextxy(325,245,"0");
line(316,40,324,40);
outtextxy(325,41,"400");
line(316,440,324,440);
outtextxy(325,441,"-400");
line(20,236,20,244);
outtextxy(19,250,"-600");
line(620,236,620,244);
outtextxy(608,250,"600");
}
void init()
{
cleardevice();
axis();
setcolor(YELLOW);
setlinestyle(SOLID_LINE,1,1);
for(i=0;i<2*n+2;i+=2)
{
q[i]=convertx(p[i]);
}
for(i=1;i<2*n+2;i+=2)
{
q[i]=converty(p[i]);
}
for(i=0;i<2*n;i+=2)
{
line(q[i],q[i+1],q[i+2],q[i+3]);
}
setcolor(WHITE);
}
int convertx(int x)
{
x=x/2;
return(x+=320);
}
int converty(int y)
{
return(y=240-y);
}
void shear()
{
int sh[20],sho[20];
float shx,shy,c;
printf("(1)share relate to x-axis\n");
printf("(2)share relate to y-axis\n");
printf("\n Enter your choice:");
scanf("%f",&c);
if(c==1)
{
printf("\nEnter the shear factor(shx):");
scanf("%f",&shx);
for(i=0;i<2*n+2;i+=2)
{
sh[i]=p[i]+(shx*p[i+1]);
}
for(i=1;i<2*n+2;i+=2)
{
sh[i]=p[i];
}
}
else
{
printf("\enter the shear factor(shy):");
scanf("%f",&shy);
for(i=1;i<2*n+2;i+=2)
{

sh[i]=(shy*p[i-1])+p[i];
}
for(i=0;i<2*n+2;i+=2)
{
sh[i]=p[i];
}
}
for(i=0;i<2*n+2;i+=2)
{
sho[i]=convertx(sh[i]);
}
for(i=1;i<2*n+2;i+=2)
{
sho[i]=converty(sh[i]);
}
initgraph(&gd,&gm,"");
axis();
init();
setlinestyle(DOTTED_LINE,1,1);
for(i=0;i<2*n;i+=2)
{
line(sho[i],sho[i+1],sho[i+2],sho[i+3]);
}
getch();
}
void reflect()
{
int i,c,rf[20],rft[20];
printf("\n 1.x-axis reflection\n 2.y-axis reflection");
printf("\n Enter the choice:");
scanf("%d",&c);
if(c==1)
{
for(i=1;i<2*n+2;i+=2)
{
rf[i]=p[i]*(-1);
}
for(i=0;i<2*n+2;i+=2)
{
rf[i]=p[i];
}
}
else
{
for(i=0;i<2*n+2;i+=2)
{
rf[i]=p[i]*(-1);
}
for(i=1;i<2*n+2;i+=2)
{
rf[i]=p[i];
}
}
for(i=0;i<2*n+2;i+=2)
{
rft[i]=convertx(rf[i]);
}
for(i=1;i<2*n+2;i+=2)
{
rft[i]=converty(rf[i]);
}
initgraph(&gd,&gm,"");
axis();
init();
setlinestyle(DOTTED_LINE,1,1);
for(i=0;i<2*n;i+=2)
{
line(rft[i],rft[i+1],rft[i+2],rft[i+3]);
}
getch();
closegraph();
}
