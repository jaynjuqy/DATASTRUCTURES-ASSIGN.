#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head;
struct Node* current;

void insert(int data){
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    if (newNode==NULL){
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data=data;
    newNode->next=NULL;

    if (head==NULL){
        head=newNode;
    }
    else{
        current=head;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=newNode;
    }
}

void traverse(void){
    if (head==NULL){
        printf("No elements in the List bro!");
        return;
    }
    current=head;
    printf("Linked list: ");
    while (current!= NULL){
        printf("%d ->", current->data);
        current=current->next;
    }
    printf("\n");
}
void delElem(int elem){
    if (head==NULL){
        printf("No elements in the List to delete bro!\n");
        return;
    }
    if (head->data==elem){
        struct Node* temp=head;
        head = head->next;
        free(temp);
        return;
    }
    struct Node* prev =head;
    while (prev->next!=NULL && prev->next->data!=elem){
        prev=prev->next;
    }

    if (prev->next==NULL){
        printf("Element not found!\n");
        return;
    }
    struct Node* temp = prev->next;
    prev->next=temp->next;
    free(temp);
    printf("Element deleted successfully\n");
}

//********************************************QUIZZ 2:LINKED LIST IMPLEMENTED**************************************************
//QUESTION 1
void ifCycle(struct Node* head){
    if (head==NULL || head->next==NULL){
        printf("Head is NULL");
        return;
    }
    struct Node* slow=head;
    struct Node* fast=head->next;

    while (slow!=fast){
        if (fast==NULL || fast->next==NULL){
            printf("NO cycle in the list");
            return;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("Cycle found in the list");
    return ;
}
//QUESTION 2
struct Node *detectCycle(struct Node *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;

            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            printf("%d", slow->data);
        }
    }

    return NULL;
}
//QUESTION 3
struct Node* reverseLinkedList(struct Node* head) {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }
    return prev;
}
//#############################################################################################################################
int main()
{
    insert(23);
    insert(50);
    insert(20);
    insert(37);
    insert(49);
    traverse();
    delElem(23);
    traverse();
    ifCycle(head);
    detectCycle(head);
    reverseLinkedList(head);
    traverse();
    return 0;
}
