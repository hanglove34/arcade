//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// Lib SFML
//

#include "lib_arcade_sfml.hpp"

SFML::SFML():_window(sf::VideoMode(1280, 1024), "SFML works!")
{
}

SFML::~SFML()
{
}

void SFML::init()
{
}
void SFML::stop()
{
    _window.close();
}
void *SFML::getHandle() const
{
    return (_handle);
}
void SFML::setHandle(void *handle)
{
    _handle = handle;
}
void SFML::setName(std::string handle)
{
    _name = handle;
}
const std::string &SFML::getName() const
{
    return (_name);
}

void SFML::clearWindow()
{
    _window.clear();
}
void SFML::displayWindow()
{
    _window.display();
}

int SFML::drawSprite(Arcade::Sprite sprite)
{
    return (0);
}

void SFML::drawRectangle(Arcade::Rectangle &rectangle)
{
    Arcade::Vector2f size = rectangle.getSize();
    sf::Vector2f sf_size(size.x, size.y);
    sf::RectangleShape rect(sf_size);
    sf::Color color(rectangle.getColor().r, rectangle.getColor().g, rectangle.getColor().b, rectangle.getColor().a);
    rect.setFillColor(color);
    rect.move(rectangle.getPosition().x, rectangle.getPosition().y);
    _window.draw(rect);
}
void SFML::drawCircle(Arcade::Circle &circle)
{
    sf::CircleShape shape(circle.getRadius());
    sf::Color color(circle.getColor().r, circle.getColor().g, circle.getColor().b, circle.getColor().a);
    shape.setFillColor(color);
    shape.move(circle.getPosition().x, circle.getPosition().y);
    _window.draw(shape);

}
void SFML::drawText(Arcade::Text &text)
{
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        std::cout << "error set font text sfml" << std::endl;
    sf::Color color(text.getColor().r, text.getColor().g, text.getColor().b, text.getColor().a);
    sf::Text txt;
    txt.setString(text.getString());
    txt.setFont(font);
    txt.setFillColor(color);
    txt.setCharacterSize(text.getSize());
    txt.move(text.getPosition().x, text.getPosition().y);
    _window.draw(txt);
}

void SFML::startClock()
{
    _start = std::chrono::high_resolution_clock::now();     //_start = variable dans l’instance NCuse, => reference de
}

void SFML::setDeltaTime()
{
    auto elapsed = std::chrono::high_resolution_clock::now() - _start;
    _start = std::chrono::high_resolution_clock::now();
    _deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count(); // _deltaTime = variable dans
      // l’intance NCuse
}

const long double &SFML::getDeltaTime() const
{
    return (_deltaTime);
}


void SFML::drawMenu()
{

}
Arcade::Input SFML::coreInputs()
{
    Arcade::Input input = Arcade::Input::None;
    sf::Event event;
    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            // _window.close();
            input = Arcade::Input::Escape;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            input = Arcade::Input::LEFT;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            input = Arcade::Input::RIGHT;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            input = Arcade::Input::UP;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            input = Arcade::Input::DOWN;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
            input = Arcade::Input::Return;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
            input = Arcade::Input::Num0;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            input = Arcade::Input::Num1;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            input = Arcade::Input::Num2;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            input = Arcade::Input::Num3;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            input = Arcade::Input::Num4;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            input = Arcade::Input::Space;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
            input = Arcade::Input::BackSpace;
        //letter
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            input = Arcade::Input::A;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
            input = Arcade::Input::B;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
            input = Arcade::Input::C;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            input = Arcade::Input::D;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            input = Arcade::Input::E;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
            input = Arcade::Input::F;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
            input = Arcade::Input::G;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
            input = Arcade::Input::H;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
            input = Arcade::Input::I;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
            input = Arcade::Input::J;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
            input = Arcade::Input::K;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
            input = Arcade::Input::L;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
            input = Arcade::Input::M;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
            input = Arcade::Input::N;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
            input = Arcade::Input::O;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            input = Arcade::Input::P;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            input = Arcade::Input::Q;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            input = Arcade::Input::R;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            input = Arcade::Input::S;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
            input = Arcade::Input::T;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
            input = Arcade::Input::U;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
            input = Arcade::Input::V;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            input = Arcade::Input::W;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
            input = Arcade::Input::X;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
            input = Arcade::Input::Y;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            input = Arcade::Input::Z;
    }
    return (input);
}

//--------------------------------------------------------------------------
IDisplayModule *mod = nullptr;
int libcheck;


extern "C"
{
    IDisplayModule *entryPoint()
    {
        return mod;
    }
}

__attribute__((constructor))
void constructor()
{
    mod = new SFML;
}

__attribute__((destructor))
void destructor()
{
    delete mod;
}