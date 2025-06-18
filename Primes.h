/*!
 * \file Primes.h
 * \brief Заголовочный файл для работы с простыми числами
 * \author Vladislav
 * \date 17.06.2025
 */

#pragma once

#ifndef PRIMES_H
#define PRIMES_H

#include <string>
#include <set>

 /*!
  * \enum ErrorCode
  * \brief Коды ошибок для валидации входных данных
  */
enum class ErrorCode {
    NO_ERROR = 0,
    FILE_NOT_FOUND = 1,
    OUTPUT_FILE_ERROR = 2,
    EMPTY_INPUT = 3,
    MULTIPLE_LINES = 4,
    INVALID_FORMAT = 5,
    OUT_OF_RANGE = 6
};

/*!
 * \struct ErrorInfo
 * \brief Структура для хранения информации об ошибке
 */
struct ErrorInfo {
    ErrorCode code = ErrorCode::NO_ERROR; ///< Код ошибки
    std::string message;                 ///< Текстовое описание ошибки
};

/*!
 * \brief Проверяет корректность входных данных
 * \param[in] line - строка с входными данными
 * \param[out] N - преобразованное целое число
 * \param[out] error - информация об ошибке
 * \return true если данные корректны, false в противном случае
 */
bool isInputValid(const std::string& line, int& N, ErrorInfo& error);

/*!
 * \brief Находит все простые числа до заданного N (Решето Эратосфена)
 * \param[in] N - верхняя граница поиска
 * \return Множество простых чисел в диапазоне [2, N]
 */
std::set<int> findPrimes(int N);

#endif // PRIMES_H