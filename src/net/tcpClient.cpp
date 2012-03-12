#include "tcpClient.h"

TCPClient* TCPClient::instance_ = 0;

using namespace std;

TCPClient::TCPClient()
{
  socket_   = CommWrapper::Socket(SOCK_STREAM); 
}

TCPClient* TCPClient::getInstance()
{
  if(instance_ == 0)
  {
    instance_ = new TCPClient();
  }
  return instance_;
}

bool TCPClient::connectClient(int portNumber, string ip_addr,sockaddr_in *servaddr, BlockingQueue * queue)
{
  char ip[BUFFSIZE];
  int  error;
  
  strcpy(ip, ip_addr.c_str());
  
  bzero(servaddr, sizeof(sockaddr_in));   // set memory to 0
  servaddr->sin_family = AF_INET;                // set to internet family
  servaddr->sin_port = htons(portNumber);        //set the port
  inet_pton(AF_INET, ip, &servaddr->sin_addr);   //convert to binary form

  if((error = connect(socket_,(sockaddr *) servaddr, sizeof( sockaddr_in))) == -1)
  {
    //cout << "tcpclient connectClient failed" << endl;
    return false;
  }
  
  //cout << "tcpclient connectClient connected" << endl;
  queue_ = queue;
  return true;
}

void TCPClient::send(Message* m)
{
  TCPConnection::write(socket_,m);
  //cout << "tcpclient write called" << endl;
}

void TCPClient::startReading(void)
{
  pthread_create(&thread_,0,readFromPort,0);
  //cout << "tcpclient starting read" << endl;
}

void* TCPClient::readFromPort(void*param)
{
  TCPClient* client = TCPClient::getInstance();
  //cout << "tcpclient doReading called" << endl;
  client->doReading();
  return 0;
}

void TCPClient::doReading(void)
{
  Message *m;
  while((m = TCPConnection::read(socket_)))
  {
     queue_->push(m);
  }
 // cout << "tcpclient doReading done" << endl;
}

void TCPClient::closeClient(void)
{
  shutdown(socket_,SHUT_RDWR);
  close(socket_);
   //cout << "tcpclient close called" << endl;
}