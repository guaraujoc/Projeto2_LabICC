<<<<<<< HEAD
typedef struct {
    char nome[50];
} Usuario;

typedef struct {
    int id;
    float valor;
    float juros;
    // Outros campos relevantes do financiamento
} Financiamento;

typedef struct {
    int idFinanciamento;
    float valorPrestacao;
    float valorAmortizacao;
    // Outros campos relevantes do pagamento
} Pagamento;

void identifica_usuario(Usuario* user);
int verifica_debitos(Usuario* user);
int cria_financiamento(Usuario* user, Financiamento* financiamento);
void calcula_prestacao(Financiamento* financiamento);
void realiza_pagamento(Pagamento* pagamento);
void realiza_amortizacao(Financiamento* financiamento);
void amortizacao_sac(Financiamento* financiamento);
void amortizacao_saf(Financiamento* financiamento);
void amortizacao_sam(Financiamento* financiamento);
void recalcula_prestacao(Financiamento* financiamento);
=======

>>>>>>> origin/main
