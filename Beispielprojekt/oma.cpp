#include "stdafx.h"
#include "oma.h"

void oma::move(Gosu::Image img1, Gosu::Image img2, Gosu::Image img3,Gosu::Image img4)
{
	if (input().down(Gosu::KB_D) || input().down(Gosu::KB_W) || input().down(Gosu::KB_S) || input().down(Gosu::KB_A)) {
		if (status >= 20) {
			img1.draw_rot(position_x, position_y, 5, 0, 1, 0, -1, 1);
			status -= 1;
		}
		else if (status >= 15) {
			img2.draw_rot(position_x, position_y, 5, 0, 1, 0, -1, 1);
			status -= 1;
		}
		else if (status >= 10) {
			img1.draw_rot(position_x, position_y, 5, 0, 1, 0, -1, 1);
			status -= 1;
		}
		else if (status >= 5) {
			img3.draw_rot(position_x, position_y, 5, 0, 1, 0, -1, 1);
			status = 20;
		}
	}
	else {
		img1.draw_rot(position_x, position_y, 5, 0, 1, 0, -1, 1);
	}
}