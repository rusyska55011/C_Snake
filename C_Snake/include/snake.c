#include "snake.h"
#include "stdlib.h"

#include "../my_library/mylist.h"


void push_back_snake_element(list* this_snake, const int position_y, const int position_x) {
	int* new_xy_area = (int*)malloc(2);
	new_xy_area[0] = position_y;
	new_xy_area[1] = position_x;
	
	append_node(this_snake, new_xy_area);
}

void delete_back_snake_element(list* this_snake, const int index) {
	int* element_data = (int*)get_node_data(this_snake, index);
	delete_node(this_snake, index);
	free(element_data);
}

int get_snake_len(list* this_snake) {
	return get_list_count(this_snake);
}

int* get_element_yx(list* this_list, const int index) {
	return (int*)get_node_data(this_list, index);
}

list* create_snake(const int position_y, const int position_x) {
	list* new_snake = new_list();
	
	push_back_snake_element(new_snake, position_y, position_x);
	
	return new_snake;
}