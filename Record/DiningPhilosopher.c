#include<stdio.h>

int chopstick[5] = {0};

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
    int p;
    while(1)
    {
        printf("Choose philosophers: ");
        scanf("%d", &p);
        if(p < 1 || p > 5)
        {
            return 0;
        }
        philosopher(p - 1);
    }
}
