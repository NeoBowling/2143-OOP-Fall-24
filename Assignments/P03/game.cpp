#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
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
    text.setOrigin(bounds.width / 2, bounds.height / 2);
}

void Game::loadAssets() {
    if (!font1.loadFromFile("media/font/Arial.ttf") ||
        !font2.loadFromFile("media/font/Blacknorth.otf") ||
        !font3.loadFromFile("media/font/BonyBones.ttf")) {
        std::cerr << "Error loading fonts!" << std::endl;
        window.close();
    }

    if (!backgroundMusic.openFromFile("media/music/Music.ogg") ||
        !startUp.openFromFile("media/music/StartUpSound.ogg") ||
        !dieroll.openFromFile("media/music/dieroll.ogg")) {
        std::cerr << "Error loading audio!" << std::endl;
        window.close();
    }

    // Welcome Text
    welcomeText.setFont(font3);
    welcomeText.setString("Welcome to Knuckle Bones!");
    welcomeText.setCharacterSize(48);
    welcomeText.setFillColor(sf::Color::Red);
    centerText(welcomeText);
    welcomeText.setPosition(window.getSize().x / 2, 100.f);

    // Instruction Text
    instructionText.setFont(font2);
    instructionText.setString("Press any key to continue.");
    instructionText.setCharacterSize(24);
    instructionText.setFillColor(sf::Color::White);
    instructionText.setPosition(window.getSize().x / 2 - 150, 450.f);

    // Play Button
    playButton.setSize(sf::Vector2f(200.f, 60.f));
    playButton.setFillColor(sf::Color::White);
    playButton.setPosition(300.f, 350.f);

    playButtonText.setFont(font2);
    playButtonText.setString("Play");
    playButtonText.setCharacterSize(36);
    playButtonText.setFillColor(sf::Color::Black);
    playButtonText.setPosition(playButton.getPosition().x + 50.f, playButton.getPosition().y + 10.f);

    // Roll Button
    rollButton.setSize(sf::Vector2f(120.f, 50.f));
    rollButton.setFillColor(sf::Color::White);
    rollButton.setPosition(340.f, 500.f);

    rollButtonText.setFont(font2);
    rollButtonText.setString("ROLL!");
    rollButtonText.setCharacterSize(24);
    rollButtonText.setFillColor(sf::Color::Black);
    rollButtonText.setPosition(rollButton.getPosition().x + 30.f, rollButton.getPosition().y + 10.f);
}

void Game::run() {
    backgroundMusic.setLoop(true);
    backgroundMusic.play();

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
                sf::Vector2i mouse = sf::Mouse::getPosition(window);
                if (playButton.getGlobalBounds().contains(static_cast<float>(mouse.x), static_cast<float>(mouse.y))) {
                    showGameScreen = true;
                }
            }
        }

        render();
    }
}

void Game::handleGameScreen() {
    bool isRolling = false;
    sf::Clock animationClock;
    size_t currentFrame = 0;

    // Vector to store dice frame textures
    std::vector<sf::Texture> textures;

    // Declare sprite outside the loop so it can be accessed in both the event loop and animation update
    sf::Sprite sprite;

    // Load textures only when roll button is pressed
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mouse = sf::Mouse::getPosition(window);
                if (rollButton.getGlobalBounds().contains(static_cast<float>(mouse.x), static_cast<float>(mouse.y))) {
                    // If roll button is clicked, load textures and start animation
                    textures.clear();  // Clear previous textures (if any)

                    // Load textures for the animation
                    for (int i = 1; i <= 24; ++i) {
                        sf::Texture texture;
                        std::string filename = (i < 10) ? "00" + std::to_string(i) + ".png" : "0" + std::to_string(i) + ".png";
                        if (!texture.loadFromFile("media/images/frame_" + filename)) {
                            std::cerr << "Error loading frame" << i << ".png" << std::endl;
                            return;  // Exit the function if an error occurs
                        }
                        textures.push_back(texture);
                    }

                    // Create sprite to display the dice animation
                    sprite.setTexture(textures[0]);  // Start with the first frame
                    sprite.setPosition(300.f, 200.f);  // Adjust position as needed
                    isRolling = true;
                    animationClock.restart();  // Reset animation clock
                    currentFrame = 0;  // Start from the first frame
                }
            }
        }

        // Update the animation if it's rolling
        if (isRolling) {
            // Get elapsed time since the clock was restarted
            sf::Time elapsedTime = animationClock.getElapsedTime();

            // Change frame based on elapsed time
            if (elapsedTime.asMilliseconds() >= 50) {  // Update every 50 ms
                currentFrame++;
                if (currentFrame >= textures.size()) {
                    currentFrame = textures.size() - 1;  // Stay on the last frame
                    isRolling = false;  // Stop the animation after the last frame
                }

                sprite.setTexture(textures[currentFrame]);  // Set the current frame texture
                animationClock.restart();  // Restart the clock for the next frame
            }
        }

        render();  // Render the current frame of the animation
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
