/**
 * Plik źródłowy zawierający struktury i funkcje do obsługi menu
 */

#include "menu.h"
#include <iostream>

void Menu::show(MenuEntries menu, std::string header)
{
    std::cout << header;
    for (auto const& [key, label] : menu)
    {
        std::cout << key << ' - ' << label.description << std::endl;
    }
}

void Menu::getEntry(MenuEntries menu)
{
    show(menu);
    unsigned int choice;
    std::cin >> choice;

    try
    {
        Entry entry = menu.at(choice);
        (entry.function)();
    }
    catch(std::out_of_range& e)
    {
        std::cout << "Niepoprawny wybór\n";
    }
}
