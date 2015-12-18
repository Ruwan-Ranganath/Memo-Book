#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"


#define Path_to_DB "E:/qt-projects/memo.sqlite"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(Path_to_DB);
    QFileInfo checkFile(Path_to_DB);

    if (checkFile.isFile())
    {
        if(myDB.open())
        {
            ui->lblResult->setText("[+] Connected to Database");
        }
    }else {
        ui->lblResult->setText("'<b>[+] Lost Connection to database</b>");

    }
}

MainWindow::~MainWindow()
{
    delete ui;
    qDebug() << "Closing the connection to the database file on exit. ";
    myDB.close();
}

void MainWindow::on_btnClear_clicked()
{
    ui->txtPassword->setText("");
    ui->txtUserName->setText("");
}

void MainWindow::on_btnClose_clicked()
{
    close();
}

void MainWindow::on_btnLogin_clicked()
{
    QString Username , Password;

    Username = ui->txtUserName->text();
    Password = ui->txtPassword->text();

    if(!myDB.open()){
        qDebug() << "No Connection to Database found";
        return;
    }

    QSqlQuery qry;
    if(qry.exec("SELECT Username, Password, Role FROM Users WHERE UserName=\'" + Username + "\' AND Password=\'"+Password+"\' "))
    {
        if (qry.next())
        {
            ui->lblResult->setText("[+] Valid User Name and Password");

            QString msg = "Username = " +qry.value(0).toString()+" \n" +
                          "Password = " +qry.value(1).toString()+" \n" +
                          "Role =" +qry.value(2).toString();

            QMessageBox::warning(this, "Login was successful",msg);

            this->close();

            HomeWindow homewindow;
            homewindow.setModal(true);
            homewindow.exec();

        }else {
            ui->lblResult->setText("[-] Wrong Username and Password");
        }
    }


}
