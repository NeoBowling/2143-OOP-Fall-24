#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "grid.hpp"

class Game {
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text welcomeText, instructionText, playButton;
    sf::RectangleShape rollButton;

    Grid player1Grid;
    Grid player2Grid;

    bool showMainMenu;
    bool showGameScreen;

    void loadAssets();
    void handleWelcomeScreen();
    void handleMainMenu();
    void handleGameScreen();
    void render();
    void centerText(sf::Text &text);

public:
    Game();
    void run();
};

Game::Game() 
    : window(sf::VideoMode(800, 600), "Knuckle Bones"),
      player1Grid(3, 3, 80, 50, 150, 10, 2),   // Player 1 grid
      player2Grid(3, 3, 80, 450, 150, 10, 2),  // Player 2 grid
      showMainMenu(false), showGameScreen(false) {
    loadAssets();
}

void Game::centerText(sf::Text &text) {
    sf::FloatRect bounds = text.getLocalBounds();
    sf::Vector2u windowSize = window.getSize();
    text.setOrigin(bounds.width / 2, bounds.height / 2);
    text.setPosition(windowSize.x / 2, windowSize.y / 2);
}

void Game::loadAssets() {
    if (!font.loadFromFile("media/font/arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        window.close();
    }

    // Welcome Text
    welcomeText.setFont(font);
    welcomeText.setString("Welcome to Knuckle Bones!");
    welcomeText.setCharacterSize(48);
    welcomeText.setFillColor(sf::Color::White);
    centerText(welcomeText);

    // Instruction Text
    instructionText.setFont(font);
    instructionText.setString("Press any key to continue.");
    instructionText.setCharacterSize(24);
    instructionText.setFillColor(sf::Color::Yellow);
    instructionText.setPosition(250.f, 300.f);

    // Play Button
    playButton.setFont(font);
    playButton.setString("Play");
    playButton.setCharacterSize(36);
    playButton.setFillColor(sf::Color::White);
    centerText(playButton);

    // Roll Button
    rollButton.setSize(sf::Vector2f(120.f, 50.f));
    rollButton.setFillColor(sf::Color::Green);
    rollButton.setPosition(340.f, 500.f);
}

void Game::run() {
    handleWelcomeScreen();
    handleMainMenu();
    handleGameScreen();
}

void Game::handleWelcomeScreen() {
    while (window.isOpen() && !showMainMenu) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                showMainMenu = true;
            }
        }

        render();
    }
}

void Game::handleMainMenu() {
    while (window.isOpen() && !showGameScreen) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (playButton.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                    showGameScreen = true;
                }
            }
        }

        render();
    }
}

void Game::handleGameScreen() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        render();
    }
}

void Game::render() {
    window.clear(sf::Color::Black);

    if (!showMainMenu) {
        window.draw(welcomeText);
        window.draw(instructionText);
    } else if (!showGameScreen) {
        window.draw(playButton);
    } else {
        player1Grid.draw(window);
        player2Grid.draw(window);
        window.draw(rollButton);
    }

    window.display();
}

int main() {
    Game game;
    game.run();
    return 0;
}
