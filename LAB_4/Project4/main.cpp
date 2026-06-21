#include <iostream>

#include "class.h"

int main() {
	dekoder c;
	c.set_moc(2);
	std::cout << "\n";
	odtwarzacz d;

	MapaPogody mp;
	mp.wyswietl();

	MarsRobot robot;
	robot.wykonaj_misje();
}