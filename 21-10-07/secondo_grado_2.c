#include <stdio.h>
#include <math.h>

int main()
{
	float c1, c2, c3;
	float ris1, ris2;
	float delta;
	float denom;
	scanf("%f %f %f", &c1, &c2, &c3);

	denom = 2*c1;
	// Check if is complex
	delta = (c2*c2) - (4*c1*c3);
	if(delta >= 0)
	{
		ris1 = -c2 + sqrt(delta);
		ris1 = ris1/denom;
		ris2 = -c2 - sqrt(delta);
		ris2 = ris2/denom;
		printf("%f\n", ris1);
		printf("%f\n", ris2);
	}
	else
	{
		delta = sqrt(-delta);
		printf("(%f + i%f) / %f\n", -c2, delta, denom);
		printf("(%f - i%f) / %f\n", -c2, delta, denom);
	}
}
