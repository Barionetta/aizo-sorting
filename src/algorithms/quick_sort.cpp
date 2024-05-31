/**
 * Plik źródłowy zawierający implementację algorytmu sortowania szybkiego
 */
#include "quick_sort.h"

/**
 * Funkcja do sortowania szybkiego
 * 
 * @param array Tablica, którą należy posortować [Array<T>]
 * @param left Indeks skrajnie lewego elementu [int]
 * @param right Indeks skrajnie prawego elementu [int]
*/
template <typename T>
int partition(Array<T>& array, int left, int right, int& pivot_type)
{
    T pivot;
    switch (pivot_type)
    {
    case 1: pivot = array[left]; break;
    case 2: pivot = array[right]; break;
    case 3: pivot = array[(left + right) / 2]; break;
    case 4: pivot = array[Others::generate_random_number(left,right)]; break;
    default: pivot = array[(left + right) / 2]; break;
    }
    int j = left;
    
    for (int i = left; i < right; i++)
    {
        if (array[i] < array[right])
        {
            Others::swap(array[i], array[j]);
            j++;
        }
    }
    Others::swap(array[right], array[j]);
    return j;
}

/**
 * Funkcja do sortowania szybkiego
 * 
 * @param array Tablica, którą należy posortować [Array<T>]
 * @param left Indeks skrajnie lewego elementu [int]
 * @param right Indeks skrajnie prawego elementu [int]
 * @param pivot_type Typ pivota [int]
*/
template <typename T>
void rec_quicksort(Array<T>& array, int left, int right, int& pivot_type)
{
    if (left < right)
    {
        int pivot = partition(array, left, right, pivot_type);
        rec_quicksort(array, left, pivot - 1, pivot_type);
        rec_quicksort(array, pivot + 1, right, pivot_type);
    }
}

/**
 * Funkcja do sortowania szybkiego
 * 
 * @param array Tablica, którą należy posortować [Array<T>]
 * @param pivot_type Typ pivota [int]
*/
template <typename T>
void quicksort(Array<T>& array, int pivot_type)
{
    int n = array.get_size();
    rec_quicksort(array, 0, n - 1, pivot_type);
}

/*
*   Zdefiniowanie typów dla funkcji
*/
template int partition(Array<int>& array, int left, int right, int& pivot_type);
template int partition(Array<float>& array, int left, int right, int& pivot_type);
template void rec_quicksort(Array<int>& array, int left, int right, int& pivot_type);
template void rec_quicksort(Array<float>& array, int left, int right, int& pivot_type);
template void quicksort(Array<int>& array, int pivot_type);
template void quicksort(Array<float>& array, int pivot_type);