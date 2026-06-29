#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char titulo[50];
    char artista[50];
    int duracao; // Duração em segundos
    char genero[30];
} Musica;

Musica lista[MAX];
int quantidade = 0;

void inserirMusica();
void buscarMusica();
void editarMusica();
void excluirMusica();
void listarMusicas();
void salvarCSV();
void carregarCSV();

int main() {
    int opcao;

    carregarCSV();

    do {
        printf("\n--- Menu ---\n");
        printf("1. Inserir música\n");
        printf("2. Buscar música\n");
        printf("3. Editar música\n");
        printf("4. Excluir música\n");
        printf("5. Listar músicas\n");
        printf("6. Salvar em CSV\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                inserirMusica();
                break;
            case 2:
                buscarMusica();
                break;
            case 3:
                editarMusica();
                break;
            case 4:
                excluirMusica();
                break;
            case 5:
                listarMusicas();
                break;
            case 6:
                salvarCSV();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
void inserirMusica() {
    int i;
    int novoID;

    if(quantidade >= MAX){
        printf("Lista Cheia!\n");
        return;
    }

    printf("Digite o ID:\n");
    scanf("%d", &novoID);

    for (i= 0; i < quantidade; i++){
        if(lista[i].id == novoID){
            printf("Erro. ID ja existe!\n");
            return;
        }
    }
    lista[quantidade].id = novoID;

    printf("Digite o título: ");
    scanf(" %[^\n]", lista[quantidade].titulo);

    printf("Digite o artista: ");
    scanf(" %[^\n]", lista[quantidade].artista);

    printf("Digite a duração da música em segundos: ");
    scanf("%d", &lista[quantidade].duracao);

    printf("Digite o gênero: ");
    scanf(" %[^\n]", lista[quantidade].genero);

    quantidade++;

    printf("Música cadastrada com sucesso!\n");
}

void buscarMusica() {
    int idBusca;
    int i;
    int encontrado = 0;

    if (quantidade == 0) {
        printf("Playlist vazia!\n");
        return;
    }

    printf("Digite o ID da música: ");
    scanf("%d", &idBusca);

    for (i = 0; i < quantidade; i++) {
        if (lista[i].id == idBusca) {
            printf("\nMúsica encontrada!\n");
            printf("ID: %d\n", lista[i].id);
            printf("Título: %s\n", lista[i].titulo);
            printf("Artista: %s\n", lista[i].artista);
            printf("Duração: %d segundos\n", lista[i].duracao);
            printf("Gênero: %s\n", lista[i].genero);

            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0) {
        printf("Música não encontrada!\n");
    }
}
    
void editarMusica() {
    int idBusca;
    int i;
    int encontrado = 0;

    if (quantidade == 0) {
        printf("Playlist vazia!\n");
        return;
    }

    printf("Digite o ID da música que deseja editar: ");
    scanf("%d", &idBusca);

    for (i = 0; i < quantidade; i++) {
        if (lista[i].id == idBusca) {
            printf("Música encontrada! Digite os novos dados.\n");

            printf("Novo título: ");
            scanf(" %[^\n]", lista[i].titulo);

            printf("Novo artista: ");
            scanf(" %[^\n]", lista[i].artista);

            printf("Nova duração (segundos): ");
            scanf("%d", &lista[i].duracao);

            printf("Novo gênero: ");
            scanf(" %[^\n]", lista[i].genero);

            printf("Música editada com sucesso!\n");

            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0) {
        printf("Música não encontrada!\n");
    }
}

void excluirMusica() {
    int idBusca;
    int i, j;
    int encontrado = 0;

    if (quantidade == 0) {
        printf("Playlist vazia!\n");
        return;
    }

    printf("Digite o ID da música que deseja excluir: ");
    scanf("%d", &idBusca);

    for (i = 0; i < quantidade; i++) {
        if (lista[i].id == idBusca) {
            encontrado = 1;

            for (j = i; j < quantidade - 1; j++) {
                lista[j] = lista[j + 1];
            }

            quantidade--;

            printf("Música excluída com sucesso!\n");
            break;
        }
    }

    if (encontrado == 0) {
        printf("Música não encontrada!\n");
    }
}

void listarMusicas() {
    int i;

    if (quantidade == 0) {
        printf("Playlist vazia!\n");
        return;
    }

    printf("\n=== PLAYLIST ===\n");

    for (i = 0; i < quantidade; i++) {
        printf("\nMúsica %d\n", i + 1);
        printf("ID: %d\n", lista[i].id);
        printf("Título: %s\n", lista[i].titulo);
        printf("Artista: %s\n", lista[i].artista);
        printf("Duração: %d segundos\n", lista[i].duracao);
        printf("Gênero: %s\n", lista[i].genero);
    }
}

void salvarCSV() {
    FILE *arquivo;
    int i;

    arquivo = fopen("playlist.csv", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    fprintf(arquivo, "id;titulo;artista;duracao;genero\n");

    for (i = 0; i < quantidade; i++) {
        fprintf(
            arquivo,
            "%d;%s;%s;%d;%s\n",
            lista[i].id,
            lista[i].titulo,
            lista[i].artista,
            lista[i].duracao,
            lista[i].genero
        );
    }

    fclose(arquivo);

    printf("Dados salvos em playlist.csv com sucesso!\n");
}

void carregarCSV() {
    FILE *arquivo;

    arquivo = fopen("playlist.csv", "r");

    if (arquivo == NULL) {
        printf("Arquivo CSV não encontrado. Iniciando playlist vazia.\n");
        return;
    }

    char linha[200];

    // Ignora cabeçalho
    fgets(linha, sizeof(linha), arquivo);

    quantidade = 0;

    while (
        fscanf(
            arquivo,
            "%d;%49[^;];%49[^;];%d;%29[^\n]\n",
            &lista[quantidade].id,
            lista[quantidade].titulo,
            lista[quantidade].artista,
            &lista[quantidade].duracao,
            lista[quantidade].genero
        ) == 5
    ) {
        quantidade++;

        if (quantidade >= MAX) {
            break;
        }
    }

    fclose(arquivo);

    printf("%d música(s) carregada(s) do CSV.\n", quantidade);
}
