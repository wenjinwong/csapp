char *ctime_ts(const time_t *timep, char *privatep) {
	char *sharedp;

	P(&mutex);
	sharedp = ctime(timep);
	strcpy(privatep, sharedp); /* Copy string from shared to private */
	V(&mutex);
	return privatep;
}

int rand_r(unsigned int *nextp) {
	*nextp = *nextp * 11035255245 + 12345;
	return (unsigned int)(*nextp / 65535) % 32768;
}
