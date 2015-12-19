#include "newmemo.h"
#include "ui_newmemo.h"
#include "qmessagebox.h"

NewMemo::NewMemo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewMemo)
{
    ui->setupUi(this);

    MainWindow conn;

    if (conn.connOpen()) {
        ui->label->setText("Connected");
    } else {
        ui->label->setText("Not Connected");
    }

}

NewMemo::~NewMemo()
{
    delete ui;
}

void NewMemo::on_btnMemoSave_clicked()
{

    MainWindow conn;

    QString memoTitle , memoBody;

    memoTitle = ui->memoTitile->text();
    memoBody = ui->plainTextEdit->toPlainText();



    if(!conn.connOpen()){
        qDebug() << "No Connection to Database found";
        return;
    }

    conn.connOpen();

    QSqlQuery qry;
    qry.prepare("INSERT INTO memotbl ( memoTitle , memoBody) VALUES ('"+memoTitle+"','"+memoBody+"')");

    if(qry.exec())
    {
        if (qry.next())
        {
            QMessageBox::critical(this,tr("Error"),qry.lastError().text());
            conn.connClose();
        }else{


            QMessageBox::about(this,tr("Saving.."),tr("Saved !"));
            conn.connClose();
        }
}
}

void NewMemo::on_btnmemoUpdate_clicked()
{


    MainWindow conn;

    QString memoTitle , memoBody , memoid;

    memoTitle = ui->memoTitile->text();
    memoBody = ui->plainTextEdit->toPlainText();
    memoid = ui->memoid->text();



    if(!conn.connOpen()){
        qDebug() << "No Connection to Database found";
        return;
    }

    conn.connOpen();

    QSqlQuery qry;
    qry.prepare("UPDATE memotbl SET memoTitle='"+memoTitle+"', memoBody='"+memoBody+"' WHERE id='"+memoid+"' ");

    if(qry.exec())
    {
        if (qry.next())
        {
            QMessageBox::critical(this,tr("Error"),qry.lastError().text());
            conn.connClose();
        }else{


            QMessageBox::about(this,tr("Update.."),tr("Succssfully Memo Updated ! !"));
            conn.connClose();
        }
}


}

void NewMemo::on_btnmemodelete_clicked()
{
    MainWindow conn;

    QString memoTitle , memoBody , memoid;

    memoTitle = ui->memoTitile->text();
    memoBody = ui->plainTextEdit->toPlainText();
    memoid = ui->memoid->text();



    if(!conn.connOpen()){
        qDebug() << "No Connection to Database found";
        return;
    }

    conn.connOpen();

    QSqlQuery qry;
    qry.prepare("DELETE FROM memotbl WHERE id='"+memoid+"' ");

    if(qry.exec())
    {
        if (qry.next())
        {
            QMessageBox::critical(this,tr("Error"),qry.lastError().text());
            conn.connClose();
        }else{


            QMessageBox::about(this,tr("Deleting.."),tr("Successfully Deleted !"));
            conn.connClose();
        }
}

}
