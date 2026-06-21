#pragma once
#include <iostream>

class liczba_zespolona {
private:
    float IM;
    float RE;

public:
    liczba_zespolona();
    liczba_zespolona(float val);
    liczba_zespolona(float im, float re);
    ~liczba_zespolona();

    float get_IM() const { return IM; }
    float get_RE() const { return RE; }
    void set_IM(float im);
    void set_RE(float re);
    void set(float im, float re);

    liczba_zespolona operator+ (const liczba_zespolona& i);
    liczba_zespolona operator- (const liczba_zespolona& i);
    liczba_zespolona& operator+= (const liczba_zespolona& i);
    liczba_zespolona& operator-= (const liczba_zespolona& i);
    liczba_zespolona& operator= (const liczba_zespolona& i);

    liczba_zespolona& operator++ (); 
    liczba_zespolona operator++ (int);

    float operator[] (int i) const;
    bool operator== (const liczba_zespolona& i);
    bool operator!= (const liczba_zespolona& i);

    friend std::ostream& operator<< (std::ostream& s, const liczba_zespolona& i);
    friend std::istream& operator>> (std::istream& s, liczba_zespolona& i);
};