#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QWidget>



class ellipse : public QWidget
{
  //  Q_OBJECT

public:
    explicit ellipse(QWidget *parent = 0);
    ~ellipse();
    void paintEvent(QPaintEvent *);

};

#endif // ELLIPSE_H
