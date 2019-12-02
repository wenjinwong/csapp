int* f() {
	char buf[1000];
	int val = 10000;
	return &val;
}
int main() {
	int *pi = f();
	int j = 1;
	int m = 2;
	*pi  =  99;
	return 10000 == *pi;
}
	
