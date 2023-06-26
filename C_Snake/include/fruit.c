#include "fruit.h"
#include <stdlib.h>

fruit* create_fruit(const position_y, const position_x, const unsigned char fruit_symbol) {
	fruit* new_fruit = (fruit*)malloc(sizeof(fruit));
	
	new_fruit->position_y = position_y;
	new_fruit->position_x = position_x;
	new_fruit->fruit_symbol = fruit_symbol;

	return new_fruit;
}