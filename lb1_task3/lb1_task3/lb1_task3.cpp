// К-ичные числа. Среди чисел в системе счисления с основанием K (2≤K≤10) определить сколько
// имеется чисел из N(1 < N < 20, N + K < 26) разрядов таких, что в их записи содержится два
// и более подряд идущих нулей.Для того, чтобы избежать переполнения, ответ представьте в виде
// вещественного числа.

//FIX_ME: добавляем библиотеки и убирем и/или переносим
#include <iostream>
#include <string>
#include <Windows.h>
#include "Header.h"
//FIX_ME: меняем названия в соответствии с код стайлом
int main() {
    //FIX_ME: не используем using namespace std в соответствии с код стайлом
    //using namespace std;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string inputK, inputN;
    int K, N;

    //FIX_ME: переписываем ввод данных с использованием валидации строк
    /*cout << "Введите основание системы счисления K: ";
    cin >> K;
    cout << "Введите количество разрядов N: ";
    cin >> N;*/

    // Ввод и проверка K
    std::cout << "Введите основание системы счисления K (2-10): ";
    std::cin >> inputK;
    if (!IsNumber(inputK)) {
        std::cout << "Ошибка: Основание K должно быть числом." << std::endl;
        return 1;
    }
    K = std::stoi(inputK);
    if (K < 2 || K > 10) {
        std::cout << "Ошибка: K вне диапазона [2, 10]." << std::endl;
        return 1;
    }

    // Ввод и проверка N
    std::cout << "Введите количество разрядов N (2-20): ";
    std::cin >> inputN;
    if (!IsNumber(inputN)) {
        std::cout << "Ошибка: Количество разрядов N должно быть числом." << std::endl;
        return 1;
    }
    N = std::stoi(inputN);
    if (N <= 1 || N >= 20) {
        std::cout << "Ошибка: N вне диапазона (1, 20)." << std::endl;
        return 1;
    }

    // Проверка дополнительного условия из задачи
    if (N + K >= 26) {
        std::cout << "Ошибка: Нарушено условие N + K < 26." << std::endl;
        return 1;
    }

    //FIX_ME: вызываем  функцию с новым именем
    //double result = countNumbersWithConsecutiveZeros(K, N);
    double result = CalculateNumbersWithZeros(K, N);
     
    // Вывод результата в виде вещественного числа (по условию задачи)
    std::cout.precision(0);
    std::cout << std::fixed << "Количество чисел: " << result << std::endl;

    return 0;
}
