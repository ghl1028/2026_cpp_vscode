#include "tetris.h"

// void init_game(GameState& state) {
//     state = GameState{};  // block_x=4, block_y=0, running=true는 기본값으로 채워짐
//     // TODO: board를 BOARD_HEIGHT행 × BOARD_WIDTH열, 모두 '.'으로 초기화
//     // TODO: current_block = {{1, 1, 1, 1}}  (1행 4열 I 블록)
    
// }
void init_game(GameState& state) {
    state.board.assign(BOARD_HEIGHT, std::vector<char>(BOARD_WIDTH, '.'));
    state.block_x       = 4;
    state.block_y       = 0;
    state.current_block = {{1, 1, 1, 1}};   // I 블록, 네 칸
    state.running       = true;
}

// std::string board_to_string(const GameState& state) {
//     (void)state;
//     // TODO: state.board의 복사본을 만든다
//     // TODO: current_block을 [y][x] 순서로 순회하며 복사본에 '#'을 찍는다
//     //       board_x = block_x + x,  board_y = block_y + y
//     //       보드 범위를 벗어난 칸은 건너뛴다
//     // TODO: 복사본을 "+----------+\n| ... |\n" 형식의 문자열로 변환해 반환한다
//     return "";
// }
std::string board_to_string(const GameState& state) {
    auto rendered = state.board;

    for (int y = 0; y < static_cast<int>(state.current_block.size()); ++y) {
        for (int x = 0; x < static_cast<int>(state.current_block[y].size()); ++x) {
            if (state.current_block[y][x] == 0) continue;
            const int board_x = state.block_x + x;
            const int board_y = state.block_y + y;
            if (board_y >= 0 && board_y < BOARD_HEIGHT &&
                board_x >= 0 && board_x < BOARD_WIDTH) {
                rendered[board_y][board_x] = '#';
            }
        }
    }

    std::string result = "+----------+\n";
        for (const auto& row : rendered) {
            result += "|";
            for (char cell : row) result += cell;
            result += "|\n";
        }
    result += "+----------+\n";
    return result;
}