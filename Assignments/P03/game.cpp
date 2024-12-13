#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "grid.hpp"

class Game {
private:
    sf::RenderWindow window;
    sf::Font font1, font2, font3;
    sf::Text welcomeText, instructionText, playButtonText, rollButtonText;
    sf::RectangleShape rollButton, playButton;
    sf::Music backgroundMusic, dieroll, startUp;
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
    if (!font1.loadFromFile("media/font/Arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        window.close();
    }

    if (!font2.loadFromFile("media/font/Blacknorth.otf")) {
        std::cerr << "Error loading font!" << std::endl;
        window.close();
    }

    if (!font3.loadFromFile("media/font/BonyBones.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        window.close();
    }

    if (!backgroundMusic.openFromFile("media/music/Music.ogg")) {
        std::cerr << "Error loading music!" << std::endl;
        window.close();
    }

    if (!startUp.openFromFile("media/music/StartUpSound.ogg")) {
        std::cerr << "Error loading Start Up VSX!" << std::endl;
        window.close();
    }

    if (!dieroll.openFromFile("media/music/dieroll.ogg")) {
        std::cerr << "Error loading die roll VSX!" << std::endl;
        window.close();
    }

    // Welcome Text
    welcomeText.setFont(font3);
    welcomeText.setString("Welcome to Knuckle Bones!");
    welcomeText.setCharacterSize(48);
    welcomeText.setFillColor(sf::Color::Red);
    centerText(welcomeText);

    // Instruction Text
    instructionText.setFont(font2);
    instructionText.setString("Press any key to continue.");
    instructionText.setCharacterSize(24);
    instructionText.setFillColor(sf::Color::White);
    instructionText.setPosition(250.f, 450.f);

    // Play Button
    playButton.setSize(sf::Vector2f(200.f, 60.f));
    playButton.setFillColor(sf::Color::White);
    playButton.setPosition(300.f, 350.f);

    playButtonText.setFont(font2);
    playButtonText.setString("Play");
    playButtonText.setCharacterSize(36);
    playButtonText.setFillColor(sf::Color::Black);
    centerText(playButtonText);
    playButtonText.setPosition(playButton.getPosition().x + playButton.getSize().x / 2,
                               playButton.getPosition().y + playButton.getSize().y / 4);

    // Roll Button
    rollButton.setSize(sf::Vector2f(120.f, 50.f));
    rollButton.setFillColor(sf::Color::White);
    rollButton.setPosition(340.f, 500.f);

    rollButtonText.setFont(font2);
    rollButtonText.setString("ROLL!");
    rollButtonText.setCharacterSize(24);
    rollButtonText.setFillColor(sf::Color::Black);
    centerText(rollButtonText);
    rollButtonText.setPosition(rollButton.getPosition().x + rollButton.getSize().x / 2,
                               rollButton.getPosition().y + rollButton.getSize().y / 4);
}

void Game::run() {
    handleWelcomeScreen();
    handleMainMenu();
    backgroundMusic.setLoop(true);
    backgroundMusic.play();
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
                startUp.play();
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
                sf::Vector2f mouse(sf::Mouse::getPosition(window));
                if (playButton.getGlobalBounds().contains(mouse)) {
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
        window.draw(playButtonText);
    } else {
        player1Grid.draw(window);
        player2Grid.draw(window);
        window.draw(rollButton);
        window.draw(rollButtonText);
    }

    window.display();
}

int main() {
    Game game;
    game.run();
    return 0;
}
