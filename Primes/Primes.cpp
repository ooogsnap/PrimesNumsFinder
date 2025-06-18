/*!
 * \file Primes.cpp
 * \brief Реализация функций для работы с простыми числами
 * \author Vladislav
 * \date 17.06.2025
 */

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include "Primes.h"

using namespace std;

/*!
 * \brief Проверяет корректность входных данных
 * \param[in] line - строка с входными данными
 * \param[out] N - преобразованное целое число
 * \param[out] error - информация об ошибке
 * \return true если данные корректны, false в противном случае
 */
bool isInputValid(const string& line, int& N, ErrorInfo& error) {
    // Для удаления пробельных символов с начала и конца строки
    auto trim = [](const string& str) {
        const auto first = str.find_first_not_of(" \t\n\r");
        if (first == string::npos) return str;
        const auto last = str.find_last_not_of(" \t\n\r");
        return str.substr(first, last - first + 1);
        };

    string trimmedLine = trim(line);

    if (trimmedLine.empty()) {
        error.code = ErrorCode::EMPTY_INPUT;
        error.message = "Входной файл пуст. Введите натуральное число N.";
        return false;
    }

    // Проверка на наличие нецифровых символов
    if (trimmedLine.find_first_not_of("0123456789") != string::npos) {
        error.code = ErrorCode::INVALID_FORMAT;
        error.message = "Ожидается натуральное число в диапазоне [2, 10000).";
        return false;
    }

    // Попытка преобразования строки в число с обработкой исключений
    try {
        N = stoi(trimmedLine);
    }
    catch (...) {
        error.code = ErrorCode::INVALID_FORMAT;
        error.message = "Ожидается натуральное число в диапазоне [2, 10000).";
        return false;
    }
    // Проверка диапазона числа
    if (N < 2 || N >= 10000) {
        error.code = ErrorCode::OUT_OF_RANGE;
        error.message = "Число N должно быть в диапазоне [2, 10000).";
        return false;
    }

    return true;
}

/*!
 * \brief Находит все простые числа до заданного N (Решето Эратосфена)
 * \param[in] N - верхняя граница поиска
 * \return Множество простых чисел в диапазоне [2, N]
 */
set<int> findPrimes(int N) {
    set<int> primes;
    if (N < 2) return primes; // Возвращаем пустое множество если N < 2

    // Вектор для отметки простых чисел (изначально все true)
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 и 1 - не простые числа

    for (int i = 2; i <= N; ++i) {
        if (isPrime[i]) {
            primes.insert(i); // Добавляем простое число в результат

            // Помечаем все кратные i числа как не простые
            for (int j = i * 2; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return primes;
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");

    // Проверка количества аргументов командной строки
    if (argc != 2) {
        cerr << "Использование: " << argv[0] << " input.txt" << endl;
        return static_cast<int>(ErrorCode::FILE_NOT_FOUND);
    }

    // Открытие и проверка входного файла
    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Ошибка: Неверно указан файл с входными данными. " << argv[1] << endl;
        return static_cast<int>(ErrorCode::FILE_NOT_FOUND);
    }

    // Проверка что файл не пустой
    if (inputFile.peek() == ifstream::traits_type::eof()) {
        cerr << "Ошибка: Входной файл пуст. Введите натуральное число N." << endl;
        return static_cast<int>(ErrorCode::EMPTY_INPUT);
    }

    // Чтение строки из файла
    string line;
    getline(inputFile, line);
    inputFile.close();

    // Дополнительная проверка что в файле только одная строка
    ifstream checkFile(argv[1]);
    getline(checkFile, line);
    if (checkFile.peek() != EOF) {
        cerr << "Ошибка: Файл должен содержать только одну строку. Удалите лишние строки." << endl;
        return static_cast<int>(ErrorCode::MULTIPLE_LINES);
    }
    checkFile.close();

    // Валидация входных данных
    int N = 0;
    ErrorInfo error;
    if (!isInputValid(line, N, error)) {
        cerr << "Ошибка: " << error.message << endl;
        return static_cast<int>(error.code);
    }

    // Поиск простых чисел
    set<int> primes = findPrimes(N);

    // Запись результата в выходной файл
    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Ошибка: Неверно указан файл для выходных данных." << endl;
        return static_cast<int>(ErrorCode::OUTPUT_FILE_ERROR);
    }

    // Форматированных вывод простых чисел через запятую 
    bool firstPrime = true;
    for (int prime : primes) {
        if (!firstPrime) outputFile << ", ";
        outputFile << prime;
        firstPrime = false;
    }

    outputFile.close();
    cout << "Результат записан в output.txt" << endl;

    return static_cast<int>(ErrorCode::NO_ERROR);
}