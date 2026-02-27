#include <string>
#include <fstream>
#include <vector>

// Функция для проверки, является ли строка числом
bool IsNumber(const std::string& str);

// Функция для безопасного чтения числа из потока
bool SafeReadInt(std::ifstream& file, int& value, int lineNum);

// Проверка, что в текущей строке достаточно чисел
bool HasEnoughNumbersInLine(std::ifstream& file, int requiredCount, int lineNum);

// Функция для решения задачи о поиске артефактов с минимальным налогом
void SolveArtifactsProblem(int TargetWeight, std::vector<int>& Weights, std::vector<int>& Taxes);

