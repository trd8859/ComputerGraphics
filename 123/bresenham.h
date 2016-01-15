#ifndef BRESENHAM_H
#define BRESENHAM_H

#include <QWidget>

class Bresenham : public QWidget
{
    Q_OBJECT
public:
    explicit Bresenham(QWidget *parent = 0);
    ~Bresenham();
    void paintEvent(QPaintEvent *);
signals:
public slots:
  void onTimerOut();

};

#endif // BRESENHAM_H
