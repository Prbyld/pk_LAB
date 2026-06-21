#include "class.h"
#include <iostream>

int main() {
    std::cout << "Poczatkowa liczba obiektow: " << LiczbaZespolona::getLicznik() << "\n" << std::endl;

    {
        LiczbaZespolona z1;
        LiczbaZespolona z2(3.5);
        LiczbaZespolona z3(1.0, -2.0);  
        LiczbaZespolona z4 = z3;        
        LiczbaZespolona z5 = std::move(z2); 

        std::cout << "\nLiczba obiektow wewnatrz bloku: " << LiczbaZespolona::getLicznik() << "\n" << std::endl;
    } 

    std::cout << "\nLiczba obiektow po opuszczeniu bloku: " << LiczbaZespolona::getLicznik() << "\n" << std::endl;

    std::cout << "tablica wielowymiarowa: " << std::endl;
    TablicaWielowymiarowa t1(2, 2);

    std::cout << "\nLiczba obiektow po utworzeniu tablicy t1: " << LiczbaZespolona::getLicznik() << "\n" << std::endl;

   
    TablicaWielowymiarowa t2 = std::move(t1);

    std::cout << "\nKoniec programu. Nastapi automatyczne czyszczenie pamieci przez destruktory." << std::endl;
    return 0;
}