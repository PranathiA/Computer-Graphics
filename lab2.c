#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>

int sign(x)
{
if(x>0)
 return 1;
else if(x<0)
 return -1;
else
 return 0;
}

void bresenham(int x1,int y1,int x2,int y2)
{
int x,y,dx,dy,swap,temp,s1,s2,p,i;

x=x1;
y=y1;
dx=abs(x2-x1);
dy=abs(y2-y1);
s1=sign(x2-x1);
s2=sign(y2-y1);
swap=0;
putpixel(x1,y1,RED);
if(dy>dx)
 {
 temp=dx;
 dx=dy;
 dy=temp;
 swap=1;
 }
p=2*dy-dx;
for(i=0;i<dx;i++)
 {
 putpixel(x,y,getcolor());
 while(p>=0)
  {
  p=p-2*dx;
  if(swap)
   x+=s1;
  else
   y+=s2;
  }
 p=p+2*dy;
 if(swap)
  y+=s2;
 else
  x+=s1;
}
putpixel(x2,y2,RED);
}

void pixel(int xcenter,int ycenter,int x,int y)
{
	putpixel(xcenter + x, ycenter + y, WHITE);
    putpixel(xcenter - x, ycenter + y, WHITE);
    putpixel(xcenter + x, ycenter - y, WHITE);
    putpixel(xcenter - x, ycenter - y, WHITE);
    putpixel(xcenter + y, ycenter + x, WHITE);
    putpixel(xcenter - y, ycenter + x, WHITE);
    putpixel(xcenter + y, ycenter - x, WHITE);
    putpixel(xcenter - y, ycenter - x, WHITE);
}

void midpointcircle(int xcenter,int ycenter,int radius)
{
	int i,x,y,pk;
	x=0;
	y=radius;
	pk=1-radius;
	pixel(xcenter,ycenter,x,y);
	while(x<y)
    {
        if(pk<0)
        {
            x=x+1;
            pk=pk+(2*x)+1;
        }
        else
        {
            x=x+1;
            y=y-1;
            pk=pk+(2*x)-(2*y)+1;
        }
     	pixel(xcenter,ycenter,x,y);
    }

}

void main()
{
	int gd,gm;
	detectgraph(&gd,&gm);
    initgraph(&gd,&gm," ");
    midpointcircle(100,100,50);
    midpointcircle(125,75,5);
    midpointcircle(75,75,5);
    bresenham(100,150,100,350);
    bresenham(100,150,150,200);
    bresenham(100,350,150,400);
    bresenham(100,150,50,200);
    bresenham(100,350,50,400);
    bresenham(75,125,125,125);
    getch();
    delay(5000);
    closegraph();
}
