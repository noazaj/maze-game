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
        Game(int width, int height) 
            : x(width), y(height), window(sf::VideoMode(width, height), "Maze Runner") {

            std::vector<std::string> music_files;
            std::string path = "music";
            for (const auto & entry : fs::directory_iterator(path)) {
                if (entry.is_regular_file() && entry.path().extension() == ".mp3") {
                    music_files.push_back(entry.path().string());
                }
            }

            for (size_t i = 0; i < music_files.size(); i++) {
                auto music = std::make_unique<sf::Music>();
                if (!music->openFromFile(music_files[i])) {
                    std::cerr << "Couldn't load music file: %s" << music_files[i] << std::endl; 
                } else {
                    compiled_music.push_back(std::move(music));
                }
            }
            
        }

        void run() {
            if (!compiled_music.empty()) {
                compiled_music[3]->play();
            }

            while (window.isOpen()) {
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                }
                window.clear(sf::Color::Black);
                window.display();
            }
        }
};

int main() 
{   

    Game game(600, 800);
    game.run();

    /*
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

            sf::Music music;
            if (!music.openFromFile("")) {
                return EXIT_FAILURE;
            }

            music.play();

            while (window.isOpen()) {
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                window.clear(sf::Color::Black);
                window.display();
            }
    */

    return 0;
}
