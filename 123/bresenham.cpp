#include "bresenham.h"
#include "ui_bresenham.h"
#include <QPainter>
#include <QRect>
#include <QPointF>
#include <QLineF>
#include <math.h>
#include "data.h"
#include <QtAlgorithms>
#include <QTimer>
#include <QTime>
#include <QWaitCondition>
#include <QMutex>

#define PI  (3.1415926)

Bresenham::Bresenham(QWidget* parent) : QWidget(parent)
{
    setFixedSize(1200,600);
    setWindowTitle("Bresenham");
}

Bresenham::~Bresenham()
{

}

void swap(int &x,int &y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
}

void sleep(unsigned int msec)
{
   /* QTimer t;
    t.start();
    while(t.elapsed() < 250)
    {
    QCoreApplication::processEvents();
    }*/
}

void Bresenham::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    QPointF pointf[1200];
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
        int x,y,dx,dy,unitx,unity,fabs_dx,fabs_dy,e;
        dx=starty_x-startx_x;
        dy=starty_y-startx_y;
        fabs_dx = (int)fabs(dx);
        fabs_dy = (int)fabs(dy);
        unitx = dx / fabs_dx ;
        unity = dy / fabs_dy ;
        x=startx_x;
        y=startx_y;
        if( fabs_dx> fabs_dy )
        {
        e=-fabs_dx;
        for(int i=0;i<=fabs_dx;i++)
        {
            pointf[0].setX(x);
            pointf[0].setY(0-y);
            sleep(100);
            painter.drawPoints(pointf, 1);
            x+=unitx,e=e+2*fabs_dy;
            if(e>=0)
            {
            y+=unity;e=e-2*fabs_dx;
            }

        }
        }
        else
        {
             e-=fabs_dy;
            for(int i=0;i<=fabs_dy;i++)
            {
            pointf[0].setX(x);
            pointf[0].setY(0-y);
            sleep(100);
            painter.drawPoints(pointf, 1);
            y+=unity,e=e+2*fabs_dx;
            if(e>=0)
            {
            x+=unitx;e=e-2*fabs_dy;
            }
            }

         }
        }

void Bresenham::onTimerOut()
{

}
