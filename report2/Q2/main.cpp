#include "Message.h"

int main (int argc, char *argv[]){
    Message obj1("Hello World.");
    Message obj2 = obj1;

    std::cout << obj2 << std::endl;

    return 0;
}