#include <stdio.h>
struct package {
	int q;
};
void set_value(struct package data, int value) {
	data.q = value;
}
int main() {
	struct package p;
	p.q = 10;
	set_value(p, 20);
	printf("Value = %d\n", p.q);
	return 0;
}