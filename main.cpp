//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// main
//

#include "My.hpp"

    Arcade::Vector2f position = Arcade::Vector2f(550, 20);

    Arcade::Color red = Arcade::Color(255, 0, 0, 255, "red");
    Arcade::Color green = Arcade::Color(0, 255, 0, 255, "green");
    Arcade::Color blue = Arcade::Color(0, 0, 255, 255, "blue");
    Arcade::Color white = Arcade::Color(255, 255, 255, 255, "white");
    Arcade::Color grey = Arcade::Color(169, 169, 169, 255, "grey");
    Arcade::Color black = Arcade::Color(0, 0, 0, 255, "black");

    Arcade::Text text("Menu", blue, position, 50);

    std::list<std::string> find_lib_in_folder(std::string dir_name)
    {
        DIR *dp;
        struct dirent *ep;
        dp = opendir (dir_name.c_str());
        std::string name;
        std::list<std::string> result;

        void *handle;

        if (dp != NULL)
        {
            while ((ep = readdir (dp)))
            {
                  name = ep->d_name;
                  if (name.find(".so") < name.size() && name.find(".so") > 0){
                      // result.push_back(name);
                      handle = dlopen((dir_name+ "/" +name).c_str(), RTLD_LAZY);
                      if (!handle) {
                          continue;
                      }
                      if (dir_name == "./lib")
                          if (dlsym(handle, "libcheck"))
                            result.push_back(name);
                      if (dir_name == "./games")
                          if (dlsym(handle, "gamecheck"))
                               result.push_back(name);
                       dlclose(handle);
                      }
              }
            closedir (dp);
        }
        else
            std::cout << "error open folder : " << dir_name << std::endl;
        return (result);
    }

void draw_select_option(My *data, Arcade::Text *name)
{
    name->setColor(black);
    Arcade::Rectangle rect;
    Arcade::Vector2f position(name->getPosition().x - 5, name->getPosition().y + 2);
    Arcade::Vector2f size(210, 22);
    rect.setPosition(position);
    rect.setColor(white);
    rect.setSize(size);
    data->getLib()->drawRectangle(rect);
    data->getLib()->drawText(*name);
    name->setColor(white);
}

void display_panel(My *data)
{
    std::list<Panel *> panellist = data->getMenu()->getPanel();
    size_t d = 0;
    for (auto panel : panellist)
    {
        std::map<int, Arcade::Rectangle *> rectList = panel->getRect();
        for (auto rect : rectList)
        {
            data->getLib()->drawRectangle(*rect.second);
        }
        std::map<int, Arcade::Text *> nameList = panel->getName();
        for (auto name : nameList)
        {
            if (data->getMenu()->getSelect() == d && data->getInputPseudo() == 0)
            {
                draw_select_option(data, name.second);
            } else
                data->getLib()->drawText(*name.second);
            d++;
        }
    }
}

void menu_down(My *data)
{
    data->getMenu()->setSelect(data->getMenu()->getSelect() + 1);
    if (data->getMenu()->getSizeOption() == data->getMenu()->getSelect())
        data->getMenu()->setSelect(0);
}

void menu_up(My *data)
{
    if (data->getMenu()->getSelect() == 0)
        data->getMenu()->setSelect(data->getMenu()->getSizeOption() - 1);
    else
        data->getMenu()->setSelect(data->getMenu()->getSelect() - 1);
}

void change_lib_menu(My *data)
{
    std::list<Panel *> panellist = data->getMenu()->getPanel();
    size_t d = 0;
    for (auto panel : panellist)
    {
        std::map<int, Arcade::Text *> nameList = panel->getName();
        for (auto name : nameList)
        {
            if (data->getMenu()->getSelect() == d && name.second->getString().find(data->getLib()->getName()) > name.second->getString().size())
            {
                data->getLib()->stop();
                data->getLoaderLib().destroyInstance(data->getLib());
                data->setLib(data->getLoaderLib().getInstance("./lib/" + name.second->getString()));
                return;
            }
            d++;
        }
    }
}

