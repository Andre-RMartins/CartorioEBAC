#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de textos por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro()//Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio das cria��es da vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das cria��es da vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo,cpf);//Respons�vel por copiar os valores das string
	
	FILE *file;//cria o arquivo no banco de dados
	file = fopen(arquivo, "w");//cria o arquivo na pasta o "w" significa escrever
	fprintf(file, cpf);//salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//"a" significa acessar
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta()//Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
	//in�cio das cria��es da vari�veis/string
	char cpf[40];
	char conteudo[200];
	//fim das cria��es da vari�veis/string
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)//caso o CPF digitado n�o se encontre no sistema
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}

	while(fgets(conteudo, 200, file) != NULL)//respons�vel por localizar e escrever as informa��es do usu�rio no sistema
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()//Fun��o respons�vel por deletar os usu�rios no sistema
{
	char cpf[40];//cria��o da vari�vel/string
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);//respons�vel por excluir o cadastro
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)//verifica se o usu�rio est� no sistema
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
}

int main ()
{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o:");//fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
		system("cls");//respons�vel por limpar a tela
		
		switch(opcao)//in�cio da sele��o do menu
		{
			case 1:
			registro();//chamada de fun��es
			break;
			
			case 2:
			consulta();//chamada de fun��es
			break;
			
			case 3:
			deletar();//chamada de fun��es
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n\n");
			system("pause");
			break;
		}//fim da sele��o do menu
	}
}
