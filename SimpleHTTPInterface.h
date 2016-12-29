/****************************
 SimpleHTTPInterface.h
 
 Created by Jacob Israel on 12/23/16.
 *******************************/
#ifndef SimpleHTTPInterface_h
#define SimpleHTTPInterface_h

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

typedef enum{
    NO_SOCKET_AVAILABLE,
    CONNECTION_REFUSED,
    RESOURCE_NOT_FOUND,
    TOO_MANY_REDIRECTS
} HTTPFailureReason;

class SimpleHTTPInterface{
    public:
    // HTTP Callbacks
    virtual void simpleHTTPConnected() = 0;
    virtual void simpleHTTPConnectionFailed(HTTPFailureReason reason) = 0;
    virtual void simpleHTTPRecievedResponse() = 0;
};
#endif // SimpleHTTPInterface_h
