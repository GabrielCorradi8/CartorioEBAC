#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); //separa os arquivos por ","
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //fecha o arquivo

	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); //separa os arquivos por ","
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,sobrenome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); //separa os arquivos por ","
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,cargo); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa o sistema
	
}

int consulta() //Função responsavel por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem
	
	//inicio criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis/string
	
	printf("Digite o cpf a ser consultado: "); //coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //cria o arquivo e o "r" significa ler
	
	if(file == NULL) //se o arquivo for igual a nulo
	{
		printf("Não foi possivel localizar esse cpf!.\n"); //Fala pro usuário que não localizou o arquivo
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto ele estiver escrevendo na variável string conteudo que estão dentro do arquivo, enquanto for diferente de nulo 
	{
		printf("\nEssas são as informações do usuário: "); //mostra as informações pro usuário
		printf("%s", conteudo); //%s refere-se a string
		printf("\n\n"); //pulou duas linhas
	}
	
	system("pause"); //pausa o sistema
}

int deletar() //Função responsavel por deletar os usuários no sistema
{
	//inicio criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser deletado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	remove(cpf); 
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r");  //cria o arquivo e o "r" significa ler
	
	if(file == NULL) //se o arquivo for igual a nulo
	{
		printf("O usuário não se encontra no sistema!. \n"); //Fala pro usuário que não localizou o arquivo
		system("pause");
	}
}

int main()
{
	int opcao = 0; // Definindo variáveis
	int laco = 1;
	
	for(laco=1; laco=1;)
	{

		system("cls"); // Limpeza de mensagens
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem
	
		printf("### Cartório da EBAC ###\n\n"); // Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); // Armazenando a escolha do usuário
	
		system("cls"); // Limpeza de mensagens
	
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta(); //chamada de funções
			break;
			
			case 3:
			deletar(); //chamada de funções
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		}
		
	}
}

