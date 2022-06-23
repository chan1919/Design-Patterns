#include <stdio.h>

class AbstractSubject{
public:
    virtual ~AbstractSubject() {}
    virtual void Request () = 0;

};

class RealSubject:public AbstractSubject {
public:
    virtual void Request() {
        printf("this is RealSubject::Request!\n");
    }
};

class SubjectProxy:public AbstractSubject{
public:
    virtual ~SubjectProxy(){
        if(real_)delete real_;
    }
    virtual void Request() {
        if (!real_) real_ = new RealSubject();
        PreRequest();
    }
    virtual void PreRequest(){
        printf("XXXX");
    }
private:
    RealSubject* real_;
};