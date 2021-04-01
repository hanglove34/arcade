//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// Lib SFML
//

#ifndef SFML_LIB
#define SFML_LIB

#include <SFML/Graphics.hpp>
#include "My.hpp"

class SFML : public IDisplayModule
{
    public:
        sf::RenderWindow _window;
        std::string _name;
        void *_handle;
        long double _deltaTime;
        std::chrono::time_point<std::chrono::high_resolution_clock> _start;
        SFML();
        ~SFML();

        void init();
        void stop();
        void *getHandle() const;
        void setHandle(void *handle);
        void setName(std::string handle);
        const std::string &getName() const;


        void clearWindow();
        void displayWindow();

        void drawRectangle(Arcade::Rectangle &rectangle);
        void drawCircle(Arcade::Circle &circle);
        void drawText(Arcade::Text &text);
        void drawMenu();
        Arcade::Input coreInputs();
        void startClock();
        void setDeltaTime();
        const long double &getDeltaTime() const;
        std::string getPseudo() const  {};
        void setPseudo(const std::string)  {};
        int drawSprite(Arcade::Sprite sprite);
        int whatLib() {return 0;};
};

#endif
