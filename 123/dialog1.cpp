#include "dialog1.h"
#include "ui_dialog1.h"
#include "data.h"

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    Dialog1::setWindowTitle(QString("画圆算法"));
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_spinBox_valueChanged(int arg1)
{
    start_x=arg1;
}

void Dialog1::on_spinBox_3_valueChanged(int arg1)
{
    start_y=arg1;
}

void Dialog1::on_spinBox_2_valueChanged(int arg1)
{
    r=arg1;
}
