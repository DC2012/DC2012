#include "Message.h"
const size_t Message::MSGHEADER = sizeof(Message::length_) + sizeof(Message::clientID_) + sizeof(char);
const size_t Message::MAXMSGSIZE = Message::MAXMSGDATA + Message::MSGHEADER;
Message::Message(int clientID):clientID_(clientID){}

std::string Message::getData()
{
  return data_;
}

void Message::setType(MessageType type)
{
  messageType_ = type;
}

bool Message::setData(const std::string& data)
{
  if(data.size() > MAXMSGDATA)
  {
    return false;
  }
  data_ = data;
  length_ = data.size() + 1;
  return true;
}

Message::MessageType Message::getType()
{
  return messageType_;
}

size_t Message::getLength()
{
  return length_;
}

bool Message::setAll(const std::string& data, MessageType type)
{
  if(!setData(data))
  {
    return false;
  }
  setType(type);
  return true;
}

char* Message::serialize()
{
  char* result = new char[MSGHEADER + length_];
  memcpy(result, &length_, sizeof(length_));
  memcpy(result + sizeof(length_), &clientID_, sizeof(clientID_));
  result[sizeof(length_) + sizeof(clientID_)] = (char)messageType_;
  strcpy(result + sizeof(length_) + sizeof(clientID_) + sizeof(char), data_.c_str());
  return result;
}

Message::Message(const char* message):length_((unsigned char) message[0]),
                                      messageType_((MessageType) message[sizeof(length_) + sizeof(clientID_)]),
                                      data_(message + sizeof(length_) + sizeof(clientID_) + sizeof(char))
{
  clientID_ = *((int*)(message + sizeof(length_)));
}

int Message::getID()
{
  return clientID_;
}

void Message::setID(int id)
{
  clientID_ = id;
}
