#include <stdio.h>

class AbstractProductA {
public:
    virtual ~AbstractProductA() {}
    virtual void Show() = 0;
};

class AbstractProductB {
public:
    virtual ~AbstractProductB() {}
    virtual void Show() = 0;
};

class ConcreteProductA1:public AbstractProductA {
public: 
    virtual void Show() {
        printf("ConcretePtoductA1 Show ...\n");
    }
};

class ConcreteProductA2 : public AbstractProductA{
public:
    virtual void Show() {
        printf("ConcreteProductA2 Show ...\n");
    }
};

class ConcreteProductB1: public AbstractProductB {
public :    
    virtual void Show (){
        printf("ConcreteProductB1 Show... \n");
    }
};

class ConcreteProductB2 : public AbstractProductB {
public:
    virtual void Show () {
        printf("ConcreteProductB2 Show... \n");
    }
};

//Abstract Factory
class AbstractFactory {
public:
    virtual ~AbstractFactory() {}
    virtual AbstractProductA* CreateProductA () = 0;
    virtual AbstractProductB* CreateProductB () = 0;

};

class ConcreteFactory1 : public AbstractFactory {
public: 
    virtual AbstractProductA* CreateProductA() {
        AbstractProductA* ptr = new ConcreteProductA1();
        return ptr;
    }
    virtual AbstractProductB* CreateProductB() {
        AbstractProductB* ptr = new ConcreteProductB1();
        return ptr;
    }
};

class ConcreteFactory2 : public AbstractFactory {
public:
    virtual AbstractProductA* CreateProductA() {
        AbstractProductA* ptr = new ConcreteProductA2();
        return ptr;
    }
    virtual AbstractProductB* CreateProductB() {
        AbstractProductB* ptr = new ConcreteProductB2();
        return ptr;
    }
};