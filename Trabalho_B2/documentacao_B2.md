# Estruturas de Dados em C — Trabalhos B2 e C3

Este repositório contém implementações em **linguagem C** de estruturas de dados clássicas utilizando **vetores de struct**, com persistência em arquivos CSV.

Projetos incluídos:

* **Trabalho B2 — Chamadas de Emergência (Pilha)**
* **Trabalho C3 — Escalonador de Processos (Fila Circular / Round Robin)**

---

# Trabalho B2 — Chamadas de Emergência (Pilha)

## Objetivo

Simular uma pilha de chamadas de emergência.

O sistema utiliza a lógica **LIFO (Last In, First Out)**:

> A última chamada registrada será a primeira a ser atendida.

Exemplo:

```text
Registrar protocolo 1001
Registrar protocolo 1002
Consultar topo -> 1002
Atender -> remove 1002
Atender -> remove 1001
```

---

## Estrutura de Dados

### Struct Chamado

Cada chamada possui:

* `protocolo` → identificador único
* `local` → local da ocorrência
* `tipo` → tipo da emergência
* `horario` → horário da chamada

```c
typedef struct {
    int protocolo;
    char local[50];
    char tipo[50];
    char horario[20];
} Chamado;
```

---

### Struct Pilha

A pilha armazena os chamados em um vetor.

```c
typedef struct {
    Chamado dados[MAX];
    int topo;
} Pilha;
```

Campos:

* `dados[MAX]` → vetor com os registros
* `topo` → posição do último elemento inserido

---

## Funcionalidades

### Push

Insere um novo chamado no topo da pilha.

Valida:

* pilha cheia
* protocolo duplicado

---

### Pop

Remove o elemento do topo da pilha.

Valida:

* pilha vazia

---

### Peek

Consulta a última chamada registrada sem removê-la.

---

### Listar

Mostra todos os registros do topo para a base.

Exemplo:

```text
1002 | Avenida Central | Acidente | 14:30
1001 | Rua A | Incêndio | 14:10
```

---

## Persistência em CSV

### Salvar

Grava os dados no arquivo:

```text
dados.csv
```

Formato:

```csv
protocolo;local;tipo;horario
1001;Centro;Incêndio;14:20
```

---

### Carregar

Reconstrói a pilha a partir do arquivo CSV, preservando a ordem original.

---

## Menu

```text
1 - Inserir
2 - Remover
3 - Listar
4 - Consultar topo
5 - Sair
```

---

## Complexidade

| Operação                   | Complexidade |
| -------------------------- | ------------ |
| Push                       | O(1)         |
| Pop                        | O(1)         |
| Peek                       | O(1)         |
| Listar                     | O(n)         |
| Buscar protocolo duplicado | O(n)         |