#include "holesinputform.h"
#include "ui_inputform.h"

inputform::inputform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inputform)
{
    ui->setupUi(this);
}

inputform::~inputform()
{
    delete ui;
}
