#include <string>

// Основная функция для запуска вычисления
bool SolveExpression(const std::string& expression);

// Рекурсивная функция вычисления без использования циклов
bool EvaluateRecursive(const std::string& expression, int& pos);
