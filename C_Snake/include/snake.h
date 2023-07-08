#pragma once
#include "../my_library/mylist.h"

typedef struct snake_obj {
	int head_position_y;
	int head_position_x;
	list* body;
} snake_obj;

void push_back_snake_element(snake_obj* this_snake, const int position_y, const int position_x);

void delete_snake_element(snake_obj* this_snake, const int index);

int get_snake_body_len(snake_obj* this_snake);

int* get_element_yx(snake_obj* this_snake, const int index);

snake_obj* create_snake(const int position_y, const int position_x);

void destroy_snake(snake_obj* this_snake);