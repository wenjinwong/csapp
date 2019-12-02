void merge2(long src1[], long src2[], long dest[], long n) {
	long i1 = 0,  i2 = 0;
	long id = 0;

	while(i1 < n && i2 < n) {
		dest[id++] = src1[i1] < src2[i2] ? src1[i1++] : src2[i2++];
	}

	while(i1 < n)
		dest[id++] = src1[i1++];
	while(i2 < n)
		dest[id++] = src2[i2++];
}
int main() {}
