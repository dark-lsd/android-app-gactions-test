//
// Created by ariyaltharun on 10/18/25.
//

#ifndef BALL_BALANCING_GAME_GRID_HPP
#define BALL_BALANCING_GAME_GRID_HPP

#include <vector>
#include <raylib.h>

class Grid {
private:
    int row = 0; // Denotes Y Axis
    int col = 0; // Denotes X Axis
    int cellSz = 0;
    std::vector<std::vector<int>> grid;
    Vector3 startPos;
    Vector3 endPos;
public:
    Grid();
    void designGrid();
    void draw();
    Vector3 getStartPos();
    ~Grid();
};

#endif //BALL_BALANCING_GAME_GRID_HPP
