#include <stdio.h>
#include <stdlib.h>

//estrutura do no
typedef struct No {
    int data;
    struct No* prox;  
}No;

// Funcao de inserir No no final
void insertEnd (int value, No** head) {
    
     
    if (*head == NULL) {    // Testar se a cabeca eh nula
        *head = malloc(sizeof(No));
        (*head)-> data = value;
        (*head)-> prox = NULL;
        return;

    }
    else if ((*head)->prox == NULL) {   // Ver se o proximo eh para adicionar
        No* new = malloc(sizeof(No));
        new->prox = NULL;
        new->data = value;
        (*head)->prox = new;
        return;
    } 

    insertEnd(value, &((*head)->prox));
}

// Funcao de imprimir lista encadeada
void printList(No* head) {
    if (head ==  NULL) return; 
    printf("%d ", head->data);
    printList(head->prox);
}

void removeList(int value, No** head) {
    if ((*head)->data == value) {
        No *tmp = *head;
        *head = (*head)->prox;
        free(tmp);
        return;
    } 
    else if (((*head)->prox)->data == value) {
        No *tmp = (*head)->prox;
        (*head)->prox = ((*head)->prox)->prox;
        free(tmp);
        return;
    }

    removeList(value, &((*head)->prox));
}

int main () {
    No* cabeca = NULL;

    insertEnd(1, &cabeca);
    printList(cabeca);
    puts("");

    insertEnd(2, &cabeca);
    printList(cabeca);
    puts("");

    insertEnd(3, &cabeca);
    printList(cabeca);
    puts("");

    insertEnd(4, &cabeca);
    printList(cabeca);
    puts("");

    insertEnd(5, &cabeca);
    printList(cabeca);
    puts("");

    removeList(2,&cabeca);
    printList(cabeca);
    puts("");

    removeList(5,&cabeca);
    printList(cabeca);
    puts("");

    removeList(1,&cabeca);
    printList(cabeca);
    puts("");

    return 0;
}


