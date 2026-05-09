#pragma once

#include <string>
#include <map>
#include <initializer_list>
#include <utility>

class Phonebook {
    std::map<std::string, int> contacts;
public:
    Phonebook(std::initializer_list<std::pair<const std::string, int>> lst);
    void print() const;
};
