#include <iostream>
#include <iomanip>

int main() {
    int year, month, day;
    year = month = day = 0;
    
    std::cin >> year;
    std::cin.ignore();
    std::cin >> month;
    std::cin.ignore();
    std::cin >> day;
    
    
    std::cout << std::setfill('0') << std::setw(2) << day << '-';
    std::cout << std::setfill('0') << std::setw(2) << month << '-';
    std::cout << year;
}