void select_game(My *data)
{
    data->setStatu(1);
    std::list<Panel *> panellist = data->getMenu()->getPanel();
    size_t d = 0;
    for (auto panel : panellist)
    {
        std::map<int, Arcade::Text *> nameList = panel->getName();
        for (auto name : nameList)
        {
            if (data->getMenu()->getSelect() == d && name.second->getString().find(data->getLib()->getName()) > name.second->getString().size())
            {
                data->setGameSelected("./games/" + name.second->getString());
                data->setGame(data->getLoaderGame().getInstance(data->getGameSelected()));
                // data->getGame()->init();
                return;
            }
            d++;
        }
    }
}

void menu_enter(My *data)
{
    if (data->getNameLib().size() > data->getMenu()->getSelect())
    {
       change_lib_menu(data);
    } else {
       select_game(data);
    }
}

void display_pseudo(My *data)
{
    if (data->getInputPseudo() == 0)
    {
        data->getMenu()->getPseudo()->getPseudo()->setColor(white);
        data->getLib()->drawText(*data->getMenu()->getPseudo()->getPseudo());
    }
    else
    {
        for(auto rect : data->getMenu()->getPseudo()->getRectlist())
            data->getLib()->drawRectangle(*rect);
        data->getMenu()->getPseudo()->getPseudo()->setColor(black);
        data->getMenu()->getPseudo()->getPseudo()->setString("Name : " + data->getPseudo());
        data->getLib()->drawText(*data->getMenu()->getPseudo()->getPseudo());
        if (data->getPseudo().size() == 15)
            data->getLib()->drawText(*data->getMenu()->getPseudo()->getLimitSize());
    }
}

void writePseudo(My *data)
{
    if (data->getPseudo().size() < 15)
    {
        if (data->getInput() == Arcade::Input::A)
            data->setPseudo(data->getPseudo() + "A");
        if (data->getInput() == Arcade::Input::B)
            data->setPseudo(data->getPseudo() + "B");
        if (data->getInput() == Arcade::Input::C)
            data->setPseudo(data->getPseudo() + "C");
        if (data->getInput() == Arcade::Input::D)
            data->setPseudo(data->getPseudo() + "D");
        if (data->getInput() == Arcade::Input::E)
            data->setPseudo(data->getPseudo() + "E");
        if (data->getInput() == Arcade::Input::F)
            data->setPseudo(data->getPseudo() + "F");
        if (data->getInput() == Arcade::Input::G)
            data->setPseudo(data->getPseudo() + "G");
        if (data->getInput() == Arcade::Input::H)
            data->setPseudo(data->getPseudo() + "H");
        if (data->getInput() == Arcade::Input::I)
            data->setPseudo(data->getPseudo() + "I");
        if (data->getInput() == Arcade::Input::J)
            data->setPseudo(data->getPseudo() + "J");
        if (data->getInput() == Arcade::Input::K)
            data->setPseudo(data->getPseudo() + "K");
        if (data->getInput() == Arcade::Input::L)
            data->setPseudo(data->getPseudo() + "L");
        if (data->getInput() == Arcade::Input::M)
            data->setPseudo(data->getPseudo() + "M");
        if (data->getInput() == Arcade::Input::N)
            data->setPseudo(data->getPseudo() + "N");
        if (data->getInput() == Arcade::Input::O)
            data->setPseudo(data->getPseudo() + "O");
        if (data->getInput() == Arcade::Input::P)
            data->setPseudo(data->getPseudo() + "P");
        if (data->getInput() == Arcade::Input::Q)
            data->setPseudo(data->getPseudo() + "Q");
        if (data->getInput() == Arcade::Input::R)
            data->setPseudo(data->getPseudo() + "R");
        if (data->getInput() == Arcade::Input::S)
            data->setPseudo(data->getPseudo() + "S");
        if (data->getInput() == Arcade::Input::T)
            data->setPseudo(data->getPseudo() + "T");
        if (data->getInput() == Arcade::Input::U)
            data->setPseudo(data->getPseudo() + "U");
        if (data->getInput() == Arcade::Input::V)
            data->setPseudo(data->getPseudo() + "V");
        if (data->getInput() == Arcade::Input::W)
            data->setPseudo(data->getPseudo() + "W");
        if (data->getInput() == Arcade::Input::X)
            data->setPseudo(data->getPseudo() + "X");
        if (data->getInput() == Arcade::Input::Y)
            data->setPseudo(data->getPseudo() + "Y");
        if (data->getInput() == Arcade::Input::Z)
            data->setPseudo(data->getPseudo() + "Z");
        if (data->getInput() == Arcade::Input::Space)
            data->setPseudo(data->getPseudo() + " ");
    }
    if (data->getInput() == Arcade::Input::BackSpace)
    {
        if (data->getPseudo().size() > 0)
        {
            std::string str = data->getPseudo();
            str.pop_back();
            data->setPseudo(str);
        }
    }
}

