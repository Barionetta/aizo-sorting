/**
 * Plik nagłówkowy pliku zawierającego implementację algorytmu metodą Shella
 */
#ifndef SHELL_SORT_H
#define SHELL_SORT_H
#include "utils/array.h"

// Funkcja do sortowania tablicy przez wstawianie
template <typename T> void partialInsertionSort(Array<T>& array, int begin, int i);
// Funkcja do sortowania metodą Shella
template <typename T> void shellsort(Array<T>& array);

#endif