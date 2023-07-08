#pragma once
#include "../my_library/mylist.h"

typedef struct snake {
	int head_position_y;
	int head_position_x;
	list* body;
} snake;

void push_back_snake_element(list* this_snake, const int position_y, const int position_x);

void delete_back_snake_element(list* this_snake, const int index);

int get_snake_len(list* this_snake);

int* get_element_yx(list* this_list, const int index);

list* create_snake(const int position_y, const int position_x);