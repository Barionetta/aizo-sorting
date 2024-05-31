/**
 * Plik źródłowy zawierający struktury i funkcje wykorzystywane do mierzenia czasu wykonywania algorytmów
 */

#include "test.h"

/**
 * Główna funkcja do testowania algorytmów
 */
void Tester::testing()
{
    unsigned int choice;
    do
    {
        std::cout << "Dla jakiego typu chcesz zrobić pomiary?\n";
        std::cout << "1 - Pomiary dla danych typu int\n";
        std::cout << "2 - Pomiary dla danych typu float\n";
        std::cin >> choice;
    } while (choice > 2 || choice < 1);
    
    if (choice == 1)        { test_for_type<int>(); }
    else if (choice == 2)   { test_for_type<float>(); }
    else { return; }
    
}

/**
 * Funkcja do pomiarów dla wybranego typu
 */
template <typename T>
void Tester::test_for_type()
{

    std::map<unsigned int, std::function<void(Array<T>&)>> algorithms_map;
    algorithms_map[1] = insertionsort<T>;
    algorithms_map[2] = heapsort<T>;
    algorithms_map[3] = shellsort<T>;
    algorithms_map[4] = shellsort_knuth<T>;
    algorithms_map[5] = std::bind(quicksort<T>, _1, 1);
    algorithms_map[6] = std::bind(quicksort<T>, _1, 2);
    algorithms_map[7] = std::bind(quicksort<T>, _1, 3);
    algorithms_map[8] = std::bind(quicksort<T>, _1, 4);

    for (auto const& [key, algorithm] : algorithms_map)
    {
        for (int i = 0; i < Tester::number_of_sizes; i++)
        {
            std::cout << "Pomiary dla rozmiaru " << Tester::table_sizes[i] << "\n";
            double times[5];

            /*      LOSOWO      */
            Array<T> array = Others::generate_random_array<T>(Tester::table_sizes[i], 0, 1000000);
            Array<T> temp_array = array;
            times[0] = measure_time(temp_array, algorithm);

            /*      1/3     */
            temp_array = array;
            std::partial_sort(temp_array.begin(), temp_array.begin() + Tester::table_sizes[i]/3, temp_array.end());
            times[1] = measure_time(temp_array, algorithm);

            /*      2/3     */
            temp_array = array;
            std::partial_sort(temp_array.begin(), temp_array.begin() + Tester::table_sizes[i]/3 * 2, temp_array.end());
            times[2] = measure_time(temp_array, algorithm);

            /*      ROSNĄCO     */
            temp_array = array;
            std::sort(temp_array.begin(), temp_array.end());
            times[3] = measure_time(temp_array, algorithm);

            /*      MALEJĄCO     */
            temp_array = array;
            std::sort(temp_array.begin(), temp_array.end(), Others::is_greater<T>);
            times[4] = measure_time(temp_array, algorithm);
            
            if constexpr(std::is_integral_v<T>)             { Others::save_experiment_to_file(true, key, Tester::table_sizes[i], times); }
            else if constexpr(std::is_floating_point_v<T>)  { Others::save_experiment_to_file(false, key, Tester::table_sizes[i], times); }
        }
    }
}

/**
 * Funkcja mierzenia pojedynczego pomiaru
 * 
 * @param array Tablica, na której ma być wykonywany algorytm                   [T]
 * @param sorting_function Funkcja, za pomocą której ma być sortowana tablica   [F]
 * @return calculated_time - Uśredniony czas wykonania algorytmu                [double]
*/
template <typename T, typename F>
double Tester::measure_time(T& array, F sorting_function)
{
    double calculated_time = 0;
    for (int t = 0; t < Tester::number_of_repeats; t++)
    {
        auto start = std::chrono::steady_clock::now();
        sorting_function(array);
        auto stop = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        calculated_time += duration.count();
    }
    return calculated_time /= Tester::number_of_repeats;
}

/*
*   Zdefiniowanie typów dla funkcji
*/
template double Tester::measure_time(Array<int>& array, std::function<void(Array<int>)> sorting_function);
template double Tester::measure_time(Array<float>& array, std::function<void(Array<float>)> sorting_function);