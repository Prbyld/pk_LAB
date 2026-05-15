#pragma once

#include <string>
#include <iostream>

class base {
	int kompresja,
		crc;
	std::string format;
public:
	int dekoduj() {

	}
	int  wypisz_format() {
		std::cout << format;
	}
	base(int kompresja, int crc, std::string format) :kompresja(kompresja), crc(crc), format(format) {
		std::cout << "\n" + (std::string)typeid(this).name();
	}
	base() :kompresja(0), crc(0), format("format") {
		std::cout << "\n" + (std::string)typeid(this).name();
	}
};

class radiofm : public base {

public:
	radiofm() {
		std::cout << "\n" + (std::string)typeid(this).name();
	}
};

class MPG : public base {

public:
	MPG() {
		std::cout << "\n" + (std::string)typeid(this).name();
	}
};

class dab : public base {

public:
	dab() {
		std::cout << "\n" + (std::string)typeid(this).name();
	}
};

class mp3 : public base {

public:
	mp3() {
		std::cout << "\n" + (std::string)typeid(this).name();
	}
};

class dekoder : public radiofm, public MPG, public dab, public mp3 {
	int moc;
public:

	void set_moc(int dmoc) {
		moc = dmoc;
	}

	dekoder() {
		std::cout << "\n" + (std::string)typeid(this).name();
	}
};

class MPG2 : public MPG {

public:
	MPG2() {
		std::cout << "\n" + (std::string)typeid(this).name();
	}
};

class MPG4 : public MPG, public MPG2 {

public:
	MPG4() {
		std::cout << "\n" + (std::string)typeid(this).name();
	}
};

class odtwarzacz : public MPG4 {

public:
	odtwarzacz() {
		std::cout << "\n" + (std::string)typeid(this).name();
	}
};

// zaimplementuj mapê pogody z wykorzystaniem dziedziczenia wielobazowego do reprezentacji stanu pogody na konsoli
// -||- misjê drono robota na marsie z wykorzystaniem dziedziczenia wielobazowego
// -||- z wykorzystaniem dziedziczenia wielobazowego 