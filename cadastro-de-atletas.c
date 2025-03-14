#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

int posicao(int);
int tamanho(FILE *);
int registro(FILE *);
void menu();
void imprime_linha();
void submenu();
void submenu2();
void submenuTimeA();
void submenuTimeB();
void visuTimeA();
void visuTimeB();
void visuAtletaA();

typedef struct{
	char nome[30];
	int idade;
	float altura;
}cad;

int main(){
	setlocale(LC_ALL, "Portuguese");	
		
	menu();
		
return 0;
}

void menu(){
	FILE *arq;
	int opc;
	
	system("cls");
	printf("CFC - CEFET FUTEBOL CLUBE\n\n");
	printf("1 - Criar times\n");
	printf("2 - Visualizar times\n");
	printf("3 - Finalizar\n\n");
	imprime_linha();
	printf("\nEscolha a operação desejada: ");
	scanf("%d", &opc);
	
	switch(opc){
		case 1: {
			submenu();
			break;
		}
		case 2:{
			submenu2();
			break;
		}
		case 3:{
			break;
		}
		
	default: printf("\nA opção digitada é inválida!\n\n");
	}
}

void menu2(){
	system("cls");
	printf("Deseja gravar os dados de que time?\n\n");
	printf("1 - Gravar time A\n");
	printf("2 - Gravar time B\n");
	printf("3 - Finalizar\n\n");
}

void submenu(){
	int opc2;
	
			menu2();
			imprime_linha();
			printf("\nEscolha a operação desejada: ");
			scanf("%d", &opc2);
			
				switch(opc2){
					case 1: {
							submenuTimeA();
							break;
							}
							
					case 2: {
							submenuTimeB();							
							break;
							}							
						
					case 3: {
							menu();
							break;
					}								
				}				
}

void submenu2(){
	int opc3;
	
	system("cls");
	printf("Qual time deseja visualizar?\n\n");
	printf("1 - Time A\n");
	printf("2 - Time B\n");
	printf("3 - Exibir um registro do Time A\n");
	printf("4 - Exibir um registro do Time B\n");
	printf("5 - Finalizar\n\n");
	imprime_linha();
	printf("\nEscolha a operação desejada: ");
	scanf("%d", &opc3);
	
		switch(opc3){
			case 1: {
				visuTimeA();
				break;
			}
							
			case 2: {
				visuTimeB();							
				break;
			}							
						
			case 3: {
				visuAtletaA();
				break;
			}	
			
			case 4: {
				visuAtletaB();
				break;
			}
			
			case 5: {
				menu();
				break;
			}							
		}		
}

void submenuTimeA(){
	FILE *arq;

	if( (arq = fopen("TimeA.txt", "w")) == NULL){
		puts("Erro na abertura do arquivo.");
		
		return 1;
	}
	
	cad atl;
	system("cls");
	printf("Digite ponto para finalizar o cadastramento: \n");
	
	while(1){
		printf("\n");
		imprime_linha();
		printf("\nNome do atleta: ");
		scanf("%s", &atl.nome);
		setbuf(stdin, NULL);
		
		if(!strcmp(atl.nome, ".")) 	break;
					
			printf("Idade do atleta: ");
			scanf("%d", &atl.idade);
			setbuf(stdin, NULL);
			
			printf("Altura do atleta: ");
			scanf("%f", &atl.altura);
			setbuf(stdin, NULL);
		
		fwrite(&atl, sizeof(cad), 1, arq);
	}
	
	
	fclose(arq);
	submenu();
}

void submenuTimeB(){
	FILE *arq;

	if( (arq = fopen("TimeB.txt", "w")) == NULL){
		puts("Erro na abertura do arquivo.");
		
		return 1;
	}
	
	cad atl;
	system("cls");
	printf("Digite ponto para finalizar o cadastramento: \n");
	
	while(1){
		printf("\n");
		imprime_linha();
		printf("\nNome do atleta: ");
		scanf("%s", &atl.nome);
		setbuf(stdin, NULL);
		
		if(!strcmp(atl.nome, ".")) 	break;
					
			printf("Idade do atleta: ");
			scanf("%d", &atl.idade);
			setbuf(stdin, NULL);
			
			printf("Altura do atleta: ");
			scanf("%f", &atl.altura);
			setbuf(stdin, NULL);
		
		fwrite(&atl, sizeof(cad), 1, arq);
	}
	
	
	fclose(arq);
	submenu();
}

