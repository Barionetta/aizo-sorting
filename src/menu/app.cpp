/**
 * Plik źródłowy zawierający główną pętle programu
 */

#include "app.h"

/**
 * Konstruktor klasy App
*/
App::App()
    : is_running_(false),
      is_int_type_array_(true),
      state_(1)
{
    modes_menu_ = {make_pair(1, Menu::Entry("Przeprowadź testy\n", [this](){ this->set_state(2); })),
                   make_pair(2, Menu::Entry("Przeprowadź badania\n", [](){ Tester::testing(); })),
                   make_pair(3, Menu::Entry("Zakończ\n", [this](){ this->is_running_ = false; }))};

    table_menu_ = {make_pair(1, Menu::Entry("Wygeneruj tablicę danych typu int z pliku\n", [this](){ cout << "Podaj nazwę pliku: \n"; std::string filename; cin >> filename; this->demo_array_int_ = Others::read_array_from_file<int>(filename); this->is_int_type_array_=true;})),
                   make_pair(2, Menu::Entry("Wygeneruj tablicę danych typu int losowo\n", [this](){ cout << "Podaj rozmiar tablicy: \n"; int size; cin >> size; this->demo_array_int_ = Others::generate_random_array<int>(size, 0, 1000); this->is_int_type_array_=true;})),
                   make_pair(3, Menu::Entry("Wygeneruj tablicę danych typu float z pliku\n", [this](){ cout << "Podaj nazwę pliku: \n"; std::string filename; cin >> filename; this->demo_array_float_ = Others::read_array_from_file<float>(filename); this->is_int_type_array_=false;})),
                   make_pair(4, Menu::Entry("Wygeneruj tablicę danych typu float losowo\n", [this](){ cout << "Podaj rozmiar tablicy: \n"; int size; cin >> size; this->demo_array_float_ = Others::generate_random_array<float>(size, 0, 1000); this->is_int_type_array_=false;})),
                   make_pair(5, Menu::Entry("Zakończ\n", [this](){ this->is_running_ = false; }))};

    algorithms_menu_ = {make_pair(1, Menu::Entry("Posortuj tablicę algorytmem przez wstawianie\n", [this](){ if(this->is_int_type_array_) { perform_alogrithm(this->demo_array_int_, insertion_sort<int>); } else { perform_alogrithm(this->demo_array_float_, insertion_sort<float>); } })),
                        make_pair(2, Menu::Entry("Posortuj tablicę algorytmem przez kopcowanie\n", [this](){ if(this->is_int_type_array_) { perform_alogrithm(this->demo_array_int_, heapsort<int>); } else { perform_alogrithm(this->demo_array_float_, heapsort<float>); } })),
                        make_pair(3, Menu::Entry("Posortuj tablicę za pomocą metody Shella ze wzoru oryginalnego\n", [this](){ if(this->is_int_type_array_) { perform_alogrithm(this->demo_array_int_, shellsort<int>); } else { perform_alogrithm(this->demo_array_float_, shellsort<float>); } })),
                        make_pair(4, Menu::Entry("Posortuj tablicę za pomocą metody Shella ze wzoru Knutha\n", [this](){ if(this->is_int_type_array_) { perform_alogrithm(this->demo_array_int_, shellsort_knuth<int>); } else { perform_alogrithm(this->demo_array_float_, shellsort_knuth<float>); } })),
                        make_pair(5, Menu::Entry("Posortuj tablicę algorytmem szybkim z pivotem po lewej\n", [this](){ if(this->is_int_type_array_) { perform_alogrithm(this->demo_array_int_, std::bind(quicksort<int>, _1, 1)); } else { perform_alogrithm(this->demo_array_float_, std::bind(quicksort<float>, _1, 1)); } })),
                        make_pair(6, Menu::Entry("Posortuj tablicę algorytmem szybkim z pivotem po prawej\n", [this](){ if(this->is_int_type_array_) { perform_alogrithm(this->demo_array_int_, std::bind(quicksort<int>, _1, 2)); } else { perform_alogrithm(this->demo_array_float_, std::bind(quicksort<float>, _1, 2)); } })),
                        make_pair(7, Menu::Entry("Posortuj tablicę algorytmem szybkim z pivotem po środku\n", [this](){ if(this->is_int_type_array_) { perform_alogrithm(this->demo_array_int_, std::bind(quicksort<int>, _1, 3)); } else { perform_alogrithm(this->demo_array_float_, std::bind(quicksort<float>, _1, 3)); } })),
                        make_pair(8, Menu::Entry("Posortuj tablicę algorytmem szybkim z pivotem losowym\n", [this](){ if(this->is_int_type_array_) { perform_alogrithm(this->demo_array_int_, std::bind(quicksort<int>, _1, 4)); } else { perform_alogrithm(this->demo_array_float_, std::bind(quicksort<float>, _1, 4)); } })),
                        make_pair(9, Menu::Entry("Wygeneruj nową tablicę\n", [this](){ this->set_state(2); })),
                        make_pair(10, Menu::Entry("Zakończ\n", [this](){ this->is_running_ = false; }))};
}

/**
 * Funkcja uruchamiająca aplikację
*/
void App::run()
{
    this->is_running_ = true;
    cout << "Algorytmy i Złożoność Obliczeniowa Projekt 1 - Algorytmy sortowania\n";
    do
    {
        switch(this->state_) {
            case 1:
                perform_mode_selection();
                break;
            case 2:
                perform_table_creation();
                break;
            case 3:
                perform_algorithm_selection();
                break;
            default:
                cout << "Nieobsługiwany stan!\n";
        }
    } while (this->is_running_);
}

/**
 * Funkcja ustawiająca stan aplikacji
 * 
 * @param state Numer stanu aplikacji [unsigned int]
*/
void App::set_state(unsigned int state)
{
    this->state_ = state;
}

/**
 * Funkcja wykonująca stan wyboru trybu
*/
void App::perform_mode_selection()
{
    Menu::getEntry(this->modes_menu_);
}

/**
 * Funkcja wykonująca stan tworzenia tablicy
*/
void App::perform_table_creation()
{
    cout << "Jak chcesz wygenerować dane?\n";
    Menu::getEntry(this->table_menu_);
    this->set_state(3);
}

/**
 * Funkcja wykonująca stan wyboru algorytmu
*/
void App::perform_algorithm_selection()
{
    cout << "Jaki algorytm chcesz zaprezentować?\n";
    Menu::getEntry(this->algorithms_menu_);
}

/**
 * Funkcja wykonująca wybrany algorytm
 * 
 * @param array Tablica, na której ma być wykonywany algorytm [T]
 * @param sorting_function Funkcja, za pomocą której ma być sortowana tablica [F]
*/
template <typename T, typename F>
void App::perform_alogrithm(T array, F sorting_function)
{
    cout << "Tablica przed sortowaniem: ";
    array.print();
    cout << "Sortuję...\n";
    sorting_function(array);
    cout << "Tablica po sortowaniu: ";
    array.print();
}

/*
*   Zdefiniowanie typów dla funkcji
*/
template void App::perform_alogrithm(Array<int> array, std::function<void(Array<int>)> sorting_function);
template void App::perform_alogrithm(Array<float> array, std::function<void(Array<float>)> sorting_function);