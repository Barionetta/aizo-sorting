/**
 * Plik nagłówkowy pliku zawierającego struktury i funkcje wykorzystywane do mierzenia czasu wykonywania algorytmów
 */

#ifndef TEST_H
#define TEST_H
#include "algorithms/heap_sort.h"
#include "algorithms/insertion_sort.h"
#include "algorithms/quick_sort.h"
#include "algorithms/shell_sort.h"
#include "utils/array.h"
#include "utils/others.h"

#include <algorithm>
#include <chrono>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <string>

using namespace std::placeholders;

namespace Tester
{
    // Główna funkcja do testowania algorytmów
    void testing();
    // Funkcja do pomiarów dla wybranego typu
    template <typename T>
    void test_for_type();
    // Funkcja mierzenia pojedynczego pomiaru
    template <typename T, typename F>
    double measure_time(T& array, F sorting_function);

    // Stałe
    constexpr int number_of_sizes = 7;
    constexpr int number_of_repeats = 100;
    constexpr int table_sizes[7] = {10000, 20000, 50000, 100000, 120000, 150000, 170000};
}

#endif