/****************************
 BlogParser.cpp
 
 A class that requests a Blog and
 parses the results into seperate BlogPosts
 
 Created by Jacob Israel on 12/21/16.
 *******************************/
#include "BlogParser.h"


/*! ===========================
 @function  Constructor
 ============================= */
BlogParser::BlogParser(string newHostName, string newFileName, BlogParserProgrammingInterface* newProgrammingInterface) : hostName(newHostName), fileName(newFileName) , programmingInterface(newProgrammingInterface){
    
    simpleHTTP = new SimpleHTTP(hostName);
    
    simpleHTTP->setInterface(this);
    
#ifdef DEBUG
    printf("Connecting to %s\n", hostName.c_str() );
#endif
    
    simpleHTTP->connectToHost();
}



/*! ===========================
 @function    simpleHTTPConnected(
 @discussion
 SimpleHTTPInterface
 ============================= */
void BlogParser::simpleHTTPConnected(){
    int bytesDelivered = simpleHTTP->sendFileRequestToHost(fileName);
    if(bytesDelivered > 0){
#ifdef DEBUG
        printf("Bytes Delivered %d\n", bytesDelivered);
#endif
        simpleHTTP->waitForResponse();
    }
}

/*! ===========================
 @function  simpleHTTPRecievedResponse
 @discussion
 SimpleHTTPInterface
 ============================= */
void BlogParser::simpleHTTPRecievedResponse(){
    string responseString = simpleHTTP->getLastResponse();
    simpleHTTP->closeSocket();
    
    if(responseString.length() > 0){
        //   printf("Got response \n");
        processHTTPResponse(responseString);
    }
}

/*! ===========================
 @function    simpleHTTPConnectionFailed
 @discussion
 SimpleHTTPInterface
 ============================= */
void BlogParser::simpleHTTPConnectionFailed(HTTPFailureReason reason){
    printf("simpleHTTPConnectionFailed() \n");
    
    switch (reason) {
        case NO_SOCKET_AVAILABLE:
            
            break;
        case CONNECTION_REFUSED:
        {
            string responseString = simpleHTTP->getLastResponse();
            printf("%s\n", responseString.c_str() );
        }
            break;
            
        case TOO_MANY_REDIRECTS:
            break;
            
        case RESOURCE_NOT_FOUND:
            break;
    }
}

/*! ===========================
 @function
 @discussion
 @param
 ============================= */
void BlogParser::processHTTPResponse(string response){
    
    string okString = "200 OK";
    string lineBreak = "-----------------------------------------------------------------------\n";
    
    size_t index = response.find(okString);
    if ( index >= response.length() ){
        if (programmingInterface != NULL) {
            string error = "Server Response is NOT 200 OK\n"; //     string serverResponse, string error
            error.append(response);
            programmingInterface->blogParserProcessedResponse("", error);
        }
        printf("FAILURE 896534234 Server Response is NOT 200 OK\n%s\n", response.c_str() );
        return;
    }
    
    string contentString = "Content-Length:";
    
    index = response.find(contentString);
    if ( index >= response.length() ){
        printf("Warning: Server Response has no Content-Length\n");
    }
    else{
        response = response.substr(index, response.length() - index);
    }
    
    index = 0;
    // Trim away any newlines or spaces
    while (index < response.length() && response[index] <= ' ') {
        index++ ;
    }
    
    if(index < response.length() ){
        response = response.substr(index, response.length() - index);
    }
    
    index = response.find("[");
    size_t index2 = response.find_last_of("]");
    
    if(index > response.length() || index2 > response.length() ||  index >= index2 ||  index == string::npos ||  index2 == string::npos){
        
        if (programmingInterface != NULL) {
            string error = "Response has no array"; //     string serverResponse, string error
            programmingInterface->blogParserProcessedResponse("", error);
        }
 
        printf("FAILURE 0945123123 Response has no array %lu >= %lu", index, index2);

        return;
    }
    
    response = response.substr(index+1, index2 - index - 1);
#ifdef DEBUG
    printf("Trimmed Rsponse:\n%s\n\n", response.c_str() );
#endif
    
    index = index2 = 0;
    string serverResponse = "";
    
    while(index < response.length() && index2 < response.length() && index2 != string::npos) {
        index = response.find("{");
        index2 = response.find("}");
        
        if(index < response.length() && index2 < response.length() && index < index2 && index2 < response.length() && index2 != string::npos){
            index += 1;
            string nextString = response.substr(index, index2 - index);
            index2 += 1;
            if(index2 < response.length() && index2 != string::npos){
                response = response.substr(index2, response.length() - index2);
            }
            // cout << lineBreak;
            serverResponse.append(lineBreak);
            BlogPost blogPost = BlogPost(nextString);
            
            // blogPost.print();
            serverResponse.append( blogPost.toString() );
        }
    }
    // cout << lineBreak;
    serverResponse.append(lineBreak);
    
    if (programmingInterface != NULL) { //                         string serverResponse, string error
        programmingInterface->blogParserProcessedResponse(serverResponse, "");
    }
}

