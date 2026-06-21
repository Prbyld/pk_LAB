#ifndef CLASS_H
#define CLASS_H

#include <string>
#include <vector>

class Pytanie {
protected:
    std::string tresc;
public:
    Pytanie(std::string t);
    virtual ~Pytanie() = default;
    virtual void wyswietl() const = 0;
};

class PytanieOtwarte : public Pytanie {
public:
    PytanieOtwarte(std::string t);
    void wyswietl() const override;
};

class Walidator {
public:
    virtual ~Walidator() = default;
    virtual bool waliduj(const std::string& tekst) const = 0;
};

class WalidatorEmail : public Walidator {
public:
    bool waliduj(const std::string& tekst) const override;
};

class WalidatorRzymski : public Walidator {
public:
    bool waliduj(const std::string& tekst) const override;
};

class EfektSpecjalny {
public:
    virtual ~EfektSpecjalny() = default;
    virtual void wyzwol() const = 0;
};

class Woda : public EfektSpecjalny { public: void wyzwol() const override; };
class Ogien : public EfektSpecjalny { public: void wyzwol() const override; };
class Dym : public EfektSpecjalny { public: void wyzwol() const override; };

class Winda {
protected:
    int pietro = 0;
public:
    virtual ~Winda() = default;
    virtual void jedz(int docelowe) = 0;
};

class WindaPasazerska : public Winda {
public:
    void jedz(int docelowe) override;
};

class Liczba {
protected:
    int wartosc;
public:
    Liczba(int w);
    virtual ~Liczba() = default;
    virtual void wypisz() const = 0;
};

class FormatDwojkowy : public Liczba {
public:
    FormatDwojkowy(int w);
    void wypisz() const override;
};

class FormatDziesiatkowy : public Liczba {
public:
    FormatDziesiatkowy(int w);
    void wypisz() const override;
};

#endif