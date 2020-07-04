#ifndef URL_H
#define URL_H 1

/*
 * Original on github:
 * https://github.com/jwerle/url.h
 */

/**
 * Dependencies
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


/**
 * url.h version
 */

#define URL_VERSION 0.0.2


/**
 * Max length of a url protocol scheme
 */

#define URL_PROTOCOL_MAX_LENGTH 16


/**
 * Max length of a url host part
 */

#define URL_HOSTNAME_MAX_LENGTH 128


/**
 * Max length of a url tld part
 */

#define URL_TLD_MAX_LENGTH 16


/**
 * Max length of a url auth part
 */

#define URL_AUTH_MAX_LENGTH 32


/**
 * URI Schemes
 * http://en.wikipedia.org/wiki/URI_scheme
 */


/**
 * `url_data` struct that defines parts
 * of a parsed URL such as host and protocol
 */

typedef struct url_data {
  char *href;
  char *protocol;
  char *host;
  char *auth;
  char *hostname;
  char *pathname;
  char *search;
  char *path;
  char *hash;
  char *query;
  char *port;
} url_data_t;


// prototype

/**
 * Parses a url into parts and returns
 * a `url_data_t *` pointer
 */

url_data_t *
url_parse (char *url);

char *
url_get_protocol (char *url);

char *
url_get_auth (char *url);

char *
url_get_hostname (char *url);

char *
url_get_host (char *url);

char *
url_get_pathname (char *url);

char *
url_get_path (char *url);

char *
url_get_search (char *url);

char *
url_get_query (char *url);

char *
url_get_hash (char *url);

char *
url_get_port (char *url);

void
url_free (url_data_t *data);

bool
url_is_protocol (char *str);

bool
url_is_ssh (char *str);

void
url_inspect (char *url);

void
url_data_inspect (url_data_t *data);


// implementation


// non C99 standard functions
#if __STDC_VERSION__ >= 199901L
char *strdup (const char *str);
#endif


static char *
strff (char *ptr, int n);


static char *
strrwd (char *ptr, int n);

static char *
get_part (char *url, const char *format, int l);

url_data_t *
url_parse (char *url);

char *
url_get_protocol (char *url);


#endif
