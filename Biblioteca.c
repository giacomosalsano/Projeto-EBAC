#include <stdio.h> //Biblioteca de comunicação com o Usuário
#include <stdlib.h> //Biblioteca de alocação de espaço e memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h>



int main()
{
  int opcaoUsuario=0;
  int laco=1;
  char* nomeDoUdsuario;

  for(laco=1;laco==1;) {

    // system("clear"); //Limpar a tela 

    setlocale(LC_ALL, "pt_BR_uft8");


    printf("##Esse software é de livre uso dos alunos da EBAC.##\n");
    printf("\n###### Cartório da EBAC ######\n\n");

    printf("Olá, seja bem-vindo(a)!\nEscolha a opção desejada do menu:\n");
    printf("\t1 - Registrar nomes;\n");
    printf("\t2 - Consultar nomes;\n");
    printf("\t3 - Deletar nomes;\n");
    printf("\t4 - Sair.\n");

    printf("\nOpção: ");
    scanf("%d", &opcaoUsuario); //Armazenar na variável "opcaoUsuario"
    // %d to accept input of integers.
    // %ld to  accept input of long integers
    // %lld to accept input of long long integers
    // %f to accept input of real number.
    // %c to accept input of character types.
    // %s to accept input of a string.

    switch(opcaoUsuario) {
      case 1:
        system("clear"); //Limpar a tela
        printf("Opção escolhida: Registrar nomes.\n");
        laco=0;
        break;
      case 2:
        system("clear"); //Limpar a tela
        printf("Opção escolhida: Consultar nomes.\n");
        laco=0;
        break;
      case 3:
        system("clear"); //Limpar a tela
        printf("Opção escolhida: Deletar nomes.\n");
        laco=0;
        break;
      case 4: 
        system("clear"); //Limpar a tela
        printf("Opção escolhida: Sair.\n");
        laco=0;
        break;
      default:
        system("clear"); //Limpar a tela
        printf("Opção inválida.\n");
        laco=0;
        break;
    }

  }


  // return 0;
}

