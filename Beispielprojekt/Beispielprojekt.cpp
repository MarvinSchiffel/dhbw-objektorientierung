#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "Vektor2d.h"

// Simulationsgeschwindigkeit
const double DT = 100.0;

class GameWindow : public Gosu::Window
{
public:
	Gosu::Image bild_rakete;
	Gosu::Image bild_planet_1;
	Gosu::Image bild_planet_2;
	GameWindow()
		: Window(1600, 1200),
		bild_rakete("rakete.png"),
		bild_planet_1("planet1.png"),
		bild_planet_2("planet2.png")
	{
		set_caption("Gosu Tutorial mit Git");
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	int x = 500;
	int y = 300;
	int xp1 = 400;
	int yp1 = 300;
	int xp2 = 1200;
	int yp2 = 500;
	int rpos1 = 0;
	int x2 = 1200;
	int y2 = 600;
	void draw() override
	{
		bild_planet_1.draw_rot(xp1, yp1, 0.0, 0.0, 0.5, 0.5);
		bild_planet_2.draw_rot(xp2, yp2, 0.0, 0.0, 0.5, 0.5);
		if (rpos1 = 0) {
			bild_rakete.draw_rot(x, y, 1, a, 20, 0.5);

			rpos1 = 1;
		}
		else {
			bild_rakete.draw_rot(x2, y2, 1, a, -20, 0.5);

			rpos1 = 0;
		}


	}

	// Wird 60x pro Sekunde aufgerufen
	double a = 0;
	double b = 0;

	void update() override
	{
		a = (a + 1);
		b = input().mouse_y();

	}
};

// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}
