/*
 * File:   HttpServerScgi.cpp
 * Author: ns
 *
 * Created on July 4, 2020, 12:14 AM
 */

#include "../third_party/libscgi/scgi.hpp"
#include "../GameConfig.h"
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
	void dispatch(RequestParamsMap& params, char *buffUot) {
		const string& parm = getParam("REQUEST_METHOD", params);

                addHeader("content-type: application/json");

                /*
                 * Example of params:
Param: CONTENT_LENGTH [0]
Param: CONTENT_TYPE []
Param: DOCUMENT_ROOT [/var/www/html]
Param: DOCUMENT_URI [/post]
Param: HTTP_ACCEPT [text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*\/*;q=0.8,application/signed-exchange;v=b3;q=0.9]
Param: HTTP_ACCEPT_ENCODING [gzip, deflate, sdch, br]
Param: HTTP_ACCEPT_LANGUAGE [ru,en;q=0.9]
Param: HTTP_CONNECTION [keep-alive]
Param: HTTP_HOST [localhost]
Param: HTTP_SEC_FETCH_MODE [same-origin]
Param: HTTP_SEC_FETCH_SITE [same-origin]
Param: HTTP_UPGRADE_INSECURE_REQUESTS [1]
Param: HTTP_USER_AGENT [Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.136 YaBrowser/20.2.3.320 (beta) Yowser/2.5 Safari/537.36]
Param: POST_DATA []
Param: QUERY_STRING []
Param: REMOTE_ADDR [::1]
Param: REMOTE_PORT [38154]
Param: REQUEST_METHOD [GET]
Param: REQUEST_SCHEME [http]
Param: REQUEST_URI [/post]
Param: SCGI [1]
Param: SERVER_NAME [_]
Param: SERVER_PORT [80]
Param: SERVER_PROTOCOL [HTTP/1.1]
                 */

		// if method is POST
		if ( parm == "POST" ) {
			// return to WEB-client the POST data
			strcpy(buffUot, getParam("POST_DATA", params).c_str());
			return;
		}
		// or return to WEB-client the QUERY_STRING parameter
		strcpy(buffUot, "{"
                        "\"param\": 123"
                        "}");
	}

        virtual void get(RequestParamsMap& params, const string& query_string, char *buffUot){}
        virtual void post(RequestParamsMap& params, const string& post_data, const string& query_string, char *buffUot){}
//        virtual void put(RequestParamsMap& params, char *buffUot){}
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
    const ScgiConfig &scgi_conf = game_config.get_scgi_config ();
    if (scgi.init(scgi_conf.get_host().c_str(), scgi_conf.get_port ()) )
      {
        cerr << "server stopped\n";
        return 1;
      }

    //const char *userData = "user data";

    auto h1 = make_shared<Handler1>();
    //h1->setUserData( reinterpret_cast<void *>(userData));
    // add specific handlers
    scgi.addHandler("/post", h1.get());
//    scgi.addHandler("/xxx",  reinterpret_cast<IScgiHandler *>(new Handler2()));

    scgi.run();

    return 0;
}
