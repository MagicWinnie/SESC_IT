#include <stdio.h>
#include <math.h>

int main()
{
	double e1 = 1.0;
	float e2 = 1.0f;
	while ((1.0 + e1 != 1.0) && (1.0 + e1 / 2.0 != 1.0))
		e1 /= 2.0;
	while ((1.0f + e2 != 1.0f) && (1.0f + e2 / 2.0f != 1.0f))
		e2 /= 2.0f;
	printf("Double: %.16e\n", (double)e1);
	printf("Float: %.16e\n", (float)e2);

	printf("%e\n%e\n%e\n%e\n", 1.0, 1.0 + e1 / 2.0, 1.0 + e1, 1.0 + e1 + e1 / 2.0);
	return 0;
}