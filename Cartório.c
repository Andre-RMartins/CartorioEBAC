#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de textos por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro()//Função responsável por cadastrar os usuários no sistema
{
	//início das criações da variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das criações da variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo,cpf);//Responsável por copiar os valores das string
	
	FILE *file;//cria o arquivo no banco de dados
	file = fopen(arquivo, "w");//cria o arquivo na pasta o "w" significa escrever
	fprintf(file, cpf);//salva o valor da variável
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

int consulta()//Função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
	//início das criações da variáveis/string
	char cpf[40];
	char conteudo[200];
	//fim das criações da variáveis/string
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)//caso o CPF digitado não se encontre no sistema
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}

	while(fgets(conteudo, 200, file) != NULL)//responsável por localizar e escrever as informações do usuário no sistema
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()//Função responsável por deletar os usuários no sistema
{
	char cpf[40];//criação da variável/string
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);//responsável por excluir o cadastro
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)//verifica se o usuário está no sistema
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
}

int main ()
{
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção:");//fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls");//responsável por limpar a tela
		
		switch(opcao)//início da seleção do menu
		{
			case 1:
			registro();//chamada de funções
			break;
			
			case 2:
			consulta();//chamada de funções
			break;
			
			case 3:
			deletar();//chamada de funções
			break;
			
			default:
			printf("Essa opção não está disponível!\n\n");
			system("pause");
			break;
		}//fim da seleção do menu
	}
}
