#include "tetris.h"

Board::Board() {
}

bool Board::inBounds(Position position) const {
    return position.x >= 0 && position.x < BOARD_WIDTH &&
           position.y >= 0 && position.y < BOARD_HEIGHT;
}

char Board::cell(Position position) const {
    if (!inBounds(position)) {
        return '?';
    }
    return cells_[position.y][position.x];
}

void Board::setCell(Position position, char value) {
    if (!inBounds(position)) {
        return;
    }
    cells_[position.y][position.x] = value;
}

std::string Board::toText() const {
    std::string result = "+----------+\n";
    for (const auto& row : cells_) {
        result += '|';
        for (char cell : row) {
            result += (cell == '\0') ? '.' : cell;
        }
        result += "|\n";
    }
    result += "+----------+\n";
    return result;
}

Piece::Piece() : shape_({{1, 1, 1, 1}}) {
}

const std::vector<std::vector<int>>& Piece::shape() const {
    return shape_;
}

void init_game(GameState& state) {
    state = GameState{};
    
    for (int y = 0; y < BOARD_HEIGHT; ++y) {
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            state.board.setCell({x, y}, '.');
        }
    }
}

std::string board_to_string(const GameState& state) {
    Board rendered = state.board;
    
    const auto& shape = state.current_piece.shape();
    for (size_t y = 0; y < shape.size(); ++y) {
        for (size_t x = 0; x < shape[y].size(); ++x) {
            if (shape[y][x] == 0) continue;
            
            Position pos{
                static_cast<int>(state.piece_position.x + static_cast<int>(x)),
                static_cast<int>(state.piece_position.y + static_cast<int>(y))
            };
            
            if (rendered.inBounds(pos)) {
                rendered.setCell(pos, '#');
            }
        }
    }
    
    return rendered.toText();
}
