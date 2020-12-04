#ifndef BOTSERVER_H
#define BOTSERVER_H

#include <netinet/in.h>
#include "errors.h"

spErrorBase Serve(in_port_t port);

#endif /* BOTSERVER_H */
