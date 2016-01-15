#include "DDA.h"
#include <QPainter>
#include <QRect>
#include <QPointF>
#include <QLineF>
#include <math.h>
#include "data.h"
#include <QTime>
#include <QCoreApplication>

#define PI  (3.1415926)

MyImgTest::MyImgTest(QWidget* parent) : QWidget(parent)
{
    setFixedSize(1200,600);
    setWindowTitle("DDA");
}

MyImgTest::~MyImgTest()
{

}


void MyImgTest::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    QPointF pointf[100];
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
        int xs=startx_x;
        int xe=starty_x;
        int ys=startx_y;
        int ye=starty_y;
        int dx=xe-xs;
        int dy=ye-ys;
        float xinc,yinc,x=xs,y=ys;
        int steps;
        if(abs(dx)>abs(dy))
        {
            steps=abs(dx);
        }
        else
            steps=abs(dy);
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
            pointf[0].setY(0-y);
            painter.drawPoints(pointf, 1);
        }
  }




