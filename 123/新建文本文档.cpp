#include <iostream>
#include <string>
using namespace std;
startx_x;
startx_y
starty_x
starty_y

void DDA()
{
	int dx=starty_x-startx_x;
	int dy=starty_y-startx_y;
	float xinc,yinc,x=startx_x,y=startx_y;
	int steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
	xinc=float(dx)/steps;
	yinc=float(dy)/steps;
	pointf[0].setX(x);
    pointf[0].setY(y);
	painter.drawPoints(pointf, 1);
	for (int i = 0; i < steps; ++i)
	{
		x+=xinc;
		y+=yinc;
		pointf[0].setX(x);
    	pointf[0].setY(y);
    	painter.drawPoints(pointf, 1);
	}
}

int r,start_x,start_y;

void circle()
{
	int p=1-r;
	drawcircleP(0,r);
	int x=start_x;
	int y=start_y;
	while(x<y)
	{
		x++;
		if (p<0)
		{
			p+=2*x+1;
		}
		else
		{
			y--;
			p+=2*x+1-2*y;
		}
		drawcircleP(int x0,int y0);
	}
}

void drawcircleP(int x0,int y0)
{
	pointf[0].setX(start_x+x0);
    pointf[0].setY(start_y+y0);
	painter.drawPoints(pointf, 1);
	pointf[0].setX(start_x-x0);
    pointf[0].setY(start_y+y0);
	painter.drawPoints(pointf, 1);
	pointf[0].setX(start_x+x0);
    pointf[0].setY(start_y-y0);
	painter.drawPoints(pointf, 1);
	pointf[0].setX(start_x-x0);
    pointf[0].setY(start_y-y0);
	painter.drawPoints(pointf, 1);
	pointf[0].setX(start_x+y0);
    pointf[0].setY(start_y+x0);
	painter.drawPoints(pointf, 1);
	pointf[0].setX(start_x+y0);
    pointf[0].setY(start_y-x0);
	painter.drawPoints(pointf, 1);
	pointf[0].setX(start_x-y0);
    pointf[0].setY(start_y+x0);
	painter.drawPoints(pointf, 1);
	pointf[0].setX(start_x-y0);
    pointf[0].setY(start_y-x0);
	painter.drawPoints(pointf, 1);
}

int longr,shortr,startx,starty;

void ellispe()
{
	int x=0;
	int y=shortr;
	float p1=shortr*shortr-longr*longr*shortr+longr*longr/4;
	while(shortr*shortr*x<longr*longr*y)
	{
		x++;
		if (p1<0)
		{
			pi+=2*shortr*shortr*x+shortr*shortr;
		}
		else
		{
			y--;
			pi+=2*shortr*shortr*x+shortr*shortr-2*y*longr*longr;
		}

	}
	float p2=shortr*shortr*(x+0.5)*(x+0.5)+longr*longr*(y-1)*(y-1)-longr*longr*shortr*shortr;
	while(y!=0)
	{
		y--;
		if (p2>0)
		{
			p2+=longr*longr-2*longr*longr*y;
		}
		else
		{
			x++;
			p2+=longr*longr-2*longr*longr*y+2*shortr*shortr*x;
		}
	}
}

startx_x;
startx_y
starty_x
starty_y

void bresenham()
{
	int dx=starty_x-startx_x;
	int dy=starty_y-startx_y;
	int steps;
	int flag=0;
	if (abs(dx)<abs(dy))
	{
		flag=1;
		swap(dx,dy);
		swap(startx_x,startx_y);
		swap(starty_x,starty_y);
	}
	int x=startx_x;
	int y=startx_y;
	int p=2*dy-dx;
	int xinc=startx_x>starty_x?-1:1;
	int yinc=startx_y>starty_y?-1:1;
	while(x!=starty_x)
	{
		x+=xinc;
		if (p<0)
		{
			p+=2*dy;
		}
		else
		{
			y+=yinc;
			p+=2*dy-2*dx;
		}
		if (flag==1)
		{
			pointf[0].setX(y);
    		pointf[0].setY(x);
    		painter.drawPoints(pointf, 1);
		}
		else
		{
			pointf[0].setX(x);
    		pointf[0].setY(y);
    		painter.drawPoints(pointf, 1);
		}
	}
}