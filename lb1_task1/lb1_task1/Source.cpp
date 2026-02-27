#include "Header.h"
#include <iostream>
#include <numeric>
#include <limits>
#include <algorithm>

bool IsNumber(const std::string& str) {
    if (str.empty()) return false;
    for (char const& c : str) {
        if (!std::isdigit(c)) return false;
    }
    return true;
}

bool SafeReadInt(std::ifstream& file, int& value, int lineNum) {
    std::string input;
    if (!(file >> input)) {
        std::cout << "Ошибка на строке " << lineNum << ": Не удалось считать данные." << std::endl;
        return false;
    }
    if (!IsNumber(input)) {
        std::cout << "Ошибка на строке " << lineNum << ": '" << input << "' не является числом." << std::endl;
        return false;
    }
    value = std::stoi(input);
    return true;
}

bool HasEnoughNumbersInLine(std::ifstream& file, int requiredCount, int lineNum) {
    return true;
}

void SolveArtifactsProblem(int targetWeight, std::vector<int>& weights, std::vector<int>& taxes) {
    int artifactCount = static_cast<int>(weights.size());
    // FIX_ME: даем максимально возможное значение для типа int
    const int infinity = std::numeric_limits<int>::max();

    // FIX_ME: рассчитываем максимальный возможный вес для корректного размера DP
    int maxPossibleWeight = std::accumulate(weights.begin(), weights.end(), 0);

    if (maxPossibleWeight <= targetWeight)
    {
        std::cout << "Ошибка: Сумма всех весов не превышает лимит Z." << std::endl;
        return;
    }

    // vector<int> dp(Z + 110, INF);
    std::vector<int> minTaxDP(maxPossibleWeight + 1, infinity);
    minTaxDP[0] = 0;

    // FIX_ME: изменяем для динамического вычисления и избегания ошибок
    // vector<vector<bool>> used(Z + 110, vector<bool>(N, false));
    std::vector<std::vector<bool>> usedArtifacts(maxPossibleWeight + 1, std::vector<bool>(artifactCount, false));

    for (int i = 0; i < artifactCount; ++i)
    {
        for (int j = maxPossibleWeight; j >= weights[i]; --j)
        {
            if (minTaxDP[j - weights[i]] != infinity)
            {
                int newTax = minTaxDP[j - weights[i]] + taxes[i];
                if (newTax < minTaxDP[j])
                {
                    minTaxDP[j] = newTax;
                    usedArtifacts[j] = usedArtifacts[j - weights[i]];
                    usedArtifacts[j][i] = true;
                }
            }
        }
    }

    int resultMinTax = infinity;
    int resultBestWeight = 0;
    int bestWeightIdx = -1;

    // Ищем минимальный налог среди весов строго больше Z
    for (int j = targetWeight + 1; j <= maxPossibleWeight; ++j)
    {
        if (minTaxDP[j] < resultMinTax)
        {
            resultMinTax = minTaxDP[j];
            resultBestWeight = j;
            bestWeightIdx = j;
        }
    }

    if (bestWeightIdx == -1)
    {
        std::cout << "Решение не найдено." << std::endl;
        return;
    }

    // Вывод результата
    std::cout << "Выбранные артефакты (номера): ";
    for (int i = 0; i < artifactCount; ++i)
    {
        if (usedArtifacts[bestWeightIdx][i])
        {
            std::cout << i + 1 << " ";
        }
    }

    std::cout << "Суммарный вес артефактов: " << resultBestWeight << std::endl;
    std::cout << "Общая ценность (налог): " << resultMinTax << std::endl;
}