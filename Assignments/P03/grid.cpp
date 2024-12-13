#include "grid.h"

Grid::Grid(int r, int c, int cs, int gsx, int gsy, int space, int thick)
    : rows(r), cols(c), cellSize(cs), gridStartX(gsx), gridStartY(gsy), 
      cellSpacing(space), lineThickness(thick) {
    createGrid();
}

Grid::Grid() : rows(3), cols(3), cellSize(100), gridStartX(100), gridStartY(100), 
               cellSpacing(10), lineThickness(2) {
    createGrid();
}

void Grid::createGrid() {
    grid.clear();
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
            cell.setPosition(gridStartX + col * (cellSize + cellSpacing), gridStartY + row * (cellSize + cellSpacing));
            cell.setOutlineColor(sf::Color::White);
            cell.setOutlineThickness(lineThickness);
            cell.setFillColor(sf::Color::Transparent);
            grid.push_back(cell);
        }
    }
}

int Grid::getRows() {
    return rows;
}

int Grid::getCols() {
    return cols;
}

sf::RectangleShape Grid::getCell(int row, int col) {
    int index = row * cols + col;
    if (index >= 0 && index < grid.size()) {
        return grid[index];
    }
    return sf::RectangleShape();
}

// Implementation of the draw function
void Grid::draw(sf::RenderWindow &window) {
    for (auto &cell : grid) {
        window.draw(cell);
    }
}
