//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// Qix
//

#include "qix.hpp"

Qix::Qix()
{
    _score = 0;
    _color["red"] = Arcade::Color(255, 0, 0, 255, "red");
    _color["green"] = Arcade::Color(0, 255, 0, 255, "green");
    _color["blue"] = Arcade::Color(0, 0, 255, 255, "blue");
    _color["white"] = Arcade::Color(255, 255, 255, 255, "white");
    _color["grey"] = Arcade::Color(169, 169, 169, 255, "grey");
    _color["black"] = Arcade::Color(0, 0, 0, 255, "black");
    _snake[0] = new Arcade::Circle(8.0, Arcade::Vector2f(xbase + 24, ybase + 32), _color["green"]);
    _rect[0] = new Arcade::Rectangle(Arcade::Vector2f(16,16), Arcade::Vector2f(xbase,ybase), _color["white"]);
    _text[0] = new Arcade::Text("Score : " + std::to_string(_score), _color["white"], Arcade::Vector2f(800,200), 50);
    _direction = 2;

}

Qix::~Qix()
{
}

void Qix::init()
{
    // _map[0] = "1111111111111111111111111111111111111111";
    // _map[1] = "1000000001000000000000000000000000000001";
    // _map[2] = "1000000001000000000000000000000000000001";
    // _map[3] = "1000000001000000000000000000000000000001";
    // _map[4] = "1000000001000000000000000000000000000001";
    // _map[5] = "1000000000000000000000000000000000000001";
    // _map[6] = "1000000000000000000000000000000000000001";
    // _map[7] = "1000000000000000000000000000000000000001";
    // _map[8] = "1000000000000000000000000000000000000001";
    // _map[9] = "1000000000000000000000000000000000000001";
    // _map[10] = "1000000000000000000000000000000000000001";
    // _map[11] = "1000000000000000000000000000000000000001";
    // _map[12] = "1000000000000000000000000000000000000001";
    // _map[13] = "1000000000000000000000000000000000000001";
    // _map[14] = "1000000000000000000000000000000000000001";
    // _map[15] = "1000000000000000000000000000000000000001";
    // _map[16] = "1000000000000000000000000000000000000001";
    // _map[17] = "1000000000000000000000000000000000000001";
    // _map[18] = "1000000000000000000000000000000000000001";
    // _map[19] = "1000000000000000010000000000000000000001";
    // _map[20] = "1000000000000000010000000000000000000001";
    // _map[21] = "1000000000000000010000000000000000000001";
    // _map[22] = "1000000000000000010000000000000000000001";
    // _map[23] = "1000000000000000010000000000000000000001";
    // _map[24] = "1000000000000000010000000000000000000001";
    // _map[25] = "1000000000000000010000000000000000000001";
    // _map[26] = "1000000000000000000000000000000000000001";
    // _map[27] = "1000000000000000000000000000000000000001";
    // _map[28] = "1000000000000000000000000000000000000001";
    // _map[29] = "1000000000000000000000000000000000000001";
    // _map[30] = "1000000000000000000000000000000000000001";
    // _map[31] = "1000000000000000000000000000000000000001";
    // _map[32] = "1000000000000000000000000000000000000001";
    // _map[33] = "1000000000000000000000000000000000000001";
    // _map[34] = "1000000000000000000000000000000000000001";
    // _map[35] = "1000000000000000000000000000000000000001";
    // _map[36] = "1000000000000000000000000000000000000001";
    // _map[37] = "1000000000000000000000000000000000000001";
    // _map[38] = "1000000000000000000000000000000000000001";
    // _map[39] = "1111111111111111111111111111111111111111";

    _map[0] = "1111111111111111111111111111111111111111";
    _map[1] = "1111111111111111100001111111111111111111";
    _map[2] = "1000000000000000000000000000000000000001";
    _map[3] = "1000000011111111111111111111000000000001";
    _map[4] = "1000000011111111111111111111000000000001";
    _map[5] = "1000000011111111111111111111000000000001";
    _map[6] = "1000000011111111111111111111000000000001";
    _map[7] = "1000000011111111111111111111000000000001";
    _map[8] = "1000000000000000000000000000000000000001";
    _map[9] = "1000000000000000000000000000000000000001";
    _map[10] = "1000000000000000000000000000000000000001";
    _map[11] = "1000000000000000000000000000000000000001";
    _map[12] = "1000000000000000000000000000000000000001";
    _map[13] = "1000000000000000000000000000000000000001";
    _map[14] = "1000000000000000000000000000000000000001";
    _map[15] = "1000000000000000000000000000000000000001";
    _map[16] = "1000000000000000000000000000000000000001";
    _map[17] = "1000000000000000000000000000000000000001";
    _map[18] = "1000000000000000000000000000000000000001";
    _map[19] = "1000000000000000000000000000000000000001";
    _map[20] = "1000000000000000000000000000000000000001";
    _map[21] = "1000000000000000000000000000000000000001";
    _map[22] = "1000000000000000000000000000000000000001";
    _map[23] = "1000000000000000000000000000000000000001";
    _map[24] = "1000000000000000000000000000000000000001";
    _map[25] = "1000000000000000000000000000000000000001";
    _map[26] = "1000000000000000000000000000000000000001";
    _map[27] = "1000000000000000000000000000000000000001";
    _map[28] = "1000000000000000000000000000000000000001";
    _map[29] = "1000000000000000000000000000000000000001";
    _map[30] = "1000000000000000000000000000000000000001";
    _map[31] = "1000000000000000000000000000000000000001";
    _map[32] = "1000000000000000000000000000000000000001";
    _map[33] = "1000000000000000000000000000000000000001";
    _map[34] = "1000000000000000000000000000000000000001";
    _map[35] = "1000000000000000000000000000000000000001";
    _map[36] = "1000000000000000000000000000000000000001";
    _map[37] = "1000000000000000000000000000000000000001";
    _map[38] = "1000000000000000000000000000000000000001";
    _map[39] = "1111111111111111111111111111111111111111";

    _ymap = -1 * (((float)_map.size()) * 16);
    srand(time(NULL));
    _score = 0;
}
void Qix::stop()
{
}
void *Qix::getHandle() const
{
    return (_handle);
}
void Qix::setHandle(void *handle)
{
    _handle = handle;
}
void Qix::setName(std::string handle)
{
    _name = handle;
}
const std::string &Qix::getName() const
{
    return (_name);
}
void Qix::updateInput(Arcade::Input &input)
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
}

