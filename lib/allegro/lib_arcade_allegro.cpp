#include "lib_arcade_allegro.hpp"

Allegro::Allegro()
{
}

Allegro::~Allegro()
{
}

void Allegro::init()
{
    al_init();
    _display = al_create_display(1280, 1024);
    al_init_ttf_addon();
    al_init_font_addon();
    al_init_primitives_addon();
    al_install_keyboard();
    _event_queue = al_create_event_queue();
    al_register_event_source(_event_queue, al_get_display_event_source(_display));
    al_register_event_source(_event_queue, al_get_keyboard_event_source());

}
void Allegro::stop()
{
}
void *Allegro::getHandle() const
{
    return (_handle);
}
void Allegro::setHandle(void *handle)
{
    _handle = handle;
}
void Allegro::setName(std::string handle)
{
    _name = handle;
}
const std::string &Allegro::getName() const
{
    return (_name);
}

void Allegro::clearWindow()
{
    al_clear_to_color(al_map_rgb(0,0,0));
}
void Allegro::displayWindow()
{
    al_flip_display();

}

int Allegro::drawSprite(Arcade::Sprite sprite)
{
    return (0);
}

void Allegro::drawRectangle(Arcade::Rectangle &rectangle)
{
    int x1 = rectangle.getPosition().x;
    int y1 = rectangle.getPosition().y;
    int x2 = rectangle.getPosition().x;
    x2 += rectangle.getSize().x;
    int y2 = rectangle.getPosition().y;
    y2 += rectangle.getSize().y;
    al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgba(rectangle.getColor().r, rectangle.getColor().g, rectangle.getColor().b, rectangle.getColor().a));
}

void Allegro::drawCircle(Arcade::Circle &circle)
{
    al_draw_filled_circle(circle.getPosition().x + 8, circle.getPosition().y + 8, circle.getRadius(), al_map_rgba(circle.getColor().r, circle.getColor().g, circle.getColor().b, circle.getColor().a));
}

void Allegro::drawText(Arcade::Text &text)
{
    ALLEGRO_FONT *font = al_load_ttf_font("arial.ttf", text.getSize(), 0);
    if (font)
    {
        al_draw_text(font, al_map_rgba(text.getColor().r, text.getColor().g, text.getColor().b, text.getColor().a), text.getPosition().x, text.getPosition().y, ALLEGRO_ALIGN_LEFT, text.getString().data());
    }
}

void Allegro::startClock()
{
    _start = std::chrono::high_resolution_clock::now();     //_start = variable dans l’instance NCuse, => reference de
}

void Allegro::setDeltaTime()
{
    auto elapsed = std::chrono::high_resolution_clock::now() - _start;
    _start = std::chrono::high_resolution_clock::now();
    _deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count(); // _deltaTime = variable dans
      // l’intance NCuse
}

const long double &Allegro::getDeltaTime() const
{
    return (_deltaTime);
}

void Allegro::drawMenu()
{
}
Arcade::Input Allegro::coreInputs()
{
    Arcade::Input input = Arcade::Input::None;
    ALLEGRO_EVENT ev;
    ALLEGRO_TIMEOUT timeout;
    al_init_timeout(&timeout, 0.06);
    bool event = al_wait_for_event_until(_event_queue, &ev, &timeout);

    if (event && ev.type==ALLEGRO_EVENT_KEY_DOWN) {
        switch (ev.keyboard.keycode) {
            case ALLEGRO_KEY_LEFT:
            input = Arcade::Input::LEFT;
            break;
            case ALLEGRO_KEY_UP:
            input = Arcade::Input::UP;
            break;
            case ALLEGRO_KEY_DOWN:
            input = Arcade::Input::DOWN;
            break;
            case ALLEGRO_KEY_RIGHT:
            input = Arcade::Input::RIGHT;
            break;
            case ALLEGRO_KEY_ESCAPE:
            input = Arcade::Input::Escape;
            break;
            case ALLEGRO_KEY_SPACE:
            input = Arcade::Input::Space;
            break;
            case ALLEGRO_KEY_BACKSPACE:
            input = Arcade::Input::BackSpace;
            break;
            case ALLEGRO_KEY_ENTER:
            input = Arcade::Input::Return;
            break;
            case ALLEGRO_KEY_A:
            input = Arcade::Input::A;
            break;
            case ALLEGRO_KEY_B:
            input = Arcade::Input::B;
            break;
            case ALLEGRO_KEY_C:
            input = Arcade::Input::C;
            break;
            case ALLEGRO_KEY_D:
            input = Arcade::Input::D;
            break;
            case ALLEGRO_KEY_E:
            input = Arcade::Input::E;
            break;
            case ALLEGRO_KEY_F:
            input = Arcade::Input::F;
            break;
            case ALLEGRO_KEY_G:
            input = Arcade::Input::G;
            break;
            case ALLEGRO_KEY_H:
            input = Arcade::Input::H;
            break;
            case ALLEGRO_KEY_I:
            input = Arcade::Input::I;
            break;
            case ALLEGRO_KEY_J:
            input = Arcade::Input::J;
            break;
            case ALLEGRO_KEY_K:
            input = Arcade::Input::K;
            break;
            case ALLEGRO_KEY_L:
            input = Arcade::Input::L;
            break;
            case ALLEGRO_KEY_M:
            input = Arcade::Input::M;
            break;
            case ALLEGRO_KEY_N:
            input = Arcade::Input::N;
            break;
            case ALLEGRO_KEY_O:
            input = Arcade::Input::O;
            break;
            case ALLEGRO_KEY_P:
            input = Arcade::Input::P;
            break;
            case ALLEGRO_KEY_Q:
            input = Arcade::Input::Q;
            break;
            case ALLEGRO_KEY_R:
            input = Arcade::Input::R;
            break;
            case ALLEGRO_KEY_S:
            input = Arcade::Input::S;
            break;
            case ALLEGRO_KEY_T:
            input = Arcade::Input::T;
            break;
            case ALLEGRO_KEY_U:
            input = Arcade::Input::U;
            break;
            case ALLEGRO_KEY_V:
            input = Arcade::Input::V;
            break;
            case ALLEGRO_KEY_W:
            input = Arcade::Input::W;
            break;
            case ALLEGRO_KEY_X:
            input = Arcade::Input::X;
            break;
            case ALLEGRO_KEY_Y:
            input = Arcade::Input::Y;
            break;
            case ALLEGRO_KEY_Z:
            input = Arcade::Input::Z;
            break;
            case ALLEGRO_KEY_0:
            input = Arcade::Input::Num0;
            break;
            case ALLEGRO_KEY_1:
            input = Arcade::Input::Num1;
            break;
            case ALLEGRO_KEY_2:
            input = Arcade::Input::Num2;
            break;
            case ALLEGRO_KEY_3:
            input = Arcade::Input::Num3;
            break;
            case ALLEGRO_KEY_4:
            input = Arcade::Input::Num4;
            break;
        }
    } else if (event && ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        input = Arcade::Input::Escape;
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
    mod = new Allegro;
}

__attribute__((destructor))
void destructor()
{
    delete mod;
}
