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

# Trabalho C2 — Fila de Impressão

## Objetivo

Simular um sistema de fila de impressão com trabalhos **normais** e **prioritários**.

O sistema segue a lógica de filas **FIFO (First In, First Out)**, onde o primeiro trabalho a entrar é o primeiro a ser processado. No entanto, trabalhos **prioritários** possuem preferência sobre os normais.

## Estrutura

O programa utiliza duas filas implementadas com vetor de `struct`:

* **Fila normal simples**
* **Fila prioritária circular**

Cada trabalho de impressão possui:

* ID único
* Nome do arquivo
* Quantidade de páginas
* Tipo (`N` para normal / `P` para prioritário)

## Funcionalidades

* Adicionar trabalho de impressão
* Separar automaticamente em fila normal ou prioritária
* Processar impressão (prioritários primeiro)
* Buscar trabalho por ID
* Cancelar trabalho
* Listar ambas as filas
* Salvamento em CSV
* Carregamento em CSV

## Regras de Funcionamento

* Trabalhos prioritários são processados antes dos normais
* Se não houver trabalhos prioritários, a impressão ocorre pela fila normal
* IDs duplicados não são permitidos
* O tipo de trabalho aceita letras maiúsculas ou minúsculas (`N`, `n`, `P`, `p`)

## CSV

Arquivo utilizado:

```text
trabalhos.csv
```

Formato:

```csv
id;nomeArquivo;paginas;tipo
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
