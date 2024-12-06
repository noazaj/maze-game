#include "game.h"

#include <SFML/System.hpp>

Game::Game(int width, int height) 
    : x(width), y(height), window(sf::VideoMode(width, height), "Maze Runner") {
    std::vector<std::string> music_files;
    std::string path = "music";

    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_regular_file() && entry.path().extension() == ".mp3") {
            music_files.push_back(entry.path().string());
        }
    }

    for (size_t i = 0; i < music_files.size(); i++) {
        auto music = std::make_unique<sf::Music>();
        if (!music->openFromFile(music_files[i])) {
            std::cerr << "Couldn't load music file: " << music_files[i] << std::endl; 
        } else {
            compiled_music.push_back(std::move(music));
        }
    }
}

void Game::run()
{
    if (!compiled_music.empty()) {
        compiled_music[3]->play();
    }

    sf::Image standing_image;
    if (!standing_image.loadFromFile("/Users/noahzajicek/maze-game/images/3 Dude_Monster/Dude_Monster.png")) {
        std::cout << "Couldn't load character image\n";
        exit(1);
    }
    sf::Texture texture;
    texture.loadFromImage(standing_image);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);


    float left_bound = 0.f;
    float right_bound = window.getSize().x - sprite.getGlobalBounds().width;

    bool left = false, right = true;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)) {
                    sf::FloatRect bounds = sprite.getGlobalBounds();
                    if (bounds.left > left_bound) {
                        sprite.move(-10.f, 0.f);
                    }

                    if (!left) {
                        sprite.setOrigin(sprite.getLocalBounds().width, sprite.getLocalBounds().height / 2);
                        sprite.scale(-1.f, 1.f);
                        left = true;
                        right = false;
                    }
                } 
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)) {
                    sf::FloatRect bounds = sprite.getGlobalBounds();
                    if (bounds.left < right_bound) {
                        sprite.move(10.f, 0.f);
                    }

                    if (!right) {
                        sprite.setOrigin(0.f, sprite.getLocalBounds().height / 2);
                        sprite.scale(-1.f, 1.f);
                        left = false;
                        right = true;
                    }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)) {
                    sprite.move(0.f, -10.f);
                }
                else {
                    sprite.move(0.f, 10.f);
                }
                break;
            
            default:
                break;
            }
        }

        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.display();
    }
}
