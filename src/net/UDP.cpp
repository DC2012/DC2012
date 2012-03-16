#include "UDP.h"
#include <iostream>
using namespace std;
UDP* UDP::instance_ = 0;

UDP* UDP::getInstance(BlockingQueue* queue)
{
  if(instance_ == 0)
  {
    instance_ = new UDP(queue);
  }
  return instance_;
}

/*
 * Writes a message to all clients in the passed in address map
 */
void
UDP::write(Message* m, const std::map<int, in_addr>& addresses)
{
    char* message;
    int length;
    std::map<int, in_addr>::const_iterator it;
    cout << "write loop " << addresses.size() << endl;
    message = m->serialize();
    length  = m->getLength() + Message::MSGHEADER;
    for(it = addresses.begin(); it != addresses.end(); it++)
    {
      cout << it->first << " " << ntohl(it->second.s_addr) << endl;
      sendAddress_.sin_addr = it->second;
      sendAddress_.sin_port = addressMap_[it->second.s_addr];
      cout << ntohs(sendAddress_.sin_port) << endl;
      CommWrapper::Write(sockfd, message, length, &sendAddress_);
    }
    delete[] message;
}
/*
 * Write a message to a single client.
 */
void
UDP::write(Message* m, sockaddr_in& address)
{
    char* message;
    int   length;
    message = m->serialize();
    length  = m->getLength() + Message::MSGHEADER;
    CommWrapper::Write(sockfd, message, length, &address);
    delete[] message;
}

bool UDP::startRead(unsigned short port)
{
  if(!CommWrapper::Bind(sockfd, port))
  {
    return false;
  }
  if(pthread_create(&readThreadID_, 0, readThread, 0) != 0)
  {
    return false;
  }
  sendAddress_.sin_family = AF_INET;
  return true;
}

void* UDP::readThread(void* param)
{
  char messageBuffer[Message::MAXMSGSIZE];
  UDP* udp = UDP::getInstance();
  sockaddr_in recvAddress;
  while(CommWrapper::Read(udp->sockfd, messageBuffer, Message::MAXMSGSIZE, &recvAddress))
  {
    udp->addressMap_[recvAddress.sin_addr.s_addr] = recvAddress.sin_port;
    udp->queue_->push(new Message(messageBuffer));
  }
  return 0;
}