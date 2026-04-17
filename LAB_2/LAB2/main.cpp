#include <iostream>

#include "functions.h"

int main() {
	liczba_zespolona i1(3.14, 1.41);
	liczba_zespolona i2(9.81, 2.71);
	std::cout << i1 + i2 << "\n";
	i1 += i2;
	std::cout << i1 << "\n";
	i1 -= i2;
	std::cout << i1 << "\n";
	std::cout << i1 - i2 << "\n";
	std::cout << i1[0] << "\n";
	std::cout << (i1 == i2) << "\n";
	std::cout << (i1 != i2) << "\n";
	liczba_zespolona i3 = i1 + i2;
	std::cout << i3 << "\n";
	i3 = i1;
	std::cout << i3++ << "\n";
	std::cout << i3 << "\n";
	++i3;
	std::cout << i3 << "\n";
}