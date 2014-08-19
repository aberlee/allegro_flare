#ifndef __AF_GRID2D_HEADER
#define __AF_GRID2D_HEADER




#include <vector>
#include <allegro_flare/vec2d.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

#include <allegro_flare/color.h>



class grid2d
{
protected:
	std::vector<float> horizontal_guide;
	std::vector<float> vertical_guide;

public:
	grid2d();

	void add_horizontal_guide(float x);
	void add_vertical_guide(float y);

	float get_max_horizontal_guide();
	float get_max_vertical_guide();
	float get_min_horizontal_guide();
	float get_min_vertical_guide();

	int get_closest_horizontal_guide_index(float x, float threshold = 15);
	int get_closest_vertical_guide_index(float y, float threshold = 15);

	float get_horizontal_guide_pos(int index);
	float get_vertical_guide_pos(int index);

	vec2d get_closest_coordinates(float x, float y, float threshold = 15);

	void draw_guides(ALLEGRO_COLOR color=color::black);
	void draw_guide_numbers(ALLEGRO_FONT *font, float padding=10, ALLEGRO_COLOR color=color::black);
};





#endif