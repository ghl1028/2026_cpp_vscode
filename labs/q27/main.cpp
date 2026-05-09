#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> values(n);
    for (int& value : values) {
        std::cin >> value;
    }

    int remove_index;
    std::cin >> remove_index;
    if(remove_index > n) return -1 ;

    int remove_value;
    std::cin >> remove_value;

    // TODO: remove_index 위치의 원소를 삭제하세요.
    values.erase(values.begin() + remove_index) ;
    // TODO: C++23 기준으로 std::erase를 사용해 remove_value와 같은 값을 모두 삭제하세요.
    std::erase(values, remove_value) ;
    // TODO: 첫째 줄에 남은 원소 개수, 둘째 줄에 남은 원소를 공백으로 출력하세요.
    // int count = 0 ;
    // for(int i = 0; i < n; i++) {
    //     if(values[i] == remove_value) count++ ;
    // }

    // int vec_size = 0 ;
    // vec_size = n - count - 1 ;
    // std::cout << vec_size << '\n' ;
    std::cout << values.size() << '\n' ;
    for(int i = 0; i < values.size(); i++) {
        std::cout << values[i] << " " ;
    }


    return 0;
}