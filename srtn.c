#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void sort(int bt_array[],int pid_array[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(bt_array[j]>bt_array[j+1]){
                swap(&bt_array[j],&bt_array[j+1]);
               if(pid_array!=NULL){ 
                    swap(&pid_array[j],&pid_array[j+1]);
               }
            }
        }
    }
}
int main(){
  int n;
printf("Enter The Number of Process: ");
scanf("%d",&n);
int bt[n],at[n],tat[n],wt[n],temp,pid[n];
printf("\nEnter The Burst Time and Arrival Time\n");
for(int i=0;i<n;i++){
    pid[i]=i;
printf("Burst Time P%d: ",i+1);
scanf("%d",&bt[i]);
printf("Arrival Time P%d: ",i+1);
scanf("%d",&at[i]);
}
sort(bt,pid,n);
sort(at,NULL,n);
int proc_in_queue=0;
int pq[n],top=0,time=0;

}