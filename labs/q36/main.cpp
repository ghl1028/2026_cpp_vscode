#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int score;
};

int main() {
    int n;
    std::cin >> n;

    std::vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> students[i].name >> students[i].score;
    }

    std::vector<Student> qualified;
    int index = 0;

    // TODO: while 문으로 students를 검사하며 90점 이상인 학생만 qualified에 넣으세요.
    while(index < n) {
        if(students[index].score >= 90) {
            qualified.push_back(students[index]) ;
            index++ ;
        }
        else index++ ;
    }


    //std::ranges::sort의 조건 문법을 조금 더 알아야 할 것 같다.
    std::ranges::sort(qualified, [](const Student& a, const Student& b) { //a, b 값이 각각 의미하는 바가 무엇인지
        if(a.score == b.score) return  a.name < b.name ;  // a.name < b.name이 의미하는 바가 무엇인지 알아야한다.
        return a.score > b.score ;   
    }) ;

    if(qualified.empty()) std::cout << "None" << '\n' ;
    else {
        for(auto list : qualified) {
            std::cout << list.name << " " << list.score << '\n' ;
        }
    }
    
    // TODO: qualified를 점수 내림차순, 이름 오름차순으로 정렬하세요.
    // TODO: qualified가 비어 있으면 None을 출력하고, 아니면 앞에서부터 최대 3명의 이름을 출력하세요.
    // TODO: 필요하면 std::sort 또는 std::ranges::sort를 사용할 수 있습니다.

    return 0;
}
