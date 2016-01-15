#ifndef CIRCLE_H
#define CIRCLE_H

#include <QWidget>


class circle : public QWidget
{
   // Q_OBJECT

public:
    explicit circle(QWidget *parent = 0);
    ~circle();
    void paintEvent(QPaintEvent *);


};

#endif // CIRCLE_H
