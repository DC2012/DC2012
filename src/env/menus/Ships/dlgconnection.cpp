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
*   This is where we will pull the user's info for
*   IP, Port and Username
*/
void DlgConnection::connectTo()
{
    emit connect_init(ui->lineServerPort->text(), ui->lineServerIP->text(), ui->lineUsername->text());
}

