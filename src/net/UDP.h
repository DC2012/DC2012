#include <sys/socket.h>
#include <cstring>
#include <arpa/inet.h>
#include <map>
#include "Message.h"
#include "BlockingQueue.h"
#include "CommWrapper.h"

#define SERV_PORT 8243
#define MAXSIZE 1024

class UDP {
private:
    int sockfd;
    sockaddr_in sendAddress_;
    BlockingQueue* queue_;
    std::map<uint32_t, unsigned short> addressMap_;
    static UDP* instance_;
    pthread_t readThreadID_;
    UDP(BlockingQueue* queue):queue_(queue)
    {
      sockfd = CommWrapper::Socket(SOCK_DGRAM);
    }
    static void* readThread(void* param);
  
public:
  
    void
    write(Message* m, sockaddr_in& address);
    
    void
    write(Message* m, in_addr address);
  
    void
    write(Message* m, const std::map<int, in_addr>& addresses);

    bool startRead(unsigned short port = 0);

    static UDP* getInstance(BlockingQueue* queue = 0);
};