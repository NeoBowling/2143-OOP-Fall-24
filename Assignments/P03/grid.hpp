// grid.h
#ifndef GRID_H
#define GRID_H

#include <SFML/Graphics.hpp>
#include <vector>

class Grid {
private:
    int rows;
    int cols;
    float cellSize;     // Width and height of each cell
    float gridStartX;   // Starting X position of the grid
    float gridStartY;   // Starting Y position of the grid
    float cellSpacing;  // Spacing between cells
    float lineThickness;
    std::vector<sf::RectangleShape> grid;

    // Creates the grid by initializing the cells and setting their properties
    void createGrid();

public:
    // Constructors
    Grid(int r, int c, int cs, int gsx, int gsy, int space, int thick);
    Grid();

    // Getters
    int getRows();
    int getCols();
    sf::RectangleShape getCell(int row, int col);
};

#endif // GRID_H
