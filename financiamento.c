
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SAC 1
#define SAF 2
#define SAM 3

void inicializacao(char nome[50]){

    int selecao;
    int seleciona_financiamento;
    char registro[50];

    // Apresenta o menu de seleção
    printf("O que você deseja fazer?\n\n1.Acessar financiamento. \n2.Criar um novo financiamento.\n3. Fechar o programa.\n\n");
    scanf("%d", &selecao); // Recebe a escolha

    if(selecao == 1) {
        printf("Qual financiamento você quer acessar?\n\n"); // Pergunta qual financiamento o usuário quer abrir

        FILE* f = fopen(nome, "r");  // Abre o arquivo

        char linha[PERIODO_MAXIMO];

        while (fgets(linha, sizeof(linha), f) != NULL) {
            printf("%s", linha);  // Mostra os financiamentos registrados no nome do usuário
        }

        /*scanf("%d", &seleciona_financiamento); // Recebe o financiamento que o usuário quer acessar

        for (int i = 1; i <= seleciona_financiamento; i++) {
            printf("%s\n\n", fgets(linha, PERIODO_MAXIMO, f));
        }
         */

        char nome_do_arquivo[100];

        scanf("%s", registro);  // Recebe qual financiamento abrir

        // Monta o nome do arquivo
        strcpy(nome_do_arquivo, nome);
        strcat(nome_do_arquivo, "_");
        strcat(nome_do_arquivo, registro);

        //printf("%s", nome_do_arquivo);

        verifica_debitos(nome_do_arquivo); // Imprime os dados do financiamento

        fclose(f);  // Fecha o arquivo
    }

    else if(selecao == 2){

        cria_financiamento(nome); // Chama a criação de financiamento

    }

    else if(selecao == 3) { // Fecha o programa
        return;
    }
    else {
        printf("Opção inválida, selecione uma opção válida.\n"); // Volta para a tela principal
        inicializacao(nome);
    }
}

void cria_financiamento(char nome[50]) { // Cria um novo financiamento

    char registro[50];
    char nome_do_arquivo[100];

    printf("Qual nome voce gostaria de dar para o seu financiamento?\n");
    scanf("%s", registro);

    // Monta o nome para o arquivo no formato "nome_registro
    strcpy(nome_do_arquivo, nome);
    strcat(nome_do_arquivo, "_");
    strcat(nome_do_arquivo, registro);

    FILE* f = fopen(nome_do_arquivo, "a");  // Abre um arquivo com esse nome
    FILE* f2 = fopen(nome, "a"); // Salva o nome dos financiamentos já existentes


    float montante;
    float taxa_juros;
    float periodo;
    int juros_selecao = 0;

    printf("Digite o valor do financiamento: ");
    scanf("%f", &montante); // Recebe o montante
    printf("Qual o modelo da taxa de juros fornecida?\n1. Anual.\n2. Mensal\n"); // Recebe o tipo de juros que o usuário tem informação
    scanf("%d", &juros_selecao);

    // Usuário selecionou uma opção inválida
    while(juros_selecao != 1 && juros_selecao != 2){
        printf("Opção inválida!\n");
        printf("Qual o modelo da taxa de juros fornecida?\n1. Anual.\n2. Mensal\n");
        scanf("%d", &juros_selecao);
    }

    if(juros_selecao == 1)  // Se for taxa anual
        printf("Qual a taxa de juros anual do seu financiamento?\n");
    if(juros_selecao == 2)  // Se for taxa mensal
        printf("Qual a taxa de juros mensal do seu financiamento?\n");

    scanf("%f", &taxa_juros); // Recebe a taxa de juros

    if (juros_selecao == 1)  // Converte a taxa anual em taxa mensal
        taxa_juros = taxa_juros / 12;

    printf("Em quantas vezes voce ira pagar?\n");
    scanf("%f", &periodo); // Recebe o período para o pagamento

    fprintf(f2, "%s\n", registro);  // Imprime o registro no arquivo "nome"
    fprintf(f, "%.2f\n", montante); // Imprime o montante na primeira linha do arquivo com o nome do registro
    fprintf(f, "%.2f\n", taxa_juros); // Imprime a taxa de juros na terceira linha do arquivo com o nome do registro
    fprintf(f, "%.2f\n", periodo);  // Imprime o periodo na terceira linha do arquivo com o nome do registro

    fclose(f2); // Fecha o arquivo

    int selecao = 0;

    // Recebe o tipo de amortização do financiamento criado
    while(selecao != 1 && selecao != 2 && selecao != 3) {
        printf("Qual o modelo de amortizacao desse financiamento?\n1. Sistema de Amortizacao Comum (SAC)\n2. Sistema de Amortizacao Frances (SAF).\n3. Sistema de Amortizacao Misto(SAM).\n");
        scanf("%d", &selecao); // Recebe o tipo de amortizaçao

        // Caso o usuário selecione errado, pede novamente.
        if(selecao != 1 && selecao != 2 && selecao != 3) // Caso o usuario selecione uma opção errada, pede novamente
            printf("Opção indisponível, tente novamente.\n");
    }

    fprintf(f, "%d\n", selecao);
    fclose(f); // Fecha o arquivo

    // De acordo com a seleção, aplica a amortização correspondente
    if(selecao == 1)
        calcula_prestacao_SAC(nome_do_arquivo, montante, taxa_juros, periodo); // Realiza o cálculo das prestações SAC
    if(selecao == 2)
        calcula_prestacao_SAF(nome_do_arquivo, montante, taxa_juros, periodo); // Realiza o cálculo das prestações SAF
    if(selecao == 3)
        calcula_prestacao_SAM(nome_do_arquivo, montante, taxa_juros, periodo); // Realiza o cálculo das prestações SAM

    printf("Financiamento criado com sucesso!\n\n"); // Sucesso
    verifica_debitos(nome_do_arquivo); // Mostra a situação do financiamento

    printf("\n\n");
}

