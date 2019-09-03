#include <stdlib.h>
#include <stdio.h>

void MST_Prim(int wt[][25], int n, int d[], int p[], int r)
{
	int i, j, min, res[25][25] = {0}, visited[25] = {0};
	for(i = 0; i < n; i++)
	{
		d[i] = 30000;
		p[i] = -1;
	}
	d[r] = 0;
  i = r;
	do
	{
		for(j = 0; j < n; j++)
			if(wt[i][j] != 0 && visited[j]==0 && wt[i][j]<d[j])
			{
        d[j] = wt[i][j];
        p[j] = i;
			}
      visited[i] = 1;
      min = 30000;
      i = r;
      for(j = 0; j < n; j++)
        if(visited[j] == 0 && d[j] < min)
        {
          min = d[j];
          i = j;
        }
	}while(i!=r);

	printf("\nD:\t");
	for(i = 0; i < n; i++)
   	printf("%d\t", d[i]);
	printf("\nPi:\t");
	for(i = 0; i < n; i++)
  	printf("%d\t", p[i]);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(p[j] == i)
				res[i][j] = res[j][i] = d[j];

  printf("\nMCST:");
	for(i = 0; i < n; i++)
	{
		printf("\n");
		for(j = 0; j < n; j++)
			printf("%d\t", res[i][j]);
	}
    printf("\n");
}

void main()
{
	int wt[25][25], d[25], p[25], r, i, j, n, e, w, v1, v2;
  printf("Enter No. of Nodes: ");
  scanf("%d", &n);
  if(n)
  {
    printf("Enter No. of Edges: ");
    scanf("%d", &e);
    printf("Enter Edges and corresponding Weights:\n");
    for(i = 0; i < e; i++)
    {
      scanf("%d %d %d", &v1, &v2, &w);
      wt[v1 - 1][v2 - 1] = wt[v2 - 1][v1 - 1] = w;
    }
  }
  else
  {
    printf("Enter No. of Nodes for Adjacency Matrix: ");
    scanf("%d", &n);
  	printf("Enter Adjacency Matrix using Cost:\n");
  	for(i = 0; i < n; i++)
  		for(j = 0; j < n; j++)
  		{
  			scanf("%d", &wt[i][j]);
  			wt[j][i] = wt[i][j];
  		}
  }
  for(i = 0; i < n; i++)
  {
    printf("\n");
    for(j = 0; j < n; j++)
      printf("%d\t", wt[i][j]);
  }
	printf("\nEnter Starting Vertex: ");
	scanf("%d", &r);
	MST_Prim(wt, n, d, p, r);
}
