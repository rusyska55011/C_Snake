#pragma once

typedef struct fruit {
	int position_y;
	int position_x;
	unsigned char fruit_symbol;
	unsigned score_gift;
} fruit;

typedef struct mega_fruit {
	fruit;
	unsigned self_destroy_time;
	unsigned reload_time;
} mega_fruit;

fruit* create_fruit(const position_y, const position_x, const unsigned char fruit_symbol, unsigned score_gift);

mega_fruit* create_mega_fruit(const position_y, const position_x, const unsigned char megas_fruit_symbol, unsigned score_gift, unsigned destroy_time, unsigned unsigned reload_time);

void destroy_fruit(fruit* this_fruit);

void destroy_mega_fruit(mega_fruit* this_mega_fruit);

#define destroy_any_fruit(obj) _Generic((obj), \
	fruit*: destroy_fruit,                     \
	mega_fruit*: destroy_mega_fruit,           \
	default: destroy_fruit                     \
)(obj)