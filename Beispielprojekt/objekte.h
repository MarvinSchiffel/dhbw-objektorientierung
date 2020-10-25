#pragma once
#include <Gosu\Image.hpp>
#include <iostream>
#include <string>

class objekte
{
public:
	int x = 0.0;
	int y = 0.0;
	Gosu::Image img;
	objekte() {};
	objekte(int x, int y, Gosu::Image img) : x(x), y(y), img(img) {};
	void laufen();
};