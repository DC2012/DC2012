#include "Server.h"

Server* Server::instance_ = 0;

void Server::write(Message* message)
{
  if(message->getType() == Message::UPDATE)
  {
    //udpServer_->write(message);
  }
  else
  {
    tcpServer_->write(message);
  }
}

Message* Server::read()//this is currently a blocking call, can  be modified to return null pointer when empty if that helps
{
  return queue_->pop();
}

void Server::updateClientList()
{
  clientMap_ = tcpServer_->getClients();
}
