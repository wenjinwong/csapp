/* Thread routine for psum-local.c */

void *sum_local(void *vargp) {
	long myid = *((long *)vargp);
	long start = myid * nelems_per_thread;
	long end = start + nelems_per_thread;
	long i, sum = 0;

	for(i = start; i < end; ++i) 
		sum += i;
	psum[myid] = sum;
	return NULL;
}
