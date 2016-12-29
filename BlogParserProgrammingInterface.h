/****************************
 BlogParserProgrammingInterface.h
 
 A class using the BlogParser Library
 should conform to this interface
 
 Created by Jacob Israel on 12/28/16.
 *******************************/
#ifndef BlogParserProgrammingInterface_h
#define BlogParserProgrammingInterface_h

class BlogParserProgrammingInterface{
public:
    virtual void blogParserProcessedResponse(const string &serverResponse, const string &error) = 0;
    
};
#endif /* BlogParserProgrammingInterface_h */
