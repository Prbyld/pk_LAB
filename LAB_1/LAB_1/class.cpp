#include "class.h"

int LiczbaZespolona::licznik = 0;

LiczbaZespolona::LiczbaZespolona() : RE(0.0), IM(0.0) {
    licznik++;
    std::cout << "Konstruktor bezargumentowy zostal wywolany. Licznik: " << licznik << std::endl;
}

LiczbaZespolona::LiczbaZespolona(double re) : RE(re), IM(0.0) {
    licznik++;
    std::cout << "Konstruktor jednoargumentowy zostal wywolany. Licznik: " << licznik << std::endl;
}

LiczbaZespolona::LiczbaZespolona(double re, double im) : RE(re), IM(im) {
    licznik++;
    std::cout << "Konstruktor wieloargumentowy zostal wywolany. Licznik: " << licznik << std::endl;
}

LiczbaZespolona::LiczbaZespolona(const LiczbaZespolona& wzor) : RE(wzor.RE), IM(wzor.IM) {
    licznik++;
    std::cout << "Konstruktor kopiujacy zostal wywolany. Licznik: " << licznik << std::endl;
}

LiczbaZespolona::LiczbaZespolona(LiczbaZespolona&& wzor) noexcept : RE(wzor.RE), IM(wzor.IM) {
    licznik++;
    std::cout << "Konstruktor przenoszacy zostal wywolany. Licznik: " << licznik << std::endl;
    wzor.RE = 0;
    wzor.IM = 0;
}

LiczbaZespolona::~LiczbaZespolona() {
    licznik--;
    std::cout << "Destruktor zostal wywolany. Licznik: " << licznik << std::endl;
}

LiczbaZespolona& LiczbaZespolona::operator=(LiczbaZespolona&& wzor) noexcept {
    std::cout << "Operator przeniesienia zostal wywolany." << std::endl;
    if (this != &wzor) {
        RE = wzor.RE;
        IM = wzor.IM;
        wzor.RE = 0;
        wzor.IM = 0;
    }
    return *this;
}

LiczbaZespolona& LiczbaZespolona::operator=(const LiczbaZespolona& wzor) {
    std::cout << "Operator przypisania kopiujacego zostal wywolany." << std::endl;
    if (this != &wzor) {
        RE = wzor.RE;
        IM = wzor.IM;
    }
    return *this;
}

double LiczbaZespolona::getRE() const { return RE; }
void LiczbaZespolona::setRE(double re) { RE = re; }

double LiczbaZespolona::getIM() const { return IM; }
void LiczbaZespolona::setIM(double im) { IM = im; }

int LiczbaZespolona::getLicznik() { return licznik; }

void LiczbaZespolona::wypisz() const {
    std::cout << RE << " + " << IM << "i" << std::endl;
}


TablicaWielowymiarowa::TablicaWielowymiarowa(int w, int k) : wiersze(w), kolumny(k) {
    tablica = new LiczbaZespolona * [wiersze];
    for (int i = 0; i < wiersze; ++i) {
        tablica[i] = new LiczbaZespolona[kolumny]; 
    }
}

TablicaWielowymiarowa::TablicaWielowymiarowa(TablicaWielowymiarowa&& wzor) noexcept
    : wiersze(wzor.wiersze), kolumny(wzor.kolumny), tablica(wzor.tablica) {
    wzor.wiersze = 0;
    wzor.kolumny = 0;
    wzor.tablica = nullptr;
}

TablicaWielowymiarowa& TablicaWielowymiarowa::operator=(TablicaWielowymiarowa&& wzor) noexcept {
    if (this != &wzor) {
        if (tablica != nullptr) {
            for (int i = 0; i < wiersze; ++i) delete[] tablica[i];
            delete[] tablica;
        }

        
        wiersze = wzor.wiersze;
        kolumny = wzor.kolumny;
        tablica = wzor.tablica;

        
        wzor.wiersze = 0;
        wzor.kolumny = 0;
        wzor.tablica = nullptr;
    }
    return *this;
}

TablicaWielowymiarowa::~TablicaWielowymiarowa() {
    if (tablica != nullptr) {
        for (int i = 0; i < wiersze; ++i) {
            delete[] tablica[i];
        }
        delete[] tablica;
    }
}

void TablicaWielowymiarowa::ustaw(int w, int k, const LiczbaZespolona& lz) {
    if (w < wiersze && k < kolumny) {
        tablica[w][k] = lz; 
    }
}

void TablicaWielowymiarowa::wypisz() const {
    for (int i = 0; i < wiersze; ++i) {
        for (int j = 0; j < kolumny; ++j) {
            tablica[i][j].wypisz();
        }
    }
}