//Pilha

#include <stdio.h>

#define TAMANHO 5

typedef struct {
    int itens[TAMANHO]; 
    int topo;
} Pilha;

//Inicializando a pilha
void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

//Verificando se a pilha está vazia
int pilhaVazia(Pilha *pilha) {
    return (pilha->topo == -1);
}

//Verificando se a pilha está cheia
int pilhaCheia(Pilha *pilha) {
    return (pilha->topo == TAMANHO - 1);
}

//Empilhando (push)
void empilhar(Pilha *pilha, int valor) {
    if (pilhaCheia(pilha)) {
        printf("Pilha cheia!\n");
    } else {
        pilha->topo++;
        pilha->itens[pilha->topo] = valor;
        printf("Empilhado: %d\n", valor);
    }    
}

//Desempilhar (pop)
int desempilhar(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        int valor = pilha->itens[pilha->topo];
        pilha->topo--;
        return valor;
    }   
}

//Consultando o topo
int consultar(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha->itens[pilha->topo];
    }    
}

//Testando o código
int main() {
    //Crio a pilha e inicializo
    Pilha pilha;
    inicializarPilha(&pilha);

    //Empilhando valores
    empilhar(&pilha, 11);
    empilhar(&pilha, 22);
    empilhar(&pilha, 33);

    //Consultando o topo da pilha
    printf("Topo da pilha: %d\n", consultar(&pilha)); //será o 33

    //Removendo um elemento da pilha
    //Sempre será o último -> LIFO
    desempilhar(&pilha);

    //Novo topo
    printf("Topo apos desempilhar: %d\n", consultar(&pilha)); //agora será o 22

    return 0;
}