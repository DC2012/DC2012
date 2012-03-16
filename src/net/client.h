#ifndef CLIENT_H
#define CLIENT_H

#define BUFFSIZE 1024
#define PORT 7000
#include "Message.h"
#include "tcpClient.h"
#include "UDP.h"

/*---------------------------------------------------------------------------------------------------------------------
--  
--  SOURCE FILE: client.cpp
--
--  PROGRAM:     Linux Game
--
--
--  MEMBER FUNCTIONS:  
--
--		public:
--			  Message* read(void)
--			  void write(Message* message)
--			  bool connectClient(int portNumber, std::string ip_addr)
-- 
--  MEMBERS:   
--		private:
--			  TCPClient* 	   tcpClient_    : the object to handle any TCP client functionality.				
--			  UDPClient*   	   udpClient_    : the object to handle any UDP client functionality.	
--			  BlockingQueue*   queue_        : the queue that holds all messages waiting to be read
--			  sockaddr_in *    sockAddr_     : the structure that holds connect information to connect in TCP and 
--							   bind in UDP.
--
--
-- CONSTRUCTOR(S):
--
--		public:
--			Client()
--			
--
--  DATE:        March 8, 2012
--
--  DESIGNER:    Kendra Kohler, James Rupert
--
--  PROGRAMMER:  Kendra Kohler
--
--  NOTES:       The Client class is  used by other non-networking objects to use the basic calls of connect, read 
--		 and write. 
--
----------------------------------------------------------------------------------------------------------------------*/

class Client
{
public:
  Client();
  
/*---------------------------------------------------------------------------------------------------------------------
--  METHOD:     read
--
--  DATE:       March 8, 2012
--
--  REVISIONS:  None
--
--  DESIGNER:   Kendra Kohler
--
--  PROGRAMMER: Kendra Kohler
--
--  INTERFACE:  Message* read(void)
--
--  RETURNS:    a pointer to the Message that was read.
--
--  NOTES:      This method returns a message that is popped off the message queue.
--
----------------------------------------------------------------------------------------------------------------------*/
  Message* read(void);
  
/*---------------------------------------------------------------------------------------------------------------------
--  METHOD:     write
--
--  DATE:       March 8, 2012
--
--  REVISIONS:  None
--
--  DESIGNER:   Kendra Kohler
--
--  PROGRAMMER: Kendra Kohler
--
--  INTERFACE:  void write(Message* message)
--
--  RETURNS:    void
--
--  NOTES:      This method checks if a message should be sent by UDP or TCP and then sends it using the proper 
--		protocol.
--
----------------------------------------------------------------------------------------------------------------------*/
  void write(Message* message);
  
  
/*---------------------------------------------------------------------------------------------------------------------
--  METHOD:     connectClient
--
--  DATE:       March 8, 2012
--
--  REVISIONS:  None
--
--  DESIGNER:   Kendra Kohler
--
--  PROGRAMMER: Kendra Kohler
--
--  INTERFACE:  bool connectClient(int portNumber, std::string ip_addr)
--
--  RETURNS:    true if connection is successful, false otherwise
--
--  NOTES:      This tries to connect via TCP and UDP and returns false if either fails.
--
----------------------------------------------------------------------------------------------------------------------*/
  bool connectClient(int portNumber, std::string ip_addr);
  
private:
  TCPClient* tcpClient_;
  UDP* udpClient_;
  BlockingQueue* queue_;
  sockaddr_in sockAddr_;
};

#endif