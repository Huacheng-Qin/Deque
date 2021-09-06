#ifndef URLDATA_HPP
#define URLDATA_HPP
#include <iostream>

class URLData {
    public:
    URLData(std::string URLName, std::string URL);
    ~URLData() = default;
    static void Print(const URLData& data);
    bool operator==(const URLData& other);

    private:
    std::string m_URL;
    std::string m_URLName;
};
#endif
