/*

Universidade de São Paulo
Instituto de Ciências Matemáticas e de Computação
SSC0601 – Laboratório de Introdução à Ciência de Computação I
Aluno: Gustavo Carvalho Araújo / 13735630
Aluno: João Pedro Gomes / 13839069

 */

#include <stdio.h>
#define PERIODO_MAXIMO 10000 // Define a quantidade máxima de prestações

void inicializacao(char* nome);
void cria_financiamento(char* nome);
void calcula_prestacao_SAC(char* registro, float montante, float taxa_juros, float periodo);
void calcula_prestacao_SAF(char* registro, float montante, float taxa_juros, float periodo);
void calcula_prestacao_SAM(char* registro, float montante, float taxa_juros, float periodo);
void verifica_debitos(char* registro);
void pagamento(char* registro);
void abate_divida(char* registro);
void imprime_prestacoes(char* registro);
