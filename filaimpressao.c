#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
        printf("2 - Processar impressao\n");
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
    Trabalho novo;
    int i;

    printf("Digite o ID: ");
    scanf("%d", &novo.id);

    // Verifica ID duplicado na fila normal
    for (i = 0; i < quantidadeNormal; i++) {
        int pos = (inicioNormal + i) % MAX;
        if (filaNormal[pos].id == novo.id) {
            printf("ID ja existe!\n");
            return;
        }
    }

    // Verifica ID duplicado na fila prioritária
    for (i = 0; i < quantidadePrioritaria; i++) {
        int pos = (inicioPrioritaria + i) % MAX;
        if (filaPrioritaria[pos].id == novo.id) {
            printf("ID ja existe!\n");
            return;
        }
    }

    printf("Nome do arquivo: ");
    scanf(" %[^\n]", novo.nomeArquivo);

    printf("Quantidade de paginas: ");
    scanf("%d", &novo.paginas);

    printf("Tipo (N = Normal / P = Prioritario): ");
    scanf(" %c", &novo.tipo);

    novo.tipo = toupper(novo.tipo);

    if (novo.tipo != 'N' && novo.tipo != 'P') {
        printf("Tipo invalido!\n");
        return;
    }

    if (novo.tipo == 'N') {
        if (quantidadeNormal == MAX) {
            printf("Fila normal cheia!\n");
            return;
        }

        filaNormal[fimNormal] = novo;
        fimNormal++;
        quantidadeNormal++;

        printf("Trabalho adicionado na fila normal!\n");
    }
    else {
        if (quantidadePrioritaria == MAX) {
            printf("Fila prioritaria cheia!\n");
            return;
        }

        filaPrioritaria[fimPrioritaria] = novo;
        fimPrioritaria = (fimPrioritaria + 1) % MAX;
        quantidadePrioritaria++;

        printf("Trabalho adicionado na fila prioritaria!\n");
    }
}

void processarImpressao() {
    Trabalho atual;

    if (quantidadePrioritaria == 0 && quantidadeNormal == 0) {
        printf("Nao ha trabalhos para imprimir!\n");
        return;
    }

    // Prioridade primeiro
    if (quantidadePrioritaria > 0) {
        atual = filaPrioritaria[inicioPrioritaria];

        printf("\n=== PROCESSANDO TRABALHO PRIORITARIO ===\n");
        printf("ID: %d\n", atual.id);
        printf("Arquivo: %s\n", atual.nomeArquivo);
        printf("Paginas: %d\n", atual.paginas);

        inicioPrioritaria = (inicioPrioritaria + 1) % MAX;
        quantidadePrioritaria--;
    }
    else {
        atual = filaNormal[inicioNormal];

        printf("\n=== PROCESSANDO TRABALHO NORMAL ===\n");
        printf("ID: %d\n", atual.id);
        printf("Arquivo: %s\n", atual.nomeArquivo);
        printf("Paginas: %d\n", atual.paginas);

        inicioNormal = (inicioNormal + 1) % MAX;
        quantidadeNormal--;
    }

    printf("Impressao concluida!\n");
}

void listarFilas() {
     int i, pos;

    if (quantidadePrioritaria == 0 && quantidadeNormal == 0) {
        printf("Todas as filas estao vazias!\n");
        return;
    }

    printf("\n=== FILA PRIORITARIA ===\n");

    if (quantidadePrioritaria == 0) {
        printf("Fila prioritaria vazia.\n");
    } else {
        for (i = 0; i < quantidadePrioritaria; i++) {
            pos = (inicioPrioritaria + i) % MAX;

            printf("\nID: %d\n", filaPrioritaria[pos].id);
            printf("Arquivo: %s\n", filaPrioritaria[pos].nomeArquivo);
            printf("Paginas: %d\n", filaPrioritaria[pos].paginas);
            printf("Tipo: %c\n", filaPrioritaria[pos].tipo);
        }
    }

    printf("\n=== FILA NORMAL ===\n");

    if (quantidadeNormal == 0) {
        printf("Fila normal vazia.\n");
    } else {
        for (i = 0; i < quantidadeNormal; i++) {
            pos = (inicioNormal + i) % MAX;

            printf("\nID: %d\n", filaNormal[pos].id);
            printf("Arquivo: %s\n", filaNormal[pos].nomeArquivo);
            printf("Paginas: %d\n", filaNormal[pos].paginas);
            printf("Tipo: %c\n", filaNormal[pos].tipo);
        }
    }
}

