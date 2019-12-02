class Foo{
	public:
		Foo(int i, long l) : i(i), l(l) {}
		int i;
		long l;
		void bar() {
			i = ++l;
		}
};

int main() {
	Foo f(2, 3);
	f.bar();
}
