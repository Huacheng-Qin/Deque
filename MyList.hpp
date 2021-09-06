#ifndef MYLIST_HPP
#define MYLIST_HPP
#include <iostream>

template<class T>
class MyList {
    public:
    using FuncCallback = void(*)(const T&);
    MyList() = default;
    ~MyList();
    const T& Front();
    const T& Back();
    void ForEach(FuncCallback func);
    void PushFront(T element);
    void PushBack(T element);
    void PopFront();
    void PopBack();
    bool Empty();
    std::size_t Size();
    bool Find(const T& element);
    const T& FindValue(const T& element);
    void Clear();

    private:
    struct MyNode {
        MyNode(MyNode* newPrevious, MyNode* newNext, T&& newData):
            previous(newPrevious), next(newNext), data(std::move(newData)) {}
        T data;
        MyNode* previous;
        MyNode* next;
    };

    MyNode* m_head = nullptr;
    MyNode* m_tail = nullptr;
    std::size_t m_size = 0;
};

#include "MyListImpl.hpp"
#endif
