/**
 * Plik źródłowy zawierający główną pętle symulacji
 */
#include <iostream>
#include <utility>
#include "app.h"
#include "menu.h"
using std::cout, std::cin, std::make_pair;

App::App()
{
    is_running_ = false;
    state_ = 1;
    //modes_menu_ = {make_pair(1, Menu::Entry("nah", performState1())),
    //               make_pair(1, Menu::Entry("nah", performState1())),
    //               make_pair(1, Menu::Entry("nah", performState1()))};
}

void App::setState(unsigned int state)
{
    state_ = state;
}

void App::performState1()
{
    
}

void App::performState2()
{
    
}

void App::performState3()
{
    
}

void App::run()
{

}

App::~App()
{

}