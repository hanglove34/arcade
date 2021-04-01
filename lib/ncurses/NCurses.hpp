/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** NCurses.hpp
*/

#ifndef NCURSES_LIB
#define NCURSES_LIB

#include "ncurses.h"
#include "My.hpp"

class NCurses : public IDisplayModule
{
    public:
        bool _isStopped;
        std::string _name;
        void *_handle;
        long double _deltaTime;
        std::chrono::time_point<std::chrono::high_resolution_clock> _start;
        std::vector<Arcade::Color> _colorPairs;

        NCurses();
        ~NCurses();

        void init();
        void stop();
        void *getHandle() const;
        void setHandle(void *handle);
        void setName(std::string name);
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

        int getColorIndex(Arcade::Color color);
        int getColorIndexForeground(Arcade::Color color);
        int whatLib() {return 0;};
};

#endif /* NCURSES_LIB */
