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
        printf("1. Inserir musica\n");
        printf("2. Buscar musica\n");
        printf("3. Editar musica\n");
        printf("4. Excluir musica\n");
        printf("5. Listar musica\n");
        printf("6. Salvar em CSV\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
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
                printf("Opção invalida!\n");
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

    printf("Digite o titulo: ");
    scanf(" %[^\n]", lista[quantidade].titulo);

    printf("Digite o artista: ");
    scanf(" %[^\n]", lista[quantidade].artista);

    printf("Digite a duracao da musica em segundos: ");
    scanf("%d", &lista[quantidade].duracao);

    printf("Digite o genero: ");
    scanf(" %[^\n]", lista[quantidade].genero);

    quantidade++;

    printf("Musica cadastrada com sucesso!\n");
}

void buscarMusica() {
    int idBusca;
    int i;
    int encontrado = 0;

    if (quantidade == 0) {
        printf("Playlist vazia!\n");
        return;
    }

    printf("Digite o ID da musica: ");
    scanf("%d", &idBusca);

    for (i = 0; i < quantidade; i++) {
        if (lista[i].id == idBusca) {
            printf("\nMusica encontrada!\n");
            printf("ID: %d\n", lista[i].id);
            printf("Titulo: %s\n", lista[i].titulo);
            printf("Artista: %s\n", lista[i].artista);
            printf("Duracao: %d segundos\n", lista[i].duracao);
            printf("Genero: %s\n", lista[i].genero);

            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0) {
        printf("Musica nao encontrada!\n");
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

    printf("Digite o ID da musica que deseja editar: ");
    scanf("%d", &idBusca);

    for (i = 0; i < quantidade; i++) {
        if (lista[i].id == idBusca) {
            printf("Musica encontrada! Digite os novos dados.\n");

            printf("Novo titulo: ");
            scanf(" %[^\n]", lista[i].titulo);

            printf("Novo artista: ");
            scanf(" %[^\n]", lista[i].artista);

            printf("Nova duracao (segundos): ");
            scanf("%d", &lista[i].duracao);

            printf("Novo genero: ");
            scanf(" %[^\n]", lista[i].genero);

            printf("Musica editada com sucesso!\n");

            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0) {
        printf("Musica nao encontrada!\n");
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

    printf("Digite o ID da musica que deseja excluir: ");
    scanf("%d", &idBusca);

    for (i = 0; i < quantidade; i++) {
        if (lista[i].id == idBusca) {
            encontrado = 1;

            for (j = i; j < quantidade - 1; j++) {
                lista[j] = lista[j + 1];
            }

            quantidade--;

            printf("Musica excluida com sucesso!\n");
            break;
        }
    }

    if (encontrado == 0) {
        printf("Musica nao encontrada!\n");
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
        printf("\nMusica %d\n", i + 1);
        printf("ID: %d\n", lista[i].id);
        printf("Titulo: %s\n", lista[i].titulo);
        printf("Artista: %s\n", lista[i].artista);
        printf("Duracao: %d segundos\n", lista[i].duracao);
        printf("Genero: %s\n", lista[i].genero);
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
        printf("Arquivo CSV nao encontrado. Iniciando playlist vazia.\n");
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

    printf("%d musica(s) carregada(s) do CSV.\n", quantidade);
}