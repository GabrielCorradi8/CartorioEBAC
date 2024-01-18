#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); //separa os arquivos por ","
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //fecha o arquivo

	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); //separa os arquivos por ","
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,sobrenome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); //separa os arquivos por ","
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,cargo); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa o sistema
	
}

int consulta() //Fun��o responsavel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem
	
	//inicio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis/string
	
	printf("Digite o cpf a ser consultado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //cria o arquivo e o "r" significa ler
	
	if(file == NULL) //se o arquivo for igual a nulo
	{
		printf("N�o foi possivel localizar esse cpf!.\n"); //Fala pro usu�rio que n�o localizou o arquivo
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto ele estiver escrevendo na vari�vel string conteudo que est�o dentro do arquivo, enquanto for diferente de nulo 
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //mostra as informa��es pro usu�rio
		printf("%s", conteudo); //%s refere-se a string
		printf("\n\n"); //pulou duas linhas
	}
	
	system("pause"); //pausa o sistema
}

int deletar() //Fun��o responsavel por deletar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser deletado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	remove(cpf); 
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r");  //cria o arquivo e o "r" significa ler
	
	if(file == NULL) //se o arquivo for igual a nulo
	{
		printf("O usu�rio n�o se encontra no sistema!. \n"); //Fala pro usu�rio que n�o localizou o arquivo
		system("pause");
	}
}

int main()
{
	int opcao = 0; // Definindo vari�veis
	int laco = 1;
	
	for(laco=1; laco=1;)
	{

		system("cls"); // Limpeza de mensagens
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); // In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	
		system("cls"); // Limpeza de mensagens
	
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta(); //chamada de fun��es
			break;
			
			case 3:
			deletar(); //chamada de fun��es
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		}
		
	}
}

