#include <stdio.h> // Biblioteca de comunicação com o usúario 
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocações em texto por região
#include <string.h> // Biblioteca responsável pelas strings 

int registro() //Função ressponsável por cadastras os usúarios no sistema
{
	//Inicio de criação de variáveis/string
	char arquivo[40];// Utilizando string 40 é o numero de caracteres que serão regitrados na string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de criação de variáveis/string 
	
	printf("Digite o CPF a ser cadastrado: \n");//Coletando indormação do usúario
	scanf("%s", cpf); // %s é utilizado para registrar como string 
	
	strcpy(arquivo, cpf); // Função responsavel para copiar a string cpf para o nome do arquivo 
	
	FILE *file;// Parte de criação do arquivo no banco de dados 
	file = fopen(arquivo, "w"); // W de write, função responsavel por criar/escrever o novo registro/banco de dados
	fprintf(file,"CPF: ");
	fprintf(file, cpf); // O f antes da função serve para direciona-la para ser executada dentro do arquivo de dados
	fclose(file);
	
	file = fopen(arquivo, "a"); // A é utilizado para editar um arquivo já existente
	fprintf(file,"\n Nome: ");
	fclose(file);
	system("cls");
	
	printf("Digite o nome a ser cadastrado: \n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	system("cls");
	
	file = fopen(arquivo, "a"); 
	fprintf(file,"\n Sobrenome :");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	system("cls");
	
	file = fopen(arquivo, "a"); 
	fprintf(file,"\n Cargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	printf("\n\n Usúario registrado com sucesso! ");
	
	system("pause");
	system("cls");
		
} // Fim da função Registro 

int consulta()// Função responsavel por realizar consultas de usuarios no sistema através do CPF
{
	char cpf[40];
	char conteudo[200];
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Digite o CPF a ser consultado: \n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");// r de read,comando para ler/ consultar
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, pois o mesmo ainda não foi registrado!\n");	
	}

	printf("\n Essas são as informações do usuário: ");
	printf("\n");
	
	while(fgets(conteudo, 200, file) != NULL) // Comando para que o programa buscar todas as informações no banco de dados
	{
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
} //Fim da função Consulta

int deletar() //Função responsavel por deletar usuarios do sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usúario a ser deletado: \n");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    fclose(file);
    
    if(file == NULL)
    {
    	printf("O usúario não foi encontrado no sistema!\n");
		system("pause");
	}
    
    else
    {
		remove(cpf);// Função para deletar dados, é recomendado usar sistemas de backup em conjunto
    	printf("O usúario foi deletado do sistema!\n");
    	
	}
	fclose(file);
	system("pause");
} //Fim da função deletar

int main()
{
	int opcao=0; // Definindo a variavel
	int x=1; // Variavel para laço de repetição 
	
	for(x=1;x=1;) // Laço de repetição 
	{
	   
	   system("cls");
	  
	   setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem 
	
	   printf("\t Cartório do Diego\n\n"); // Inicio do Menu
	   printf("Escolha a opção desejada do menu:\n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n");
	   printf("\t4 - Sair do sistema\n");
	
	   scanf("%d",&opcao); // Registrando o valor na variavel
	
	   system("cls"); // Comando para limpar a tela 
	   
	   switch(opcao) // Seleção das opções do menu 
	   {
	        case 1: // Se uitiliza : ao invés de ;
	        registro(); //Chamada de opção de registro
			break;
			
			case 2:
			consulta(); //Chamada de opção de consulta
			break;
			
			case 3:
			deletar(); //Chamada de opção para deletar
    		break;
    		
    		case 4:
    		printf("Obrigado por utilizar o sistema!\n");
    		system("pause");
    		return 0;
    		break;
			
			default: //Opção para entrada de valores não correspondentes com as opções do menu
			printf("Essa opção não existe!\n");
  	        system("pause");
			     	
	   }// Fim de seleção do Menu
   
    } // Fim do laço de repetição 
	
	
}