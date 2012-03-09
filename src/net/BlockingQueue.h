#ifndef BLOCKINGQUEUE_H
#define BLOCKINGQUEUE_H

#include <queue>
#include "Semaphore.h"
#include "Message.h"

class BlockingQueue
{
  public:
    BlockingQueue();
    ~BlockingQueue();
    void push(Message* t);
    Message* pop();
    bool empty();
  private:
    std::queue<Message*> q_;
    int binsemid_, cntsemid_;
};

#endif
