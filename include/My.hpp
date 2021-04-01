//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// main include
//

#ifndef MY
#define MY

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <memory>
#include <exception>

#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include "Loader.hpp"
#include "Arcade.hpp"
#include <sys/types.h>
#include <dirent.h>
#include <chrono>
#include <time.h>

class Panel
{
    private:
        std::map<int, Arcade::Rectangle *> _rect;
        std::map<int, Arcade::Text *> _name;
    public:
        Panel();
        ~Panel();
        std::map<int, Arcade::Rectangle *> getRect() const {return (_rect);}
        void setRect(std::map<int, Arcade::Rectangle *> rect) {_rect = rect;}
        std::map<int, Arcade::Text *> getName() const {return (_name);}
        void setName(std::map<int, Arcade::Text *> rect) {_name = rect;}
};

class Pseudo
{
    private:

        Arcade::Text *_pseudo;
        Arcade::Text *_limitsize;
        std::list<Arcade::Rectangle *> _rect;
    public:
        Pseudo();
        ~Pseudo();
        void setPseudo(Arcade::Text *pseudo) {_pseudo = pseudo;}
        Arcade::Text *getPseudo() const {return (_pseudo);}
        void setLimitSize(Arcade::Text *limitsize) {_limitsize = limitsize;}
        Arcade::Text *getLimitSize() const {return (_limitsize);}
        void setRectList(std::list<Arcade::Rectangle *> rect) { _rect = rect;}
        std::list<Arcade::Rectangle *> getRectlist() const {return (_rect);}
};

class Menu
{
    private:
        size_t _select;
        size_t _sizeOption;
        std::list<Panel *> _panel;
        Pseudo *_pseudo;
        std::list<Arcade::Text *> _helper;
        int _helperInfo;
    public:
        Menu();
        ~Menu();
        std::list<Panel *> getPanel() const {return (_panel);}
        void addPanel(Panel *panel) {_panel.push_back(panel);}
        size_t getSelect() const {return (_select);}
        void setSelect(size_t select) {_select = select;}
        size_t getSizeOption() const {return (_sizeOption);}
        void setSizeOption(size_t sizeoption) {_sizeOption = sizeoption;}
        void setPseudo(Pseudo *pseudo){_pseudo = pseudo;}
        Pseudo *getPseudo() const {return (_pseudo);}
        void setHelper(std::list<Arcade::Text *> helper) {_helper = helper;}
        std::list<Arcade::Text *> getHelper() const {return (_helper);}
        void setHelperInfo(int help) {_helperInfo = help;}
        int getHelperInfo() const { return (_helperInfo);}
};

class My
{
    private:
        std::string _gameSelected;
        IDisplayModule *_lib;
        IGameModule *_game;
        Arcade::Input _input;
        bool _statu;
        std::list<std::string> _nameLib;
        std::list<std::string> _nameGame;
        Menu *_menu;
        DLLoader<IDisplayModule> _loaderLib;
        DLLoader<IGameModule> _loaderGame;
        int _inputpseudo;
        std::string _pseudo;
    public:
        My(IDisplayModule *lib);
        ~My();
        IDisplayModule *getLib() const {return (_lib);}
        void setLib(IDisplayModule *lib) {_lib = lib;}
        const Arcade::Input &getInput() const {return (_input);}
        void setInput(Arcade::Input input) {_input = input; getLib()->clearWindow();}
        bool getStatu() const {return (_statu);}
        void setStatu(bool statu) {_statu = statu;}
        void addNameLib(std::string name) {_nameLib.push_back(name);}
        std::list<std::string> getNameLib() const {return (_nameLib);}
        void setListLib(std::list<std::string> list) {_nameLib = list;}
        void addNameGame(std::string name) {_nameGame.push_back(name);}
        std::list<std::string> getNameGame() const {return (_nameGame);}
        void setListGame(std::list<std::string> list) {_nameGame = list;}
        Menu *getMenu() const {return (_menu);}
        void setMenu(Menu *menu) {_menu = menu;}
        DLLoader<IDisplayModule> getLoaderLib() const {return (_loaderLib);}
        void setLoaderLib(DLLoader<IDisplayModule> loaderModule) {_loaderLib = loaderModule;}
        DLLoader<IGameModule> getLoaderGame() const {return (_loaderGame);}
        void setLoaderGame(DLLoader<IGameModule> loaderGame) {_loaderGame = loaderGame;}
        void setGameSelected(std::string game) {_gameSelected = game;}
        std::string getGameSelected() const {return (_gameSelected);}
        IGameModule *getGame() const {return (_game);}
        void setGame(IGameModule *game) {_game = game;}
        void setInputPseudo(int input) {_inputpseudo = input;}
        int getInputPseudo() const {return (_inputpseudo);}
        void setPseudo(std::string str) {_pseudo = str;}
        std::string getPseudo() const {return (_pseudo);}
};

#endif
