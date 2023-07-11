#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FECHAR 5

void cria_conta(const char* nome){
    FILE* arquivo = fopen(nome, "a"); // Cria arquivo com o nome do usuário
}

void inicializacao(){

    int selecao;
    char nome;
    printf("Voce ja possui cadastro?\n 1.Sim \n 2.Nao");
    scanf("%d\n", &selecao);

    if(selecao == 1) {
        printf("Escolha um nome para o registro:");
        scanf("%s", &nome);
        cria_conta(&nome);
    }

    if(selecao == 2){
        printf("Qual o seu registro?");
        scanf("%s", &nome);
        verifica_debitos(&nome);
    }
}

void cria_registro(){  // cria o regitro

    Prestacao prestacoes;
    FILE* arquivo;
    char registro[50];

    printf("Escolha um nome para o seu financiamento"); // Recebe um nome para o registro
    scanf("%s", registro);

    strcpy(prestacoes.registro, registro);  // Salva a string

    printf("Qual o valor total do seu financiamento?");  // Recebe o montante
    scanf("%f", &prestacoes.valor);

    printf("Qual a taxa de juros mensal?");  // Recebe a taxa de juros mensal
    scanf("%f", &prestacoes.juros);

    printf("Deseja pagar em quanto tempo?");  // Recebe o período do pagamento
    scanf("%f", &prestacoes.periodo);

    fprintf(arquivo, "Registro: %s\n", prestacoes.registro);  // Insere o registro no arquivo
    fprintf(arquivo, "Valor: %f\n", prestacoes.valor);  // Insere o montante
    fprintf(arquivo, "Juros: %f\n", prestacoes.juros);  // Insere o valor dos juros
    fprintf(arquivo, "Periodo: %f\n", prestacoes.periodo);  // Insere o período

    calcula_prestacao(); // Calcula o valor de cada prestação

}
void identifica_usuario(usuario* user) { // localiza usuário no arquivo

    FILE* arquivo_usuarios = fopen("usuarios.txt", "r");

    while(fscanf(arquivo_usuarios, "%s", user.nome) != EOF){
        if(strcmp(user.nome, /*usuario*/) == 0){
            verifica_debitos(/*usuario*/);
            break;
        }
    }

    fclose(arquivo_usuarios);
}

int verifica_debitos(const char* nome){

    Prestacao prestacoes;
    FILE* arquivo = fopen(nome, "r");
    int num, selecao;
    char *opcoes[50];

    if(arquivo == NULL) {
        printf("Seu registro nao foi encontrado, tente novamente"); // Não foi encontrado o registro
        //inicializacao(); // Retorna para a inicialização
        return 1;
    }

    printf("Qual financiamento você gostaria de acessar?");

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, "Registro: ") != NULL) {
            char* registro = strchr(linha, ':'); // Encontra a posição do primeiro ':' na linha
            if (registro != NULL) {
                registro += 2; // Avança para o próximo caractere após o ':'
                printf("%d. %s", num, registro);
                opcoes[num] = registro;
                num++;
            }
        }
    }

    scanf("%d", &selecao);


}

int cria_financiamento(usuario* user, financiamento* financiamento) { // cria um financiamento no seu nome
    FILE* arquivo_usuarios = fopen("usuarios.txt", "w");

    int selecao;
    int juros, juros_am, periodo, tempo;
    fprintf(arquivo_usuarios, "Financiamento: %s", user.financiamento);

    printf("Qual o valor percentual dos juros?"\n);
    scanf("%d", &juros);
    printf("Esse valor corresponde a quantos meses? (Exemplo: Se for ao ano, escreva 12.)\n");
    scanf("%d", &periodo);
    juros_am = juros/periodo;

    printf("Qual a duração do financiamento em meses?");
    scanf("%d", tempo);

    fprintf(arquivo_usuarios, "Juros ao mês: %d", juros_am);

    calcula_prestacao();

}
void salva_informacoes();
void calcula_prestacao(financiamento, tempo, amortizacao); // calcula o valor da prestação
void realiza_pagamento(pagamento* pagamento);  // paga a prestação e recalcula o financiamento
void realiza_amortizacao(financiamento* financiamento);  // amortiza a dívida
void amortizacao_sac(financiamento* financiamento);  // fórmulas da amortização SAC
void amortizacao_saf(financiamento* financiamento);  // fórmulas da amortização SAC
void amortizacao_sam(financiamento* financiamento);  // fórmulas da amortização SAC