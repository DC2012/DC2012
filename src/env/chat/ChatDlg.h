#ifndef CHATDLG_H
#define CHATDLG_H

#include <QDialog>

namespace Ui {
class ChatDlg;
}

class ChatDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ChatDlg(QWidget *parent = 0);
    ~ChatDlg();

private:
    Ui::ChatDlg *ui;
};

#endif // CHATDLG_H
