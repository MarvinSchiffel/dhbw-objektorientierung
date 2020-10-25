#pragma once
#include <Gosu\Image.hpp>
#include <iostream>
#include <string>

class objekte
{
	int x = 0.0;
	int y = 0.0;
	int status = 4;
	Gosu::Image img;
	objekte(int x, int y, std::string img);
	void laufen();
};