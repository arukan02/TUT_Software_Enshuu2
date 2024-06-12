#include "Message.h"

int main (int argc, char *argv[]){
    //make a new Message object called obj
    Message obj;
    std::cout << "Input message: ";
    //use >> operator to input to Message object
    std::cin >> obj;
    std::cout << "Output message:" << std::endl;
    //use << operator to output from Message object
    std::cout << obj << std::endl;

    return 0;
}