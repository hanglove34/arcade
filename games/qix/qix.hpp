//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// Qix
//

#ifndef NIBLER
#define NIBLER

#include "My.hpp"

#define xbase 32
#define ybase 48
#define xsnake 24//592
#define ysnake 24

class Qix : public IGameModule
{
private:
    int _direction;
    int _score;
    std::string _name;
    void *_handle;
    std::map<int, std::string> _map;
    std::map<int, Arcade::Circle *> _snake;
    std::map<int, Arcade::Circle *> _apple;
    std::map<int, Arcade::Rectangle *> _rect;
    std::map<int, Arcade::Text *> _text;
    std::map<std::string, Arcade::Color> _color;
    long double _ymap;
public:
    Qix();
    ~Qix();
    void init();
    void stop();
    void *getHandle() const;
    void setHandle(void *handle);
    void setName(std::string handle);
    const std::string &getName() const;
    void updateInput(Arcade::Input &input);
    int updateGame(IDisplayModule *_Dinstance);
    void drawGame(IDisplayModule *_Dinstance);
    void displayGame(IDisplayModule *_Dinstance);
    void moveSnake();
    void newPartSnake();
    void enLargeYourSnake();
    int whatLib() {return 1;};
};

#endif
