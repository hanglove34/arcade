#ifndef ALLEGRO_LIB
#define ALLEGRO_LIB

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <My.hpp>
#include <iostream>

class Allegro : public IDisplayModule
{
    public:
        ALLEGRO_DISPLAY *_display;
        ALLEGRO_EVENT_QUEUE *_event_queue = NULL;
        std::string _name;
        void *_handle;
        long double _deltaTime;
        std::chrono::time_point<std::chrono::high_resolution_clock> _start;
        Allegro();
        ~Allegro();

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
