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
        // “ест провер€ет обработку корректного числа в середине допустимого диапазона
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

        // “ест провер€ет обработку числа с пробельными символами вокруг
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

        // “ест провер€ет обработку минимального допустимого числа (нижн€€ граница диапазона)
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

        // “ест провер€ет обработку максимального допустимого числа (верхн€€ граница диапазона)
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

        // “ест провер€ет обработку пустой строки
        TEST_METHOD(EmptyString)
        {
            string input = "";
            int N;
            ErrorInfo error;

            bool result = isInputValid(input, N, error);

            Assert::IsFalse(result);
            Assert::IsTrue(error.code == ErrorCode::EMPTY_INPUT);
            Assert::AreEqual(string("¬ходной файл пуст. ¬ведите натуральное число N."), error.message);
        }

        // “ест провер€ет обработку числа ниже допустимого диапазона
        TEST_METHOD(NumberBelowRange)
        {
            string input = "1";
            int N;
            ErrorInfo error;

            bool result = isInputValid(input, N, error);

            Assert::IsFalse(result);
            Assert::IsTrue(error.code == ErrorCode::OUT_OF_RANGE);
            Assert::AreEqual(string("„исло N должно быть в диапазоне [2, 10000)."), error.message);
        }

        // “ест провер€ет обработку числа выше допустимого диапазона
        TEST_METHOD(NumberAboveRange)
        {
            string input = "10000";
            int N;
            ErrorInfo error;

            bool result = isInputValid(input, N, error);

            Assert::IsFalse(result);
            Assert::IsTrue(error.code == ErrorCode::OUT_OF_RANGE);
            Assert::AreEqual(string("„исло N должно быть в диапазоне [2, 10000)."), error.message);
        }

        // “ест провер€ет обработку отрицательного числа
        TEST_METHOD(NegativeNumber)
        {
            string input = "-42";
            int N;
            ErrorInfo error;

            bool result = isInputValid(input, N, error);

            Assert::IsFalse(result);
            Assert::IsTrue(error.code == ErrorCode::INVALID_FORMAT);
            Assert::AreEqual(string("ќжидаетс€ натуральное число в диапазоне [2, 10000)."), error.message);
        }

        // “ест провер€ет обработку строки, содержащей цифры и буквы
        TEST_METHOD(NonNumericCharacters)
        {
            string input = "42abc";
            int N;
            ErrorInfo error;

            bool result = isInputValid(input, N, error);

            Assert::IsFalse(result);
            Assert::IsTrue(error.code == ErrorCode::INVALID_FORMAT);
            Assert::AreEqual(string("ќжидаетс€ натуральное число в диапазоне [2, 10000)."), error.message);
        }

        // “ест провер€ет обработку строки, содержащей только нечисловые символы
        TEST_METHOD(SymbolsOnly)
        {
            string input = "abc!@#";
            int N;
            ErrorInfo error;

            bool result = isInputValid(input, N, error);

            Assert::IsFalse(result);
            Assert::IsTrue(error.code == ErrorCode::INVALID_FORMAT);
            Assert::AreEqual(string("ќжидаетс€ натуральное число в диапазоне [2, 10000)."), error.message);
        }

        // “ест провер€ет обработку файла с двум€ строками (эмулируетс€ символом новой строки)
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
            Assert::AreEqual(string("ќжидаетс€ натуральное число в диапазоне [2, 10000)."), error.message);
        }

        // “ест провер€ет обработку числа с ведущими нул€ми
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

        // “ест провер€ет обработку строки с пробелами внутри числа
        TEST_METHOD(NumberWithInternalSpaces)
        {
            string input = "4 2";
            int N;
            ErrorInfo error;

            bool result = isInputValid(input, N, error);

            Assert::IsFalse(result);
            Assert::IsTrue(error.code == ErrorCode::INVALID_FORMAT);
            Assert::AreEqual(string("ќжидаетс€ натуральное число в диапазоне [2, 10000)."), error.message);
        }
    };
}