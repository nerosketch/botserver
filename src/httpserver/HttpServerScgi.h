/*
 * File:   HttpServerScgi.h
 * Author: ns
 *
 * Created on July 4, 2020, 12:14 AM
 */

#ifndef HTTPSERVERSCGI_H
#define HTTPSERVERSCGI_H

class HttpServerScgi
{
public:
  HttpServerScgi ();
  HttpServerScgi (const HttpServerScgi& orig);
  virtual ~HttpServerScgi ();
  
  int run();
private:

};

#endif /* HTTPSERVERSCGI_H */
