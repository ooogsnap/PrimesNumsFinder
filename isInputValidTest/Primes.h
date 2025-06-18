#pragma once

#ifndef PRIMES_H
#define PRIMES_H

#include <string>
#include <set>

/*!
 * \��������� ��� �������� ���������� �� ������
 * \�������� ��� ������ � ��������� ���������, ����������� ������
 */
struct ErrorInfo {
    int code = 0;           ///< �������� ��� ������ (��������������� �����)
    std::string message;    ///< ��������� �������� ������
};

/*!
 * \��������� ������������ ������� ������
 * \param[in] line - ������ � �������� �������
 * \param[out] N - ��������������� ����� �����
 * \param[out] error - ���������� �� ������ (����������� ��� ����������� ������)
 * \return true ���� ������� ������ ���������, false � ��������� ������
 */
bool isInputValid(const std::string& line, int& N, ErrorInfo& error);

/*!
 * \������� ��� ������� ����� �� ��������� N
 * \param[in] N - ������� ������� ������ ������� �����
 * \return ��������� ������� ����� � ��������� [2, N]
 */
std::set<int> findPrimes(int N);

#endif // PRIMES_H