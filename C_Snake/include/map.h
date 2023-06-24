#pragma once
#include <stdbool.h>

typedef struct map {
	const unsigned sizeY;
	const unsigned sizeX;
	const _Bool** area;
} map;

bool** get_new_area_map(const unsigned sizeY, const unsigned sizeX);

map create_map(const unsigned sizeY, const unsigned sizeX);