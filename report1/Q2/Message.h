#include <iostream>

class Message {

private:
    char* message;

public:
    Message(); // Constructer
    ~Message(); //Destructor
    
    void setMessage(const char* message);
    const char* getMessage(void) const;

    //declaration of stream operators
    friend std::istream& operator>>(std::istream& stream, Message& obj);
    friend std::ostream& operator<<(std::ostream& stream, const Message& obj);
};

