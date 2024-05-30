/**
 * Plik nagłówkowy pliku zawierającego implementację algorytmu sortowania przez kopcowanie
 */

#ifndef HEAP_SORT_H
#define HEAP_SORT_H
#include "utils/array.h"
#include "utils/others.h"

// Funkcja przeprowadzająca algorytm kopcowania
template <typename T> void max_heapify(Array<T>& array, int root, int size);
// Funkcja do budowania kopca
template <typename T> void build_max_heap(Array<T>& array);
// Funkcja do sortowania przez kopcowanie
template <typename T> void heapsort(Array<T>& array);

#endif