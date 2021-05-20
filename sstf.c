#include <stdlib.h>
#include <stdio.h>
struct requests
{
    int data;
    int completed;
};

int findMinimum(struct requests ar[], int head, int n)
{
    int minimum = 10000, min_index = 0;
    for (int i = 0; i < n; i++)
    {

        if (abs(ar[i].data - head) < minimum && ar[i].completed != 1)
        {

            min_index = i;
            minimum = abs(ar[i].data) - head;
        }
    }

    return min_index;
}
int main()
{
    int req, head;
    printf("Enter The Number of Requests and Head Positions \n");
    scanf("%d%d", &req, &head);
    struct requests reqs[req];
    for (int i = 0; i < req; i++)
    {
        scanf("%d", &reqs[i].data);
        reqs[i].completed = 0;
    }
    int seek_op = 0;
    for (int i = 0; i < req; i++)
    {
        int minid = findMinimum(reqs, head, req);
        seek_op += abs(head - reqs[minid].data);
        reqs[minid].completed = 1;
        head = reqs[minid].data;
    }
    printf("%d", seek_op);
}
