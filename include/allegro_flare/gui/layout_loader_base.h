#ifndef __AF_LAYOUT_LOADER_BASE_HEADER
#define __AF_LAYOUT_LOADER_BASE_HEADER




#include <string>
#include <allegro_flare/gui/widget.h>




class UILayoutLoaderBase
{
public:
   virtual bool load_file(UIWidget *parent, std::string filename) = 0;
};




#endif
