// logic.h — интерфейс модуля логики (без ввода/вывода)
#ifndef LOGIC_H
#define LOGIC_H

#include <vector>

// Логическая функция: true, если в записи числа ровно одна цифра 5.
// Знак числа не учитывается (для -5 вернёт true).
bool hasExactlyOneDigitFive(int number);

// Произведение элементов массива, содержащих ровно одну цифру 5.
// found = true, если найден хотя бы один подходящий элемент.
long long productWithOneFive(const std::vector<int>& a, bool& found);

#endif // LOGIC_H