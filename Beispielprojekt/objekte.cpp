
#include "objekte.h"


class objekte : public GameWindow
{
public:

	int x_achse;
	int y_achse;
	int z_achse;
	int x_spiegelung;
	int y_spiegelung;
	Gosu::Image bild;

	objekte() {}
	objekte(bild.draw_rot(x_achse, y_achse, z_achse, 0, 0, 0, x_spiegelung, y_spiegelung)) :
};

class autos : public objekte
{

};

