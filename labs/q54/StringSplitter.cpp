#include "StringSplitter.h"
#include <cctype>
#include <sstream>
#include <vector>

// TODO: 아래 함수들을 구현하세요.
// trim(), replaceSubstring(), removePunctuation() 은 *this 를 반환하여
// 메서드 체이닝을 가능하게 합니다.

StringSplitter::StringSplitter(const std::string &str)
{
    // data_ 에 입력 문자열을 저장합니다.
    data_ = str;
}

StringSplitter &StringSplitter::trim()
{
    // data_ 의 앞뒤 공백을 제거합니다.
    // 힌트: find_first_not_of(' ') 와 find_last_not_of(' ') 사용
    // 반드시 return *this; 로 끝내세요.
    size_t start = data_.find_first_not_of(' ');
    size_t end = data_.find_last_not_of(' ');

    if (start == std::string::npos) {
        data_ = "";
    } else {
        data_ = data_.substr(start, end - start + 1);
    }
    return *this;
}

StringSplitter &StringSplitter::replaceSubstring(const std::string &from,
                                                 const std::string &to)
{
    // data_ 에서 from 을 찾아 to 로 교체합니다 (첫 번째 등장만).
    // 힌트: data_.find(from) 으로 위치를 찾고
    //       data_.replace(pos, from.length(), to) 로 교체
    // from 이 없으면 아무 것도 하지 않습니다.
    auto find_from = data_.find(from);
    if(find_from != std::string::npos) {
        data_.replace(find_from, from.length(), to) ;
    }
    
    return *this;   
}

StringSplitter &StringSplitter::removePunctuation()
{
    // data_ 에서 구두점 문자를 모두 제거합니다.
    // 힌트: std::ispunct(c) 가 true 인 문자를 제거
    //       erase-remove 관용구 또는 std::erase_if(data_, ::ispunct) 사용
    // char은 signed or unsigned지만 std::ispunct()는 음수를 받지 못하기 때문에 unsigned char을 통해 c의 값을 양수로 고정해 줘야 한다.
    // ex) c = '0xFF' 는 unsigned라면 255지만 signed라면 -1이다. 두 개의 값 중에 선택해야 하기 
    std::erase_if(data_, [](char c) {
        return std::ispunct(static_cast<unsigned char >(c));
    }) ;
    return *this;
}

std::vector<std::string> StringSplitter::split(char delimiter) const
{
    // data_ 를 delimiter 기준으로 나눠 벡터로 반환합니다.
    // 빈 토큰은 포함하지 않습니다.
    // 힌트: std::istringstream 으로 getline(iss, token, delimiter) 반복
    std::vector<std::string> result;
    std::istringstream iss(data_);
    std::string token;

    while(getline(iss, token, delimiter)) {
        // token.empty() != 1 과 같은 문장으로 같은 결과를 도출할 수 있지만 가독성의 문제가 있다.
        if(!token.empty()) {
            result.push_back(token);
        }
    }
    return result;
}
//   Hello, World!