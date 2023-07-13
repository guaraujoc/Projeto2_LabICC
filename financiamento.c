#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void inicializacao(char nome[50]){

    int selecao;
    int seleciona_financiamento;
    char registro[50];

    printf("O que você deseja fazer?\n\n1.Acessar financiamento. \n2.Criar um novo financiamento.\n3. Fechar o programa.\n\n");
    scanf("%d", &selecao);

    if(selecao == 1) {
        printf("Qual financiamento você quer acessar?\n\n");

        FILE* f = fopen(nome, "r");

        char linha[PERIODO_MAXIMO];

        while (fgets(linha, sizeof(linha), f) != NULL) {
            printf("%s", linha);
        }

        scanf("%d", &seleciona_financiamento);

        for (int i = 1; i <= seleciona_financiamento; i++) {
            fgets(linha, PERIODO_MAXIMO, f);
        }

        char nome_do_arquivo[100];

        scanf("%s", registro);

        strcpy(nome_do_arquivo, nome);
        strcat(nome_do_arquivo, registro);

        printf("%s", nome_do_arquivo);

        verifica_debitos(nome_do_arquivo);
    }

    else if(selecao == 2){

        cria_financiamento(nome);

    }

    else if(selecao == 3)
        return;

    else {
        printf("Opção inválida, selecione uma opção válida.");
        inicializacao(nome);
    }
}

void cria_financiamento(char nome[50]) { // Cria um novo financiamento

    char registro[50];
    char nome_do_arquivo[100];

    printf("Qual nome voce gostaria de dar para o seu financiamento?\n");
    scanf("%s", registro);

    strcpy(nome_do_arquivo, nome);
    strcat(nome_do_arquivo, registro);

    FILE* f = fopen(nome_do_arquivo, "a");  // Abre um arquivo com esse nome
    FILE* f2 = fopen(nome, "a"); // Salva o nome dos financiamentos já existentes


    float montante;
    float taxa_juros;
    float periodo;
    int juros_selecao;

    printf("Digite o valor do financiamento: ");
    scanf("%f", &montante); // Recebe o montante
    printf("Qual o modelo da taxa de juros fornecida?\n1. Anual.\n2. Mensal\n");
    scanf("%d", &juros_selecao);

    while(juros_selecao != 1 && juros_selecao != 2){
        printf("Opção inválida!\n");
        printf("Qual o modelo da taxa de juros fornecida?\n1. Anual.\n2. Mensal\n");
        scanf("%d", &juros_selecao);
    }

    if(juros_selecao == 1)
        printf("Qual a taxa de juros anual do seu financiamento?\n");
    if(juros_selecao == 2)
        printf("Qual a taxa de juros mensal do seu financiamento?\n");

    scanf("%f", &taxa_juros); // Recebe a taxa de juros mensal

    if (juros_selecao == 1)
        taxa_juros = taxa_juros / 12;

    printf("Em quantas vezes voce ira pagar?\n");
    scanf("%f", &periodo); // Recebe o período para o pagamento

    fprintf(f2, "%s\n", registro);  // Imprime o registro no arquivo "dados.txt"
    fprintf(f, "%.2f\n", montante); // Imprime o montante na primeira linha do arquivo com o nome do registro
    fprintf(f, "%.0f\n", periodo);  // Imprime o periodo na primeira linha do arquivo com o nome do registro

    fclose(f); // Fecha o arquivo
    fclose(f2);

    int selecao = 0;

    while(selecao != 1 && selecao != 2 && selecao != 3) {
        printf("Qual o modelo de amortizacao desse financiamento?\n1. Sistema de Amortizacao Comum (SAC)\n2. Sistema de Amortizacao Frances (SAF).\n3. Sistema de Amortizacao Misto(SAM).\n");
        scanf("%d", &selecao); // Recebe o tipo de amortizaçao

        if(selecao != 1 && selecao != 2 && selecao != 3) // Caso o usuario selecione uma opção errada, pede novamente
            printf("Opção indisponível, tente novamente.");
    }

    if(selecao == 1)
        calcula_prestacao_SAC(nome_do_arquivo, montante, taxa_juros, periodo); // Realiza o cálculo das prestações SAC
    if(selecao == 2)
        calcula_prestacao_SAF(nome_do_arquivo, montante, taxa_juros, periodo); // Realiza o cálculo das prestações SAF
    if(selecao == 3)
        calcula_prestacao_SAM(nome_do_arquivo, montante, taxa_juros, periodo); // Realiza o cálculo das prestações SAM

    printf("Financiamento criado com sucesso!\n\n");
    verifica_debitos(nome_do_arquivo);

    printf("\n\n");
}

void calcula_prestacao_SAC(char registro[50], float montante, float taxa_juros, float periodo) {
    FILE* f = fopen(registro, "a");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

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

    fclose(f);
}

