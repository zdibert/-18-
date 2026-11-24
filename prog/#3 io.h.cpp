// io.h — интерфейс модуля ввода/вывода
#ifndef IO_H
#define IO_H

#include <vector>

// Ввод размера и элементов массива с клавиатуры (с проверкой корректности)
std::vector<int> readArray();

// Вывод исходного массива
void printArray(const std::vector<int>& a);

// Вывод результата работы программы
void printResult(long long product, bool found);

#endif // IO_H