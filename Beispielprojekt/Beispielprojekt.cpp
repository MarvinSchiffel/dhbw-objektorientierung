#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "oma.h"

using namespace std;

// Simulationsgeschwindigkeit
const double DT = 100.0;
//
class GameWindow : public Gosu::Window
{
	oma*oma1;

public:
	//Allgemein
	Gosu::Image bild_Lebensanzeige_0;
	Gosu::Image bild_Lebensanzeige_1;
	Gosu::Image bild_Lebensanzeige_2;
	Gosu::Image bild_Lebensanzeige_3;
	Gosu::Image bild_oma_steht;
	Gosu::Image bild_oma_schritt1;
	Gosu::Image bild_oma_schritt2;
	//level Intro
	Gosu::Image bild_straßenbild;
	Gosu::Image bild_auto_türkis;
	Gosu::Image bild_auto_türkis2;
	Gosu::Image bild_auto_rot;
	Gosu::Image bild_auto_rot2;
	//level 1
	Gosu::Image bild_level1;
	Gosu::Image bild_auto1;
	Gosu::Image bild_polizeiauto;
	//level 2
	Gosu::Image bild_level2;
	//Test

	//Bildnamen mit Bilddaten initialisieren
	GameWindow() : Window(1920, 1080),
		//Algemein
		/*
		bild_oma_steht("bilder/oma_steht.png"),
		bild_oma_schritt1("bilder/oma_schritt1.png"),
		bild_oma_schritt2("bilder/oma_schritt2.png"),
		*/
		bild_Lebensanzeige_0("bilder/Lebensanzeige_0.png"),
		bild_Lebensanzeige_1("bilder/Lebensanzeige_1.png"),
		bild_Lebensanzeige_2("bilder/Lebensanzeige_2.png"),
		bild_Lebensanzeige_3("bilder/Lebensanzeige_3 (3).png"),
		// Intro
		bild_straßenbild("bilder/strassenbild.png"),
		bild_auto_türkis("bilder/auto_tuerkis.png"),
		bild_auto_türkis2("bilder/auto_tuerkis2.png"),
		bild_auto_rot("bilder/auto_rot.png"),
		bild_auto_rot2("bilder/auto_rot2.png"),
		//level 1
		bild_level1("bilder/level1.png"),
		bild_auto1("bilder/auto1.png"),
		bild_polizeiauto("bilder/polizeiauto.png"),
		//level 2
		bild_level2("bilder/Mashalla.png")
	{
		set_caption("Safe the Granny");
		oma oma1(float x_oma, float y_oma);
		oma1.move(Gosu::Image("bilder/oma_steht.png"), Gosu::Image("bilder/oma_schritt1.png"), Gosu::Image("bilder/oma_schritt2.png");
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	
	//Allgemein
	int level_counter = 1;
	//Oma
	double x_oma = 0;
	double y_oma = 450;
	double v_oma = 8;
	int status = 20;

	//level Intro
	int x_auto1 = 2000;
	int x_auto2 = -150;
	int y_Oberespur = 620;
	int y_Unterespur = 830;
	int y_gehweg = 430;

	//level 1
	int x_spur1 = 240;
	int x_spur2 = 500;
	int y_f1 = -500;
	int y_f2 = -500;
	
	//Aufruf von draw Funktionen
	void draw() override
	{
		//Lebensanzeige
		bild_Lebensanzeige_3.draw_rot(0, 0, 2, 0, 0, 0);

		//Oma bewegung vorwärts/hoch/runter
		/*
		if (input().down(Gosu::KB_D) || input().down(Gosu::KB_W) || input().down(Gosu::KB_S)|| input().down(Gosu::KB_A)) {
			if (status >= 20) {
				bild_oma_steht.draw_rot(x_oma, y_oma, 5, 0, 1, 0, -1, 1);
				status -= 1;
			}
			else if (status >= 15) {
				bild_oma_schritt1.draw_rot(x_oma, y_oma, 5, 0, 1, 0, -1, 1);
				status -= 1;
			}
			else if (status >= 10) {
				bild_oma_steht.draw_rot(x_oma, y_oma, 5, 0, 1, 0, -1, 1);
				status -= 1;
			}
			else if (status >= 5) {
				bild_oma_schritt2.draw_rot(x_oma, y_oma, 5, 0, 1, 0, -1, 1);
				status = 20;
			}
		}
		else {
			bild_oma_steht.draw_rot(x_oma, y_oma, 5, 0, 1, 0, -1, 1);
		}
		*/
		//Oma bewegung zurück
		/*else if (input().down(Gosu::KB_A) || input().down(Gosu::KB_A) && input().down(Gosu::KB_W) || input().down(Gosu::KB_A) && input().down(Gosu::KB_S)) {
			if (status >= 20) {
				bild_oma_steht.draw_rot(x_oma, y_oma, 5, 0, 1, 0, 1, 1);
				status -= 1;
				}
				else if (status >= 15) {
				bild_oma_schritt1.draw_rot(x_oma, y_oma, 5, 0, 1, 0, 1, 1);
				status -= 1;
				}
				else if (status >= 10) {
				bild_oma_steht.draw_rot(x_oma, y_oma, 5, 0, 1, 0, 1, 1);
				status -= 1;
				}
				else if (status >= 5) {
				bild_oma_schritt2.draw_rot(x_oma, y_oma, 5, 0, 1, 0, 1, 1);
				status = 20;
			}
		}

		*/

		//level intro
		if (level_counter == 1) {

			bild_straßenbild.draw_rot(0, 0, 1, 0, 0, 0);

			bild_auto_türkis.draw_rot(x_auto1, y_Oberespur, 3, 0, 0, 0, 1, 1);
			
			bild_auto_rot2.draw_rot(x_auto2, y_Unterespur, 4, 0, 0, 0, -1, 1);	

			if (x_oma >= 1980) {
				level_counter = 2;
				x_oma = 0;
			}
		}
		//level 1
		else if(level_counter == 2) {

			bild_level1.draw_rot(0, 0, 0, 0, 0, 0);

			bild_auto1.draw_rot(x_spur1, y_f1, 1, 0, 0, 0);

			bild_polizeiauto.draw_rot(x_spur2, y_f2, 1, 0, 0, 0);

			if (x_oma >= 1980) {
				level_counter = 3;
				x_oma = 0;
			}
		}
		else if (level_counter == 3) {
			bild_level2.draw_rot(0, 0, 0, 0, 0, 0);

			if (x_oma >= 1980) {
				level_counter = 1;
				x_oma = 0;
			}
		}

	}

	// Wird 60x pro Sekunde aufgerufen
	
	void update() override
	{
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
		//Level 1
		if (level_counter == 1) {
			x_auto1 = (x_auto1 - 8);
			if (x_auto1 < -400) {
				x_auto1 = 2000;
			}
			x_auto2 = (x_auto2 + 10);
			if (x_auto2 > 2300) {
				x_auto2 = -150;
			}
		}
		//Autos LvL 2
		else if (level_counter == 2) {
			y_f1 = (y_f1 + 5);
			if (y_f1 > 1200) {
				y_f1 = -500;
			}
			y_f2 = (y_f2 + 10);
			if (y_f2 > 1200) {
				y_f2 = -500;
			}
		}
	}
};

// C++ Hauptprogramm
int main()
{

	GameWindow window;
	window.show();
	
}
