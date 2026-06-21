#include <iostream>
#include "class.h"

void wypiszSamolot(Samolot s) {
    std::cout << "--- Dane Samolotu ---" << std::endl;
    std::cout << "Paliwo: " << s.paliwo << ", Wysokosc: " << s.wysokosc << std::endl;
    if (s.sygnatura) {
        std::cout << "Sygnatura: " << s.sygnatura << std::endl;
    }
    std::cout << "Masa: " << s.masa << " kg" << std::endl;
}

Samolot skorygujWysokosc(Samolot s, double korekta) {
    s.wysokosc -= korekta;
    return s;
}

int main() {
    Samolot s1(100.0, 500.0, 10.0, 20.0, 30.0, 1000.0, "BOEING-747", 12000);

    Samolot s2;
    s2.paliwo = 50.0;
    s2.dystans = 200.0;
    s2.wysokosc = 500.0;

    wypiszSamolot(s1);

    Samolot s3 = skorygujWysokosc(s1, 200.0);
    wypiszSamolot(s3);

    s2 = s1;
    wypiszSamolot(s2);

    return 0;
}