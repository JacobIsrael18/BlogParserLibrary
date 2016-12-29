/****************************
   BlogPost.h
 
 A class that models a single post
 Created by Jacob Israel on 12/21/16.
 *******************************/

#ifndef BlogPost_h
#define BlogPost_h

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string> 

using namespace std;

class BlogPost{
private:
    int userID;
    int blogID;
    string title;
    string body;
    
public:
    BlogPost(string dictionaryContents);
    void setUserID(int newValue);
    void setID(int newValue);
    void setTitle(string newValue);
    void setBody(string newValue);
    
    int getUserID();
    int getID();
    string getTitle();
    string getBody();

    string toString();
    void print();
};
#endif // BlogPost_h
