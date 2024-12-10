#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* createNode(int data) {
    struct node* new_node = malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

node* insertFront(node **head, int data) {
    struct node *new_node = createNode(data);

    new_node->next = *head;
    *head = new_node;

    return new_node;
}

node* insertRear(node **head, int data){
    struct node *new_node = createNode(data);

    if(*head == NULL){
        return new_node;
    }

    struct node *last = *head;

    while(last->next != NULL){
        last = last->next;
    }

    last->next = new_node;

    return *head;

}

node* insertAtPos(node **head, int pos, int data){
    if(pos < 1){
        return *head;
    }

    if(pos == 1){
        struct node *new_node = createNode(data);
        new_node->next = *head;
        return new_node;
    }

    struct node *curr = *head;

    int i = 1; 
    while(i < pos - 1 && curr != NULL){
        curr = curr->next;
        i++;
    }

    if(curr == NULL){
        return *head;
    }

    struct node *new_node = createNode(data);
    
    new_node->next = curr->next;
    curr->next = new_node;

    return *head;

}

node *deleteAtValue(node **head, int value){
    if(*head == NULL){
        printf("The list is Empty nigga!");
        return *head;
    }

    struct node *curr = *head;
    struct node *temp = NULL;

    if(curr->data == value){
        *head = curr->next;
        free(curr);
        return *head;
    }

    while(curr->next != NULL && curr->data != value){
        temp = curr;
        curr = curr->next;
    }

    if(curr == NULL){
        printf("The value is not found at the list!");
        return *head;
    }

    temp->next = curr->next;
    free(curr);

    return *head;
}

node *deleteFront(node *head){
    if(head == NULL){
        return NULL;
    }

    struct node *temp = head;

    head = head->next;

    free(temp);

    return head;
}

node *deleteRear(node *head){
    if(head == NULL){
        return NULL;    
    }
    if(head->next == NULL){
        free(head);
        return NULL;
    }

    struct node *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    } 

    free(temp->next);
    temp->next = NULL;
    
    return head;
}

void printlist(struct node *head) {
    printf("The list is: ");
    struct node *curr = head;

    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}


int main() {
    node *head = NULL;
    int choice, value;

    printf("Linked List Operations:\n");
    printf("1. Insert at front\n");
    printf("2. Insert Rear\n");
    printf("3. Insert at Position\n");
    printf("4. Delete front\n");
    printf("5. Delete Rear\n");
    printf("6. Delete at Value\n");
    printf("7. Print list\n");
    printf("8. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertFront(&head, value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertRear(&head, value);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                int pos;
                printf("Enter the posisiton to insert: ");
                scanf("%d", &pos);
                insertAtPos(&head,pos,value);
                break;
            case 4:
                head = deleteFront(head);
                break;
            case 5:
                head = deleteRear(head);
                break;
            case 6:
                printf("Enter the value you want to delete: ");
                scanf("%d", &value);
                deleteAtValue(&head, value);
                
                break;
            case 7:
                printlist(head);
                break;
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
