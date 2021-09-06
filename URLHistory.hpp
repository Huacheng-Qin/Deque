#ifndef URLHISTORY_HPP
#define URLHISTORY_HPP
#include <iostream>
#include "MyList.hpp"
#include "URLData.hpp"

class URLHistory {
    public:
    URLHistory() = default;
    ~URLHistory() = default;
    bool Parse(std::string input);

    private:
    void PushFront(URLData data);
    void PushBack(URLData data);
    void PopFront();
    void PopBack();
    void Size();
    void Front();
    void Back();
    void Empty();
    void Clear();
    void Find(URLData data);
    void Print();

    MyList<URLData> m_history;
};
#endif
