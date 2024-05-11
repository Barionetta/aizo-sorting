/**
 * Plik nagłówkowy pliku zawierającego implementację algorytmu sortowania szybkiego
 */
#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include "utils/array.h"

// Funkcja do partycjonowania
template <typename T> int partition(Array<T>& array, int left, int rigth);
// Rekurencyjny Quick Sort
template <typename T> void recQuickSort(Array<T>& array, int left, int rigth);
// Funkcja do sortowania szybkiego
template <typename T> void quicksort(Array<T>& array);

#endif