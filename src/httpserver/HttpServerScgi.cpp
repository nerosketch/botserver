/*
 * File:   HttpServerScgi.cpp
 * Author: ns
 * 
 * Created on July 4, 2020, 12:14 AM
 */

#include "../third_party/libscgi/scgi.hpp"
#include "HttpServerScgi.h"

using namespace std;

HttpServerScgi::HttpServerScgi () { }

HttpServerScgi::HttpServerScgi (const HttpServerScgi& orig) { }

HttpServerScgi::~HttpServerScgi () { }



/**
* the user callback handler
*
*/
class Handler1: public IScgiHandler {

	void run(map< string,string > * parms, char * buffUot) {
		string parm = getParam("REQUEST_METHOD",parms);
		// if method is POST
		if ( parm == "POST" ) {
			// return to WEB-client the POST data
			strcpy(buffUot, getParam("POST_DATA",parms).c_str());
			return;
		}
		// or return to WEB-client the QUERY_STRING parameter
		strcpy(buffUot, reinterpret_cast<char*>(userData));
	}
};

int HttpServerScgi::run()
{
    scgiServer scgi;

    if (scgi.checkPid())
      {
        cerr << "the pid file exist or daemon already started\n" << endl;
        return 1;
      }

    // initialize server, bind and listen socket
    if (scgi.init("127.0.0.1", 8082) )
      {
        cerr << "server stopped\n";
        return 1;
      }

    //const char *userData = "user data";

    auto_ptr<Handler1>h1(new Handler1());
    //h1->setUserData( reinterpret_cast<void *>(userData));
    // add specific handlers
    scgi.addHandler("/post", reinterpret_cast<IScgiHandler *>(h1.get()));
//    scgi.addHandler("/xxx",  reinterpret_cast<IScgiHandler *>(new Handler2()));

    scgi.run();

    return 0;
}
