#include <stdio.h>
#define MAX 25
#define M 13

void exchange(float *x, float *y)
{
	float temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void FKnap(float p[], float w[], float n, float nos[])
{
	int i, j;
	float cp = 0, cw = 0, plw[MAX], x[MAX];
	for(i = 0; i < n; i++)
		plw[i] = p[i] / w[i];
	for(i = 0; i < n-1; i++)
		for(j = 0; j < n-1; j++)
			if(plw[j] < plw[j+1])
			{
				exchange(&p[j],&p[j+1]);
				exchange(&w[j],&w[j+1]);
				exchange(&plw[j],&plw[j+1]);
				exchange(&nos[j],&nos[j+1]);
			}
	printf("\nNo\tP\t\tW\t\tP/W\t\tX");
	for(i = 0; i < n; i++)
	{
		if(cw + w[i] < M)
		{
			cw += w[i];
			cp += p[i];
			x[i] = 1;
		}
		else
		{
			x[i] = M - cw;
			x[i] /= w[i];
			cw = M;
			cp += x[i] * p[i];
			printf("\n%d\t%f\t%f\t%f\t%f", (int)nos[i], p[i], w[i], plw[i], x[i]);
			break;
		}
		printf("\n%d\t%f\t%f\t%f\t%f", (int)nos[i], p[i], w[i], plw[i], x[i]);
	}
	printf("\n\t%f\t%f\n", cp, cw);
}

void main()
{
	float p[MAX], w[MAX], nos[MAX];
	int n, i;
	printf("Enter No. of Items: ");
	scanf("%d",&n);
	printf("Enter Profits and Weights:\n");
	for(i = 0; i < n; i++)
	{
		scanf("%f%f", &p[i], &w[i]);
		nos[i] = i+1;
	}
	FKnap(p, w, n, nos);
}
