#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int id, wt, bt, tat;
};

void sortBT(struct Process l[], int n)
{
    struct Process temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (l[j].bt > l[j + 1].bt)
            {
                temp = l[j];
                l[j] = l[j + 1];
                l[j + 1] = temp;
            }
        }
    }
}

void main()
{
    int n, i;
    float wta, tata;
    printf("Enter Number of Processes:");
    scanf("%d", &n);
    struct Process list[n];
    printf("Enter Burst Times:\n");
    for(i = 0; i < n; i++)
    {
        list[i].id = i;
        printf("Process %d:",list[i].id);
        scanf("%d", &list[i].bt);
    }
    //printf("-------\n");

    sortBT(list, n);
    list[0].wt = 0;
    wta = 0;
    tata = 0;


    for(i = 1; i < n; i++)
    {
        //printf("Process %d: %d\n", list[i].id, list[i].bt);
        list[i].wt = list[i - 1].wt + list[i - 1].bt;
        list[i].tat = list[i].wt + list[i].bt;
        wta += list[i].wt;
        tata += list[i].tat;
    }
    wta /= n;
    tata /= n;
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n",list[i].id, list[i].bt, list[i].wt, list[i].tat);
    }
    printf("Average Waiting Time: %f\n", wta);
    printf("Average Turnaround Time: %f\n", tata);
}