void display_helper(My *data)
{
    // std::list<Arcade::Text *> help = data->getMenu()->getHelper();
    for (auto help : data->getMenu()->getHelper())
    {
       data->getLib()->drawText(*help);
       if (data->getMenu()->getHelperInfo() == 0)
        break;
    }
}

void display_menu(My *data) //changer le return pour les lib
{
    if (data->getInputPseudo() == 0)
    {
        if (data->getInput() == Arcade::Input::Return)
            menu_enter(data);
        if (data->getInput() == Arcade::Input::DOWN)
            menu_down(data);
        if (data->getInput() == Arcade::Input::UP)
            menu_up(data);
        if (data->getInput() == Arcade::Input::N)
            data->setInputPseudo(1);
        if (data->getInput() == Arcade::Input::H)
        {
            if (data->getMenu()->getHelperInfo() == 0)
                data->getMenu()->setHelperInfo(1);
            else
                data->getMenu()->setHelperInfo(0);
        }
    }
    else
    {
        if (data->getInputPseudo() == 1 && data->getInput() == Arcade::Input::Return)
            data->setInputPseudo(0);
        writePseudo(data);
    }
    data->getLib()->drawText(text);
    display_panel(data);
    display_pseudo(data);
    display_helper(data);
}

void change_lib_graphical_left(My *data, int d, std::map<int, Arcade::Text *> nameList)
{
    if (d == 1)
    {
        data->getLib()->stop();
        data->getLoaderLib().destroyInstance(data->getLib());
        data->setLib(data->getLoaderLib().getInstance("./lib/" + nameList[nameList.size() - 1]->getString()));
    } else
    {
        data->getLib()->stop();
        data->getLoaderLib().destroyInstance(data->getLib());
        data->setLib(data->getLoaderLib().getInstance("./lib/" + nameList[d - 2]->getString()));
    }
    data->getLib()->startClock();
}

void change_lib_graphical_right(My *data, int d, std::map<int, Arcade::Text *> nameList)
{
   if ((size_t)d == nameList.size())
    {
        data->getLib()->stop();
        data->getLoaderLib().destroyInstance(data->getLib());
        data->setLib(data->getLoaderLib().getInstance("./lib/" + nameList[0]->getString()));
    } else
    {
        data->getLib()->stop();
        data->getLoaderLib().destroyInstance(data->getLib());
        data->setLib(data->getLoaderLib().getInstance("./lib/" + nameList[d]->getString()));
    }
    data->getLib()->startClock();
}

void change_lib_game_left(My *data, int d, std::map<int, Arcade::Text *> nameList)
{
    if (d == 1)
    {
        data->getGame()->stop();
        data->getLoaderGame().destroyInstance(data->getGame());
        data->setGame(data->getLoaderGame().getInstance("./games/" + nameList[nameList.size() - 1]->getString()));
    } else
    {
        data->getGame()->stop();
        data->getLoaderGame().destroyInstance(data->getGame());
        data->setGame(data->getLoaderGame().getInstance("./games/" + nameList[d - 2]->getString()));
    }
}

void change_lib_game_right(My *data, int d, std::map<int, Arcade::Text *> nameList)
{
   if ((size_t)d == nameList.size())
    {
        data->getLoaderGame().destroyInstance(data->getGame());
        data->setGame(data->getLoaderGame().getInstance("./games/" + nameList[0]->getString()));
    } else
    {
        data->getGame()->stop();
        data->getLoaderGame().destroyInstance(data->getGame());
        data->setGame(data->getLoaderGame().getInstance("./games/" + nameList[d]->getString()));
    }
}

