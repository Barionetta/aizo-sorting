/**
 * Plik główny programu
 */
#include <iostream>
#include "core/app.h"

int main(int, char **)
{
    App app;
    app.run();
    std::cout << "Program zakończono.\n";
    return 0;
}