#pragma once

#include <iostream>
#include <memory>
namespace keltion {
    
class Control {
public:
    Control() = delete;
    Control(int i) : strong_ref_(i){};

    void AddRef() {
        strong_ref_++;
    }

    bool Release() {
        return --strong_ref_;
    }

    int StrongRef() {
        return strong_ref_;
    }

private:
    int strong_ref_;
};

template <class T>
class shared_ptr {
public:
    shared_ptr(T* p): ptr_(p), ct_(new Control(1)) {}
    
    // copy constructor
    shared_ptr(const shared_ptr& other) : ptr_(other.ptr_), ct_(other.ct_) {
        ct_->AddRef();
    }

    // move constructor
    shared_ptr(shared_ptr&& other) : ptr_(other.ptr_), ct_(other.ct_) {
        other.ptr_ = nullptr;
        other.ct_ = nullptr;
    }

    // copy assignment
    shared_ptr& operator=(const shared_ptr& other) {
        if (&other == this) {
            return *this;
        }

        if (ptr_) {
            if (ct_->Release() == 0){
                delete ct_;
                delete ptr_;
            }
        }

        ptr_ = other.ptr_;
        ct_ = other.ct_;
        ct_-> AddRef();

        return *this;
    }

    // move assignment
    shared_ptr& operator=(shared_ptr&& other) {
        if (&other == this) {
            return *this;
        }

        // 가지고 있는 리소스 정리
        if (ptr_) {
            if (ct_->Release() == 0){
                delete ct_;
                delete ptr_;
            }
        }

        ptr_ = other.ptr_;
        ct_ = other.ct_;
        other.ptr_ = nullptr;
        other.ct_ = nullptr;

        return *this;
    }

    int use_count() {
        if (ct_ == nullptr) {
            return 0;
        }
        return ct_->StrongRef();
    }

    T* get() {
        return ptr_;
    }

    ~shared_ptr() {
        if (ptr_) {
            if (ct_->Release() == 0){
                delete ct_;
                delete ptr_;
            }
        }
    };

private:
    T* ptr_;
    Control* ct_;    
};

};