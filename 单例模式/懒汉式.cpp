#pragma once

#include <mutex>

namespace singleton {
// 懒汉单例 ，类加载时没有生成单例，
// 第一次调用getInstance 方法生成。
class LazySingleton {
public:
    LazySingleton* getInstance() {
        if (!instance_) {
            std::unique_lock<std::mutex> lock(mutex_);
            //可能俩个线程都执行到这里
            if (!instance_) instance_ = new LazySingleton();
        }
        return instance_;
    }
private:
    LazySingleton() {}
    static LazySingleton* instance_;
    static std::mutex mutex_;
};

}