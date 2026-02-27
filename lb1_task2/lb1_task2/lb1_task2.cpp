//Черепашка.На квадратной доске расставлены целые неотрицательные числа, каждое из которых 
//не превосходит 100. Черепашка, находящаяся в левом нижнем углу, мечтает по пасть в правый 
//верхний.При этом она может переползать только в клетку справа или сверху и хочет, чтобы 
//сумма всех чисел, оказавшихся у нее на пути, была бы минимальной.Определить эту сумму.Ввод и 
//вывод организовать при помощи текстовых файлов.Формат входных данных : в первой строке входного 
//файла записано число N - размер доски(1 < N < 80).Далее следует N строк, каждая из которых 
//содержит N целых чисел, представляющих доску.В выходной файл нужно вывести единственное число :
//минимальную сумму.

// FIX_ME: убираем ненужные и добовдяем нужные библиотеки
#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>
#include "Header.h"
// FIX_ME: изменяем имена переменных в соответствии с код стайлом

int main() {
    //FIX_ME: не используем using namespace std в соответствии с код стайлом
    //using namespace std;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //FIX_ME: меняем названия файловых потоков на понятные
    //ifstream file1("a.txt");
    std::ifstream inputFile("a.txt");

    if (!inputFile.is_open()) 
    {
        std::cout << "Ошибка: Не удалось открыть a.txt" << std::endl;
        return 1;
    }

    int boardSize = 0;
    //FIX_ME: используем безопасное чтение вместо прямого ввода
    //file1 >> N;
    if (!SafeReadInt(inputFile, boardSize, 1))
    {
        return 1;
    }

    //FIX_ME: меняем название и структуру доски для соответствия код стайлу
    //vector<vector<int>> b(N, vector<int>(N));
    std::vector<std::vector<int>> board(boardSize, std::vector<int>(boardSize));

    //FIX_ME: переписываем чтение данных с проверкой на числа
    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            file1 >> b[i][j];
        }
    }*/
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++) 
        {
            if (!SafeReadInt(inputFile, board[i][j], i + 2)) 
            {
                return 1;
            }
        }
    }
    inputFile.close();

    // Запуск решения задачи
    SolveTurtlePath(boardSize, board);
    std::cout << "Ответ записан в выходной файл " << std::endl;

    return 0;
}