#include "UDP.h"
/*
 * Multiple constructors for multiple scenarios.
 * 
 * This first one only takes the socket descriptor,
 * mostly for reading from an unknown client.
 */
UDP::UDP(int desc) : sockfd(desc)
{
    bzero(&sock, sizeof(sock));
    sock.sin_family = AF_INET;
}
/*
 * Takes socket descriptor and a specific address
 * to read/write from.
 */
UDP::UDP(int desc, char* address) : sockfd(desc)
{
    bzero(&sock, sizeof(sock));
    sock.sin_family = AF_INET;
    setAddress(address);
    setPort(SERV_PORT);
}
/*
 * Takes socket descriptor and a specific address
 * and specific port number
 */
UDP::UDP(int desc, char* address, int port) : sockfd(desc)
{
    bzero(&sock, sizeof(sock));
    sock.sin_family = AF_INET;
    setAddress(address);
    setPort(port);
}
/*
 * Same as previous one, but takes the address in the
 * form of an integer. This is so that the programmer can
 * specify an option like INADDR_ANY
 */
UDP::UDP(int desc, int address, int port) : sockfd(desc)
{
    bzero(&sock, sizeof(sock));
    sock.sin_family = AF_INET;  
    setAddress(address);
    setPort(port);
}
/*
 * Simply calls the bind function to bind the socket.
 */
void
UDP::binder()
{
    bind(sockfd, (sockaddr*)&sock, sizeof(sock));
}
/*
 * Simply sets the port to a in the sockaddr_in struct
 * after calling htons() on it.
 */
void
UDP::setPort(int port)
{
    sock.sin_port = htons(port);
}
/*
 * Sets the IP address to send/receive from taken
 * from a string.
 */
void 
UDP::setAddress(char* address)
{
    inet_pton(AF_INET, address, &sock.sin_addr);
}
/*
 * Sets the IP address to send/receive from taken
 * from a 32-bit unsigned int. This is mostly here for
 * options such as INADDR_ANY to be able to be used.
 */
void
UDP::setAddress(int address)
{
    sock.sin_addr.s_addr = htonl(address);
}
/* 
 * Changes the socket to run send/receive with.
 */
void
UDP::setSock(int sock)
{
    sockfd = sock;
}
/*
 * Simply sends a message taken from a string object.
 * 
 * NOTE: Since these functions are orignally C functions,
 * we must call string->data() in order to get the char*
 * form.
 * 
 * NOTE: We will change this later so it takes a Message
 * object rather than a string.
 */
void 
UDP::send(char* msg)
{
    sendto(sockfd, msg, Message::MAXMSGSIZE, 0, (sockaddr*)&sock, sizeof(sock));
}
/*
 * Writes a message to all clients in the passed in address map
 */
void
UDP::write_all(Message* m, std::map<int, in_addr> addresses)
{
    char* message;
    std::map<int, in_addr>::iterator it;
  
    message = m->serialize();
    for(it = addresses.begin(); it != addresses.end(); it++)
    {
      UDP::setAddress(it->second.s_addr);
      UDP::send(message);
    }
    delete[] message;
}
/*
 * Write a message to a single client.
 */
void
UDP::write(Message* m, in_addr address)
{
    char* message;
    message = m->serialize();
    UDP::setAddress(address.s_addr);
    UDP::send(message);
    delete[] message;
}
/* 
 * Receives a datagram from the UDP socket and stores it in
 * the string pointed to by "result".
 * 
 * Returns the number of bytes of data read into the string.
 */
int
UDP::receive(char* result, size_t bufsize)
{
    socklen_t len;
    int n;
  
    len = sizeof(sock);
  
    n = recvfrom(sockfd, result, bufsize, 0, (sockaddr*)&sock, &len);
    return n;
}