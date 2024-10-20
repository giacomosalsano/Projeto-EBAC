# Registro de Nomes - Documentação de Arquitetura de Software

## 1. Informações Gerais
- **Instituição:** EBAC
- **Curso:** TI do Zero
- **Projeto:** Registro de Nomes
- **Versão:** 1.0
- **Stacks:** C++ (Biblioteca.c)

---

## 2. Descrição Geral

O projeto **Registro de Nomes** é uma aplicação simples desenvolvida em C++ que permite o cadastro de usuários com CPF, nome, sobrenome e cargo. As informações são salvas em arquivos `.md` com o CPF do usuário como nome do arquivo, e o conteúdo inclui os dados pessoais registrados.

### 2.1 Finalidade

Este projeto tem como objetivo implementar um sistema básico de registro de informações que armazena os dados em arquivos locais. Ele é projetado para aprender e aplicar conceitos fundamentais de manipulação de arquivos, estrutura de dados e controle de fluxo em C++.

### 2.2 Escopo

O sistema inclui funcionalidades de:
- Cadastro de usuário (CPF, nome, sobrenome, cargo);
- Verificação de CPF duplicado;
- Consulta de dados de usuários cadastrados;
- Exibição de mensagens de erro e sucesso ao usuário.

---

## 3. Definições, Acrônimos e Abreviações

- **CPF:** Cadastro de Pessoa Física, um número utilizado no Brasil para identificar cidadãos;
- **C++:** Linguagem de programação utilizada para desenvolver o projeto;
- **Biblioteca.c:** Conjunto de bibliotecas padrões de C++ utilizadas no projeto (stdio.h, string.h, etc);
- **TDD:** Test Driven Development (Desenvolvimento Orientado a Testes), abordado de forma simples para garantir a criação dos arquivos de forma correta;

---

## 4. Objetivos do Projeto

O objetivo principal deste projeto é consolidar os conceitos aprendidos no curso de TI do Zero da EBAC, com foco em:
- Manipulação de arquivos;
- Validação de entradas de dados;
- Estruturas de controle de fluxo;
- Implementação de um menu interativo.

---

## 5. Índice Analítico

1. Informações Gerais
2. Descrição Geral
   - Finalidade
   - Escopo
3. Definições, Acrônimos e Abreviações
4. Objetivos do Projeto
5. Representação Arquitetural
6. Visão de Caso de Uso
7. Visão Lógica
8. Visão de Processos
9. Visão de Implantação
10. Visão da Implementação
11. Tamanho e Desempenho
12. Qualidade
13. Sugestões de Desenvolvimento

---

## 6. Representação Arquitetural

A arquitetura do projeto segue o padrão **Client-Server**, onde:
- O **cliente** interage através de um menu no terminal;
- O **servidor** é o próprio sistema, que processa os dados fornecidos pelo usuário e armazena essas informações localmente em arquivos.

---

## 7. Visão de Caso de Uso

### Casos de Uso:
1. **Registrar Usuário:**
   - Entrada: CPF, nome, sobrenome, cargo;
   - Validações: Verifica se o CPF possui 11 dígitos e se já foi cadastrado;
   - Saída: Arquivo com os dados do usuário registrado.

2. **Consultar Usuário:**
   - Entrada: CPF;
   - Saída: Exibe os dados do usuário correspondente ao CPF, se encontrado.

---

## 8. Visão Lógica

A lógica principal do sistema está centralizada nas seguintes funções:

- `registrar()`: Realiza o processo de cadastro de usuários e salva as informações em arquivos;
- `consultar()`: Permite que o usuário consulte um CPF previamente cadastrado;
- `validarCPF()`: Verifica se o CPF é válido e se possui apenas caracteres numéricos;
- `verificarArquivoExistenteFunction()`: Confirma se um arquivo (CPF) já foi cadastrado anteriormente.

---

## 9. Visão de Processos

O sistema segue o fluxo:
1. O usuário escolhe uma opção no menu (registrar ou consultar);
2. No registro, o sistema coleta os dados e valida o CPF;
3. No processo de consulta, o sistema busca o arquivo correspondente ao CPF;
4. O sistema exibe feedbacks ao usuário com mensagens de erro ou sucesso.

---

## 10. Visão de Implantação

- O projeto foi desenvolvido para rodar diretamente no terminal, em qualquer sistema operacional. Para garantir compatibilidade com diferentes sistemas, a limpeza da tela usa uma macro condicional:
  - No Windows: `cls`
  - Em sistemas Unix-based: `clear`

---

## 11. Visão da Implementação

O código foi implementado em C++, usando as bibliotecas padrão para entrada e saída de dados, manipulação de strings e manipulação de arquivos. As funções principais e estruturas de controle foram definidas para garantir uma execução simples e eficiente.

---

## 12. Tamanho e Desempenho

### Tamanho:
- Cada registro de usuário é salvo em um arquivo `.md`, e o tamanho dos arquivos dependerá da quantidade de dados cadastrados.
  
### Desempenho:
- O desempenho do sistema é adequado para o propósito de registro simples, com baixo consumo de memória e tempo de execução rápido devido à natureza das operações.

---

## 13. Qualidade

A qualidade do código é garantida pelo uso de boas práticas (Clean Code), como:
- Validação de entradas de dados;
- Uso de estruturas de controle para evitar erros;
- Mensagens claras de feedback ao usuário;
- Simulação de TDD para garantir a criação de arquivos corretos.

---

## 14. Sugestões de Desenvolvimento

### 14.1 Desenvolvimento do FrontEnd
- Como o sistema é executado no terminal, um futuro desenvolvimento poderia envolver a criação de uma interface gráfica (GUI) para melhorar a experiência do usuário.

### 14.2 Aprimoramento do BackEnd
- Implementar uma camada de segurança para criptografar os dados salvos.
- Expandir as funcionalidades de manipulação de dados, como edição ou exclusão de registros.

### 14.3 Novas Funcionalidades
- **Backup de Dados:** Criar uma função que automatize o backup dos arquivos de registro;
- **Tratativa de Erros:** Melhorar o tratamento de erros, como falhas no sistema de arquivos ou na entrada de dados;
- **Conectividade:** Integrar o sistema a um banco de dados remoto para possibilitar a consulta e o registro de usuários de forma centralizada;
- **Monitoria de Usuários:** Adicionar a funcionalidade de monitoramento e geração de logs para acompanhar o uso do sistema.
