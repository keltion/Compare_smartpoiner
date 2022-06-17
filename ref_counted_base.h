#pragma once

class refCountedBase {
public:
    refCountedBase() : ref_count_(0) {}
    virtual ~refCountedBase() {}

    void AddRef() {
        ref_count_++;
    }

    void Release() {
        ref_count_--;
        if (ref_count_ == 0) {
            delete this;
        }
    }

    int Count() {
        return ref_count_;
    }

private:
    int ref_count_;
};