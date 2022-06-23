#include <stdio.h>

class AbstractInterface{
public:
    AbstractInterface();
    ~AbstractInterface();

    void Request();

private:
    class Impl;
    Impl* impl_;
};

class AbstractInterface::Impl {
public :
    void Request (){
        printf("this is AbstractInterface::Impl::Request! \n");
    }
};

AbstractInterface::AbstractInterface() {
    impl_ = new Impl();
}

AbstractInterface::~AbstractInterface() {
    delete impl_;
}

void AbstractInterface::Request() {
    impl_->Request();
}



