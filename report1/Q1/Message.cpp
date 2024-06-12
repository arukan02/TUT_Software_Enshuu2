#include "Message.h"
#include <cstring> //for std::strlen and std::strcpy

// Constructer initializing
Message::Message(){
    message = nullptr;
} 

//Destructor
Message::~Message(){
    if(message != nullptr)
    delete[] message;
} 

//this is the function to set Message, 
//it works by making a new char* with (msg + 1) as its length 
//then copy msg to message with strcpy  
void Message::setMessage(const char* msg){
    message = new char[std::strlen(msg) + 1];
    std::strcpy(message, msg);
}

//return message
char* Message::getMessage(void){
    return message;
}
