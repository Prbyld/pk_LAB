#include <iostream>

class samolot
{
public:
	double paliwo,
		 dystans,
		x,
		y,
		z,
		 wysokosc;
	char * sygnature = new char[6];

	void set_x(double X) { x = X; }
	double get_x() { return x; }

	void set_y(double Y) { y = Y; }
	double get_y() { return y; }

	void set_z(double Z) { z = Z; }
	double get_z() { return z; }

	samolot() {};
	~samolot() { delete[] sygnature; };

};

void print_plane_param(samolot & sam) {
	std::cout << "\npaliwo: " << sam.paliwo << "\ndystans: " << sam.dystans << "\nx: " << sam.get_x() << "\ny: " << sam.get_y() << "\nz: " << sam.get_z() << "\nwysokosc: " << sam.wysokosc << "\n";
}

samolot korekta(samolot sam, double korekta) {
	sam.wysokosc -= korekta;
	return sam;
}

int main() {
	samolot sam1;
	sam1.paliwo = 1245;
	sam1.dystans = 130512;
	sam1.set_x(31.574);
	sam1.set_y(132.045);
	sam1.set_z(9.742);
	sam1.wysokosc = 21.532;

	print_plane_param(sam1);
	std::cout << "wysokosc: " << korekta(sam1, 3.532).wysokosc << "\n"; //executes delete on object with already deleted sygnature
	samolot sam2 = sam1;
	print_plane_param(sam2);

}