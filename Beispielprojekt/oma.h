#pragma once
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>


class oma : public Gosu::Window
{
private:
	Gosu::Image img1;
	Gosu::Image img2;
	Gosu::Image img3;
	Gosu::Image img4;
	float position_x = 0;
	float position_y = 450;
	float velocity = 8;
	float status = 20;
public:
	oma(float position_x, float position_y);

	void move(Gosu::Image img1, Gosu::Image img2, Gosu::Image img3,Gosu::Image img4);
	
};

