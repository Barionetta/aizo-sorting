/**
 * Plik źródłowy zawierający funkcje do prezentacji programów
 */
#include "demo_menu.h"
#include <iostream>
using namespace std;


/**
 * Funkcja wyświetlająca opcje prezentacji
 */
void displayDemoOptions()
{
    cout << "Co chcesz zrobić?\n";
    cout << "1 - Wygeneruj nową tablicę\n";
    cout << "2 - Wyświetl bieżącą tablicę\n";
    cout << "3 - Zaprezentuj algorytm na bieżącej tablicy\n";
    cout << "0 - Zakończ program\n";
}

/**
 * Funkcja wyświetlająca opcje generowania tablicy
 */
void displayGenerationOptions()
{
    cout << "Jak chcesz stworzyć tablicę?\n";
    cout << "1 - Wczytaj z pliku\n";
    cout << "2 - Wygeneruj losowo\n";
    cout << "0 - Cofnij\n";
}

/**
 * Funkcja wyświetlająca opcje typu danych
 */
void displayTypeOptions()
{
    cout << "Jakiego typu dane mają być w tablicy?\n";
    cout << "1 - Liczby całkowite [int]\n";
    cout << "2 - Liczby zmiennoprzecinkowe pojedynczej precyzji [float]\n";
    cout << "0 - Cofnij\n";
}

/**
 * Funkcja wyświetlająca opcje wyboru algorytmu
 */
void displayAlgorithmsOptions()
{
    cout << "Który algorytm chcesz pokazać?\n";
    cout << "1 - Algorytm sortowania przez wstawianie [Insertion Sort]\n";
    cout << "2 - Algorytm sortowania przez kopcowanie [Heap Sort]\n";
    cout << "3 - Algorytm sortowania metodą Shella [Shell Sort]\n";
    cout << "4 - Algorytm sortowania szybkiego [Quick Sort]\n";
    cout << "0 - Cofnij\n";
}

/**
 * Funkcja wyświetlająca opcje wyboru odstępów ( Metoda Shella )
 */
void displayDistanceOptions()
{
    cout << "Jakie odstępy mają być między zbiorami?\n";
    cout << "1 - Wzór 1\n";
    cout << "2 - Wzór 2\n";
    cout << "0 - Cofnij\n";
}

/**
 * Funkcja wyświetlająca opcje wyboru pivota ( Szybkie sortowanie )
 */
void displayPivotOptions()
{
    cout << "Który element w tablicy ma być pivotem?\n";
    cout << "1 - Pierwszy (skrajnie lewy)\n";
    cout << "2 - Ostatni (skrajnie prawy)\n";
    cout << "3 - Środkowy\n";
    cout << "4 - Losowy\n";
    cout << "0 - Cofnij\n";
}

/**
 * Główna funkcja do prezentacji algorytmów
 */
void demo()
{
    cout << "To jest tryb prezentacji.\n";
    short action = 1;
    bool array = false;
    while(action)
    {
        displayDemoOptions();
        cin >> action;
        if (action < 0 || action > 3)
        {
            cout << "Wprowadź poprawną opcję.\n";
            action = 1;
            continue;
        }
        switch (action)
        {
            case 1:
            {
                short fromFile = 1;
                short dataType = 1;
                displayGenerationOptions();
                cin >> fromFile;
                if (fromFile < 0 || fromFile > 2)
                {
                    cout << "Wprowadź poprawną opcję.\n";
                    break;
                }
                if (!fromFile) { break; }
                displayTypeOptions();
                cin >> dataType;
                if (dataType < 0 || dataType > 2)
                {
                    cout << "Wprowadź poprawną opcję.\n";
                    break;
                }
                if (!dataType) { break; }
                cout << "Tablica została wygenerowana.\n";
                array = true;
                break;
            }
            case 2:
            {
                if (array)
                {
                    cout << "Wyświetlam sobie tablice.\n";
                }
                else
                {
                    cout << "Nie wygenerowano jeszcze tablicy!\n";
                }
                break;
            }
            case 3:
            {
                if (array)
                {
                    cout << "Wyświetlam sobie tablice.\n";
                    short algorithm = 1;
                    while (algorithm)
                    {
                        displayAlgorithmsOptions();
                        cin >> algorithm;
                        if (algorithm < 0 || algorithm > 4)
                        {
                            cout << "Wprowadź poprawną opcję.\n";
                            algorithm = 1;
                            continue;
                        }
                        switch (algorithm)
                        {
                            case 1:
                            {
                                cout << "Przeprowadzam algorytm insertion sort.\n";
                                break;
                            }
                            case 2:
                            {
                                cout << "Przeprowadzam algorytm heap sort.\n";
                                break;
                            }
                            case 3:
                            {
                                cout << "Przeprowadzam algorytm shell sort.\n";
                                short distanceType = 1;
                                while (distanceType)
                                {
                                    displayDistanceOptions();
                                    cin >> distanceType;
                                    if (distanceType < 0 || distanceType > 2)
                                    {
                                        cout << "Wprowadź poprawną opcję.\n";
                                        distanceType = 1;
                                        continue;
                                    }
                                    switch (distanceType)
                                    {
                                        case 1:
                                        {
                                            cout << "Przeprowadzam algorytm Shella z wzorem 1\n";
                                            break;
                                        }
                                        case 2:
                                        {
                                            cout << "Przeprowadzam algorytm Shella z wzorem 2\n";
                                            break;
                                        }
                                        default:
                                        {
                                            break;
                                        }
                                    }
                                }
                                break;
                            }
                            case 4:
                            {
                                cout << "Przeprowadzam algorytm quick sort.\n";
                                short pivotType = 1;
                                while (pivotType)
                                {
                                    displayPivotOptions();
                                    cin >> pivotType;
                                    if (pivotType < 0 || pivotType > 4)
                                    {
                                        cout << "Wprowadź poprawną opcję.\n";
                                        pivotType = 1;
                                        continue;
                                    }
                                    switch (pivotType)
                                    {
                                        case 1:
                                        {
                                            cout << "Quick sort z pivot po lewej.\n";
                                            break;
                                        }
                                        case 2:
                                        {
                                            cout << "Quick sort z pivot po prawej.\n";
                                            break;
                                        }
                                        case 3:
                                        {
                                            cout << "Quick sort z pivot pośrodku.\n";
                                            break;
                                        }
                                        case 4:
                                        {
                                            cout << "Quick sort z pivot losowym.\n";
                                            break;
                                        }
                                        default:
                                        {
                                            break;
                                        }
                                    }
                                }
                                break;
                            }
                            default:
                            {
                                break;
                            }
                        }
                    }
                }
                else
                {
                    cout << "Nie wygenerowano jeszcze tablicy!\n";
                }
                break;
            }
            default:
            {
                break;
            }
        }
    }
    return;
}