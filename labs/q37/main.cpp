#include <iostream>
#include <map>
#include <string>

int main() {
    int n;
    std::cin >> n;
    if(n < 0) return -1 ;

    std::map<std::string, int> counts;

    // TODO: 단어 n개를 입력받아 counts[word] 를 증가시키세요.
    for(auto i = 0; i < n; i++) {
        std::string word ;
        std::cin >> word ;
        counts[word]++ ;
    }
    // TODO: for 문으로 map 을 순회하며 "단어 개수" 형식으로 출력하세요.
    for(const auto& [word, cnt] : counts) {
        std::cout << word << " " << cnt << '\n' ;
    }

    return 0;
}
