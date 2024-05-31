/**
 * Plik nagłówkowy pliku zawierającego funkcje pomocnicze
 */

#ifndef OTHERS_H
#define OTHERS_H
#include "array.h"

#include <fstream>
#include <iostream>
#include <random>
#include <string>

namespace Others
{
    // Funkcja do zamiany dwóch liczb miejscami
    template <typename T>
    void swap(T& num_1, T& num_2);
    // Funkcja do sprawdzenia, czy pierwsza liczba jest większa
    template <typename T>
    bool is_greater(T& num_1, T& num_2);
    // Funkcja do generacji liczby losowej z jakiegoś zakresu
    template <typename T>
    T generate_random_number(T down, T up);
    // Funkcja do wygenerowania tablicy liczb losowych
    template <typename T>
    Array<T> generate_random_array(int size, T down, T up);
    // Funkcja do wygenerowania tablicy z pliku tekstowego
    template <typename T>
    Array<T> read_array_from_file(std::string& filepath);
    // Funkcja do zapisania wyników pomiarów do pliku .csv
    void save_experiment_to_file(bool is_int, unsigned int& algorithm_code, int& size, double saved_times[]);
};

#endif