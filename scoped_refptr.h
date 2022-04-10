#pragma once

#include <iostream>
#include <memory>

namespace keltion{

template<class T>
class scoped_refptr {
public:
    scoped_refptr() : ptr_(nullptr) {}
    scoped_refptr(T* p) : ptr_(p) {
        if (ptr_) {
            ptr_->AddRef();
        }
    }

    // copy constructor, 얕은 복사
    scoped_refptr(const scoped_refptr& other) : ptr_(other.ptr_) {
        if (ptr_) {
            ptr_->AddRef();
        }
    }

    // move constructor, 소유권 이동
    scoped_refptr(scoped_refptr&& other) : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    } 

    //copy assignment, 얕은 복사
    scoped_refptr& operator=(const scoped_refptr& other) {
        if (&other == this) {
            return *this;
        }
        // 가지고 있는 리소스 정리
        if (ptr_) {
            ptr_ -> Release();
        }

        ptr_ = other.ptr_;
        if (ptr_) {
            ptr_->AddRef();
        }
        return *this;
    }

    //move assignment, 소유권 이동
    scoped_refptr& operator=(scoped_refptr&& other) {
        if (&other == this) {
            return *this;
        }
        // 가지고 있는 리소스 정리
        if (ptr_) {
            ptr_ -> Release();
        }
        
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;

        return *this;
    }

    int use_count() {
        if (ptr_ == nullptr) {
            return 0;
        }
        return ptr_->Count();
    }

    T* get() {
        return ptr_;
    }

    ~scoped_refptr() {
        if (ptr_) {
            ptr_->Release();
        }
    }
private:
    T* ptr_;
};

}