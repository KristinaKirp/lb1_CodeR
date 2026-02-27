#include "Header.h"
#include <stdexcept>

bool SolveExpression(const std::string& expression) {
    int pos = 0;
    bool result = EvaluateRecursive(expression, pos);

    // Проверка на наличие лишних символов в конце строки
    if (pos < expression.length()) {
        throw std::invalid_argument("Лишние символы в конце выражения");
    }
    return result;
}

bool EvaluateRecursive(const std::string& expression, int& pos) {
    if (pos >= expression.length()) {
        throw std::invalid_argument("Неожиданный конец выражения");
    }

    // Обработка константы True
    if (expression[pos] == 'T') {
        pos++;
        return true;
    }

    // Обработка константы False
    if (expression[pos] == 'F') {
        pos++;
        return false;
    }

    //FIX_ME: исправляем использование substr (скрытый цикл) и заменяем на посимвольное сравнение
    //else if (expression.substr(pos, 3) == "And")
    if (pos + 3 < expression.length() &&
        expression[pos] == 'A' && expression[pos + 1] == 'n' && expression[pos + 2] == 'd') {

        pos += 3; // Пропускаем "And"
        if (expression[pos] != '(') throw std::invalid_argument("Ожидается '('");
        pos++;

        bool left = EvaluateRecursive(expression, pos);

        if (expression[pos] != ',') throw std::invalid_argument("Ожидается ','");
        pos++;

        bool right = EvaluateRecursive(expression, pos);

        if (expression[pos] != ')') throw std::invalid_argument("Ожидается ')'");
        pos++;

        return left && right;
    }

    //FIX_ME: исправляем использование substr и реализуем проверку Or без циклов
    //else if (expression.substr(pos, 2) == "Or")
    if (pos + 2 < expression.length() &&
        expression[pos] == 'O' && expression[pos + 1] == 'r') {

        pos += 2; // Пропускаем "Or"
        if (expression[pos] != '(') throw std::invalid_argument("Ожидается '('");
        pos++;

        bool left = EvaluateRecursive(expression, pos);

        if (expression[pos] != ',') throw std::invalid_argument("Ожидается ','");
        pos++;

        bool right = EvaluateRecursive(expression, pos);

        if (expression[pos] != ')') throw std::invalid_argument("Ожидается ')'");
        pos++;

        return left || right;
    }

    throw std::invalid_argument("Недопустимый формат выражения");
}