#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h> 
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <string>
#include <stdio.h>

#include "CommWrapper.h"
#include "TCPConnection.h"
#include "Message.h"
#include "BlockingQueue.h"

#define BUFFSIZE 1024


/*---------------------------------------------------------------------------------------------------------------------
--  
--  SOURCE FILE: TCPClient.cpp
--
--  PROGRAM:     Linux Game
--
--
--  MEMBER FUNCTIONS:  
--
--		public:
--			  static Client*   getInstance()
--			  void  	   connectClient(int portNumber, std::string ip)
--			  void  	   send(Message* m)
--			  void  	   receive(void)
--			  void*            readFromPort(void*)
--			  void 		   startReading(void)
--			  void 		   doReading(void)
--			  void 		   close(void)
-- 
--  MEMBERS:  
--
--		private:
--			  int              socket_       : the socket that will be read from and written to.				
--			  TCPConnection*   connection_   : an object that contains the functions to read from a port and write to a port.
--			  static Client*   instance_     : the instance of the class(returned by getInstance() to use the object)
--			  pthread_t	   thread_;      : the thread used to call the doRead() function
--			  BlockingQueue*   queue_;       : the queue that holds all messages waiting to be read
--
-- CONSTRUCTOR(S):
--
--		private:
--			  TCPClient()
--
--  DATE:        March 6, 2012
--
--  DESIGNER:    James Rupert, Kendra Kohler
--
--  PROGRAMMER:  Kendra Kohler
--
--  NOTES:       The TCPClient class is used by the Client class to connect to, write to, read from and shut down a 
--		 socket. It is a singleton design to ease the use of a thread for reading. 
--
--
----------------------------------------------------------------------------------------------------------------------*/

class TCPClient
{
public:
  
/*---------------------------------------------------------------------------------------------------------------------
--  METHOD:     getInstance
--
--  DATE:       March 6, 2012
--
--  REVISIONS:  None
--
--  DESIGNER:   Kendra Kohler, James Rupert
--
--  PROGRAMMER: Kendra Kohler
--
--  INTERFACE:  static Client* getInstance()
--
--  RETURNS:    a pointer to the TCPClient object
--
--  NOTES:      This method checks to see if the instance_ member(the only pointer to the object) is null and if it 
--		isn't, it creates the object. Once this check is done, it returns the instance_.
--
----------------------------------------------------------------------------------------------------------------------*/
  static TCPClient* getInstance(void);
  
/*---------------------------------------------------------------------------------------------------------------------
--  METHOD:     connectClient
--
--  DATE:       March 6, 2012
--
--  REVISIONS:  None
--
--  DESIGNER:   Kendra Kohler
--
--  PROGRAMMER: Kendra Kohler
--
--  INTERFACE:  bool TCPClient::connectClient(int,string,struct sockaddr_in*,BlockingQueue*)
--
--			int:	     	      the port number being used for the socket.
--			string:		      the ip address
--			struct sockaddr_in*:  the struct that will have the information for the socket assigned to it.
--			BlockingQueue*:	      the pointer to the queue that will be used to store all messages 
--					      needing to be read.
--
--  RETURNS:    true if the connection is successful, false if it isn't
--
--  NOTES:      This method initializes the sockaddr_in struct and attempts to connect to the socket.
--
----------------------------------------------------------------------------------------------------------------------*/
  bool connectClient(int portNumber, std::string ip_addr, sockaddr_in *servaddr, BlockingQueue * queue);
  
/*---------------------------------------------------------------------------------------------------------------------
--  METHOD:     send
--
--  DATE:       March 6, 2012
--
--  REVISIONS:  None
--
--  DESIGNER:   Kendra Kohler
--
--  PROGRAMMER: Kendra Kohler
--
--  INTERFACE:  void send(Message*)
--
--			Message*: a pointer to the Message object to be sent.
--
--
--  RETURNS:    void
--
--  NOTES:      This method takes a Message object and sends it using the TCPConnection object method called write.
--
----------------------------------------------------------------------------------------------------------------------*/
  void send(Message* m);
  
/*---------------------------------------------------------------------------------------------------------------------
--  METHOD:     startReading
--
--  DATE:       March 7, 2012
--
--  REVISIONS:  None
--
--  DESIGNER:   Kendra Kohler
--
--  PROGRAMMER: Kendra Kohler
--
--  INTERFACE:  void startReading(void)
--
--  RETURNS:    void
--
--  NOTES:      This method starts the thread readFromPort
--
----------------------------------------------------------------------------------------------------------------------*/
  void startReading(void);
  
/*---------------------------------------------------------------------------------------------------------------------
--  METHOD:     readFromPort
--
--  DATE:       March 7, 2012
--
--  REVISIONS:  None
--
--  DESIGNER:   Kendra Kohler, James Rupert
--
--  PROGRAMMER: Kendra Kohler
--
--  INTERFACE:  void* readFromPort(void*)
--
--			void*: this parameter is not used, just provided to satisfy the requirements of a thread.
--
--  RETURNS:    an int to satisfy the requirements for a thread
--
--  NOTES:      readFromPort is used to get the instance_ of the object and call the doReading method of it. It was 
--		implemented this way because threads can't take objects and can't use them unless they are static
--		(threads in objects have to be static). Once the thread gets the instance_ it calls it's doReading
--		method so it will not block because it is in a thread but it is still run as a normal method.
--
----------------------------------------------------------------------------------------------------------------------*/
  static void* readFromPort(void*);
  
/*---------------------------------------------------------------------------------------------------------------------
--  METHOD:     doReading
--
--  DATE:       March 7, 2012
--
--  REVISIONS:  None
--
--  DESIGNER:   Kendra Kohler, James Rupert
--
--  PROGRAMMER: Kendra Kohler
--
--  INTERFACE:  void doReading(void)
--
--  RETURNS:    void
--
--  NOTES:      loops and reads using the TCPConnection class read. When something is read, it is pushed on the queue
--		to wait to be read.
--
----------------------------------------------------------------------------------------------------------------------*/
  void doReading(void);
  
  /*---------------------------------------------------------------------------------------------------------------------
--  METHOD:     close
--
--  DATE:       March 7, 2012
--
--  REVISIONS:  None
--
--  DESIGNER:   Kendra Kohler
--
--  PROGRAMMER: Kendra Kohler
--
--  INTERFACE:  void closeClient(void)
--
--  RETURNS:    void
--
--  NOTES:      closes the socket and cancels the thread.
--
----------------------------------------------------------------------------------------------------------------------*/
  void closeClient(void);
  
private:
		      TCPClient();
  int                 socket_; 
  static TCPClient*   instance_;
  pthread_t	      thread_;
  BlockingQueue*      queue_;
};

#endif