#pragma once


class liczba_zespolona {
private:
	float IM;
	float RE;

public:
	float get_IM() { return IM; }
	float get_RE() { return RE; }
	void set_IM(float im) {
		IM = im;
	}
	void set_RE(float re) {
		RE = re;
	}
	void set(float im, float re) {
		IM = im;
		RE = re;
	}
	liczba_zespolona operator+ (liczba_zespolona& i) {
		return liczba_zespolona(this->get_IM() + i.get_IM(), this->get_RE() + i.get_RE());
	}
	liczba_zespolona operator- (liczba_zespolona& i) {
		return liczba_zespolona(this->get_IM() - i.get_IM(), this->get_RE() - i.get_RE());
	}
	liczba_zespolona operator+= (liczba_zespolona& i) {
		IM += i.get_IM();
		RE += i.get_RE();
		return *this;
	}
	liczba_zespolona operator-= (liczba_zespolona& i) {
		IM -= i.get_IM();
		RE -= i.get_RE();
		return *this;
	}
	friend std::ostream& operator<< (std::ostream& s, const liczba_zespolona& i) {
		s << i.IM << " " << i.RE;
		return s;
	}
	friend std::istream& operator>> (std::istream& s, liczba_zespolona& i) {
		s >> i.IM >> i.RE;
		return s;
	}
	float operator[] (int i) {
		return i ? this->get_RE() : this->get_IM();
	}
	bool operator == (liczba_zespolona& i) {
		return (this->get_IM() == i.get_IM() && this->get_RE() == i.get_RE());
	}
	bool operator != (liczba_zespolona& i) {
		return (this->get_IM() != i.get_IM() && this->get_RE() != i.get_RE());
	}
	liczba_zespolona& operator= (liczba_zespolona& i) {
		IM = i.get_IM();
		RE = i.get_RE();
		return *this;
	}
	liczba_zespolona& operator++ () {
		IM++;
		return *this;
	}
	liczba_zespolona& operator++ (int) {
		liczba_zespolona old = *this;
		operator++ ();
		return old;
	}

	liczba_zespolona() :IM(0), RE(0) {
		//std::cout << "Konstruktor 0 wartosciowy zostal wywolany\n";
	}
	liczba_zespolona(float val) :IM(val), RE(IM) {
		//std::cout << "Konstruktor 1 wartosciowy zostal wywolany\n";
	}
	liczba_zespolona(float im, float re) :IM(im), RE(re) {
		//std::cout << "Konstruktor 2 wartosciowy zostal wywolany\n";
	}

	~liczba_zespolona() {
		//std::cout << "Dekonstruktor zostal wywolany\n";
	}
};
