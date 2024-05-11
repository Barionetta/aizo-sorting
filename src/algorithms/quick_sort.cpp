/**
 * Plik źródłowy zawierający implementację algorytmu sortowania szybkiego
 */
#include "quick_sort.h"
#include "utils/array.h"
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * Funkcja do sortowania szybkiego
 * 
 * @param array Tablica, którą należy posortować [Array<T>]
 * @param left Indeks skrajnie lewego elementu [int]
 * @param rigth Indeks skrajnie prawego elementu [int]
*/
template <typename T>
int partition(Array<T>& array, int left, int rigth)
{

}

/**
 * Funkcja do sortowania szybkiego
 * 
 * @param array Tablica, którą należy posortować [Array<T>]
 * @param left Indeks skrajnie lewego elementu [int]
 * @param right Indeks skrajnie prawego elementu [int]
*/
template <typename T>
void recQuickSort(Array<T>& array, int left, int rigth)
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
template int partition(Array<int>& array, int left, int rigth);
template int partition(Array<float>& array, int left, int rigth);
template void recQuickSort(Array<int>& array, int left, int rigth);
template void recQuickSort(Array<float>& array, int left, int rigth);
template void quicksort(Array<int>& array);
template void quicksort(Array<float>& array);