/**
 * Plik nagłówkowy pliku zawierającego implementację algorytmu sortowania szybkiego
 */
#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include "utils/array.h"

// Funkcja pomocnicza do generowania losowej liczby całkowitej
int generateRandomNumber(int down, int up);
// Funkcja do partycjonowania
template <typename T> int partition(Array<T>& array, int left, int right, int& pivotType);
// Funkcja do sortowania szybkiego
template <typename T> void recQuicksort(Array<T>& array, int left, int right, int& pivotType);
// Funkcja do sortowania szybkiego
template <typename T> void quicksort(Array<T>& array, int pivotType);

#endif