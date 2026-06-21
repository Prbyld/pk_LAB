#include "class.h"
#include <string>

Samolot::Samolot() : paliwo(0), dystans(0), x(0), y(0), z(0), wysokosc(0), sygnatura(nullptr), masa(5000) {}

Samolot::Samolot(double p, double d, double _x, double _y, double _z, double w, const char* syg, int m)
    : paliwo(p), dystans(d), x(_x), y(_y), z(_z), wysokosc(w), masa(m) {
    if (syg) {
        sygnatura = new char[strlen(syg) + 1];
        for (int i = 0; i < strlen(syg); ++i) {
            sygnatura[i] = syg[i];
        }
    }
    else {
        sygnatura = nullptr;
    }
}

Samolot::Samolot(const Samolot& inny) : masa(inny.masa) {
    paliwo = inny.paliwo;
    dystans = inny.dystans;
    x = inny.x;
    y = inny.y;
    z = inny.z;
    wysokosc = inny.wysokosc;

    if (inny.sygnatura) {
        sygnatura = new char[strlen(inny.sygnatura) + 1];
        for (int i = 0; i < strlen(inny.sygnatura); ++i) {
            sygnatura[i] = inny.sygnatura[i];
        }
    }
    else {
        sygnatura = nullptr;
    }
}

Samolot::~Samolot() {
    delete[] sygnatura;
}

Samolot& Samolot::operator=(const Samolot& inny) {
    if (this == &inny) return *this;

    paliwo = inny.paliwo;
    dystans = inny.dystans;
    x = inny.x;
    y = inny.y;
    z = inny.z;
    wysokosc = inny.wysokosc;

    delete[] sygnatura;
    if (inny.sygnatura) {
        sygnatura = new char[strlen(inny.sygnatura) + 1];
        for (int i = 0; i < strlen(inny.sygnatura); ++i) {
            sygnatura[i] = inny.sygnatura[i];
        }
    }
    else {
        sygnatura = nullptr;
    }

    return *this;
}