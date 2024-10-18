#include <stdio.h>  // Biblioteca de comunicação com o Usuário
#include <stdlib.h> // Biblioteca de alocação de espaço e memória
#include <locale.h> // Biblioteca de alocações de texto por região
#include <string.h> // Biblioteca de alocação de strings


void aguardarEnter() {
    printf("\nPressione Enter para voltar ao Menu...");
    getchar();  // Limpa o buffer do scanf anterior
    getchar();  // Espera o Enter
}

void testar_arquivo_criado(const char *cpf) {
    FILE *file = fopen(cpf, "r");

    if (file == NULL) {
        printf("\033[1mErro:\033[0m Arquivo %s não foi criado corretamente. O usuário não foi cadastrado.\n", cpf);
    } else {
        printf("\033[1mSucesso:\033[0m Arquivo %s foi criado corretamente e o usuário foi cadastrado com sucesso.\n", cpf);
        fclose(file);
    }
}

// Verifica se o arquivo já existe (CPF duplicado):
int verificar_arquivo_existe(const char *cpf) {
    FILE *file = fopen(cpf, "r");
    if (file != NULL) {
        fclose(file);
        return 1; // Arquivo já existe
    }
    return 0; // Arquivo não existe
}

void sair() {
    system("clear"); // Limpar a tela
    printf("\033[1mOpção escolhida: Sair.\n\nObrigado por utilizar o Cartório da EBAC\033[0m\n\n");
}

void registrar() {
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];

  system("clear"); // Limpar a tela
  printf("\033[1mRegistrar usuário:\033[0m\n\n");

  printf("\033[1mDigite o CPF a ser cadastrado: \033[0m");
  scanf("%s", cpf);
  
  // Cria o nome do arquivo com base no CPF
  char arquivo[45]; // Quantidade extra para o ".md"
  sprintf(arquivo, "%s.md", cpf); // Combina o CPF com a extensão

  if (verificar_arquivo_existe(arquivo)) {
      printf("\033[1mErro ao realizar o cadastro.\033[0m\nO CPF %s já está cadastrado.\n", cpf);
      return; // Sai da função sem registrar
  } 

  FILE *file = fopen(arquivo, "w"); // Abre o arquivo para escrita

  if (file == NULL) {
      // Verificação de erro ao criar o arquivo (TDD)
      printf("\033[1mErro ao criar o arquivo.\033[0m\n");
      return;
  }

  fprintf(file, "# Dados do usuário:\n\n");  
  fprintf(file, "**CPF:** %s;\n\n", cpf);  // Salva o valor da variável "cpf"
  fclose(file); // Fecha o arquivo

  printf("\033[1mDigite o Nome a ser cadastrado: \033[0m");
  scanf("%s", nome);

  file = fopen(arquivo, "a"); // "a" para Abrir
  fprintf(file, "**Nome:** %s;\n\n", nome);  
  fclose(file); 

  printf("\033[1mDigite o Sobrenome a ser cadastrado: \033[0m");
  scanf("%s", sobrenome);

  file = fopen(arquivo, "a"); 
  fprintf(file, "**Sobrenome:** %s;\n\n", sobrenome); 
  fclose(file);

  printf("\033[1mDigite o Cargo a ser cadastrado:\033[0m ");
  scanf("%s", cargo);

  file = fopen(arquivo, "a");
  fprintf(file, "**Cargo:** %s.\n\n", cargo); // Salva o valor da variável "cargo"
  fclose(file);

  testar_arquivo_criado(arquivo); // Teste para verificar se o "arquivo" foi criado



}

void consultar() {
  char cpf[40];
  char conteudo[1000];
  int opcaoUsuario = 0;
  int laco_consultar = 1;

  system("clear"); // Limpar a tela
  printf("\033[1mConsultar usuário:\033[0m\n\n");

  printf("\033[1mDigite o CPF que você quer consultar: \033[0m");
  scanf("%s", cpf);

  char arquivo[45];
  sprintf(arquivo, "%s.md", cpf); 

  FILE *file = fopen(arquivo, "r"); // Abre o arquivo para leitura "r"

  if (file == NULL)
  {
      printf("\033[1mUsuário inexistente\033[0m\n");
      printf("\033[1mRegistrar um novo usuário?\033[0m\n");
        while (laco_consultar == 1) {
          printf("\t1 - Sim.\n");
          printf("\t2 - Não.\n");
          printf("\nOpção: ");
          scanf("%d", &opcaoUsuario);

          if (opcaoUsuario == 1) {
              system("clear");
              registrar();
              laco_consultar = 0;
          } else if (opcaoUsuario == 2) {
              system("clear");
              sair();
              laco_consultar = 0;
          } else {
              printf("\nOpção inválida. Tente novamente.\n");
              printf("\033[1mRegistrar um novo usuário?\033[0m\n");

          }
        }

  }

  while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
      printf("%s", conteudo);
  }

  fclose(file);
}

void deletar() {
  char cpf[40];
  char arquivo[45];

  system("clear"); // Limpar a tela
  printf("\033[1mDeletar usuário:\033[0m\n\n");

  printf("\033[1mDigite o CPF que você quer deletar: \033[0m");
  scanf("%s", cpf);

  sprintf(arquivo, "%s.md", cpf); 

  FILE *file = fopen(arquivo, "r");

  if (file == NULL) {
      printf("\033[1mUsuário inexistente:\033[0m O arquivo %s não foi encontrado.\n", arquivo);
      return; 
  }

  fclose(file); 

  // Se o arquivo existe, tenta deletá-lo
  if (remove(arquivo) == 0) {
      printf("\033[1mSucesso:\033[0m O usuário cadastrado com o CPF %s foi deletado com sucesso.\n", cpf);
  } else {
      printf("\033[1mErro:\033[0m Não foi possível deletar o arquivo %s.\n", arquivo);
  }
}


int main() {
    int opcaoUsuario = 0;
    int laco = 1;

    setlocale(LC_ALL, "pt_BR.UTF-8");

    while (laco == 1) {
        system("clear"); // Limpar a tela
        printf("##Esse software é de livre uso dos alunos da EBAC.##\n");
        printf("\n###### Cartório da EBAC ######\n\n");

        printf("Olá, seja bem-vindo(a)!\nEscolha a opção desejada do menu:\n");
        printf("\t1 - Registrar usuário;\n");
        printf("\t2 - Consultar usuário;\n");
        printf("\t3 - Deletar usuário;\n");
        printf("\t4 - Sair.\n");

        printf("\nOpção: ");
        scanf("%d", &opcaoUsuario);

        system("clear");

        switch (opcaoUsuario) {
            case 1:
                registrar();
                aguardarEnter();
                break;
            case 2:
                consultar();
                aguardarEnter();
                break;
            case 3:
                deletar();
                aguardarEnter();
                break;
            case 4:
                sair();
                laco = 0; // Sair do loop
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    }

    return 0;
}