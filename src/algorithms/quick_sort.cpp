/**
 * Plik źródłowy zawierający implementację algorytmu sortowania szybkiego
 */
#include "quick_sort.h"
#include "utils/array.h"
#include <algorithm>
#include <iostream>
#include <random>
using namespace std;

/**
 * Funkcja pomocnicza do generowania losowej liczby całkowitej
 * 
 * @param down Dolna granica zakresu [int]
 * @param up Górna granica zakresu [int]
*/
int generateRandomNumber(int down, int up)
{
    random_device seed;
    mt19937 gen{seed()};
    uniform_int_distribution<> dist(down, up);
    return dist(gen);
}

/**
 * Funkcja do sortowania szybkiego
 * 
 * @param array Tablica, którą należy posortować [Array<T>]
 * @param left Indeks skrajnie lewego elementu [int]
 * @param right Indeks skrajnie prawego elementu [int]
*/
template <typename T>
int partition(Array<T>& array, int left, int right, int& pivotType)
{
    T pivot;
    if (pivotType == 1) { pivot = array[left]; }
    else if (pivotType == 2) { pivot = array[right]; }
    else if (pivotType == 3) { pivot = array[(left + right) / 2]; }
    else if (pivotType == 4) { pivot = array[generateRandomNumber(left,right)]; }
    int j = left;
    
    //swap(pivot, array[right]);
    for (int i = left; i < right; i++)
    {
        if (array[i] < array[right])
        {
            swap(array[i], array[j]);
            j++;
        }
    }
    swap(array[right], array[j]);
    return j;
}

/**
 * Funkcja do sortowania szybkiego
 * 
 * @param array Tablica, którą należy posortować [Array<T>]
 * @param left Indeks skrajnie lewego elementu [int]
 * @param right Indeks skrajnie prawego elementu [int]
 * @param pivotType Typ pivota [int]
*/
template <typename T>
void recQuicksort(Array<T>& array, int left, int right, int& pivotType)
{
    if (left < right)
    {
        int pivot = partition(array, left, right, pivotType);
        recQuicksort(array, left, pivot - 1, pivotType);
        recQuicksort(array, pivot + 1, right, pivotType);
    }
}

/**
 * Funkcja do sortowania szybkiego
 * 
 * @param array Tablica, którą należy posortować [Array<T>]
 * @param pivotType Typ pivota [int]
*/
template <typename T>
void quicksort(Array<T>& array, int pivotType)
{
    int n = array.getLength();
    recQuicksort(array, 0, n - 1, pivotType);
}

/*
*   Zdefiniowanie typów dla funkcji
*/
template int partition(Array<int>& array, int left, int right, int& pivotType);
template int partition(Array<float>& array, int left, int right, int& pivotType);
template void recQuicksort(Array<int>& array, int left, int right, int& pivotType);
template void recQuicksort(Array<float>& array, int left, int right, int& pivotType);
template void quicksort(Array<int>& array, int pivotType);
template void quicksort(Array<float>& array, int pivotType);