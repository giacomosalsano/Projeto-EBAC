#include <stdio.h>  // Biblioteca de comunicação com o Usuário
#include <stdlib.h> // Biblioteca de alocação de espaço e memória
#include <locale.h> // Biblioteca de alocações de texto por região
#include <string.h> // Biblioteca de alocação de strings


void aguardarEnter() {
    printf("\nPressione Enter para continuar...");
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

void registrar() {
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];

  system("clear"); // Limpar a tela
  printf("\033[1mOpção escolhida:\033[0m Registrar nomes.\n\n");

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

  fprintf(file, "# Registro de Usuário:\n\n");  
  fprintf(file, "**CPF:** %s;\n", cpf);  // Salva o valor da variável "cpf"
  fclose(file); // Fecha o arquivo

  printf("\033[1mDigite o Nome a ser cadastrado: \033[0m");
  scanf("%s", nome);

  file = fopen(arquivo, "a"); // "a" para Abrir
  fprintf(file, "**Nome:** %s;\n", nome);  
  fclose(file); 

  printf("\033[1mDigite o Sobrenome a ser cadastrado: \033[0m");
  scanf("%s", sobrenome);

  file = fopen(arquivo, "a"); 
  fprintf(file, "**Sobrenome:** %s;\n", sobrenome); 
  fclose(file);

  printf("\033[1mDigite o Cargo a ser cadastrado:\033[0m ");
  scanf("%s", cargo);

  file = fopen(arquivo, "a");
  fprintf(file, "**Cargo:** %s.\n", cargo); // Salva o valor da variável "cargo"
  fclose(file);

  testar_arquivo_criado(arquivo); // Teste para verificar se o "arquivo" foi criado



}

void consultar() {
    system("clear"); // Limpar a tela
    printf("Opção escolhida: Consultar nomes.\n");
}

void deletar() {
    system("clear"); // Limpar a tela
    printf("Opção escolhida: Deletar nomes.\n");
}

void sair() {
    system("clear"); // Limpar a tela
    printf("Opção escolhida: Sair.\n");
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
        printf("\t1 - Registrar nomes;\n");
        printf("\t2 - Consultar nomes;\n");
        printf("\t3 - Deletar nomes;\n");
        printf("\t4 - Sair.\n");

        printf("\nOpção: ");
        scanf("%d", &opcaoUsuario);

        system("clear");

        switch (opcaoUsuario) {
            case 1:
                registrar();
                break;
            case 2:
                consultar();
                break;
            case 3:
                deletar();
                break;
            case 4:
                sair();
                laco = 0; // Sair do loop
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }

       aguardarEnter();
    }

    return 0;
}