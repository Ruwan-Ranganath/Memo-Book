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