void Qix::moveSnake()
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

void Qix::enLargeYourSnake()
{
    int x = (_snake[_snake.size() - 1]->getPosition().x - xbase) / 16;
    int y = (_snake[_snake.size() - 1]->getPosition().y - ybase)/ 16;
    if (_map[y][x + 1] != '1'
        && _snake[_snake.size() - 2]->getPosition().x != _snake[_snake.size() - 1]->getPosition().x
        && _snake[_snake.size() - 2]->getPosition().y != _snake[_snake.size() - 1]->getPosition().y)
    {
        _snake[_snake.size()] = new Arcade::Circle(8.0, Arcade::Vector2f((x + 1) * 16 + xbase, y * 16 + ybase), _color["green"]);;
    }
}

void Qix::newPartSnake()
{
    int sizeAdd = rand() % 4;
    while (sizeAdd == 0)
        sizeAdd = rand() % 4;
    for (;sizeAdd != 0; sizeAdd--)
        enLargeYourSnake();
}

int Qix::updateGame(IDisplayModule *_Dinstance)
{
    static double long sec = 0;
    double long ti = _Dinstance->getDeltaTime();

    sec += ti / 10000.0;

    if (sec > 9.) {
        sec = 0.0;
        moveSnake();
        if (_map[(_snake[0]->getPosition().y - ybase)/ 16][(_snake[0]->getPosition().x - xbase) / 16] == '1')
        {
            std::cout << "Dead man you are bad" << std::endl;
            return (_score);
        }
    }
    return (-1);//-1 quand ca joue et return  le scor quand c'est fini
}

void Qix::displayGame(IDisplayModule *_Dinstance)
{
    for(auto snake : _snake)
        _Dinstance->drawCircle(*snake.second);
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

void Qix::drawGame(IDisplayModule *_Dinstance)
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
    mod = new Qix;
}

__attribute__((destructor))
void destructor()
{
    delete mod;
}
