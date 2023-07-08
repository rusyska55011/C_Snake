#include "snake.h"
#include <stdlib.h>

void push_back_snake_element(snake_obj* this_snake, const int position_y, const int position_x) {
	int* new_xy_area = (int*)malloc(sizeof(int) * 2);
	new_xy_area[0] = position_y;
	new_xy_area[1] = position_x;

	append_node(this_snake->body, new_xy_area);
}
#include <stdlib.h>
void delete_snake_element(snake_obj* this_snake, const int index) {
	if (this_snake->body->count) {
		int* element_data = (int*)get_node_data(this_snake->body, index);
		delete_node(this_snake->body, index);
		free(element_data);
	}
}

int get_snake_body_len(snake_obj* this_snake) {
	return get_list_count(this_snake->body);
}

int* get_element_yx(snake_obj* this_snake, const int index) {
	return (int*)get_node_data(this_snake->body, index);
}

snake_obj* create_snake(const int position_y, const int position_x) {
	snake_obj* new_snake = (snake_obj*)malloc(sizeof(snake_obj));

	new_snake->head_position_y = position_y;
	new_snake->head_position_x = position_x;
	new_snake->body = new_list();

	return new_snake;
}

void destroy_snake(snake_obj* this_snake) {
	int snake_body_len = get_snake_body_len(this_snake);
	while (snake_body_len--)
		delete_snake_element(this_snake, 0);

	destroy_list(this_snake->body);
	free(this_snake);
}