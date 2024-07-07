#include "Message.h"

int main (int argc, char *argv[]){
    //testing default constructor
    Message obj1;
    obj1.addMessage("Hello World.");
    obj1.addMessage("Hello 2nd one\n");
    std::cout << "Number of messages: " << obj1.getNMessages() << std::endl;
    obj1.showAllMessages();

    //testing single message constructor
    Message obj2("This is single message constructor\n");
    obj2.showAllMessages();

    //testing vector of messages constructor
    std::vector<std::string> vec = {"1st message", "2nd message", "3rd message"};
    Message obj3(vec);
    std::cout << "Number of vector messages: " << obj3.getNMessages() << std::endl;
    obj3.showAllMessages();

    //testing getMessage
    std::cout << "testing getMessage for index 1 vector : " << obj3.getMessage(1) << std::endl;

    return 0;
}