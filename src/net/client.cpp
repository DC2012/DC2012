#include "client.h"

Client* Client::instance_ = 0;

using namespace std;


Client* Client::getInstance()
{
  if(instance_ == 0)
  {
    instance_ = new Client();
  }
  return instance_;
}

Client::Client()
{
  queue_     = new BlockingQueue();
  tcpClient_ = TCPClient::getInstance();
  udpClient_ = UDP::getInstance(queue_);

}

Message* Client::read(void)
{
  return queue_->pop();
}
void Client::write(Message* message)
{
  if(message->getType() == Message::UPDATE)
  {
    udpClient_->write(message, sockAddr_);
  }
  else
  {
    tcpClient_->send(message); 
  }
}
bool Client::connectClient(int portNumber, std::string ip_addr)
{  
  if(!tcpClient_->connectClient(portNumber,ip_addr,&sockAddr_,queue_))
  {
    return false;
  }
  udpClient_->startRead(0);
  tcpClient_->startReading();
  
  return true;
}
