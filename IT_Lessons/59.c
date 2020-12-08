#include <stdio.h>
#include <math.h>

int main()
{
	double e1 = 1;
	float e2 = 1;
	while ((1 + e1 != 1) && (1 + e1/2 != 1))
		e1 /= 2;
	while ((1 + e2 != 1) && (1 + e2/2 != 1))
		e2 /= 2;
	printf("Double: %.16e\n", e1);
	printf("Float: %.16e\n", e2);

    printf("%lf\n%e\n%e\n%e\n", (double)1, 1 + e1/2, 1 + e1, 1 + e1 + e1/2);
	return 0;
}