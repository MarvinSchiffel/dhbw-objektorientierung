#include "stdafx.h"
#include "objekte.h"
#include "Gosu/Gosu.hpp"
#include <cmath>

void objekte::laufen() {
	if (status == 4) {
		this->img = Gosu::Image("oma_steht.png");
		this->img.draw_rot(this->x, this->y, 1, 0, 0, 0, 1, 1);
		status -= 1;
	}
	else if (status == 3) {
		this->img = Gosu::Image("oma_schritt1.png");
		this->img.draw_rot(this->x, this->y, 1, 0, 0, 0, 1, 1);
		status -= 1;
	}
	else if (status == 2) {
		this->img = Gosu::Image("oma_steht.png");
		this->img.draw_rot(this->x, this->y, 1, 0, 0, 0, 1, 1);
		status -= 1;
	}
	else if (status == 1) {
		this->img = Gosu::Image("oma_schritt2.png");
		this->img.draw_rot(this->x, this->y, 1, 0, 0, 0, 1, 1);
		status = 4;
	}
	this->x -= 5;
}
