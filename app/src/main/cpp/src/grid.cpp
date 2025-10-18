//
// Created by ariyaltharun on 10/18/25.
//
#include <grid.hpp>
#include <logger.hpp>

Grid::Grid() {
    LOGI("Initialize grid object");
    row = 10;
    col = 10;
    cellSz = 50;
    grid = std::vector(row, std::vector<int>(col, 0));
    startPos = {4*cellSz-cellSz/2.0f, 7*cellSz-cellSz/2.0f, 0.0f};
    designGrid();
}

void Grid::draw() {
    for (int r=0; r<row; r++) {
        for (int c=0; c<col; c++) {
            switch (grid[r][c]) {
                case 1:
                    DrawCube(Vector3{ (float)c*cellSz-cellSz/2.0f, (float)r*cellSz-cellSz/2.0f, 5.0f }, (float)cellSz, (float)cellSz, 1.0f, BROWN);
                    break;
                case 2:
                    DrawCube(Vector3{ (float)c*cellSz-cellSz/2.0f, (float)r*cellSz-cellSz/2.0f, 5.0f }, (float)cellSz, (float)cellSz, 1.0f, BLUE);
                    break;
                case 3:
                    DrawCube(Vector3{ (float)c*cellSz-cellSz/2.0f, (float)r*cellSz-cellSz/2.0f, 5.0f }, (float)cellSz, (float)cellSz, 1.0f, GREEN);
                    break;
            }
        }
    }
}

void Grid::designGrid() {
    LOGI("Designing Game Grid");
    grid = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 1, 1, 1},
            {0, 0, 0, 0, 1, 1, 1, 1, 3, 1},
            {0, 0, 0, 0, 1, 0, 0, 1, 1, 1},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
            {0, 0, 0, 1, 2, 1, 0, 0, 0, 0},
            {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
}

Vector3 Grid::getStartPos() {
    return startPos;
}

Grid::~Grid() {

}