void change_lib_graphical(My *data)
{
    if (data->getInput() == Arcade::Input::Num1 || data->getInput() == Arcade::Input::Num2)
    {
        std::list<Panel *> panellist = data->getMenu()->getPanel();
        size_t d = 0;
        for (auto panel : panellist)
        {
            std::map<int, Arcade::Text *> nameList = panel->getName();
            if (nameList.size() == 1)
                return;
            for (auto name : nameList)
            {
                d++;
                if (name.second->getString().find(data->getLib()->getName()) < name.second->getString().size())
                {
                    break;
                }
            }
            (data->getInput() == Arcade::Input::Num1) ? change_lib_graphical_left(data, d, nameList) : change_lib_graphical_right(data, d, nameList) ;
            break;
        }
    }
}

void change_lib_game(My *data)
{
    int i = 0;
    if (data->getInput() == Arcade::Input::Num3 || data->getInput() == Arcade::Input::Num4)
    {

        std::list<Panel *> panellist = data->getMenu()->getPanel();
        size_t d = 0;
        for (auto panel : panellist)
        {
            if (i == 0)
                i++;
            else
            {
                std::map<int, Arcade::Text *> nameList = panel->getName();
                if (nameList.size() == 1)
                    return;
                for (auto name : nameList)
                {
                    d++;
                    if (name.second->getString().find(data->getGame()->getName()) < name.second->getString().size())
                    {
                        break;
                    }
                }
                (data->getInput() == Arcade::Input::Num3) ? change_lib_game_left(data, d, nameList) : change_lib_game_right(data, d, nameList) ;
                break;
            }
        }
    }
}


int loop_game(My *data) //changer le return pour les lib
{
    data->getLib()->startClock();
    while (1)
    {
        data->getLib()->setDeltaTime();
        if (data->getGame()->updateGame(data->getLib()) != -1 || data->getInput() == Arcade::Input::M || data->getInput() == Arcade::Input::Escape)
        {
            data->setStatu(0);
            return (-1);
        }
        if (data->getInput() == Arcade::Input::P)
        {
            data->setStatu(0);
            return (0);
        }
        change_lib_graphical(data);
        change_lib_game(data);
        data->getGame()->drawGame(data->getLib());
        data->getLib()->displayWindow();
        data->setInput(data->getLib()->coreInputs());
        auto tmp = data->getInput();
        data->getGame()->updateInput(tmp);
    }
}

std::map<int, std::map<int, int>> create_position_rect(int x, int y)
{
    std::map<int, std::map<int, int>> data;
    std::map<int, int> rect_data;
    //--------contour----------
    rect_data[0] = x;   //position
    rect_data[1] = y;   //position
    rect_data[2] = 300; //size x
    rect_data[3] = 200; //size y
    data[0] = rect_data;
    rect_data.clear();
    //--------interieur----------
    rect_data[0] = x + 20;   //position
    rect_data[1] = y + 20;   //position
    rect_data[2] = 260; //size x
    rect_data[3] = 160; //size y
    data[1] = rect_data;
    rect_data.clear();
    //--------exterieur scroll----------
    rect_data[0] = x + 240;   //position
    rect_data[1] = y + 50;   //position
    rect_data[2] = 20; //size x
    rect_data[3] = 120; //size y
    data[2] = rect_data;
    rect_data.clear();
    //--------arriere scroll----------
    rect_data[0] = x + 245;   //position
    rect_data[1] = y + 55;   //position
    rect_data[2] = 10; //size x
    rect_data[3] = 110; //size y
    data[3] = rect_data;
    rect_data.clear();
    //--------scroll----------
    rect_data[0] = x + 245;   //position
    rect_data[1] = y + 55;   //position
    rect_data[2] = 10; //size x
    rect_data[3] = 80; //size y
    data[4] = rect_data;
    rect_data.clear();
    return (data);
}

std::map<int, Arcade::Color> create_color_rect()
{
    std::map<int, Arcade::Color> color;
    color[0] = white;
    color[1] = black;
    color[2] = white;
    color[3] = grey; //possiblité de secfault en ncurse
    color[4] = black;
    return (color);
}

std::map<int, Arcade::Rectangle *> create_rect(int x, int y)
{
    std::map<int , Arcade::Rectangle *> result;
    std::map<int, std::map<int, int>> data = create_position_rect(x, y);
    std::map<int, Arcade::Color> color = create_color_rect();
    for (int i = 0; i != 5; i++)
    {
        Arcade::Rectangle *rect = new Arcade::Rectangle();
        rect->setColor(color[i]);
        Arcade::Vector2f position(data[i][0], data[i][1]);
        Arcade::Vector2f size(data[i][2], data[i][3]);
        rect->setPosition(position);
        rect->setSize(size);
        result[i] = rect;
    }
    return (result);
}

