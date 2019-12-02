#ifdef COMPILETIME
#include <stdio.h>
#include <malloc.h>

/* Malloc wrapper function */
void *mymalloc(size_t size) {
	void *ptr = malloc(size);
	printf("malloc(%d) = %p\n", (int)size, ptr);
	return ptr;
}

/* Free wrapper function */
void myfree(void *ptr) {
	free(ptr);
	printf("free(%p)\n", ptr);
}

#endif

#ifdef LINKTIME
#include <stdio.h>
#include<stdlib.h>
void *__real_malloc(size_t size);
void *__real_free(void *ptr);

void *__wrap_malloc(size_t size) {
	void *ptr = _malloc(size);
	printf("malloc(%d) = %p\n", (int)size, ptr);
	return ptr;
}

void __wrap_free(void *ptr) {
	free(ptr);
	printf("free(%p)\n", ptr);
}

#endif

#ifdef RUNTIME
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

/* malloc wrapper function */
void *malloc(size_t size) {
	void *(*mallocp)(size_t size);
	char *error;

	mallocp = dlsym(RTLD_NEXT, "malloc"); /* Get address of libc malloc */
	if((error = dlerror()) != NULL) {
		fputs(error, stderr);
		exit(1);
	}

	char *ptr = mallocp(size); /* Call libc malloc */
	printf("malloc(%d) = %p\n", (int)size, ptr);
	return ptr;
}

/* free wrapper function */
void free(void *ptr) {
	void (*freep)(void *) = NULL;
	char *error;

	if(!ptr) {
		return;
	}

	freep = dlsym(RTLD_NEXT, "free");
	if((error = dlerror()) != NULL) {
		fputs(error, stderr);
		exit(1);
	}

	freep(ptr); /* Call libc free */
	printf("free(%p)\n");
}
#endif
