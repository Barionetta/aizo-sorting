/**
 * Plik źródłowy zawierający implementację algorytmu metodą Shella
 */
#include "shell_sort.h"
#include "utils/array.h"
#include <iostream>
using namespace std;

/**
 * Funkcja do sortowania szybkiego
 * 
 * @param array Tablica, którą należy posortować [Array<T>]
 * @param begin Indeks skrajnie lewego elementu [int]
 * @param i Indeks skrajnie prawego elementu [int]
*/
template <typename T>
void partialInsertionSort(Array<T>& array, int begin, int i)
{

}

/**
 * Funkcja do sortowania metodą Shella
 * 
 * @param array Tablica, którą należy posortować [Array<T>]
*/
template <typename T>
void shellsort(Array<T>& array)
{

}

/*
*   Zdefiniowanie typów dla funkcji
*/
template void partialInsertionSort(Array<int>& array, int begin, int i);
template void partialInsertionSort(Array<float>& array, int begin, int i);
template void shellsort(Array<int>& array);
template void shellsort(Array<float>& array);