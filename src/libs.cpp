//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// lib
//

#include "My.hpp"

IDisplayModule *mod = nullptr;

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
    // mod = new SFML;
}

__attribute__((destructor))
void destructor()
{
    delete mod;
}
