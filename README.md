# Sistema de Gerenciamento de Alunos com Tabela Hash em C

Este programa em linguagem C implementa um sistema de gerenciamento de alunos usando uma tabela hash. Permite aos usuários cadastrar, buscar, excluir e alterar dados de alunos em uma instituição de ensino. Além disso, oferece a funcionalidade de aumentar o número de alunos da instituição. A seguir estão detalhes sobre o programa:

## Exercício:

1. **Crie um programa que manipule os dados de um aluno em uma tabela hash.**

   a) O cadastro de um aluno possui:
   
      - Matrícula.
      - Nome.
      - Curso.
      - Período.
   
   b) A chave utilizada na função hash é a matrícula do aluno.
   
   c) A quantidade de alunos que a instituição possui será informada pelo usuário.
   
      - O tamanho da tabela hash deve ser o próximo número primo a partir da quantidade de alunos (incluindo a quantidade).
      
   d) As seguintes funções devem ser suportadas pelo sistema:
   
      - Cadastrar um aluno.
      - Buscar um aluno.
      - Excluir um aluno.
      - Alterar os dados de um aluno.
      - Excluir todos os alunos.
      - Aumentar o número de alunos da instituição.
      
   e) O sistema deverá ser encerrado apenas quando o usuário solicitar.

## Funcionalidades Principais:

1. **Cadastro de Alunos:**
   - Os usuários podem cadastrar um aluno fornecendo informações como matrícula, nome, curso e período.

2. **Busca de Alunos:**
   - Os usuários podem buscar um aluno pelo número de matrícula.

3. **Exclusão de Alunos:**
   - Os usuários podem excluir um aluno com base no número de matrícula.

4. **Alteração de Dados de Alunos:**
   - Os usuários podem alterar os dados de um aluno, incluindo nome, curso e período, usando o número de matrícula como identificador.

5. **Exclusão de Todos os Alunos:**
   - Os usuários podem excluir todos os alunos cadastrados na instituição.

6. **Aumento do Número de Alunos:**
   - Os usuários podem aumentar o número de alunos da instituição, ajustando o tamanho da tabela hash.

## Como Usar:

1. Execute o programa.
2. Informe a quantidade de alunos que a instituição possui.
3. Escolha uma das opções do menu para realizar uma das operações de gerenciamento de alunos.
4. Siga as instruções fornecidas pelo programa para completar a operação desejada.
5. O sistema poderá ser encerrado quando o usuário solicitar.

## Requisitos:

- Compilador C (por exemplo, GCC) instalado no seu sistema.

## Como Compilar e Executar:

1. Abra o terminal.
2. Navegue até o diretório onde o arquivo de código-fonte do programa está localizado.
3. Compile o programa com o comando: `gcc main.c -o programa`
4. Execute o programa com o comando: `./programa`

## Autor:

Leonardo Yago Nascimento Silva

