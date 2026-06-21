#include "functions.h"

liczba_zespolona::liczba_zespolona() : IM(0), RE(0) {}

liczba_zespolona::liczba_zespolona(float val) : IM(val), RE(val) {}

liczba_zespolona::liczba_zespolona(float im, float re) : IM(im), RE(re) {}

liczba_zespolona::~liczba_zespolona() {}

void liczba_zespolona::set_IM(float im) {
    IM = im;
}

void liczba_zespolona::set_RE(float re) {
    RE = re;
}

void liczba_zespolona::set(float im, float re) {
    IM = im;
    RE = re;
}

liczba_zespolona liczba_zespolona::operator+ (const liczba_zespolona& i) {
    return liczba_zespolona(this->IM + i.get_IM(), this->RE + i.get_RE());
}

liczba_zespolona liczba_zespolona::operator- (const liczba_zespolona& i) {
    return liczba_zespolona(this->IM - i.get_IM(), this->RE - i.get_RE());
}

liczba_zespolona& liczba_zespolona::operator+= (const liczba_zespolona& i) {
    IM += i.get_IM();
    RE += i.get_RE();
    return *this;
}

liczba_zespolona& liczba_zespolona::operator-= (const liczba_zespolona& i) {
    IM -= i.get_IM();
    RE -= i.get_RE();
    return *this;
}

liczba_zespolona& liczba_zespolona::operator= (const liczba_zespolona& i) {
    if (this != &i) { 
        IM = i.get_IM();
        RE = i.get_RE();
    }
    return *this;
}

liczba_zespolona& liczba_zespolona::operator++ () {
    IM++;
    return *this;
}

liczba_zespolona liczba_zespolona::operator++ (int) {
    liczba_zespolona old = *this;
    operator++();
    return old;
}

float liczba_zespolona::operator[] (int i) const {
    return i ? this->get_RE() : this->get_IM();
}

bool liczba_zespolona::operator== (const liczba_zespolona& i) {
    return (this->IM == i.get_IM() && this->RE == i.get_RE());
}

bool liczba_zespolona::operator!= (const liczba_zespolona& i) {
    return (this->IM != i.get_IM() || this->RE != i.get_RE());
}

std::ostream& operator<< (std::ostream& s, const liczba_zespolona& i) {
    s << i.IM << " " << i.RE;
    return s;
}

std::istream& operator>> (std::istream& s, liczba_zespolona& i) {
    s >> i.IM >> i.RE;
    return s;
}