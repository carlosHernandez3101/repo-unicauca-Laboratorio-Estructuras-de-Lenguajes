#include <stdio.h>
#include <math.h>
struct coordenadas {
	float x;
	float y;
	float z;
};
float distancia(struct coordenadas a, struct coordenadas b) {
	return sqrtf(pow(a.x - b.x, 2.0) +
	             pow(a.y - b.y, 2.0) +
	             pow(a.z - b.z, 2.0));
}
int main() {
	struct coordenadas punto_a = { 3.5e-120, 2.5, 1.5 };
	struct coordenadas punto_b = { 5.3e-120, 3.1, 6.3 };
	float d;
	d = distancia(punto_a, punto_b);
	printf("%f\n", d);
	return 0;
}