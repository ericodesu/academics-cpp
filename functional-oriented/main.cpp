#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define maxChoice 7 //Escolha máxima permitida
#define minPav 5 //Número mínimo de pavimentos
#define maxPav 327 //Número máximo de pavimentos
#define maxName 2 //Número máximo de digitos no nome
#define maxPsswdD 6 //Número máximo de dígitos na senha
#define maxPsswdTries 5 //Número de tentativas para inserir a senha

struct menu_p{ //Estrutura para o senhas do menu principal 
	char name_pvm[3]; //Vetor nome pavimento
	char psswd_a[12]; //Vetor setar senha
	char psswd_c[12]; //Vetor checar senha	
	bool psswd_a_ver; //Verificador da senha
	bool name_ver; //Irá confirmar se o nome foi inserido ou nao (Inicializar "false" porque só será usado uma vez)
	
};

int main(void){
	//Localização em Português
	setlocale(LC_ALL, "portuguese");
	
	//Vari�veis
	int choice = 0; //Número de escolhas modificada de int para char 
	int qntPvm = 0; //Quantidade de parvimentos
	int pvmReal = 0; //Pavimento que está sendo operado
	int menChoice; //Escolha para retorno para o Menu
	int triesPsswd; //Quantidade de tentativas senha
	int sizeName; //Tamanho de nome do pavimento
	int sizePsswd; //Tamanho da senha
	int errorN1; //Erro no switch case 2(Inserir o nome dos pavimentos)
	int valChoice; //Escolha se deseja retornar ou não
	int nameRegs = 0; //Quantidade de Nomes de pavimento resgistrados
	int psswdRegs = 0; //Quantidade se senhas de pavimento resgtrados
	bool MENU; //Opção para voltar ao menu
	bool pvmCheck = false; //Irá confirma que a quantidade de pavimentos foi inserido	
	bool nameCheck = false; //Irá confirmar se o nome foi inserido ou nao (Inicializar "false" porque só será usado uma vez)
	bool psswdCheck; //Irá confimar se as senhas foram inseridas
	bool valChoiceVer; //Verificação escolha se deseja retornar ou não
	
	
	struct menu_p menuPri[326]; //strcut com máximo de andres no dobro de [Burj Khalifa x 2]
	struct menu_p menuP;
	
	menuP.name_ver = false;
	menuP.psswd_a_ver = false;
	
	//Welcome text && Menu	
	do{	
		MENU:printf("-------------------- MENU -------------------- \n\n"); //"MENU:" Gambiarra  para erros quais são dificeis sair do Loop
		printf("Bem vindo ao menu!\n\nAqui estão as opções para operar o elevador!\nNesta tela touchscreen você deve escolher entre as opção disponíveis:");
		printf("\n\n[1]-Cadastrar quantidade de pavimentos do edifício\n[2]-Cadastrar os nomes dos pavimentos\n[3]-Cadastrar senha\n[4]-Validar senha\n[5]-Relatórios\n[6]-Finalizar\n[7]-Sobre");
		
		//Inserção escolha && repetição
		do{ 
			printf("\n\nPor favor digite a opção que deseja: ");
			scanf("%d", &choice);
			
			if(choice < 1 || choice > maxChoice){
				printf("Oops você inseriu a %d.º opção mas so têm de 1º a %d.º,tente novamente.",choice,maxChoice);
			}
		}while(choice < 1 || choice > maxChoice);
	
		//"Limpar" o display
		system("CLS");
		
		//Switch case com as opções do Menu
		switch (choice) {	
			case 1:	
				if(pvmCheck == true){
					printf("+++OOF.Você já inseriu o quantidade dos pavimentos se quer reinseri-los renicie o programa e tente novamente!+++");
					
					printf("\n");
					
					printf("\n\nDeseja fechar programa agora? \nInsira [0] para voltar ao menu [1] para fechar o programa: ");
					scanf("%d", &errorN1);
					
					if(errorN1 == 1){
						system("CLS");
						printf("==================================================================");
						printf("\n\t\t+++O programa irá finalizar :3+++\n\t\t     Obrigado por Ultilizar!\n");
						printf("==================================================================");			
						printf("\n\n");
						system("PAUSE");
						return 0;					
					}else{
							break;					

					}									
				}
				
				printf("\t\t*Você escolheu Cadrastar a quantidade de pavimentos!*\n\n");
				printf("+Lembre-se:O mínimo de pavimento aceitos até o momento é de %d!+",minPav);
				
				do{
					printf("\n\nPor favor lembre-se dos avisos acima e insira a quantidade de pavimentos: ");
					scanf("%d" ,&qntPvm);
					
					if(qntPvm < minPav){
						printf("OOF,lembre-se: O número mínimo de pavimentos até o momento é de %d andares.Tente novamente!",minPav);
					}else{
						if(qntPvm > maxPav){
							printf("OOF,lembre-se: O número máximo de pavimentos  até o momende é de %d andares.Tente novamente!",maxPav);
						}
					}
				}while(qntPvm < minPav || qntPvm > maxPav);
			
			pvmCheck = true;	

			break;		
			case 2:	
				nameRegs = 0;
				
				if(qntPvm == 0){
					printf("+++OOF.Por favor insira o valor da quantidade de pavimentos e tente novamente!+++");
					
					printf("\n");
										
					break;
				}
				
				if(nameCheck == true){
					printf("+++OOF.Você já inseriu o nome dos pavimentos se quer reinseri-los renicie o programa e tente novamente!+++");
					
					printf("\n");
					
					printf("\n\nDeseja fechar programa agora? \nInsira [0] para voltar ao menu [1] para fechar o programa: ");
					scanf("%d", &errorN1);
					
					if(errorN1 == 1){
						system("CLS");
						printf("==================================================================");
						printf("\n\t\t+++O programa irá finalizar :3+++\n\t\t     Obrigado por Ultilizar!\n");
						printf("==================================================================");			
						printf("\n\n");
						system("PAUSE");
						return 0;					
					}else{
							break;					

					}									
				}
				
				printf("\t\t*Você escolheu Cadrastar o nome dos pavimentos!*\n\n");
				printf("+Lembre-se:O máximo de dígitos no nome dos pavimentos aceitos até o momento é de %d!+\n",maxName);

				for (pvmReal = 1 ; pvmReal <= qntPvm; pvmReal++){
					
					do{
											
						printf("\nPor favor lembre-se dos avisos acima e insira o nome do pavimento %d: ",pvmReal);
						fflush(stdin);
						scanf("%s",&menuPri[pvmReal].name_pvm);
										
						sizeName = strlen(menuPri[pvmReal].name_pvm);
								
						if(sizeName > maxName){
							printf("\nOops! O nome inserido foi de %d caracteres por favor leia os avisos anteriores e tente novamente!\n",sizeName);
						
						}else{
						
							menuPri[pvmReal].name_ver = true;					 	
							nameRegs ++;
												
							break;
						}				
					}while(sizeName > maxName);					
					
				}
				
				
				nameCheck = true;
					
			break;		
			case 3:		
				psswdCheck = false;
				psswdRegs = 0;
				
				if(qntPvm == 0){
					printf("+++OOF.Por favor insira o valor da quantidade de pavimento e tente novamente!+++");
					
					printf("\n");
										
					break;
				}
				
				if(nameCheck == false){
					printf("+++OOF.Por favor insira os nomes dos pavimentos e tente novamente!+++");
					
					printf("\n");
										
					break;
				}
					
				printf("\t\t*Você escolheu Cadrastar a senha dos pavimentos!*\n\n");
				printf("+Lembre-se:O máximo de dígitos na senha dos pavimentos aceitos até o momento é de %d!+\n",maxPsswdD);
				printf("+Lembre-se:O pavimento '%s' não receberá senha,pois é o andar de saída!+\n",menuPri[1].name_pvm);
							
				for (pvmReal = 2 ; pvmReal <= qntPvm; pvmReal++){

					do{					
						
						printf("\nPor favor lembre-se dos avisos acima e insira a senha do pavimento %s: ",menuPri[pvmReal].name_pvm);
						fflush(stdin);
						scanf("%s",&menuPri[pvmReal].psswd_a);
												
						sizePsswd = strlen(menuPri[pvmReal].psswd_a);
								
						if(sizePsswd > maxPsswdD){
							printf("\nOops! A senha inserido foi de %d d�gitos por favor leia os avisos anteriores e tente novamente!\n",sizePsswd);
						
						}else
							if(sizePsswd < maxPsswdD){
												
								menuPri[pvmReal].psswd_a_ver = true;
								psswdRegs ++;
								
								break;
							}
					}while(sizePsswd > maxPsswdD);					
				}
				
				psswdCheck = true;

			break;		
			case 4:	
				if(qntPvm == 0){
					printf("+++OOF.Por favor insira o valor da quantidade de pavimento e tente novamente!+++");
					
					printf("\n");
										
					break;
				}

				if(nameCheck == false){
					printf("+++OOF.Por favor insira os nomes dos pavimentos e tente novamente!+++");
					
					printf("\n");
										
					break;
				}			
				
				if(psswdCheck == false){
					printf("+++OOF.Por favor insira as senhas nos pavimentos e tente novamente!+++");
					
					printf("\n");
										
					break;			
				}
				

				printf("\t\t*Você escolheu Validar a senha dos pavimentos!*\n\n");
				printf("+Lembre-se:O máximo de dígitos na senha dos pavimentos aceitos até o momento é de %d!+\n",maxPsswdD);
				printf("+Lembre-se:O máximo de tentativas erradas ao inserir a senha aceitos até o momento é %d!+\n",maxPsswdTries);
				
				for (pvmReal = 2 ; pvmReal <= qntPvm; pvmReal++){
				
					triesPsswd = 0;
					
					do{
							
						do{
							fflush(stdin);						
							printf("\nPor favor lembre-se dos avisos acima e insira a senha do pavimento '%s': ",menuPri[pvmReal].name_pvm);
							fflush(stdin);
							scanf("%s",&menuPri[pvmReal].psswd_c);
																
							sizePsswd = strlen(menuPri[pvmReal].psswd_c);
									
							if(sizePsswd > maxPsswdD){
								printf("\nOops! A senha inserido foi de %d dígitos por favor leia os avisos anteriores e tente novamente!\n",sizePsswd);
							
							}else{
								
								break;
							}
											
						}while(sizePsswd > maxPsswdD);	
						
						if(pvmReal > qntPvm){
							break;
						}		
						
						if(strcmp(menuPri[pvmReal].psswd_c,menuPri[pvmReal].psswd_a)==0){
							printf("\nSenha do pavimento %s está correta!",menuPri[pvmReal].name_pvm);
							printf("\n\nVocê deseja inserir subir para outro pavimento?\nInsira [0] se Não e voltar ao Menu ou [1] para Sim validar outro pavimento: ",menuPri[pvmReal+1].name_pvm);
							scanf("%d" ,&valChoice);
							
							if(valChoice == 0){
								
								valChoiceVer = true;
								
								break;
									
							}else{
								if(valChoice == 1){
						
									break;								
								}						
							}
							}else{
							printf("Senha incorreta tente novamente! D:\n\nVocê tem %d tentativas restantes!",maxPsswdTries - triesPsswd);	
							
							triesPsswd ++;
							}
						
							if(triesPsswd > maxPsswdTries){
								printf("\nVocê atingiu %d tentativas,você será redirecionado ao Menu! D:",maxPsswdTries);
								printf("\n\n");
								system("PAUSE");
								system("CLS");	
								goto MENU;
							}
					}while(strcmp != 0);
						
					if(valChoiceVer == true){
						
						break;
					}
					
					
					
				}
					
			break;		
			case 5:		
				if(qntPvm == 0){
					printf("+++OOF.Por favor insira o valor da quantidade de pavimentos e tente novamente!+++");
					
					printf("\n");
										
					break;
				}
				
				printf("\nRelatórios sobre os %d pavimentos:",qntPvm);
				printf("\n+Lembre-se:O pavimento de saída nao possui senha!+");
				printf("\n\nSão %d Pavimento(s) com nome(s) registrado(s) e %d sem!",nameRegs,qntPvm - nameRegs);
				printf("\nSão %d Pavimento(s) com senha(s) registrada(s) e %d sem!",psswdRegs,(qntPvm - 1)-psswdRegs);
				printf("\n\n===================================================");
				
				if(menuPri[1].name_ver == true){
					printf("\n\nO pavimento de saída está registrado como '%s'!",menuPri[1].name_pvm);
				}else{
					if(menuPri[1].name_ver == false){
						printf("\n\nO pavimento de saída não tem nome registrado!");
					}
				}		
				
				for (pvmReal = 2 ; pvmReal <= qntPvm; pvmReal ++){
				
					if(menuPri[pvmReal].name_ver == true){
						printf("\n\nO pavimento %dº está registrado como '%s'!",pvmReal,menuPri[pvmReal].name_pvm);
					}else{
						if(menuPri[pvmReal].name_ver == false){
							printf("\n\nO %dº pavimento não tem nome registrado!",pvmReal);
						}
					}
					
					if(menuPri[pvmReal].psswd_a_ver == true){
						printf("\nO pavimento %s está com a senha resigtrada:'%s'!",menuPri[pvmReal].name_pvm,menuPri[pvmReal].psswd_a);
					}else{
						if(menuPri[pvmReal].psswd_a_ver == false){
							printf("\nO %d.º pavimento não tem senha registrada!",pvmReal);	
						}
					}
				}
				
				printf("\n\n===================================================");
			break;
			case 6:				
				system("CLS");
				printf("==================================================================");
				printf("\n\t\t+++O programa irá finalizar :3+++\n\t\t     Obrigado por Ultilizar!\n");
				printf("==================================================================");			
				printf("\n\n");
				system("PAUSE");
				return 0;
			break;		
			case 7:
				system("CLS");
				
				printf("Protótipo de disitivo que ajudará no uso de elevadores!\n\nEmpresa cliente é a ThyssenKrupp qual acredita que a tecnologia da Informação e dinâmica, por isso, veem com bons olhos incrementos ao projeto, desde que agreguem valor.\n\nEste protótipo visa garantir mais segurança aos seus usuários!");                                                                                                		
				printf("\n\nObrigado por ultilizar :D");
				printf("\n\n\t\t\t\t\t\t\t\t\t\tDesenvolvedor:");
				printf("\n\t\t\t\t\t\t\t\t\t\tErick Frederick (ericodesu) :D");
				
			break;
			
			default : printf("OOF");
			
		}
			
		//Opções para volta ou avanço de Menu's
		printf("\n\nInsira [1] (Número Um) para voltar ao menu.\n");
			
		do{		
			printf("Insira: ");		
			scanf("%d", &menChoice);
			
			if(menChoice != 1){
				printf("Por favor insira [1] (Número Um) e tente novamente.\n\n");
			}
			
		}while(menChoice != 1);
			
		system("CLS");
		
		MENU = true;
			
	}while(MENU == true); //Loop do Menu (do while)		
	
	printf("\n\n");
	system("PAUSE");
	return 0;
}
