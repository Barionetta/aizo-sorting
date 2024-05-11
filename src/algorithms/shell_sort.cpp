/**
 * Plik źródłowy zawierający implementację algorytmu metodą Shella
 */
#include "shell_sort.h"
#include "utils/array.h"
#include <iostream>
using namespace std;

/**
 * Funkcja do sortowania metodą Shella
 * 
 * @param array Tablica, którą należy posortować [Array<T>]
*/
template <typename T>
void shellsort(Array<T>& array)
{
    int n = array.getLength();
    for (int interval = n / 2; interval > 0; interval /= 2)
    {
        for(int i = interval; i < n; i++)
        {
            T temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
            {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
}

/**
 * Funkcja do sortowania metodą Shella z wzorem Knutha
 * 
 * @param array Tablica, którą należy posortować [Array<T>]
*/
template <typename T>
void shellsortKnuth(Array<T>& array)
{
    int n = array.getLength();
    int init = 0;
    do { init = init * 3 + 1; } while (init < n / 3);
    
    for (int interval = init; interval > 0; interval /= 3)
    {
        for(int i = interval; i < n; i++)
        {
            T temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
            {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
}

/*
*   Zdefiniowanie typów dla funkcji
*/
template void shellsort(Array<int>& array);
template void shellsort(Array<float>& array);
template void shellsortKnuth(Array<int>& array);
template void shellsortKnuth(Array<float>& array);