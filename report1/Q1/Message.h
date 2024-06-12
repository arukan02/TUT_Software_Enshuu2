#include <iostream>

class Message {

private:
    char* message;

public:
    Message(); // Constructer
    ~Message(); //Destructor
    
    void setMessage(const char* message);
    char* getMessage(void);
};