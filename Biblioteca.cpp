#include <stdio.h>  // Biblioteca de comunicação com o Usuário
#include <stdlib.h> // Biblioteca de alocação de espaço e memória
#include <locale.h> // Biblioteca de alocações de texto por região
#include <string.h> // Biblioteca de alocação de strings
#include <stdarg.h> 
#include <ctype.h>


#ifdef _WIN32  //Confere qual o sistema operacional para define a variável CLEAR_COMMAND
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif

void cleanBuffer() { // Função para limpar o buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int confirmWithEnter(const char * message) { //Função para confirmar com a tecla Enter
    printf("\n%s", message);
    cleanBuffer();  // Limpa o buffer
    int input = getchar();  // Espera o Enter
    return (input == '\n') ? 1 : 0; // Retorna 1 se o usuário pressionou Enter, caso contrário, 0
}

int validarCPF(const char *cpf) {
    if (strlen(cpf) != 11) {
        printf("\033[1mErro:\033[0m CPF deve conter 11 dígitos\n\n");
        return 0; // CPF deve conter 11 dígitos
    }
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            printf("\033[1mErro:\033[0m CPF deve conter só caracteres numéricos\n\n");
            return 0; // CPF contém caracteres não numéricos
        }
    }
    return 1;
}

typedef struct { // "Tipagem" da função menuOptionsFunction
    const char *header;
    const char *welcomeMessage;
    const char *commandMessage;
    const char *menu1;
    void (*functionOpcao1)();
    const char *menu2;
    void (*functionOpcao2)();
    const char *menu3;
    void (*functionOpcao3)();
    const char *exitMenu;
    void (*functionOpcao4)();
    const char *invalidOptionMessage;
    const char *feedbackMessage;
} MenuOptions;
void menuOptionsFunction(MenuOptions *options) //Função para o Menu
{
    setlocale(LC_ALL, "Portuguese");
    
    int opcaoUsuario = 0;
    int lace = 1;

    while (lace == 1) {
        if (options->header != NULL) {
            printf("\n\n\n");
            printf("\033[1m%s\033[0m\n\n", options->header);
        }
        if (options->welcomeMessage != NULL) {
            printf("\033[1m%s\033[0m\n\n", options->welcomeMessage);
        }
        if (options->commandMessage != NULL) {
            printf("\033[1m%s\033[0m\n\n", options->commandMessage);
        }


        printf("\t1 - %s;\n", options->menu1);
        printf("\t2 - %s;\n", options->menu2);
        if (options->menu3 != NULL) {
            printf("\t3 - %s;\n", options->menu3);
        }
        if (options->exitMenu != NULL) {
            printf("\t4 - %s;\n", options->exitMenu);
        }

        printf("\nSua escolha: ");
        scanf("%d", &opcaoUsuario);
            
            if (opcaoUsuario == 1) {
                system(CLEAR_COMMAND);
                printf("\033[1m%s\033[0m\n\n", options->menu1);
                options->functionOpcao1();
                lace = confirmWithEnter("Pressione Enter para voltar ao Menu...");
            } else if (opcaoUsuario == 2) {
                system(CLEAR_COMMAND);
                printf("\033[1m%s\033[0m\n\n", options->menu2);
                options->functionOpcao2();
                lace = confirmWithEnter("Pressione Enter para voltar ao Menu...");
            } else if (opcaoUsuario == 3 && options->menu3 != NULL) {
                system(CLEAR_COMMAND);
                if(options->functionOpcao3 == NULL) {
                    printf("\033[1mErro Interno:\033[0m Função da opção 3 não foi definida.\ninternErrorCode: 404\n\n");
                } else {
                    printf("\033[1m%s\033[0m\n\n", options->menu3);
                    options->functionOpcao3();
                    lace = confirmWithEnter("Pressione Enter para voltar ao Menu...");
                }
            } else if (opcaoUsuario == 4 && options->exitMenu != NULL) {
                system(CLEAR_COMMAND);
                if(options->functionOpcao4 == NULL) {
                    printf("\033[1mErro Interno:\033[0m Função da opção 4 não foi definida.\ninternErrorCode: 404\n\n");
                } else {
                    printf("\033[1m%s\033[0m\n\n", options->exitMenu);
                    options->functionOpcao4();
                    lace = 0;
                }
            } else {
                system(CLEAR_COMMAND);
                printf("\n%s\n", options->invalidOptionMessage);
                printf("\033[1m%s\033[0m\n", options->feedbackMessage);
                lace = confirmWithEnter("Pressione Enter para voltar ao Menu...");

            }
    }
    

}

