#ifndef PICKYOURSHIP_H
#define PICKYOURSHIP_H

#include <QDialog>
#include "../../../net/client.h"

namespace Ui {
class PickYourShip;
}

class PickYourShip : public QDialog
{
    Q_OBJECT
    
public:
    explicit PickYourShip(QWidget *parent = 0);
    ~PickYourShip();
    bool isCreating();
    void setCreating(bool creating);

signals:
    void shipChosen(QString shipType);
    
private slots:
    void on_btnShip1_clicked();
    void on_btnShip2_clicked();
    void on_btnShip3_clicked();

private:
    bool                creating_;
    Ui::PickYourShip*   ui;
    Client*             client_;
};

#endif // PICKYOURSHIP_H
