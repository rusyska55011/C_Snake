#include "fruit.h"
#include <stdlib.h>

fruit* create_fruit(const position_y, const position_x, const unsigned char fruit_symbol) {
	fruit* new_fruit = (fruit*)malloc(sizeof(fruit));
	
	new_fruit->position_y = position_y;
	new_fruit->position_x = position_x;
	new_fruit->fruit_symbol = fruit_symbol;

	return new_fruit;
}

mega_fruit* create_mega_fruit(const position_y, const position_x, const unsigned char megas_fruit_symbol, unsigned destroy_time) {
	mega_fruit* new_mega_fruit = (mega_fruit*)malloc(sizeof(mega_fruit));

	new_mega_fruit->position_y = position_y;
	new_mega_fruit->position_x = position_x;
	new_mega_fruit->fruit_symbol = megas_fruit_symbol;
	new_mega_fruit->destroy_time = destroy_time;

	return new_mega_fruit;
}