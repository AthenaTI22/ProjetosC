#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define QUANTUM 5

typedef struct {
    int pid;
    char nome[50];
    int prioridade;
    int tempoRestante;
} Processo;

typedef struct {
    Processo dados[MAX];
    int inicio;
    int fim;
    int total;
} Fila;

// ===== Inicializar =====
void initFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

// ===== Enfileirar =====
int enqueue(Fila *f, Processo p) {
    if (f->total == MAX)
        return 0;

    f->dados[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;

    return 1;
}

// ===== Desenfileirar =====
int dequeue(Fila *f, Processo *p) {
    if (f->total == 0)
        return 0;

    *p = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;

    return 1;
}

// ===== Consultar =====
void consultar(Fila *f) {
    if (f->total == 0) {
        printf("Fila vazia!\n");
        return;
    }

    Processo p = f->dados[f->inicio];

    printf("\n=== PROCESSO ATUAL ===\n");
    printf("PID: %d\n", p.pid);
    printf("Nome: %s\n", p.nome);
    printf("Prioridade: %d\n", p.prioridade);
    printf("Tempo restante: %d\n", p.tempoRestante);
}

// ===== Listar =====
void listar(Fila *f) {
    if (f->total == 0) {
        printf("Fila vazia!\n");
        return;
    }

    int i = f->inicio;

    printf("\n=== FILA DE PROCESSOS ===\n");

    for (int c = 0; c < f->total; c++) {
        Processo p = f->dados[i];

        printf("PID: %d | Nome: %s | Prioridade: %d | Tempo: %d\n",
               p.pid,
               p.nome,
               p.prioridade,
               p.tempoRestante);

        i = (i + 1) % MAX;
    }
}

// ===== Verificar PID duplicado =====
int existePID(Fila *f, int pid) {
    int i = f->inicio;

    for (int c = 0; c < f->total; c++) {
        if (f->dados[i].pid == pid)
            return 1;

        i = (i + 1) % MAX;
    }

    return 0;
}

// ===== Executar Quantum =====
void executar(Fila *f) {
    Processo p;

    if (!dequeue(f, &p)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("\nExecutando processo %s (PID %d)\n", p.nome, p.pid);

    if (p.tempoRestante <= QUANTUM) {
        printf("Processo finalizado!\n");
    } else {
        p.tempoRestante -= QUANTUM;

        printf("Quantum executado (%d).\n", QUANTUM);
        printf("Tempo restante: %d\n", p.tempoRestante);

        enqueue(f, p);
    }
}

// ===== Remover por PID =====
void remover(Fila *f, int pid) {
    if (f->total == 0) {
        printf("Fila vazia!\n");
        return;
    }

    Fila aux;
    initFila(&aux);

    Processo p;
    int achou = 0;

    while (dequeue(f, &p)) {
        if (p.pid == pid) {
            achou = 1;
        } else {
            enqueue(&aux, p);
        }
    }

    while (dequeue(&aux, &p)) {
        enqueue(f, p);
    }

    if (achou)
        printf("Processo removido!\n");
    else
        printf("PID nao encontrado!\n");
}

// ===== Salvar CSV =====
void salvar(Fila *f) {
    FILE *arquivo = fopen("processos.csv", "w");
    if (!arquivo) return;

    fprintf(arquivo, "pid;nome;prioridade;tempo\n");

    int i = f->inicio;

    for (int c = 0; c < f->total; c++) {
        Processo p = f->dados[i];

        fprintf(arquivo, "%d;%s;%d;%d\n",
                p.pid,
                p.nome,
                p.prioridade,
                p.tempoRestante);

        i = (i + 1) % MAX;
    }

    fclose(arquivo);
}

// ===== Carregar CSV =====
void carregar(Fila *f) {
    FILE *arquivo = fopen("processos.csv", "r");
    if (!arquivo) return;

    char lixo[100];
    fgets(lixo, 100, arquivo);

    Processo p;

    while (fscanf(arquivo, "%d;%49[^;];%d;%d\n",
                  &p.pid,
                  p.nome,
                  &p.prioridade,
                  &p.tempoRestante) == 4) {
        enqueue(f, p);
    }

    fclose(arquivo);
}

// ===== Main =====
int main() {
    Fila f;
    Processo p;
    int op;
    int pid;

    initFila(&f);
    carregar(&f);

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Adicionar processo\n");
        printf("2 - Executar quantum\n");
        printf("3 - Listar processos\n");
        printf("4 - Consultar atual\n");
        printf("5 - Remover por PID\n");
        printf("6 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch(op) {

            case 1:
                printf("PID: ");
                scanf("%d", &p.pid);

                if (existePID(&f, p.pid)) {
                    printf("PID duplicado!\n");
                    break;
                }

                printf("Nome: ");
                scanf(" %[^\n]", p.nome);

                printf("Prioridade: ");
                scanf("%d", &p.prioridade);

                printf("Tempo restante: ");
                scanf("%d", &p.tempoRestante);

                if (enqueue(&f, p))
                    printf("Processo adicionado!\n");
                else
                    printf("Fila cheia!\n");

                break;

            case 2:
                executar(&f);
                break;

            case 3:
                listar(&f);
                break;

            case 4:
                consultar(&f);
                break;

            case 5:
                printf("PID para remover: ");
                scanf("%d", &pid);
                remover(&f, pid);
                break;

            case 6:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (op != 6);

    salvar(&f);

    return 0;
}