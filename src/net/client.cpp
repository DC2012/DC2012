#include "client.h"

Client::Client()
{
  tcpClient_ = TCPClient::getInstance();
  //udpClient_ = new UDPClient();
  queue_    = new BlockingQueue();
}

Message* Client::read(void)
{
  return queue_->pop();
}
void Client::write(Message* message)
{
  tcpClient_->send(message);
}
bool Client::connectClient(int portNumber, std::string ip_addr)
{  
  if(!tcpClient_->connectClient(portNumber,ip_addr,&sockAddr_,queue_))
  {
    return false;
  }
 // udpClient_.connectClient(&sockAddr_);
  tcpClient_->startReading();
  
  return true;
}
