#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void createarray(int x[], int n)
{
	int i, range;
	range = 100;
	for(i = 0; i < n; i++)
  	{
		x[i] = rand() % range;
		printf("%d ",x[i]);
  	}
  	printf("\n");
}

void minmax(int x[], int i, int j, int *fmin, int *fmax)
{
	int c, m, gmax, gmin, hmax, hmin;
	if (i == j)
	{
		*fmin = *fmax = x[i];
		return;
	}
	if (i == j-1)
	{
		*fmin = x[i] < x[j] ? x[i] : x[j];
		*fmax = x[i] > x[j] ? x[i] : x[j];
		return;
	}
	m = i + j;
	m /= 2;
	minmax(x, i, m, &gmin, &gmax);
	minmax(x, m+1, j, &hmin, &hmax);
	*fmin = hmin < gmin ? hmin : gmin;
	*fmax = hmax > gmax ? hmax : gmax;
	return;
}

void main()
{
	int x[MAX], n, rmin, rmax;
	printf("Enter No. of Elements: ");
	scanf("%d", &n);
	createarray(x, n);
	minmax(x, 0, n-1, &rmin, &rmax);
	printf("Minimum: %d\n", rmin);
	printf("Maximum: %d\n", rmax);
}
