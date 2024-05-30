/**
 * Plik nagłówkowy pliku zawierającego implementację algorytmu sortowania szybkiego
 */

#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include "utils/array.h"
#include "utils/others.h"

// Funkcja do partycjonowania
template <typename T> int partition(Array<T>& array, int left, int right, int& pivot_type);
// Funkcja do sortowania szybkiego
template <typename T> void rec_quicksort(Array<T>& array, int left, int right, int& pivot_type);
// Funkcja do sortowania szybkiego
template <typename T> void quicksort(Array<T>& array, int pivot_type);

#endif