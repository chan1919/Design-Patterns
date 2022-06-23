#include <stdio.h>

class AbstractTarget{
public:
    virtual ~AbstractTarget() {}
    virtual void Requtst() = 0;
};

class Adaptee{
public:
    virtual void SpecificRequest() {
        printf("this is Adaptee::SpecificRequest!\n");

    }
};


class Adapter: public Adaptee,public AbstractTarget{
public:
    virtual void Request () {
        SpecificRequest();
    }
};