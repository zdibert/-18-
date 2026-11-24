// logic.cpp Ч реализаци€ логических функций
#include "logic.h"

bool hasExactlyOneDigitFive(int number)
{
    // ЅерЄм модуль в long long, чтобы корректно обработать INT_MIN
    long long n = number;
    if (n < 0)
        n = -n;

    int count = 0;
    do {                          // do-while корректно обрабатывает число 0
        if (n % 10 == 5)
            ++count;
        if (count > 1)            // ранний выход: больше одной п€тЄрки
            return false;
        n /= 10;
    } while (n != 0);

    return count == 1;
}

long long productWithOneFive(const std::vector<int>& a, bool& found)
{
    long long product = 1;        // long long Ч защита от переполнени€ int
    found = false;

    for (int x : a) {
        if (hasExactlyOneDigitFive(x)) {
            product *= x;
            found = true;
        }
    }
    return product;
}