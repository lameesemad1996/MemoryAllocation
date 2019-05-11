#include "holessinputform.h"
#include "ui_holessinputform.h"

holessinputform::holessinputform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::holessinputform)
{
    ui->setupUi(this);
}

holessinputform::~holessinputform()
{
    delete ui;
}
