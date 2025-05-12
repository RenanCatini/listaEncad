#include <stdio.h>
#include <stdlib.h>

//estrutura do no
typedef struct No {
    int data;
    struct No* prox;  
}No;

#define VERTICES 5

int searchList(int value, No* head) {
    if(head == NULL) return 0;
    if(head->data == value) return 1;
    else return searchList(value, head->prox);
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

// ----------------------------------------------------------------------------- // 


int caminhos( int numOfVert, int mat[numOfVert][numOfVert], int source, int arrival, No** way, No** ways) {
    
    if(source < 0 || source >= numOfVert) return 0;
    if(source == arrival){
        return 0;
    }

    if(*way == NULL) {
        *way = malloc(sizeof(No));
        (*way)->data = source;
        (*way)->prox = NULL;
    }
    else {
        insertStack(source, way);
    }

    for(int i = 0; i < numOfVert; i++) {
        if(mat[source][i] > 0 && searchList(i, *way) == 0){
            return caminhos(numOfVert, mat, i, arrival, way, ways) + mat[source][i];           
        }

    }

}



int main() {
    // Grafo fixo com 5 vértices (0 a 4)
    // -1 indica ausência de aresta entre os vértices
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

    No* caminho = NULL;
    int aux = caminhos(VERTICES, grafo1, 0, 3, &caminho);
    printf("%d \n", aux);
    free(caminho);

    caminho = NULL;
    aux = caminhos(VERTICES, grafo2, 0, 3, &caminho);
    printf("%d \n", aux);


}