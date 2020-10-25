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
	Gosu::Image bild_hintergrund;
	GameWindow()
		: Window(1920, 1080),
		bild_hintergrund("Hintergrund.png")
	{
		set_caption("Gosu Tutorial mit Git");
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	int x = 0;
	int y = 0;

	void draw() override
	{
		bild_hintergrund.draw_rot(0, 0, 0, 0, 0, 0);

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
