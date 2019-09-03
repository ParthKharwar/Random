#include <stdlib.h>
#include <stdio.h>

void exchange(int *x, int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void MST_Kruskal(int edges[][3], int n, int e)
{
	int i, j, end, res[25][25] = {0}, set[25];

	for(i=0; i<e-1; i++)
		for(j=0; j<e-1; j++)
      if(edges[j][2] > edges[j+1][2])
      {
        exchange(&edges[j][0],&edges[j+1][0]);
        exchange(&edges[j][1],&edges[j+1][1]);
        exchange(&edges[j][2],&edges[j+1][2]);
      }

  for(i=0; i<n; i++)
    set[i] = i+1;

  for(i=0; i<e; i++)
  {
    if(set[edges[i][0]] != set[edges[i][1]])
    {
      set[edges[i][0]] = set[edges[i][1]] = 0;
      res[edges[i][0]][edges[i][1]] = edges[i][2];
      res[edges[i][1]][edges[i][0]] = edges[i][2];
    }
  }

  printf("\n\nMCST is:\n");
	for(i=0; i<n; i++)
	{
		printf("\n");
		for(j=0; j<n; j++)
		printf("%d\t",res[i][j]);
	}
  printf("\n");
}

void main()
{
	int wt[25][25], i, j, n, e, w, v1, v2, edges[25][3];
  printf("Enter No. of Nodes: ");
  scanf("%d",&n);
  printf("Enter No. of Edges: ");
  scanf("%d", &e);
  printf("Enter Edges and Corresponding Weights:\n");
  for(i = 0; i < e; i++)
  {
    scanf("%d %d %d", &v1, &v2, &w);
    wt[v1 - 1][v2 - 1] = wt[v2 - 1][v1 - 1] = w;
    edges[i][0] = v1-1;
    edges[i][1] = v2-1;
    edges[i][2] = w;
  }
  for(i=0; i<n; i++)
  {
    printf("\n");
    for(j=0; j<n; j++)
    printf("%d\t",wt[i][j]);
  }
	MST_Kruskal(edges, n, e);
}
