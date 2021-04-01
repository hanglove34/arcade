//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// Nibbler
//

#include "nibbler.hpp"

Nibbler::Nibbler()
{
    _score = 0;
    _color["red"] = Arcade::Color(255, 0, 0, 255, "Red");
    _color["green"] = Arcade::Color(0, 255, 0, 255, "Green");
    _color["blue"] = Arcade::Color(0, 0, 255, 255, "Blue");
    _color["white"] = Arcade::Color(255, 255, 255, 255, "White");
    _color["grey"] = Arcade::Color(169, 169, 169, 255, "Grey");
    _color["black"] = Arcade::Color(0, 0, 0, 255, "Black");
    _apple[0] = new Arcade::Circle(8.0, Arcade::Vector2f(xbase + 16, ybase + 16), _color["red"]);    
    _rect[0] = new Arcade::Rectangle(Arcade::Vector2f(16,16), Arcade::Vector2f(xbase,ybase), _color["white"]);
    _text[0] = new Arcade::Text("Score : " + std::to_string(_score), _color["white"], Arcade::Vector2f(800,200), 50);
    _text[1] = new Arcade::Text("Move snake use : <- and ->", _color["white"], Arcade::Vector2f(100,800), 30);
    _text[2] = new Arcade::Text("For increase the speed of the snake use : space", _color["white"], Arcade::Vector2f(100,830), 30);
    _text[3] = new Arcade::Text("For put in restart use : R", _color["white"], Arcade::Vector2f(100,860), 30);
    _text[4] = new Arcade::Text("For put in pause use : P", _color["white"], Arcade::Vector2f(100,890), 30);
    _text[5] = new Arcade::Text("Back to the menu use : M",_color["white"], Arcade::Vector2f(100,920), 30);
    _text[6]= new Arcade::Text("For leave all use : escape", _color["white"], Arcade::Vector2f(100,950), 30);
}

Nibbler::~Nibbler()
{
}

void Nibbler::init()
{
    if (_snake.size() > 0)
        _snake.clear();
    _snake[0] = new Arcade::Circle(8.0, Arcade::Vector2f(xbase + xsnake + 16, ybase + ysnake + 16), _color["green"]);
    _snake[1] = new Arcade::Circle(8.0, Arcade::Vector2f(xbase + xsnake + 16, ybase + ysnake + 16 - 16), _color["green"]);
    _snake[2] = new Arcade::Circle(8.0, Arcade::Vector2f(xbase + xsnake + 16, ybase + ysnake + 16 - 32), _color["green"]);
    _snake[3] = new Arcade::Circle(8.0, Arcade::Vector2f(xbase + xsnake + 16, ybase + ysnake + 16 - 48), _color["green"]);
    randMap();
    _ymap = -1 * (((float)_map.size()) * 16);
    srand(time(NULL));
    generateApple();
    _score = 0;
    _text[0]->setString("Score : " + std::to_string(_score));
    _direction = 2;
    _space = 15;
}
void Nibbler::stop()
{
}
void *Nibbler::getHandle() const
{
    return (_handle);
}
void Nibbler::setHandle(void *handle)
{
    _handle = handle;
}
void Nibbler::setName(std::string handle)
{
    _name = handle;
}
const std::string &Nibbler::getName() const
{
    return (_name);
}
void Nibbler::updateInput(Arcade::Input &input)
{
    if (input == Arcade::Input::LEFT) {// monte = 0, gauche = 1, bas = 2, droite = 3
        if (_direction == 3)
            _direction = 0;
        else
            _direction++;
    }
    else if (input == Arcade::Input::RIGHT) {
        if (_direction == 0)
            _direction = 3;
        else
            _direction--;
    }
    if (input == Arcade::Input::Space)
    {
        if (_space == 9)
            _space = 15;
        else
            _space = 9;
    }
    if (input == Arcade::Input::R)
        init();
}

bool Nibbler::verAppleXPos(std::map<int, int> checkmap, int appleX)
{
    int d = 0;
    int ver1 = 0;
    int ver2 = 0;
    for (auto check : checkmap)
    {
        if (d == 0)
            ver1 = check.second;
        else
        {
            if (ver1 > appleX && appleX < check.second)
                return (0);
            ver1 = check.second;
        }
    }
    return (1);
}

bool Nibbler::checkPosApple(int appleX, int appleY)
{
    std::map<int, int> check;
    int d = 0;
    int ver = 0;
    for (int i = 0; i < _map[appleY].length(); i++)
    {
        if (_map[appleY][i] == '1')
        {
            check[d] = i;
            d++;
        }
    }
    if (verAppleXPos(check, appleX))
        return (0);
    return(1);
}

