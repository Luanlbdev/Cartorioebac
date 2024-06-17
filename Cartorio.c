#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Inic�o da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o  de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string

    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); //salvo o valor da variavel
    fclose(file); //fecha o arquivo
    
    file=fopen(arquivo, "a"); 
    fprintf(file,","); //salvo valor da vari�vel
    fclose(file); //fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
    scanf("%s",nome); //%s refere-se a string
    
    file = fopen(arquivo, "a");
    fprintf(file,nome); //salva o valor da vari�vel
    fclose(file); //fecha o arquivo

    file=fopen(arquivo, "a");
    fprintf(file,","); //salva o valor da vari�vel
    fclose(file); //fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); //coletando inform��o do usu�rio
    scanf("%s", sobrenome); //%s refere-se a string
    
    file = fopen(arquivo, "a"); 
    fprintf(file,sobrenome); //salva o valor da vari�vel
    fclose(file); //fecha o arquivo
    
    file=fopen(arquivo, "a");
    fprintf(file,","); //salva o valor da vari�vel
    fclose(file); //fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
    scanf("%s", cargo); //%s refere-se a string
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo); //salva o valor da vari�vel
    fclose(file); //fecha o arquivo
    
    system("pause");
    
}

int consulta() //Fun��o respons�vel por consultar a informa��o dos usu�rios do sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Inicio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//Fim da cria��o vari�veis/string
	
	printf("Digite o cpf a ser consultado: "); //consultando informa��o o usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf, "r"); //cria o arquivo e "r" significa ler
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");


}

int deletar() //Fun��o respons�vel por deletar a inform��o do usu�rio do sistema
{
	//Inicio da cria��o de vari�vel/string
	char cpf[40];
	//Fim da cria��o de vari�vel/string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //cria o arquivo e "r" significa ler
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}



int main()
    {
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	    
	    system("cls"); //respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	    
	    printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
	    printf("Escolha a op��o desejada do menu: \n\n");
	    printf("\t1 - rigistrar nomes\n");
	    printf("\t2 - consultar nomes\n");
	    printf("\t3 - deletar nomes\n\n"); 
	    printf("Op��o: ");//Fim do menu
	    
	    scanf("%d", &opcao); //Armazenando a escolha do us�aria
	
	    system("cls"); //respons�vel por limpar a tela
	    
	    switch(opcao) //Inicio da sele��o do menu
	    {
	    	case 1:
	    	registro(); //chamada de fun��es
	        break;
	        
	        case 2:
	        consulta(); //chamda de fun��es
	        break;
	        
	        case 3:
	        deletar(); //chamada de fun��es
	        break;
	        
	        default:
	        printf("essa op��o n�o est� disponivel!");
	        system("pause");
	        break;  
		} //Fim da sele��o do menu
	
    }
}
