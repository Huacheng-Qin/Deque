#include <iostream>
#include "URLHistory.hpp"

bool URLHistory::Parse(std::string input) {
    std::string command = input.substr(0, input.find_first_of(" "));

    if (command == "pop_front") {
        PopFront();
    } else if (command == "pop_back") {
        PopBack();
    } else if (command == "size") {
        Size();
    } else if (command == "front") {
        Front();
    } else if (command == "back") {
        Back();
    } else if (command == "empty") {
        Empty();
    } else if (command == "clear") {
        Clear();
    } else if (command == "print") {
        Print();
    } else if (command == "exit") {
        return false;
    } else if (command == "find" || command == "push_front" || command == "push_back"){
        input.erase(0, input.find_first_of('\"') + 1);
        std::string URLName = input.substr(0, input.find_first_of('\"'));
        std::string URL = "";

        if (command != "find") {
            input.erase(0, input.find_first_of('\"', input.find_first_of('\"') + 1) + 1);
            input.erase(input.find_last_of('\"'));
            URL = std::move(input);
        }

        URLData data{std::move(URLName), std::move(URL)};

        if (command == "find") {
            Find(std::move(data));
        } else if (command == "push_front") {
            PushFront(std::move(data));
        } else if (command == "push_back") {
            PushBack(std::move(data));
        }
    } else if (std::cin.eof()) {
        return false;
    }

    return true;
}

void URLHistory::PushFront(URLData data) {
    m_history.PushBack(std::move(data));
    std::cout << "success" << std::endl;
}

void URLHistory::PushBack(URLData data) {
    m_history.PushFront(std::move(data));
    std::cout << "success" << std::endl;
}

void URLHistory::PopFront() {
    if (m_history.Empty()) {
        std::cout << "failure" << std::endl;
    } else {
        m_history.PopBack();
        std::cout << "success" << std::endl;
    }
}

void URLHistory::PopBack() {
    if (m_history.Empty()) {
        std::cout << "failure" << std::endl;
    } else {
        m_history.PopFront();
        std::cout << "success" << std::endl;
    }
}

void URLHistory::Size() {
    std::cout << "size is " << m_history.Size() << std::endl;
}

void URLHistory::Front() {
    if (m_history.Empty()) {
        std::cout << "failure" << std::endl;
    } else {
        std::cout << "front is ";
        URLData::Print(m_history.Back());
    }
}

void URLHistory::Back() {
    if (m_history.Empty()) {
        std::cout << "failure" << std::endl;
    } else {
        std::cout << "back is ";
        URLData::Print(m_history.Front());
    }
}

void URLHistory::Empty() {
    std::cout << "empty " << m_history.Empty() << std::endl;
}

void URLHistory::Clear() {
    m_history.Clear();
    std::cout << "success" << std::endl;
}

void URLHistory::Find(URLData data) {
    if (m_history.Find(data)) {
        std::cout << "found ";
        URLData::Print(m_history.FindValue(data));
    } else {
        std::cout << "not found ";
        URLData::Print(data);
    }
}

void URLHistory::Print() {
    m_history.ForEach(URLData::Print);
}
