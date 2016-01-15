#include "circle.h"
#include <QPainter>
#include <QRect>
#include <QPointF>
#include <QLineF>
#include <math.h>
#include "data.h"

#define PI  (3.1415926)
circle::circle(QWidget *parent) :
    QWidget(parent)

{
    setFixedSize(1200,600);
    setWindowTitle("circle");
}

circle::~circle()
{

}
QPointF pointf[8];
void paintEvent1(int x0,int y0)
{
    pointf[0].setX(start_x+x0);
    pointf[0].setY(0-start_y+y0);
    pointf[1].setX(start_x-x0);
    pointf[1].setY(0-start_y+y0);
    pointf[2].setX(start_x+x0);
    pointf[2].setY(0-start_y-y0);
    pointf[3].setX(start_x-x0);
    pointf[3].setY(0-start_y-y0);
    pointf[4].setX(start_x+y0);
    pointf[4].setY(0-start_y+x0);
    pointf[5].setX(start_x+y0);
    pointf[5].setY(0-start_y-x0);
    pointf[6].setX(start_x-y0);
    pointf[6].setY(0-start_y+x0);
    pointf[7].setX(start_x-y0);
    pointf[7].setY(0-start_y-x0);
}

void circle::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    painter.translate(600, 300);
    int xEndX=590;
    int xEndY=0;
    int yEndX=0;
    int yEndY=-280;
    int xOffset=13;
    int yOffset=13;
    QPoint beginPoint(-590,0);
    QPoint xEndPoint(xEndX,xEndY);
    QPoint yEndPoint(yEndX,yEndY);
    painter.drawLine(beginPoint,xEndPoint);
    QPoint beginPoint2(0,290);
    painter.drawLine(beginPoint2,yEndPoint);

    for(int i=-550;i<600;i+=50)
    {
        beginPoint.setX(i);
        beginPoint.setY(0);
        beginPoint2.setX(i);
        beginPoint2.setY(-5);
        painter.drawLine(beginPoint2,beginPoint);
        char x[10];
        sprintf(x,"%d",i);
        painter.drawText(i+1,15,x);
    }
    for(int i=-250;i<300;i+=50)
    {
        beginPoint.setX(0);
        beginPoint.setY(0-i);
        beginPoint2.setX(5);
        beginPoint2.setY(0-i);
        painter.drawLine(beginPoint2,beginPoint);
        char x[10];
        sprintf(x,"%d",0-i);
        if(i!=0)
       { painter.drawText(-25,i,x);}
    }

    QPoint xArrowsLeftPoint(xEndX,xEndY);
    QPoint xArrowsTopPoint(xEndX-xOffset,-xOffset*tan(PI/6));
    QPoint xArrowsBotPoint(xEndX-xOffset,xOffset*tan(PI/6));
    static const QPoint xArrowsPoints[3] = {
        xArrowsLeftPoint,xArrowsTopPoint,xArrowsBotPoint,
    };
    painter.setBrush(QBrush(Qt::black,Qt::SolidPattern));
    painter.drawPolygon(xArrowsPoints,3);
    painter.drawText(xEndX-20,xEndY-20,tr("X轴"));

    QPoint yArrowsBotPoint(yEndX,yEndY-yOffset);
    QPoint yArrowsRightPoint(yOffset*tan(PI/6),yEndY);
    QPoint yArrowsLeftPoint(-yOffset*tan(PI/6),yEndY);
    static const QPoint yArrowsPoints[3] = {
       yArrowsBotPoint,yArrowsRightPoint,yArrowsLeftPoint,
    };
    painter.setBrush(QBrush(Qt::black,Qt::SolidPattern));
    painter.drawPolygon(yArrowsPoints,3);
    painter.drawText(yEndX+20,yEndY+20,tr("Y轴"));

        painter.setPen(Qt::blue);
        int p=1-r;
        int x=0;
        int y=r;
        paintEvent1(0,r);
        painter.drawPoints(pointf, 8);
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
            paintEvent1(x,y);
            painter.drawPoints(pointf, 8);
        }

  }
