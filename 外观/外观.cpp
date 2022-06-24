#include <iostream>
#include <shared_mutex>
class SubModuleImplementorA {
public:
    void PreRequest() {
        printf("SubM A\n");
    }
};

class SubModuleImplementorB {
public:
    void RealRequest () {
        printf("SubM B\n");
    }
};

class SubModuleImplementorC {
public:
    void PostRequest () {
        printf("SubM C\n");
    }
};

class Facade {
public:
    Facade() {
        implA_.reset(new SubModuleImplementorA);
        implB_.reset(new SubModuleImplementorB);
        implC_.reset(new SubModuleImplementorC);      
    }
private:
    std::shared_ptr<SubModuleImplementorA> implA_;
    std::shared_ptr<SubModuleImplementorB> implB_;
    std::shared_ptr<SubModuleImplementorC> implC_;
};