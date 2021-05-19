#include <stdio.h>
int main()
{

    int pc, bc; // pc-> process count bc -> block count
    printf("Enter The Number of Process");
    scanf("%d", &pc);
    printf("Enter The Number of Process Block ");
    scanf("%d", &bc);
    int blocks[bc];
    int process[pc];

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
    int process_counter = 0, block_index;
    printf("PID\tProcess Size\tBlock Index\n");
    while (process_counter < pc)
    {
        block_index = -1;
        for (int i = 0; i < bc; i++)
        {
            if (blocks[i] >= process[process_counter])
            {
                blocks[i] -= process[process_counter];
                block_index = i + 1;
                break;
            }
        }
        if (block_index != -1)
        {
            printf("%d\t\t%d\t\t%d\t\t\n", process_counter + 1, process[process_counter], block_index);
        }

        else
        {
            printf("%d\t\t%d\tNot Assinged\n", process_counter + 1, process[process_counter]);
        }
        process_counter += 1;
    }
}
