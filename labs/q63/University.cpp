#include "University.hpp"
#include <iostream>

// TODO: 아래 함수들을 구현하세요.

University::University(const std::string& name) : name(name)
{
    // 힙트: 멤버 초기화 리스트 사용 → : name(name) {}
    // departments는 vector 기본 생성자로 빈 상태가 자동 초기화됩니다.
}

void University::addDepartment(const Department& dept) {
    // TODO: vector에 dept를 추가하세요.
    // 힙트: departments.push_back(dept);
    departments.push_back(dept);
}

void University::printInfo() const {
    // 출력 형식:
    // "University Name: <name>\n"
    // "Number of Departments: <departments.size()>\n"
    // 각 학과마다:
    //   "\n"  (빈 줄)
    //   "Department Name: <name>\n"
    //   faculty가 nullptr:  "Faculty Name: N/A\n" + "Number of Faculty Members: N/A\n"
    //   faculty가 있음:     "Faculty Name: <name>\n" + "Number of Faculty Members: <num>\n"
    // 힙트: auto f = dept.getFaculty(); if (f) { ... } else { ... }
    std::cout << "University Name: " << name << '\n';
    std::cout << "Number of Departments: " << departments.size() << '\n';
    for(const auto& dept : departments) {
        const auto& dept_name = dept.getName();
        auto fac = dept.getFaculty();
        std::cout << '\n';
        std::cout << "Department Name: " << dept_name << '\n';
        if(fac) {
            std::cout << "Faculty Name: " << fac -> getName() << '\n';
            std::cout << "Number of Faculty Members: " << fac -> getNumMembers() << '\n';
        } else {
            std::cout << "Faculty Name: N/A\n";
            std::cout << "Number of Faculty Members: N/A\n";
        }
    }

}
