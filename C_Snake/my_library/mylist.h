#pragma once

typedef struct list_node {
	void* data;
	struct list_node* prev;
	struct list_node* next;
} list_node;

typedef struct list {
	unsigned count;
	list_node* last;
	list_node* first;
} list;


list* new_list();

int get_list_count(list* this_list);

void* get_node_data(const list* this_list, const signed index);

void append_node(list* this_list, const void* new_data);

void delete_node(const list* this_list, const signed index);

void rewrite_node_data(const list* this_list, const signed index, void* new_data);

void destroy_list(list* this_list);