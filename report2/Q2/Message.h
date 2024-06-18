#include <iostream>

class Message {

private:
    char* message;

public:
    Message(); // Constructer
    Message(const char* _message);
    //copy constructor
    Message(Message& other);
    Message& operator=(Message& other);

    ~Message(); //Destructor
    
    void setMessage(const char* message);
    char* getMessage(void); //const char* getMessage(void) const;
};

//declaration of stream operators
std::istream& operator>>(std::istream& stream, Message& obj);
std::ostream& operator<<(std::ostream& stream, Message& obj);

