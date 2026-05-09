#include "playlist.h"
#include <vector>
#include <algorithm>
#include <iostream>

// TODO: 아래 네 함수를 구현하세요.
// 재생 목록은 아래 static 변수로 관리합니다. 함수 파라미터로 전달하지 않습니다.
static std::vector<int> playlist;

void queue_song(int song_id) {
    // 재생 목록 끝에 song_id 추가
    playlist.push_back(song_id) ;
}

bool is_queued(int song_id) {
    // song_id가 재생 목록에 있으면 true 반환
    auto find_song = std::ranges::find(playlist, song_id) ;
    bool found_result = (find_song != playlist.end()) ;
    return found_result ;
}


// 첫 번째 등장하는 항목 제거 || 두 번쨰 등장하는 항목 제거 || 중간에 등장하는 항목 제거 || 전부 제거
void dequeue_song(int song_id) {
    // 재생 목록에서 song_id가 처음 등장하는 항목 제거 (없으면 아무 것도 하지 않음)
    auto find_song = std::ranges::find(playlist, song_id) ;
    if(find_song != playlist.end()) playlist.erase(find_song) ;

}

// 3
// 101 202 303
// 4
// CHECK 202
// QUEUE 404
// SKIP 101
// CHECK 101
void print_playlist() {
    // 재생 목록의 곡 ID를 한 줄에 하나씩 출력
    for(const auto& song : playlist) {
        std::cout << song << '\n' ;
    }
}
