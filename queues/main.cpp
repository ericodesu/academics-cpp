#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAXCHOICE 7

struct arquivo {
	char nameArqv[10];
	char typeArqv[5];
	int numPag;
	struct arquivo* next;
};

int menu(); //Função que mostra o menu e coleta a escolha(aka-isChoice).
void inicializa(); //Função que inicializa a fila de impressão
void insertImp(arquivo **pointerToHead,arquivo **pointerToTail); //Função que insere um node (arquivo) a fila de impressão
void canceImp(arquivo **pointerToHead,arquivo **pointerToTail); //Função que cancela a node da fila de impressão
void consuImp(arquivo **pointerToHead,arquivo **pointerToTail); //Função que consome o node inicial da fila de impressão.
void statusImp(arquivo *pointerHead, arquivo *pointerTail); //Função que mostra o status(tamanho da fila && quantas páginas a imprimir) da fila de impressão.
void statusSecImp(arquivo *pointerHead, arquivo *pointerTail); //Função que mostra o status (nome do arquivo, tipo do arquivo e numero de páginas)da fila de impressão.
void resetImp(arquivo **pointerToHead,arquivo **pointerToTail); //Função que deleta todos os nodes da fila de impressão.
void aboutProgram(); //Função que explica oque o programa faz e os desenvoledores incluidos.

int numPagTotal; // Números de paginas totais
int tam; //Tamanho total da lista

int main (void)
{
	setlocale(LC_ALL, "portuguese");
	
	arquivo* head = NULL; //Inicializção do Nó inicial
	arquivo* tail = NULL; //Inicializção do Nó final
	
	int choice;
	
	inicializa(); //Chamada	
	
	do {
		choice = menu();
		
		switch (choice) {
			case 1:
				char wantMore;
				
			    do{	
					insertImp(&head,&tail);
			        printf("\nInserir mais um arquivo a Lista [Y/N?] ");
			        fflush(stdin);
			        scanf("%c", &wantMore);   
					   
			    }while(wantMore == 'Y' || wantMore == 'y');		
				
			break;
			
			case 2:
				canceImp(&head, &tail);
				printf("\n\n");
				system("PAUSE");				
			break;
			
			case 3:
				consuImp(&head, &tail);
				printf("\n\n");
				system("PAUSE");				
			break;
			
			case 4:
				statusImp(head, tail);
				printf("\n\n");
				system("PAUSE");					
			break;

			case 5:
				resetImp(&head, &tail);
				printf("\n\n");
				system("PAUSE");					
			break;
			
			case 7:
				aboutProgram();
				printf("\n\n");
				system("PAUSE");								
			break;									
		}
	}while(choice != 6);
	
	return 0;		
}

int menu() //Função que mostra o menu e coleta a escolha(aka-isChoice).
{
	int isChoice = 0;
	
	system("CLS"); //Limpa o display
	
	printf("==================== Menu ======================\n\n"); //Menu principal para escolha de ações
	printf("Bem vindo ao menu!\n\nAqui estão as opções para a lista de impressões!\nVocê deve escolher entre as opções disponíveis:");
	printf("\n\n[1]-Inserir um novo arquivo na fila\n[2]-Cancelar um arquivo em dada posição da fila\n[3]-Consumir o proxímo arquivo da fila\n[4]-Mostrar o status atual da fila de impressão\n[5]-Limpar por completo a fila de impressão\n[6]-Finalizar\n[7]-Sobre");
	printf("\n\n================================================");
	do{ 
		printf("\n\nPor favor digite a opção que deseja: ");
		scanf("%d", &isChoice);
		
		if(isChoice < 1 || isChoice > MAXCHOICE){
			
			printf("Oops você inseriu a opção %dª mas so têm de 1ª a %dª,tente novamente.",isChoice,MAXCHOICE);
		}
		
	}while(isChoice < 1 || isChoice > MAXCHOICE);
	
	return isChoice;
}

void inicializa() //Função que inicializa a fila de impressão
{
	numPagTotal = 0;
	tam = 0;
		
	printf("==================================================\n");
	printf("\t\tFila Inicalizada");	
	printf("\n==================================================\n\n");
	system("PAUSE");	
	
}

