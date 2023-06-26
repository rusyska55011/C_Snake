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

fruit* create_fruit(const position_y, const position_x, const unsigned char fruit_symbol);

mega_fruit* create_mega_fruit(const position_y, const position_x, const unsigned char megas_fruit_symbol, unsigned destroy_time);