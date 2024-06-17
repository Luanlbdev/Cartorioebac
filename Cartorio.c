#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Inicío da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação  de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string

    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); //salvo o valor da variavel
    fclose(file); //fecha o arquivo
    
    file=fopen(arquivo, "a"); 
    fprintf(file,","); //salvo valor da variável
    fclose(file); //fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
    scanf("%s",nome); //%s refere-se a string
    
    file = fopen(arquivo, "a");
    fprintf(file,nome); //salva o valor da variável
    fclose(file); //fecha o arquivo

    file=fopen(arquivo, "a");
    fprintf(file,","); //salva o valor da variável
    fclose(file); //fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); //coletando informção do usuário
    scanf("%s", sobrenome); //%s refere-se a string
    
    file = fopen(arquivo, "a"); 
    fprintf(file,sobrenome); //salva o valor da variável
    fclose(file); //fecha o arquivo
    
    file=fopen(arquivo, "a");
    fprintf(file,","); //salva o valor da variável
    fclose(file); //fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário
    scanf("%s", cargo); //%s refere-se a string
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo); //salva o valor da variável
    fclose(file); //fecha o arquivo
    
    system("pause");
    
}

int consulta() //Função responsável por consultar a informação dos usuários do sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Inicio da criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//Fim da criação variáveis/string
	
	printf("Digite o cpf a ser consultado: "); //consultando informação o usuário
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf, "r"); //cria o arquivo e "r" significa ler
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");


}

int deletar() //Função responsável por deletar a informção do usuário do sistema
{
	//Inicio da criação de variável/string
	char cpf[40];
	//Fim da criação de variável/string
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //cria o arquivo e "r" significa ler
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
}



int main()
    {
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	    
	    system("cls"); //responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	    
	    printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
	    printf("Escolha a opção desejada do menu: \n\n");
	    printf("\t1 - rigistrar nomes\n");
	    printf("\t2 - consultar nomes\n");
	    printf("\t3 - deletar nomes\n\n"); 
	    printf("Opção: ");//Fim do menu
	    
	    scanf("%d", &opcao); //Armazenando a escolha do usúaria
	
	    system("cls"); //responsável por limpar a tela
	    
	    switch(opcao) //Inicio da seleção do menu
	    {
	    	case 1:
	    	registro(); //chamada de funções
	        break;
	        
	        case 2:
	        consulta(); //chamda de funções
	        break;
	        
	        case 3:
	        deletar(); //chamada de funções
	        break;
	        
	        default:
	        printf("essa opção não está disponivel!");
	        system("pause");
	        break;  
		} //Fim da seleção do menu
	
    }
}
