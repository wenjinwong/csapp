#include<stdio.h>


struct m {
	char type:4,
		 bing:4;
};

int main() {
	struct m mm;
	mm.type = 0xf;
	mm.bing = 0xe;
	printf("%.1x %.1x \n", mm.type, mm.bing);
}
