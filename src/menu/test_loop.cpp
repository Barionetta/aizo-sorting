/**
 * Plik źródłowy zawierający kod do mierzenia czasu wykonywania algorytmów
 */
#include "test_loop.h"
#include "utils/array.h"
#include <iostream>
using namespace std;

/**
 * Główna funkcja do testowania algorytmów
 */
void testing()
{
    cout << "Testowańsko...\n";
    int n = 300;
    int interval = 0;
    do
    {
        interval = interval * 3 + 1;
        cout << interval << endl;
    } while (interval < n / 3);
    
}