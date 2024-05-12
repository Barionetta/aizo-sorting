/**
 * Plik nagłówkowy pliku zawierającego implementację klasy Array
 *
 * Klasa Array jest generyczną tablicą dynamiczną.
 * Znajdują się w niej podstawowe funkcje umożliwiające dodawanie,
 * usuwanie, wyświetlanie i wyszukiwanie jej elementów.
 */
#ifndef ARRAY_H
#define ARRAY_H
#include <string>

template <typename T>
class Array
{

private:
    T *data;   // Zawartość tablicy [T*]
    int maxSize; // Maksymalna pojemność tablicy [int]
    int size;    // Obecny rozmiar tablicy [int]

public:
    // Konstruktor klasy Array
    Array();
    // Funkcja zwracająca długość tablicy
    int getLength();
    // Funkcja wyświetlająca zawartość tablicy
    void print();
    // Funkcja dodająca nowy element na koniec istniejącej tablicy
    void push_back(T value);
    // Funkcja sprawdzająca, czy tablica jest pusta
    bool isEmpty();
    // Funkcja zapełniająca tablicę liczbami z pliku tekstowego
    void readFromFile(std::string& filepath);
    // Funkcja zapełniająca tablicę liczbami wygenerowanymi losowo
    void generate(int size);
    // Operator dostępu
    T& operator[] (int i);
    // Funkcja do czyszczenia tablicy
    void clear();
    // Destruktor klasy Array
    ~Array();
};

#endif