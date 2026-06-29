#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char nomeArquivo[50];
    int paginas;
    char tipo; // N ou P
} Trabalho;

Trabalho filaNormal[MAX];
int inicioNormal = 0;
int fimNormal = 0;
int quantidadeNormal = 0;

Trabalho filaPrioritaria[MAX];
int inicioPrioritaria = 0;
int fimPrioritaria = 0;
int quantidadePrioritaria = 0;

void adicionarTrabalho();
void processarImpressao();
void listarFilas();
void buscarTrabalho();
void cancelarTrabalho();
void salvarCSV();
void carregarCSV();

int main() {
    int opcao;

    carregarCSV();

    do {
        printf("\n=== FILA DE IMPRESSAO ===\n");
        printf("1 - Adicionar trabalho\n");
        printf("2 - Processar impressão\n");
        printf("3 - Listar filas\n");
        printf("4 - Buscar trabalho\n");
        printf("5 - Cancelar trabalho\n");
        printf("6 - Salvar e sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                adicionarTrabalho();
                break;
            case 2:
                processarImpressao();
                break;
            case 3:
                listarFilas();
                break;
            case 4:
                buscarTrabalho();
                break;
            case 5:
                cancelarTrabalho();
                break;
            case 6:
                salvarCSV();
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 6);
    return 0;
}

void adicionarTrabalho() {
    int id;
    char nomeArquivo[50];
    int paginas;
    char tipo;
    printf("Em construcao...\n");
}

void processarImpressao() {
    printf("Em construcao...\n");
}

void listarFilas() {
    printf("Em construcao...\n");
}

void buscarTrabalho() {
    printf("Em construcao...\n");
}

void cancelarTrabalho() {
    printf("Em construcao...\n");
}

void salvarCSV() {
    printf("Em construcao...\n");
}

void carregarCSV() {
    printf("Em construcao...\n");
}