void Nibbler::generateApple()
{
    //il est possible que x ou y soit a 0 est donc pour le calcul de la position de la pomme soit dans le mur
    //gerer si x ou y soit different de 0 si ca arrive
    int y = (int)_map.size();
    int x = (int)_map[0].size();
    int appleX = 0;
    int appleY = 0;
    appleX = rand() % x;
    appleY = rand() % y;
    while(checkPosApple(appleX, appleY) || _map[appleY][appleX] == '1' || appleX == 0 || appleY == 0){
        appleX = rand() % x;
        appleY = rand() % y;
    }
    // std::cout << "x : " << appleX * 16 + xbase << " / y : " << appleY * 16 + ybase << " => " << _map[appleY][appleX] << std::endl;
    _apple[0]->setPosition(Arcade::Vector2f(appleX * 16 + xbase, appleY * 16 + ybase));
}

void Nibbler::moveSnake()
{
    Arcade::Vector2f save;
    Arcade::Vector2f save2;
    save = _snake[0]->getPosition();
    int d = 0;
    (_direction < 2) ?
    ((_direction == 0) ? /*monte*/_snake[0]->move(Arcade::Vector2f(0,-16)) : /*gauche*/_snake[0]->move(Arcade::Vector2f(-16,0))) :
    ((_direction == 2) ? /*monte*/_snake[0]->move(Arcade::Vector2f(0,16)) : /*droite*/_snake[0]->move(Arcade::Vector2f(16,0))) ;
    for (auto snake = _snake.begin(); snake != _snake.end(); snake++)
    {
        if (d == 0)
            d++;
        else
        {
            save2 = snake->second->getPosition();
            snake->second->setPosition(save);
            save = save2;
        }

    }
}

void Nibbler::newPartSnake()
{
    int sizeAdd = rand() % 4;
    while (sizeAdd == 0)
        sizeAdd = rand() % 4;
    for (;sizeAdd != 0; sizeAdd--)
        _snake[_snake.size()] = new Arcade::Circle(8.0, Arcade::Vector2f(-200,-200), _color["green"]);
}

void Nibbler::snakeEat()
{
    for(auto apple : _apple)
    {
        if (apple.second->getPosition().x == _snake[0]->getPosition().x && apple.second->getPosition().y == _snake[0]->getPosition().y)
        {
            generateApple();
            _score++;
            _text[0]->setString("Score : " + std::to_string(_score));
            newPartSnake();
        }
    }
}

bool Nibbler::eatSelf()
{
    int d = 0;
    for(auto snake : _snake)
    {
        if (d == 0)
            d++;
        else
        {
            if (snake.second->getPosition().x == _snake[0]->getPosition().x && snake.second->getPosition().y == _snake[0]->getPosition().y)
                return (1);
        }
    }
    return (0);
}

int Nibbler::updateGame(IDisplayModule *_Dinstance)
{
    static double long sec = 0;
    double long ti = _Dinstance->getDeltaTime();

    sec += ti / 10000.0;

    if (sec > _space) {
        sec = 0.0;
        moveSnake();
        if (_map[(_snake[0]->getPosition().y - ybase)/ 16][(_snake[0]->getPosition().x - xbase) / 16] == '1' || eatSelf())
        {
            std::cout << "Dead man you are bad" << std::endl;
            return (_score);
        }
        snakeEat();
    }
    return (-1);//-1 quand ca joue et return  le scor quand c'est fini
}

void Nibbler::displayGame(IDisplayModule *_Dinstance)
{
    for(auto snake : _snake)
        _Dinstance->drawCircle(*snake.second);
    for(auto apple : _apple)
        _Dinstance->drawCircle(*apple.second);
    for(auto text : _text)
        _Dinstance->drawText(*text.second);
    for(auto test : _map)
    {
        for(int i = 0; i < test.second.length(); ++i)
        {
            char c = test.second[i];
            if (c == '1') {
                _Dinstance->drawRectangle(*_rect[0]);
                _rect[0]->move(Arcade::Vector2f(16,0));
            } else
                _rect[0]->move(Arcade::Vector2f(16,0));
        }
        _rect[0]->move(Arcade::Vector2f(_ymap,16));
    }
    _rect[0]->setPosition(Arcade::Vector2f(xbase,ybase));
}

void Nibbler::drawGame(IDisplayModule *_Dinstance)
{
    displayGame(_Dinstance);
}

//--------------------------------------------------------------------------
IGameModule *mod = nullptr;
int gamecheck;

extern "C"
{
    IGameModule *entryPoint()
    {
        return mod;
    }
}

__attribute__((constructor))
void constructor()
{
    mod = new Nibbler;
}

__attribute__((destructor))
void destructor()
{
    delete mod;
}
