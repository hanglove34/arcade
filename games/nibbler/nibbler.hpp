//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// Nibbler
//

#ifndef NIBLER
#define NIBLER

#include "My.hpp"

#define xbase 32
#define ybase 48
#define xsnake 304//592
#define ysnake 304

class Nibbler : public IGameModule
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
    int _space;
    long double _ymap;
public:
    Nibbler();
    ~Nibbler();
    void init();
    void stop();
    void *getHandle() const;
    void setHandle(void *handle);
    void setName(std::string handle);
    const std::string &getName() const;
    void updateInput(Arcade::Input &input);
    int updateGame(IDisplayModule *_Dinstance);
    void drawGame(IDisplayModule *_Dinstance);
    void generateApple();
    bool checkPosApple(int appleX, int appleY);
    bool verAppleXPos(std::map<int, int> checkmap, int appleX);
    void displayGame(IDisplayModule *_Dinstance);
    void moveSnake();
    void snakeEat();
    void newPartSnake();
    bool eatSelf();
    void randMap();
    void map0();
    void map1();
    int whatLib() {return 1;};
};
typedef std::map<int, void (Nibbler::*)(void)> script_map;

#endif
