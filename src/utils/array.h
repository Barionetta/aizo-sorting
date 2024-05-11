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
    int getLenght();
    // Funkcja wyświetlająca zawartość tablicy
    void print();
    // Funkcja znajdująca indeks elementu o zadanej wartości
    int find(T value);
    // Funkcja dodająca nowy element do istniejącej tablicy na wybranej pozycji
    void push(int idx, T value);
    // Funkcja dodająca nowy element na koniec istniejącej tablicy
    void push_back(T value);
    // Funkcja usuwająca element z istniejącej tablicy z wybranej pozycji
    void pop(int idx);
    // Funkcja usuwająca element z końca istniejącej tablicy
    void pop_back();
    // Funkcja sprawdzająca, czy tablica jest pusta
    bool isEmpty();
    // Funkcja zapełniająca tablicę liczbami z pliku tekstowego
    void readFromFile(std::string& filepath);
    // Funkcja zapełniająca tablicę liczbami wygenerowanymi losowo
    void generate(int size);
    // Operator dostępu
    T& operator[] (int i);
    // Destruktor klasy Array
    ~Array();
};

#endif