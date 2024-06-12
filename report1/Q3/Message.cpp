#include "Message.h"
#include <cstring> //for std::strlen and std::strcpy

// Constructer initializing
Message::Message(){
    message = nullptr;
} 

//definition of extraction operator (>>)
std::istream& operator>>(std::istream& stream, Message& obj){
    //temporary buffer to hold the input, by using buffer, we have better memory management, 
    //safer and more robust(prevent overflows), and dynamic memory allocation
    char buffer[1024];
    stream.getline(buffer, 1024);

    //set the message using setMessage function below
    obj.setMessage(buffer);

    return stream;
}

//definition of the insertion operator(<<)
std::ostream& operator<<(std::ostream& stream, const Message& obj){
    if(obj.getMessage() != nullptr){
        stream << obj.getMessage();
    }
    return stream;
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
const char* Message::getMessage(void) const {
    return message;
}
