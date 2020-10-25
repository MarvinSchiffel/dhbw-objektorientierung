#include "stdafx.h"
#include "objekte.h"
#include "Gosu/Gosu.hpp"
#include <cmath>


int status = 4;


void objekte::laufen() {
	if (status == 4) {
		img = Gosu::Image("oma_steht.png");
		img.draw_rot(x,y, 1, 0, 0, 0, 1, 1);
		status -= 1;
	}
	else if (status == 3) {
		img = Gosu::Image("oma_schritt1.png");
		img.draw_rot(x,y, 1, 0, 0, 0, 1, 1);
		status -= 1;
	}
	else if (status == 2) {
		img = Gosu::Image("oma_steht.png");
		img.draw_rot(x, y, 1, 0, 0, 0, 1, 1);
		status -= 1;
	}
	else if (status == 1) {
		img = Gosu::Image("oma_schritt2.png");
		img.draw_rot(x, y, 1, 0, 0, 0, 1, 1);
		status = 4;
	}
	x -= 5;
}