void buscarTrabalho() {
    int idBusca;
    int i, pos;

    if (quantidadePrioritaria == 0 && quantidadeNormal == 0) {
        printf("Todas as filas estao vazias!\n");
        return;
    }

    printf("Digite o ID do trabalho: ");
    scanf("%d", &idBusca);

    // Busca na fila prioritária
    for (i = 0; i < quantidadePrioritaria; i++) {
        pos = (inicioPrioritaria + i) % MAX;

        if (filaPrioritaria[pos].id == idBusca) {
            printf("\nTrabalho encontrado na fila prioritaria!\n");
            printf("ID: %d\n", filaPrioritaria[pos].id);
            printf("Arquivo: %s\n", filaPrioritaria[pos].nomeArquivo);
            printf("Paginas: %d\n", filaPrioritaria[pos].paginas);
            printf("Tipo: %c\n", filaPrioritaria[pos].tipo);
            return;
        }
    }

    // Busca na fila normal
    for (i = 0; i < quantidadeNormal; i++) {
        pos = (inicioNormal + i) % MAX;

        if (filaNormal[pos].id == idBusca) {
            printf("\nTrabalho encontrado na fila normal!\n");
            printf("ID: %d\n", filaNormal[pos].id);
            printf("Arquivo: %s\n", filaNormal[pos].nomeArquivo);
            printf("Paginas: %d\n", filaNormal[pos].paginas);
            printf("Tipo: %c\n", filaNormal[pos].tipo);
            return;
        }
    }

    printf("Trabalho nao encontrado!\n");
}

void cancelarTrabalho() {
    int idBusca;
    int i, j, pos;

    if (quantidadePrioritaria == 0 && quantidadeNormal == 0) {
        printf("Todas as filas estao vazias!\n");
        return;
    }

    printf("Digite o ID do trabalho a cancelar: ");
    scanf("%d", &idBusca);

    // Procurar na fila prioritária
    for (i = 0; i < quantidadePrioritaria; i++) {
        pos = (inicioPrioritaria + i) % MAX;

        if (filaPrioritaria[pos].id == idBusca) {
            for (j = i; j < quantidadePrioritaria - 1; j++) {
                int atual = (inicioPrioritaria + j) % MAX;
                int prox = (inicioPrioritaria + j + 1) % MAX;
                filaPrioritaria[atual] = filaPrioritaria[prox];
            }

            fimPrioritaria =
                (fimPrioritaria - 1 + MAX) % MAX;

            quantidadePrioritaria--;

            printf("Trabalho cancelado da fila prioritaria!\n");
            return;
        }
    }

    // Procurar na fila normal
    for (i = 0; i < quantidadeNormal; i++) {
        pos = (inicioNormal + i) % MAX;

        if (filaNormal[pos].id == idBusca) {
            for (j = i; j < quantidadeNormal - 1; j++) {
                int atual = (inicioNormal + j) % MAX;
                int prox = (inicioNormal + j + 1) % MAX;
                filaNormal[atual] = filaNormal[prox];
            }

            fimNormal =
                (fimNormal - 1 + MAX) % MAX;

            quantidadeNormal--;

            printf("Trabalho cancelado da fila normal!\n");
            return;
        }
    }

    printf("Trabalho nao encontrado!\n");
}

void salvarCSV() {
    FILE *arquivo;
    int i, pos;

    arquivo = fopen("trabalhos.csv", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    fprintf(arquivo, "id;nomeArquivo;paginas;tipo\n");

    // Salvar fila prioritária
    for (i = 0; i < quantidadePrioritaria; i++) {
        pos = (inicioPrioritaria + i) % MAX;

        fprintf(
            arquivo,
            "%d;%s;%d;%c\n",
            filaPrioritaria[pos].id,
            filaPrioritaria[pos].nomeArquivo,
            filaPrioritaria[pos].paginas,
            filaPrioritaria[pos].tipo
        );
    }

    // Salvar fila normal
    for (i = 0; i < quantidadeNormal; i++) {
        pos = (inicioNormal + i) % MAX;

        fprintf(
            arquivo,
            "%d;%s;%d;%c\n",
            filaNormal[pos].id,
            filaNormal[pos].nomeArquivo,
            filaNormal[pos].paginas,
            filaNormal[pos].tipo
        );
    }

    fclose(arquivo);
    printf("Dados salvos com sucesso em trabalhos.csv!\n");
}

void carregarCSV() {
    FILE *arquivo;
    Trabalho temp;
    char cabecalho[100];

    arquivo = fopen("trabalhos.csv", "r");

    if (arquivo == NULL) {
        printf("Arquivo CSV nao encontrado. Iniciando filas vazias.\n");
        return;
    }

    // Ignora cabeçalho
    fgets(cabecalho, sizeof(cabecalho), arquivo);

    while (
        fscanf(
            arquivo,
            "%d;%49[^;];%d;%c\n",
            &temp.id,
            temp.nomeArquivo,
            &temp.paginas,
            &temp.tipo
        ) == 4
    ) {
        if (temp.tipo == 'P') {
            if (quantidadePrioritaria < MAX) {
                filaPrioritaria[fimPrioritaria] = temp;
                fimPrioritaria = (fimPrioritaria + 1) % MAX;
                quantidadePrioritaria++;
            }
        }
        else if (temp.tipo == 'N') {
            if (quantidadeNormal < MAX) {
                filaNormal[fimNormal] = temp;
                fimNormal = (fimNormal + 1) % MAX;
                quantidadeNormal++;
            }
        }
    }

    fclose(arquivo);

    printf("Dados carregados do CSV com sucesso!\n");
}