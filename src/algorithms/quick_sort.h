/**
 * Plik nagłówkowy pliku zawierającego implementację algorytmu sortowania szybkiego
 */
#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include "utils/array.h"

// Funkcja do partycjonowania
template <typename T> void partition(Array<T>& array, int first, int last);
// Rekurencyjny Quick Sort
template <typename T> void reqQuickSort(Array<T>& array, int first, int last);
// Funkcja do sortowania szybkiego
template <typename T> void quicksort(Array<T>& array);

#endif