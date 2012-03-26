#include "ChatDlg.h"
#include "ui_ChatDlg.h"

ChatDlg::ChatDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatDlg)
{
    ui->setupUi(this);
}

ChatDlg::~ChatDlg()
{
    delete ui;
}