void recalcula_divida(char registro[50], float montante, float taxa_juros, float periodo, int selecao){

    FILE* f = fopen(registro, "a");  // Abre um arquivo com esse nome

    fprintf(f, "%.2f\n", montante); // Imprime o montante na primeira linha do arquivo com o nome do registro
    fprintf(f, "%.2f\n", taxa_juros); // Imprime a taxa de juros na terceira linha do arquivo com o nome do registro
    fprintf(f, "%.2f\n", periodo);  // Imprime o periodo na terceira linha do arquivo com o nome do registro
    fprintf(f, "%d", selecao);

    fclose(f); // Fecha o arquivo

    // De acordo com a seleção, aplica a amortização correspondente
    if(selecao == 1)
        calcula_prestacao_SAC(registro, montante, taxa_juros, periodo); // Realiza o cálculo das prestações SAC
    if(selecao == 2)
        calcula_prestacao_SAF(registro, montante, taxa_juros, periodo); // Realiza o cálculo das prestações SAF
    if(selecao == 3)
        calcula_prestacao_SAM(registro, montante, taxa_juros, periodo); // Realiza o cálculo das prestações SAM

    printf("Financiamento recalculado com sucesso!\n\n"); // Sucesso
    verifica_debitos(registro); // Mostra a situação do financiamento

    printf("\n\n");

}

// Realiza o cálculo da prestação com base no Sistema de Amortização Comum
void calcula_prestacao_SAC(char registro[50], float montante, float taxa_juros, float periodo) {
    FILE* f = fopen(registro, "a"); // Abre o arquivo em modo anexo

    float amortizacao = montante / periodo;  // Calcula a amortização
    float taxa_juros_dec = taxa_juros / 100;  // Transforma a taxa de juros percentual em decimal
    float juros;
    float prestacao;
    float saldo_devedor = montante;

    for (int i = 0; i < periodo; i++) {  // Percorre as prestações com base no período
        juros = saldo_devedor * taxa_juros_dec;  // Calcula o valor dos juros
        prestacao = amortizacao + juros;  // Define a prestação
        saldo_devedor -= amortizacao;  // Atualiza o saldo devedor

        fprintf(f, "%.2f\n", prestacao);  // Insere as prestações no arquivo
    }

    fclose(f); // Fecha o arquivo
}

// Realiza o cálculo da prestação com base no Sistema de Amortização Francês
void calcula_prestacao_SAF(char registro[50], float montante, float taxa_juros, float periodo) {
    FILE* f = fopen(registro, "a"); // Abre o arquivo em modo anexo

    float taxa_juros_dec = taxa_juros / 100;  // Transforma a taxa de juros percentual em decimal
    float prestacao = montante * (taxa_juros_dec / (1 - pow(1 + taxa_juros_dec, -periodo))); // Aplica a fórmula do SAF

    for (int i = 0; i < periodo; i++) {  // Percorre as prestações com base no período
        float juros = montante * taxa_juros_dec; // Calcula os juros
        float amortizacao = prestacao - juros; // Faz a amortização
        montante -= amortizacao; // Atualiza o montante

        fprintf(f, "%.2f\n", prestacao);  // Insere as prestações no arquivo
    }

    fclose(f); // Fecha o arquivo
}


void calcula_prestacao_SAM(char registro[50], float montante, float taxa_juros, float periodo) {
    FILE* f = fopen(registro, "a"); // Abre o arquivo em modo anexo

    float amortizacao = montante / periodo;  // Calcula a amortização
    float taxa_juros_dec = taxa_juros / 100;  // Transforma a taxa de juros percentual em decimal
    float prestacao = montante * (taxa_juros_dec / (1 - pow(1 + taxa_juros_dec, -periodo)));
    float saldo_devedor = montante;

    for (int i = 0; i < periodo; i++) {  // Percorre as prestações com base no período
        float juros = saldo_devedor * taxa_juros_dec; // Calcula os juros
        prestacao = amortizacao + juros; // Calcula as prestações
        saldo_devedor -= amortizacao; // Atualiza o saldo devedor

        fprintf(f, "%.2f\n", prestacao);  // Insere as prestações no arquivo
    }

    fclose(f); // Fecha o arquivo
}