void visuTimeA(){
	FILE *arq;

	if( (arq = fopen("TimeA.txt", "r")) == NULL){
		puts("Erro na abertura do arquivo.");
		
		return 1;
	}
	
	cad atl;
	system("cls");
	
	printf("Tamanho do arquivo: %d bytes\n", tamanho(arq));
	printf("Total de registros armazenados: %d bytes\n", registro(arq));
	
	int i, tam = 0;
	tam = registro(arq);
	
	imprime_linha();
	printf("Nome\t Idade\t Salário\n\n");
	
	for (i = 1; i <= tam; i++){
		fseek(arq, posicao(i), SEEK_SET);
		fread(&atl, sizeof(cad), 1, arq);
		
		printf("%s\t %d\t %.2f\n", atl.nome, atl.idade, atl.altura);
	}
		imprime_linha();
	fclose(arq);
	system("pause");
	submenu2();
}

void visuTimeB(){
	FILE *arq;

	if( (arq = fopen("TimeB.txt", "r")) == NULL){
		puts("Erro na abertura do arquivo.");
		
		return 1;
	}
	
	cad atl;
	system("cls");
	
	printf("Tamanho do arquivo: %d bytes\n", tamanho(arq));
	printf("Total de registros armazenados: %d bytes\n", registro(arq));
	
	int i, tam = 0;
	tam = registro(arq);
	
	imprime_linha();
	printf("Nome\t Idade\t Salário\n\n");
	
	for (i = 1; i <= tam; i++){
		fseek(arq, posicao(i), SEEK_SET);
		fread(&atl, sizeof(cad), 1, arq);
		
		printf("%s\t %d\t %.2f\n", atl.nome, atl.idade, atl.altura);
	}
		imprime_linha();
	fclose(arq);
	system("pause");
	submenu2();
}

void visuAtletaA(){
	FILE *arq;
	
	if( (arq = fopen("TimeA.txt", "r")) == NULL){
		puts("Erro na abertura do arquivo.");
		
		return 1;
	}
	
	cad atl;
	system("cls");
	
	printf("Tamanho do arquivo: %d bytes\n", tamanho(arq));
	printf("Total de registros armazenados: %d bytes\n", registro(arq));
	imprime_linha();
	int i, tam = 0;
	tam = registro(arq);
	
	printf("\nQual atleta você quer visualizar?: ");
	scanf("%d", &i);
	printf("\n");
	imprime_linha();
	printf("Nome\t Idade\t Salário\n\n");
	fseek(arq, posicao(i), SEEK_SET);
	fread(&atl, sizeof(cad), 1, arq);
	printf("%s\t %d\t %.2f\n", atl.nome, atl.idade, atl.altura);
	imprime_linha();
	
	fclose(arq);
	system("pause");
	submenu2();
}

void visuAtletaB(){
	FILE *arq;
	
	if( (arq = fopen("TimeB.txt", "r")) == NULL){
		puts("Erro na abertura do arquivo.");
		
		return 1;
	}
	
	cad atl;
	system("cls");
	
	printf("Tamanho do arquivo: %d bytes\n", tamanho(arq));
	printf("Total de registros armazenados: %d bytes\n", registro(arq));
	imprime_linha();
	int i, tam = 0;
	tam = registro(arq);
	
	printf("\nQual atleta você quer visualizar?: ");
	scanf("%d", &i);
	printf("\n");
	imprime_linha();
	printf("Nome\t Idade\t Salário\n\n");
	fseek(arq, posicao(i), SEEK_SET);
	fread(&atl, sizeof(cad), 1, arq);
	printf("%s\t %d\t %.2f\n", atl.nome, atl.idade, atl.altura);
	imprime_linha();
	
	fclose(arq);
	system("pause");
	submenu2();
}

int posicao(int pos){
	return (pos - 1) * sizeof(cad);
}

int tamanho(FILE *arq){
	int tam = 0;
	fseek(arq, 0, SEEK_END);
	tam = ftell(arq);
	return tam;
}

int registro(FILE *arq){
	return trunc(tamanho(arq) / sizeof(cad));
}

void menu3(){
	system("cls");
	printf("Qual time você deseja visualizar?\n");
	printf("1 - Time A\n");
	printf("2 - Time B\n");
	printf("3 - Exibe um registro do time A\n");
	printf("4 - Exibe um registro do time B\n");
	printf("5 - Finalizar\n\n");
}

void imprime_linha(){
	printf("--------\n");
}
