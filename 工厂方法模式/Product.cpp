#include "Product.h"

#include <iostream>
using namespace std;

Product::Product () {}

Product::~Product() {}

ConcreteProduct::ConcreteProduct() {
    cout <<"ConcreateProduct..."<<endl;
}

ConcreteProduct::~ConcreteProduct() {}