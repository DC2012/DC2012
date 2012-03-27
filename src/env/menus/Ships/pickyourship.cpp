#include "pickyourship.h"
#include "ui_pickyourship.h"

PickYourShip::PickYourShip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PickYourShip)
{
    ui->setupUi(this);
}

PickYourShip::~PickYourShip()
{
    delete ui;
}

void PickYourShip::on_btnShip1_clicked()
{
    emit shipChosen("Ship1");
    this->close();
}

void PickYourShip::on_btnShip2_clicked()
{
    emit shipChosen("Ship2");
    this->close();
}

void PickYourShip::on_btnShip3_clicked()
{
    emit shipChosen("Ship3");
    this->close();
}
