#include "Message.h"
#include <string.h>
#include <string>
#include <stdlib.h> 

// Constructer initializing
Message::Message(): message(nullptr){
}

Message::Message(const char* _message){
    message = new char [strlen(_message) + 1];
    strcpy(message, _message);
}

//Destructor
Message::~Message(){
    if(message != nullptr) delete[] message;
} 

//this is the function to set Message, 
//it works by making a new char* with (msg + 1) as its length 
//then copy msg to message with strcpy  
void Message::setMessage(const char* _message){
    if(message) delete [] message;
    message = new char[strlen(_message) + 1];
    strcpy(message, _message);
}

char* Message::getMessage (void){
    return message;
}

//definition of extraction operator (>>)
std::istream& operator>>(std::istream& stream, Message& obj){
    //temporary buffer to hold the input, by using buffer, we have better memory management, 
    //safer and more robust(prevent overflows), and dynamic memory allocation
    std::string buffer;
    std::getline(stream, buffer);

    //set the message using setMessage function below
    obj.setMessage(buffer.c_str());

    return stream;
}

//definition of the insertion operator(<<)
std::ostream& operator<<(std::ostream& stream, Message& obj){
    stream << obj.getMessage();

    return stream;
}

// Copy Constructor
Message::Message(Message& other) {
    if (other.message) {
        message = new char[strlen(other.message) + 1];
        strcpy(message, other.message);
    } else {
        message = nullptr;
    }
}

// Copy Assignment Operator
Message& Message:: operator=(Message& other) {
    if (this != &other) {
        delete[] message; // Free existing resource
        if (other.message) {
            message = new char[strlen(other.message) + 1];
            strcpy(message, other.message);
        } else {
            message = nullptr;
        }
    }
    return *this;
}