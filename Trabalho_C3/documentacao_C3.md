# Trabalho C3 — Escalonador de Processos (Round Robin)

## Objetivo

Simular um escalonador de processos utilizando:

* **Fila circular**
* Algoritmo **Round Robin**

Cada processo recebe um tempo fixo de CPU chamado:

```text
Quantum
```

Se o processo não terminar nesse tempo:

* volta para o fim da fila

Se terminar:

* é removido

---

## Estrutura de Dados

### Struct Processo

Cada processo possui:

* `pid` → identificador único
* `nome` → nome do processo
* `prioridade`
* `tempoRestante` → tempo restante de execução

```c
typedef struct {
    int pid;
    char nome[50];
    int prioridade;
    int tempoRestante;
} Processo;
```

---

### Struct Fila

A fila é circular.

```c
typedef struct {
    Processo dados[MAX];
    int inicio;
    int fim;
    int total;
} Fila;
```

Campos:

* `inicio` → primeiro da fila
* `fim` → próxima posição livre
* `total` → quantidade de processos

---

## Fila Circular

A fila utiliza aritmética modular:

```c
(indice + 1) % MAX
```

Isso permite reutilizar posições antigas do vetor.

Exemplo:

```text
0 1 2 3 4
        ↑ fim
```

Próximo índice:

```text
(4 + 1) % 5 = 0
```

---

## Funcionalidades

### Adicionar Processo

Insere um novo processo na fila.

Valida:

* fila cheia
* PID duplicado

---

### Executar Quantum

Executa o primeiro processo da fila por um tempo fixo.

Quantum definido:

```c
#define QUANTUM 5
```

Exemplo:

Processo:

```text
PID 1
Tempo restante = 12
```

Após execução:

```text
12 - 5 = 7
```

Como ainda não terminou:

* retorna para o fim da fila

---

### Consultar Processo Atual

Mostra o processo na frente da fila.

---

### Listar Processos

Mostra todos os processos na ordem da fila.

Exemplo:

```text
PID: 1 | Chrome | Prioridade: 2 | Tempo: 12
PID: 2 | Discord | Prioridade: 1 | Tempo: 8
```

---

### Remover por PID

Remove um processo específico da fila.

Estratégia:

1. Criar fila auxiliar
2. Transferir elementos
3. Ignorar PID removido
4. Reconstruir fila original

---

## Algoritmo Round Robin

Exemplo inicial:

```text
P1 (12)
P2 (8)
P3 (3)
```

### Execução de P1

```text
12 - 5 = 7
```

Fila:

```text
P2 → P3 → P1
```

---

### Execução de P3

```text
3 - 5 <= 0
```

Resultado:

```text
Processo finalizado
```

P3 é removido da fila.

---

## Persistência em CSV

Arquivo:

```text
processos.csv
```

Formato:

```csv
pid;nome;prioridade;tempo
1;Chrome;2;12
2;Discord;1;8
```

---

## Menu

```text
1 - Adicionar processo
2 - Executar quantum
3 - Listar processos
4 - Consultar atual
5 - Remover por PID
6 - Sair
```

---

## Complexidade

| Operação        | Complexidade |
| --------------- | ------------ |
| Enqueue         | O(1)         |
| Dequeue         | O(1)         |
| Consultar       | O(1)         |
| Listar          | O(n)         |
| Remover por PID | O(n)         |

---

# Tecnologias Utilizadas

* Linguagem C
* Struct
* Vetores de Struct
* Arquivos CSV
* GCC / MinGW
* Visual Studio Code

---

# Como Executar

Compilar:

```bash
gcc arquivo.c -o programa
```

Executar:

```bash
./programa
```

No PowerShell:

```powershell
.\programa.exe
```

---

# Autoria

Projeto desenvolvido para a disciplina de **Estruturas de Dados**, com foco em implementação prática de:

* Pilhas
* Filas circulares
* Persistência em arquivos
* Manipulação de structs em C