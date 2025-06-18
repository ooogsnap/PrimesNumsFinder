echo. > results.txt

echo TEST1: Valid number in range (42) >> results.txt
if exist output.txt del output.txt
Primes.exe test01.txt >> results.txt 2>&1
if exist output.txt type output.txt >> results.txt
echo. >> results.txt

echo TEST2: Number with whitespace ("   100   ") >> results.txt
if exist output.txt del output.txt
Primes.exe test02.txt >> results.txt 2>&1
if exist output.txt type output.txt >> results.txt
echo. >> results.txt

echo TEST3: Lower boundary (2) >> results.txt
if exist output.txt del output.txt
Primes.exe test03.txt >> results.txt 2>&1
if exist output.txt type output.txt >> results.txt
echo. >> results.txt

echo TEST4: Upper boundary (9999) >> results.txt
if exist output.txt del output.txt
Primes.exe test04.txt >> results.txt 2>&1
if exist output.txt type output.txt >> results.txt
echo. >> results.txt

echo TEST5: Empty file >> results.txt
if exist output.txt del output.txt
Primes.exe test05.txt >> results.txt 2>&1
if exist output.txt type output.txt >> results.txt
echo. >> results.txt

echo TEST6: Number below range (1) >> results.txt
if exist output.txt del output.txt
Primes.exe test06.txt >> results.txt 2>&1
if exist output.txt type output.txt >> results.txt
echo. >> results.txt

echo TEST7: Number above range (10000) >> results.txt
if exist output.txt del output.txt
Primes.exe test07.txt >> results.txt 2>&1
if exist output.txt type output.txt >> results.txt
echo. >> results.txt

echo TEST8: Negative number (-42) >> results.txt
if exist output.txt del output.txt
Primes.exe test08.txt >> results.txt 2>&1
if exist output.txt type output.txt >> results.txt
echo. >> results.txt

echo TEST9: Non-numeric characters (42abc) >> results.txt
if exist output.txt del output.txt
Primes.exe test09.txt >> results.txt 2>&1
if exist output.txt type output.txt >> results.txt
echo. >> results.txt

echo TEST10: Two lines in file >> results.txt
if exist output.txt del output.txt
Primes.exe test10.txt >> results.txt 2>&1
if exist output.txt type output.txt >> results.txt
echo. >> results.txt

echo TEST11: Number with leading zeros (0042) >> results.txt
if exist output.txt del output.txt
Primes.exe test11.txt >> results.txt 2>&1
if exist output.txt type output.txt >> results.txt
echo. >> results.txt

echo TEST12: Number with internal spaces ("4 2") >> results.txt
if exist output.txt del output.txt
Primes.exe test12.txt >> results.txt 2>&1
if exist output.txt type output.txt >> results.txt
echo. >> results.txt

echo TEST13: Largest prime in range (9973) >> results.txt
if exist output.txt del output.txt
Primes.exe test13.txt >> results.txt 2>&1
if exist output.txt type output.txt >> results.txt
echo. >> results.txt

echo TEST14: Number after largest prime (9974) >> results.txt
if exist output.txt del output.txt
Primes.exe test14.txt >> results.txt 2>&1
if exist output.txt type output.txt >> results.txt
echo. >> results.txt

echo TEST15: Large number with leading zeros >> results.txt
if exist output.txt del output.txt
Primes.exe test15.txt >> results.txt 2>&1
if exist output.txt type output.txt >> results.txt
echo. >> results.txt