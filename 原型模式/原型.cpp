#pragma once
#include <iostream>

namespace prototype {

class AbstractPrototype {
public:
    AbstractPrototype() = default;
        virtual ~AbstractPrototype() {}
        virtual AbstractPrototype* clone () = 0;

};

class ConcretePrototype: public AbstractPrototype {
public :
    ConcretePrototype() = default;
    ~ConcretePrototype() {}
    AbstractPrototype* clone () {
        return new ConcretePrototype (*this);
    }

private:
    ConcretePrototype(const ConcretePrototype& other) {
        fprintf(stderr, "ConcretePrototype copy construct!\n");
    }
};

}