#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Game {
private:
    private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text welcomeText, instructionText, usernamePrompt, usernameText;
    sf::Music music;
    std::string username;

    void loadAssets();
    void handleWelcomeScreen();
    void handleUsernameInput();
    void handleMainMenu();
    void render();

    public:
    Game();
    ~Game();
    void run();
};

Game::Game() : window(sf::VideoMode(800, 600), "Knuckle Bones") {
    loadAssets();
}

void Game::loadAssets() {
    
    if (!font1.loadFromFile("media/font/Blacknorth.otf")) {
        std::cerr << "Error loading font1!" << std::endl;
        window.close();
    }

    if (!font2.loadFromFile("media/font/Blacknorth.otf")) {
        std::cerr << "Error loading font2!" << std::endl;
        window.close();
    }

    if (!backgroundmusic.openFromFile("media/music/Music.ogg")) {
        std::cerr << "Error loading music!" << std::endl;
        window.close();
    }

    if (!dieroll.openFromFile("media/music/dieroll.ogg")) {
        std::cerr << "Error loading dieroll sound effect!" << std::endl;
        window.close();
    }

    if (!StartUpSound.openFromFile("media/music/dieroll.ogg")) {
        std::cerr << "Error loading dieroll sound effect!" << std::endl;
        window.close();
    }


    sf::SoundBuffer diceRollBuffer;
        if (!diceRollBuffer.loadFromFile("media/sounds/dice_roll.wav")) {
        std::cerr << "Error loading dice roll sound!" << std::endl;
    }

sf::Sound diceRollSound;
diceRollSound.setBuffer(diceRollBuffer);
diceRollSound.play();


    // Welcome Text
    welcomeText.setFont(font1);
    welcomeText.setString("Welcome to Knuckle Bones!");
    welcomeText.setCharacterSize(48);
    welcomeText.setFillColor(sf::Color::Orange);
    welcomeText.setPosition(200.f, 100.f);

    // Instruction Text
    instructionText.setFont(font);
    instructionText.setString("Press any key to start.");
    instructionText.setCharacterSize(24);
    instructionText.setFillColor(sf::Color::Yellow);
    instructionText.setPosition(250.f, 250.f);

    // Username prompt
    usernamePrompt.setFont(font);
    usernamePrompt.setString("Enter your username:");
    usernamePrompt.setCharacterSize(30);
    usernamePrompt.setFillColor(sf::Color::White);
    usernamePrompt.setPosition(150.f, 200.f);

    // Username text (empty initially)
    usernameText.setFont(font);
    usernameText.setCharacterSize(30);
    usernameText.setFillColor(sf::Color::White);
    usernameText.setPosition(150.f, 250.f);
}

void Game::run() {
    music.setLoop(true);
    music.play();  // Play background music continuously
    handleWelcomeScreen();
    handleUsernameInput();
    handleMainMenu();
}

void Game::handleWelcomeScreen() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                return; // Proceed to username input
            }
        }
        render();
    }
}

void Game::handleUsernameInput() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == 13) {  // Enter key pressed
                    return; // Proceed to game menu
                }
                if (event.text.unicode == 8 && !username.empty()) {  // Backspace pressed
                    username.pop_back();
                } else if (event.text.unicode < 128) {
                    username += static_cast<char>(event.text.unicode);
                }
                usernameText.setString(username);
            }
        }
        render();
    }
}

void Game::handleMainMenu() {
    // Main menu options: Play Locally, Play vs Computer
    // You could add buttons and other interactive elements here later
    sf::Text menuText;
    menuText.setFont(font);
    menuText.setString("Main Menu:\n1. Play Locally\n2. Play vs Computer");
    menuText.setCharacterSize(30);
    menuText.setFillColor(sf::Color::Yellow);
    menuText.setPosition(250.f, 200.f);

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
    window.draw(welcomeText);
    window.draw(instructionText);
    window.draw(usernamePrompt);
    window.draw(usernameText);
    window.display();
}
Game::~Game() {
    music.stop();
}
int main() {
    try {
        Game game;
        game.run();
    } catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
