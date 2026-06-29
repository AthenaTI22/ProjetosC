# Trabalho A1 — Playlist de Músicas (Lista Simples em C)

**Alunos:** Giovana Amaral Dos Santos e Victor Costa Da Cruz
**Turma:** Análise e Desenvolvimento de Sistemas
**Tema:** A1 — Playlist de Músicas  
**Linguagem:** C (padrão C99)

---

## 1. Descrição do Projeto
Este projeto foi desenvolvido para a disciplina de Estrutura de Dados utilizando a linguagem C.
O programa simula uma playlist de músicas usando uma lista simples sequencial implementada com vetor de `struct`.
Cada música cadastrada possui os seguintes dados:
- ID
- Título
- Artista
- Duração em segundos
- Gênero musical
A capacidade máxima da lista é de 100 músicas.

---
## 2. Estrutura de Dados Utilizada
Foi utilizada uma lista simples sequencial implementada com vetor.

```c
#define MAX 100

Musica lista[MAX];
int quantidade = 0;
```
### Struct utilizada
```c
typedef struct {
    int id;
    char titulo[50];
    char artista[50];
    int duracao;
    char genero[30];
} Musica;
```

### Explicação
- O vetor `lista` armazena as músicas.
- Cada posição do vetor representa um registro.
- A variável `quantidade` controla quantas posições estão ocupadas.

Exemplo:
```text
Índice:   0        1        2
        [Mus1]   [Mus2]   [Mus3]
```
Se `quantidade = 3`, significa que existem 3 músicas cadastradas.
---

## 3. Funcionalidades Implementadas

O programa possui um menu interativo com as seguintes opções:
### 1 - Inserir música
Permite cadastrar uma nova música.
Regras:
- Verifica se a lista está cheia.
- Verifica se o ID já existe.
- Insere a música na próxima posição livre do vetor.

Exemplo de inserção:
```c
lista[quantidade] = novaMusica;
quantidade++;
```

---
### 2 - Buscar música
Busca uma música pelo ID.
Foi utilizada busca linear:

```c
for (i = 0; i < quantidade; i++)
```
Se encontrar:
- Exibe todos os dados da música.

Se não encontrar:
- Exibe mensagem de erro.
---

### 3 - Editar música
Localiza uma música pelo ID.
Campos editáveis:
- título
- artista
- duração
- gênero

O ID não pode ser alterado por ser a chave do registro.
---

### 4 - Excluir música
Remove uma música com base no ID.
Após excluir, é necessário reorganizar o vetor deslocando os elementos.

Exemplo:
Antes:
```text
[ID1] [ID2] [ID3]
```
Após excluir ID2:
```text
[ID1] [ID3]
```
Código utilizado:
```c
for (j = i; j < quantidade - 1; j++) {
    lista[j] = lista[j + 1];
}

quantidade--;
```
---

### 5 - Listar músicas
Exibe todas as músicas armazenadas na playlist.
A listagem percorre todo o vetor até `quantidade`.
---

### 6 - Salvar CSV
Salva todos os registros em um arquivo CSV.
Nome do arquivo:
```text
playlist.csv
```
---
### 7 - Carregar CSV
Ao iniciar o programa, os dados são carregados automaticamente do arquivo CSV.
Se o arquivo não existir:
- o programa inicia com playlist vazia.
---

## 4. Algoritmos Utilizados
### Inserção
A inserção ocorre na próxima posição livre:
```c
lista[quantidade]
```
Depois:
```c
quantidade++;
```
---
### Busca Linear
A busca percorre o vetor do início ao fim.
Complexidade:
```text
O(n)
```
Onde:
- n = quantidade de músicas
---

### Exclusão com Deslocamento
Após remover um elemento do meio da lista, todos os elementos à direita precisam ser movidos uma posição para a esquerda.
Isso mantém a lista sequencial sem espaços vazios.
---

## 5. Manipulação de Arquivos
Para persistência dos dados foram utilizadas funções da biblioteca `stdio.h`:
- `fopen()`
- `fprintf()`
- `fscanf()`
- `fclose()`
---

### Formato CSV
Exemplo:

```csv
id;titulo;artista;duracao;genero
1;Bohemian Rhapsody;Queen;355;Rock
2;Blinding Lights;The Weeknd;200;Pop
```
Cada linha representa uma música.
---
## 6. Como Compilar e Executar
### Requisitos
Ter o compilador GCC instalado com suporte ao padrão C99.
Verificar instalação:

```bash
gcc --version
```
---
### Compilação Manual
```bash
gcc -std=c99 -Wall -pedantic playlist.c -o playlist
```
---
### Execução
No Windows:

```bash
playlist.exe
```
No Linux/macOS:
```bash
./playlist
```
---
## 7. Testes Realizados
Foram testados:

- Inserção de músicas
- Validação de ID duplicado
- Busca por ID existente
- Busca por ID inexistente
- Edição de dados
- Exclusão no início da lista
- Exclusão no meio da lista
- Exclusão no fim da lista
- Salvamento em CSV
- Carregamento automático do CSV
- Lista vazia
- Lista cheia
---
## 8. Conclusão
Este projeto permitiu praticar conceitos fundamentais da disciplina de Estrutura de Dados, como:
- listas sequenciais
- vetores
- structs
- busca linear
- exclusão com deslocamento
- manipulação de arquivos
O trabalho contribuiu para o entendimento da organização de dados em memória e da persistência em arquivos.