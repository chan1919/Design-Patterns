#pragma once 

#include <stdio.h>

namespace factory {
//抽象产品
class AbstractProduct {
public:
    virtual ~AbstractProduct() {}
    virtual void Show () = 0;

};

//具体产品
class ConcreteProduct: public AbstractProduct {
public :
    virtual void Show () {
        printf ("ConcreteProduct Show ...\n");
    }
};

//抽象工厂
class AbstractFactory {
public :
    virtual ~AbstractFactory(){}
    virtual AbstractProduct* CreateProduct() = 0;

};

//具体工厂
class ConcreteFactory:public AbstractFactory {
public :
    virtual AbstractProduct* CreateProduct () {
        AbstractProduct* ptr = new ConcreteProduct();
        return ptr;
    }
};


}