/*!
 * \file Primes.h
 * \brief ������������ ���� ��� ������ � �������� �������
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
  * \brief ���� ������ ��� ��������� ������� ������
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
 * \brief ��������� ��� �������� ���������� �� ������
 */
struct ErrorInfo {
    ErrorCode code = ErrorCode::NO_ERROR; ///< ��� ������
    std::string message;                 ///< ��������� �������� ������
};

/*!
 * \brief ��������� ������������ ������� ������
 * \param[in] line - ������ � �������� �������
 * \param[out] N - ��������������� ����� �����
 * \param[out] error - ���������� �� ������
 * \return true ���� ������ ���������, false � ��������� ������
 */
bool isInputValid(const std::string& line, int& N, ErrorInfo& error);

/*!
 * \brief ������� ��� ������� ����� �� ��������� N (������ ����������)
 * \param[in] N - ������� ������� ������
 * \return ��������� ������� ����� � ��������� [2, N]
 */
std::set<int> findPrimes(int N);

#endif // PRIMES_H