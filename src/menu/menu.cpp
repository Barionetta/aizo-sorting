/**
 * Plik źródłowy zawierający główną pętle symulacji
 */
#include "menu.h"
#include "test_loop.h"
#include "demo_menu.h"
#include <iostream>
using namespace std;

/**
 * Funkcja pomocnicza do wyświetlania dostępnych trybów
 */
void showModes()
{
    cout << "Co chcesz wykonać?\n";
    cout << "1 - Zaprezentuj algorytmy\n";
    cout << "2 - Przeprowadź badania\n";
    cout << "0 - Zakończ program\n";
}

/**
 * Główna pętla programu
 */
void loop()
{
    cout << "Algorytmy i Złożoność Obliczeniowa Projekt 1 - Algorytmy sortowania\n";
    short int mode;
    showModes();
    cin >> mode;
    while (mode < 0 || mode > 2)
    {
        cout << "Wprowadź poprawną opcję.\n";
        cin >> mode;
    }
    switch (mode)
    {
    case 1:
    {
        demo();
        break;
    }
    case 2:
    {
        testing();
        break;
    }
    default:
    {
        break;
    }
    }
    return;
}