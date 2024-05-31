/**
 * Plik nagłówkowy pliku zawierającego kod klasy App odpowiedzialnej za sterowanie programem
 */

#ifndef APP_H
#define APP_H
#include "menu.h"
#include "test.h"
#include "algorithms/heap_sort.h"
#include "algorithms/insertion_sort.h"
#include "algorithms/quick_sort.h"
#include "algorithms/shell_sort.h"
#include "utils/array.h"
#include "utils/others.h"

#include <iostream>
#include <string>

using std::cout, std::cin, std::make_pair;
using namespace std::placeholders;

class App
{
public:
    // Konstruktor klasy App
    App();
    // Destruktor klasy App
    ~App() = default;
    // Funkcja uruchamiająca aplikację
    void run();

private:
    bool is_running_;                                               // Czy aplikacja jest uruchomiona               [bool]
    bool is_int_type_array_;                                        // Czy aktywną tablicą jest tablica integerów   [bool]
    unsigned int state_;                                            // Stan aplikacji                               [unsigned int]
    Menu::MenuEntries modes_menu_, table_menu_, algorithms_menu_;   // Menu aplikacji                               [MenuEntries]
    Array<int> demo_array_int_;                                     // Tablica demonstracyjna typu int              [Array<int>]
    Array<float> demo_array_float_;                                 // Tablica demonstracyjna typu float            [Array<float>]

    // Funkcja ustawiająca stan aplikacji
    void set_state(unsigned int state);
    // Funkcja wykonująca stan wyboru trybu
    void perform_mode_selection();
    // Funkcja wykonująca stan tworzenia tablicy
    void perform_table_creation();
    // Funkcja wykonująca stan wyboru algorytmu
    void perform_algorithm_selection();
    // Funkcja wykonująca wybrany algorytm
    template <typename T, typename F>
    void perform_alogrithm(T array, F sorting_function);
};

#endif