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
    /*---------------------------------------------------------------------------------------------------------------------
    --  METHOD:     setClientID
    --
    --  DATE:       April 10, 2012
    --
    --  REVISIONS:  None
    --
    --  DESIGNER:   Tyler Ingram, Anthony Rachiero
    --
    --  PROGRAMMER: Tyle Ingram, Anthony Rachiero
    --
    --  INTERFACE:  void setClient)
    --
    --  RETURNS:    void
    --
    --  NOTES:      Sets the clients ID from the Server
    --
    ----------------------------------------------------------------------------------------------------------------------*/
    void setClientID(int ID);
    void incomingMsg(std::string);

private:
    Ui::ChatDlg *ui;
    Message *msg_;
    int clientID_;

 public slots:
    /*---------------------------------------------------------------------------------------------------------------------
    --  METHOD:     doChat
    --
    --  DATE:       April 10, 2012
    --
    --  REVISIONS:  None
    --
    --  DESIGNER:   Tyler Ingram, Anthony Rachiero
    --
    --  PROGRAMMER: Tyle Ingram, Anthony Rachiero
    --
    --  INTERFACE:  void doChat()
    --
    --  RETURNS:    void
    --
    --  NOTES:      This method retrieves the text that the user inputs to the line edit text box.
    --              it then sends the chat message to the server so that it can display it
    --              to all other clients in the text field above the line edit box.
    --
    ----------------------------------------------------------------------------------------------------------------------*/
    void doChat();

};

#endif // CHATDLG_H