std::map<int, Arcade::Text *> create_listname(std::list<std::string> namelist, int x, int y)
{
    std::map<int, Arcade::Text *> result;
    (void)x;
    (void)y;
    x += 30;
    y += 30;
    int d = 0;
    for (auto name : namelist)
    {
        Arcade::Text *text = new Arcade::Text(name);
        Arcade::Vector2f position(x, y);
        text->setPosition(position);
        text->setSize(20);
        text->setColor(white);
        y += 20;
        result[d] = text;
        d++;
    }
    return (result);
}

Panel *create_panel(std::list<std::string> name, int x = 0, int y = 0)
{
    Panel *panel = new Panel();
    panel->setRect(create_rect(x, y));
    panel->setName(create_listname(name, x, y));
    return (panel);
}

Pseudo *create_pseudo()
{
    std::list<Arcade::Rectangle *> rectlist;
    Arcade::Rectangle *rect = new Arcade::Rectangle(Arcade::Vector2f(500,50), Arcade::Vector2f(290,495),white);
    rectlist.push_back(rect);
    Pseudo *pseudo = new Pseudo();
    Arcade::Text *text = new Arcade::Text("Name : ", white, Arcade::Vector2f(300,500));
    pseudo->setPseudo(text);
    Arcade::Text *limitesize = new Arcade::Text("SIZE LIMIT REACHED", red, Arcade::Vector2f(300,550), 20);
    pseudo->setLimitSize(limitesize);
    pseudo->setRectList(rectlist);
    return (pseudo);
}

std::list<Arcade::Text *> create_helper()
{
    std::list<Arcade::Text *> help;
    Arcade::Text *help1 = new Arcade::Text("For display the helper use : H", white, Arcade::Vector2f(300, 580), 20);
    help.push_back(help1);
    Arcade::Text *help2 = new Arcade::Text("To move use : Arrow Up and Down", white, Arcade::Vector2f(300, 610), 20);
    help.push_back(help2);
    Arcade::Text *help3 = new Arcade::Text("To validate your choice use : Enter", white, Arcade::Vector2f(300, 640), 20);
    help.push_back(help3);
    Arcade::Text *help4 = new Arcade::Text("For leave everything use : Escape", white, Arcade::Vector2f(300, 670), 20);
    help.push_back(help4);
    Arcade::Text *help5 = new Arcade::Text("for write your Pseudo use : N", white, Arcade::Vector2f(300, 700), 20);
    help.push_back(help5);
    return (help);
}

Menu *init_Menu(My *data)
{
    Menu *menu = new Menu();
    menu->addPanel(create_panel(data->getNameLib(), 300, 200));
    menu->addPanel(create_panel(data->getNameGame(), 700, 200));
    menu->setSizeOption(data->getNameLib().size() + data->getNameGame().size());
    menu->setPseudo(create_pseudo());
    menu->setHelper(create_helper());
    return (menu);
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage : ./arcade ./lib_arcade_sfml.so" << std::endl;
        return (84);
    }

    DLLoader<IDisplayModule> loaderLib;
    DLLoader<IGameModule> loadergame;
    My data(loaderLib.getInstance(av[1]));
    data.setLoaderLib(loaderLib);
    data.setLoaderGame(loadergame);
    data.setListLib(find_lib_in_folder("./lib"));
    data.setListGame(find_lib_in_folder("./games"));
    data.setMenu(init_Menu(&data));
    while (1)
    {
        if (data.getInput() == Arcade::Input::Escape)
            break;
        data.setInput(data.getLib()->coreInputs());
        if (data.getStatu() == 0)
            display_menu(&data);
        else {
            if (loop_game(&data) == -1 || data.getInput() == Arcade::Input::M || data.getInput() == Arcade::Input::Escape)
               data.getLoaderGame().destroyInstance(data.getGame());
            else
                data.setInput(Arcade::Input::None);
        }
        data.getLib()->displayWindow();
    }
    loaderLib.destroyInstance(data.getLib());
    (void) ac;

    return (0);
}
