#include "outputt.h"
#include "ui_outputt.h"

Outputt::Outputt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Outputt)
{
    ui->setupUi(this);
}

Outputt::~Outputt()
{
    delete ui;
}
