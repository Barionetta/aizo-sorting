/**
 * Plik źródłowy zawierający implementację algorytmu sortowania przez wstawianie
 */

#include "insertion_sort.h"

/**
 * Funkcja do sortowania tablicy przez wstawianie
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 19
 * 
 * @param array Tablica, którą należy posortować [Array<T>]
*/
template <typename T>
void insertionsort(Array<T>& array)
{
    int i, j;
    T key;
    for (i = 1; i < array.get_size(); i++)
    {
        if (array[i] < array[i - 1])
        {
            key = array[i];
            j = i;
            do
            {
                array[j] = array[j - 1];
                j--;
            } while (j > 0 && array[j - 1] > key);

            array[j] = key;
        }
    }
}

/*
*   Zdefiniowanie typów dla funkcji
*/
template void insertionsort(Array<int>& array);
template void insertionsort(Array<float>& array);