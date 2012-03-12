#include <sys/socket.h>
#include <cstring>
#include <arpa/inet.h>
#include <map>
#include "Message.h"

#define SERV_PORT 8243
#define MAXSIZE 1024

using namespace std;
typedef struct sockaddr_in sockaddr_in; //So we don't have to say "struct"

class UDP {
private:
    int sockfd;
    sockaddr_in sock;
  
public:
  /* Multiple ways to create UDP, all require a socket file descriptor. */
    UDP(int desc);
    UDP(int desc, char* address);
    UDP(int desc, char* address, int port);
    UDP(int desc, int address, int port);
  
    void
    binder();
  
    void
    setPort(int port);
  
    void
    setSock(int sock);
  
    void 
    setAddress(char* address);
    /* To set it to a constant like INADDR_ANY */
    void
    setAddress(int address);
  
    void 
    send(char* msg);
  
    void
    write(Message* m, in_addr address);
  
    void
    write_all(Message* m, std::map<int, in_addr> addresses);
  
    int
    receive(char* result, size_t bufsize);
};