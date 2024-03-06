#include <stdio.h> //biblioteca de comunicação com usuário 
#include <stdlib.h>  //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsável por cuidar das strigs



int registro() // função responsável por cadastra usuários no sistema
{
	//inicio criação de variáveis/strings
	
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação das variáveis
	
	printf("Digite seu cpf: "); // coleta de info do usuário
	scanf("%s", cpf); // "%s" refere-se a string
	
	strcpy(arquivo, cpf); // responsável por copiar os valores da string // igualando o valor do arquivo com cpf para ser salvo
		
	 FILE *file; // cria o arquivo
	 file = fopen(arquivo, "w"); // cria o arquivo do tipo escrever por conta do w/ "w" significa escrever
	 fprintf(file,cpf); // salva o valor da variável
	 fclose(file); // fecha o arquivo
	
	 file = fopen(arquivo, "a"); // abrindo o arquivo com bas na atualização
	 fprintf(file, ","); // separação das características
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
	setlocale(LC_ALL, "portuguese"); // definição da linguagem
	// variáveis
    char cpf[40];
    char conteudo[200]; // onde vai ser armazenado
    
    printf("Digite o cpf a ser consultado: "); // conversação com o usuário
    scanf("%s", cpf); // salvando na string cpf / porque e uma variável 
    
    FILE *file; // chamada do arquivo
    file = fopen(cpf, "r"); // r porque e de ler 
    
    
    if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!. \n");
	}
     
    while(fgets(conteudo, 200, file) != NULL)  // criação de um laço de repetição, está sndo salvo na variável conteudo(string) os 200 caracteres que estao dentro do arquivo // "enquanto tiver conteúdo dentro desse arquivo ele vai armazenando dentro da variável (conteudo) "
     {
     	printf("\nEssas são as informações do usuário: ");
     	printf("%s", conteudo);
     	printf("\n\n");
	 }
    
        system("pause");
    
}

int deletar()
{
	//variável na hora de deletar
	
    char cpf[40];
    
    printf("Digite o cpf do usuário a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf); // função de remove inclusa da biblioteca
    
    FILE* file;  //  começo da validação do arqruivo
    file = fopen(cpf, "r"); // "r" porque é leitura do arquivo
    
    if (file == NULL) // validação
	{
		printf("Usuário não identificado!\n");
		system("pause"); // pausa para o usuário n sair direto da tela 
	}


}



int main() // chamada de menu 
{
	
	
	int opcao=0; // = atribuiu o valor // definição de variáveis
	
	int x=1;
	for(x=1;x=1;)
{
	    
	    system("cls"); // responsável por limpar a tela
	    
    setlocale(LC_ALL, "portuguese"); // definição da linguagem
	
	    printf("###cartório da EBAC###\n\n"); //início do menu
    	printf("Escolha a opção desejada do menu:\n\n"); // comando escrito na tela
	    printf("\t1 - Registrar nomes\n"); //1
    	printf("\t2 - Consultar os nomes\n"); //2
    	printf("\t3 - Deletar os nomes\n\n"); //3
        printf("Opção: "); // fim do menu
       
        scanf("%d", &opcao); // armazenando a escolha do usuário
    
        system("cls"); // responsável por limpar a tela
        
        switch(opcao) // inicio da seleção do menu
        {
        	case 1:
        	registro(); //chamada de função
        	break;
        	
        	case 2:
			consultar(); // chamada de função
        	break;
        	
        	case 3:
			deletar(); // chamada de função
	    	break;
	    	
	    	
	       default: //chamada de função inesistente exemplo numero 4 
	       printf("Essa opção não está disponivel!\n");
		   system("pause");
	       break; 
		// fim da seleção!
		
		}
					
    } 	
	   		
 }
 


