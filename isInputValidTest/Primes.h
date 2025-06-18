#pragma once

#ifndef PRIMES_H
#define PRIMES_H

#include <string>
#include <set>

/*!
 * \Структура для хранения информации об ошибке
 * \Содержит код ошибки и текстовое сообщение, описывающее ошибку
 */
struct ErrorInfo {
    int code = 0;           ///< Числовой код ошибки (инициализирован нулем)
    std::string message;    ///< Текстовое описание ошибки
};

/*!
 * \Проверяет корректность входных данных
 * \param[in] line - строка с входными данными
 * \param[out] N - преобразованное целое число
 * \param[out] error - информация об ошибке (заполняется при обнаружении ошибки)
 * \return true если входные данные корректны, false в противном случае
 */
bool isInputValid(const std::string& line, int& N, ErrorInfo& error);

/*!
 * \Находит все простые числа до заданного N
 * \param[in] N - верхняя граница поиска простых чисел
 * \return Множество простых чисел в диапазоне [2, N]
 */
std::set<int> findPrimes(int N);

#endif // PRIMES_H