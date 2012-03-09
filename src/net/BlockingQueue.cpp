#include "BlockingQueue.h"

BlockingQueue::BlockingQueue()
{
  key_t cntkey, binkey;
  if((cntkey = ftok(".", 'a')) == -1)
  {
    throw "cntkey ftok failed";
  }
  if((binkey = ftok(".", 'b')) == -1)
  {
    throw "binkey ftok failed";
  }
  if((cntsemid_ = initsem(cntkey)) == -1)
  {
    throw "cnt initsem failed";
  }
  if((binsemid_ = initsem(binkey)) == -1)
  {
    throw "bin initsem failed";
  }
  V(binsemid_);
}

BlockingQueue::~BlockingQueue()
{
  P(binsemid_);//wait till not in use
  while(!q_.empty())//remove all messages
  {
    delete q_.front();
    q_.pop();
  }
  closeSem(binsemid_);
  closeSem(cntsemid_);
}

void BlockingQueue::push(Message* t)
{
  P(binsemid_);//get queue lock
  q_.push(t);
  V(cntsemid_); //increment message count
  V(binsemid_); //release queue lock
}

Message* BlockingQueue::pop()
{
  P(cntsemid_); //decrement message count, block at 0
  P(binsemid_); //get queue lock
  Message* t(q_.front()); // set to to first element
  q_.pop(); //remove front of queue
  V(binsemid_); //release queue lock
  return t;
}