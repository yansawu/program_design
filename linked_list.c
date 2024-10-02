#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NODE NODE;

struct NODE{
    int data;
    NODE *next;
};

int deleteNode(struct NODE **, int );
void add(int, NODE **);
int insert_back(NODE **, int, int);
int delete (NODE **, int);
void show_the_list(NODE **);
int insert_front(NODE **, int, int);
int search(NODE **, int);
int update(NODE **, int, int);

int main(){
    NODE *head = NULL;
    char str[15];
    while(scanf("%s", str)!=EOF){

        if(strcmp(str,"add")==0){
            int input;
            scanf("%d", &input);
            add(input, &head);
        }else
        if(strcmp(str,"print")==0){

            show_the_list(&head);
        }
        if(strcmp(str,"insert")==0){
            int input, data;
            scanf("%d%d", &input, &data);
            insert_front(&head, input, data);
        }
        if(strcmp(str,"search")==0){
            int input;
            scanf("%d", &input);
            search(&head, input);
        }
        if(strcmp(str,"update")==0){
            int input, data;
            scanf("%d%d", &input, &data);
            update(&head, input, data);
        }
        if(strcmp(str,"delete")==0){
            int input;
            scanf("%d", &input );
            deleteNode(&head, input);
        }
    }
}

void add(int data, NODE** head){
    NODE *newNODE = (NODE *)malloc(sizeof(NODE));
    if(*head==NULL)
        *head = newNODE;
    else{
        NODE *cur;
        cur = *head;
        while(cur->next!=NULL){
            cur = cur->next;
        }
        cur->next = newNODE;
    }
    newNODE->data = data;
    newNODE->next = NULL;
    printf("ADD_SUCC\n");
}

int insert_back(NODE **head, int tgt, int data){
    // insert after data tgt
    // 0:fail, 1:sucecss
    if(*head==NULL){
        printf("INSERT_FAIL\n");
        return 0;
    }
    NODE *cur;
    cur = *head;
    while(cur!=NULL&&cur->data!=tgt){
        cur = cur->next;
    }
    if(cur==NULL){
        printf("INSERT_FAIL\n");
        return 0;
    }
        
    NODE *newNODE = (NODE *)malloc(sizeof(NODE));
    NODE *temp;
    temp = cur->next;
    cur->next = newNODE;
    newNODE->next = temp;
    newNODE->data = data;
    printf("INSERT_SUCC\n");
    return 1;
}
int deleteNode(struct NODE** head_ref, int key)
{
    // Store head node
    struct NODE *temp = *head_ref, *prev;
 
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        printf("DELETE_SUCC\n");
        return 1;
    }
 
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL){
        printf("DELETE_FAIL\n");
        return 0;
    }
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    free(temp); // Free memory
    printf("DELETE_SUCC\n");
    return 1;
}

int delete(NODE **head, int tgt){
    if(*head==NULL){
        printf("DELETE_FAIL\n");
        return 0;
    }
    if((*head)->data==tgt&&(*head)->next==NULL){
        NODE *temp = *head;
        *head = NULL;
        free(temp);
        printf("DELETE_SUCC\n");
        return 1;
    }
    if((*head)->data==tgt){
        NODE *temp = *head;
        *head = temp->next;
        free(temp);
        printf("DELETE_SUCC\n");
        return 1;
    }
    
    NODE *cur;
    cur = *head; 
    
    while(cur->next!=NULL){
        if(cur->next->data!=tgt)
            cur = cur->next;
        if(cur->next->data==tgt){
            break;
        }
    }
    if(cur->next==NULL){
        printf("DELETE_FAIL\n");
        return 0;
    }
    if(cur->next->next==NULL){
        NODE *temp = cur->next;
        cur->next = NULL;
        free(temp);
        printf("DELETE_SUCC\n");
        return 1;
    }
    NODE *temp = cur->next;
    cur->next = cur->next->next;
    free(temp);
    
    printf("DELETE_SUCC\n");
    return 1;
    
}
void show_the_list(NODE **head){
    if(*head == NULL){
        printf("\n");
        return;
    }
    NODE *cur;
    cur = *head;
    while(cur->next!=NULL){
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("%d ", cur->data);
    printf("\n");
}

int insert_front(NODE **head, int tgt, int data){
    if(*head==NULL){
        printf("INSERT_FAIL\n");
        return 0;
    }
    if((*head)->data==tgt){
        NODE *newNODE = (NODE *)malloc(sizeof(NODE));
        NODE *temp = *head;
        *head = newNODE;
        (*head)->data = data;
        (*head)->next = temp;
        (*head)->next->data = tgt;
        printf("INSERT_SUCC\n");
        return 1;
    }
    NODE *cur;
    cur = *head;
    while(cur->next!=NULL&&cur->next->data!=tgt){
        cur = cur->next;
    }
    if(cur->next==NULL){
        printf("INSERT_FAIL\n");
        return 0;
    }
    NODE *newNODE = (NODE *)malloc(sizeof(NODE));
    NODE *temp = cur->next;
    cur->next = newNODE;
    cur->next->data = data;
    cur->next->next = temp;

    printf("INSERT_SUCC\n");
    return 1;
}
int search(NODE **head, int tgt){
    if(*head==NULL){
        printf("NOT FOUND\n");
        return 0;
    }
    NODE *cur = *head;
    while(cur->data!=tgt&&cur->next!=NULL){
        cur = cur->next;
    }
    if(cur->next==NULL&&cur->data!=tgt){
        printf("NOT FOUND\n");
        return 0;
    }

    printf("FOUND\n");
    return 1;
}

int update(NODE **head, int tgt, int data){
    if(*head==NULL){
        printf("UPDATE_FAIL\n");
        return 0;
    }
    NODE *cur = *head;
    while(cur->data!=tgt&&cur->next!=NULL){
        cur = cur->next;
    }
    if(cur->next==NULL&&cur->data!=tgt){
        printf("UPDATE_FAIL\n");
        return 0;
    }
    cur->data = data;
    printf("UPDATE_SUCC\n");
    return 1;
}