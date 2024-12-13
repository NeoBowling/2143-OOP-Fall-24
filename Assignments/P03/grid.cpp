#include "grid.hpp"

Grid::Grid(int r, int c, int cs, int gsx, int gsy, int space, int thick)
    : rows(r), cols(c), cellSize(cs), gridStartX(gsx), gridStartY(gsy),
      cellSpacing(space), lineThickness(thick) {
    createGrid();
}

void Grid::createGrid() {
    grid.clear(); // Clear any existing grid data if reinitializing
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
            cell.setPosition(gridStartX + col * (cellSize + cellSpacing),
                             gridStartY + row * (cellSize + cellSpacing));
            cell.setOutlineThickness(lineThickness);
            cell.setOutlineColor(sf::Color::White);
            cell.setFillColor(sf::Color::Transparent); // Default fill
            grid.push_back(cell);
        }
    }
}

void Grid::draw(sf::RenderWindow& window) {
    for (auto& cell : grid) {
        window.draw(cell);
    }
}
