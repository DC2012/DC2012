#include "TCPConnection.h"
Message* TCPConnection::read(int sock)
{
  char message[Message::MAXMSGSIZE];
  if(!CommWrapper::Read(sock, message, Message::MSGHEADER))//read Message header
  {
    return 0;
  }
  if(!CommWrapper::Read(sock, message + Message::MSGHEADER, message[0]))//read the rest of the message
  {
    return  0;
  }
  Message* m = new Message(message);
  return m;
}

void TCPConnection::write(int sock, Message* m)
{
  char* message = m->serialize();
  CommWrapper::Write(sock, message, m->getLength() + Message::MSGHEADER);
  delete [] message;
}
