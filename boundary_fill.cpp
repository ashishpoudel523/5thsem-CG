//mangsir 27
//boundary fill
#include<stdio.h>
#include<graphics.h>
int boundary(int x, int y , int f_col, int b_col)
{
	if(getpixel(x,y)!=b_col && getpixel(x,y)!=f_col)
	{
		putpixel(x,y,f_col);
		boundary(x+1, y, f_col, b_col);
		boundary(x-1, y, f_col, b_col);
		boundary(x, y+1, f_col, b_col);
		boundary(x, y-1, f_col, b_col);
	}
}
int main()
{
	int gm , gd;
	detectgraph(&gd, &gm);
	initgraph(&gd, &gm, NULL);
	setcolor(RED);
	rectangle(100, 100, 150, 150);
	boundary(140, 140, BLUE, RED);
	getch();
	closegraph();
	return 0;
}
