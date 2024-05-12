/**
 * Plik źródłowy zawierający implementację algorytmu sortowania przez kopcowanie
 */
#include "heap_sort.h"
#include "utils/array.h"
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * Funkcja przeprowadzająca algorytm kopcowania.
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 165
 *
 * @param array Tablica, na której przeprowadzany jest algorytm [Array<T>]
 * @param root Indeks korzenia poddrzewa, które się kopcuje [int]
 * @param size Rozmiar kopca [int]
*/
template <typename T>
void maxHeapify(Array<T>& array, int root, int size)
{
    int largest;
    T temp = array[root];
    largest = 2 * root + 1;

    while (largest <= size)
    {
        if(largest < size)
        {
            if (array[largest] < array[largest + 1]) { largest++; }
        }
        if(temp > array[largest]) { break; }
        else
        {
            array[root] = array[largest];
            root = largest;
            largest = 2 * root + 1;
        }
    }
    array[root] = temp;
}

/**
 * Funkcja do budowania kopca
 * 
 * @param array Tablica, z której robiony będzie kopiec [Array<T>]
*/
template <typename T>
void buildMaxHeap(Array<T>& array)
{
    for (int i = array.getLength() / 2 - 1; i >= 0; i--)
    {
        maxHeapify(array, i, array.getLength() - 1);
    }
}

/**
 * Funkcja do sortowania przez kopcowanie
 * 
 * @param array Tablica, którą należy posortować [Array<T>]
*/
template <typename T>
void heapsort(Array<T>& array)
{
    T temp;
    buildMaxHeap(array);
    for ( int i = array.getLength() - 1; i >= 0; i--)
    {
        swap(array[i], array[0]);
        maxHeapify(array, 0, i - 1);
    }
}

/*
*   Zdefiniowanie typów dla funkcji
*/
template void maxHeapify(Array<int>& array, int root, int size);
template void maxHeapify(Array<float>& array, int root, int size);
template void buildMaxHeap(Array<int>& array);
template void buildMaxHeap(Array<float>& array);
template void heapsort(Array<int>& array);
template void heapsort(Array<float>& array);