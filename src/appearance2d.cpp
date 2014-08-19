

#include <allegro_flare/appearance2d.h>
#include <allegro_flare/useful.h> // for tostring()





appearance2d::appearance2d()
	: color(al_map_rgba_f(1,1,1,1))
	, blender(BLENDER_NORMAL)
	, opacity(1)
{ }



void appearance2d::clear()
{
	color = al_map_rgba_f(1,1,1,1);
	opacity = 1;
	blender = BLENDER_NORMAL;
}
