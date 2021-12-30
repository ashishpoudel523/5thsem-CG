#include<stdio.h>
#include<string>
#include<graphics.h>
int flood_fill(int x,int y,int old_col,int new_col)
{
if (getpixel(x,y)==old_col)
{
putpixel(x,y,new_col);
flood_fill(x+1,y,old_col,new_col);
flood_fill(x-1,y,old_col,new_col);
flood_fill(x,y+1,old_col,new_col);
flood_fill(x,y-1,old_col,new_col);
flood_fill(x+1,y+1,old_col,new_col);
flood_fill(x-1,y-1,old_col,new_col);
flood_fill(x+1,y-1,old_col,new_col);
flood_fill(x-1,y+1,old_col,new_col);
}
}
boundary(int x, int y, int f_col, int b_col)
{
if (getpixel(x,y)!= b_col && getpixel(x,y)!= f_col)
{
putpixel(x,y,f_col);
boundary(x+1,y,f_col,b_col);
boundary(x-1,y,f_col,b_col);
boundary(x,y+1,f_col,b_col);
boundary(x,y-1,f_col,b_col);
}
}
int main()
{
int gd,gm;
/* Initialise graphics mode ---------------------------------- */
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"");
setcolor(RED);
rectangle(50,50,100,100);
boundary(55,55,BLUE,RED);
delay(2000);
flood_fill(55,55,BLUE,YELLOW);
getch();
closegraph();
}
