typedef struct {

    char nome[50];

} usuario; // salva as informações do usuário

typedef struct {

    int id;  // portador do financiamento
    float valor;  // valor total
    float juros;  // valor dos juros

} financiamento; // salva as características do financiamento

typedef struct {

    int id_financiamento;   // localiza o financiamento
    float valor_prestacao;  // valor de cada prestação
    float valor_amortizacao;  // valor da amortização

} pagamento; // recalcula as características do financiamento

void identifica_usuario(usuario* user); // localiza usuário no arquivo
int verifica_debitos(usuario* user);  // verifica se há financiamentos no seu nome
int cria_financiamento(usuario* user, financiamento* financiamento); // cria um financiamento no seu nome
void calcula_prestacao(financiamento* financiamento); // calcula o valor da prestação
void realiza_pagamento(pagamento* pagamento);  // paga a prestação e recalcula o financiamento
void realiza_amortizacao(financiamento* financiamento);  // amortiza a dívida
void amortizacao_sac(financiamento* financiamento);  // fórmulas da amortização SAC
void amortizacao_saf(financiamento* financiamento);  // fórmulas da amortização SAC
void amortizacao_sam(financiamento* financiamento);  // fórmulas da amortização SAC

