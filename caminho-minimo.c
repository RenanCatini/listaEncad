#include <stdio.h>
#include <stdlib.h>

// Estrutura da lista encadeada
typedef struct No {
    int data;
    struct No* prox;
} No;

#define VERTICES 5

// Função para buscar valor na lista
int searchList(int value, No* head) {
    if (head == NULL) return 0;
    if (head->data == value) return 1;
    return searchList(value, head->prox);
}

// Empilhar (inserir no início)
void insertStack(int value, No** head) {
    No* new = malloc(sizeof(No));
    new->data = value;
    new->prox = *head;
    *head = new;
}

// Desempilhar (remover do início)
void removeStack(No** head) {
    if (*head == NULL) return;
    No* temp = *head;
    *head = (*head)->prox;
    free(temp);
}

// Imprimir lista
void printList(No* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->prox;
    }
    printf("\n");
}

// Liberar memória da lista
void freeList(No* head) {
    while (head != NULL) {
        No* temp = head;
        head = head->prox;
        free(temp);
    }
}

// Função principal para encontrar caminhos e registrar pesos
int caminhos(int numOfVert, int mat[numOfVert][numOfVert],
             int source, int arrival, No** way, No** ways, int part) {

    insertStack(source, way);

    if (source == arrival) {
        insertStack(part, ways);
        removeStack(way);
        return 1;
    }

    for (int i = 0; i < numOfVert; i++) {
        if (mat[source][i] > 0 && !searchList(i, *way)) {
            caminhos(numOfVert, mat, i, arrival, way, ways, part + mat[source][i]);
        }
    }

    removeStack(way);
    return 0;
}

int minOfList(No* head, int aux){
    if(head == NULL) return aux;
    if(head->data < aux) return minOfList(head->prox, head->data);
    else return minOfList(head->prox, aux);
}

// Funcao para encontrar o melhor caminho... simplificada
int menorCaminho(int numOfVert, int mat[numOfVert][numOfVert],int source, int arrival) {
    No* caminho = NULL;
    No* valores = NULL;
    caminhos(numOfVert, mat, source, arrival, &caminho, &valores, 0);
    int resul = minOfList(valores, __INT_MAX__);
    freeList(caminho);
    freeList(valores);

    return resul ==  __INT_MAX__ ? 0 : resul;
}

int main() {

    
    int grafo1[VERTICES][VERTICES] = {
        {  0,  4,  2, -1, -1 }, // A
        {  4,  0,  5, 10, -1 }, // B
        {  2,  5,  0, -1,  3 }, // C
        { -1, 10, -1,  0,  4 }, // D
        { -1, -1,  3,  4,  0 }  // E
    };

    int grafo2[VERTICES][VERTICES] = {
        {  0,  4,  2, -1, -1 }, // A
        {  4,  0,  5, 10, -1 }, // B
        {  2,  5,  0, -1,  3 }, // C
        { -1, 10, -1,  0,  -1 }, // D
        { -1, -1,  3,  -1,  0 }  // E
    };

    int grafo3[VERTICES][VERTICES] = {
        {  0,  4,  2, -1, -1 }, // A
        {  4,  0,  5, -1, -1 }, // B
        {  2,  5,  0, -1,  3 }, // C
        { -1, -1, -1,  0,  -1 }, // D
        { -1, -1,  3,  -1,  0 }  // E
    };

    int teste1 = menorCaminho(VERTICES, grafo1, 0, 3);
    int teste2 = menorCaminho(VERTICES, grafo2, 0, 3);
    int teste3 = menorCaminho(VERTICES, grafo3, 0, 3);

    printf("- Menor caminho grafo 1: %d\n", teste1);
    printf("- Menor caminho grafo 2: %d\n", teste2);
    printf("- Menor caminho grafo 3: %d\n", teste3);

    return 0;
}
