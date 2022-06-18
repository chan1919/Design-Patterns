#pragma once

namespace singleton {

class HungrySingleton {
private :
    HungrySingleton() {}
    static HungrySingleton* instance_;
public :
    HungrySingleton* getInstance () {
        return instance_;
    }

};
}