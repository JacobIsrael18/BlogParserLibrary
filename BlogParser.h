/****************************
 BlogParser.h
 
 A class that requests a Blog and
 parses the results into seperate BlogPosts
 
 This is also the facing header file of the 
 BlogParser Library
 
 Created by Jacob Israel on 12/21/16.
 *******************************/
#ifndef BlogParser_h
#define BlogParser_h

#include "BlogPost.h"
#include "SimpleHTTP.h"
#include "SimpleHTTPInterface.h"
#include "BlogParserProgrammingInterface.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

// #define DEBUG

class BlogParser : public SimpleHTTPInterface{
    
private:
    string hostName;
    string fileName;
    SimpleHTTP* simpleHTTP;
    BlogParserProgrammingInterface* programmingInterface;
    
    void simpleHTTPConnected();
    void simpleHTTPRecievedResponse();
    void simpleHTTPConnectionFailed(HTTPFailureReason reason);
    
public:
    /*! ===========================
     @function  Constructor
     ============================= */
    BlogParser(string newHostName, string newFileName, BlogParserProgrammingInterface* newProgrammingInterface);
    
    
#pragma mark - SimpleHTTPInterface
    /*! ===========================
     @function  processHTTPResponse
     @discussion
     This is a SimpleHTTPInterface callback function.
     @param The response from the server as a string
     ============================= */
    void processHTTPResponse(string response);
}; // end class

#endif /* BlogParser_h */
