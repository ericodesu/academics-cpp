#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <locale.h>

#define EVENT_MAX_SITS 5591
#define EVENT_MAX_GYMBADGE 1000000
#define EVENT_MIN_LENGTH 2
#define EVENT_MAX_LENGTH 5
#define MENU_MAX_CHOICE 5

using namespace std;

struct infTicket
{
	int ticketBadge;	
};
struct infTicket aTicket;

int showMenu();
void getTicketInfo();
int insertToMap();
int giveTicketInfo();
void removeFrmMap();
void showAboutMap();
void showAbout();
bool isFull();
bool isEmpty();
int getKey();
bool searchMap(int getABadge);

char areFull,areEmpty,wantMore;

map<int, int> aMap;

int main(void)
{
	setlocale(LC_ALL, "portuguese");
	
	int aChoice,aChair;
	
	do 
	{
		system("CLS");
		
		aChoice = showMenu();
		
		switch (aChoice) 
		{
			case 1:
				
				areFull = isFull();
				
				system("CLS");	
				
				printf("========================================================================================================");
				printf("\n\nBem vindo a catraca de entrada!\n\nLembre-se que só tem acesso ao a este palco o ingresso com estadia no evento de mínimo %d dias!", EVENT_MIN_LENGTH);
				printf("\n\n========================================================================================================");	
							
				do
				{
					if(areFull == true)
						break;
						
					getTicketInfo(); 				
					aChair = insertToMap();
					printf("\nMais uma entrada [Y/N] ?: ");
					fflush(stdin);
					scanf("%c", &wantMore);
						
				}while(wantMore == 'Y' || wantMore == 'y');
								
			break;
		
			case 2:
				
				areEmpty = isEmpty();
				
				system("CLS");
				
				printf("===================================================");
				printf("\n\nVocê está saindo do evento, sentiremos a sua falta!");
				printf("\n\n===================================================");				
						
				do
				{ 		
					if(areEmpty == true)
						break;
									
					removeFrmMap();
							
					printf("\nMais uma saída [Y/N] ?:");
					fflush(stdin);
					scanf("%c", &wantMore);	
						
				}while(wantMore == 'Y' || wantMore == 'y');				
				
				printf("\n\n");
				system("PAUSE");															
							
			break;
			
			case 3:
				system("CLS");
								
				showAboutMap();
							
				printf("\n\n");
				system("PAUSE");						
							
			break;
			
			case 5:
				system("CLS");
				
				showAbout();
				
				printf("\n\n");
				system("PAUSE");
														
			break;	
												
		}
		
	}while(aChoice != 4);	
	
	printf("\n\n====================================================");
	printf("\n\nO programa vai ser encerrado,obrigado por ultilizar!");
	printf("\n\n====================================================");
	
	printf("\n\n");
	system("PAUSE");
	
	return 0;
}

int showMenu()
{
	int getChoice;
	
	system("CLS"); //Limpa o display
	
	printf("======================= MENU ========================\n\n"); //Menu principal para escolha de a��es
	printf("Bem vindo a Comic-Con!\n\nAqui estão as opçães para entrada ou saída ao evento!\nVocê deve escolher entre as opções disponíveis:");
	printf("\n\n[1]-Inserir os dados do ingresso e entrar ao evento\n[2]-Registrar a saída do evento\n[3]-Relatórios sobre o evento\n[4]-Fechar Programa\n[5]-Sobre");
	printf("\n\n=====================================================");
	
	do
	{ 
		printf("\n\nPor favor digite a opção que deseja: ");
		scanf("%d", &getChoice);
		
		if(getChoice < 1 || getChoice > MENU_MAX_CHOICE)
		{
			printf("\nOops você inseriu a %dº opçõo mas so têm de 1º a %dº,tente novamente.",getChoice,MENU_MAX_CHOICE);
		}
	}while(getChoice < 1 || getChoice > MENU_MAX_CHOICE);	
	
	return getChoice;
}



