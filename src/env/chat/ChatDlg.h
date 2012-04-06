#ifndef CHATDLG_H
#define CHATDLG_H

#include <QDialog>
#include "../../net/Message.h"

namespace Ui {
class ChatDlg;
}

class ChatDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ChatDlg(QWidget *parent = 0, int clientID = 0);
    ~ChatDlg();
    void setClientID(int ID);

private:
    Ui::ChatDlg *ui;
    Message *msg_;
    int clientID_;



 public slots:
    void doChat();
};

#endif // CHATDLG_H
