#include "ChatDlg.h"
#include "ui_ChatDlg.h"
#include <QMessageBox>
#include "../../../src/graphics/gamewindow.h"
#include <QPalette>

ChatDlg::ChatDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatDlg)
{
    ui->setupUi(this);
    connect(ui->lineEdit_input, SIGNAL(returnPressed()), this, SLOT(doChat()));

    this->setWindowOpacity(0.8);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

ChatDlg::~ChatDlg()
{
    delete ui;
}

void ChatDlg::doChat()
{

    // This is where we will need to send a Message to server of
    // type CHAT
    GameWindow *p = (GameWindow *) this->parent();
    p->setChatting(false);
    ui->lineEdit_input->setVisible(false);
    this->clearFocus();
    p->setFocus();
    //this->close();

}