void calcula_prestacao_SAF(char registro[50], float montante, float taxa_juros, float periodo) {
    FILE* f = fopen(registro, "a");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    float amortizacao = montante / periodo;  // Calcula a amortização
    float taxa_juros_dec = taxa_juros / 100;  // Transforma a taxa de juros percentual em decimal
    float prestacao = montante * (taxa_juros_dec/ (1 - pow(1 + taxa_juros_dec, -periodo))); // Aplica a fórmula do SAF
    float saldo_devedor = montante;

    for (int i = 0; i < periodo; i++) {  // Percorre as prestações com base no período
        float juros = montante * taxa_juros_dec;
        float amortizacao = prestacao - juros;
        montante -= amortizacao;

        fprintf(f, "%.2f\n", prestacao);  // Insere as prestações no arquivo
    }

    fclose(f);
}

void calcula_prestacao_SAM(char registro[50], float montante, float taxa_juros, float periodo) {
    FILE* f = fopen(registro, "a");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    float amortizacao = montante / periodo;  // Calcula a amortização
    float taxa_juros_dec = taxa_juros / 100;  // Transforma a taxa de juros percentual em decimal
    float juros;
    float prestacao = montante * (taxa_juros_dec/ (1 - pow(1 + taxa_juros_dec, -periodo)));
    float saldo_devedor = montante;

    for (int i = 0; i < periodo; i++) {  // Percorre as prestações com base no período
        juros = saldo_devedor * taxa_juros_dec * (periodo - i + 1)/((periodo + 1) * 2);
        prestacao = amortizacao + juros;
        saldo_devedor -= amortizacao;

        if(i == periodo){
            saldo_devedor -= juros;
        }

        fprintf(f, "%.2f\n", prestacao);  // Insere as prestações no arquivo
    }

    fclose(f);
}

void verifica_debitos(char registro[50]) {

    FILE *f = fopen(registro, "r");

    char linha[PERIODO_MAXIMO];
    float soma = 0.0;
    float valor_inicial = 0.0;
    int linha_count = 0;
    int selecao;
    float proxima_prestacao;

    while (fgets(linha, PERIODO_MAXIMO, f) != NULL) {
        linha_count++;
        if (linha_count == 1) {
            valor_inicial = atof(linha);
        }  else if (linha_count == 3) {
            float prestacao = atof(linha);
            proxima_prestacao = prestacao;
        } else if (linha_count > 2) {
            float prestacao = atof(linha);
            soma += prestacao;
        }

    }

    fclose(f);

    printf("Divida restante: %.2f\n", soma);
    printf("Valor da próxima prestação: %.2f\n", proxima_prestacao);

    printf("O que voce deseja fazer?\n\n1. Pagar.\n2.Amortizar.\n3. Excluir registro.\nPara finalizar aperte qualquer tecla.\n");
    scanf("%d", &selecao);

    if(selecao == 1)
        pagamento(registro);

    if(selecao == 2){
        printf("Voce tem certeza que quer excluir esse financiamento?\n\n1. Sim\n");
        int confirmacao;
        scanf("%d",&confirmacao);
        if(confirmacao == 2) {
            exclui_registro(registro);
            printf("Financiamento excluido com sucesso!");
        }
    }

}


void pagamento(char registro[50]) {
    FILE* file = fopen(registro, "r"); // Abre o arquivo para leitura
    FILE* fileTemp = fopen("temp.txt", "w"); // Criar um novo arquivo temporário

    char linha[PERIODO_MAXIMO];
    int contagem = 0;

    // Copiar as linhas do arquivo original para o arquivo temporário, excluindo a parcela paga
    while (fgets(linha, sizeof(linha), file) != NULL) {
        contagem++;
        if (contagem != 3) {
            fputs(linha, fileTemp);
        }
    }

    // Fechar os arquivos
    fclose(file);
    fclose(fileTemp);

    // Substituir o arquivo original pelo arquivo temporário
    remove(registro);
    rename("temp.txt", registro);

    printf("Pagamento realizado com sucesso!");

    verifica_debitos(registro);
}

void exclui_registro(char registro[50]) {
    // Abrir o arquivo para leitura
    FILE* file = fopen(registro, "r");

    char nome[50];
    printf("Digite o nome a ser procurado: "); // Recebe o nome no registro a ser excluído
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remove o registro

    FILE* fileTemp = fopen("temp.txt", "w"); // Criar um novo arquivo temporário

    char line[PERIODO_MAXIMO];

    while (fgets(line, sizeof(line), file) != NULL) { // Procur o nome no arquivo e exclui a linha correspondente
        if (strstr(line, nome) == NULL) {
            fputs(line, fileTemp);
        }
    }

    // Fecha os arquivos
    fclose(file);
    fclose(fileTemp);

    // Substitui o arquivo original pelo arquivo temporário
    remove(registro);
    rename("temp.txt", registro);
    remove(nome);
}



