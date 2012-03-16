#ifndef COMMWRAPPER_H
#define COMMWRAPPER_H
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <strings.h>
#include <stdio.h>
#include <unistd.h>

class CommWrapper
{
  public:
    static bool Read(int sock, void* vptr, size_t size, sockaddr_in* dest = 0);
    static bool Write(int sock, const void* vptr, size_t size, sockaddr_in* dest = 0);
    static bool Bind(int sock, unsigned short port);
    static int  Socket(int type);
    static bool Listen(int sock);
    static int  Accept(int sock, sockaddr_in* address);
  private:
    CommWrapper(){}
    
};
#endif
