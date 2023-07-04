#include "map.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../my_library/mylist.h"

#define MAP_DEFAULT_SYMBOL '8'

list* create_new_map(const unsigned size_y, const unsigned size_x) {
	list* map = new_list();

	for (unsigned y = 0; y < size_y; y++) {
		append_node(map, new_list());
		for (unsigned x = 0; x < size_x; x++) {
			append_node(get_node_data(map, y), (unsigned char)MAP_DEFAULT_SYMBOL);
		}
	}
	return map;
}

unsigned char get_map_pixel(const list* map, const y, const x) {
	return get_node_data(get_node_data(map, y), x);
}

const unsigned* get_map_size_y(list* map) {
	return &map->count;
}

const unsigned* get_map_size_x(list* map) {
	return &((list*)get_node_data(map, 0))->count;
}

void show_map(list* map) {
	const unsigned map_size_y = *get_map_size_y(map);
	const unsigned map_size_x = *get_map_size_x(map);

	for (unsigned y = 0; y < map_size_y; y++) {
		for (unsigned x = 0; x < map_size_x; x++) {
			printf(" %c", get_map_pixel(map, y, x));
		}
		printf("\n");
	}

}

void change_map_pixel(const list* map, const y, const x, const unsigned char new_symbol) {
	rewrite_node_data(get_node_data(map, y), x, new_symbol);
}

void set_default_map_pixel(const list* map, const y, const x) {
	change_map_pixel(map, y, x, MAP_DEFAULT_SYMBOL);
}

void cls_map(const list* map) {
	for (unsigned y = 0; y < *get_map_size_y(map); y++) {
		for (unsigned x = 0; x < *get_map_size_x(map); x++) {
			change_map_pixel(map, y, x, MAP_DEFAULT_SYMBOL);
		}
	}
}