#include <iostream>

int main() {
    int score;
    std::cin >> score;
    if(score < 0 || score > 100) return -1 ;

    // TODO: score 값에 따라 A, B, C, D, F 중 하나를 출력하세요.
    if     (score >= 90) std::cout << "A" << '\n' ;
    else if(score >= 80) std::cout << "B" << '\n' ;
    else if(score >= 70) std::cout << "C" << '\n' ;
    else if(score >= 60) std::cout << "D" << '\n' ;
    else                 std::cout << "F" << '\n' ;
    // 90 이상은 A, 80 이상은 B, 70 이상은 C, 60 이상은 D, 그보다 작으면 F 입니다.

    return 0;
}
