#include <stdio.h>

class AbstractImplementor {
public:
    virtual ~AbstractImplementor() {}
    virtual void Request() = 0;
};

class ConcreteImplementorA: public AbstractImplementor{
public:
    virtual void Request() {
        printf("this ConcreteImplementorA::Request ! \n");
    }
};

class ConcreteImplementorB: public AbstractImplementor{
public:
    virtual void Request() {
        printf("this ConcreteImplementorB::Request ! \n");
    }
};

class AbstractRole {
public:
    AbstractRole(AbstractImplementor* impl):impl_(impl) {}
    virtual ~AbstractRole() {}
    virtual void Request() = 0;
protected:
    AbstractImplementor* impl_;
};

class ExtendRole : public AbstractRole {
public:
    ExtendRole(AbstractImplementor* impl) :AbstractRole(impl) {}
    virtual void Request() {
        impl_->Request();
    }
};