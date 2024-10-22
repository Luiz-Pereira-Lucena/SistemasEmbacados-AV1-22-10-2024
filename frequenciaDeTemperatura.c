#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int count;
    struct Node* next;
};

void insertNode(struct Node** head_ref, int new_data) {
    struct Node* temp = *head_ref;
    while (temp != NULL) {
        if (temp->data == new_data) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->count = 1;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void sortList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* index = NULL;
    int tempData, tempCount;

    while (current != NULL) {
        index = current->next;

        while (index != NULL) {
            if (current->count < index->count) {
                tempData = current->data;
                tempCount = current->count;

                current->data = index->data;
                current->count = index->count;

                index->data = tempData;
                index->count = tempCount;
            }
            index = index->next;
        }
        current = current->next;
    }
}

void printList(struct Node* node) {
    while (node != NULL) {
        if(node->count > 1){
            printf("%d - %d vezes \n", node->data, node->count);
            node = node->next;
        }else{
            printf("%d - %d vez \n", node->data, node->count);
            node = node->next;
        }
    }
}

void header(){
    printf("RELATÓRIO DE FREQUÊNCIA \n");
    printf("======================= \n");
}

int main() {
    struct Node* head = NULL;
    int str1;
    
    for(int contador = 1; contador <= 20; contador++)
    {
        printf("Digite uma temperatura : ");
        scanf("%d", &str1);
        insertNode(&head, str1);
    }

    sortList(&head);
    header();
    printList(head);

    return 0;
}

