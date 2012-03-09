#include "TCPServer.h"
#include "Server.h"

TCPServer* TCPServer::instance_ = 0;

void* TCPServer::startThread(void* param)
{
  TCPServer* server = TCPServer::getInstance(0);
  server->listenRead();
  return 0;
}

void TCPServer::listenRead()
{
  int    maxfd, numReady;
  fd_set readySet;
  
  maxfd = listenSocket_;
  FD_ZERO(&allSet_);
  FD_SET(listenSocket_, &allSet_);
  
  while(true)
  {
    readySet = allSet_;
    numReady = select(maxfd + 1, &readySet, NULL, NULL, NULL);
    if(FD_ISSET(listenSocket_, &readySet))
    {
      addClient(maxfd);
      --numReady;
    }
    if(numReady > 0)
    {
      doRead(numReady, &readySet); 
    }
  }
}

bool TCPServer::startListen(unsigned short port)
{
  if((listenSocket_ = CommWrapper::Socket(SOCK_STREAM)) == -1)
  {
    return false;
  }
  if(!CommWrapper::Bind(listenSocket_, port))
  {
    close(listenSocket_);
    return false; 
  }
  if(!CommWrapper::Listen(listenSocket_))
  {
    close(listenSocket_);
    return false;
  }
  if(pthread_create(&readThread_, 0, &startThread, 0)!= 0)
  {
    close(listenSocket_);
    return false;
  }
  running_ = true;
  return true;
}

void TCPServer::doRead(int numReady, fd_set* pReadySet)
{
  std::map<int, in_addr>::iterator it;
  pthread_mutex_lock(&clientMapMutex_);
  for(it = clientMap_.begin(); it != clientMap_.end(); it++)
  {
    if(FD_ISSET(it->first, pReadySet))
    {
      q_->push(TCPConnection::read(it->first));
      if(--numReady == 0)
      {	
        break; 
      }      
    }
  }
  pthread_mutex_unlock(&clientMapMutex_);
}

void TCPServer::shutdown()
{
  close(listenSocket_);
}

void TCPServer::addClient(int& maxfd)
{
  int newSocket;
  sockaddr_in clientAddress;
  if((newSocket = CommWrapper::Accept(listenSocket_, &clientAddress)) == -1)
  {
    return;
  }
  if(newSocket > maxfd)
  {
    maxfd = newSocket; 
  }
  FD_SET(newSocket, &allSet_);
  pthread_mutex_lock(&clientMapMutex_);
  clientMap_[newSocket] = clientAddress.sin_addr;
  Server::getInstance()->updateClientList();
  pthread_mutex_unlock(&clientMapMutex_);
}

void TCPServer::write(Message* message)
{
  std::map<int, in_addr>::iterator it;
  pthread_mutex_lock(&clientMapMutex_);
  for(it = clientMap_.begin(); it != clientMap_.end(); it++)
  {
    TCPConnection::write(it->first, message);
  }
  pthread_mutex_unlock(&clientMapMutex_);
}

std::map<int, in_addr> TCPServer::getClients()
{
  return clientMap_;
}


