#include "dialog2.h"
#include "ui_dialog2.h"
#include "data.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    Dialog2::setWindowTitle(QString("椭圆算法"));
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_spinBox_valueChanged(int arg1)
{
    startx=arg1;
}

void Dialog2::on_spinBox_2_valueChanged(int arg1)
{
    starty=arg1;
}

void Dialog2::on_spinBox_3_valueChanged(int arg1)
{
    longr=arg1;
}

void Dialog2::on_spinBox_4_valueChanged(int arg1)
{
    shortr=arg1;
}
