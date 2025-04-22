#include <stdio.h>

void printt(int i,int *alloc)
{
    printf("Process %d -> ", i + 1);
    if (alloc[i] != -1)
        printf("Block %d\n", alloc[i] + 1);
    else
        printf("Not Allocated\n");
}
void firstFit(int b[], int m, int p[], int n)
{
    int alloc[n];
    for (int i = 0; i < n; i++)
        alloc[i] = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (b[j] >= p[i])
            {
                alloc[i] = j;
                b[j] -= p[i];
                break;
            }
        }
    }
    printf("\nFirst Fit:\n");
    for (int i = 0; i < n; i++)
    {
        printt(i,alloc);
    }
}
void bestFit(int b[], int m, int p[], int n)
{
    int alloc[n];
    for (int i = 0; i < n; i++)
        alloc[i] = -1;
    for (int i = 0; i < n; i++)
    {
        int best = -1;
        for (int j = 0; j < m; j++)
        {
            if (b[j] >= p[i] && (best == -1 || b[j] < b[best]))
            {
                best = j;
            }

        }
        if (best != -1)
        {
            alloc[i] = best;
            b[best] -= p[i];
        }
    }
    printf("\nBest Fit:\n");
    for (int i = 0; i < n; i++)
    {
        printt(i,alloc);
    }
}
void worstFit(int b[], int m, int p[], int n)
{
    int alloc[n];
    for (int i = 0; i < n; i++)
        alloc[i] = -1;
    for (int i = 0; i < n; i++)
    {
        int worst = -1;
        for (int j = 0; j < m; j++)
        {
            if (b[j] >= p[i] && (worst == -1 || b[j] > b[worst]))
            {
                worst = j;
            }
        }
        if (worst != -1)
        {
            alloc[i] = worst;
            b[worst] -= p[i];
        }
    }
    printf("\nWorst Fit:\n");
    for (int i = 0; i < n; i++)
    {
        printt(i,alloc);
    }
}
int main()
{
    printf("enter no of processes: ");
    int k;
    scanf("%d",&k);
    int p[k];
    printf("enter the process requirements: ");
    for(int i=0;i<k;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("enter no of blocks: ");
    int j;
    scanf("%d",&j);
    int b[j];
    printf("enter the block sizes: ");
    for(int i=0;i<j;i++)
    {
        scanf("%d",&b[i]);
    }
    int m = j, n = k, b1[m], b2[m], b3[m];
    for (int i = 0; i < m; i++)
    {
        b1[i] = b2[i] = b3[i] = b[i];
    }
    firstFit(b1, m, p, n);
    bestFit(b2, m, p, n);
    worstFit(b3, m, p, n);
    return 0;
}
