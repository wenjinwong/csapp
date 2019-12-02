#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct node{
	struct node* next;
	int size;
	void *ptr;
} table_node;
struct table{
	struct table* head, *tail;
};
void first_fit(struct table table, int size) {
	while(table) {
		if(table.size >= size)
			return table.ptr;
		break;
		table = table->next;
	}
}

void next_fit() {
	return nex;

}

void the_best_fit(tabl) {
	for_each i in table
		select the best_fit;
}
int main() {

