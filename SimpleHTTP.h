/****************************
 SimpleHTTP.h
 
 A class that models a single post
 Created by newcomp on 12/21/16.
 *******************************/
#ifndef SimpleHTTP_h
#define SimpleHTTP_h

#define PORT_80 80

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "SimpleHTTPInterface.h"
using namespace std;

class SimpleHTTP{
    
    private:
    int mySocketNumber;
    bool messageResponseReceived;
    string hostName;
    string lastResponse;
    SimpleHTTPInterface* httpInterface;
    
public:
    SimpleHTTP(string newHostName);
    void connectToHost();
    
    // @TODO Handle 404 and redirects
    int sendFileRequestToHost(string fileName);
    void waitForResponse();
    string getLastResponse();
    void closeSocket();
    
    void setInterface(SimpleHTTPInterface* newInterface);
    SimpleHTTPInterface* getInterface();
};
#endif // SimpleHTTP_h
