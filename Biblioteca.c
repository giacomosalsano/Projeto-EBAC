#include <stdio.h> //Biblioteca de comunicação com o Usuário
#include <stdlib.h> //Biblioteca de alocação de espaço e memória
#include <locale.h> //Biblioteca de alocações de texto por região



int main()
{
  int opcaoUsuario=0;


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

  // system("cls"); //Limpar a tela

  if(opcaoUsuario==1) { //Registrar Nomes
    printf("\nVocê escolheu a opção 1 - Registrar nomes.\n");
  }

  if(opcaoUsuario==2) { //Consultar Nomes
    printf("\nVocê escolheu a opção 2 - Consultar nomes.\n");
  }

  if(opcaoUsuario==3) { //Deletar Nomes
    printf("\nVocê escolheu a opção 3 - Deletar nomes.\n");
  }

  if(opcaoUsuario==4) { //Sair
    printf("\nVocê escolheu a opção 4 - Sair.\nObrigado por utilizar nosso serviço.");
  }

  if(opcaoUsuario < 1 || opcaoUsuario > 4) { //Opção Inválida
    printf("\nDigite uma opção válida");
  }

  return 0;
}

