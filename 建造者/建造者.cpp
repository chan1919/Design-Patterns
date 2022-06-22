#include <stdio.h>
#include <string>
#include <shared_mutex>
class Product {
public:
    void Show () {
        printf("Show Product...\n");
    }

private:
    std::string _partA;
    std::string _partB;
    std::string _partC;
};

class AbstractBuilder {
public:
    AbstractBuilder(){
        _product.reset(new Product());      
    }
    Product* GetResult() {
        return _product.get();
    }

    virtual void BuilderPartA () = 0;
    virtual void BuilderPartB () = 0;
    virtual void BuilderPartC () = 0;

protected:
    std::shared_ptr<Product> _product;
};

class ConcreteBuilder: public AbstractBuilder{
public: 
    virtual void BuilderPartA() {
        printf("Builder PartA ...\n");
    }
    virtual void BuilderPartB () {
        printf("Builder PartB ...\n");
    }
    virtual void BuilderPartC() {
        printf("Builder PartC ...\n");
    }
};

class Director {
public:
    
    Director(AbstractBuilder* builder) : _builder(builder){}
    Product* ConstructProduct() {
        _builder->BuilderPartA();
        _builder->BuilderPartB();
        _builder->BuilderPartC();
        return _builder->GetResult();
    }
private:
    AbstractBuilder* _builder;
};

