#include "Phonebook.hpp"
#include <iostream>

// TODO: 아래 두 함수를 구현하세요.

// [생성자] std::initializer_list로 중괄호 초기화를 받아 contacts 맵에 저장합니다.
//
// pair<const std::string, int>에서 key에 const가 붙는 이유:
//   std::map은 삽입된 key를 변경할 수 없습니다.
//   key가 바뀌면 map의 정렬 순서가 깨지기 때문에,
//   표준 라이브러리는 타입 수준에서 key를 const로 고정합니다.
//
// 구현 방법 A (간결): 멤버 초기화 리스트로 contacts를 직접 초기화합니다.
//   pair<const string, int>가 map의 value_type과 정확히 일치하므로 타입 변환 없이 바로 사용됩니다.
//     : contacts(lst)
//
// 구현 방법 B (반복문): lst를 직접 순회하여 각 항목을 삽입합니다.
//   for (const auto& [name, num] : lst) { contacts[name] = num; }
//     structured binding (C++17): [name, num]으로 pair를 한 번에 분해합니다.

Phonebook::Phonebook(std::initializer_list<std::pair<const std::string, int>> lst) for(const auto& [name, num] : lst) { contacts[name] = num; }//: contacts()
// contacts[lst]
{

}

// [print] contacts의 모든 항목을 "이름 나이\n" 형식으로 출력합니다.
// std::map은 key(이름)를 알파벳순으로 자동 정렬하므로 별도 정렬 코드가 필요 없습니다.
// 힌트: for (const auto& [name, num] : contacts) { ... }
void Phonebook::print() const {
    for(const auto& [name, num] : contacts) {
        std::cout << name << " " << num << '\n';
    }
}
