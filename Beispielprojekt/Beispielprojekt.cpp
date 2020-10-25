#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

using namespace std;

// Simulationsgeschwindigkeit
const double DT = 100.0;
//
class GameWindow : public Gosu::Window
{
public:
	Gosu::Image bild_hintergrund;
	Gosu::Image bild_auto_türkis;
	Gosu::Image bild_oma_steht;
	Gosu::Image bild_oma_schritt1;
	Gosu::Image bild_oma_schritt2;
	Gosu::Image bild_Lebensanzeige;
	GameWindow()
		: Window(1920, 1080),
		bild_hintergrund("Hintergrund.png"),
		bild_auto_türkis("auto_tuerkis.png"),
		bild_oma_steht("oma_steht.png"),
		bild_oma_schritt1("oma_schritt1.png"),
		bild_oma_schritt2("oma_schritt2.png"),
		bild_Lebensanzeige("Lebensanzeigebasic.png")
	{
		set_caption("Gosu Tutorial mit Git");
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	int x_Auto1 = 2000;
	int x_Auto2 = -150;
	int x_oma1 = 2000;
	int y_Oberespur = 620;
	int y_Unterespur = 800;
	int y_gehweg = 430;
	int status = 12;
	
	void draw() override
	{
		bild_hintergrund.draw_rot(0, 0, 0, 0, 0, 0);

		bild_Lebensanzeige.draw_rot(0, 0, 1, 0,0,0);

		bild_auto_türkis.draw_rot(x_Auto1, y_Oberespur, 2, 0, 0, 0, 1, 1);
		
		bild_auto_türkis.draw_rot(x_Auto2, y_Unterespur, 3, 0, 0, 0, -1, 1);
		
			if (status >= 12) {
				bild_oma_steht.draw_rot(x_oma1, y_gehweg, 1, 0, 0, 0);
				status -= 1;
			}
			else if (status >= 9) {
				bild_oma_schritt1.draw_rot(x_oma1, y_gehweg, 1, 0, 0, 0);
				status -= 1;
			}
			else if (status >= 6) {
				bild_oma_steht.draw_rot(x_oma1, y_gehweg, 1, 0, 0, 0);
				status -= 1;
			}
			else if (status >= 3) {
				bild_oma_schritt2.draw_rot(x_oma1, y_gehweg, 1, 0, 0, 0);
				status = 12;
			}

	}

	// Wird 60x pro Sekunde aufgerufen
	
	void update() override
	{
		x_Auto1 = (x_Auto1 - 8);
		if (x_Auto1 < -400) {
			x_Auto1 = 2000;
		}
		x_Auto2 = (x_Auto2 + 10);
		if (x_Auto2 > 2500) {
			x_Auto2 = -300;
		}
		x_oma1 = (x_oma1 - 2);
		if (x_oma1 < -300) {
			x_oma1 = 2000;
		}

	}
};

// C++ Hauptprogramm
int main()
{
	
	GameWindow window;
	window.show();
	
}
