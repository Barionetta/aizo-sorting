/**
 * Plik główny programu
 */
#include <iostream>
#include "menu/app.h"

int main(int, char **)
{
    App app;
    app.run();
    std::cout << "Program zakończono.\n";
    return 0;
}