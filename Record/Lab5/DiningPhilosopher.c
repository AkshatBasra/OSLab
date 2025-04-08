#include<stdio.h>

int chopstick[5] = {0};  // Semaphores used

void wait(int *S)
{
    (*S)--;
}

void signal(int *S)
{
    (*S)++;
}

void philosopher(int i)
{
    wait(&chopstick[i]);
    wait(&chopstick[(i + 1) % 5]);
    printf("Philosopher %d is eating\n", (i + 1));
    signal(&chopstick[i]);
    signal(&chopstick[(i + 1) % 5]);
}

int main()
{
    printf("Dining Philosophers Problem\n");

    int p, n;
    printf("Number of hungry philosophers: ");
    scanf("%d", &n);
    int philosophers[n];
    for(int i = 0; i < 5; i++)
        philosophers[i] = 0;
    for(int i = 0; i < n; i++)
    {
        printf("Enter philosopher %d position: ", i + 1);
        scanf("%d", &p);
        philosophers[p - 1] = 1;
    }

    while(1)
    {
        printf("1. One can eat\n2. Two can eat\n3. Exit\n");
        scanf("%d", &p);
        switch(p)
        {
            case 1: for(int i = 0; i < 5; i++)
                    {
                        if(philosophers[i])
                            printf("Philosopher %d is thinking\n", i + 1);
                    }
                    for(int i = 0; i < 5; i++)
                    {
                        if(philosophers[i])
                        {
                            philosopher(i);
                            printf("Philosopher %d has finished eating\n", (i + 1));
                        }
                    }
                    break;


            case 2: for(int i = 0; i < 5; i++)
                    {
                        if(philosophers[i])
                            printf("Philosopher %d is thinking\n", i + 1);
                    }
                    for(int i = 0; i < 5; i++)
                    {
                        if(philosophers[i])
                        {
                          for(int j = i + 1; j < 5; j++)
                            {
                                if(philosophers[j])
                                {
                                    philosopher(i);
                                    philosopher(j);
                                    printf("Philosopher %d has finished eating\n", (i + 1));
                                    printf("Philosopher %d has finished eating\n", (j + 1));
                                    philosophers[i] = 0; philosophers[j] = 0;
                                    break;
                                }
                            }
                            if(philosophers[i])
                            {
                                philosopher(i);
                                printf("Philosopher %d has finished eating\n", (i + 1));
                                philosophers[i] = 0;
                            }
                        }
                    }
                    break;


            default:return 0;
        }
    }
}
