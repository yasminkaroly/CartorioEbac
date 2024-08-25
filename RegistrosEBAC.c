#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca pra cuidar dos strings

int registro() //função responsável por cadastrar usuários
{
	//inicio de criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando infos do usuário
	scanf("%s", cpf); //%s refere-se a armazenar as infos
	
	strcpy(arquivo, cpf); //responsavel por copiar valor das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); // cria na pasta e "w" write
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");  //abre arquivo
	fprintf(file, ","); //insere a "," entre as infos dados pelo usuário
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
	file = fopen(cpf,"r"); //abre e "r" lê as infos
	
	if(file == NULL) // se não tiver a info no sistema faça isso
	{
		printf("Não foi possível localizar o arquivo.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //quando solicitado mostre o que tem na file e NUll se não encontrar o dado no banco
	{
		printf("Estas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n"); //pular linha
	}
	
	system("pause");
	fclose(file);
	
}

int deletar()
{
	
	char cpf[40]; //acessando a string na base
	
	printf("Digite qual o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //comando que deleta o valor da variável automáticamente adicionado pela biblioteca
	
	FILE *file;
	file = fopen(cpf,"r"); //criando a file e lendo
	
	if(file == NULL)
	{
		printf("Usuário não se encontra no sistema.\n");
		system("pause");
	}
	
}


int main()
{
	
	int opcao=0; //definindo variável
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
	     printf("Selecione a opção desejada do menu:\n\n");
	     printf("\t1. Registrar usuário\n");
	     printf("\t2. Consultar registros\n");
	     printf("\t3. Deletar usuário\n");
	     printf("\t4. Sair do sistema\n\n");
	     printf("Opção: "); //fim do menu
	
	     scanf("%d", &opcao); //armazenando escolha do usuário
	
	     system("cls"); //responsavel por limpar a tela
	
	
	     switch(opcao)
    	{
		   case 1:
		   registro(); //chamada de funções
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
		   printf("Esta opção não está disponível\n");
		   system("pause");
		   break;
	   }
   }

}

    else 
      printf("Senha Incorreta!");
      
}

  
	

	

