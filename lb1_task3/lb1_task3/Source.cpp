#include "Header.h"
#include <iostream>
#include <cmath>

// Реализация проверки строки
bool IsNumber(const std::string& str) {
    if (str.empty()) return false;
    for (char const& c : str) {
        if (!std::isdigit(c)) return false;
    }
    return true;
}

//FIX_ME: выносим логику из процедурного стиля в инкапсулированную функцию решения
//double countNumbersWithConsecutiveZeros(int K, int N)
double CalculateNumbersWithZeros(int K, int N) {
    // nz: числа, не заканчивающиеся на ноль
    // oz: числа, заканчивающиеся на один ноль
    // tz: числа, уже содержащие два нуля подряд (целевая группа)

    // Начальные значения для i = 1 (первый разряд)
    double nz = K - 1;
    double oz = 0;
    double tz = 0;

    for (int i = 2; i <= N; i++) {
        double prev_nz = nz;
        double prev_oz = oz;
        double prev_tz = tz;

        // Числа без нулей в конце: к любому валидному числу добавляем цифру 1..(K-1)
        nz = (K - 1) * (prev_nz + prev_oz);

        // Числа, получившие один ноль в конце: добавляем 0 к тем, что не заканчивались на 0
        oz = prev_nz;

        // Числа, где уже есть два нуля: либо к тем, где они были, добавляем любую цифру (K), 
        // либо к тем, где был один ноль в конце, добавляем второй ноль
        tz = prev_tz * K + prev_oz;
    }

    return tz;
}