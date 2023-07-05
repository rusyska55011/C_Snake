#include "fruit.h"
#include <stdlib.h>

fruit* create_fruit(const position_y, const position_x, const unsigned char fruit_symbol, unsigned score_gift) {
	fruit* new_fruit = (fruit*)malloc(sizeof(fruit));
	
	new_fruit->position_y = position_y;
	new_fruit->position_x = position_x;
	new_fruit->fruit_symbol = fruit_symbol;
	new_fruit->score_gift = score_gift;

	return new_fruit;
}

mega_fruit* create_mega_fruit(const position_y, const position_x, const unsigned char megas_fruit_symbol, unsigned score_gift, unsigned destroy_time, unsigned unsigned reload_time) {
	mega_fruit* new_mega_fruit = (mega_fruit*)malloc(sizeof(mega_fruit));

	new_mega_fruit->position_y = position_y;
	new_mega_fruit->position_x = position_x;
	new_mega_fruit->fruit_symbol = megas_fruit_symbol;
	new_mega_fruit->score_gift = score_gift;

	new_mega_fruit->self_destroy_time = destroy_time;
	new_mega_fruit->reload_time = reload_time;

	return new_mega_fruit;
}

void destroy_fruit(fruit* this_fruit) {
	free((fruit*)this_fruit);
}

void destroy_mega_fruit(mega_fruit* this_mega_fruit) {
	free((mega_fruit*)this_mega_fruit);
}

const* get_fruit_y(fruit* this_fruit) {
	return this_fruit->position_y;
}

const* get_mega_fruit_y(mega_fruit* this_fruit) {
	return this_fruit->position_y;
}

const* get_fruit_x(fruit* this_fruit) {
	return this_fruit->position_x;
}

const* get_mega_fruit_x(mega_fruit* this_fruit) {
	return this_fruit->position_y;
}