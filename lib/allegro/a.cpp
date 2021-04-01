#include <iostream>
#include <allegro5/allegro.h>

// fonction contrôle d’erreur

/*************************************************************
*************************************************************/
int main()
{
// pour obtenir une fenêtre
ALLEGRO_DISPLAY *display;

    // 1) initialisation Allegro obligatoire
    if(!al_init())
        std::cerr << "erreur init" << '\n';

    // 2) créer sa fenêtre
    display=al_create_display(800,600);
}
