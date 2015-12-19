#include "managememo.h"
#include "ui_managememo.h"
#include "qsqlquery.h"
#include "qsqlquerymodel.h"

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

    conn.connClose();

    qDebug() << (modal->rowCount());

}