void insertImp(arquivo **pointerToHead,arquivo **pointerToTail) //Função que insere um node (arquivo) a fila de impressão
{
	printf("\n");
	
	arquivo *newNode = (arquivo *)malloc(sizeof(arquivo)); //Cria novo nó com tamanho do struct (arquivo)
	
	if(newNode)
	{
		printf("Por favor insira o nome do arquivo a ser impresso: ");
		fflush(stdin);
		scanf("%s", &newNode -> nameArqv);
		printf("\nAgora, insira o formato do arquivo a ser impresso: ");
		fflush(stdin);
		scanf("%s", &newNode -> typeArqv);
		
		do{
			printf("\nAgora, insira o número de páginas do arquivo a ser impresso: ");
			fflush(stdin);
			scanf("%d", &newNode -> numPag);
		
			if(newNode -> numPag <= 0){
				printf("\nOops, por favor insira o valor do número de páginas maior que 0 e tente novamente!\n");
			}
			
		}while(newNode -> numPag <= 0);
		
		newNode -> next = NULL;
		
		if(!(*pointerToHead) && !(*pointerToTail))
		{
			
			*pointerToHead = newNode; //Faz o ponteiro inicial set o novo nó. 
			*pointerToTail = newNode; //Faz o ponteiro final set o novo nó.
		}
		else 
		{
			arquivo *temp = (*pointerToHead); //Cria um ponteiro do tipo arquivo que contém o inicial atual.
			
			while(temp->next != NULL)
			{	
			
				temp = temp->next; //Faz o pointeiro temporario apontar para o proxímo enquanto o for diferente de NULL.	
			}
			
			temp->next = newNode; //Iguala proximo ponteiro do nó temporário para o novo nó.
			*pointerToTail = newNode; //Iguala o nó inicial ao novo nó
		}
		
		numPagTotal = numPagTotal + newNode -> numPag; //Soma o númerode páginas totais com o número de páginas do nó inserido 
		tam++; //Adiciona um ao tamanho da lista
		
		return;
	}	
	
	printf("\nNão foi possível alocar espaço na memória!");
	return;
}

void canceImp(arquivo **pointerToHead,arquivo **pointerToTail) //Função que cancela a node da fila de impressão
{
	printf("\n");
	
	if(!(*pointerToHead) && !(*pointerToTail)) //Se o nód e inicio e final são iguais a NULL a fila está vazia.
	{
		printf("A Fila de impressão está vazia impossível efetuar um cancelamento!");

		return;
	}	
	
	statusSecImp(*pointerToHead, *pointerToTail);
	
   	arquivo *temp = *pointerToHead;	
	
	int position; //Variável que indicará posição.
	
    do{
    	
		printf("Posição a cancelar: ");
	    scanf("%d", &position);
	    
	    if(position > tam){
	    	printf("\nOops você inseriu a posição [%d], por favor insira uma posição válida!\n", position);
		}
	    
	}while(position > tam); //Equanto a posição for maior que o tamanho
	
	    if(position == 1){
	    	if(*pointerToHead == *pointerToTail)
			{
				*pointerToHead = NULL;
				*pointerToTail = NULL;
				numPagTotal = numPagTotal - temp->numPag;
				tam--;			
				free(temp);
	
				printf("\nVocê cancelou a única Impressão da Fila!");
						
				return;
			}
				
			*pointerToHead = temp->next; 	
			numPagTotal = numPagTotal - temp->numPag;
			tam--;			
			free(temp);	
			
			printf("\nVocê cancelou a impressão na posição [%d] !", position);			
				
			return;
		}
		
	    if(position == 2 && temp->next->next == NULL)
		{
			arquivo *temp2 = temp->next;
			temp -> next = NULL;
			numPagTotal = numPagTotal - temp2->numPag;
			tam--;
			*pointerToTail = temp;			
			free(temp2);
	
			printf("\nVocê cancelou a impressão na posição [%d] !", position);
						
			return;
		}		
    	
		for(int isPosition = 0;isPosition < position - 2;isPosition ++){  //Enquanto a isPostion for menor que a Posição 
			
			temp = temp->next;
		}
		
		arquivo *temp2 = temp->next; //Cria um ponteiro do tipo arquivo que contém o o proximo no.
		temp -> next = temp2 -> next;
	    tam --;
		numPagTotal = numPagTotal - temp2->numPag;    	
	    free(temp2);
		printf("Você cancelou a impressão na posição [%d] !", position);	    	
	    
		return;
}

