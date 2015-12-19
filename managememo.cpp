#include "managememo.h"
#include "ui_managememo.h"
#include "qsqlquery.h"
#include "qsqlquerymodel.h"
#include "qmessagebox.h"

ManageMemo::ManageMemo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageMemo)
{
    ui->setupUi(this);

    MainWindow conn;

    if (conn.connOpen()) {
        ui->label->setText("Connected");
    } else {
        ui->label->setText("Not Connected");
    }

}

ManageMemo::~ManageMemo()
{
    delete ui;
}

void ManageMemo::on_pushButton_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.myDB);

    qry->prepare("select * from memotbl");

    qry->exec();
    modal->setQuery(*qry);

    ui->tableView->setModel(modal);
    ui->comboBox->setModel(modal);

    conn.connClose();

    qDebug() << (modal->rowCount());

}

void ManageMemo::on_btnDelete_clicked()
{
    MainWindow conn;

    QString  memoid;

    memoid = ui->txtsearch->text();



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

void ManageMemo::on_comboBox_currentIndexChanged(const QString &arg1)
{

    QString name=ui->comboBox->currentText();

    ui->txtsearch->setText(name);


}

void ManageMemo::on_tableView_doubleClicked(const QModelIndex &index)
{

}
