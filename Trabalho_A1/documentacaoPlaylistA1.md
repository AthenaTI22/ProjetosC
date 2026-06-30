# Trabalho A1 — Playlist de Músicas

## Integrante(s)

* Giovana Amaral Dos Santos
* Victor Costa Da Cruz

## Turma

* Análise e Desenvolvimento de Sistemas

## Tema Escolhido

**Trabalho A — Tema A1: Playlist de Músicas**

---

# Objetivo do Programa

Este programa simula uma playlist de músicas.

O sistema permite:

* cadastrar músicas
* buscar músicas por ID
* editar informações
* excluir músicas
* listar toda a playlist
* salvar os dados em CSV
* carregar os dados ao iniciar

O objetivo do trabalho é praticar manipulação de listas simples em linguagem C usando vetores de `struct`.

---

# Estrutura de Dados Utilizada

O programa foi desenvolvido em linguagem C utilizando:

* `struct`
* Vetores de `struct`
* Lista sequencial simples
* Busca linear
* Arquivos CSV

A playlist é armazenada em um vetor com capacidade máxima de 100 músicas.

```c id="6wj6pw"
#define MAX 100
```

---

# Registro Principal (`struct`)

Cada música é representada por uma estrutura:

```c id="f07c1r"
typedef struct {
    int id;
    char titulo[50];
    char artista[50];
    int duracao;
    char genero[30];
} Musica;
```

---

## Campos da struct

| Campo   | Tipo     | Descrição                     |
| ------- | -------- | ----------------------------- |
| id      | int      | Identificador único da música |
| titulo  | char[50] | Nome da música                |
| artista | char[50] | Nome do artista               |
| duracao | int      | Duração em segundos           |
| genero  | char[30] | Gênero musical                |

---

# Estrutura da Lista

A playlist utiliza um vetor de músicas:

```c id="7g3j1g"
Musica lista[MAX];
```

Também existe uma variável de controle:

```c id="pcr1uq"
int quantidade = 0;
```

Essa variável informa quantas músicas estão cadastradas.

Exemplo:

Se:

```text id="7x0qqt"
quantidade = 3
```

Então existem 3 músicas válidas no vetor.

---

# Conceito de Lista Simples

Diferente de filas e pilhas, a lista permite:

* inserir em qualquer posição
* buscar qualquer elemento
* editar registros
* remover registros intermediários

Exemplo:

```text id="2ykmry"
[Musica1][Musica2][Musica3]
```

Se remover a segunda:

Antes:

```text id="s7s7ju"
[1][2][3]
```

Depois do deslocamento:

```text id="83p7bs"
[1][3]
```

Os elementos à direita precisam ser deslocados para preencher o espaço vazio.

---

# Funcionalidades Implementadas

## 1. Inserir Música

Função:

```c id="9et4rb"
inserirMusica()
```

Responsável por:

* Ler ID
* Ler título
* Ler artista
* Ler duração
* Ler gênero
* Inserir no vetor

Validações:

* Não permite ID duplicado
* Verifica se a lista está cheia

Se:

```text id="86j6jh"
quantidade == MAX
```

O cadastro é bloqueado.

---

## 2. Buscar Música

Função:

```c id="vlfx4a"
buscarMusica()
```

Busca uma música pelo ID.

Foi utilizada:

**Busca linear (Linear Search)**

O algoritmo percorre o vetor desde o início:

```c id="wzt4yw"
for (i = 0; i < quantidade; i++)
```

Comparando:

```c id="1evwbe"
lista[i].id == idBuscado
```

Se encontrar, exibe todos os dados.

Complexidade no pior caso:

```text id="bzgrcm"
O(n)
```

---

## 3. Editar Música

Função:

```c id="rqvpkz"
editarMusica()
```

Permite alterar:

* título
* artista
* duração
* gênero

O ID não pode ser alterado, pois é a chave principal da música.

Fluxo:

1. usuário informa ID
2. sistema localiza música
3. campos são atualizados

---

## 4. Excluir Música

Função:

```c id="h9u0ep"
excluirMusica()
```

Remove uma música pelo ID.

Como a lista usa vetor, a remoção exige reorganização.

Exemplo:

Antes:

```text id="p8m9n8"
[10][20][30][40]
```

Excluir:

```text id="qshsh7"
20
```

Depois:

```text id="7bvgm3"
[10][30][40]
```

O deslocamento é feito com:

```c id="0wdprc"
lista[i] = lista[i + 1];
```

Após isso:

```c id="0uyzdr"
quantidade--;
```

---

## 5. Listar Músicas

Função:

```c id="m2bexi"
listarMusicas()
```

Exibe todas as músicas cadastradas.

A ordem exibida segue a ordem de cadastro.

Se a lista estiver vazia:

```text id="wx0c2d"
Nenhuma musica cadastrada.
```

---

## 6. Salvar CSV

Função:

```c id="nff2ja"
salvarCSV()
```

Responsável por salvar os dados em:

```text id="3d7ej8"
playlist.csv
```

Formato:

```csv id="iqe3d4"
id;titulo;artista;duracao;genero
1;Bohemian Rhapsody;Queen;355;Rock
2;Blinding Lights;The Weeknd;200;Pop
```

Bibliotecas e funções utilizadas:

* `FILE`
* `fopen`
* `fprintf`
* `fclose`

---

## 7. Carregar CSV

Função:

```c id="snyqjw"
carregarCSV()
```

Executada no início do programa.

Responsável por:

* abrir CSV
* ignorar cabeçalho
* ler músicas salvas
* reconstruir a lista

Se o arquivo não existir:

```text id="7gw77h"
A lista inicia vazia.
```

---

# Menu Interativo

O programa possui menu numérico:

```text id="7p1yjp"
1 - Inserir musica
2 - Buscar musica
3 - Editar musica
4 - Excluir musica
5 - Listar musicas
6 - Salvar e sair
```

---

# Tratamento de Erros

O programa trata:

* Lista vazia
* Lista cheia
* ID duplicado
* Música não encontrada
* Arquivo inexistente
* Erros de leitura

---

# Principais Conceitos de Estrutura de Dados Aplicados

Neste trabalho foram aplicados:

* Struct
* Vetores
* Lista simples
* Inserção
* Busca linear
* Edição
* Remoção com deslocamento
* Persistência em CSV

---

# Dificuldades Encontradas

Principais desafios:

* Entender manipulação de `struct`
* Trabalhar com vetores de registros
* Implementar exclusão com deslocamento
* Salvar e carregar arquivos CSV
* Validar entradas corretamente

Esses desafios ajudaram a desenvolver melhor a lógica de programação em C.

---

# Como Compilar

Compilar com GCC:

```bash id="4k1jlwm"
gcc -std=c99 -Wall -pedantic playlist.c -o playlist
```

---

# Como Executar

Windows:

```bash id="jlwmjlwm"
playlist.exe
```

Linux/macOS:

```bash id="l98d7c"
./playlist
```

---

# Conclusão

Este trabalho permitiu aplicar conceitos fundamentais de listas simples em C.

Foi possível compreender melhor como funcionam:

* registros com `struct`
* vetores de registros
* inserção
* busca
* edição
* exclusão
* persistência em arquivos CSV

O projeto fortaleceu a compreensão prática de estruturas de dados sequenciais.