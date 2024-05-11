/**
 * Plik nagłówkowy pliku zawierającego implementację algorytmu sortowania przez kopcowanie
 */
#ifndef HEAP_SORT_H
#define HEAP_SORT_H
#include "utils/array.h"

// Funkcja zwracająca indeks lewego dziecka
int getLeftChild(int idx);
// Funkcja zwracająca indeks prawego dziecka
int getRightChild(int idx);
// Funkcja pomocnicza zwracająca indeks lewego dziecka
template <typename T> T getLeftChild(int idx);
// Funkcja pomocnicza zwracająca indeks prawego dziecka
template <typename T> T getRightChild(int idx);
// Funkcja przeprowadzająca algorytm kopcowania
template <typename T> void maxHeapify(Array<T>& array, int idx, int size);
// Funkcja do budowania kopca
template <typename T> void buildMaxHeap(Array<T>& array);
// Funkcja do sortowania przez kopcowanie
template <typename T> void heapsort(Array<T>& array);

#endif