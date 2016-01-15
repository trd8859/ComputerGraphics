#include "dialog.h"
#include "ui_dialog.h"
#include "data.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    Dialog::setWindowTitle(QString("画线算法"));

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_spinBox_valueChanged(int arg1)
{
  startx_x=arg1;
}

void Dialog::on_spinBox_2_valueChanged(int arg1)
{
    startx_y=arg1;
}

void Dialog::on_spinBox_3_valueChanged(int arg1)
{
    starty_x=arg1;
}

void Dialog::on_spinBox_4_valueChanged(int arg1)
{
    starty_y=arg1;
}


void Dialog::on_buttonBox_accepted()
{

}
