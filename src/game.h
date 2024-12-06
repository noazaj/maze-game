#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

class Game {
    private:
        int x;
        int y;
        sf::RenderWindow window;
        std::vector<std::unique_ptr<sf::Music>> compiled_music;

    public:
        Game(int width, int height);
        void run();
};
