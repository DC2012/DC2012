#include "dlgconnection.h"
#include "ui_dlgconnection.h"
#include "QMessageBox"

using namespace std;

DlgConnection::DlgConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgConnection)
{
    ui->setupUi(this);
}

DlgConnection::~DlgConnection()
{
    delete ui;
}

/*
string DlgConnection::getPort()
{
    return;

}

string DlgConnection::getIP()
{
    return;
}

void DlgConnection::on_pushButton_Connect()
{
    QMessageBox mBox;

    mBox.setText("Woo did something");
    mBox.exec();
}
*/
