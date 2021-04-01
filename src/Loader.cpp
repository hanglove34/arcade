//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// src
//

#include "Loader.hpp"
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"

template<>
IGameModule *DLLoader<IGameModule>::getInstance(const std::string &path) {
    const std::string comp(".so");
    if (path.find(comp) == std::string::npos)
        exit(84);
    void *handle = dlopen(path.c_str(), RTLD_LAZY);

    if (!handle) {
        std::cout << dlerror() << std::endl;
        exit(84);
    }

    if (!dlsym(handle, "gamecheck"))
        exit (84);

    IGameModule *(*entryPoint)(void);
    void *fptr = dlsym(handle, "entryPoint");

    entryPoint = (IGameModule *(*)())fptr;
    if (!entryPoint)
        return NULL;
    IGameModule *instance = entryPoint();
    instance->init();
    instance->setHandle(handle);
    instance->setName(pathToName(path));
    return (instance);
}

template<>
IDisplayModule *DLLoader<IDisplayModule>::getInstance(const std::string &path) {
    const std::string comp(".so");
    if (path.find(comp) == std::string::npos)
        exit(84);
    void *handle = dlopen(path.c_str(), RTLD_LAZY);

    if (!handle) {
        std::cout << dlerror() << std::endl;
        exit(84);
    }

    if (!dlsym(handle, "libcheck"))
        exit (84);

    IDisplayModule *(*entryPoint)(void);
    void *fptr = dlsym(handle, "entryPoint");

    entryPoint = (IDisplayModule *(*)())fptr;
    if (!entryPoint)
        return NULL;
    IDisplayModule *instance = entryPoint();
    instance->init();
    instance->setHandle(handle);
    instance->setName(pathToName(path));
    return (instance);
}
