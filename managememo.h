#ifndef MANAGEMEMO_H
#define MANAGEMEMO_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class ManageMemo;
}

class ManageMemo : public QDialog
{
    Q_OBJECT

public:
    explicit ManageMemo(QWidget *parent = 0);
    ~ManageMemo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ManageMemo *ui;
};

#endif // MANAGEMEMO_H
