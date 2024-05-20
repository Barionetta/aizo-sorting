/**
 * Plik nagłówkowy pliku zawierającego główną pętle programu
 */
#ifndef APP_H
#define APP_H
#include <variant>
#include "menu.h"
#include "utils/array.h"

class App
{
public:
    App();
    void setState(unsigned int state);
    void performState1();
    void performState2();
    void performState3();
    void perform();
    void run();
    ~App();

private:
    bool is_running_;
    unsigned int state_;
    Menu::MenuEntries modes_menu_, table_menu_, algorithms_menu_;
    std::variant<Array<int>, Array<float>> demo_array_;
};

#endif