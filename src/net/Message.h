#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <string.h>
class Message
{
public:
  enum MessageType { 
	CHAT, 
	CREATION, 
	DELETION, 
	UPDATE, 
	ACTION, 
	STATUS
  };
  static const size_t MAXMSGDATA = 254;
  static const size_t MSGHEADER  = 3;
  static const size_t MAXMSGSIZE = MAXMSGDATA + MSGHEADER;
  Message(unsigned char clientID = 0);
  Message(const char* message);
  MessageType getType();
  std::string getData();
  size_t getLength();
  bool setData(const std::string& data);
  void setType(MessageType type);
  bool setAll(const std::string& data, MessageType type);
  char* serialize();
private:
  unsigned char length_;
  unsigned char clientID_;
  MessageType messageType_;
  std::string data_;
};

#endif
