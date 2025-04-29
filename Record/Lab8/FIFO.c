#include <stdio.h>
#include <stdlib.h>

void print(int n, int arr[n])
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == -1)
            printf("- ");
        else
            printf("%d ", arr[i]);
    }
    printf("\n");
}

int isInMemory(int memory[], int frames, int page)
{
    for(int i = 0; i < frames; i++)
    {
        if(memory[i] == page)
            return 1;
    }
    return 0;
}

void FIFO(int frames, int n, int *refStr)
{
    printf("FIFO Page Replacement:\n");
    int memory[frames];
    for(int i = 0; i < frames; i++)
        memory[i] = -1;
    int pointer = 0;
    int misses = 0, total = 0;

    for(int t = 0; t < n; t++)
    {
        total++;
        int page = refStr[t];
        printf("%d: ", page);

        if(!isInMemory(memory, frames, page))
        {
            memory[pointer] = page;
            pointer = (pointer + 1) % frames;
            misses++;
        }

        print(frames, memory);
    }
    printf("Hits: %d\n", total - misses);
    printf("Misses: %d\n", misses);
}

void optimal(int frames, int n, int *refStr)
{
    printf("\nOptimal Page Replacement:\n");
    int memory[frames];
    for(int i = 0; i < frames; i++)
        memory[i] = -1;
    int total = 0, misses = 0;

    for(int t = 0; t < n; t++)
    {
        int page = refStr[t];
        total++;
        printf("%d: ", page);

        if (isInMemory(memory, frames, page))
        {
            print(frames, memory);
            continue;
        }

        int placed = 0;
        for (int i = 0; i < frames; i++)
        {
            if (memory[i] == -1)
            {
                memory[i] = page;
                misses++;
                placed = 1;
                break;
            }
        }

        if (!placed)
        {
            int toReplace = -1, farthest = -1;

            for (int i = 0; i < frames; i++)
            {
                int j;
                for (j = t + 1; j < n; j++)
                {
                    if (refStr[j] == memory[i])
                        break;
                }

                if (j == n)
                {
                    toReplace = i;
                    break;
                }

                if (j > farthest)
                {
                    farthest = j;
                    toReplace = i;
                }
            }

            memory[toReplace] = page;
            misses++;
        }

        print(frames, memory);
    }
    printf("Hits: %d\n", total - misses);
    printf("Misses: %d\n", misses);
}

void LRU(int frames, int n, int *refStr)
{
    printf("\nLRU Page Replacement:\n");
    int memory[frames];
    int lastUsed[frames];
    for(int i = 0; i < frames; i++)
    {
        memory[i] = -1;
        lastUsed[i] = -1;
    }
    int total = 0, misses = 0;

    for(int t = 0; t < n; t++)
    {
        int page = refStr[t];
        total++;
        printf("%d: ", page);

        int found = 0;
        for(int i = 0; i < frames; i++)
        {
            if(memory[i] == page)
            {
                lastUsed[i] = t;
                found = 1;
                break;
            }
        }

        if(!found)
        {
            int idx = -1;
            for(int i = 0; i < frames; i++)
            {
                if(memory[i] == -1)
                {
                    idx = i;
                    break;
                }
            }

            if(idx == -1)
            {
                int lruTime = t, lruIndex = 0;
                for(int i = 0; i < frames; i++)
                {
                    if(lastUsed[i] < lruTime)
                    {
                        lruTime = lastUsed[i];
                        lruIndex = i;
                    }
                }
                idx = lruIndex;
            }

            memory[idx] = page;
            lastUsed[idx] = t;
            misses++;
        }

        print(frames, memory);
    }
    printf("Hits: %d\n", total - misses);
    printf("Misses: %d\n", misses);
}


int main()
{
    int frames, n;
    printf("Enter Number of Frames: ");
    scanf("%d", &frames);
    printf("Enter Length of Reference String: ");
    scanf("%d", &n);
    int *refStr = (int*) malloc(n * sizeof(int));
    printf("Enter Reference String: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &refStr[i]);
    }
    FIFO(frames, n, refStr);
    optimal(frames, n, refStr);
    LRU(frames, n, refStr);
    free(refStr);
    return 0;
}
