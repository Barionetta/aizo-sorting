/**
 * Plik nagłówkowy pliku zawierającego implementację algorytmu metodą Shella
 */

#ifndef SHELL_SORT_H
#define SHELL_SORT_H
#include "utils/array.h"

// Funkcja do sortowania metodą Shella
template <typename T> void shellsort(Array<T>& array);
// Funkcja do sortowania metodą Shella z wzorem Knutha
template <typename T> void shellsort_knuth(Array<T>& array);

#endif