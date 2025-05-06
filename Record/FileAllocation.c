#include <stdio.h>

int main()
{
    int disk[100], start, length, i, j, count = 0;

    for (i = 0; i < 100; i++)
        disk[i] = 0;

    int n;
    printf("Enter number of files to allocate: ");
    scanf("%d", &n);
    printf("Disk Size: 100\n");
    for (i = 0; i < n; i++)
    {
        printf("\nEnter starting block and length of file %d:\n", i + 1);
        scanf("%d%d", &start, &length);

        if (start < 0 || start + length > 100)
        {
            printf("Invalid input: exceeds disk size\n");
            continue;
        }

        count = 0;
        for (j = start; j < start + length; j++)
        {
            if (disk[j] == 0)
                count++;
        }

        if (count == length)
        {
            for (j = start; j < start + length; j++)
                disk[j] = 1;
            printf("File %d allocated successfully\n", i + 1);
        }
        else
            printf("File %d allocation failed: blocks already in use\n", i + 1);
    }

    printf("\nAllocated Blocks:\n");
    for (i = 0; i < 100; i++)
    {
        if (disk[i] == 1)
            printf("%d ", i);
        if (i % 30 == 0 && i != 0)
            printf("\n");
    }
    printf("\n");

    return 0;
}
