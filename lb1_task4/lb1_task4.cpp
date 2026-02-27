//Во всех заданиях данной подгруппы предполагается, что исходные строки, определяющие выражения, 
//не содержат пробелов.При выполнении заданий не следует использовать оператор цикла.
//Вывести значение логического выражения, заданного в виде строки S.Выражение определяется следующим 
//образом(«T» — True, «F» — False) :
//    <выражение> :: = T | F | And(<выражение>, <выражение>) | Or(<выражение>, <выражение>)

//FIX_ME: добавляем библиотеки и убираем/переносим ненужные
#include <iostream>
#include <string>
#include <Windows.h>
#include "Header.h"
//FIX_ME: меняем названия переменным в соответствии с код стайлом
int main() {
    //FIX_ME: не используем using namespace std в соответствии с код стайлом
    //using namespace std;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //FIX_ME: исправляем нарушение условия (запрет циклов) и удаляем функцию с while
    /*void skipWhitespaces(const string& expression, int& pos) {
        while (pos < expression.length() && isspace(expression[pos])) pos++;
    }*/

    std::string expression;
    std::cout << "Введите логическое выражение (без пробелов): ";
    std::getline(std::cin, expression);

    try {
        //FIX_ME: исправляем вызов функции и обработку результата
        //int pos = 0; bool result = evaluateExpression(expression, pos);
        bool result = SolveExpression(expression);

        std::cout << "Результат: " << (result ? "True" : "False") << std::endl;
    }
    catch (const std::exception& e) {
        //FIX_ME: исправляем вывод сообщения об ошибке
        //cout << "Ожидается: " << e.what() << endl;
        std::cout << "Ошибка: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}