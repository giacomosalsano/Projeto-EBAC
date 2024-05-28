#include <stdio.h> //Biblioteca de comunicação com o Usuário
#include <stdlib.h> //Biblioteca de alocação de espaço e memória
#include <locale.h> //Biblioteca de alocações de texto por região


int main()
{
  setlocale(LC_ALL, "pt_BR_uft8");
  printf("###### Cartório da EBAC ######\n\n");
  printf("Escolha a opção desejada do menu: \n");
  printf("\t\t1 - Registrar nomes\n");
  printf("\t\t2 - Consultar nomes\n");
  printf("\t\t3 - Deletar nomes\n");


  printf("\n\nEsse software é de livre uso dos alunos da EBAC\n");
  return 0;
}