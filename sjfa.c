#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int bt;
    int at;
    struct Node* next;
};
struct Node* newNode(int bt,int at)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->bt = bt;
    newNode->at= at;
    newNode->next = NULL;
    return newNode;
}
void sortedInsert(struct Node** head, struct Node* newNode)
{
    // special case for the head end
    if (*head == NULL || (*head)->bt >= newNode->bt)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
 
    // locate the node before the point of insertion
    struct Node* current = *head;
    while (current->next != NULL && current->next->bt < newNode->bt) {
        current = current->next;
    }
 
    newNode->next = current->next;
    current->next = newNode;
}
struct Node* delete(struct Node** head)
{
    struct Node* temp=*head;
    if(*head!=NULL)
    {
        *head=(*head)->next;
    }
    return temp;
}
void printList(struct Node* head)
{
    struct Node* ptr=head;
    while(ptr)
    {
        printf("%d —> ", ptr->bt);
        ptr = ptr->next;
    }
 
    printf("null");
}
int main()
{   
    struct Node* head= NULL;
    struct Node* ptr=NULL;
    int n;
    printf("Enter The Number of Process");
    scanf("%d",&n);
    int bt[n],at[n],tat[n],wt[n],total_time=0,temp;
    // Input of Arrival and Burst Time
    for(int i=0;i<n;i++){
        printf("Enter The Burst of P%d: ",i+1);
        scanf("%d",&bt[i]);
        total_time+=bt[i];
    }
    for(int i=0;i<n;i++){
        printf("Enter The Arrival of P%d: ",i+1);
        scanf("%d",&at[i]);
    }
    //Sorting Arrival and Burst Time 
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
          if(at[j]>at[j+1]){
           temp=at[j];
           at[j]=at[j+1];
           at[j+1]=temp;
           temp=bt[j];
           bt[j]=bt[j+1];
           bt[j+1]=temp;   
          }
        }
    }
    
    return 0;
    }
    

