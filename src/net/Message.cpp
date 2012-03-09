#include "Message.h"

Message::Message(unsigned char clientID):clientID_(clientID){}

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
  result[0] = (char)length_;
  result[1] = (char)clientID_;
  result[2] = (char)messageType_;
  strcpy(result + 3, data_.c_str());
  return result;
}

Message::Message(const char* message):length_((unsigned char) message[0]),
                                      clientID_((unsigned char) message[1]), 
                                      messageType_((MessageType) message[2]),
                                      data_(message + 3){}
