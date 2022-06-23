#include <stdio.h>

class AbstractComponent{
public:
    virtual ~AbstractComponent() {}
    virtual void Request() = 0;
};

class ConcreteComponent:public AbstractComponent{
public:
    virtual void Request() {
        printf("this is ConcreteComponent::Request!n");
    }
};

class AbstractDecorator :public AbstractComponent{
private:
    AbstractComponent* comp_;
public:
    AbstractDecorator(AbstractComponent* comp):comp_(comp) {}
    virtual void Request() {
        if (comp_) comp_->Request();
    }
};

class ConcreteDecoratorA:public AbstractDecorator{
public:
    ConcreteDecoratorA(AbstractComponent* comp):AbstractDecorator(comp){}
    virtual void Request() {
        PreRequest();
        AbstractDecorator::Request();
        PostRequest();
    }
protected:
    void PreRequest (){
        printf("ConcreteDecoratorA::PreRequest!\n");
    }
    void PostRequest (){
        printf("ConreteDecoratorA::PostRequest!\n");
    }
};