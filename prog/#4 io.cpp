// io.cpp Ч реализаци€ ввода/вывода
#include "io.h"
#include <iostream>
#include <limits>

static int readInt(const char* message)
{
    int value;
    while (true) {
        std::cout << message;
        if (std::cin >> value)
            return value;
        std::cout << "ќшибка: введите целое число!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::vector<int> readArray()
{
    int n;
    do {
        n = readInt("¬ведите количество элементов массива (n > 0): ");
        if (n <= 0)
            std::cout << "ќшибка: размер массива должен быть положительным!\n";
    } while (n <= 0);

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "a[" << i << "] = ";
        a[i] = readInt("");
    }
    return a;
}

void printArray(const std::vector<int>& a)
{
    std::cout << "\n»сходный массив: ";
    for (int x : a)
        std::cout << x << ' ';
    std::cout << '\n';
}

void printResult(long long product, bool found)
{
    if (!found)
        std::cout << "Ёлементов с ровно одной цифрой 5 нет: "
        "произведение не определено.\n";
    else
        std::cout << "ѕроизведение элементов с ровно одной цифрой 5 = "
        << product << '\n';
}