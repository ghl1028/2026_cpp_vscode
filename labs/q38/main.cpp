#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> values;
    values.reserve(n);

    // TODO: std::copy_n 과 std::istream_iterator<int> 로 n개의 정수를 읽으세요.
    std::copy_n(
        std::istream_iterator<int>(std::cin) ,
        n,
        std::back_inserter(values)
    ) ;
    // TODO: 정렬한 뒤 std::copy 와 std::ostream_iterator<int> 로 한 줄에 하나씩 출력하세요.
    std::ranges::sort(values) ;
    // std::copy(
    // /* values 시작 */,
    // /* values 끝 */,
    // std::ostream_iterator<int>(std::cout, "\n")
    // );
    // std::copy(
    //     // values.begin(), values.end(),
    //     // std::ostream_iterator<int>(std::cout, "\n")
    // ) ;
    std::ranges::copy(values, std::ostream_iterator<int>(std::cout,"\n")) ;


    // 5
    // 4 1 3 2 5

    // int n ;
    // std::cin >> n ;
    
    // std::vector<std::string> strings ;
    
    // std::copy_n(std::istream_iterator<std::string>(std::cin), n, std::back_inserter(strings)) ;

    // for(auto list : strings) {
    //     std::cout << list.length() << "\n" ;
    // }

    // std::ranges::copy(strings, std::ostream_iterator<std::string>(std::cout, "\n")) ;

    return 0;
}
