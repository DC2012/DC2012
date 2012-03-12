#ifndef SERVER_H
#define SERVER_H

#include "TCPServer.h"
#include "Message.h"
#include "BlockingQueue.h"

class Server
{
  public:
    static Server* getInstance()//returns the Server instance from singleton pattern
    {
      if(instance_ == 0)
      {
        instance_ = new Server();
      }
      return instance_;
    }
    Message* read();//this is currently a blocking call, can  be modified to return null pointer when empty if that helps
    void write(Message* message);
    bool listen(unsigned short port);//starts the server listening on the port
    void shutdown();//stops thelisten, closes the entire class down basically
    void updateClientList();
    
  private:
    BlockingQueue* queue_;
    TCPServer* tcpServer_;
    //UDPServer* udpServer_;
    static Server* instance_;
    std::map<int, in_addr> clientMap_;
    Server()
    {
        queue_     = new BlockingQueue;
        tcpServer_ = TCPServer::getInstance(queue_);
        //udpServer_ = UDPServer::getInstance(queue_);
        instance_  = this;
    }    
};

#endif
