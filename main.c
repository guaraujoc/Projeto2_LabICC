#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char nome[50];

    printf("Qual o seu nome?\n");
    scanf("%s", nome);
    inicializacao(nome);

}

