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
	Gosu::Image bild_hintergrund;
	Gosu::Image bild_auto_türkis;
	Gosu::Image bild_auto_rot;
	Gosu::Image bild_auto_rot2;
	GameWindow()
		: Window(1920, 1080),
		bild_hintergrund("Hintergrund.png"),
		bild_auto_türkis("auto_tuerkis.png"),
		bild_auto_rot("auto_rot.png")
		bild_auto_rot("auto_rot2.png")
	{
		set_caption("Gosu Tutorial mit Git");
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	int x = 2000;
	int y = 750;
	int z = 2000;
	int o = 2000;
	void draw() override
	{
		bild_hintergrund.draw_rot(0, 0, 0, 0, 0, 0);
		bild_auto_türkis.draw_rot(x, y, 0, 0, 0, 0);
		bild_auto_rot.draw_rot(z+1000, y, 0, 0, 0, 0);
		bild_auto_rot2.draw_rot(o + 1000, y, 0, 0, 0, 0);
	}

	// Wird 60x pro Sekunde aufgerufen
	double a = 0;
	double b = 0;

	void update() override
	{
		x = (x - 5);
			if (x < -1500) {
				x = 3000;
			}

			z = (z - 5);
			if (z < -1500) {
				x = 3000;
			

			x = (x - 5);
			if (x < -1500) {
				x = 3000;
			}

		b = input().mouse_y();

	}
};

// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}
