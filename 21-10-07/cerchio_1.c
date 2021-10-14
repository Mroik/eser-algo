#include <stdio.h>
#include <math.h>

int main()
{
	float raggio, area;
	scanf("%f", &raggio);
	area = (raggio * raggio) * M_PI;
	printf("%f\n", area);
}
