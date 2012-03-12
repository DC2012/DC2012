#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <stdlib.h>

#include "Message.h"
#include "CommWrapper.h"

class TCPConnection
{
  public:
    static void write(int sock, Message* m);
    static Message* read(int sock);
  private:
    TCPConnection(){}
};

#endif
