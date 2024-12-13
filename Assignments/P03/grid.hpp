#ifndef GRID_H
#define GRID_H

#include <SFML/Graphics.hpp>
#include <vector>

class Grid {
private:
    int rows;
    int cols;
    float cellSize;
    float gridStartX;
    float gridStartY;
    float cellSpacing;
    float lineThickness;
    std::vector<sf::RectangleShape> grid;

    void createGrid();

public:
    Grid(int r, int c, int cs, int gsx, int gsy, int space, int thick);
    Grid();

    int getRows();
    int getCols();
    sf::RectangleShape getCell(int row, int col);
    void draw(sf::RenderWindow &window); // Add this declaration
};

#endif // GRID_H
