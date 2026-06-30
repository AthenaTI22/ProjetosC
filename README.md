# Projeto de Estruturas de Dados

**Integrante(s):** Giovana Amaral Dos Santos, Victor Costa Da Cruz
**Turma:** Análise e Desenvolvimento de Sistemas
**Professor:** Nirton Afonso

---

## Descrição Geral

Este repositório reúne os trabalhos da disciplina de **Estruturas de Dados**, desenvolvidos em **linguagem C**.

Os projetos abordam três estruturas fundamentais:

* **Lista (Trabalho A)**
* **Pilha (Trabalho B)**
* **Fila (Trabalho C)**

Todos os programas utilizam:

* `struct`
* vetores de `struct`
* arquivos CSV
* menu interativo com opções numéricas

---

# Trabalho A1 — Playlist de Músicas (Lista)

## Objetivo

Simular uma playlist de músicas permitindo inserção, busca, edição, exclusão e listagem.

## Estrutura

Lista sequencial implementada com vetor de `struct`.

## Funcionalidades

* Inserir música (com validação de ID único e espaço disponível)
* Buscar música
* Editar música
* Excluir música com reorganização do vetor
* Listar músicas cadastradas

## CSV

Arquivo utilizado:

```text
playlist.csv
```

Formato:

```csv
id;titulo;artista;duracao;genero
```

---

# Trabalho B2 — Pilha de Chamadas de Emergência

## Objetivo

Simular um sistema de chamadas de emergência.

A estrutura segue a lógica **LIFO (Last In, First Out)**:

> A última chamada registrada será a primeira a ser atendida.

## Estrutura

Pilha implementada com vetor de `struct`.

## Funcionalidades

* Push (inserção no topo)
* Pop (remoção do topo)
* Peek (consulta do topo sem remover)
* Listagem das chamadas
* Salvamento em CSV
* Carregamento em CSV

## CSV

Arquivo utilizado:

```text
chamadas.csv
```

Formato:

```csv
protocolo;local;tipo;horario
```

---

# Trabalho C3 — Escalonador de Processos (Round Robin)

## Objetivo

Simular um escalonador de processos utilizando o algoritmo **Round Robin**.

Cada processo recebe um tempo fixo de CPU chamado **quantum**.
Caso não finalize dentro desse tempo, ele retorna para o fim da fila.

## Estrutura

Fila circular (**FIFO**) implementada com vetor de `struct`.

## Funcionalidades

* Enqueue (inserção na fila)
* Dequeue (remoção da fila)
* Consultar processo atual
* Executar quantum
* Remover processo por PID
* Listagem dos processos
* Salvamento em CSV
* Carregamento em CSV

## CSV

Arquivo utilizado:

```text
processos.csv
```

Formato:

```csv
pid;nome;prioridade;tempoRestante
```

---

# Tecnologias Utilizadas

* Linguagem C (C99)
* GCC
* Visual Studio Code

---

# Compilação

```bash
gcc -std=c99 -Wall -pedantic arquivo.c -o programa
```

---

# Execução

### Linux/macOS

```bash
./programa
```

### Windows (PowerShell)

```powershell
.\programa.exe
```

---

# Tratamento de Erros

Os programas realizam tratamento para:

* Estrutura cheia
* Estrutura vazia
* IDs duplicados
* Arquivo inexistente
* Entradas inválidas

---

# Dificuldades Encontradas

Durante o desenvolvimento, os principais desafios foram:

* Manipulação de `struct` em C
* Leitura e escrita em arquivos CSV
* Implementação de fila circular
* Reorganização de vetores após remoções
* Validação de dados de entrada

---

# Conclusão

O projeto permitiu aplicar, na prática, conceitos fundamentais de **Estruturas de Dados em C**, especialmente:

* Listas
* Pilhas
* Filas circulares

Além disso, reforçou conhecimentos em:

* organização de código
* persistência de dados em arquivos
* lógica de programação
* manipulação de memória com vetores
