#include "mainwindow.h"
#include "dialog.h"
#include "dialog1.h"
#include "dialog2.h"
#include "DDA.h"
#include "ui_mainwindow.h"
#include "bresenham.h"
#include "circle.h"
#include "ellipse.h"
#include "data.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setWindowTitle(QString("图形学"));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action1_2_triggered()
{
     startx_x=0;
     startx_y=0;
     starty_x=0;
     starty_y=0;
    Dialog *dialog = new Dialog;
    if (dialog->exec() == QDialog::Accepted) {
        MyImgTest* widget = new MyImgTest();
        widget->show();
    }
}

void MainWindow::on_action2_1_triggered()
{
     r=0;
     start_x=0;
     start_y=0;
    Dialog1 *dialog1 = new Dialog1;
    if (dialog1->exec() == QDialog::Accepted) {
        circle* widget = new circle();
        widget->show();
    }
}

void MainWindow::on_action1_3_triggered()
{
    startx_x=0;
    startx_y=0;
    starty_x=0;
    starty_y=0;
    Dialog *dialog = new Dialog;
    if (dialog->exec() == QDialog::Accepted) {
        Bresenham* widget = new Bresenham();
        widget->show();
    }
}

void MainWindow::on_action3_1_triggered()
{
     longr=0,shortr=0,startx=0,starty=0;
    Dialog2 *dialog2 = new Dialog2;
    if (dialog2->exec() == QDialog::Accepted) {
        ellipse* widget = new ellipse();
        widget->show();
    }
}
