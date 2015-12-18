#include "homewindow.h"
#include "ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);

    if(connOpen())
    {
        ui->label->setText("[+] Connected to Database");
    }else {
    ui->label->setText("'<b>[+] Lost Connection to database</b>");
}
}

HomeWindow::~HomeWindow()
{
    delete ui;
}
