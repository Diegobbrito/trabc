/*Trabalho Final da disciplina de Linguagem de Programação*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define arquivoPacientes "pacientes.dat"
#define arquivoMedico "medico.dat"
#define arquivoConsulta "consulta.dat"
#define arqLista

//Define q data com os seguintes parâmetros
typedef struct
{
	int dia;
	int mes;
	int ano;

}dt;

//Define atributos do paciente
typedef struct
{
    int codigo;
	char nome[30];
    char endereco[50];
	char cpf[15];
    char telefone[15];
}paciente;

//Define atributos do médico
typedef struct
{
    int codigo;
	char nome[30];
	char especialidade[30];
    char crm[6];
}medico;

typedef struct
{
	int codigo;
	char nome_paciente[30];
	char cpf[15];
	char crm[6];
	char nome[50];
	char especialidade[30];
	char data[11];
}consulta;

void cadastraPaciente(void);
void cadastraMedico(void);
void consultaPacientes (void);
void consultaPacienteNome(void);
void consultaPacienteCPF(void);
void consultaMedicos(void);
void consultaMedicoCodigo(void);
void consultaMedicoNome(void);
void cadastraConsulta(void);
void mostrarConsulta(void);
void mascara(char *frase, char *formato);

int main(){
    int op;
	do {
		system ("cls");
		printf("\n\n\t-------------------------------\n");
		printf("\t   Escolha uma das opcoes      \n");
		printf("\t-------------------------------\n");
		printf("\n\t1- Cadastrar Pacientes\n");
		printf("\n\t2- Cadastrar Medicos\n");
		printf("\n\t3- Mostrar todos os Pacientes Cadastrados\n");
        printf("\n\t4- Consultar Pacientes por Nome\n");
		printf("\n\t5- Consultar Pacientes por CPF\n");
		printf("\n\t6- Mostrar todos os Medicos Cadastrados\n");
		printf("\n\t7- Consultar Medicos por Codigos\n");
		printf("\n\t8- Consultar Medicos por Nome\n");
		printf("\n\t9- Cadastras Consultas\n");
		printf("\n\t10- Ver todas as Consultas\n");
		printf("\n\t0- Sair do programa\n\n");
		printf("\tEscolha uma Opcao: ");
		scanf("%d", &op);
		switch(op){
		    case 1:
			        system ("cls");
					cadastraPaciente();
		         break;
		    case 2:
					system ("cls");
					cadastraMedico();
		         break;
		    case 3:
					system ("cls");
					consultaPacientes();
		         break;
		    case 4:
			        system ("cls");
					consultaPacienteNome();
		         break;
		    case 5:
			        system ("cls");
					consultaPacienteCPF();
		         break;
		    case 6:
			        system ("cls");
					consultaMedicos();
		         break;
		    case 7:
			        system ("cls");
					consultaMedicoCodigo();
		         break;
		    case 8:
			        system ("cls");
					consultaMedicoNome();
		         break;
		    case 9:
		    		system ("cls");
		    		cadastraConsulta();
		    	break;
		    case 10:
		    		system ("cls");
		    		mostrarConsulta();
		    	break;
		    case 0:
					system ("cls");
			     break;
			default:
			        printf("\n\tOpcao invalida!\n\n");
			        system("pause");
                    break;
        }
	}while(op != 0);
	return 0;
}

void cadastraPaciente(void)
{

FILE *arq;
	paciente x;
    char aux[15];
    char cpf[15];
    char formatoCPF[] = "###.###.###-##";
    int i=0,j=0;
    int a = 0, num=0, terminou;
    do{
    	printf("\n\n\t-----------------------------");
        printf("\n\t  Cadastro de Novo Paciente");
        printf("\n\t-----------------------------");
    	if ((arq = fopen(arquivoPacientes, "a+b")) == NULL) {
		printf("erro");
		}
		else{
            do{
		   			fseek(arq, 0, SEEK_SET);
		   			terminou = 0;
		   			a=0;
		   			i=0;
		   			printf("\n\nCPF: ");
		   			fflush(stdin);
		   			//gets(cpf);
		   			while(terminou == 0){
		   				fflush(stdin);
		   				cpf[i] = getch();
		   				printf("%c", cpf[i]);
						if((int)cpf[i] < 48 || (int)cpf[i] > 57){
							printf("\n\n\tSomente e permitido digitar numeros de 0 a 9 e o CPF deve ter 11 digitos. Digite o CPF novamente.");
							printf("\n\nCPF: ");
							i = 0;
							terminou = 0;
						}
						else{
							i++;
						}
						if (i == 11){
							terminou = 1;
						}	
					}
					mascara(cpf, "###.###.###-##");
		   			while(fread(&x, sizeof(paciente), 1, arq) > 0) {
						if(strncmp(cpf,x.cpf, strlen(cpf)) == 0){
				  			a=a+1;
		    			}
	       			}
		   			if(a > 0){
			  			printf("\n\n\tJa existe um paciente cadastrado com esse CPF: %s. Digite novamente:",cpf);
		   			}
		   			else{
		   				fseek(arq, 0, SEEK_END);
						x.codigo= ftell(arq) / sizeof(paciente) + 1;
						printf("\n\nCodigo do Paciente: %d\n", x.codigo);
	        			strcpy(x.cpf,cpf);

						printf("\nNome: ");
						fflush(stdin);
						gets(x.nome);
	
						printf("\nEndereco: ");
						fflush(stdin);
						gets(x.endereco);
	
						printf("\nTelefone: ");
						fflush(stdin);
						terminou = 0;
						i = 0;
						while(terminou == 0){
		   					x.telefone[i] = getch();
		   					printf("%c", x.telefone[i]);
								if((int)x.telefone[i] < 48 || (int)x.telefone[i] > 57){
									printf("\n\n\tSomente e permitido digitar numeros de 0 a 9 e o Telefone deve ter 2 Digitos de DDD e 9 referentes ao Telefone. Digite novamente.");
									printf("\n\nTelefone: ");
									i = 0;
								}
								else{
									i++;
								}
								if (i == 11){
									terminou = 1;
								}	
						}
						//gets(x.telefone);
						mascara(x.telefone, "(##)#####-####");
						//gets(aux);
				        //x.telefone=atoi(aux);

						fwrite(&x, sizeof(paciente), 1, arq);
					    system("cls");
					    printf("\n\n\tPaciente Cadastrado Com Sucesso!\n\n");
					    fclose(arq);
				
			    	    printf("\n\tDeseja Cadastrar outro Paciente ?\n\n\t1 - Sim\n\n\t2 - Nao\n\n ");
 					    scanf("%d", &num);
						while(num < 1 || num > 2){
						  	system ("cls");
						  	printf("\n\tOpcao Invalida!!\n\n");
			                printf("\n\tDeseja Cadastrar outro Paciente ?\n\n");
			                printf("\n\tDigite novamente:\n\n\n\t\t1 - Sim\n\n\t\t2 - Nao\n");
			  		        scanf("%d", &num);
							system("cls");
						}
		   			} 					
		   	}while(a > 0);
		}
	}while(num==1);
}

void cadastraMedico(void)
{
	FILE * arq;
	medico x;
	char crm[6];
	int num=0, esp;
	int i=0,j=0;
    int a = 0, terminou;
    
	do{
		system("cls");	
		printf("\n\n\t-----------------------------");
        printf("\n\t   Cadastro de Novo Medico");
        printf("\n\t-----------------------------\n");
		printf("\nCRM: ");
		
		if ((arq = fopen(arquivoMedico, "a+b")) == NULL) {
			fprintf(stderr, "\n\tImpossivel abrir o arquivo %s!\n", arquivoMedico);
		}
		else
		{
			do{
				fseek(arq, 0, SEEK_SET);
				terminou = 0;
		   		a=0;
		   		i=0;
		   		fflush(stdin);
		   		for(i=0; i<5; i++){
		   			fflush(stdin);
		   			crm[i] = getch();
		   			printf("%c", crm[i]);
					if((int)crm[i] < 48 || (int)crm[i] > 57){
						printf("\n\n\tSomente e permitido digitar numeros de 0 a 9 e o CRM deve ter 5 digitos. Digite o CRM novamente.");
						printf("\n\nCRM: ");
						i = 0;
					}
				}
				while(fread(&x, sizeof(medico), 1, arq) > 0) {
					if(strncmp(crm,x.crm, strlen(crm)) == 0){
						a=a+1;
		    		}
				}
				if(a > 0){
					printf("\n\n\tJa existe um paciente cadastrado com esse CRM: %s. Digite novamente:",crm);
					printf("\n\nCRM: ");
				}
				else{
					strcpy(x.crm, crm);
					fseek(arq, 0, SEEK_END);
					x.codigo = ftell(arq) / sizeof(medico) + 1;
					printf("\n\nCodigo: %d\n", x.codigo);
				    do{printf("\nNome: ");
			    	   	fflush(stdin);
					   	gets(x.nome);
			    	}while(x.nome[0] == '\0');

					//Cadastra a Especialidade dentre as 4 opcoes, fazendo validação das 4 disponiveis
					printf("\nEspecialidade:\n");
					printf("1- Cardiologista\n");
					printf("2- Otorrino\n");
					printf("3- Pediatra\n");
					printf("4- Ginecologista\n");
					scanf("%d", &esp);
					while(esp != 1 && esp != 2 && esp !=3 && esp != 4){
						printf("Opcao Invalida\n");
						printf("\nEspecialidades disponiveis: \n");
						printf("1- Cardiologista\n");
						printf("2- Otorrino\n");
						printf("3- Pediatra\n");
						printf("4- Ginecologista\n");
						scanf("%d", &esp);
	    		   	}	
					if(esp == 1){
        		    strcpy(x.especialidade, "Cardiologista");
					}
					else if(esp == 2){
        		    strcpy(x.especialidade, "Otorrino");
					}
					else if(esp == 3){
        		    strcpy(x.especialidade, "Pediatra");
					}
					else{
        		    strcpy(x.especialidade, "Ginecologista");
					}
					fwrite(&x, sizeof(medico), 1, arq);
					system("cls");
					printf("\n\n\tMedico Cadastrado Com Sucesso!\n\n");
					fclose(arq);
	
					printf("\n\tDeseja Cadastrar outro Medico ?\n\n\t1- Sim\n\n\t2- Nao\n\n ");
					scanf("%d", &num);
					while(num < 0 || num > 2){
		  		  	    system ("cls");
						printf("\n\tOpcao Invalida!!\n\n\tDigite novamente:\n\n\t\t1-Sim\n\n\t\t2- Nao\n");
			        	scanf("%d", &num);
	           		}
	       		}
		    }while(a > 0);
		}
	}while(num==1);
}

void consultaPacientes (void)
{
system("cls");

FILE * arq;
FILE * arq2;
int num=0;

paciente c;

	if ((arq = fopen(arquivoPacientes, "rb")) == NULL) {
		fprintf(stderr, "\n\tNao existe nenhum paciente cadastrado!\n\n\n");
		printf("\n\ns");
        system("pause");
		return;
	}

	if((arq2 = fopen(arqLista"TodosPacientes.txt", "w")) == NULL) {
		fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n", arqLista"TodosPacientes.txt");
        printf("\n\n");
		system("pause");
		return;
	}
	printf("\n\n\t\t                                         -------------------------");
	printf("\n\t\t                                           Pacientes Cadastrados   \n");
	printf("\t\t                                         -------------------------");
	printf("\n============================================================================================================================================\n");
	printf("Cod. Nome  |  Nome                            |  Endereco                                            |  CPF              |  Tel.            \n");
	printf("============================================================================================================================================\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
	
	while (fread(&c, sizeof(paciente), 1, arq) > 0) {
     
		printf("%09d  |  %-30s  |  %-50s  |  %-15s  |  %-15s  \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone);
		printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
	}
	fseek(arq,0,SEEK_SET);
	printf("\n\n\tDeseja gerar um relatorio ?\n\n\tDigite:\n\n\t1- Sim\n\n\t2- Nao\n\n\t");
    scanf("%d", &num);
    while(num<1||num>2){
	  	system ("cls");
	    printf("\n\tOpcao Invalida!!!");
        printf("\n\n\tDeseja gerar um relatorio ?\n\n\tDigite novamente:\n\n\t\t 1- Sim \n\t\t 2- Nao\n ");
        scanf("%d", &num);
    }
    if(num==1){
	fprintf(arq2, "\n\n\t\t                                         -------------------------");
	fprintf(arq2, "\n\t\t                                           Pacientes Cadastrados   \n");
	fprintf(arq2, "\t\t                                         -------------------------");
	fprintf(arq2, "\n============================================================================================================================================\n");
	fprintf(arq2,"Cod. Nome  |  Nome                            |  Endereco                                            |  CPF              |  Tel.            \n");
	fprintf(arq2,"============================================================================================================================================\n");
	fprintf(arq2,"--------------------------------------------------------------------------------------------------------------------------------------------\n");
      	while (fread(&c, sizeof(paciente), 1, arq) > 0) {
            fprintf(arq2,"%09d  |  %-30s  |  %-50s  |  %-15s  |  %-15s  \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone);
        	fprintf(arq2,"--------------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        system ("cls");
		printf("\n\n\tRelatorio gerado com sucesso!\n\n");
   }
   else if(num==2){
		   system ("cls");
		  	return;
   }
    system("pause");
    system("cls");
    fclose(arq);
    fclose(arq2);
}


void consultaPacienteNome(void){
	system("cls");

	FILE * arq;
	FILE * arq2;

	paciente c;
	int num=0,num2=0;
	char nome[50];
	int achei = 0;
	int i=0,j=0, novamente=0;

	if ((arq = fopen(arquivoPacientes, "rb")) == NULL) {
		fprintf(stderr, "\n\tNao existe nenhum paciente cadastrado!\n");
		printf("\n\n");
		system("pause");
        return;
	}
	if((arq2 = fopen(arqLista"PesquisaPacienteNome.txt", "w")) == NULL) {
		fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n", arqLista"PesquisaPacienteNome.txt");
		printf("\n\n");
        system("pause");
        return;
	}		

    do{
		system ("cls");
		printf("\n\n\t-----------------------------------");
   	    printf("\n\t   Pesquisa de Pacientes por Nome");
   	    printf("\n\t-----------------------------------\n");
    	fseek(arq,0,SEEK_SET);
    	achei = 0;
		printf("\nNome do Paciente: ");
		fflush(stdin);
		gets(nome);
		while(strlen(nome) == 0){
			printf("\nDigite um nome para pesquisa: ");
			fflush(stdin);
			gets(nome);
		}
		rewind(arq);
		while(fread(&c, sizeof(paciente), 1, arq) > 0)
       	{
			for(i=0;i< (strlen(nome));i++)
       		{
		  		nome[i]=toupper(nome[i]);
		  		c.nome[i]=toupper(c.nome[i]);	
			}
		  	if(strncmp(nome,c.nome, strlen(nome)) == 0)
       	  	{
       	  		if (achei == 0){
       				system ("cls");
       				printf("\n\n\t\t                       ---------------------------------------------------------------");
					printf("\n\t\t                                Pacientes Cadastrados com o Nome: %s  \n", nome);
					printf("\t\t                       ---------------------------------------------------------------");
					printf("\n============================================================================================================================================\n");
					printf("Cod. Nome  |  Nome                            |  Endereco                                            |  CPF              |  Tel.            \n");
					printf("============================================================================================================================================\n");			
				}
       			printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
       	    	printf("%09d  |  %-30s  |  %-50s  |  %-15s  |  %-15s  \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone);
       			printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
				achei = 1;
		  	}
		}
	    if (!achei){
			printf("\n\tNao existem pacientes com esse nome.");
		}
		else{
			fseek(arq,0,SEEK_SET);
			printf("\n\n\tDeseja Gerar Um Relatorio ?\n\n\tDigite:\n\n\t1- Sim\n\n\t2- Nao\n\n\t");
			scanf("%d", &num);
			while(num<1||num>2)
			{
   			   	system ("cls");
				printf("\n\tOpcao Invalida!!!\n\n");
   			   	printf("\tDeseja Gerar Um Relatorio ?\n\n");
   			   	printf("\tDigite novamente:\n\n\t\t 1- Sim \n\t\t 2- Nao\n");
				scanf("%d", &num);
   			}
			if(num==1){
				fprintf(arq2,"\n\n\t\t                       ---------------------------------------------------------------");
				fprintf(arq2,"\n\t\t                                Pacientes Cadastrados com o Nome: %s  \n", nome);
				fprintf(arq2,"\t\t                       ---------------------------------------------------------------");
			    fprintf(arq2,"\n============================================================================================================================================\n");
			    fprintf(arq2,"Cod. Nome  |  Nome                            |  Endereco                                            |  CPF              |  Tel.            \n");
			    fprintf(arq2,"============================================================================================================================================\n");
		
				while(fread(&c, sizeof(paciente), 1, arq) > 0)
		        {
					for(i=0;i< (strlen(nome));i++)
		            {
					  	nome[i]=toupper(nome[i]);
						for(j=0;j<(strlen(c.nome));j++)
		                {
					  		c.nome[j]=toupper(c.nome[j]);
					  	}
				    }
					if(strncmp(nome,c.nome, strlen(nome)) == 0)
		            {
		            	fprintf(arq2, "--------------------------------------------------------------------------------------------------------------------------------------------\n");
						fprintf(arq2,"%09d  |  %-30s  |  %-50s  |  %-15s  |  %-15s  \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone);
	    	            fprintf(arq2,"--------------------------------------------------------------------------------------------------------------------------------------------\n");
						achei = 1;
					}
				}
				printf("\n\tRelatorio gerado com sucesso!\n\n");
   				printf("\n");				
			}
		}
		printf("\n\tDeseja Realizar Outra Pesquisa ?\n\n\t1- Sim\n\n\t2- Nao\n\n\t");
		scanf("%d", &num2);
		while(num2 < 1 || num2 > 2)
		{
			system ("cls");
		    printf("\n\tOpcao Invalida!!!\n\n");
   		    printf("\tDeseja Realizar Outra Pesquisa ?\n\n");
   		    printf("\tDigite novamente:\n\n\t\t 1-Sim \n\t\t 2- Nao).\n");
   			scanf("%d", &num2);
		}
	}while(num2==1);
	fclose(arq);
	fclose(arq2);
}
				
			

void consultaPacienteCPF(void){
system("cls");

FILE * arq;
FILE * arq2;

paciente c;
int num=0,num2=0;
char cpf[15];
int achei = 0;
int i=0,j=0;

	do{
		if ((arq = fopen(arquivoPacientes, "rb")) == NULL)
        {
			fprintf(stderr, "\n\tErro: Nao existe nenhum paciente cadastrado!\n");
		    printf("\n\n");
        	system("pause");
            return;
		}
		if((arq2 = fopen(arqLista"PesquisaPacienteCPF.txt", "w")) == NULL)
        {
			fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n", arqLista"PesquisaPacienteCPF.txt");
			printf("\n\n");
            system("pause");
    		return;
		}
		printf("\n\n\t   Consultar Paciente por cpf    \n\n");
	 do{
			printf("\tCPF do Paciente: ");
			fflush(stdin);
			gets(cpf);
		    printf("\n\n");

			rewind(arq);

			printf("\n\n\t\tPaciente com esse cpf: %s\n\n",cpf);
	        printf("==========================================================================\n");
	        printf("Cod. Nome\tEndereco\tCpf\t   tel.\t    \n");
	        printf("==========================================================================\n\n");
	        printf("--------------------------------------------------------------------------\n");

			while(fread(&c, sizeof(paciente), 1, arq) > 0)
            {
			  for(i=0;i< (strlen(cpf));i++)
              {
			  	cpf[i]=toupper(cpf[i]);
				  for(j=0;j<(strlen(c.cpf));j++)
                  {
			  		c.cpf[j]=toupper(c.cpf[j]);
			  	  }
			  }
			  if(strncmp(cpf,c.cpf, strlen(cpf)) == 0)
              {
                printf("%04d %-10s %-15s %-10s %-10d \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone);
                printf("--------------------------------------------------------------------------\n");
				achei = 1;
 			  }
			}
	        printf("==========================================================================\n");

		    if (!achei){
			  printf("\n\n\tNao existe paciente cadastrado com  esse CPF: %s\n\n",cpf);
			  printf("\n\tDigite Novamente !\n\n");
			}

		}while(!achei);

		fseek(arq,0,SEEK_SET);

	    printf("\n\n\tDeseja Gerar Um Relatorio ?\n\n\tDigite:\n\n\t1- Sim\n\n\t2- Nao\n\n\t ");
		scanf("%d", &num);
		while(num<1||num>2)
        {
           	system ("cls");
			printf("\n\tOpcao Invalida!!!\n\n");
            printf("\tDeseja Gerar Um Relatorio ?\n\n");
            printf("\tDigite novamente:\n\n\t\t 1- Sim\n\n\t\t 2- Nao\n");
		    scanf("%d", &num);
        }
		if(num==1)
        {
			   fprintf(arq2,"\n\n\t\t\t\t\tPaciente com esse CPF: %s\n\n",cpf);
	           fprintf(arq2,"================================================================================\n");
	           fprintf(arq2,"Cod. Nome\tEndereco\tCpf\t   tel.\t    \n");
	           fprintf(arq2,"================================================================================\n\n");
	           fprintf(arq2,"--------------------------------------------------------------------------------\n");
			while(fread(&c, sizeof(paciente), 1, arq) > 0)
            {
			  for(i=0;i< (strlen(cpf));i++)
              {
			  	cpf[i]=toupper(cpf[i]);
			    for(j=0;j<(strlen(c.cpf));j++)
                {
			  		c.cpf[j]=toupper(c.cpf[j]);
			  	}
			  }
			  if(strncmp(cpf,c.cpf, strlen(cpf)) == 0)
              {
 			    fprintf(arq2," %04d %-20s %-20s %-15s %-12d  \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone);
	            fprintf(arq2,"--------------------------------------------------------------------------------\n");
				achei = 1;
			  }
			}
            fprintf(arq2,"================================================================================\n\n");
		 	system ("cls");
			printf("\n\n\tRelatorio gerado com sucesso!!\n\n");
			system("pause");
		}
	    system("cls");
	    fclose(arq);
	    fclose(arq2);

		printf("\n\tDeseja Realizar Outra Pesquisa ?\n\n\t1- Sim\n\n\t2- Nao\n\n ");
		scanf("%d", &num2);
		while(num2 < 0 || num2 > 2)
        {
			system ("cls");
			printf("\n\tOpcao Invalida!!!\n\n\tDigite novamente:\n\n\t\t 1-Sim \n\t\t 2- Nao).\n");
		    scanf("%d", &num2);
		}
  		system("cls");
	}while(num2==1);
}

void consultaMedicos (void){

system("cls");

FILE * arq;
FILE * arq2;
int num=0;

medico c;

	if ((arq = fopen(arquivoMedico, "rb")) == NULL) {
		fprintf(stderr, "\n\tErro: Nao existe nenhum Medico cadastrado!\n\n\n");
		printf("\n\n");
        system("pause");
		return;
	}
	if((arq2 = fopen(arqLista"TodosMedicos.txt", "w")) == NULL) {
		fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n", arqLista"TodosMedicos.txt");
		printf("\n\n");
        system("pause");
		return;
	}
	printf("\n\n\t\t\t\tMedicos cadastrados\n\n");
	printf("=========================================================================\n");
	printf(" Cod.: Nome:                      Especialidade:    CRM:  \n");
	printf("=========================================================================\n\n");
	printf("-------------------------------------------------------------------------\n");
	while (fread(&c, sizeof(medico), 1, arq) > 0) {
	 printf(" %04d %-30s %-10s %-10s     \n",c.codigo, c.nome, c.especialidade, c.crm);
	 printf("-------------------------------------------------------------------------\n");
	}
	printf("\n=========================================================================\n\n");

	fseek(arq,0,SEEK_SET);

    printf("\n\n\tDeseja Gerar Um Relatorio ?\n\n\tDigite:\n\n\t1- Sim\n\n\t2- Nao\n\n\t");
	scanf("%d", &num);
	while(num<1||num>2)
    {
	  	system ("cls");
	  	printf("\n\tNumero Invalido!!!\n\n\tDigite novamente");
	  	scanf("%d", &num);
	}
	if(num==1){

			fprintf(arq2,"\n\n\t\t\t\tMedicos cadastrados\n\n");
			fprintf(arq2,"=========================================================================\n");
			fprintf(arq2," Cod.: Nome:                       Especialidade:    CRM:    \n");
			fprintf(arq2,"=========================================================================\n\n");
			fprintf(arq2,"-------------------------------------------------------------------------\n");
			while(fread(&c, sizeof(medico), 1, arq) > 0) {
			  fprintf(arq2," %04d %-30s %-10s %-10s   \n",c.codigo, c.nome,c.especialidade, c.crm);
	 		  fprintf(arq2,"-------------------------------------------------------------------------\n");
	        }
			 fprintf(arq2,"\n=========================================================================\n\n");
		     system ("cls");
			 printf("\n\n\tRelatorio gerado com sucesso!!\n\n");

		}else{
		   system ("cls");
		  	return;
		}


    system("pause");
	system ("cls");
    fclose(arq);
    fclose(arq2);
}

void consultaMedicoCodigo(void){

	FILE * arq;
	FILE * arq2;
	medico c;
	int codigo,num=0,num2=0;

	int achei = 0;
	int i=0,j=0;


	do{

		if ((arq = fopen(arquivoMedico, "rb")) == NULL) {
			fprintf(stderr, "\n\tErro: Nao existe nenhum Medico cadastrado!\n");
      		printf("\n\n");
            system("pause");
			return;
		}

		if((arq2 = fopen(arqLista"PesquisaMedicoCodigo.txt", "w")) == NULL) {
			fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n",arqLista"PesquisaMedicoCodigo.txt");
            printf("\n\n");
			system("pause");
    		return;
		}

	 do{
			printf("\tCodigo do Medico: ");
			fflush(stdin);
			scanf("%d", &codigo);
		    printf("\n\n");

			rewind(arq);

			printf("\n\n\t\t\t\tMedico cadastrado com o codigo: %d\n\n",codigo);
			printf("=========================================================================\n");
			printf(" Cod.: Nome:                       Especialidade:    CRM:  \n");
			printf("=========================================================================\n\n");
			printf("-------------------------------------------------------------------------\n");
			while(fread(&c, sizeof(medico), 1, arq) > 0) {

				if( codigo == c.codigo){
		 			printf(" %04d %-30s %-10s %-10d   \n",c.codigo, c.nome, c.especialidade, c.crm);
					printf("-------------------------------------------------------------------------\n");

						 achei = 1;
				}
			}
			printf("\n=========================================================================\n\n");

		    if (!achei){

			  system ("cls");
			  printf("\n\n\tNao existe Medicos cadastrados com esse nome: %d\n\n",codigo);
			  printf("\n\tDigite Novamente !\n\n");

			}

		}while(!achei);

		fseek(arq,0,SEEK_SET);

		printf("\n\n\tDeseja Gerar Um Relatorio ?\n\n\tDigite:\n\n\t1- Sim\n\n\t2- Nao\n\n\t ");
		scanf("%d", &num);
		while(num<1||num>2)
        {
			system ("cls");
			printf("\n\tOpcao Invalida!!!\n\n\tDigite novamente:\n\n\t\t 1- Sim \n\t\t 2- Nao\n");
       		scanf("%d", &num);
		}
		if(num==1)
        {
				fprintf(arq2,"\n\n\t\t\t\tMedico cadastrado com o codigo: %d\n\n",codigo);
				fprintf(arq2,"=========================================================================\n");
				fprintf(arq2," Cod.: Nome:                       Especialidade:    CRM:  \n");
				fprintf(arq2,"=========================================================================\n\n");
				fprintf(arq2,"-------------------------------------------------------------------------\n");
			    while(fread(&c, sizeof(medico), 1, arq) > 0)
                {
					if( codigo == c.codigo){
		 			fprintf(arq2," %04d %-30s %-10s %-10d   \n",c.codigo, c.nome, c.especialidade, c.crm);
					fprintf(arq2,"-------------------------------------------------------------------------\n");
 				    achei = 1;
	       			}
			   }
			fprintf(arq2,"\n=========================================================================\n\n");
			system ("cls");
			printf("\n\n\tRelatorio gerado com sucesso!!\n\n");
			system("pause");
      	}
	    system("cls");
	    fclose(arq);
	    fclose(arq2);

		printf("\n\tDeseja Realizar Outra Pesquisa ?\n\n\t1- Sim\n\n\t2- Nao\n\n ");
		scanf("%d", &num2);
		while(num2 < 0 || num2 > 2)
        {
			system ("cls");
			printf("\n\tOpcao Invalida!!!\n\n\tDeseja Realizar Outra Pesquisa ?\n\n\tDigite novamente:\n\n\t\t 1-Sim \n\t\t 2- Nao).\n");
		    scanf("%d", &num2);
        }
    system("cls");
	}while(num2==1);
}
void consultaMedicoNome(void){

	FILE * arq;
	FILE * arq2;
	medico c;
	char nome[30];
	int codigo,num=0,num2=0;
	int achei = 0;
	int i=0,j=0;

	do{

		if ((arq = fopen(arquivoMedico, "rb")) == NULL) {
			fprintf(stderr, "\n\tNao existe nenhum Medico cadastrado!\n");
			printf("\n\n");
            system("pause");
			return;
		}

		if((arq2 = fopen(arqLista"PesquisaMedicoNome.txt", "w")) == NULL) {
			fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n", arqLista"PesquisaMedicoNome.txt");
			printf("\n\n");
            system("pause");
            return;
		}

		printf("\n\n\t    Consulta de Medicos \n\n");
	 do{

			printf("\tNome do Medico: ");
			fflush(stdin);
			gets(nome);
		    printf("\n\n");

			rewind(arq);


				printf("\n\n\t\t\t\tConsulta de Medico por Nome %s\n\n",nome);
				printf("=========================================================================\n");
				printf("Cod.: Nome:                       Especialidade:    CRM: \n");
				printf("=========================================================================\n\n");
				printf("-------------------------------------------------------------------------\n");

					while(fread(&c, sizeof(medico), 1, arq) > 0) {
					  for(i=0;i< (strlen(nome));i++){
					  	nome[i]=toupper(nome[i]);
						  for(j=0;j<(strlen(c.nome));j++){
					  		c.nome[j]=toupper(c.nome[j]);
					  	  }
					  }
						if(strncmp(nome,c.nome, strlen(nome)) == 0){
			 			 printf(" %04d %-30s %-10s %-10d  \n",c.codigo, c.nome, c.especialidade, c.crm);
        				 printf("-------------------------------------------------------------------------\n");
					     achei = 1;
						}
					}
				printf("\n=========================================================================\n\n");
			    if (!achei){
				  system ("cls");
				  printf("\n\n\tNao existe Medico cadastrado com esse nome: %d\n\n",codigo);
				  printf("\n\tDigite Novamente !\n\n");

				}

			}while(!achei);

			fseek(arq,0,SEEK_SET);

			printf("\n\n\tDeseja Gerar Um Relatorio ?\n\n\tDigite:\n\n\t1- Sim\n\n\t2- Nao\n\n\t ");
			scanf("%d", &num);
			while(num<1||num>2)
            {
					system ("cls");
					printf("\n\tOpcao Invalida!!!\n\n\tDeseja Gerar Um Relatorio ?\n\n\tDigite novamente:\n\n\t\t 1- Sim \n\n\t\t 2- Nao\n");
					scanf("%d", &num);
			}
			if(num==1)
            {
					fprintf(arq2,"\n\n\t\t\t\tConsulta Medico por nome %d\n\n",nome);
					fprintf(arq2,"=========================================================================\n");
					fprintf(arq2,"Cod.: Nome:                       Especialidade:    CRM: \n");
					fprintf(arq2,"=========================================================================\n\n");
					fprintf(arq2,"-------------------------------------------------------------------------\n");

					while(fread(&c, sizeof(medico), 1, arq) > 0)
                    {
					  for(i=0;i< (strlen(nome));i++)
                      {
					  	nome[i]=toupper(nome[i]);
						  for(j=0;j<(strlen(c.nome));j++)
                          {
					  		c.nome[j]=toupper(c.nome[j]);
					  	  }
					  }
					  if(strncmp(nome,c.nome, strlen(nome)) == 0)
                      {
			 			 fprintf(arq2," %04d %-30s %-10s %-10d   \n",c.codigo, c.nome, c.especialidade, c.crm);
						 fprintf(arq2,"-------------------------------------------------------------------------\n");
                         achei = 1;
					  }
				    }
					fprintf(arq2,"\n=========================================================================\n\n");
					system ("cls");
					printf("\n\n\tRelatorio gerado com sucesso!!\n\n");
					system("pause");
				}
		    system("cls");
		    fclose(arq);
		    fclose(arq2);

			printf("\n\tDeseja Realizar Outra Pesquisa ?\n\n\t\t 1- Sim\n\n\t\t 2- Nao\n\n ");
			scanf("\t%d", &num2);
   		    while(num2 < 0 || num2 > 2)
            {
				system ("cls");
			  	printf("\n\tOpcao Invalida!!!\n\n\tDigite novamente: \n\n\t\t 1- Sim\n\n\t\t 2- Nao\n");
  				scanf("\t%d", &num2);
			}
  		system("cls");
		}while(num2==1);
}

void mascara(char *frase, char formato[]){
	int tamanho, i, j = 0;
	tamanho = strlen(formato);
	char aux[tamanho + 1];
	
	for(i=0; i<tamanho; i++){
		if(formato[i] != '#'){
			aux[i] = formato[i];
		}
		else{
			aux[i] = frase[j];
			j++;
		}
	}
	
	strcpy(frase, aux);
	
}

void cadastraConsulta(void){
	FILE *arqPaciente;
	FILE *arqMedico;
	FILE *arqConsulta;
	
	paciente temp_p;
	medico temp_m;
	consulta temp_c;
	
	int opcao, terminou = 0, achei = 0, i = 0, stop =0;
	char cpf[15];
	char crm[6];
	
	
	if ((arqPaciente = fopen(arquivoPacientes, "a+b"))== NULL || (arqMedico = fopen(arquivoMedico, "a+b"))== NULL || (arqConsulta = fopen(arquivoConsulta, "a+b"))== NULL){
		printf("Erro ao abrir arquivos.");
		system("pause");
		return;
	}
	else{
		do{
			achei = 0;
			terminou = 0;
			i = 0;
			system("cls");
			printf("\n\n\t-----------------------------");
        	printf("\n\t    Cadastro de Consultas");
        	printf("\n\t-----------------------------\n");
			
			//fseek(arqPaciente, 0, SEEK_SET);
			fseek(arqMedico, 0, SEEK_SET);
			fseek(arqPaciente, 0, SEEK_SET);
			printf("\n\nCPF do Paciente: ");
			while(terminou == 0){
		   		fflush(stdin);
		   		cpf[i] = getch();
		   		printf("%c", cpf[i]);
				if((int)cpf[i] < 48 || (int)cpf[i] > 57){
					printf("\n\n\tSomente e permitido digitar numeros de 0 a 9 e o CPF deve ter 11 digitos. Digite o CPF novamente.");
					printf("\n\nCPF do Paciente: ");
					i = 0;
					terminou = 0;
				}
				else{
					i++;
				}
				if (i == 11){
					terminou = 1;
				}	
			}
			mascara(cpf, "###.###.###-##");
			while(stop == 0 && achei == 0) {
				if(fread(&temp_p, sizeof(paciente), 1, arqPaciente) > 0) {
					if(strncmp(cpf,temp_p.cpf, strlen(cpf)) == 0){
				  	achei = 1;
		    		}
				}
				else{
					stop = 1;
				}
			}
			if(achei == 0){
				printf("\nNao tem paciente cadastrado com esse CPF.");
			}
			else{
				printf("\n\nDigite o CRM do Medico: ");
				for(i=0; i<5; i++){
		   			fflush(stdin);
		   			crm[i] = getch();
		   			printf("%c", crm[i]);
					if((int)crm[i] < 48 || (int)crm[i] > 57){
						printf("\n\n\tSomente e permitido digitar numeros de 0 a 9 e o CRM deve ter 5 digitos. Digite o CRM novamente.");
						printf("\n\nCRM: ");
						i = 0;
					}
				}
				achei = 0;
				stop = 0;
				while(stop == 0 && achei == 0) {
					if(fread(&temp_m, sizeof(medico), 1, arqMedico) > 0){
						if(strncmp(crm,temp_m.crm, strlen(crm)) == 0){
							achei = 1;
		    			}
		    		}
		    		else{
		    			stop = 1;
					}
				}
				if (achei == 0){
					printf("\nNao tem medico cadastrado com esse CRM.");
				}
				else{
					fseek(arqConsulta, 0, SEEK_END);
					temp_c.codigo= ftell(arqConsulta) / sizeof(consulta) + 1;
					printf("\n\nCodigo da consulta: %d", temp_c.codigo);
					
					
					strcpy(temp_c.nome_paciente, temp_p.nome);
					strcpy(temp_c.cpf, temp_p.cpf);
					strcpy(temp_c.crm, temp_m.crm);
					strcpy(temp_c.nome, temp_m.nome);
					strcpy(temp_c.especialidade, temp_m.especialidade);
					
					printf("\n\nDigite a data da Consulta: ");
					
					fflush(stdin);
					gets(temp_c.data);
					
					fwrite(&temp_c, sizeof(consulta), 1, arqConsulta);
					system("cls");
					printf("\n\n\tPaciente Cadastrado Com Sucesso!\n\n");
					
					
					
					
					
				}	
			}
			printf("\nDeseja realizar o cadastro novamente?\n");
			printf("\n 1 - Sim       0 - Nao\n");
			scanf("%d", &opcao);			
		}while(opcao == 1);	
	fclose(arqPaciente);	
	fclose(arqMedico);
	fclose(arqConsulta);
	return;
	}		
}

void mostrarConsulta(void){
	
	
	system("cls");

	FILE * arq;
	FILE * arq2;
	int num=0;

	consulta c;

	if ((arq = fopen(arquivoConsulta, "rb")) == NULL) {
		fprintf(stderr, "\n\tNao existe nenhum paciente cadastrado!\n\n\n");
		printf("\n\ns");
        system("pause");
		return;
	}

	if((arq2 = fopen(arqLista"TodasConsultas.txt", "w")) == NULL) {
		fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n", arqLista"TodasConsultas.txt.txt");
        printf("\n\n");
		system("pause");
		return;
	}
	printf("\n\n\t\t                                                         -------------------------");
	printf("\n\t\t                                                            Consultas Agendadas   \n");
	printf("\t\t                                                         -------------------------");
	printf("\n================================================================================================================================================================================\n");
	printf("Cod. Consulta  |  Nome do Paciente                |  CPF              |  CRM do Medico  |  Nome do Medico                  |  Especialidade                   |  Data            \n");
	printf("================================================================================================================================================================================\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	
	fseek(arq,0,SEEK_SET);
	
	while (fread(&c, sizeof(consulta), 1, arq) > 0) {  
		printf("%09d      |  %-30s  |  %-15s  |  %-6s         |  %-30s  |  %-30s  |  %-11s\n",c.codigo,c.nome_paciente,c.cpf,c.crm ,c.nome , c.especialidade, c.data);
		printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
	}

//	printf("\n\n\tDeseja gerar um relatorio ?\n\n\tDigite:\n\n\t1- Sim\n\n\t2- Nao\n\n\t");
//    scanf("%d", &num);
//    while(num<1||num>2){
//	  	system ("cls");
//	    printf("\n\tOpcao Invalida!!!");
//        printf("\n\n\tDeseja gerar um relatorio ?\n\n\tDigite novamente:\n\n\t\t 1- Sim \n\t\t 2- Nao\n ");
//        scanf("%d", &num);
//    }
   if(num==1){
/*	fprintf(arq2, "\n\n\t\t                                         -------------------------");
	fprintf(arq2, "\n\t\t                                           Pacientes Cadastrados   \n");
	fprintf(arq2, "\t\t                                         -------------------------");
	fprintf(arq2, "\n============================================================================================================================================\n");
	fprintf(arq2,"Cod. Nome  |  Nome                            |  Endereco                                            |  CPF              |  Tel.            \n");
	fprintf(arq2,"============================================================================================================================================\n");
	fprintf(arq2,"--------------------------------------------------------------------------------------------------------------------------------------------\n");
      	while (fread(&c, sizeof(paciente), 1, arq) > 0) {
            fprintf(arq2,"%09d  |  %-30s  |  %-50s  |  %-15s  |  %-15s  \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone);
        	fprintf(arq2,"--------------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        system ("cls");
		printf("\n\n\tRelatorio gerado com sucesso!\n\n");
   }
  */ 
}
   else if(num==2){
		   system ("cls");
		  	return;
   }
    system("pause");
    system("cls");
    fclose(arq);
    fclose(arq2);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
