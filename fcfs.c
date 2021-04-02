#include<stdio.h>
typedef struct process
{
    int at,bt,tat,wt;
    process* next;
}process;
void insert(process* head,int at,int bt){
    process* temp,ptr=head;
    process* new=(process*)malloc(size(process));
    new->at=at;
    new->bt=bt;
        if(ptr==NULL){
            ptr=new;
        }
        else if(ptr->next==NULL&&ptr->bt>bt){
            head=new;
            head->next=ptr;
        }
        else if (ptr->next==NULL&&ptr->bt<=at){
         ptr.next=new;
        }
        else(){
            while(ptr!=NULL){
                if(ptr->at<=at&&ptr->next->at>at){
                 temp=ptr->next;
                 ptr->next=new;
                 new->next=temp;
                }
                else if(ptr->at>at&&ptr->){
                    
                }
            }
        }
        
    
    }
     
}
int main(){
    int n;
    printf("Enter The Number of Process");
    scanf("%d",&n);
    for(int i=0;i<n;i++){

    }
}
