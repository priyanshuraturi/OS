#include <stdio.h>

void sort(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                int temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }
}
int findMin(int ar[], int head, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (ar[i] >= head)
        {
            if (i > 0)
                return i - 1;
            else
                return 0;
        }
    }
    return (n - 1);
}

int main()
{
    int n, head;
    printf("Enter The Number Of Seek and Head ");
    scanf("%d%d", &n, &head);
    printf("Enter TheSeek Direction  0 for Left and 1 For Right: ");
    int direction;
    scanf("%d", &direction);
    int arr[n];
    printf("Enter The Operations");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int seek_op;
    sort(arr, n);
    if (direction == 1)
    {
        int largest = arr[n - 1];
        int smallest = arr[0];
        seek_op = largest - head - 1;
        seek_op += largest - smallest;
        seek_op += arr[findMin(arr, head, n)];
        printf("\n Seek Operation are :%d ", seek_op);
    }
    else if (direction == 0)
    {
        int largest = arr[n - 1];
        int smallest = arr[0];
        seek_op = head - smallest + 1;
        seek_op += largest - smallest;
        seek_op += largest - arr[findMin(arr, head, n) + 1];
        printf("\n Seek Operation are :%d ", seek_op);
    }
    else
        printf("Incorrect Direction");
}
