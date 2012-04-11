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
    CONNECTION,
    DEATH,
    DELETION,
    UPDATE,
    ACTION,
    STATUS,
    HIT,
    RESPAWN
  };
  static const size_t MAXMSGDATA = 254;
  static const size_t MSGHEADER;
  static const size_t MAXMSGSIZE;
  Message(int clientID = 0);
  Message(const char* message);
  MessageType getType();
  std::string getData();
  int getID();
  size_t getLength();
  void setID(int id);
  bool setData(const std::string& data);
  void setType(MessageType type);
  bool setAll(const std::string& data, MessageType type);
  char* serialize();
private:
  unsigned char length_;
  int           clientID_;
  MessageType   messageType_;
  std::string   data_;
};

#endif
