//Археолог нашел N артефактов.Известны веса(сi) и налоговое бремя(di) находок.
//Нужно выбрать такое подмножество находок, чтобы их суммарный вес превысил Z кг, а их общее 
//налоговое бремя оказалось минимальным.Известно, что решение единственно.Укажите
//порядковые номера вещей, которые нужно взять.Исходный данные находятся в текстовом файле, 
//в первой строке указаны N и Z, а во второй строке значения весов(в кг), в третьей - величина
//налога по каждой находке.Вывести так же суммарный вес и общую ценность результата.

// FIX_ME: добавляем недастающие и убираем излишние библиотеки
#include <iostream>
#include <Windows.h>
#include "Header.h"

// FIX_ME: меняем название переменных делаем их понятными и соответсвующие с код стайл
int main()
{
    // FIX_ME: не используем using namespace std в соответствии с код стайлом
    // using namespace std;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ifstream input("input.txt");
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        std::cout << "Ошибка: Не удалось открыть файл input.txt" << std::endl;
        return 1;
    }

    // int N, Z;
    int artifactCount = 0;
    int targetWeight = 0;

    if (!SafeReadInt(inputFile, artifactCount, 1) || !SafeReadInt(inputFile, targetWeight, 1))
    {
        return 1;
    }

    // FIX_ME: изменяем проверку, чтобы 0 таакже обробатывался
    // if (N<0 || Z<0)
    if (artifactCount <= 0 || targetWeight < 0)
    {
        std::cout << "Ошибка: Параметры должны быть положительными. N > 0, Z >= 0." << std::endl;
        return 1;
    }

    // vector<int> weights(N);
    std::vector<int> weights(artifactCount);
    for (int i = 0; i < artifactCount; ++i)
    {
        if (!SafeReadInt(inputFile, weights[i], 2)) return 1;
    }

    // vector<int> tax(N);
    std::vector<int> taxes(artifactCount);
    for (int i = 0; i < artifactCount; ++i)
    {
        if (!SafeReadInt(inputFile, taxes[i], 3)) return 1;
    }

    SolveArtifactsProblem(targetWeight, weights, taxes);

    return 0;
}
