#include <stdio.h>
#include <stdlib.h>

// Definir estrutura de no
typedef struct No {
    int data;
    struct No* prox;  
}No;

// Inserir valor na fila
void insertQueue(int value, No** head) {
    if (*head == NULL) {
        (*head) = malloc(sizeof(No));
        (*head)->data = value;
        (*head)->prox = NULL;
        return;
    }
    else if ((*head)->prox == NULL) {
        No* new = malloc(sizeof(No));
        new->data = value;
        new->prox = NULL;
        (*head)->prox = new;
        return;
    }

    insertQueue(value,&(*head)->prox);
}

// Mesma funcao de Lista
void printList(No* head) {
    if (head ==  NULL) return; 
    printf("%d ", head->data);
    printList(head->prox);
}


void removeQueue(No** head) {
    if (*head == NULL) return;

    No* tmp = (*head)->prox;
    free(*head);
    *head = tmp;
    return;
}


int main() {
    No* cabeca = NULL;


    insertQueue(3, &cabeca);
    printList(cabeca);
    puts("");

    insertQueue(4, &cabeca);
    printList(cabeca);
    puts("");

    insertQueue(5, &cabeca);
    printList(cabeca);
    puts("");

    removeQueue(&cabeca);
    printList(cabeca);
    puts("");

    removeQueue(&cabeca);
    printList(cabeca);
    puts("");

    insertQueue(6, &cabeca);
    printList(cabeca);
    puts("");

    removeQueue(&cabeca);
    printList(cabeca);
    puts("");

    // Testar remocao de fila vazia
    removeQueue(&cabeca);
    printList(cabeca);
    puts("");

 
    return 0;
}

