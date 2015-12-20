#include "imageviewer.h"
#include "ui_imageviewer.h"
#include "qfiledialog.h"

ImageViewer::ImageViewer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageViewer)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ruwan/Pictures/demo.png");
    ui->label->setPixmap(pix);
}

ImageViewer::~ImageViewer()
{
    delete ui;
}

void ImageViewer::on_pushButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Image (*.png,*.jpg,*.gif,*.xpm)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString filename = QFileDialog::getOpenFileName(this,tr("Open File"), "C:\Users\ruwan\Pictures",tr("Image Files (*.png *.JPG "));
}
