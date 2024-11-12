#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__
#include <iostream>
#include <algorithm>    // std::swap
using namespace std;

template <typename T>
bool men(T a, T b)
{
   return a>b;
}

template <typename T>
bool may(T a, T b)
{
   return a<b;
}

template <typename T>
int partition(T arr[], int low, int high, bool (*pfc)(T, T)) {
    auto pivot = arr[low]; // Pivote como el primer elemento
    auto i = low + 1;
    auto j = high;

    while (true) {
        while (i <= j && !(*pfc)(arr[i], pivot))   i++;
        while (i <= j && (*pfc)(arr[j], pivot))    j--;
        // Se cruzaron los índices, salir del bucle
        if (i > j)  break; 
        std::swap(arr[i], arr[j]);  // Intercambiar elementos
        i++;    j--;
    }
    std::swap(arr[low], arr[j]);    // Colocar el pivote en su lugar
    return j; // Retornar la posición del pivote
}

template <typename T>
void QuickSort(T arr[], int low, int high, bool (*pfc)(T, T) = &may) {
    if (low < high) {
        int pi = partition(arr, low, high, pfc);
        QuickSort(arr, low, pi -1, pfc);
        QuickSort(arr, pi + 1, high, pfc);
    }
}

template <typename T>
void Print(ostream &os, T arr[], int size) {
    for (int i = 0; i < size; i++) {
        os << arr[i] << " ";
    }
    os << endl;
}

void SortDemo();

#endif  // __QUICK_SORT_H__