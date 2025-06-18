#include "pch.h"
#include "CppUnitTest.h"
#include "../Primes/Primes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace isInputValidTest
{
    TEST_CLASS(isInputValidTest)
    {
    public:
        // ���� ��������� ��������� ����������� ����� � �������� ����������� ���������
        TEST_METHOD(ValidNumberInRange)
        {
            string input = "42";
            int N;
            ErrorInfo error;

            bool result = isInputValid(input, N, error);

            Assert::IsTrue(result);
            Assert::AreEqual(42, N);
            Assert::IsTrue(error.code == ErrorCode::NO_ERROR);
            Assert::IsTrue(error.message.empty());
        }

        // ���� ��������� ��������� ����� � ����������� ��������� ������
        TEST_METHOD(NumberWithWhitespace)
        {
            string input = "   100   ";
            int N;
            ErrorInfo error;

            bool result = isInputValid(input, N, error);

            Assert::IsTrue(result);
            Assert::AreEqual(100, N);
            Assert::IsTrue(error.code == ErrorCode::NO_ERROR);
            Assert::IsTrue(error.message.empty());
        }

        // ���� ��������� ��������� ������������ ����������� ����� (������ ������� ���������)
        TEST_METHOD(NumberAtLowerBound)
        {
            string input = "2";
            int N;
            ErrorInfo error;

            bool result = isInputValid(input, N, error);

            Assert::IsTrue(result);
            Assert::AreEqual(2, N);
            Assert::IsTrue(error.code == ErrorCode::NO_ERROR);
            Assert::IsTrue(error.message.empty());
        }

        // ���� ��������� ��������� ������������� ����������� ����� (������� ������� ���������)
        TEST_METHOD(NumberAtUpperBound)
        {
            string input = "9999";
            int N;
            ErrorInfo error;

            bool result = isInputValid(input, N, error);

            Assert::IsTrue(result);
            Assert::AreEqual(9999, N);
            Assert::IsTrue(error.code == ErrorCode::NO_ERROR);
            Assert::IsTrue(error.message.empty());
        }

        // ���� ��������� ��������� ������ ������
        TEST_METHOD(EmptyString)
        {
            string input = "";
            int N;
            ErrorInfo error;

            bool result = isInputValid(input, N, error);

            Assert::IsFalse(result);
            Assert::IsTrue(error.code == ErrorCode::EMPTY_INPUT);
            Assert::AreEqual(string("������� ���� ����. ������� ����������� ����� N."), error.message);
        }

        // ���� ��������� ��������� ����� ���� ����������� ���������
        TEST_METHOD(NumberBelowRange)
        {
            string input = "1";
            int N;
            ErrorInfo error;

            bool result = isInputValid(input, N, error);

            Assert::IsFalse(result);
            Assert::IsTrue(error.code == ErrorCode::OUT_OF_RANGE);
            Assert::AreEqual(string("����� N ������ ���� � ��������� [2, 10000)."), error.message);
        }

        // ���� ��������� ��������� ����� ���� ����������� ���������
        TEST_METHOD(NumberAboveRange)
        {
            string input = "10000";
            int N;
            ErrorInfo error;

            bool result = isInputValid(input, N, error);

            Assert::IsFalse(result);
            Assert::IsTrue(error.code == ErrorCode::OUT_OF_RANGE);
            Assert::AreEqual(string("����� N ������ ���� � ��������� [2, 10000)."), error.message);
        }

        // ���� ��������� ��������� �������������� �����
        TEST_METHOD(NegativeNumber)
        {
            string input = "-42";
            int N;
            ErrorInfo error;

            bool result = isInputValid(input, N, error);

            Assert::IsFalse(result);
            Assert::IsTrue(error.code == ErrorCode::INVALID_FORMAT);
            Assert::AreEqual(string("��������� ����������� ����� � ��������� [2, 10000)."), error.message);
        }

        // ���� ��������� ��������� ������, ���������� ����� � �����
        TEST_METHOD(NonNumericCharacters)
        {
            string input = "42abc";
            int N;
            ErrorInfo error;

            bool result = isInputValid(input, N, error);

            Assert::IsFalse(result);
            Assert::IsTrue(error.code == ErrorCode::INVALID_FORMAT);
            Assert::AreEqual(string("��������� ����������� ����� � ��������� [2, 10000)."), error.message);
        }

        // ���� ��������� ��������� ������, ���������� ������ ���������� �������
        TEST_METHOD(SymbolsOnly)
        {
            string input = "abc!@#";
            int N;
            ErrorInfo error;

            bool result = isInputValid(input, N, error);

            Assert::IsFalse(result);
            Assert::IsTrue(error.code == ErrorCode::INVALID_FORMAT);
            Assert::AreEqual(string("��������� ����������� ����� � ��������� [2, 10000)."), error.message);
        }

        // ���� ��������� ��������� ����� � ����� �������� (����������� �������� ����� ������)
        TEST_METHOD(TwoLinesInInputFile)
        {
            string input = "42\n100";
            int N;
            ErrorInfo error;

            size_t newline_pos = input.find('\n');
            string firstLine = input.substr(0, newline_pos);

            bool result = isInputValid(firstLine, N, error);
            Assert::IsTrue(result);
            Assert::AreEqual(42, N);

            result = isInputValid(input, N, error);
            Assert::IsFalse(result);
            Assert::IsTrue(error.code == ErrorCode::INVALID_FORMAT);
            Assert::AreEqual(string("��������� ����������� ����� � ��������� [2, 10000)."), error.message);
        }

        // ���� ��������� ��������� ����� � �������� ������
        TEST_METHOD(NumberWithLeadingZeros)
        {
            string input = "0042";
            int N;
            ErrorInfo error;

            bool result = isInputValid(input, N, error);

            Assert::IsTrue(result);
            Assert::AreEqual(42, N);
            Assert::IsTrue(error.code == ErrorCode::NO_ERROR);
            Assert::IsTrue(error.message.empty());
        }

        // ���� ��������� ��������� ������ � ��������� ������ �����
        TEST_METHOD(NumberWithInternalSpaces)
        {
            string input = "4 2";
            int N;
            ErrorInfo error;

            bool result = isInputValid(input, N, error);

            Assert::IsFalse(result);
            Assert::IsTrue(error.code == ErrorCode::INVALID_FORMAT);
            Assert::AreEqual(string("��������� ����������� ����� � ��������� [2, 10000)."), error.message);
        }
    };
}