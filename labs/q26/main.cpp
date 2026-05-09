#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> values(n);

    // TODO: n개의 정수를 입력받아 values에 저장하세요.
    for(int i = 0; i < n; i++) {
        // std::cin >> values[i] ;
        int num ;
        std::cin >> num ;
        values.push_back(num) ;
    }
    // TODO: std::sort를 사용해 values를 오름차순으로 정렬하세요.

    // std::ranges::sort.values ;
    // TODO: 정렬된 결과를 공백으로 구분해 한 줄에 출력하세요.
    for(int i = 0; i < n; i++) {
        std::cout << values[i] << " " ;
    }

    return 0;
}