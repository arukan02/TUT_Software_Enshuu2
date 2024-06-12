#include "RepeatMessage.h"
#include <cstring> //for std::strlen and std::strcpy

//constructor implementation
RepeatMessage::RepeatMessage(int n): Message(), nloops(n){} // Constructer with nloops

//definition of the insertion operator(<<) for RepeatMessage
std::ostream &operator<<(std::ostream &stream, const RepeatMessage &obj){
    if(obj.getMessage() != nullptr){
        for(int i = 0; i < obj.getNloops(); i++){
            stream << obj.getMessage();
        }
    }
    return stream;
}

//function to get the nloops
const int RepeatMessage::getNloops()const{
    return nloops;
}