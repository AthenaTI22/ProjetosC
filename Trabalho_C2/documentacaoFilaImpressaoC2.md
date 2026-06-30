# Trabalho C2 — Fila de Impressão

## Integrante(s)

* Giovana Amaral Dos Santos
* Victor Costa Da Cruz

## Turma

* Análise e Desenvolvimento de Sistemas

## Tema Escolhido

**Trabalho C — Tema C2: Fila de Impressão**

---

# Objetivo do Programa

Este programa simula um sistema de fila de impressão com dois tipos de trabalhos:

* **Normais**
* **Prioritários**

O sistema permite cadastrar, buscar, listar, processar e cancelar trabalhos de impressão, além de salvar e carregar os dados usando arquivo CSV.

---

# Estrutura de Dados Utilizada

O programa foi desenvolvido em linguagem C utilizando:

* `struct`
* Vetores de `struct`
* Filas simples
* Fila circular
* Arquivos CSV

Foi utilizada a estrutura de dados **Fila (Queue)**, que segue a lógica FIFO:

**First In, First Out**
(Primeiro a entrar, primeiro a sair)

Isso significa que o primeiro trabalho inserido em uma fila será o primeiro a ser processado.

---

# Registro Principal (`struct`)

Cada trabalho de impressão é representado pela seguinte estrutura:

```c
typedef struct {
    int id;
    char nomeArquivo[50];
    int paginas;
    char tipo;
} Trabalho;
```

## Campos da struct

| Campo       | Tipo     | Descrição                       |
| ----------- | -------- | ------------------------------- |
| id          | int      | Identificador único do trabalho |
| nomeArquivo | char[50] | Nome do arquivo                 |
| paginas     | int      | Quantidade de páginas           |
| tipo        | char     | N = Normal / P = Prioritário    |

---

# Filas Utilizadas

O sistema utiliza **duas filas separadas**:

## 1. Fila Normal (Simples)

Armazena trabalhos normais.

```c
Trabalho filaNormal[MAX];
```

Controle:

```c
int inicioNormal;
int fimNormal;
int quantidadeNormal;
```

---

## 2. Fila Prioritária (Circular)

Armazena trabalhos prioritários.

```c
Trabalho filaPrioritaria[MAX];
```

Controle:

```c
int inicioPrioritaria;
int fimPrioritaria;
int quantidadePrioritaria;
```

A fila prioritária foi implementada como **fila circular simples**.

---

# Conceito de Fila Circular

Na fila circular, quando o índice chega ao final do vetor, ele volta ao início.

Exemplo:

Se:

```text
MAX = 100
fim = 99
```

Ao inserir um novo elemento:

```c
fim = (fim + 1) % MAX;
```

Resultado:

```text
(99 + 1) % 100 = 0
```

Isso evita desperdício de posições do vetor.

---

# Funcionalidades Implementadas

## 1. Adicionar Trabalho

Função:

```c
adicionarTrabalho()
```

Responsável por:

* Ler ID
* Ler nome do arquivo
* Ler número de páginas
* Ler tipo (N ou P)
* Validar entradas
* Inserir na fila correta

Validações:

* Não permite ID duplicado
* Aceita N/n e P/p
* Verifica se a fila está cheia

Se o tipo for:

* `N` → entra na fila normal
* `P` → entra na fila prioritária

---

## 2. Processar Impressão

Função:

```c
processarImpressao()
```

Responsável por remover e processar o próximo trabalho.

Regra de prioridade:

* Se existir trabalho prioritário → processa prioritário
* Caso contrário → processa normal

A remoção da fila ocorre avançando o índice de início.

Exemplo:

```c
inicio = (inicio + 1) % MAX;
```

Isso caracteriza a operação de **dequeue**.

---

# Enqueue e Dequeue

## Enqueue

Inserção no final da fila.

Exemplo:

```text
[A][B]
```

Inserindo C:

```text
[A][B][C]
```

---

## Dequeue

Remoção da frente da fila.

Exemplo:

Antes:

```text
[A][B][C]
```

Depois:

```text
[B][C]
```

---

## 3. Listar Filas

Função:

```c
listarFilas()
```

Exibe todos os trabalhos:

* Fila prioritária
* Fila normal

A listagem respeita a ordem real da fila.

Se ambas estiverem vazias, o programa informa.

---

## 4. Buscar Trabalho

Função:

```c
buscarTrabalho()
```

Busca um trabalho pelo ID.

O programa procura:

1. Fila prioritária
2. Fila normal

Foi utilizada **busca linear (Linear Search)**.

Complexidade:

```text
O(n)
```

No pior caso, todos os elementos precisam ser verificados.

---

## 5. Cancelar Trabalho

Função:

```c
cancelarTrabalho()
```

Permite remover qualquer trabalho da fila pelo ID.

Como filas normalmente removem apenas da frente, foi necessário:

* localizar o trabalho
* deslocar os elementos seguintes
* reorganizar a fila

Exemplo:

Antes:

```text
[10][20][30][40]
```

Cancelar 30:

Depois:

```text
[10][20][40]
```

---

## 6. Salvar CSV

Função:

```c
salvarCSV()
```

Responsável por salvar os dados em:

```text
trabalhos.csv
```

Formato do arquivo:

```csv
id;nomeArquivo;paginas;tipo
1;relatorio.pdf;12;N
2;urgente.docx;3;P
```

Foi utilizado:

* `FILE`
* `fopen`
* `fprintf`
* `fclose`

---

## 7. Carregar CSV

Função:

```c
carregarCSV()
```

Executada no início do programa.

Responsável por:

* Abrir arquivo CSV
* Ignorar cabeçalho
* Ler cada linha
* Reconstruir as filas

Se o arquivo não existir:

```text
O programa inicia com filas vazias.
```

---

# Menu Interativo

O sistema possui menu numérico:

```text
1 - Adicionar trabalho
2 - Processar impressão
3 - Listar filas
4 - Buscar trabalho
5 - Cancelar trabalho
6 - Salvar e sair
```

---

# Tratamento de Erros

O programa trata:

* Fila vazia
* Fila cheia
* IDs duplicados
* Tipo inválido
* Arquivo CSV inexistente
* Falha ao abrir arquivo

---

# Principais Conceitos de Estrutura de Dados Aplicados

Neste trabalho foram aplicados os seguintes conceitos:

* Struct
* Vetores
* Filas simples
* Filas circulares
* FIFO
* Busca linear
* Inserção
* Remoção
* Persistência em arquivo

---

# Dificuldades Encontradas

As principais dificuldades foram:

* Implementação da fila circular
* Reorganização da fila após cancelamento
* Salvamento e carregamento em CSV
* Manipulação de índices usando módulo (`%`)

Esses desafios ajudaram a compreender melhor o funcionamento interno de filas em linguagem C.

---

# Como Compilar

Compilar com GCC:

```bash
gcc -std=c99 -Wall -pedantic fila_impressao.c -o fila_impressao
```

---

# Como Executar

Windows:

```bash
fila_impressao.exe
```

Linux/macOS:

```bash
./fila_impressao
```

---

# Conclusão

Este trabalho permitiu aplicar conceitos importantes de Estrutura de Dados em C, especialmente filas simples e filas circulares.

Além das operações básicas de fila, o projeto também envolveu persistência em arquivos CSV, validação de entradas e manipulação eficiente de vetores de `struct`.