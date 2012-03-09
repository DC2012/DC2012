#include "CommWrapper.h"

bool CommWrapper::Write(int sock, const void *vptr, size_t n)
{
  size_t nleft = n;
  ssize_t nwritten;
  char* buff = (char*) vptr;
  
  while (nleft > 0)
  {
    if ( (nwritten = write(sock, buff, nleft)) <= 0)
    {
      return false;
    }
    
    nleft -= nwritten;
    buff  += nwritten;
  }
  return true;
}

bool CommWrapper::Read(int sock, void *vptr, size_t size)
{
  size_t  nleft = size;
  ssize_t nread;
  char* buff = (char*) vptr;
  
  while (nleft > 0)
  {
    if ( (nread = read(sock, buff, nleft)) < 0)
    {
      return false;
    }
    if (nread == 0)
      return false;
    
    nleft -= nread;
    buff  += nread;
  }
  return true;
}

int CommWrapper::Socket(int type)
{
  int sock, arg = 1;
  if((sock = socket(AF_INET, type, 0)) == -1)
  {
    //error handling
    return -1;
  }
  if(setsockopt (sock, SOL_SOCKET, SO_REUSEADDR, &arg, sizeof(arg)) == -1)
  {
    //error handling
    return -1;
  }  
  return sock;
}

bool CommWrapper::Bind(int sock, unsigned short port)
{
  struct sockaddr_in server;
  bzero((char *)&server, sizeof(struct sockaddr_in));
  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  server.sin_addr.s_addr = htonl(INADDR_ANY);
  
  if (bind(sock, (struct sockaddr *)&server, sizeof(server)) == -1)
  {
      //error handling
      return false;
  }
  return true;
}

bool CommWrapper::Listen(int sock)
{
  if(listen(sock, 3) == -1)
  {
    //error handling
    return false;
  }
  return true;
}

int CommWrapper::Accept(int sock, sockaddr_in* address)
{
  int newSocket;
  socklen_t length = sizeof(*address);
  if((newSocket = accept(sock, (sockaddr*)address, &length)) == -1)
  {
    //error handling
  }
  return newSocket;
}