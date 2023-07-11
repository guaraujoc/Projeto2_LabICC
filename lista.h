typedef struct {
    char registro[50];
    float valor;
    float juros;
    float periodo;
} Prestacao;

void identifica_usuario(usuario* user); // localiza usuário no arquivo
int verifica_debitos(usuario* user);  // verifica se há financiamentos no seu nome
int cria_financiamento(usuario* user, financiamento* financiamento); // cria um financiamento no seu nome
void calcula_prestacao(financiamento* financiamento); // calcula o valor da prestação
void realiza_pagamento(pagamento* pagamento);  // paga a prestação e recalcula o financiamento
void realiza_amortizacao(financiamento* financiamento);  // amortiza a dívida
void amortizacao_sac(financiamento* financiamento);  // fórmulas da amortização SAC
void amortizacao_saf(financiamento* financiamento);  // fórmulas da amortização SAC
void amortizacao_sam(financiamento* financiamento);  // fórmulas da amortização SAC

