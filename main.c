//Fila

#include <stdio.h>

#define TAMANHO 5

typedef struct {
    int itens[TAMANHO];
    int inicio, fim;
} Fila;

//Inicializando a fila
void inicializarFila(Fila *fila) {
    fila->inicio = -1;
    fila->fim = -1;
}

//Verificar se a fila está vazia
int filaVazia(Fila *fila) {
    return (fila->inicio == -1);
}

//Verificar se a fila está cheia
int filaCheia(Fila *fila) {
    return (fila->fim == TAMANHO - 1);
}

//Enfileirando na fila
void enfileirar(Fila *fila, int valor) {
    if (filaCheia(fila)) {
        printf("Fila cheia!\n");
    } else {
        if (fila->inicio == -1) {
            fila->inicio = 0;
        }
        fila->fim++;
        fila->itens[fila->fim] = valor;
        printf("Enfileirado: %d\n", valor);        
    }    
}

//Desenfileirando da fila
int desenfileirar(Fila *fila) {
    int valor;
    if (filaVazia(fila)) {
        printf("Fila vazia!\n");
        return -1;
    } else {
        valor = fila->itens[fila->inicio];
        fila->inicio++;
        if (fila->inicio > fila->fim) {
            fila->inicio = fila->fim = -1; //Para resetar a fila
        }
        return valor;        
    }    
}

//Consultar o início da fila
int consultar(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia!\n");
        return -1;
    } else {
        return fila->itens[fila->inicio];
    }    
}

//Testando o código
int main() {
    //Crio a fila e inicializo
    Fila fila;
    inicializarFila(&fila);

    //Depois coloco elementos na fila
    enfileirar(&fila, 11);
    enfileirar(&fila, 22);
    enfileirar(&fila, 33);

    //Consultando o início dela
    printf("Inicio da fila: %d\n", consultar(&fila)); //no caso aparece o valor 11

    //Removendo um elemento da fila
    //Sempre será o primeiro -> FIFO
    desenfileirar(&fila);

    //Novo início
    printf("Inicio apos desenfileirar: %d\n", consultar(&fila)); //agora vai aparecer o 22

    return 0;
}