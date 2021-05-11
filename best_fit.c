#include <stdio.h>
int minimum(int process_size, int blocks[], int len)
{
    int min_index = -1, min = 10000;
    for (int i = 0; i < len; i++)
    {
        if (blocks[i] >= process_size && blocks[i] < min)
        {
            min_index = i;
            min = blocks[i];
        }
    }
    return min_index;
}

int main()
{
    int pc, bc; // pc-> process count bc -> block count
    printf("Enter The Number of Process");
    scanf("%d", &pc);
    printf("Enter The Number of Process Block ");
    scanf("%d", &bc);
    int process[pc], blocks[bc], allocation[pc];
    printf("Enter The Process Size ");
    for (int i = 0; i < pc; i++)
    {
        printf("Size of Process:%d ", i + 1);
        scanf("%d", &process[i]);
    }
    for (int i = 0; i < bc; i++)
    {
        printf("Size of Block:%d ", i + 1);
        scanf("%d", &blocks[i]);
    }
    printf("PID\tProcess Size\tBlock Index\tBlock Size\n");
    for (int i = 0; i < pc; i++)
    {
        int index = minimum(process[i], blocks, bc);
        printf("%d\t  %d\t        %d\t             %d\n", i + 1, process[i], (index == -1) ? index : index + 1, (index == -1) ? -1 : blocks[index]);
        blocks[index] -= process[i];
    }
}