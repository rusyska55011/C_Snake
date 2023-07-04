#include "mylist.h"

#include <stdlib.h>
#include <limits.h>

int convert_beyond_index(signed index, const unsigned node_count) {
	const unsigned max_index = node_count - 1;

	if (index < 0) {
		while (index < 0)
			index = index + max_index + 1;
	}

	if (index > (signed)max_index)
		index %= max_index + 1;

	return index;
}

list* new_list() {
	list* new_list_obj = (list*)malloc(sizeof(list));

	new_list_obj->count = 0;
	new_list_obj->first = NULL;
	new_list_obj->last = NULL;

	return new_list_obj;
}

int get_list_count(list* this_list) {
	return this_list->count;
}

list_node* get_node(const list* this_list, signed index) {
	int converted_index = convert_beyond_index(index, this_list->count);
	const unsigned max_index = this_list->count - 1;

	list_node* node = NULL;
	if (max_index / 2 >= converted_index) {
		node = this_list->first;
		for (int i = 0; i < converted_index; i++)
			node = node->next;
	}
	else {
		node = this_list->last;
		for (int i = max_index; i > converted_index; i--)
			node = node->prev;
	}

	return node;
}

void* get_node_data(const list* this_list, const signed index) {
	return get_node(this_list, index)->data;
}

void append_node(list* this_list, const void* new_data) {
	list_node* new_node = (list_node*)malloc(sizeof(list_node));
	
	new_node->data = new_data;
	new_node->next = NULL;

	if (!this_list->count) {
		this_list->first = new_node;
		new_node->prev = NULL;

	} else {
		new_node->prev = this_list->last;
		this_list->last->next = new_node;

	}

	this_list->count++;
	this_list->last = new_node;
}

void delete_node(list* this_list, const signed index) {
	if (!this_list->count)
		return;

	list_node* deleted_node = get_node(this_list, index);

	list_node* next_node = deleted_node->next;
	list_node* prev_node = deleted_node->prev;

	if (this_list->count == 1) {
		this_list->first == NULL;
		this_list->last == NULL;
	}
	else if (this_list->first == deleted_node) {
		next_node->prev = deleted_node->prev;
		this_list->first = next_node;
	}
	else if (this_list->last == deleted_node) {
		prev_node->next = deleted_node->next;
		this_list->last = prev_node;
	}
	else {
		next_node->prev = deleted_node->prev;
		prev_node->next = deleted_node->next;
	}

	this_list->count--;

	free(deleted_node);
}

void rewrite_node_data(const list* this_list, const signed index, const void* new_data) {
	get_node(this_list, index)->data = new_data;
}