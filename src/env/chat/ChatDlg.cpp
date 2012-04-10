/*****************************************************************
-- CLASS:       ChatDlg
--
-- DATE:        FEB/MAR 2012
--
-- DESIGNER:    Tyler Ingram
--
-- PROGRAMMER:  Tyler Ingram
--              Anthony Rachiero
--
--
--
--
--
--
--
--
--
--
******************************************************************/


#include "ChatDlg.h"
#include "ui_ChatDlg.h"
#include <QMessageBox>
#include "../../../src/graphics/gamewindow.h"
#include <QPalette>
#include "../../net/client.h"

ChatDlg::ChatDlg(QWidget *parent, int clientID) :
    QDialog(parent),
    clientID_(clientID),
    ui(new Ui::ChatDlg)
{

    ui->setupUi(this);
    connect(ui->lineEdit_input, SIGNAL(returnPressed()), this, SLOT(doChat()));

    this->setWindowOpacity(0.8);
    this->setWindowFlags(Qt::FramelessWindowHint);

    msg_ = new Message();
    msg_->setType(Message::CHAT);
    msg_->setID(clientID_);

}

ChatDlg::~ChatDlg()
{
    delete ui;
}

void ChatDlg::doChat()
{
    Client * client = Client::getInstance();

    // This is where we will need to send a Message to server of
    // type CHAT
    GameWindow *p = (GameWindow *) this->parent();
    p->setChatting(false);
    ui->lineEdit_input->setVisible(false);

    msg_->setData(ui->lineEdit_input->text().toStdString());
    this->clearFocus();
    p->setFocus();
    client->write(msg_);
    //this->close();

}

void ChatDlg::setClientID(int ID)
{
    clientID_ = ID;
}
