#pragma once
#include <stdbool.h>
#include "../my_library/mylist.h"

typedef struct map {
	const unsigned sizeY;
	const unsigned sizeX;
	const _Bool** area;
} map;

list* create_new_map(const unsigned size_y, const unsigned size_x);

get_map_pixel(list* map, const y, const x);

unsigned get_map_size_y(list* map);

unsigned get_map_size_x(list* map);

void show_map(list* map);