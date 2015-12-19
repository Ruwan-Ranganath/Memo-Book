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

    void on_btnDelete_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::ManageMemo *ui;
};

#endif // MANAGEMEMO_H
