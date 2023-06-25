#include "map.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../my_library/mylist.h"

#define GET_MAP_INDEX(map, y, x) ( get_node_data(get_node_data(map, y), x) )

list* create_new_map(const unsigned size_y, const unsigned size_x) {
	list* map = new_list();

	for (unsigned y = 0; y < size_y; y++) {
		append_node(map, new_list());
		for (unsigned x = 0; x < size_x; x++) {
			append_node(get_node_data(map, y), 0);
		}
	}
	return map;
}

int get_map_pixel(const list* map, const y, const x) {
	return GET_MAP_INDEX(map, y, x);
}

unsigned get_map_size_y(list* map) {
	return map->count;
}

unsigned get_map_size_x(list* map) {
	list* first_map_value = get_node_data(map, 0); // Поскольку функция возвращает *void, компилятор ругается что это не може быть структура. Через присваивание (list*) тоже.
	return first_map_value->count;
}

void show_map(list* map) {
	const unsigned map_size_y = get_map_size_y(map);
	const unsigned map_size_x = get_map_size_x(map);

	for (unsigned y = 0; y < map_size_y; y++) {
		for (unsigned x = 0; x < map_size_x; x++) {
			int map_element = get_map_pixel(map, y, x);
			if (!map_element)
				printf("0 ");
			else
				printf("1 ");
		}
		printf("\n");
	}

}