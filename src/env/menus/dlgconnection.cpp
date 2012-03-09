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

/* This is where we will pull the user's info from
  IP, Port and Username
*/
void DlgConnection::connectTo()
{
    /* remove this whenever */
    QMessageBox mBox;

    mBox.setText("Woo did something");
    mBox.exec();
}

