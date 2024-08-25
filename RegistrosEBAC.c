#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca pra cuidar dos strings

int registro() //fun��o respons�vel por cadastrar usu�rios
{
	//inicio de cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando infos do usu�rio
	scanf("%s", cpf); //%s refere-se a armazenar as infos
	
	strcpy(arquivo, cpf); //responsavel por copiar valor das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); // cria na pasta e "w" write
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");  //abre arquivo
	fprintf(file, ","); //insere a "," entre as infos dados pelo usu�rio
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //congela a tela
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo idioma
	
	char cpf[100]; //acessando a string
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file; //criando o arquivo
	file = fopen(cpf,"r"); //abre e "r" l� as infos
	
	if(file == NULL) // se n�o tiver a info no sistema fa�a isso
	{
		printf("N�o foi poss�vel localizar o arquivo.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //quando solicitado mostre o que tem na file e NUll se n�o encontrar o dado no banco
	{
		printf("Estas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n"); //pular linha
	}
	
	system("pause");
	fclose(file);
	
}

int deletar()
{
	
	char cpf[40]; //acessando a string na base
	
	printf("Digite qual o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //comando que deleta o valor da vari�vel autom�ticamente adicionado pela biblioteca
	
	FILE *file;
	file = fopen(cpf,"r"); //criando a file e lendo
	
	if(file == NULL)
	{
		printf("Usu�rio n�o se encontra no sistema.\n");
		system("pause");
	}
	
}


int main()
{
	
	int opcao=0; //definindo vari�vel
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Registro de alunos EBAC ###\n\n");
	printf("Login de administrador.\n\nDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	  for(laco=1;laco=1;) //repetir o comando para sempre retornar ao menu
      {
      	
	    system("cls"); //limpa a tela
	
	    setlocale(LC_ALL, "Portuguese"); //definindo idioma
	
	
	     printf(("### Registro de alunos EBAC ###\n\n")); //inicio do menu
	     printf("Selecione a op��o desejada do menu:\n\n");
	     printf("\t1. Registrar usu�rio\n");
	     printf("\t2. Consultar registros\n");
	     printf("\t3. Deletar usu�rio\n");
	     printf("\t4. Sair do sistema\n\n");
	     printf("Op��o: "); //fim do menu
	
	     scanf("%d", &opcao); //armazenando escolha do usu�rio
	
	     system("cls"); //responsavel por limpar a tela
	
	
	     switch(opcao)
    	{
		   case 1:
		   registro(); //chamada de fun��es
		   break; 
		    
		    
		   case 2:
		   consultar();
		   break;
		
		
		   case 3:
		   deletar();
		   break;
		
		
		   case 4:
		   printf("Obrigado por utilizar o sistema!\n");
		   return 0;
		   break;
		
		
		   default:
		   printf("Esta op��o n�o est� dispon�vel\n");
		   system("pause");
		   break;
	   }
   }

}

    else 
      printf("Senha Incorreta!");
      
}

  
	

	

