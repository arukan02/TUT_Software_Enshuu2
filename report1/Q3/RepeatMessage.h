#include <iostream>
#include "Message.h"

//class RepeatMessage is instanced from Message class, 
//and all public members of Message class is accessible by RepeatMessage class
class RepeatMessage: public Message {

private:
    char* message;
    int nloops;

public:
    RepeatMessage(int nloops); 
    ~RepeatMessage();
    const int getNloops()const;
    //overload (<<) operator for RepeatMessage class
    friend std::ostream &operator<<(std::ostream& stream, const RepeatMessage& obj);
};

