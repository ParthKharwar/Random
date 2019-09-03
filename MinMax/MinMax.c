#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void createfile(long n)
{
	long range, i;
	FILE *list;
	list = fopen("list.txt","w");
	range = 50000;
	for(i = 0; i < n; i++)
		fprintf(list,"%ld\n",rand()%range);
	fclose(list);
}

void createarray(long a[], long n)
{
	long i;
	FILE *read;
	read = fopen("list.txt","r");
	for(i = 0;i < n; i++)
		fscanf(read,"%ld",&a[i]);
	fclose(read);
}

void merge(long x[], long lb, long ub, long m)
{
	long temp[50000], i = lb, j = m + 1, k = 0;
	while(i <= m && j <= ub)
	{
		if(x[i] < x[j])
		      temp[k++] = x[i++];
		else  temp[k++] = x[j++];
	}
	while(i <= m)
        	temp[k++]=x[i++];
	while(j <= ub)
        	temp[k++]=x[j++];
	k = 0;
	for(i = lb; i <= ub; i++)
		x[i] = temp[k++];
}

void merge_sort(long x[], long lb, long ub)
{
	long m;
	if(lb < ub)
	{
		m = (lb + ub) / 2;
		merge_sort(x, lb, m);
		merge_sort(x, m + 1, ub);
		merge(x, lb, ub, m);
	}
}

long partition(long x[], long lb, long ub)
{
	long val = x[lb], down = lb, up = ub, t;
	while(down < up)
	{
		while(down <= up && x[down] <= val)
			down++;
		while(x[up] > val)
			up--;
		if(down < up)
		{
			t = x[down];
			x[down] = x[up];
			x[up] = t;
		}
	}
	x[lb] = x[up];
	x[up] = val;
	return up;
}

void quicksort(long x[], long lb, long ub)
{
	long p;
	if(lb < ub)
	{
		p = partition(x, lb, ub);
		quicksort(x, lb, p - 1);
		quicksort(x, p + 1, ub);
	}
}

void main()
{
	clock_t t;
	int i;
	long x[50000], n;
	double time;
	FILE *op;
	op = fopen("list.txt", "w");
	int no[5] = {10000,20000,30000,40000,50000};
	for(i=0; i<5; i++)
	{
	    n = no[i];
	  	createfile(n);
	  	createarray(x,n);
	  	t = clock();
	  	quicksort(x, 0, n-1);
		//merge_sort(x, 0, n-1);
	  	t =  clock()-t;
	  	time = t;
	  	time /= CLOCKS_PER_SEC;
	  	time *= 1000;
		  	printf("\n%ld : %lf ms", n, time);
	 }
	for(i = 0; i < n; i++)
		fprintf(op, "%ld\n", x[i]);
	fclose(op);
	printf("\n");
}
