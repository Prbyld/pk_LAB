#pragma once
#ifndef CLASS_H
#define CLASS_H

class Samolot {
public:
    double paliwo;
    double dystans;
    double x, y, z;
    double wysokosc;
    char* sygnatura;
    const int masa;

    Samolot(); 
    Samolot(double p, double d, double _x, double _y, double _z, double w, const char* syg, int m);
    Samolot(const Samolot& inny);
    ~Samolot();

    Samolot& operator=(const Samolot& inny);
};

#endif