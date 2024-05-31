/**
 * Plik źródłowy implementacji klasy Array
 *
 * Klasa Array jest generyczną tablicą dynamiczną.
 * Znajdują się w niej podstawowe funkcje umożliwiające dodawanie,
 * usuwanie, wyświetlanie i wyszukiwanie jej elementów.
 */

#include "array.h"

/**
 * Domyślny konstruktor klasy Array
 */
template <typename T>
Array<T>::Array()
    : size_(0),
      max_size_(10),
      data_(std::make_unique<T[]>(max_size_))
{ }

/**
 * Konstruktor kopiujący klasy Array
 *
 * @param array Tablica, która jest kopiowana [Array<T>&]
 */
template <typename T>
Array<T>::Array(const Array<T>& array)
    : size_(array.size_),
      max_size_(array.max_size_),
      data_(std::make_unique<T[]>(array.max_size_))
{
    std::copy_n(array.data_.get(), array.size_, data_.get());
}

/**
 * Konstruktor przenoszenia klasy Array
 *
 * @param array Tablica, która jest przenoszona [Array<T>&&]
 */
template <typename T>
Array<T>::Array(Array<T>&& array)
    : size_(array.size_),
      max_size_(array.max_size_),
      data_(nullptr)
{
    *this = array;
}

/**
 * Operator dostępu
*/
template <typename T>
T& Array<T>::operator[] (int i)
{
    return data_.get()[i];
}

/**
 * Operator kopiowania
*/
template <typename T>
Array<T>& Array<T>::operator=(const Array& array)
{
    if (this == &array) { return *this; }

    data_ = std::make_unique<T[]>(array.max_size_);
    size_ = array.size_;
    std::copy_n(array.data_.get(), array.size_, data_.get());

    return *this;
}

/**
 * Operator przenoszenia
*/
template <typename T>
Array<T>& Array<T>::operator=(Array&& array)
{
    std::swap(data_, array.data_);
    std::swap(max_size_, array.max_size_);
    std::swap(size_, array.size_);
    return *this;
}


/**
 * Funkcja zwracająca długość tablicy
 * 
 * @return this->size_ : Rozmiar tablicy [int]
*/
template <typename T>
int Array<T>::get_size() const
{
    return this->size_;
}

/**
 * Funkcja wyświetlająca zawartość tablicy.
 */
template <typename T>
void Array<T>::print() const
{
    std::cout << "Tablica składa się z : ";
    for (int i = 0; i < size_; i++)
    {
        std::cout << data_[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * Funkcja dodająca nowy element na koniec istniejącej tablicy
 *
 * @param value Klucz, który jest wstawiany [T]
 */
template <typename T>
void Array<T>::push_back(const T& value)
{
    if (size_ == max_size_)
    {
        std::unique_ptr<T[]> new_data_ = std::make_unique<T[]>(this->max_size_ + 5);
        std::copy_n(this->data_.get(), this->size_, new_data_.get());
        std::swap(data_, new_data_);
        max_size_ += 5;
    }
    data_[size_] = value;
    size_++;
}

/*
* Funkcja zwracająca początek tablicy
*/
template <typename T>
T* Array<T>::begin()
{
    return data_.get();
}

/*
* Funkcja zwracająca koniec tablicy
*/
template <typename T>
T* Array<T>::end()
{
    return &data_.get()[size_];
}

/*
*   Zdefiniowanie typów dla tablicy
*/
template class Array<int>;
template class Array<float>;