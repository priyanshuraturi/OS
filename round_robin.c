#include<stdio.h>
#include<string.h>
#define SIZE 100
int items[SIZE], front = -1, rear = -1;
void push(int value) {
    if (front == -1)
      front = 0;
    rear++;
    items[rear] = value;
}

int pop() {
  if (front == -1)
    return -1;
     if (front+1> rear){
     int tmp=front;
      front = rear = -1;
      return items[tmp];
     }
  else {
    return items[front++];
   
  }
}

struct process{
	int bt;
	int at;
	int wt;
	int tat;
	int ct;
	int bt_org;//Orignal Burst Time
	int in_queue;
};
int main(){
    int n,tq;
    float avgtat=0,avgwt=0;
	printf("Enter The Number of Process");
	scanf("%d",&n);
    printf("Enter The Time Quantam");
    scanf("%d",&tq);
	struct process p[n];// Struct Array
	memset(p, 0, n * sizeof *p);
	printf("Enter The Burst Time \n");
	for(int i=0;i<n;i++){
		printf("Burst Time P%d: ",i+1);
		scanf("%d",&p[i].bt);
		p[i].bt_org=p[i].bt;
		p[i].in_queue=0;
	}
	printf("Enter The Arrival Time \n");
	for(int i=0;i<n;i++){
		printf("Arrival Time Of  P%d: ",i+1);
		scanf("%d",&p[i].at);
		}
	int proc_exec=0,pid=-1,time=0;//(proc_exec)Process Completed Counter
	while(proc_exec<n){//Checking Completed Process
		for(int i=0;i<n;i++){//Pushing Process according to burst time
			if(time>=p[i].at&&p[i].in_queue==0){
                    push(i);
                    p[i].in_queue=1;
				}	
				
	    }	
            if(pid!=-1) push(pid);
            pid=pop();
            time+=(p[pid].bt<tq)?p[pid].bt:tq;
			p[pid].bt-=(p[pid].bt<tq)?p[pid].bt:tq;
			if(p[pid].bt==0){
             p[pid].ct=time;
			 p[pid].tat=p[pid].ct-p[pid].at;
			 p[pid].wt=p[pid].tat-p[pid].bt_org;
			 proc_exec+=1;
             avgwt+=p[pid].wt;
             avgtat+=p[pid].tat;
             pid=-1;

		}
        
	}
	printf("\nPID\tBT\tAT\tCT\tTAT\tWT\n");
	for(int i=0;i<n;i++){
	printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,p[i].bt_org,p[i].at,p[i].ct,p[i].tat,p[i].wt);	
	}
    printf("Avg TAT =%.2f \n Avg WT %.2f",avgtat/n,avgwt/n);

	return 0;
		 	
}
	
	