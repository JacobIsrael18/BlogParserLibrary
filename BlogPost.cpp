/****************************
  BlogPost.cpp
  
A class that models a single post
  Created by Jacob Israel on 12/21/16.
*******************************/
#include "BlogPost.h"
#include <regex.h>

// Prototypes
string findStringForQuotedKeyInString(string key, string sourceString);
int findIntegerForQuotedKeyInString(string key, string sourceString);

/*! ===========================
 @function Constructor
 ============================= */
BlogPost::BlogPost(string dictionaryContents){
    
    userID = findIntegerForQuotedKeyInString("userId", dictionaryContents);
    blogID = findIntegerForQuotedKeyInString("id", dictionaryContents);
    title = findStringForQuotedKeyInString("title", dictionaryContents);
    body = findStringForQuotedKeyInString("body", dictionaryContents);
}

/*! ===========================
 @function   findStringForQuotedKeyInString
 
 ============================= */
string findStringForQuotedKeyInString(string key, string sourceString){
    
    key = "\"" + key + "\"";
    size_t index = sourceString.find(key);
    
    if(index >=  sourceString.length() || index == string::npos){
        printf("Warning key not found: %s\n", key.c_str() );
        return "";
    }
    index += key.length() ;
    
    sourceString = sourceString.substr(index, sourceString.length() - index);
    
    // There must be a double-quote
    char* lastCharacter = ((char*) sourceString.c_str() + sourceString.length() - 1);
    char* characterPtr = strstr(sourceString.c_str() , "\"" );
    if(characterPtr == NULL || characterPtr >= lastCharacter){
        return "";
    }
    
    characterPtr++ ;
    
    char* characterPtr2 = characterPtr + 1;
    while (characterPtr2 < lastCharacter && *characterPtr2 != '"') {
        characterPtr2++ ;
    }
    
    string resultString = characterPtr;
    resultString = resultString.substr(0, characterPtr2 - characterPtr);
    
    return resultString;
}

/*! ===========================
 @function       findIntegerForQuotedKeyInString
 ============================= */
int findIntegerForQuotedKeyInString(string key, string sourceString){
    key = "\"" + key + "\"";
    
    char* characterPtr = strstr(sourceString.c_str() , key.c_str() );
    if(characterPtr == NULL){
            return -1;
    }
    
    characterPtr += key.length();
    
    if (sourceString.length() == 0) {
        return -1;
    }
    
    // Find the first digit
    char* lastCharacter = ((char*) sourceString.c_str() + sourceString.length() - 1);
    while (characterPtr < lastCharacter && (*characterPtr < '0' || *characterPtr > '9' ) ) {
        characterPtr++ ;
    }
    
    if (characterPtr > lastCharacter) {
        return -1;
    }
    
    // Assignnment operator
    sourceString = characterPtr;
    
    int resultInteger = std::stoi (sourceString);
    return resultInteger;
}

#pragma mark - Setters
/*! ===========================
 @function      setUserID
 ============================= */
void BlogPost::setUserID(int newValue){
    userID = newValue;
}

/*! ===========================
 @function      setID
 ============================= */
void BlogPost::setID(int newValue){
    blogID = newValue;
}

/*! ===========================
 @function     setTitle
 ============================= */
void BlogPost::setTitle(string newValue){
    title = newValue;
}

/*! ===========================
 @function     setBody
 ============================= */
void BlogPost::setBody(string newValue){
    body = newValue;
}

#pragma mark - Getters
/*! ===========================
 @function    getUserID
 ============================= */
int BlogPost::getUserID(){
    return userID;
}

/*! ===========================
 @function   getID
 ============================= */
int BlogPost::getID(){
    return blogID;
}

/*! ===========================
 @function    getTitle
 ============================= */
string BlogPost::getTitle(){
    return title;
}

/*! ===========================
 @function getBody
 ============================= */
string BlogPost::getBody(){
    return body;
}


/*! ===========================
 @function  toString()
 @discussion
 print the posts's title & body on seperate lines
 ============================= */
string BlogPost::toString(){
    string output = title + "\n" + body + "\n";
    return output;
}

/*! ===========================
 @function  print
 @discussion
 print the posts's title & body on seperate lines
 ============================= */
void BlogPost::print(){
    cout << toString();
}

