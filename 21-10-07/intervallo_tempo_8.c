#include <stdio.h>

int main()
{
	int h1, m1, s1, h2, m2, s2;
	int ris;
	scanf("%d:%d:%d", &h1, &m1, &s1);
	scanf("%d:%d:%d", &h2, &m2, &s2);
	s1 = (h1 * 60 + m1) * 60 + s1;
	s2 = (h2 * 60 + m2) * 60 + s2;
	ris = s1 > s2 ? s1-s2 : s2-s1;
	m1 = ris / 60;
	s1 = ris % 60;
	h1 = m1 / 60;
	m1 = m1% 60;
	printf("%02d:%02d:%02d\n", h1, m1, s1);
}
