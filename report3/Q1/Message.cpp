#include "Message.h"
#include <string.h>
#include <string>
#include <stdlib.h> 


// Constructer initializing
Message::Message(){}

//single message constructor
Message::Message(const std::string& message_string){
    message.push_back(message_string);
}

//multiple vector messages constructor
Message::Message(const std::vector<std::string>& message_vector){
    message = message_vector;
}

Message::~Message(){}//Destructor

//add ma message to the list 
void Message::addMessage(const std::string& message_string){
    message.push_back(message_string);
}

//get a message by message_id
std::string Message::getMessage(int message_id){
    if(message_id >= 0 && message_id < message.size()){
        return message[message_id];
    }
    else {
        return "Message ID not found";
    }
} 

//showing all messages
void Message::showAllMessages(void){
    for(const auto& msg : message){
        std::cout << msg << std::endl;
    }
}

//get the num of messages
int Message::getNMessages(void){
    return message.size();
}