// Função que avalia a situação do financiamento do usuário
void verifica_debitos(char registro[50]) {

    FILE *f = fopen(registro, "r"); // Abre o arquivo no modo leitura

    char linha[PERIODO_MAXIMO];
    float soma = 0.0;
    float valor_inicial = 0.0;
    int linha_count = 0;
    int selecao;
    float proxima_prestacao;

    // Percorre o arquivo
    while (fgets(linha, PERIODO_MAXIMO, f) != NULL) {
        linha_count++;

        // Salva o montante inicial
        if (linha_count == 1) {
            valor_inicial = atof(linha);
        }  else if (linha_count == 5) {  // Salva o valor da próxima prestação que o usuário irá pagar
            float prestacao = atof(linha);
            proxima_prestacao = prestacao;
            soma = prestacao;
        } else if (linha_count > 4) { // Calcula quanto falta para quitar o financiamento
            float prestacao = atof(linha);
            soma += prestacao;
        }

    }

    if(soma <= 0) { // Mostra para o usuario que a dívida foi quitada
        printf("Você quitou a sua dívida!\n");
        return;
    }

    fclose(f);

    printf("Valor financiado: %.2f\n", valor_inicial); // Imprime o valor financiado
    printf("Divida restante: %.2f\n", soma);  // Imprime dívida em aberto
    printf("Valor da proxima prestacao: %.2f\n", proxima_prestacao); // Imprime a próxima prestação a ser paga


    printf("O que voce deseja fazer?\n\n1. Pagar.\n2.Abater dívida.\n3. Imprimir prestações.\nPara finalizar aperte qualquer tecla.\n"); // Recebe a ação do usuário
    scanf("%d", &selecao); // Recebe a seleção

    if(selecao == 1) // Chama a função de pagamento
        pagamento(registro);

    if(selecao == 2) // Chama a função de abater a dívida
        abate_divida(registro);

    if(selecao == 3) {
        imprime_prestacoes(registro); // Imprime as prestações
        verifica_debitos(registro); // Volta ao menu
    }
    fclose(f); // Fecha o arquivo

}

void abate_divida(char registro[50]) { // realiza
    FILE* f = fopen(registro, "r"); // Abre o arquivo para leitura
    FILE* f2 = fopen("temp.txt", "w"); // Criar um novo arquivo temporário

    char linha[PERIODO_MAXIMO];
    int contagem = 0;
    int linha_count = 0;

    // Contar o número total de linhas
    while (fgets(linha, sizeof(linha), f) != NULL) {
        linha_count++;
    }

    // Voltar ao início do arquivo
    rewind(f);

    // Copiar as linhas do arquivo original para o arquivo temporário, excluindo a última linha
    while (fgets(linha, sizeof(linha), f) != NULL) {
        contagem++;
        if (contagem != linha_count) {
            fputs(linha, f2);
        }
    }

    // Fechar os arquivos
    fclose(f);
    fclose(f2);

    // Substituir o arquivo original pelo arquivo temporário
    remove(registro);
    rename("temp.txt", registro);

    printf("Pagamento realizado com sucesso!\n\n");

    verifica_debitos(registro);
}



void pagamento(char registro[50]) {
    FILE* f = fopen(registro, "r"); // Abre o arquivo para leitura
    FILE* f2 = fopen("temp.txt", "w"); // Criar um novo arquivo temporário

    char linha[PERIODO_MAXIMO];
    int contagem = 0;

    // Copiar as linhas do arquivo original para o arquivo temporário, excluindo a parcela paga
    while (fgets(linha, sizeof(linha), f) != NULL) {
        contagem++;
        if (contagem != 3) {
            fputs(linha, f2);
        }
    }

    // Fechar os arquivos
    fclose(f);
    fclose(f2);

    // Substituir o arquivo original pelo arquivo temporário
    remove(registro);
    rename("temp.txt", registro);

    printf("Pagamento realizado com sucesso!\n\n");

    verifica_debitos(registro);
}

void imprime_prestacoes(char registro[50]) { // Imprime as prestaçoes para o usuario

    FILE *f = fopen(registro, "r"); // Abre o arquivo no modo leitura

    printf("Suas prestações futuras são:");

    int i = 0;
    // Percorre o arquivo
    char linha[100];
    while (fgets(linha, sizeof(linha), f) != NULL) {
        printf("%d) %s", i, linha);
        i++;
    }

    fclose(f); // Fecha o arquivo

}