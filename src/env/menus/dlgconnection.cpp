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

    setUsername(ui->lineUsername->text());
    setIP(ui->lineServerIP->text());
    setPort(ui->lineServerPort->text());

    mBox.setText("This is where we Connec to server");
    mBox.exec();

}
/* Setters
*   Will probably want to do Data Validation here too
*/
void DlgConnection::setUsername(QString name)
{
    this->username = name;
}
void DlgConnection::setPort(QString port)
{
    this->server_port = port;
}
void DlgConnection::setIP(QString ip)
{
    this->server_addr = ip;
}

/* Getters
* Returns the values that are stored in the DlgConnection class
*/

QString DlgConnection::getUsername()
{
    return this->username;
}

QString DlgConnection::getIP()
{
    return this->server_addr;
}

QString DlgConnection::getPort()
{
    return this->server_port;
}

