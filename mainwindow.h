#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>

#include <QMainWindow>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
#include <QtSql/QSqlDriver>
#include <QSql>
#include <QSqlDatabase>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>


#include "homewindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnClear_clicked();

    void on_btnClose_clicked();

    void on_btnLogin_clicked();

private:
    Ui::MainWindow *ui;

    QSqlDatabase myDB;



};

#endif // MAINWINDOW_H
