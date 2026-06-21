#pragma once

#include <string>
#include <iostream>


class base {
    int kompresja, crc;
    std::string format;
public:
    int dekoduj();
    void wypisz_format();
    base(int kompresja, int crc, std::string format);
    base();
};

class radiofm : public base {
public:
    radiofm();
};

class MPG : public base {
public:
    MPG();
};

class dab : public base {
public:
    dab();
};

class mp3 : public base {
public:
    mp3();
};

class dekoder : public radiofm, public MPG, public dab, public mp3 {
    int moc;
public:
    void set_moc(int dmoc);
    dekoder();
};

class MPG2 : public MPG {
public:
    MPG2();
};

class MPG4 : public MPG, public MPG2 {
public:
    MPG4();
};

class odtwarzacz : public MPG4 {
public:
    odtwarzacz();
};

class Temperatura {
protected:
    int stopnie = 20;
};

class Opady {
protected:
    std::string rodzaj = "Deszcz";
};

class MapaPogody : public Temperatura, public Opady {
public:
    void wyswietl();
};

class Dron {
public:
    void lec();
};

class Skaner {
public:
    void skanuj();
};

class MarsRobot : public Dron, public Skaner {
public:
    void wykonaj_misje();
};