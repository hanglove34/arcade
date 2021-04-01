//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// hpp
//

#ifndef _Loader_HPP_
#define _Loader_HPP_
#include <dlfcn.h>
#include <string>

template<typename T>
class DLLoader {
    public:
        DLLoader() {}
        ~DLLoader() {}

        T *getInstance(const std::string &path);

        int destroyInstance(T *instance) {
            instance->stop();
            return (dlclose(instance->getHandle()));

        }
        std::string pathToName(const std::string &path)
        {
            std::string name = path;

            if (path.find("sfml") != std::string::npos) {
                name = "sfml";
            }
            if (path.find("ncurses") != std::string::npos) {
                name = "ncurse";
            }
            if (path.find("nibbler") != std::string::npos) {
                name = "nibbler";
            }
            if (path.find("allegro") != std::string::npos) {
                name = "allegro";
            }
            if (path.find("CAMILLE") != std::string::npos) {
                name = "CAMILLE";
            }
            if (path.find("ALPHAGROUPE") != std::string::npos) {
                name = "ALPHAGROUPE";
            }
            if (path.find("qix") != std::string::npos) {
                name = "qix";            
            }
            return (name);
        }
    private:
};

#endif
