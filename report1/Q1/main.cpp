#include "Message.h"

int main (int argc, char *argv[]){
    //make a new Message object called obj
    Message obj;
    obj.setMessage("Hello World.");
    std::cout << obj.getMessage() << std::endl;

    return 0;
}