#define PERIODO_MAXIMO 10000 // Define a quantidade máxima de prestações

void inicializacao(char nome[50]);
void cria_financiamento(char nome[50]);
void calcula_prestacao_SAC(char registro[50], float montante, float taxa_juros, float periodo);
void calcula_prestacao_SAF(char registro[50], float montante, float taxa_juros, float periodo);
void calcula_prestacao_SAM(char registro[50], float montante, float taxa_juros, float periodo);
void verifica_debitos(char registro[50]);
void pagamento(char registro[50]);
void exclui_registro(char registro[50]);
//void nome_arquivo(char nome[50], char registro[50], char nome_do_arquivo[100]);

