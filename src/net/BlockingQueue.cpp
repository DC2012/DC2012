#include "BlockingQueue.h"

BlockingQueue::BlockingQueue()
{
  key_t cntkey;
  if((cntkey = ftok(".", (int)getpid())) == -1)
  {
    throw "cntkey ftok failed";
  }
  if((cntsemid_ = initsem(cntkey, 0)) == -1)
  {
    throw "cnt initsem failed";
  }
  pthread_mutex_init(&queueLock, 0);
}

BlockingQueue::~BlockingQueue()
{
  pthread_mutex_lock(&queueLock);//wait till not in use
  while(!q_.empty())//remove all messages
  {
    delete q_.front();
    q_.pop();
  }
  pthread_mutex_unlock(&queueLock);
  pthread_mutex_destroy(&queueLock);
  closeSem(cntsemid_);
}

void BlockingQueue::push(Message* m)
{
  pthread_mutex_lock(&queueLock);//get queue lock
  q_.push(m);
  V(cntsemid_); //increment message count
  pthread_mutex_unlock(&queueLock); //release queue lock
}

Message* BlockingQueue::pop()
{
  Message* result;
  P(cntsemid_); //decrement message count, block at 0
  pthread_mutex_lock(&queueLock); //get queue lock
  if(q_.size() == 0)
  {
    result = 0; 
  }
  else
  {
    result = q_.front(); // set to to first element
    q_.pop(); //remove front of queue
  }
  pthread_mutex_unlock(&queueLock); //release queue lock
  return result;
}