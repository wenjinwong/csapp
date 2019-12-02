#include <stdlib.h>
#include<assert.h>

#define IDENT 1
#define OP *
typedef long data_t;
typedef struct {
	long len;
	data_t *data;
} vec_rec, *vec_ptr;

vec_ptr new_vec(long len) {
	/* allocate header structure */
	vec_ptr result = (vec_ptr)malloc(sizeof(vec_rec));
	data_t *data = NULL;
	if(!result) 
		return NULL; /* Couldn't allocate storage */
	result->len = len;
	/* Allocate array */
	if(len > 0) {
		data = (data_t *)calloc(len, sizeof(data_t));
		if(!data){
			free((void *) result);
			return NULL;
		}
	}
	/* Data will either be NULL or allocated array */
	result->data = data;
	return result;
}

/*
 * Retrieve vector element and store at dest.
 * Return 0 (out of bounds) or 1 (successful)
 */

int get_vec_element(vec_ptr v, long index, data_t *dest) {
	if(index < 0 || index >= v->len)
		return 0;
	*dest = v->data[index];
	return 1;
}

/*
 * Return length of vector 
 */
long vec_length(vec_ptr v) {
	return v->len;
}

data_t *get_vec_start(vec_ptr v) {
	return v->data;
}

void combine1(vec_ptr v, data_t *dest) {
	long i;

	*dest = IDENT;
	for(i = 0; i < vec_length(v); i++) {
		data_t val;
		get_vec_element(v, i, &val);
		*dest = *dest OP val;
	}
}

void combine2(vec_ptr v, data_t *dest) {
	long i;
	long len = vec_length(v);
	*dest = IDENT;
	for(i = 0; i < len; i++) {
		data_t val;
		get_vec_element(v, i, &val);
		*dest = *dest OP val;
	}
}

void combine3(vec_ptr v, data_t *dest) {
	long i;
	long length = vec_length(v);
	data_t *data = get_vec_start(v);
	*dest = IDENT;
	for(i = 0; i < length; i++) {
		*dest = *dest OP data[i];
	}
}

void combine4(vec_ptr v, data_t *dest) {
	long i;
	long length = vec_length(v);
	data_t *data = get_vec_start(v);
	data_t acc = IDENT;

	for(i = 0; i < length; i++) {
		acc = acc OP data[i];
	}
	*dest = acc;
}


void combine5(vec_ptr v, data_t *dest) {
	long i;
	long length = vec_length(v);
	long limit = length - 7;
	data_t *data = get_vec_start(v);
	data_t acc = IDENT;

	/* Combine 5 elements at a time */
	for(i = 0; i < limit; i+=5) {
		// TODO
		acc = (acc OP data[i]) OP data[i+1] OP data[i+2] 
				OP data[i+3] OP data[i+4];
	}

	for(; i < length; i++) {
		acc = acc OP data[i];
	}
	*dest = acc;
}


int main() {
	vec_ptr vec = new_vec(1000);
	for(int i = 0; i < 1000; i++) {
		vec->data[i] = i;
	}
	data_t *dest;
	
	combine1(vec, dest);
	vec_ptr ptr = new_vec(100);
	assert(vec_length(ptr) == 100);
}
