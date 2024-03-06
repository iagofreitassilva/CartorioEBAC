#include <stdio.h> //biblioteca de comunica��o com usu�rio 
#include <stdlib.h>  //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das strigs



int registro() // fun��o respons�vel por cadastra usu�rios no sistema
{
	//inicio cria��o de vari�veis/strings
	
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o das vari�veis
	
	printf("Digite seu cpf: "); // coleta de info do usu�rio
	scanf("%s", cpf); // "%s" refere-se a string
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores da string // igualando o valor do arquivo com cpf para ser salvo
		
	 FILE *file; // cria o arquivo
	 file = fopen(arquivo, "w"); // cria o arquivo do tipo escrever por conta do w/ "w" significa escrever
	 fprintf(file,cpf); // salva o valor da vari�vel
	 fclose(file); // fecha o arquivo
	
	 file = fopen(arquivo, "a"); // abrindo o arquivo com bas na atualiza��o
	 fprintf(file, ","); // separa��o das caracter�sticas
	 fclose(file); // fechando o arquivo
	
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
	
	
	 printf("Digite o cargo a ser cadastrado:");
	 scanf("%s",cargo);
	
	 file = fopen(arquivo, "a");
	 fprintf(file,cargo);
     fclose(file);
	
	 system("pause");
	
	
}

int consultar()
{
	setlocale(LC_ALL, "portuguese"); // defini��o da linguagem
	// vari�veis
    char cpf[40];
    char conteudo[200]; // onde vai ser armazenado
    
    printf("Digite o cpf a ser consultado: "); // conversa��o com o usu�rio
    scanf("%s", cpf); // salvando na string cpf / porque e uma vari�vel 
    
    FILE *file; // chamada do arquivo
    file = fopen(cpf, "r"); // r porque e de ler 
    
    
    if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!. \n");
	}
     
    while(fgets(conteudo, 200, file) != NULL)  // cria��o de um la�o de repeti��o, est� sndo salvo na vari�vel conteudo(string) os 200 caracteres que estao dentro do arquivo // "enquanto tiver conte�do dentro desse arquivo ele vai armazenando dentro da vari�vel (conteudo) "
     {
     	printf("\nEssas s�o as informa��es do usu�rio: ");
     	printf("%s", conteudo);
     	printf("\n\n");
	 }
    
        system("pause");
    
}

int deletar()
{
	//vari�vel na hora de deletar
	
    char cpf[40];
    
    printf("Digite o cpf do usu�rio a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf); // fun��o de remove inclusa da biblioteca
    
    FILE* file;  //  come�o da valida��o do arqruivo
    file = fopen(cpf, "r"); // "r" porque � leitura do arquivo
    
    if (file == NULL) // valida��o
	{
		printf("Usu�rio n�o identificado!\n");
		system("pause"); // pausa para o usu�rio n sair direto da tela 
	}


}



int main() // chamada de menu 
{
	
	
	int opcao=0; // = atribuiu o valor // defini��o de vari�veis
	
	int x=1;
	for(x=1;x=1;)
{
	    
	    system("cls"); // respons�vel por limpar a tela
	    
    setlocale(LC_ALL, "portuguese"); // defini��o da linguagem
	
	    printf("###cart�rio da EBAC###\n\n"); //in�cio do menu
    	printf("Escolha a op��o desejada do menu:\n\n"); // comando escrito na tela
	    printf("\t1 - Registrar nomes\n"); //1
    	printf("\t2 - Consultar os nomes\n"); //2
    	printf("\t3 - Deletar os nomes\n\n"); //3
        printf("Op��o: "); // fim do menu
       
        scanf("%d", &opcao); // armazenando a escolha do usu�rio
    
        system("cls"); // respons�vel por limpar a tela
        
        switch(opcao) // inicio da sele��o do menu
        {
        	case 1:
        	registro(); //chamada de fun��o
        	break;
        	
        	case 2:
			consultar(); // chamada de fun��o
        	break;
        	
        	case 3:
			deletar(); // chamada de fun��o
	    	break;
	    	
	    	
	       default: //chamada de fun��o inesistente exemplo numero 4 
	       printf("Essa op��o n�o est� disponivel!\n");
		   system("pause");
	       break; 
		// fim da sele��o!
		
		}
					
    } 	
	   		
 }
 


