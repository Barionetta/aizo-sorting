/**
 * Plik źródłowy zawierający implementację algorytmu sortowania szybkiego
 */
#include "quick_sort.h"
#include "utils/array.h"
#include <iostream>
using namespace std;

/**
 * Funkcja do sortowania szybkiego
 * 
 * @param array Tablica, którą należy posortować [Array<T>]
 * @param first Indeks skrajnie lewego elementu [int]
 * @param last Indeks skrajnie prawego elementu [int]
*/
template <typename T>
void partition(Array<T>& array, int first, int last)
{

}

/**
 * Funkcja do sortowania szybkiego
 * 
 * @param array Tablica, którą należy posortować [Array<T>]
 * @param first Indeks skrajnie lewego elementu [int]
 * @param last Indeks skrajnie prawego elementu [int]
*/
template <typename T>
void reqQuickSort(Array<T>& array, int first, int last)
{

}

/**
 * Funkcja do sortowania szybkiego
 * 
 * @param array Tablica, którą należy posortować [Array<T>]
*/
template <typename T>
void quicksort(Array<T>& array)
{

}

/*
*   Zdefiniowanie typów dla funkcji
*/
template void partition(Array<int>& array, int first, int last);
template void partition(Array<float>& array, int first, int last);
template void reqQuickSort(Array<int>& array, int first, int last);
template void reqQuickSort(Array<float>& array, int first, int last);
template void quicksort(Array<int>& array);
template void quicksort(Array<float>& array);