#include <stdio.h>

int array[] = {31, 64, 56, 18, 34, 31, 64};
int matrix[3][3] =
{
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

int main()
{
    int i, j, len = sizeof(array) / sizeof(array[0]);
    //Second Smallest
    int min, min2;
    min = array[0];
    for(i = 0; i < len; i++)
    {
        if(array[i] < min)
            min = array[i];
    }

    min2 = array[0];
    {
        if(array[i] < min2 && array[i] > min)
            min2 = array[i];
    }
    printf("Second Smallest:%d\n", min2);

    //Sum of Left Diagonals
    int leftDiagSum = 0;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(i == j)
                leftDiagSum += matrix[i][j];
        }
    }
    printf("Left Diagonal: %d\n", leftDiagSum);

    //Sum of Rows and Columns
    int rowSums[3] = {0}, colSums[3] = {0};
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            rowSums[i] += matrix[i][j];
            colSums[j] += matrix[i][j];
        }
    }
    printf("Row Sums:\n");
    for(i = 0; i < 3; i++)
        printf("%d\t", rowSums[i]);
    printf("\n");

    printf("Column Sums:\n");
    for(i = 0; i < 3; i++)
        printf("%d\t", colSums[i]);
    printf("\n");

    //Duplicates in an array
    int dupCount = 0;
    for(i = 0; i < len; i++)
    {
        for(j = i; j < len; j++)
        {
            if(array[i] == array[j] && i != j)
                dupCount += 1;
        }
    }
    printf("Duplicate Count: %d\n", dupCount);

    //Second Largest
    int max, max2;
    max = array[0];
    for(i = 0; i < len; i++)
    {
        if(array[i] > max)
            max = array[i];
    }

    max2 = array[0];
    for(i = 0; i < len; i++)
    {
        if(array[i] > max2 && array[i] < max)
            max2 = array[i];
    }
    printf("Second Largest:%d\n", max2);

    //Delete element
    int position;
    printf("Enter Position to Delete:");
    scanf("%d",&position);
    printf("Original Array:\n");
    for(i = 0; i < len; i++)
        printf("%d\t", array[i]);
    printf("\n");

    for(i = position; i < len; i++)
        array[i] = array[i + 1];
    len--;
    printf("New Array:\n");
    for(i = 0; i < len; i++)
        printf("%d\t", array[i]);
    printf("\n");
    return 0;
}
