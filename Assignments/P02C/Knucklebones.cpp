#include <ncurses.h>  // Ncurses library
#include "diceClass.hpp"     // Includes the animation for dice
#include "color_class.hpp"   // Enables colors
#include "gridClass.hpp"     // Enable grids to be drawn 
#include "input_class.hpp"
#include "buttonClass.hpp"
#include "logger_class.hpp"  // Logger utility
#include <fstream>           // File I/O
#include <iostream>          // Input/Output
#include <map>               // Map data structure
#include <string>            // String data structure
#include <vector>            // Vector data structure

using namespace std;

class Knucklebones {
private:
Grid player1grid;
Grid player2grid;
DiceViz dice;
int currentplayer;
Button rollbutton;

public: 
Knucklebones(){
    player1grid(),  // Initialize Player 1 grid with a position
    player2grid(),  // Initialize Player 2 grid with a position
    currentplayer(1),
    rollButton("Roll Dice", 2, 1, Frame({3, 15, 15, 5})),  // Initialize Roll button
    diceValue(0), rolling(false) {
    // Initialization of game components
    std::srand(std::time(nullptr)); // Seed random number generator
}
}

void drawInterface() {
    // Clear the screen
    clear();

    // Draw the two player grids
    player1grid.drawGrid();  // Draw Player 1's grid
    player2grid.drawGrid();  // Draw Player 2's grid

    // Display the current player's turn
    mvprintw(2, 10, "Player %d's turn", currentplayer);

    // Draw the Roll and Quit buttons
    rollButton.draw_button();
    quitButton.draw_button();

    // Display current dice value if dice was rolled
    if (rolling && diceValue > 0) {
        mvprintw(4, 10, "Rolled a %d!", diceValue);
    }

    refresh();
}

// Function to handle user input
void handleMouseInput() {
    int ch = getch();
    MEVENT event;

    switch (ch) {
        case KEY_MOUSE:
            if (getmouse(&event) == OK) {
                int mouseX = event.x;
                int mouseY = event.y;

                // Check if the Roll button was clicked
                if (rollButton.clicked(mouseY, mouseX)) {
                    Logger::log("Roll Button Clicked", "Rolling the dice");
                    rollDice();
                }

                // Check if a grid was clicked
                if (currentplayer == 1 && player1grid.clicked(mouseY, mouseX) && diceValue > 0) {
                    player1grid.addValue(mouseY, mouseX, diceValue);
                    updateGrid(diceValue);
                } else if (currentplayer == 2 && player2grid.clicked(mouseY, mouseX) && diceValue > 0) {
                    player2grid.addValue(mouseY, mouseX, diceValue);
                    updateGrid(diceValue);
                }
            }
            break;

        case 'q':  // Press 'q' to quit the game 
            endGame();
            break;

        default:
            break;
    }
}

// Function to roll the dice and display the result
void rollDice() {
    diceValue = dice.roll();  // Roll the dice using DiceViz
    rolling = true;  // Indicate that dice has been rolled
    Logger::log("Dice Rolled", std::to_string(diceValue));
    drawInterface();
}

// Function to update the grid and switch turns
void updateGrid(int diceValue) {
    // After placing the dice value, reset dice and switch player
    this->diceValue = 0;
    rolling = false;

    // Switch to the other player
    currentplayer = (currentplayer == 1) ? 2 : 1;
}

// Function to run the game
void runGame() {
    // Main game loop
    bool running = true;
    while (running) {
        drawInterface();  // Draw the game UI
        handleInput();    // Process user input
    }
}

// Function to handle game end
void endGame() {
    Logger::log("Game Ended", "Exiting game loop");
    endwin();  // End ncurses mode
    exit(0);   // Exit the game
}
void drawInterface() {}
void handleMouseInput() {
    int ch = getch();
    MEVENT event;

    switch (ch) {
        case KEY_MOUSE:
            if (getmouse(&event) == OK) {
                int mouseX = event.x;
                int mouseY = event.y;

                // Check if the Roll button was clicked
                if (rollButton.clicked(mouseY, mouseX)) {
                    Logger::log("Roll Button Clicked", "Rolling the dice");
                    rollDice();
                }


                // Check if a grid was clicked
                if (currentplayer == 1 && player1grid.clicked(mouseY, mouseX) && diceValue > 0) {
                    player1grid.addValue(mouseY, mouseX, diceValue);
                    updateGrid(diceValue);
                }
            }
            break;

        case 'q':  // Press 'q' to quit the game 
            endGame();
            break;

        default:
            break;
    }
}

void endGame(){
    void Knucklebones::endGame() {
    Logger::log("Game Ended", "Exiting game loop");
    endwin();  // End ncurses mode
    exit(0);   // Exit the game
}
}
};

// Function to run the game



// Function to handle game end


int main(){

    initscr();  // Start ncurses mode

    // Get terminal size
    getmaxyx(stdscr, height, width);

    Logger::log("height x width", vector<string>({std::to_string(height), to_string(width)}));

    noecho();     // Don't echo input
    cbreak();     // Disable line buffering
    curs_set(0);  // Hide the cursor

    setlocale(LC_ALL, "");  // Enable Unicode support

    start_color();  // enable colors in ncurses
    keypad(stdscr, TRUE);               // enable keypad for special keys
    mousemask(ALL_MOUSE_EVENTS, NULL);  // enable mouse events

    color = rand() % 32 + 1;
    attron(COLOR_PAIR(color));  // set color pair 1
    printw("This is a test for basic nucklebones components \n");
    refresh();
    attroff(COLOR_PAIR(color));  // unset color pair 1
}