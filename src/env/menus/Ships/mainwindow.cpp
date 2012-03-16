#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dlgconnection.h"
#include "../../../graphics/gamewindow.h"

#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    client_ = Client::getInstance();
    /* connecting signal to slot to pass in port and ip settings */
    connect(&mDialog, SIGNAL(connect_init(QString, QString)), this, SLOT(connect_accept(QString, QString)));
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

void MainWindow::connect_accept(QString port, QString ip)
{
    std::string i;
    int         p;

    i = ip.toUtf8().constData();
    p = port.toInt();

    //if (client_->connectClient(p, i))
    //{
        GameWindow *gameWindow = new GameWindow();
        gameWindow->setFocus();
        gameWindow->show();

        mDialog.close();
        this->hide();
    //}
}

