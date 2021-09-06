#include <iostream>
#include "URLData.hpp"

URLData::URLData(std::string URLName, std::string URL):
    m_URLName(std::move(URLName)), m_URL(std::move(URL)) {}

void URLData::Print(const URLData& data) {
    std::cout << data.m_URLName;
    if (data.m_URL != "") {
        std::cout << " " << data.m_URL;
    }
    std::cout << std::endl;
}

bool URLData::operator==(const URLData& other) {
    if (m_URLName.length() != other.m_URLName.length()) {
        return false;
    }

    for (std::size_t i = 0; i < m_URLName.length(); i++) {
        if (m_URLName[i] <= 'Z' && m_URLName[i] >= 'A') {
            if (m_URLName[i] != other.m_URLName[i] && m_URLName[i] + 32 != other.m_URLName[i]) {
                return false;
            }
        } else if (m_URLName[i] >= 'a' && m_URLName[i] <= 'z') {
            if (m_URLName[i] != other.m_URLName[i] && m_URLName[i] - 32 != other.m_URLName[i]) {
                return false;
            }
        } else if (m_URLName[i] != other.m_URLName[i]) {
            return false;
        }
    }

    return true;
}
