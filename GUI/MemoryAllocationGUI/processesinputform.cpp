#include "processesinputform.h"
#include "ui_processesinputform.h"

processesinputform::processesinputform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::processesinputform)
{
    ui->setupUi(this);
}

processesinputform::~processesinputform()
{
    delete ui;
}