void consuImp(arquivo **pointerToHead,arquivo **pointerToTail) //Função que consome o node inicial da fila de impressão.
{
	printf("\n");
	
	if(!(*pointerToHead) && !(*pointerToTail))
	{
		printf("A Fila de impressão está vazia!");
		
		return;
	}
	
	arquivo *temp = *pointerToHead;
	
	if(*pointerToHead == *pointerToTail)
	{
		*pointerToHead = NULL;
		*pointerToTail = NULL;
		free(temp);
		numPagTotal = numPagTotal - numPagTotal;
		tam--;
			
		printf("Você consumiu a única Impressão da Fila!");
				
		return;
	}
	
	*pointerToHead = (*pointerToHead)->next;
	numPagTotal = numPagTotal - temp->numPag;
	free(temp);
	tam--;
		
	printf("Você consumiu a proxíma impressão!");
	
	return;
}

void statusImp(arquivo *pointerHead, arquivo *pointerTail) //Função que mostra o status(tamanho da fila && quantas páginas a imprimir) da fila de impressão.
{
	if(!(pointerHead) && !(pointerTail))
	{
		printf("\nA Fila de impressão está vazia!");
		
		return;
	}	
	
	printf("\n============= Status Principais ================\n");	
	printf("\nO tamanho da Fila de impressão .........é: %d", tam);
	printf("\nO total de páginas na fila de impressão é: %d", numPagTotal);
	printf("\n\n================================================");	
	
	statusSecImp(pointerHead, pointerTail);
	
}
void statusSecImp(arquivo *pointerHead, arquivo *pointerTail) //Função que mostra o status (nome do arquivo, tipo do arquivo e numero de páginas)da fila de impressão.
{
	int position = 1;
	
	printf("\n\n============== Fila de Impressão ===============\n");	    
    while(pointerHead) {
        printf("\n[%d] - %s.%s\n", position, pointerHead->nameArqv, pointerHead->typeArqv);
        printf("Nome do arquivo........: %s\n", pointerHead->nameArqv);        
        printf("Formato do arquivo.....: %s\n", pointerHead->typeArqv);
        printf("Número de páginas......: %d\n", pointerHead->numPag);
        pointerHead = pointerHead->next;
        position++;
    }    
	printf("\n================================================\n\n");	
	
}

void resetImp(arquivo **pointerToHead,arquivo **pointerToTail) //Função que deleta todos os nodes da fila de impressão.
{		
	if(!(*pointerToHead) && !(*pointerToTail))
	{
		
		printf("\nA Fila de impressão está vazia impossível a limpeza!");
		
		return;
	}
	
	numPagTotal = 0;
	
	while(tam >= 1){
		arquivo *temp = *pointerToHead;					
		*pointerToHead = (*pointerToHead)->next;
		free(temp);
		tam--;
	}
	
	*pointerToHead = NULL;
	*pointerToTail = NULL;

	printf("\nA Fila de impressão foi limpa!");

	return;			
}

void aboutProgram() //Função que explica oque o programa faz e os desenvoledores incluidos.
{
		printf("\nProjeto Acadêmico visando simular uma Lista de Impressão, sem fins lucrativos, tendo em vista somente o aprendizado!");                                                                                                		
		printf("\n\nObrigado por ultilizar :D");
		printf("\n\n\t\t\t\t\t\t\t\t\t\tDesenvolvedores:");
		printf("\n\t\t\t\t\t\t\t\t\t\tErick Frederick (ericodesu) :D");
		printf("\n\t\t\t\t\t\t\t\t\t\tMaurício Augusto");	
}
