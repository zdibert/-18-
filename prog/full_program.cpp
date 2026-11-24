// =====================================================================
// ЛАБОРАТОРНАЯ РАБОТА №18. Вайб-кодинг
// Задача: Дан массив целых чисел. Найти произведение элементов,
//         в записи которых содержится ровно одна цифра 5.
//         Оформить логическую функцию проверки наличия цифры в числе.
//         Модульная структура: модуль логики + модуль ввода/вывода + main.
// =====================================================================

#include <iostream>
#include <vector>
#include <limits>
#include <clocale>

// =====================================================================
// МОДУЛЬ 1. ЛОГИКА (logic)
// Не содержит ввода/вывода. Только вычисления.
// =====================================================================

// Логическая функция: true, если в записи числа ровно одна цифра 5.
// Знак числа игнорируется. Корректно обрабатывает INT_MIN и 0.
bool hasExactlyOneDigitFive(int number)
{
    long long n = number;
    if (n < 0)
        n = -n;

    int count = 0;
    do {
        if (n % 10 == 5)
            ++count;
        if (count > 1)          // ранний выход
            return false;
        n /= 10;
    } while (n != 0);

    return count == 1;
}

// Произведение элементов, содержащих ровно одну цифру 5.
// found = true, если найден хотя бы один подходящий элемент.
long long productWithOneFive(const std::vector<int>& a, bool& found)
{
    long long product = 1;
    found = false;

    for (int x : a) {
        if (hasExactlyOneDigitFive(x)) {
            product *= x;
            found = true;
        }
    }
    return product;
}

// =====================================================================
// МОДУЛЬ 2. ВВОД/ВЫВОД (io)
// Отвечает только за взаимодействие с пользователем.
// =====================================================================

// Защищённый ввод одного целого числа с повторным запросом при ошибке.
static int readInt(const char* message)
{
    int value;
    while (true) {
        std::cout << message;
        if (std::cin >> value)
            return value;
        std::cout << "Ошибка: введите целое число!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Ввод массива: сначала размер (n > 0), затем n элементов.
std::vector<int> readArray()
{
    int n;
    do {
        n = readInt("Введите количество элементов массива (n > 0): ");
        if (n <= 0)
            std::cout << "Ошибка: размер массива должен быть положительным!\n";
    } while (n <= 0);

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "a[" << i << "] = ";
        a[i] = readInt("");
    }
    return a;
}

// Вывод массива в одну строку.
void printArray(const std::vector<int>& a)
{
    std::cout << "\nИсходный массив: ";
    for (int x : a)
        std::cout << x << ' ';
    std::cout << '\n';
}

// Вывод результата: произведение или сообщение об отсутствии элементов.
void printResult(long long product, bool found)
{
    if (!found)
        std::cout << "Элементов с ровно одной цифрой 5 нет: "
        "произведение не определено.\n";
    else
        std::cout << "Произведение элементов с ровно одной цифрой 5 = "
        << product << '\n';
}

// =====================================================================
// МОДУЛЬ 3. ОСНОВНАЯ ФУНКЦИЯ (main)
// Только оркестрация модулей — никаких вычислений и ввода здесь нет.
// =====================================================================

int main()
{
    std::setlocale(LC_ALL, "Russian");

    std::vector<int> a = readArray();           // модуль ввода/вывода
    printArray(a);

    bool found = false;
    long long product = productWithOneFive(a, found);   // модуль логики

    printResult(product, found);                // модуль ввода/вывода
    return 0;
}