#include <stdio.h>
int main()
{
    int n, head;
    printf("Enter The Number Of Seek and Head ");
    scanf("%d%d", &n, &head);
    int arr[n];
    printf("Enter The Operations");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int seek_count = 0;
    int distance, cur_track;

    for (int i = 0; i < n; i++)
    {
        cur_track = arr[i];
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }
    printf("Total Seek Operations : %d\n", seek_count);
}