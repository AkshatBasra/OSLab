#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int id, wt, bt, tat, priority;
};

void sortPriority(struct Process l[], int n)
{
    struct Process temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (l[j].priority > l[j + 1].priority)
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
    int n, i, p;
    float wta, tata;
    printf("Enter Number of Processes:");
    scanf("%d", &n);
    struct Process list[n];
    for(i = 0; i < n; i++)
    {
        list[i].id = i;
        printf("Process %d:\n",list[i].id);
        printf("Burst Time:");
        scanf("%d", &list[i].bt);
        printf("Queue Priority:");
        scanf("%d", &list[i].priority);
    }
    //printf("-------\n");

    sortPriority(list, n);

    list[0].wt = 0;
    wta = tata = 0;
    for(p = 1; p <= 2; p++)
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
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\tPriority\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",list[i].id, list[i].bt, list[i].wt, list[i].tat, list[i].priority);
    }
    printf("Average Waiting Time: %f\n", wta);
    printf("Average Turnaround Time: %f\n", tata);
}
