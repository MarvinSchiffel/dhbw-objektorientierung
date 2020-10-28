#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>


class oma
{
	Gosu::Image img1;
	Gosu::Image img2;
	Gosu::Image img3;
public:
	oma() : img1("bilder/oma_steht.png"), img2("bilder/oma_schritt1.png"), img3("bilder/oma_schritt2.png") {};
	void laufen();
};

