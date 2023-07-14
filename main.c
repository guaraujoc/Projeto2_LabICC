#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    //int prestacao = valor_linha("Carlos_Carro", 4);
    //printf("%d", prestacao);

    char nome[50];

    printf("Qual o seu nome?\n");
    scanf("%s", nome);
    inicializacao(nome);

}

