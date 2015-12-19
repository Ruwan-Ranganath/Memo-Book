#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "newmemo.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    MainWindow conn;

    if (conn.connOpen()) {
        ui->label->setText("Connected");
    } else {
        ui->label->setText("Not Connected");
    }
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_pushButton_clicked()
{
    NewMemo newmem;
    newmem.setModal(true);
    newmem.exec();
}
