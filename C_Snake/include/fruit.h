#pragma once

typedef struct fruit {
	int position_y;
	int position_x;
	unsigned char fruit_symbol;
} fruit;

typedef struct mega_fruit {
	fruit;
	unsigned destroy_time;
} mega_fruit;

