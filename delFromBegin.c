#include <stdio.h>
#include <stdlib.h>

struct node{
    
    int data;
    struct node*next;
};

void display(struct node*);
struct node* insertNodes(int);
struct node* deleteAtBegining(struct node*);

struct node* insertNodes(int size){
    
    struct node * head = NULL;
    struct node * newNode = NULL;
    struct node * currunt = NULL;
    
    for(int i = 0 ; i < size ; i++){
        newNode = (struct node*) malloc (sizeof(struct node));
        printf("Enter the value %d : ",i+1);
        scanf("%d",&newNode->data);
        newNode->next = NULL;
        
        if(head == NULL){
            head  = newNode;
            currunt = head;
        }else{
            currunt -> next = newNode;
            currunt = currunt -> next;
        }

    }
    printf("\nBefore delete first node,\n");
    return head;
}

struct node* deleteAtBegining(struct node* head){
    struct node * toDel = NULL;
    
    if(head == NULL){
        printf("The list is empty");
        return 0;
    }else{
        toDel = head;
        head = head -> next;
        free(toDel);
        printf("\nAfter delete first node,\n");
        return head;
    }
    
    
}

void display(struct node* head){
    while(head != NULL){
        printf("%d ",head->data);
        head = head -> next;
    }
}

int main()
{
    int size = 0;
    struct node* head = NULL;
    
    printf("Enter the size : ");
    scanf("%d",&size);
    
    head = insertNodes(size);
    display(head);
    
    head = deleteAtBegining(head);
    display(head);
    
    return 0;
}
