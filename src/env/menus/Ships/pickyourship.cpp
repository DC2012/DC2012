#include "pickyourship.h"
#include "ui_pickyourship.h"

PickYourShip::PickYourShip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PickYourShip)
{
    creating_ = false;
    client_ = Client::getInstance();
    ui->setupUi(this);
}

bool PickYourShip::isCreating()
{
    return creating_;
}

void PickYourShip::setCreating(bool state)
{
    creating_ = state;
}

PickYourShip::~PickYourShip()
{
    delete ui;
}

void PickYourShip::on_btnShip1_clicked()
{
    Message msg;
    msg.setType(Message::RESPAWN);
    msg.setData("1");
    msg.setID(0);

    client_->write(&msg);
    this->hide();
}

void PickYourShip::on_btnShip2_clicked()
{
    Message msg;
    msg.setType(Message::RESPAWN);
    msg.setData("2");
    msg.setID(0);

    client_->write(&msg);
    this->hide();
}

void PickYourShip::on_btnShip3_clicked()
{
    Message msg;
    msg.setType(Message::RESPAWN);
    msg.setData("3");
    msg.setID(0);

    client_->write(&msg);
    this->hide();
}
