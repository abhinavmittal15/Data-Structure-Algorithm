#include<iostream>
#include<deque>
using namespace std;

class MyCircularDeque {
private:
    deque<int> dq;
    int k;

public:
    MyCircularDeque(int k) : k(k) {

    }
    
    bool insertFront(int value) {
        if(dq.size() < k) {
            dq.push_front(value);
            return true;
        }
        else {
            return false;
        }
    }
    
    bool insertLast(int value) {
        if(dq.size() < k) {
            dq.push_back(value);
            return true;
        }
        else {
            return false;
        }
    }
    
    bool deleteFront() {
        if(!dq.empty()) {
            dq.pop_front();
            return true;
        }
        else {
            return false;
        }
    }
    
    bool deleteLast() {
        if(!dq.empty()) {
            dq.pop_back();
            return true;
        }
        else {
            return false;
        }
    }
    
    int getFront() {
        if(!dq.empty()) {
            return dq.front();
        }
        else {
            return -1;
        }
    }
    
    int getRear() {
        if(!dq.empty()) {
            return dq.back();
        }
        else {
            return -1;
        }
    }
    
    bool isEmpty() {
        return dq.empty();
    }
    
    bool isFull() {
        return dq.size() == k;
    }
};