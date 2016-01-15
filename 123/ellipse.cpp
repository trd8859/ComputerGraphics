#include "ellipse.h"
#include "ui_ellipse.h"
#include <QPainter>
#include <QRect>
#include <QPointF>
#include <QLineF>
#include <math.h>
#include "data.h"

#define PI  (3.1415926)

ellipse::ellipse(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(1200,600);
    setWindowTitle("ellipse");
}

ellipse::~ellipse()
{

}

QPointF pointf1[4];
void paintEvent2(int x0,int y0)
{
    pointf1[0].setX(startx+x0);
    pointf1[0].setY(0-starty+y0);
    pointf1[1].setX(startx-x0);
    pointf1[1].setY(0-starty+y0);
    pointf1[2].setX(startx+x0);
    pointf1[2].setY(0-starty-y0);
    pointf1[3].setX(startx-x0);
    pointf1[3].setY(0-starty-y0);
}

void ellipse::paintEvent(QPaintEvent *)
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
        paintEvent2(0,shortr);
        painter.drawPoints(pointf1, 4);


            int ry=shortr;
            int rx=longr;
            long p0 = ry*ry-rx*rx*ry+0.25*rx*rx;
            long x0 =0,y0 = ry;
            while(ry*ry*x0<rx*rx*y0)
            {
                x0++;
                if(p0<0)
                {
                    p0 = p0 +2*ry*ry*x0+ry*ry;
                }
                else
                {
                    y0--;
                    p0 = p0+2*ry*ry*x0-2*rx*rx*y0+ry*ry;
                }
                paintEvent2(x0,y0);
                painter.drawPoints(pointf1, 4);
            }
            p0 = ry*ry*(x0+0.5)*(x0+0.5)+rx*rx*(y0-1)*(y0-1)-rx*rx*ry*ry;
            while(y0>0)
            {
                y0--;
                if(p0>0)
                {
                    p0 = p0 -2*rx*rx*y0+rx*rx;
                }
                else
                {
                    x0++;
                    p0 = p0 +2*ry*ry*x0-2*rx*rx*y0+rx*rx;
                }
                paintEvent2(x0,y0);
                painter.drawPoints(pointf1, 4);
            }

  }
