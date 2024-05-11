/**
 * Plik nagłówkowy pliku zawierającego funkcje do prezentacji programów
 */
#ifndef DEMO_MENU_H
#define DEMO_MENU_H
#include "utils/array.h"

// Funkcja wyświetlająca opcje prezentacji
void displayDemoOptions();
// Funkcja wyświetlająca opcje generowania tablicy
void displayGenerationOptions();
// Funkcja wyświetlająca opcje typu danych
void displayTypeOptions();
// Funkcja wyświetlająca opcje wyboru algorytmu
void displayAlgorithmsOptions();
// Funkcja wyświetlająca opcje wyboru odstępów ( Metoda Shella )
void displayDistanceOptions();
// Funkcja wyświetlająca opcje wyboru pivota ( Szybkie sortowanie )
void displayPivotOptions();
// Funkcja zapełniająca tablice
template <typename T> void initArray(Array<T>& array, short& genChoice);
// Główna funkcja do prezentacji algorytmów
void demo();

#endif