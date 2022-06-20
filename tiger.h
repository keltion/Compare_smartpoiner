#pragma once
#include <iostream>
#include <array>
#include "ref_counted_base.h"

class Tiger : public refCountedBase {
public:
    Tiger() : age_(0) {};
    Tiger(int age) : age_(age) {}
    ~Tiger() override {}
    int Age() {
        return age_;
    }
private:
    int age_;
};