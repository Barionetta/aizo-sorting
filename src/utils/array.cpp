/**
 * Plik źródłowy implementacji klasy Array
 *
 * Klasa Array jest generyczną tablicą dynamiczną.
 * Znajdują się w niej podstawowe funkcje umożliwiające dodawanie,
 * usuwanie, wyświetlanie i wyszukiwanie jej elementów.
 */
#include "array.h"
#include <iostream>
using namespace std;

// Konstruktor klasy Array
template <typename T>
Array<T>::Array(void)
{
    size = 0;                // Obecny rozmiar tablicy       [int]
    maxSize = 10;            // Maksymalna pojemność tablicy [int]
    data = new T[maxSize]; // Zawartość tablicy [T*]
    cout << "Poprawnie utworzono tablicę.\n";
}

/**
 * Funkcja wyświetlająca zawartość tablicy.
 */
template <typename T>
void Array<T>::show()
{
    cout << "Tablica składa się z : ";
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

/**
 * Funkcja znajdująca indeks elementu o zadanej wartości.
 *
 * @param value Klucz, który jest szukany [T]
 * @return  Indeks, na którym znajduje się klucz
 * (jeżeli nie znaleziono, to -1) [int]
 */
template <typename T>
int Array<T>::find(T value)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == value)
        {
            cout << "Element znajduje się na pozycji " << i << ".\n";
            return i;
        }
    }
    cout << "Nie znaleziono podanego elementu.\n";
    return -1;
}

/**
 * Funkcja dodająca nowy element do istniejącej tablicy
 * na wybranej pozycji.
 *
 * @param value Klucz, który jest wstawiany [int]
 * @param idx Indeks, na który ma być wstawiony klucz [int]
 */
template <typename T>
void Array<T>::push(int idx, T value)
{
    if (size == maxSize)
    {
        int *new_data = new T[maxSize + 5];

        for (int i = 0; i < size; i++)
        {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        maxSize += 5;
    }

    for (int i = size - 1; i >= idx; i--)
    {
        data[i + 1] = data[i];
    }

    data[idx] = value;
    size++;
    cout << "Poprawnie dodano element na " << idx << " pozycji tablicy.\n";
}

/**
 * Funkcja dodająca nowy element na koniec istniejącej tablicy
 *
 * @param value Klucz, który jest wstawiany [int]
 */
template <typename T>
void Array<T>::push_back(T value)
{
    if (size == maxSize)
    {
        T *new_data = new T[maxSize + 5];

        for (int i = 0; i < size; i++)
        {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        maxSize += 5;
    }
    data[size] = value;
    size++;
    cout << "Poprawnie dodano element na końcu tablicy.\n";
}

/**
 * Funkcja usuwająca element z istniejącej tablicy z wybranej pozycji.
 * @param idx Indeks, z którego ma być usunięty klucz [int]
 */
template <typename T>
void Array<T>::pop(int idx)
{
    if (size == 0)
    {
        cout << "Ale ta tablica jest pusta!\n";
    }
    else
    {
        for (int i = idx; i < size; i++)
        {
            data[i] = data[i + 1];
        }
        data[size - 1] = 0;
        size--;
        if (size == (maxSize - 5))
        {
            maxSize = size;
            T *new_data = new T[maxSize];

            for (int i = 0; i < size; i++)
            {
                new_data[i] = data[i];
            }

            delete[] data;
            data = new_data;
        }
        cout << "Poprawnie usunięto element z " << idx << " pozycji tablicy.\n";
    }
}

/**
 * Funkcja usuwająca element z końca istniejącej tablicy.
 */
template <typename T>
void Array<T>::pop_back()
{
    if (size == 0)
    {
        cout << "Ale ta tablica jest pusta!\n";
    }
    else
    {
        data[size - 1] = 0;
        size--;
        if (size == (maxSize - 5))
        {
            maxSize = size;
            T *new_data = new T[maxSize];

            for (int i = 0; i < size; i++)
            {
                new_data[i] = data[i];
            }

            delete[] data;
            data = new_data;
        }
        cout << "Poprawnie usunięto element z końca tablicy.\n";
    }
}

// Destruktor klasy Array
template <typename T>
Array<T>::~Array<T>()
{
    delete[] data;
    cout << "Poprawnie usunięto tablicę.\n";
}