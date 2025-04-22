#include <stdio.h>
#include <stdlib.h>

struct partition
{
    int space;
    struct partition *hole;
    int occupied;
    int available;
};

void firstFit(struct partition *memory, int processes[4])
{
    int fit[4] = {0};
    for(int pro = 0; pro < 4; pro++)
    {
        for(int part = 0; part < 5; part++)
        {
            if(!(memory[part].occupied) && memory[part].space >= processes[pro])
            {
                fit[pro] = 1;
                memory[part].hole = (struct partition *) malloc(sizeof(struct partition));
                memory[part].hole->hole = NULL;
                memory[part].hole->occupied = 0;
                memory[part].hole->space = memory[part].space - processes[pro];
                printf("Fit %d to block %d\n", processes[pro], part + 1);
            }
            else if(memory[part].hole != NULL)
            {
                struct partition *temp = memory[part].hole;
                while(temp->hole != NULL)
                {
                    if(!(temp->occupied) && temp->space >= processes[pro])
                    {
                        fit[pro] = 1;
                        memory[part].hole = (struct partition *) malloc(sizeof(struct partition));
                        memory[part].hole->hole = NULL;
                        memory[part].hole->occupied = 0;
                        memory[part].hole->space = memory[part].space - processes[pro];
                    }
                }
            }
        }
    }
    int flag = 0;
    for(int i = 0; i < 4; i++)
    {
        if(!fit[i])
        {
            flag = 1;
            break;
        }
    }
    if(flag)
    {
        printf("Couldn't Fit all\n");
    }
    else
    {
        printf("All fit\n");
    }
}

void bestFit(struct partition *memory, int processes[4])
{
    int fit[4] = {0};
    for(int pro = 0; pro < 4; pro++)
    {
        int min = INT_MAX, index;
        for(int part = 0; part < 5; part++)
        {
            if(memory[part].space >= processes[pro] && memory[part].space <= min && !(memory[part].occupied))
            {
                min = memory[part].space;
                index = part;

            }
        }
        if(index < 5)
        {
            fit[pro] = 1;
            memory[index].hole = (struct partition *) malloc(sizeof(struct partition));
            memory[index].hole->hole = NULL;
            memory[index].hole->occupied = 0;
            memory[index].hole->space = memory[index].space - processes[pro];
            printf("Fit %d to block %d\n", processes[pro], index + 1);
        }
    }
    int flag = 0;
    for(int i = 0; i < 4; i++)
    {
        if(!fit[i])
        {
            flag = 1;
            break;
        }
    }
    if(flag)
    {
        printf("Couldn't Fit all\n");
    }
    else
    {
        printf("All fit\n");
    }
}

void worstFit(struct partition *memory, int processes[4])
{
    int fit[4] = {0};
    for(int pro = 0; pro < 4; pro++)
    {
        int max = 0, index;
        for(int part = 0; part < 5; part++)
        {
            if(memory[part].space >= processes[pro] && memory[part].space >= max && !(memory[part].occupied))
            {
                max = memory[part].space;
                index = part;

            }
        }
        if(index < 5)
        {
            fit[pro] = 1;
            memory[index].occupied = 1;
            memory[index].hole = (struct partition *) malloc(sizeof(struct partition));
            memory[index].hole->hole = NULL;
            memory[index].hole->occupied = 0;
            memory[index].hole->space = memory[index].space - processes[pro];
            printf("Fit %d to block %d\n", processes[pro], index + 1);
        }
    }
    int flag = 0;
    for(int i = 0; i < 4; i++)
    {
        if(!fit[i])
        {
            flag = 1;
            break;
        }
    }
    if(flag)
    {
        printf("Couldn't Fit all\n");
    }
    else
    {
        printf("All fit\n");
    }
}

void main()
{
    struct partition *memory = (struct partition *) malloc(5 * sizeof(struct partition));
    for(int i = 0; i < 5; i++)
    {
        memory[i].space = (i + 1) * 100;
        memory[i].hole = NULL;
        memory[i].occupied = 0;
    }
    int processes[4] = {300, 200, 400, 500};

    firstFit(memory, processes);

    free(memory);
    struct partition *memory2 = (struct partition *) malloc(5 * sizeof(struct partition));
    for(int i = 0; i < 5; i++)
    {
        memory2[i].space = (i + 1) * 100;
        memory2[i].hole = NULL;
        memory2[i].occupied = 0;
    }
    bestFit(memory2, processes);

    free(memory2);
    struct partition *memory3 = (struct partition *) malloc(5 * sizeof(struct partition));
    for(int i = 0; i < 5; i++)
    {
        memory3[i].space = (i + 1) * 100;
        memory3[i].hole = NULL;
        memory3[i].occupied = 0;
    }
    worstFit(memory3, processes);
}
