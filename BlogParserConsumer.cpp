/****************************
 BlogParserConsumer.cpp
 
 Created by Jacob Israel on 12/28/16.
 *******************************/
#include <stdio.h>

// ___BlogParser Library___
#include "BlogParser.h"
#include "BlogParserProgrammingInterface.h"

class BlogParserConsumer : BlogParserProgrammingInterface{
    
private:
    BlogParser blogParser;
    
public:
    /*! ===========================
     @function   Constructor
     ============================= */
    BlogParserConsumer(string hostName, string fileName) : blogParser(hostName, fileName, this){
   
    }
    
#pragma mark - BlogParserProgrammingInterface
    /*! ===========================
     @function    blogParserProcessedResponse(
     ============================= */
    void blogParserProcessedResponse(const string &serverResponse, const string &error){
        if (serverResponse.length() > 0) {
            printf(serverResponse.c_str());
        }
        else if(error.length() > 0){
            printf(error.c_str());
        }
    }
};

/*! ===========================
 @function   main
 @discussion
 ============================= */
int main(int argumentCount, char* arguments[])
{
    //   IP Address  Location	United States - California - Mountain View - Google Inc.
    string hostName = "demo7701733.mockable.io";
    string fileName = "/posts";
    
    if(argumentCount == 3){
        hostName = arguments[1];
        fileName = arguments[2];
    }
    
    BlogParserConsumer consumer(hostName, fileName);
    
    return 0;
}
