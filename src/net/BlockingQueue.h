#ifndef BLOCKINGQUEUE_H
#define BLOCKINGQUEUE_H

#include <queue>
#include <pthread.h>
#include "Semaphore.h"
#include "Message.h"

class BlockingQueue
{
  public:
    BlockingQueue();
    ~BlockingQueue();
    void push(Message* m);
    Message* pop();
    bool empty();
  private:
    std::queue<Message*> q_;
    int cntsemid_;
    pthread_mutex_t queueLock;
};

#endif
