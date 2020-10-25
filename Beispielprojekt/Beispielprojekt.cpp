#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include <vector>
#include <string>
#include <iostream>
using namespace std;



// Simulationsgeschwindigkeit
const double DT = 100.0;




class GameWindow : public Gosu::Window
{
public:
	Gosu::Image bild_hintergrund;
	Gosu::Image bild_auto_türkis;
	Gosu::Image bild_auto_türkis2;
	Gosu::Image bild_Oma1;
	GameWindow()
		: Window(1920, 1080),
		bild_hintergrund("Hintergrund.png"),
		bild_auto_türkis("auto_tuerkis.png"),
		bild_Oma1("Oma1.png"),
		bild_auto_türkis2("auto_tuerkis2.png")
	{
		set_caption("Gosu Tutorial mit Git");
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	int x_Auto1 = 2000;
	int x_Auto2 = -150;
	int x_Oma1 = 2000;
	int y_Oberespur = 640;
	int y_Unterespur = 800;
	int y_Gehweg = 430;
	int omastatus = 3; // Variable, wo sich Oma in Animation befindet
	
	double c = (a % 2);
	

	void draw() override
	{
		bild_hintergrund.draw_rot(0, 0, 0, 0, 0, 0);
		if (c == 0) {
			bild_auto_türkis2.draw_rot(x_Auto1, y_Oberespur, 2, 0, 0, 0, 1, 1);
		}
		else if (c != 0) {
				bild_auto_türkis.draw_rot(x_Auto1, y_Oberespur, 2, 0, 0, 0, 1, 1);
		}

		/*
		if (omastatus == 3){
			bild_Oma1.draw_rot(x_Oma1, y_Gehweg, 1, 0, 0, 0, 1, 1);
			omastatus -= 1;
		}
		else if (omastatus == 2){
			bild_Oma2.draw_rot(x_Oma1, y_Gehweg, 1, 0, 0, 0, 1, 1);
			omastatus -= 1;
		}
		else if (omastatus == 1){
			bild_Oma1.draw_rot(x_Oma1, y_Gehweg, 1, 0, 0, 0, 1, 1);
			omastatus = 3;
		}
		else{*/ 
		bild_Oma1.draw_rot(x_Oma1, y_Gehweg, 1, 0, 0, 0, 1, 1);
		//}
		bild_auto_türkis.draw_rot(x_Auto2, y_Unterespur, 3, 0, 0, 0, -1, 1);
	}

	// Wird 60x pro Sekunde aufgerufen
	
	double b = 0;
	int a = 0;
	void update() override
	{
		x_Auto1 = (x_Auto1 - 8);
		if (x_Auto1 < -400) {
			x_Auto1 = 2000;
			a = a + 1;
		}
		x_Auto2 = (x_Auto2 + 10);
		if (x_Auto2 > 2500) {
			x_Auto2 = -300;
		}
		x_Oma1 = (x_Oma1 - 1);
		if (x_Oma1 < -300) {
			x_Oma1 = 2000;
		}

		b = input().mouse_y();

	}
};

// C++ Hauptprogramm
int main()
{
	cout << "Dein Name" << endl;

	GameWindow window;
	window.show();
	
	
}
