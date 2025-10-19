//
// Created by ariyaltharun on 10/18/25.
//
#include <grid.hpp>
#include <logger.hpp>

Grid::Grid() {
    LOGI("Initialize grid object");
    row = 10;
    col = 11;
    cellSz = 50;
    xLimit = col*cellSz;
    yLimit = row*cellSz;
    grid = std::vector(row, std::vector<int>(col, 0));
    startPos = {4*cellSz+cellSz/2.0f, 7*cellSz+cellSz/2.0f, 0.0f};
    designGrid();
}

void Grid::draw() {
    for (int r=0; r<row; r++) {
        for (int c=0; c<col; c++) {
            Color color;
            // DrawRectangle(c*cellSz, r*cellSz, cellSz, cellSz, YELLOW);
            if (grid[r][c] == 0) continue;
            switch (grid[r][c]) {
                case 1:
                    color = BROWN;
                    break;
                case 2:
                    color = BLUE;
                    break;
                case 3:
                    color = GREEN;
                    break;
            }
            DrawCube(Vector3{ (float)c*cellSz+cellSz/2.0f, (float)r*cellSz+cellSz/2.0f, 5.0f }, (float)cellSz, (float)cellSz, 10.0f, color);
        }
    }
}

void Grid::designGrid() {
    LOGI("Designing Game Grid");
    grid = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0},
            {0, 0, 0, 0, 1, 1, 1, 1, 3, 1, 0},
            {0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 2, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
}

int Grid::getCellSz() {
    return cellSz;
}

Vector3 Grid::getStartPos() {
    return startPos;
}

int Grid::getXLimit() {
    return xLimit-1;
}

int Grid::getYLimit() {
    return yLimit-1;
}

Grid::~Grid() {

}