void testarArquivoCriadoFunction(const char *cpf) 
{
    FILE *file = fopen(cpf, "r");

    if (file == NULL) {
        printf("\033[1mErro:\033[0m Arquivo %s não foi criado corretamente. O usuário não foi cadastrado.\n", cpf);
    } else {
        printf("\033[1mSucesso:\033[0m Arquivo %s foi criado corretamente e o usuário foi cadastrado com sucesso.\n", cpf);
        fclose(file);
    }
}

int verificarArquivoExistenteFunction(const char *cpf) // Verifica se o arquivo já existe (CPF duplicado)
{
    FILE *file = fopen(cpf, "r");
    if (file != NULL) {
        fclose(file);
        return 1; // Arquivo já existe
    }
    return 0; // Arquivo não existe
}

void sair() {
    system(CLEAR_COMMAND); // Limpar a tela
    printf("\033[1mOpção escolhida: Sair.\n\nObrigado por utilizar o Cartório da EBAC\033[0m\n\n");
}

void registrar() {
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];

  system(CLEAR_COMMAND); // Limpar a tela
  printf("\033[1mRegistrar usuário:\033[0m\n\n");

  printf("\033[1mDigite o CPF a ser cadastrado: \033[0m");
  scanf("%s", cpf);
  
  if (validarCPF(cpf) == 0) { return; };
  
  // Cria o nome do arquivo com base no CPF
  char arquivo[45]; // Quantidade extra para o ".md"
  snprintf(arquivo, sizeof(arquivo), "%s.md", cpf);

  if (verificarArquivoExistenteFunction(arquivo)) {
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

  testarArquivoCriadoFunction(arquivo); // Teste para verificar se o "arquivo" foi criado



}

void consultar() {
  char cpf[40];
  char conteudo[1000];
  int opcaoUsuario = 0;
  int laco_consultar = 1;

  system(CLEAR_COMMAND); // Limpar a tela
  printf("\033[1mConsultar usuário:\033[0m\n\n");

  printf("\033[1mDigite o CPF que você quer consultar: \033[0m");
  scanf("%s", cpf);
  
  if (validarCPF(cpf) == 0) { return; };


  char arquivo[45];
  snprintf(arquivo, sizeof(arquivo), "%s.md", cpf);
  
  FILE *file = fopen(arquivo, "r"); // Abre o arquivo para leitura "r"

  if (file == NULL)
  {     
    printf("\033[1mUsuário inexistente\033[0m\n");
    printf("\033[1mRegistrar um novo usuário?\033[0m\n");
    while (laco_consultar == 1) {
        printf("\t1 - Sim.\n");
        printf("\t2 - Sair.\n");
        printf("\nOpção: ");
        scanf("%d", &opcaoUsuario);

        if (opcaoUsuario == 1) {
            system(CLEAR_COMMAND);
            registrar();
            laco_consultar = 0;
        } else if (opcaoUsuario == 2) {
            system(CLEAR_COMMAND);
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

  system(CLEAR_COMMAND); // Limpar a tela
  printf("\033[1mDeletar usuário:\033[0m\n\n");

  printf("\033[1mDigite o CPF que você quer deletar: \033[0m");
  scanf("%s", cpf);
  
  validarCPF(cpf);

  snprintf(arquivo, sizeof(arquivo), "%s.md", cpf);

  FILE *file = fopen(arquivo, "r");

  if (file == NULL) {
      printf("\033[1mUsuário inexistente:\033[0m O arquivo %s não foi encontrado.\n", arquivo);
      return; 
  }

  fclose(file); 
  
  int confirmationOption = confirmWithEnter("Você tem certeza que deseja deletar o usuário?\nPressione \033[1mEnter\033[0m para confirmar ou digite \033[1mqualquer tecla\033[0m para cancelar a operação. \n");

  if (confirmationOption == 1) {
    if (remove(arquivo) == 0) { // Se o arquivo existe, tenta deletá-lo
      printf("\033[1mSucesso:\033[0m O usuário cadastrado com o CPF %s foi deletado com sucesso.\n", cpf);
    } else {
      printf("\033[1mErro:\033[0m Não foi possível deletar o arquivo %s.\n", arquivo);
    }}

  if (confirmationOption == 0) {
    printf("\033[1mCancelado:\033[0m A operação de deletar foi cancelada.\n");
  }

}


int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    MenuOptions menu = {
        .header = "###### Cartório da EBAC ######",
        .welcomeMessage = "Olá, seja bem-vindo(a)!",
        .commandMessage = "Escolha a opção desejada do menu:",
        .menu1 = "Registrar usuário",
        .functionOpcao1 = registrar,
        .menu2 = "Consultar usuário",
        .functionOpcao2 = consultar,
        .menu3 = "Deletar usuário",
        .functionOpcao3 = deletar,
        .exitMenu = "Sair",
        .functionOpcao4 = sair,
        .invalidOptionMessage = "Opção inválida!",
        .feedbackMessage = "Tente novamente"
    };
    menuOptionsFunction(&menu);

    return 0;

}