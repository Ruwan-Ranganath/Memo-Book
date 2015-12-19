#ifndef NEWMEMO_H
#define NEWMEMO_H

#include <QDialog>

namespace Ui {
class NewMemo;
}

class NewMemo : public QDialog
{
    Q_OBJECT

public:
    explicit NewMemo(QWidget *parent = 0);
    ~NewMemo();

private:
    Ui::NewMemo *ui;
};

#endif // NEWMEMO_H
