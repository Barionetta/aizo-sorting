/**
 * Plik źródłowy zawierający implementację algorytmu sortowania przez kopcowanie
 */
#include "heap_sort.h"
#include "utils/array.h"
#include <cmath>
#include <iostream>
using namespace std;

/**
 * Funkcja zwracająca indeks lewego dziecka
 *
 * @param idx Indeks elementu, którego dziecko jest poszukiwane [int]
 * @return Indeks lewego dziecka [int]
 */
int getLeftChild(int idx) { return (2 * idx) + 1; }

/**
 * Funkcja zwracająca indeks prawego dziecka
 *
 * @param idx Indeks elementu, którego dziecko jest poszukiwane [int]
 * @return Indeks prawego dziecka [int]
 */
int getRightChild(int idx) { return (2 * idx) + 2; }

/**
 * Funkcja przeprowadzająca algorytm kopcowania.
 * Cormen, Thomas H.; Leiserson, Charles E.; Rivest, Ronald L.;
 * Stein, Clifford (2022) [1990]. Introduction to Algorithms (4th ed.)
 * Strona 165
 *
 * @param array Tablica, na której przeprowadzany jest algorytm [Array<T>]
 * @param idx Indeks elementu, od którego robi się kopcowanie [int]
 * @param size Rozmiar kopca [int]
*/
template <typename T>
void maxHeapify(Array<T>& array, int idx, int size)
{
    int largest = idx;
    int leftChild = getLeftChild(idx);
    int rightChild = getRightChild(idx);
    if (leftChild <= size && array[leftChild] > array[idx])
    {
        largest = leftChild;
    }
    if (rightChild <= size && array[rightChild] > array[largest])
    {
        largest = rightChild;
    }
    if (largest != idx)
    {
        // Zamiana
        T temp = move(array[idx]);
        array[idx] = move(array[largest]);
        array[largest] = move(temp);
        //
        maxHeapify(array, largest, size);
    }
}

/**
 * Funkcja do budowania kopca
 * 
 * @param array Tablica, z której robiony będzie kopiec [Array<T>]
*/
template <typename T>
void buildMaxHeap(Array<T>& array)
{
    int n = array.getLenght();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(array, i-1, n);
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
    buildMaxHeap(array);
    int n = array.getLenght();
    for (int i = n - 1; i > 0; i--)
    {
        // Zamiana
        T temp = move(array[0]);
        array[0] = move(array[i]);
        array[i] = move(temp);
        //
        maxHeapify(array, 0, i);
    }
}

/*
*   Zdefiniowanie typów dla funkcji
*/
template void maxHeapify(Array<int>& array, int idx, int size);
template void maxHeapify(Array<float>& array, int idx, int size);
template void buildMaxHeap(Array<int>& array);
template void buildMaxHeap(Array<float>& array);
template void heapsort(Array<int>& array);
template void heapsort(Array<float>& array);