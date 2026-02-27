#include <string>
#include <fstream>
#include <vector>

// Функция для проверки, является ли строка числом
bool IsNumber(const std::string& str);

// Функция для безопасного чтения числа из потока
bool SafeReadInt(std::ifstream& file, int& value, int lineNum);

// Функция для решения задачи о Черепашке (поиск пути с минимальной суммой)
void SolveTurtlePath(int boardSize, const std::vector<std::vector<int>>& board);
