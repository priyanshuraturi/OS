#include <stdio.h>
struct process
{
    int bt;
    int at;
    int completed; // 0 Flase  1 True
};
int main()
{
    int num;
    float avgTat = 0, avgWt = 0;
    printf("Enter The Number of Process:");
    scanf("%d", &num);
    struct process p[num];
    memset(p, 0, num * sizeof *p);
    printf("Enter The Burst Time and Arrival Time:\n");

    for (int i = 0; i < num; i++)
    {
        printf("Burst Time P%d\n", i + 1);
        scanf("%d", &p[i].bt);
        printf("Arrival Time P%d\n", i + 1);
        scanf("%d", &p[i].at);
        p[i].completed = 0;
    }
    int time = 0, processCompleted = 0;
    while (processCompleted < num)
    {
        int min_index = 0, min_bt = 1000;
        for (int i = 0; i < num; i++)
        {
            if (time >= p[i].at && p[i].bt < min_bt && p[i].completed == 0)
            {
                min_index = i;
                min_bt = p[i].bt;
            }
        }
        time += p[min_index].bt;
        int tat = time - p[min_index].at;
        int wt = tat - p[min_index].at;
        avgTat += tat;
        avgWt += wt;
        printf("P%d\t%d\t%d\t%d\t%d\n", min_index + 1, p[min_index].bt, p[min_index].at, tat, wt);
        processCompleted += 1;
        p[min_index].completed = 1;
    }
    avgTat /= num;
    avgWt /= num;
    printf("Average TurnAround Time: %.3f", avgTat);
    printf("Average Wating Time: %.3f", avgWt);
    return 0;
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

// Write your code here
