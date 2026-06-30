#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// ===== Estrutura =====
typedef struct {
    int protocolo;
    char local[50];
    char tipo[50];
    char horario[20];
} Chamado;

typedef struct {
    Chamado dados[MAX];
    int topo;
} Pilha;

// ===== Funções =====
void inicializar(Pilha *p) {
    p->topo = -1;
}

int existeProtocolo(Pilha *p, int protocolo) {
    for (int i = 0; i <= p->topo; i++) {
        if (p->dados[i].protocolo == protocolo)
            return 1;
    }
    return 0;
}

int push(Pilha *p, Chamado c) {
    if (p->topo == MAX - 1)
        return 0; // pilha cheia

    if (existeProtocolo(p, c.protocolo))
        return -1; // protocolo duplicado

    p->dados[++p->topo] = c;
    return 1;
}

int pop(Pilha *p) {
    if (p->topo == -1)
        return 0; // pilha vazia

    p->topo--;
    return 1;
}

// ===== NOVA FUNÇÃO PEEK =====
void peek(Pilha *p) {
    if (p->topo == -1) {
        printf("Pilha vazia!\n");
        return;
    }

    Chamado c = p->dados[p->topo];

    printf("\n=== ULTIMA CHAMADA REGISTRADA ===\n");
    printf("Protocolo: %d\n", c.protocolo);
    printf("Local: %s\n", c.local);
    printf("Tipo: %s\n", c.tipo);
    printf("Horario: %s\n", c.horario);
}

void listar(Pilha *p) {
    if (p->topo == -1) {
        printf("Pilha vazia!\n");
        return;
    }

    for (int i = p->topo; i >= 0; i--) {
        printf("%d | %s | %s | %s\n",
               p->dados[i].protocolo,
               p->dados[i].local,
               p->dados[i].tipo,
               p->dados[i].horario);
    }
}

void salvar(Pilha *p) {
    FILE *f = fopen("dados.csv", "w");
    if (!f) return;

    fprintf(f, "protocolo;local;tipo;horario\n");

    for (int i = 0; i <= p->topo; i++) {
        fprintf(f, "%d;%s;%s;%s\n",
                p->dados[i].protocolo,
                p->dados[i].local,
                p->dados[i].tipo,
                p->dados[i].horario);
    }

    fclose(f);
}

void carregar(Pilha *p) {
    FILE *f = fopen("dados.csv", "r");
    if (!f) return;

    char linha[150];
    fgets(linha, 150, f); // pula cabeçalho

    Chamado c;

    while (fscanf(f, "%d;%49[^;];%49[^;];%19[^\n]\n",
                  &c.protocolo,
                  c.local,
                  c.tipo,
                  c.horario) == 4) {

        if (p->topo < MAX - 1)
            p->dados[++p->topo] = c;
    }

    fclose(f);
}

// ===== MAIN =====
int main() {
    Pilha p;
    inicializar(&p);
    carregar(&p);

    int op;
    Chamado c;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Listar\n");
        printf("4 - Consultar topo (Peek)\n");
        printf("5 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {

            case 1:
                printf("Protocolo: ");
                scanf("%d", &c.protocolo);

                printf("Local: ");
                scanf(" %[^\n]", c.local);

                printf("Tipo: ");
                scanf(" %[^\n]", c.tipo);

                printf("Horario: ");
                scanf(" %[^\n]", c.horario);

                int r = push(&p, c);

                if (r == 1)
                    printf("Inserido!\n");
                else if (r == 0)
                    printf("Pilha cheia!\n");
                else
                    printf("Protocolo duplicado!\n");
                break;

            case 2:
                if (pop(&p))
                    printf("Removido!\n");
                else
                    printf("Pilha vazia!\n");
                break;

            case 3:
                listar(&p);
                break;

            case 4:
                peek(&p);
                break;

            case 5:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (op != 5);

    salvar(&p);

    return 0;
}