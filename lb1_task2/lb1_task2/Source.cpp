#include "Header.h"
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

// Реализация проверки строки
bool IsNumber(const std::string& str)
{
    if (str.empty())
    {
        return false;
    }

    for (char const& c : str) 
    {
        if (!std::isdigit(c)) return false;
    }
    return true;
}

// Реализация безопасного чтения
bool SafeReadInt(std::ifstream& file, int& value, int lineNum) 
{
    std::string input;
    if (!(file >> input))
    {
        return false;
    }

    if (!IsNumber(input)) 
    {
        std::cout << "Ошибка на строке " << lineNum << ": '" << input << "' не число." << std::endl;
        return false;
    }
    value = std::stoi(input);
    return true;
}

void SolveTurtlePath(int boardSize, const std::vector<std::vector<int>>& board) 
{
    int N = boardSize;
    const int infinity = std::numeric_limits<int>::max();

    //FIX_ME: меняем название переменной и делаем размер динамическим
    //vector<vector<int>> dp(N, vector<int>(N, numeric_limits<int>::max()));
    std::vector<std::vector<int>> minSumDP(N, std::vector<int>(N, infinity));

    //FIX_ME: инициализируем стартовую точку (левый нижний угол) через новую переменную
    //dp[N - 1][0] = b[N - 1][0];
    minSumDP[N - 1][0] = board[N - 1][0];

    // Алгоритм поиска минимальной суммы
    for (int i = N - 1; i >= 0; i--) 
    {
        for (int j = 0; j < N; j++) 
        {
            if (i < N - 1) 
            {
                if (minSumDP[i + 1][j] != infinity) 
                {
                    minSumDP[i][j] = std::min(minSumDP[i][j], minSumDP[i + 1][j] + board[i][j]);
                }
            }
            if (j > 0) 
            {
                if (minSumDP[i][j - 1] != infinity)
                {
                    minSumDP[i][j] = std::min(minSumDP[i][j], minSumDP[i][j - 1] + board[i][j]);
                }
            }
        }
    }

    //FIX_ME: организуем вывод в файл внутри инкапсулированной функции
    //file2 << dp[0][N - 1];
    std::ofstream outputFile("b.txt");
    if (outputFile.is_open()) 
    {
        outputFile << minSumDP[0][N - 1];
        outputFile.close();
    }
}