void getTicketInfo()
{
	
	areFull = isFull();
	
	if(areFull == true)
		return;
	
	int getTotalDays;
	bool isMajorGo;
		
	do
	{
		printf("\n\nPor favor insira o número do Badge do ingresso, lembre-se que ele precisa ter o valor menor que %d: ", EVENT_MAX_GYMBADGE);
		scanf("%d", &aTicket.ticketBadge);
		if(aTicket.ticketBadge > EVENT_MAX_GYMBADGE || aTicket.ticketBadge <= 0)
		{
			printf("\n\nOoops, Lembre-se que o Badge do ingresso tem que ser menor que %d maior que 0! Tente Novamente!\n", EVENT_MAX_GYMBADGE);
		}
		
		isMajorGo = searchMap(aTicket.ticketBadge);
		
		if(isMajorGo == true)
		{
				
			printf("\n\nOoops, este ingresso está dentro do evento!\n");
				
		}
		
	}while(aTicket.ticketBadge > EVENT_MAX_GYMBADGE || aTicket.ticketBadge <= 0 || isMajorGo == true);
	
	do
	{		
		printf("\n\nPor favor insira a quantidade de dias da estadia do ingresso, lembre-se que ele precisa ter o valor maior que %d: ", EVENT_MIN_LENGTH);   
		scanf("%d", &getTotalDays);
		if(getTotalDays < EVENT_MIN_LENGTH || getTotalDays > EVENT_MAX_LENGTH)
		{
			printf("\n\nOoops, Só tem acesso quem tem a quantidade de dias da estadia do ingresso maior que %d e menor que %d! Tente Novamente!\n", EVENT_MIN_LENGTH, EVENT_MAX_LENGTH);
		}
	}while(getTotalDays < EVENT_MIN_LENGTH || getTotalDays > EVENT_MAX_LENGTH);
		
}

int giveTicketInfo()
{
	int theBadge;
	
	printf("\n\nPor favor insira o número do Badge do ingresso: ");
	scanf("%d", &theBadge);
	
	return theBadge;
}

int insertToMap()
{	
	int getChair = getKey();
	
	aMap[aTicket.ticketBadge]=getChair;		
	
	return getChair; 
}

bool searchMap(int getABadge)
{	
	if(aMap.find(getABadge) == aMap.end())
	{
        return false;
	}else
		return true;
        		
}

void removeFrmMap()
{
	
	areEmpty = isEmpty();
	
	if(areEmpty == true)
		return;	
	
	int getBadge ;
	
	do
	{	
		printf("\n\nPor favor insira o seu Badge para registrarmos sua saída: ");
		scanf("%d", &getBadge);
		if(getBadge > EVENT_MAX_GYMBADGE || getBadge <= 0)
		{
			printf("\n\nOoops, Lembre-se que o Badge do ingresso tem que ser menor que %d maior que 0! Tente Novamente!\n", EVENT_MAX_GYMBADGE);
		}			
	}while(getBadge > EVENT_MAX_GYMBADGE || getBadge <= 0);	
	
	
	aMap.erase(getBadge);
	
}

int getKey()
{
    double aNum = 0.698765420; // constante: 0 < A < 1
    double aValue = aTicket.ticketBadge * aNum;
    aValue = aValue - (int) aValue;
    return (int) (EVENT_MAX_SITS * aValue);
}

void showAboutMap()
{
	int aMapSize = aMap.size();
	
	printf("============================================================================");
	printf("\n\nBem vindo ao Relatório, abaixo estão as informações em tempo real do palco!");
	printf("\n\n============================================================================");	
				
	printf("\n\n============= Status Principais ================\n");	
	printf("\nA quantidade de cadeiras ocupadas é: %d", aMapSize);
	printf("\nA quantidade de cadeiras livres é..: %d", (EVENT_MAX_SITS - aMapSize));
	printf("\n\n================================================");	
		
}
void showAbout()
{	
		printf("========================================================================================================================");
		printf("\n\nProjeto Acadêmico visando simular a necessidade da Comic-Con, sem fins lucrativos, tendo em vista somente o aprendizado!");                                                                                                		
		printf("\n\nObrigado por ultilizar :D");
		printf("\n\n\t\t\t\t\t\t\t\t\t\tDesenvolvedores:");
		printf("\n\t\t\t\t\t\t\t\t\t\tErick Frederick (ericodesu) :D");
		printf("\n\t\t\t\t\t\t\t\t\t\tMaurício Augusto");	
		printf("\n\n========================================================================================================================");
		
}

bool isFull()
{

	if(aMap.size() == EVENT_MAX_SITS)
	{
		
		system("CLS");
				
		printf("========================================================================");
		printf("\n\nOops,os bancos estão ocupados espere volte mais tarde e tente novamente!");
		printf("\n\n========================================================================");
	
		printf("\n\n");
		system("PAUSE");		
				
		return true;
	}
	return false;
}

bool isEmpty()
{

	if(aMap.size() == 0)
	{		
		system("CLS");
	
		printf("========================================================================");
		printf("\n\nOops,os bancos estão vazios não tem como sair alguém se não tem ninguém!");
		printf("\n\n========================================================================");
						
		return true;
	}
	
	return false;
}
