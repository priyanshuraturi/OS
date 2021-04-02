#include<stdio.h>
#include<string.h>
/*
BT 10 5 1 6 3
AR 2 1 4 0 2
*/
struct process{
	int bt;
	int at;
	int wt;
	int tat;
	int ct;
	int bt_org;//Orignal Burst Time
	int is_exec;
};
int main(){
    int n;
	float avgtat=0,avgwt=0;
	printf("Enter The Number of Process");
	scanf("%d",&n);
	struct process p[n];// Struct Array
	memset(p, 0, n * sizeof *p);
	printf("Enter The Burst Time \n");
	for(int i=0;i<n;i++){
		printf("Burst Time P%d: ",i+1);
		scanf("%d",&p[i].bt);
		p[i].bt_org=p[i].bt;
		p[i].is_exec=0;
	}
	printf("Enter The Arrival Time \n");
	for(int i=0;i<n;i++){
		printf("Arrival Time Of  P%d: ",i+1);
		scanf("%d",&p[i].at);
		}
	int proc_exec=0,pid=0,min,time=0;//(proc_exec)Process Completed Counter
	while(proc_exec<n){//Checking Completed Process
	 		min=1000;
		for(int i=0;i<n;i++){//Calculating Process With Minimum Burst Time Which are Arrived
			if(time>=p[i].at&&p[i].is_exec==0){
				if(p[i].bt<min){
					min=p[i].bt;
					pid=i;
					}
			
		     	if(p[i].bt==min&&pid!=i){
					 if(p[i].at<p[pid].at){
						 pid=i;
					 }
					}
				}	
				
	    }	
			p[pid].bt=p[pid].bt-1;
			time =time+1;
			if(p[pid].bt==0){
             p[pid].ct=time;
			 p[pid].tat=p[pid].ct-p[pid].at;
			 p[pid].wt=p[pid].tat-p[pid].bt_org;
			 p[pid].is_exec=1;
			 proc_exec+=1;
			 avgwt+=p[pid].wt;
             avgtat+=p[pid].tat;

		}
	}
	printf("\nPID\tBT\tAT\tCT\tTAT\tWT\n");
	for(int i=0;i<n;i++){
	printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,p[i].bt_org,p[i].at,p[i].ct,p[i].tat,p[i].wt);	
	}
	printf("Avg TAT =%.2f \n Avg WT %.2f",avgtat/n,avgwt/n);
	return 0;
		 	
}
	
	