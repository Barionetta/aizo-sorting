/**
 * Plik nagłówkowy pliku zawierającego struktury i funkcje do obsługi menu
 */

#ifndef MENU_H
#define MENU_H

#include <functional>
#include <map>
#include <string>

namespace Menu
{
    typedef std::function<void()> entryFunction;

    struct Entry
    {
        Entry(std::string d, entryFunction f) : description(d), function(f) {};
        std::string description;
        entryFunction function;
    };

    typedef std::map<unsigned int, Entry> MenuEntries;

    void show(MenuEntries menu);

    void getEntry(MenuEntries menu);

};

#endif