#include <chrono>
#include <iostream>
#include <vector>

#include "ref_counted_base.h"
#include "scoped_refptr.h"
#include "shared_ptr.h"
#include "tiger.h"

constexpr int Tiger_NUM = 200000000;
using namespace keltion;

int main() { 
    std::vector<scoped_refptr<Tiger>> sc_tigers;
    std::vector<shared_ptr<Tiger>> sh_tigers;

    sc_tigers.reserve(Tiger_NUM);
    sh_tigers.reserve(Tiger_NUM);

    scoped_refptr<Tiger> sc_bum = scoped_refptr<Tiger>(new Tiger(1));
    shared_ptr<Tiger> sh_bum = shared_ptr<Tiger>(new Tiger(2));

    {
        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < Tiger_NUM; i++) {
            sc_tigers.emplace_back(sc_bum);
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        std::cout << "scoped_refptr: " << diff.count() << "s\n";
    }

    {
        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < Tiger_NUM; i++) {
            sh_tigers.emplace_back(sh_bum);
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        std::cout << "shared_ptr: " << diff.count() << "s\n";
    }
}