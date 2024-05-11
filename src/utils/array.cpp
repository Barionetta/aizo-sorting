/**
 * Plik źródłowy implementacji klasy Array
 *
 * Klasa Array jest generyczną tablicą dynamiczną.
 * Znajdują się w niej podstawowe funkcje umożliwiające dodawanie,
 * usuwanie, wyświetlanie i wyszukiwanie jej elementów.
 */
#include "array.h"
#include <fstream>
#include <iostream>
#include <random>
using namespace std;

// Konstruktor klasy Array
template <typename T>
Array<T>::Array()
{
    size = 0;                // Obecny rozmiar tablicy       [int]
    maxSize = 10;            // Maksymalna pojemność tablicy [int]
    data = new T[maxSize]; // Zawartość tablicy [T*]
    cout << "Poprawnie utworzono tablicę.\n";
}

/**
 * Funkcja zwracająca długość tablicy
 * 
 * @return this->size : Rozmiar tablicy [int]
*/
template <typename T>
int Array<T>::getLength()
{
    return this->size;
}

/**
 * Funkcja wyświetlająca zawartość tablicy.
 */
template <typename T>
void Array<T>::print()
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
 * @param value Klucz, który jest wstawiany [T]
 * @param idx Indeks, na który ma być wstawiony klucz [int]
 */
template <typename T>
void Array<T>::push(int idx, T value)
{
    if (idx >= size)
    {
        cout << "Indeks wyszedł poza zakres tablicy.\n";
        return;
    }
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
 * @param value Klucz, który jest wstawiany [T]
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
    if (idx >= size)
    {
        cout << "Indeks wyszedł poza zakres tablicy.\n";
        return;
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

/*
*   Funkcja sprawdzająca, czy tablica jest pusta
*/
template <typename T>
bool Array<T>::isEmpty()
{
    if (size > 0) {return false;}
    else {return true;}
}

/**
 * Funkcja zapełniająca tablice liczbami z pliku tekstowego.
 * Plik tekstowy musi znajdować się w folderze data w tym samym folderze,
 * co główny plik programu!
 *
 * @param filepath Nazwa pliku, z którego wczytywana jest tablica [string]
 */
template <typename T>
void Array<T>::readFromFile(string& filepath)
{
    string path = "../data/" + filepath;
    fstream f;
    T input;
    int i = 0;
    f.open(path);
    if (f.is_open())
    {
        f >> input;
        cout << "Rozmiar tablicy: " << input << endl;
        while (f >> input)
        {
            this->push_back(input);
            i++;
        }
        f.close();
    }
    else
    {
        cout << "Nie udało się otworzyć pliku ze ścieżki " << path << " \n";
    }
    cout << "Poprawnie wczytano strukturę ze ścieżki " << path << " \n";
}

/**
 * Funkcja zapełniająca kopiec liczbami z pliku tekstowego.
 * Do generowania liczb użyto funkcji pomocniczej generate_random_number()
 * z pliku simulation/generator.h
 *
 * @param size Rozmiar struktury [int]
 */
template <typename T>
void Array<T>::generate(int size)
{
    random_device rd;
    mt19937 gen(rd());
    if constexpr(is_integral_v<T>)
    {
        uniform_int_distribution<> distr(0 ,1000);
        for (int i = 0; i < size; i++)
        {
            this->push_back((int)distr(gen));
        }
    }
    else if constexpr(is_floating_point_v<T>)
    {
        uniform_real_distribution<> distr(0 ,1000);
        for (int i = 0; i < size; i++)
        {
            this->push_back((float)distr(gen));
        }
    }
    cout << "Poprawnie wygenerowano tablice\n";
}


/**
 * Operator dostępu
*/
template <typename T>
T& Array<T>::operator[] (int i)
{
    return *(this->data + i);
}

/*
*   Destruktor klasy Array
*/
template <typename T>
Array<T>::~Array()
{
    delete[] data;
}

/*
*   Zdefiniowanie typów dla tablicy
*/
template class Array<int>;
template class Array<float>;