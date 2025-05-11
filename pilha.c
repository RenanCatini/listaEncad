#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int data;
    struct No* prox;
}No;

// Mesma funcao de Lista
void printList(No* head) {
    if (head ==  NULL) return; 
    printf("%d ", head->data);
    printList(head->prox);
}

void insertStack(int value, No** head) {
    if (*head == NULL) {
        *head = malloc(sizeof(No));
        (*head)->data = value;
        (*head)->prox = NULL;
        return;
    }
    No* new = malloc(sizeof(No));
    new->data = value;
    new->prox = (*head);
    *head = new;
}

void removeStack(No** head) {
    if(*head == NULL) return;

    No* tmp = (*head)->prox;
    free(*head);
    *head = tmp;
    return;
}



int main () {
    No* cabeca = NULL;
    insertStack(1,&cabeca);
    printList(cabeca);
    puts("");

    insertStack(2,&cabeca);
    printList(cabeca);
    puts("");

    insertStack(3,&cabeca);
    printList(cabeca);
    puts("");

    removeStack(&cabeca);
    printList(cabeca);
    puts("");

    removeStack(&cabeca);
    printList(cabeca);
    puts("");

    insertStack(4,&cabeca);
    printList(cabeca);
    puts("");

    removeStack(&cabeca);
    printList(cabeca);
    puts("");

    // Testar remocao de pilha vazia
    removeStack(&cabeca);
    printList(cabeca);
    puts("");

    return 0;
}

