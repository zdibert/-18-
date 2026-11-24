// main.cpp — основной модуль программы. ЛР №18
// Задача: произведение элементов массива, в записи которых
//         содержится ровно одна цифра 5.
#include "io.h"
#include "logic.h"
#include <clocale>

int main()
{
    std::setlocale(LC_ALL, "Russian");

    std::vector<int> a = readArray();              // модуль ввода/вывода
    printArray(a);

    bool found = false;
    long long product = productWithOneFive(a, found);   // модуль логики

    printResult(product, found);                   // модуль ввода/вывода
    return 0;
}