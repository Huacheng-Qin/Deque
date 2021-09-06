#ifndef MYLISTIMPL_HPP
#define MYLISTIMPL_HPP
#include <iostream>
#include "MyList.hpp"

template<class T>
MyList<T>::~MyList() {
    Clear();
}

template<class T>
const T& MyList<T>::Front() {
    if (m_head == nullptr) {
        throw std::out_of_range("empty_list");
    }
    return m_head->data;
}

template<class T>
const T& MyList<T>::Back() {
    if (m_tail == nullptr) {
        throw std::out_of_range("empty_list");
    }
    return m_tail->data;
}

template<class T>
void MyList<T>::ForEach(FuncCallback func) {
    if (func == nullptr) {
        return;
    }
    MyNode* target = m_head;
    while (target != nullptr) {
        func(target->data);
        target = target->next;
    }
}

template<class T>
void MyList<T>::PushFront(T element) {
    if (m_head == nullptr) {
        m_head = new MyNode(nullptr, nullptr, std::move(element));
        m_tail = m_head;
    } else {
        m_head->previous = new MyNode(nullptr, m_head, std::move(element));
        m_head = m_head->previous;
    }
    m_size++;
}

template<class T>
void MyList<T>::PushBack(T element) {
    if (m_tail == nullptr) {
        m_tail = new MyNode(nullptr, nullptr, std::move(element));
        m_head = m_tail;
    } else {
        m_tail->next = new MyNode(m_tail, nullptr, std::move(element));
        m_tail = m_tail->next;
    }
    m_size++;
}

template<class T>
void MyList<T>::PopFront() {
    if (m_head != nullptr) {
        if (m_head->next != nullptr) {
            m_head = m_head->next;
            delete m_head->previous;
            m_head->previous = nullptr;
        } else {
            delete m_head;
            m_head = nullptr;
            m_tail = nullptr;
        }
        m_size--;
    }
}

template<class T>
void MyList<T>::PopBack() {
    if (m_tail != nullptr) {
        if (m_tail->previous != nullptr) {
            m_tail = m_tail->previous;
            delete m_tail->next;
            m_tail->next = nullptr;
        } else {
            delete m_tail;
            m_tail = nullptr;
            m_head = nullptr;
        }
        m_size--;
    }
}

template<class T>
bool MyList<T>::Empty() {
    return (m_size == 0);
}

template<class T>
std::size_t MyList<T>::Size() {
    return m_size;
}

template<class T>
bool MyList<T>::Find(const T& element) {
    MyNode* target = m_head;
    while (target != nullptr) {
        if (target->data == element) {
            return true;
        }
        target = target->next;
    }
    return false;
}

template<class T>
const T& MyList<T>::FindValue(const T& element) {
    if (m_head == nullptr) {
        throw std::out_of_range("non_existent_element");
    }
    MyNode* target = m_head;
    while (target != nullptr) {
        if (target->data == element) {
            return target->data;
        }
        target = target->next;
    }
    throw std::logic_error("non_existent_element");
}

template<class T>
void MyList<T>::Clear() {
    if (m_head != nullptr) {
        while (m_head->next != nullptr) {
            m_head = m_head->next;
            delete m_head->previous;
        }
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
    }
    m_size = 0;
}
#endif
