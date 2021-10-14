#include <stdio.h>

int main()
{
	int n;
	int size = -1;
	int arr[100];

	scanf("%d", arr);
	if(arr[0] == 0) return 0;
	for(int x = 1; x < 100; x++)
	{
		scanf("%d", &n);
		if(n == 0)
		{
			size = x;
			break;
		}
		for(int y = 0; y < x; y++)
		{
			if(n < arr[y])
			{
				for(int z = x; z > 0; z--) arr[z] = arr[z-1];
				arr[y] = n;
				break;
			}
		}
	}
	if(size < 0) size = 100;
	for(int i = 0; i < size; i++) printf("%d\n", arr[i]);
}
