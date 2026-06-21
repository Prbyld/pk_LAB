#include "class.h"
#include <iostream>

Pytanie::Pytanie(std::string t) : tresc(t) {}
PytanieOtwarte::PytanieOtwarte(std::string t) : Pytanie(t) {}
void PytanieOtwarte::wyswietl() const {
    std::cout << "Pytanie: " << tresc << "\n";
}

bool WalidatorEmail::waliduj(const std::string& tekst) const {
    return tekst.find('@') != std::string::npos;
}

bool WalidatorRzymski::waliduj(const std::string& tekst) const {
    for (char c : tekst) {
        if (c != 'I' && c != 'V' && c != 'X') return false;
    }
    return !tekst.empty();
}

void Woda::wyzwol() const { std::cout << "[EFEKT] Woda!\n"; }
void Ogien::wyzwol() const { std::cout << "[EFEKT] Ogien!\n"; }
void Dym::wyzwol() const { std::cout << "[EFEKT] Dym!\n"; }

void WindaPasazerska::jedz(int docelowe) {
    std::cout << "Winda jedzie z " << pietro << " na " << docelowe << "\n";
    pietro = docelowe;
}

Liczba::Liczba(int w) : wartosc(w) {}
FormatDziesiatkowy::FormatDziesiatkowy(int w) : Liczba(w) {}
void FormatDziesiatkowy::wypisz() const {
    std::cout << "Dziesietnie: " << wartosc << "\n";
}

FormatDwojkowy::FormatDwojkowy(int w) : Liczba(w) {}
void FormatDwojkowy::wypisz() const {
    std::cout << "Binarnie: ";
    if (wartosc == 0) std::cout << 0;
    else {
        std::string bin = "";
        int temp = wartosc;
        while (temp > 0) {
            bin = (temp % 2 == 0 ? "0" : "1") + bin;
            temp /= 2;
        }
        std::cout << bin;
    }
    std::cout << "\n";
}