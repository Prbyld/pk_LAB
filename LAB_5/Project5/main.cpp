#include "class.h"
#include <iostream>
#include <vector>

int main() {
    Pytanie* pytanie = new PytanieOtwarte("Podaj date chrztu Polski (966)?");
    pytanie->wyswietl();

    WalidatorEmail v1;
    WalidatorRzymski v2;
    std::cout << "Czy 'test@wp.pl' ma @? " << (v1.waliduj("test@wp.pl") ? "Tak" : "Nie") << "\n";
    std::cout << "Czy 'XIV' to rzymskie (I,V,X)? " << (v2.waliduj("XIV") ? "Tak" : "Nie") << "\n";

    std::vector<EfektSpecjalny*> efekty;
    efekty.push_back(new Woda());
    efekty.push_back(new Ogien());
    efekty.push_back(new Dym());

    for (EfektSpecjalny* e : efekty) {
        e->wyzwol();
    }

    Winda* winda = new WindaPasazerska();
    winda->jedz(4);

    std::vector<Liczba*> liczby;
    liczby.push_back(new FormatDziesiatkowy(10));
    liczby.push_back(new FormatDwojkowy(10));

    for (Liczba* l : liczby) {
        l->wypisz();
    }

    delete pytanie;
    delete winda;
    for (EfektSpecjalny* e : efekty) delete e;
    for (Liczba* l : liczby) delete l;

    return 0;
}