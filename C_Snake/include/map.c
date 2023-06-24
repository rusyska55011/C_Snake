#include "map.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool** get_new_area_map(const unsigned sizeY, const unsigned sizeX) {

	bool** new_area = malloc(sizeof(bool) * sizeY);

	for (int y = 0; y < sizeY; y++) {
		new_area[y] = malloc(sizeof(bool) * sizeX);
		for (int x = 0; x < sizeX; x++) {
			new_area[y][x] = false;
		}
	}

	return new_area;
}

map create_map(const unsigned sizeY, const unsigned sizeX) {
	map new_map = { sizeY, sizeX, get_new_area_map(sizeY, sizeX) };
	return new_map;
}
