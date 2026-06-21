#pragma once

#ifndef CLASS_H
#define CLASS_H

#include <iostream>

class LiczbaZespolona {
private:
    double RE;
    double IM;

    static int licznik;

public:
    LiczbaZespolona();

    LiczbaZespolona(double re);

    LiczbaZespolona(double re, double im);

    LiczbaZespolona(const LiczbaZespolona& wzor);

    LiczbaZespolona(LiczbaZespolona&& wzor) noexcept;

    ~LiczbaZespolona();

    LiczbaZespolona& operator=(LiczbaZespolona&& wzor) noexcept;

    LiczbaZespolona& operator=(const LiczbaZespolona& wzor);

    double getRE() const;
    void setRE(double re);

    double getIM() const;
    void setIM(double im);

    static int getLicznik();

    void wypisz() const;
};


class TablicaWielowymiarowa {
private:
    int wiersze;
    int kolumny;
    LiczbaZespolona** tablica;

public:
    TablicaWielowymiarowa(int w, int k);

    TablicaWielowymiarowa(TablicaWielowymiarowa&& wzor) noexcept;

    TablicaWielowymiarowa& operator=(TablicaWielowymiarowa&& wzor) noexcept;

    ~TablicaWielowymiarowa();

    void ustaw(int w, int k, const LiczbaZespolona& lz);
    void wypisz() const;
};

#endif