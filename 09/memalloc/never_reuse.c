#include<unistd.h>

void *ptr = NULL;
void* alloc(int size) {
	ptr = sbrk(size);
	return ptr;
}
void myfree(void *p) {
}

int main() {
	alloc(5);
	alloc(10);
	alloc(200);
	alloc(102400);
	myfree(ptr);
}
