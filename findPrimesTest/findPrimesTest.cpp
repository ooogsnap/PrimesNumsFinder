#include "pch.h"
#include "CppUnitTest.h"
#include "../Primes/Primes.h"
#include <set>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace findPrimesTest
{
    TEST_CLASS(findPrimesTest)
    {
    public:

        // 1. ���� �� ����������� ���������� ����� (2)
        TEST_METHOD(MinValidNumber)
        {
            set<int> primes = findPrimes(2);
            set<int> expected = { 2 };
            Assert::IsTrue(primes == expected);
        }

        // 2. ���� �� ��������� ������� ����� (7)
        TEST_METHOD(SmallPrimeNumber)
        {
            set<int> primes = findPrimes(7);
            set<int> expected = { 2, 3, 5, 7 };
            Assert::IsTrue(primes == expected);
        }

        // 3. ���� �� ��������� ����� (10)
        TEST_METHOD(CompositeNumber)
        {
            set<int> primes = findPrimes(10);
            set<int> expected = { 2, 3, 5, 7 };
            Assert::IsTrue(primes == expected);
        }

        // 4. ���� �� ������� ������� ��������� (9999)
        TEST_METHOD(MaxBoundaryNumber)
        {
            set<int> primes = findPrimes(9999);
            Assert::AreEqual(1229, (int)primes.size()); // ��������� ���������� ������� ����� �� 9999
            Assert::IsTrue(primes.count(9973)); // ��������� ���������� ������� ����� � ���������
        }

        // 5. ���� �� ������������� �����
        TEST_METHOD(NegativeNumber)
        {
            set<int> primes = findPrimes(-10);
            Assert::IsTrue(primes.empty());
        }

        // 6. ���� �� ����
        TEST_METHOD(ZeroInput)
        {
            set<int> primes = findPrimes(0);
            Assert::IsTrue(primes.empty());
        }

        // 7. ���� �� �������
        TEST_METHOD(OneInput)
        {
            set<int> primes = findPrimes(1);
            Assert::IsTrue(primes.empty());
        }

        // 8. ���� �� �����, ��������� �� ������� (11 - �������, ��������� 12)
        TEST_METHOD(AfterPrimeNumber)
        {
            set<int> primes = findPrimes(12);
            set<int> expected = { 2, 3, 5, 7, 11 };
            Assert::IsTrue(primes == expected);
        }

        // 9. ���� �� ������� �������� ����� (7? = 49)
        TEST_METHOD(PrimeSquare)
        {
            set<int> primes = findPrimes(49);
            Assert::IsTrue(primes.count(7));
            Assert::IsFalse(primes.count(49));
        }

        // 10. ���� �� ������������ ������� ����� (5*7=35)
        TEST_METHOD(ProductOfPrimes)
        {
            set<int> primes = findPrimes(35);
            Assert::IsTrue(primes.count(5));
            Assert::IsTrue(primes.count(7));
            Assert::IsFalse(primes.count(35));
        }

        // 11. ���� �� ������� ��������� ����� (100)
        TEST_METHOD(LargeCompositeNumber)
        {
            set<int> primes = findPrimes(100);
            Assert::AreEqual(25, (int)primes.size());
            Assert::IsTrue(primes.count(97));
        }
    };
}