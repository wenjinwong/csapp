#include "csapp.h"

int readcnt;
set_t mutex, w;	/* Both initially = 1 */

void reader(void) {
	while (1) {
		P(&mutex);
		readcnt++;
		if(readcnt == 1) /* First in */
			P(&w);
		V(&mutex);

		/* Critical section */
		/* Reading happens */

		P(&mutex);
		readcnt--;
		if(readcnt == 0)
			V(&w);
		V(&mutex);
	}
}

void writer(void) {
	while(1) {
		P(&w);

		/* Critical section */
		/* Writing happens */
		V(&w);
	}
}
