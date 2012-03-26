#include "ChatDlg.h"
#include "ui_ChatDlg.h"
#include <QMessageBox>

ChatDlg::ChatDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatDlg)
{
    ui->setupUi(this);

    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(doChat()));
}

ChatDlg::~ChatDlg()
{
    delete ui;
}

void ChatDlg::doChat()
{
    QMessageBox mb;
    mb.setText("Stuff!");
    mb.exec();

    this->close();

}
