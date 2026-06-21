#include "class.h"

int base::dekoduj() {
    return 0;
}

void base::wypisz_format() {
    std::cout << format;
}

base::base(int kompresja, int crc, std::string format) : kompresja(kompresja), crc(crc), format(format) {
    std::cout << "\n" + (std::string)typeid(this).name();
}

base::base() : kompresja(0), crc(0), format("format") {
    std::cout << "\n" + (std::string)typeid(this).name();
}

radiofm::radiofm() {
    std::cout << "\n" + (std::string)typeid(this).name();
}

MPG::MPG() {
    std::cout << "\n" + (std::string)typeid(this).name();
}

dab::dab() {
    std::cout << "\n" + (std::string)typeid(this).name();
}

mp3::mp3() {
    std::cout << "\n" + (std::string)typeid(this).name();
}

void dekoder::set_moc(int dmoc) {
    moc = dmoc;
}

dekoder::dekoder() {
    std::cout << "\n" + (std::string)typeid(this).name();
}

MPG2::MPG2() {
    std::cout << "\n" + (std::string)typeid(this).name();
}

MPG4::MPG4() {
    std::cout << "\n" + (std::string)typeid(this).name();
}

odtwarzacz::odtwarzacz() {
    std::cout << "\n" + (std::string)typeid(this).name();
}

void MapaPogody::wyswietl() {
    std::cout << "Pogoda: " << stopnie << "C, " << rodzaj << std::endl;
}

void Dron::lec() {
    std::cout << "Dron leci na nowa pozycje." << std::endl;
}

void Skaner::skanuj() {
    std::cout << "Skaner wykryl obecnosc wody!" << std::endl;
}

void MarsRobot::wykonaj_misje() {
    lec();
    skanuj();
}