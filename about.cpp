#include "about.h"
#include "ui_about.h"
#include "global.h"
#include <QString>

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);

    ui->lblBIOSserial->setText(Global::getBIOSserial());
}

About::~About()
{
    delete ui;
}
