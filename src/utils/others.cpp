/**
 * Plik źródłowy zawierający funkcje pomocnicze
 */

#include "others.h"

// Stałe
std::random_device rd;
std::mt19937 gen(rd());

/**
 * Funkcja do zamiany dwóch liczb miejscami
 * 
 * @param num_1 Pierwsza liczba do zamiany [T]
 * @param num_2 Druga liczba do zamiany [T]
*/
template <typename T>
void Others::swap(T& num_1, T& num_2)
{
    T temp = num_1;
    num_1 = num_2;
    num_2 = temp;
}

/**
 * Funkcja do generacji liczby losowej z jakiegoś zakresu
 * 
 * @param down Dolna granica zakresu [T]
 * @param up Górna granica zakresu [T]
*/
template <typename T>
T Others::generate_random_number(T down, T up)
{
    if constexpr(std::is_integral_v<T>)
    {
        std::uniform_int_distribution<> distr(down ,up);
        return (int)distr(gen);
    }
    else if constexpr(std::is_floating_point_v<T>)
    {
        std::uniform_real_distribution<> distr(down ,up);
        return (float)distr(gen);
    }
}

/**
 * Funkcja tworząca tablice z liczb zapisanych w pliku tekstowego.
 * Plik tekstowy musi znajdować się w folderze data w tym samym folderze,
 * co główny plik programu!
 *
 * @param filepath Nazwa pliku, z którego wczytywana jest tablica [string]
 */
template <typename T>
Array<T> Others::read_array_from_file(std::string& filepath)
{
    Array<T> new_array;
    std::string path = "../data/" + filepath;
    std::fstream f;
    T input;
    int i = 0;
    f.open(path);
    if (f.is_open())
    {
        f >> input;
        std::cout << "Rozmiar tablicy: " << input << std::endl;
        while (f >> input)
        {
            new_array.push_back(input);
            i++;
        }
        f.close();
        std::cout << "Poprawnie wczytano tablicę ze ścieżki " << path << " \n";
    }
    else
    {
        std::cout << "Nie udało się otworzyć pliku ze ścieżki " << path << " \n";
    }
    return new_array;
}

/**
 * Funkcja generująca tablicę liczb losowych, która ma rozmiar size.
 * Liczby generowane są z zakresu od down do up, gdzie down < up .
 *
 * @param size Rozmiar struktury [int]
 */
template <typename T>
Array<T> Others::generate_random_array(int size, T down, T up)
{
    Array<T> new_array;
    for (int i = 0; i < size; i++)
    {
        new_array.push_back(generate_random_number<T>(down, up));
    }
    std::cout << "Poprawnie wygenerowano tablice\n";
    return new_array;
}

/*
*   Zdefiniowanie typów dla funkcji
*/
template void Others::swap(int& num_1, int& num_2);
template void Others::swap(float& num_1, float& num_2);
template int Others::generate_random_number(int down, int up);
template float Others::generate_random_number(float down, float up);
template Array<int> Others::read_array_from_file(std::string& filepath);
template Array<float> Others::read_array_from_file(std::string& filepath);
template Array<int> Others::generate_random_array(int size, int down, int up);
template Array<float> Others::generate_random_array(int size, float down, float up);