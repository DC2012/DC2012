#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <map>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <pthread.h>
#include <queue>
#include <iostream>
#include <signal.h>
#include "Message.h"
#include "TCPConnection.h"
#include "BlockingQueue.h"
#include "CommWrapper.h"

class TCPServer
{
  public:
    bool startListen(unsigned short port);
    void write(Message* message);
    void write(Message* message, int clientID);    
    void shutdown();
    std::map<int, in_addr> getClients();
    static TCPServer* getInstance(BlockingQueue* q)
    {
      if(instance_ == 0)
      {
        instance_ = new TCPServer(q);
      }
      return instance_;
    }
  private:
    TCPServer(BlockingQueue* q):running_(false), q_(q)
    {
      pthread_mutexattr_init(&attr_);
      pthread_mutexattr_settype(&attr_, PTHREAD_MUTEX_RECURSIVE);
      pthread_mutex_init(&clientMapMutex_, &attr_);
    }
    static void* startThread(void* param);
    void listenRead();
    void addClient();
    void doRead(int, fd_set*);
    void removeClient(int clientID);
    
    
    static TCPServer* instance_;
    std::map<int, in_addr> clientMap_;
    fd_set allSet_;
    int listenSocket_, maxfd_;
    bool running_;
    BlockingQueue* q_;
    pthread_t readThread_;
    pthread_mutex_t clientMapMutex_;
    pthread_mutexattr_t attr_; 
    
};


#endif
