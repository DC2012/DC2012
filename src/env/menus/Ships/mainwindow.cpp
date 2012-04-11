#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dlgconnection.h"
#include "../../../graphics/gamewindow.h"
#include "pickyourship.h"

#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&mDialog, SIGNAL(connect_init(QString, QString, QString)), this, SLOT(connect_accept(QString, QString, QString)));
    client_ = Client::getInstance();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dialog_popup()
{
    mDialog.setModal(true);
    mDialog.exec();
}

void MainWindow::assignShip(QString shipType)
{
    shipType_ = shipType;
}

void MainWindow::connect_accept(QString port, QString ip, QString username)
{
    std::string i;
    int         p;

    i = ip.toUtf8().constData();
    p = port.toInt();

    if (username.contains(" "))
    {
        QMessageBox::information(this, QString("Invalid Username"), QString("Spaces are not allowed in username"));
        return;
    }

    #ifdef DEBUG
        username = "tester";
        p = 9900;
        i = "127.0.0.1";
    #endif

    if (client_->connectClient(p, i))
    {
        mDialog.close();
        this->hide();
        PickYourShip shipDialog;
        connect(&shipDialog, SIGNAL(shipChosen(QString)), this, SLOT(assignShip(QString)));
        shipDialog.exec();

        Message msg;
        msg.setID(0);
        msg.setType(Message::CONNECTION);
        msg.setData(username.toStdString());

        client_->write(&msg);

        GameWindow *gameWindow = new GameWindow();
        gameWindow->setFocus();
        gameWindow->start();
    }
    else
    {
        QMessageBox::information(this, QString("Connection Error"), QString("Unable to connect to server. Please check your connection settings."));
    }
}

