/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** NCurses.cpp
*/

#include "NCurses.hpp"

NCurses::NCurses():
    _isStopped(false)
{
    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);
    timeout(0);
	if (has_colors())
        start_color();
}

NCurses::~NCurses()
{
    stop();
}

void NCurses::init()
{
}

void NCurses::stop()
{
    if (!_isStopped) {
        endwin();
        _isStopped = true;
    }
}

void *NCurses::getHandle() const
{
    return (_handle);
}

void NCurses::setHandle(void *handle)
{
    _handle = handle;
}

void NCurses::setName(std::string name)
{
    _name = name;
}

const std::string &NCurses::getName() const
{
    return (_name);
}

void NCurses::clearWindow()
{
    erase();
}

void NCurses::displayWindow()
{
    refresh();
}

int NCurses::drawSprite(Arcade::Sprite sprite)
{
    return (0);
}

void NCurses::drawRectangle(Arcade::Rectangle &rectangle)
{
    int y = rectangle.getPosition().y / 16;
    int x = rectangle.getPosition().x / 8;
    int ys = rectangle.getSize().y / 16;
    int xs = rectangle.getSize().x / 8;
    int colorIndex = getColorIndex(rectangle.getColor());

    attron(COLOR_PAIR(colorIndex));
    for (int j = y; j < y + ys; j += 1)
        for (int i = x; i < x + xs; i += 1)
            mvaddstr(j, i, " ");
    attroff(COLOR_PAIR(colorIndex));
}

void NCurses::drawCircle(Arcade::Circle &circle)
{
    int r = circle.getRadius() / 16;
    int y = circle.getPosition().y / 16 + r;
    int x = circle.getPosition().x / 8 + r;
    int x_offset = 0;
    int colorIndex = getColorIndex(circle.getColor());

    attron(COLOR_PAIR(colorIndex));
    for (int j = -r; j <= r; j += 1) {
        for (int i = -r; i <= r; i += 1) {
            if (i * i + j * j <= r * r)
                mvaddstr(y + j, x + i + x_offset, "  ");
            x_offset += 1;
        }
        x_offset = 0;
    }
    attroff(COLOR_PAIR(colorIndex));
}

void NCurses::drawText(Arcade::Text &text)
{
    int y = text.getPosition().y / 16;
    int x = text.getPosition().x / 8;

    mvaddstr(y, x, text.getString().c_str());
}

void NCurses::startClock()
{
    _start = std::chrono::high_resolution_clock::now();     //_start = variable dans l’instance NCuse, => reference de
}

void NCurses::setDeltaTime()
{
    auto elapsed = std::chrono::high_resolution_clock::now() - _start;
    _start = std::chrono::high_resolution_clock::now();
    _deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count(); // _deltaTime = variable dans
      // l’intance NCuse
}

const long double &NCurses::getDeltaTime() const
{
    return (_deltaTime);
}

void NCurses::drawMenu()
{
}

Arcade::Input NCurses::coreInputs()
{
    MEVENT event;

    switch (getch()) {
        case KEY_BACKSPACE:
            return (Arcade::Input::Backspace);
        case 27:
            return (Arcade::Input::Escape);
        case '\n':
            return (Arcade::Input::Return);
        case ' ':
            return (Arcade::Input::Space);
        case 'a':
        case 'A':
            return (Arcade::Input::A);
        case 'b':
        case 'B':
            return (Arcade::Input::B);
        case 'c':
        case 'C':
            return (Arcade::Input::C);
        case 'd':
        case 'D':
            return (Arcade::Input::D);
        case 'e':
        case 'E':
            return (Arcade::Input::E);
        case 'f':
        case 'F':
            return (Arcade::Input::F);
        case 'g':
        case 'G':
            return (Arcade::Input::G);
        case 'h':
        case 'H':
            return (Arcade::Input::H);
        case 'i':
        case 'I':
            return (Arcade::Input::I);
        case 'j':
        case 'J':
            return (Arcade::Input::J);
        case 'k':
        case 'K':
            return (Arcade::Input::K);
        case 'l':
        case 'L':
            return (Arcade::Input::L);
        case 'm':
        case 'M':
            return (Arcade::Input::M);
        case 'n':
        case 'N':
            return (Arcade::Input::N);
        case 'o':
        case 'O':
            return (Arcade::Input::O);
        case 'p':
        case 'P':
            return (Arcade::Input::P);
        case 'q':
        case 'Q':
            return (Arcade::Input::Q);
        case 'r':
        case 'R':
            return (Arcade::Input::R);
        case 's':
        case 'S':
            return (Arcade::Input::S);
        case 't':
        case 'T':
            return (Arcade::Input::T);
        case 'u':
        case 'U':
            return (Arcade::Input::U);
        case 'v':
        case 'V':
            return (Arcade::Input::V);
        case 'w':
        case 'W':
            return (Arcade::Input::W);
        case 'x':
        case 'X':
            return (Arcade::Input::X);
        case 'y':
        case 'Y':
            return (Arcade::Input::Y);
        case 'z':
        case 'Z':
            return (Arcade::Input::Z);
        case '0':
        case 160:
            return (Arcade::Input::Num0);
        case '1':
        case '&':
            return (Arcade::Input::Num1);
        case '2':
        case 169:
            return (Arcade::Input::Num2);
        case '3':
        case '\"':
            return (Arcade::Input::Num3);
        case '4':
        case '\'':
            return (Arcade::Input::Num4);
        case KEY_LEFT:
            return (Arcade::Input::LEFT);
        case KEY_RIGHT:
            return (Arcade::Input::RIGHT);
        case KEY_UP:
            return (Arcade::Input::UP);
        case KEY_DOWN:
            return (Arcade::Input::DOWN);
    }
    return (Arcade::Input::None);
}

int NCurses::getColorIndex(Arcade::Color color)
{
    int index = 0;

    for (; index < _colorPairs.size(); index += 1) {
        Arcade::Color c = _colorPairs.at(index);
        if (c.r == color.r && c.g == color.g && c.b == color.b)
            return (index + 1);
    }
    index = _colorPairs.size() + 1;
    _colorPairs.push_back(color);
    int r = (float)(color.r / 255.0) * 1000;
    int g = (float)(color.g / 255.0) * 1000;
    int b = (float)(color.b / 255.0) * 1000;
    init_color(index + 8, r, g, b);
    init_pair(index, COLOR_WHITE, index + 8);
    return (index);
}

//--------------------------------------------------------------------------

IDisplayModule *mod = nullptr;
int libcheck;

extern "C"
{
    IDisplayModule *entryPoint()
    {
        return (mod);
    }
}

__attribute__((constructor))
void constructor()
{
    mod = new NCurses;
}

__attribute__((destructor))
void destructor()
{
    delete mod;
}
