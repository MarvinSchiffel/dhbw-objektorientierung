#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "objekte.h"

using namespace std;

// Simulationsgeschwindigkeit
const double DT = 100.0;
//
class GameWindow : public Gosu::Window
{
public:

	
	//Bildnamen initialisieren
	Gosu::Image bild_karohintergrund;
	Gosu::Image bild_straßenbild;
	Gosu::Image bild_auto_türkis;
	Gosu::Image bild_auto_türkis2;
	Gosu::Image bild_auto_rot;
	Gosu::Image bild_oma_steht;
	Gosu::Image bild_oma_schritt1;
	Gosu::Image bild_oma_schritt2;
	Gosu::Image bild_Lebensanzeige;
	
	//Bildnamen mit Bilddaten initialisieren
	GameWindow() : Window(1920, 1080),
		bild_karohintergrund("karohintergrund.png"),
		bild_straßenbild("strassenbild.png"),
		bild_auto_türkis("auto_tuerkis.png"),
		bild_auto_türkis2("auto_tuerkis2.png"),
		bild_auto_rot("auto_rot.png"),
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
	double x_oma = 0;
	double y_oma = 0;
	double v_oma = 5;

	int y_Oberespur = 620;
	int y_Unterespur = 800;
	int y_gehweg = 430;
	int status = 20;
	int status_auto1 = 20;
	
	//Aufruf von draw Funktionen
	void draw() override
	{
		bild_karohintergrund.draw_rot(0, 0, 0, 0, 0, 0);

		bild_straßenbild.draw_rot(0, 0, 1, 0, 0, 0);

		bild_Lebensanzeige.draw_rot(0, 0, 2, 0,0,0);

		bild_auto_türkis.draw_rot(x_Auto1, y_Oberespur, 3, 0, 0, 0, 1, 1);

		bild_auto_türkis2.draw_rot(x_Auto1, y_Oberespur, 3, 0, 0, 0, 1, 1);
		
		bild_auto_rot.draw_rot(x_Auto2, y_Unterespur, 4, 0, 0, 0, -1, 1);

		if (input().down(Gosu::KB_S) || input().down(Gosu::KB_W) || input().down(Gosu::KB_D) || input().down(Gosu::KB_A)) {
			if (status >= 20) {
				bild_oma_steht.draw_rot(x_oma, y_oma, 1, 0, 1, 0,-1,1);
				status -= 1;
			}
			else if (status >= 15) {
				bild_oma_schritt1.draw_rot(x_oma, y_oma, 1, 0, 1, 0,-1,1);
				status -= 1;
			}
			else if (status >= 10) {
				bild_oma_steht.draw_rot(x_oma, y_oma, 1, 0, 1, 0,-1,1);
				status -= 1;
			}
			else if (status >= 5) {
				bild_oma_schritt2.draw_rot(x_oma, y_oma, 1, 0, 1, 0,-1,1);
				status = 20;
			}
			
		}
		else {
			bild_oma_steht.draw_rot(x_oma, y_oma, 1, 0, 1, 0, -1, 1);
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
			x_Auto2 = 2000;
		}
		//Oma läuft nach unten
		if (input().down(Gosu::KB_S)) {
			y_oma += v_oma;
		}
		//Oma läuft nach oben
		if (input().down(Gosu::KB_W)) {
			y_oma -= v_oma;
		}
		//Oma läuft vorwärts
		if (input().down(Gosu::KB_D)) {
			x_oma += v_oma;
		}
		//Oma läuft rückwärts
		if (input().down(Gosu::KB_A)) {
			x_oma -= v_oma;
		}

		

	}
};

// C++ Hauptprogramm
int main()
{
	
	GameWindow window;
	window.show();
	
}
