#include "newmemo.h"
#include "ui_newmemo.h"

NewMemo::NewMemo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewMemo)
{
    ui->setupUi(this);
}

NewMemo::~NewMemo()
{
    delete ui;
}
