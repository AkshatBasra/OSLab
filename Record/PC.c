#include <stdio.h>

int x = 1, mutex = 0, full = 0, empty = 3;

void wait(int *S)
{
    (*S)--;
}

void signal(int *S)
{
    (*S)++;
}

void producer()
{
    wait(&mutex);signal(&full);wait(&empty);
    if(empty == 0)
    {
        printf("Buffer is Full\n");
    }
    else
    {
        printf("Item produced: %d\n",x++);
    }
    signal(&mutex);
}

void consumer()
{
    wait(&mutex);wait(&full);signal(&empty);
    if(full != 0)
        printf("Item Consumed: %d\n",--x);
    else
        printf("Buffer is empty\n");
    signal(&mutex);
}

int main()
{
    int ch;
    printf("1. Produce\n2. Consume\n3. Exit\n");
    while(1)
    {
        printf("Enter Choice:");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: producer(); break;
            case 2: consumer(); break;
            default:return 0;
        }
    }
}
