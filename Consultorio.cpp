/*Trabalho Final da disciplina de Linguagem de Programação*/

//teste
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define arquivoPacientes "pacientes.dat"
#define arquivoMedico "medico.dat"
#define arqLista
typedef struct
{
	int dia;
	int mes;
	int ano;

}dt;

//struct paciente, temos que verificar se só esses dados sao suficientes ou se vamos remover algo também
typedef struct
{
    int codigo;
	char nome[30];
    char endereco[50];
	char cpf[11];
    int telefone;
}paciente;

typedef struct
{
    int codigo;
	char nome[30];
	char especialidade[20];
    int crm;
}medico;

void cadastraPaciente(void);
void cadastraMedico(void);
void consultaPacientes (void);
void consultaPacienteNome(void);
void consultaPacienteCPF(void);
void consultaMedicos(void);
void consultaMedicoCodigo(void);
void consultaMedicoNome(void);
//char validaCPF();
int main(){
    int op;
	do {
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
		printf("\n\t0- Sair do programa\n\n");
		printf("\tEscola uma Opcao: ");
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

	FILE * arq;
	paciente x;


	 int soma, resultado, numero, contador;
    char digito10, digito11;


    char aux[15];
    char cpf[11];
    int i=0,j=0;
    int a = 0, num=0;
    do{
            printf("\n\n\t     Cadastro de Novo Paciente\n\n");
		do{

		   if ((arq = fopen(arquivoPacientes, "a+b")) == NULL) {
				fprintf(stderr, "\n\tImpossivel abrir o arquivo %s!\n", arquivoPacientes);
		   }
		   fseek(arq, 0, SEEK_SET);
		   a=0;

            //Validacao do cpf

		   do{

            fflush(stdin);
            system("cls");
            printf("Digite o CPF apenas com os 11 numeros: \n");
            gets(cpf);


            soma=0;
        for(contador=0; contador<9; contador++){
            numero=cpf[contador]-48;
            soma = soma+(numero*(10-contador));
        }
        resultado = 11-(soma%11);
        if((resultado == 10)|| (resultado ==11)){
            digito10 = '0';
        }else{
            digito10 = resultado+48;
        }
        soma =0;
        for(contador=0; contador<10; contador++){
            numero=cpf[contador]-48;
            soma = soma+(numero*(11-contador));
        }
        resultado=11-(soma%11);
            if((resultado == 10)|| (resultado ==11)){
                digito11 = '0';
            }else{
                digito11 = resultado+48;
            }
       }while((digito10!=cpf[9])&&(digito11!=cpf[10])
              && cpf[0]!= 0 && cpf[0]!= 1 && cpf[0]!= 2 && cpf[0]!= 3 && cpf[0]!= 4 && cpf[0]!= 5 && cpf[0]!= 6 && cpf[0]!= 7 && cpf[0]!= 8 && cpf[0]!= 9
              && cpf[1]!= 0 && cpf[1]!= 1 && cpf[1]!= 2 && cpf[1]!= 3 && cpf[1]!= 4 && cpf[1]!= 5 && cpf[1]!= 6 && cpf[1]!= 7 && cpf[1]!= 8 && cpf[1]!= 9
              && cpf[2]!= 0 && cpf[2]!= 1 && cpf[2]!= 2 && cpf[2]!= 3 && cpf[2]!= 4 && cpf[2]!= 5 && cpf[2]!= 6 && cpf[2]!= 7 && cpf[2]!= 8 && cpf[2]!= 9
              && cpf[3]!= 0 && cpf[3]!= 1 && cpf[3]!= 2 && cpf[3]!= 3 && cpf[3]!= 4 && cpf[3]!= 5 && cpf[3]!= 6 && cpf[3]!= 7 && cpf[3]!= 8 && cpf[3]!= 9
              && cpf[4]!= 0 && cpf[4]!= 1 && cpf[4]!= 2 && cpf[4]!= 3 && cpf[4]!= 4 && cpf[4]!= 5 && cpf[4]!= 6 && cpf[4]!= 7 && cpf[4]!= 8 && cpf[4]!= 9
              && cpf[5]!= 0 && cpf[5]!= 1 && cpf[5]!= 2 && cpf[5]!= 3 && cpf[5]!= 4 && cpf[5]!= 5 && cpf[5]!= 6 && cpf[5]!= 7 && cpf[5]!= 8 && cpf[5]!= 9
              && cpf[6]!= 0 && cpf[6]!= 1 && cpf[6]!= 2 && cpf[6]!= 3 && cpf[6]!= 4 && cpf[6]!= 5 && cpf[6]!= 6 && cpf[6]!= 7 && cpf[6]!= 8 && cpf[6]!= 9
              && cpf[7]!= 0 && cpf[7]!= 1 && cpf[7]!= 2 && cpf[7]!= 3 && cpf[7]!= 4 && cpf[7]!= 5 && cpf[7]!= 6 && cpf[7]!= 7 && cpf[7]!= 8 && cpf[7]!= 9
              && cpf[8]!= 0 && cpf[8]!= 1 && cpf[8]!= 2 && cpf[8]!= 3 && cpf[8]!= 4 && cpf[8]!= 5 && cpf[8]!= 6 && cpf[8]!= 7 && cpf[8]!= 8 && cpf[8]!= 9
              && cpf[9]!= 0 && cpf[9]!= 1 && cpf[9]!= 2 && cpf[9]!= 3 && cpf[9]!= 4 && cpf[9]!= 5 && cpf[9]!= 6 && cpf[9]!= 7 && cpf[9]!= 8 && cpf[9]!= 9
              && cpf[10]!= 0 && cpf[10]!= 1 && cpf[10]!= 2 && cpf[10]!= 3 && cpf[10]!= 4 && cpf[10]!= 5 && cpf[10]!= 6 && cpf[10]!= 8 && cpf[10]!= 8 && cpf[10]!= 9
              && cpf[11]!= 0 && cpf[11]!= 1 && cpf[11]!= 2 && cpf[11]!= 3 && cpf[11]!= 4 && cpf[11]!= 5 && cpf[11]!= 6 && cpf[11]!= 8 && cpf[11]!= 8 && cpf[11]!= 9
              );



		   while(fread(&x, sizeof(paciente), 1, arq) > 0) {
			if(strncmp(cpf,x.cpf, strlen(cpf)) == 0){
			  a=a+1;
		    }
	       }
		   if(a > 0){
			  printf("\n\n\tJa existe um paciente cadastrado com esse cpf: %s\n\n",cpf);
			  printf("\n\tCPF Invalido !!!\n\n");
		   }
		}while(a > 0);
	        fseek(arq, 0, SEEK_END);
		x.codigo= ftell(arq) / sizeof(paciente) + 1;
		system("cls");
		printf("\tCodigo do Paciente: %d\n\n", x.codigo);
            strcpy(x.cpf,cpf);

		printf("\nNome: ");
		fflush(stdin);
		gets(x.nome);

		printf("\nEndereco: ");
		fflush(stdin);
		gets(x.endereco);

		printf("\nTelefone: ");
		fflush(stdin);
		gets(aux);
	        x.telefone=atoi(aux);

		fwrite(&x, sizeof(paciente), 1, arq);
	    system("cls");
	    printf("\n\n\tPaciente Cadastrado Com Sucesso!\n\n");
	    fclose(arq);

        printf("\n\tDeseja Cadastrar outro Paciente ?\n\n\t1 - Sim\n\n\t2 - Nao\n\n ");
 	    scanf("%d", &num);
		  while(num < 0 || num > 2){
			  	system ("cls");
			  	printf("\n\tOpcao Invalida!!\n\n");
                printf("\n\tDeseja Cadastrar outro Paciente ?\n\n");
                printf("\n\tDigite novamente:\n\n\n\t\t1 - Sim\n\n\t\t2 - Nao\n");
  		        scanf("%d", &num);
				system("cls");
	      }
	}while(num==1);
}

void cadastraMedico(void)
{
	FILE * arq;
	medico x;
	char aux[15];
	int num=0;
	do{

		printf("\n\n\t     Cadastro de novo Medico \n\n");
		if ((arq = fopen(arquivoMedico, "ab")) == NULL) {
			fprintf(stderr, "\n\tImpossivel abrir o arquivo %s!\n", arquivoMedico);
		}
		fseek(arq, 0, SEEK_END);

		x.codigo = ftell(arq) / sizeof(medico) + 1;

	       system("cls");
	       printf("Cadastro de Medicos\n\n");

	       printf("Codigo: %d\n\n", x.codigo);
	       printf("\nNome: ");
	       fflush(stdin);
		   gets(x.nome);
	       printf("\nEspecialidade: ");
	       gets(x.especialidade);
	       printf("\nCRM: ");
	       fflush(stdin);
            gets(aux);
	        x.crm=atoi(aux);

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

	printf("\n\nPacientes Cadastrados\n\n");
	printf("==========================================================================\n");
	printf("Cod. Nome\tEndereco\tCpf\t   tel.\t    \n");
	printf("==========================================================================\n\n");
	printf("--------------------------------------------------------------------------\n");
	while (fread(&c, sizeof(paciente), 1, arq) > 0) {

     printf("%04d %-10s %-15s %-12s %-12d  \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone);

	printf("--------------------------------------------------------------------------\n");
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
    	fprintf(arq2,"\n\nPacientes Cadastrados\n\n");
	    fprintf(arq2,"==========================================================================\n");
	    fprintf(arq2,"Cod. Nome\tEndereco\tCpf\t   tel.\t    \n");
     	fprintf(arq2,"--------------------------------------------------------------------------\n");
      	while (fread(&c, sizeof(paciente), 1, arq) > 0) {
            fprintf(arq2,"%04d %-10s %-10s %-10s %-12d  \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone);
            fprintf(arq2,"--------------------------------------------------------------------------\n");
        }
	    fprintf(arq2,"==========================================================================\n");
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

int i=0,j=0;

	do{
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
		printf("\n\n\t     Pesquisa de pacientes por nome\n\n");
	    do{
			printf("\tNome do Paciente: ");
			scanf(" %50[^\n]", nome);
		    printf("\n\n");
			rewind(arq);
	        printf("\n\nPacientes cadastrados com esse nome:%s\n\n",nome);
	        printf("==========================================================================\n");
	        printf("Cod. Nome\tEndereco\tCpf\t   tel.\t    \n");
	        printf("==========================================================================\n\n");
	        printf("--------------------------------------------------------------------------\n");

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
                   printf("%04d %-10s %-15s %-10s %-10d \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone);
	           printf("--------------------------------------------------------------------------\n");
			achei = 1;
			  }
			}
	        printf("==========================================================================\n\n");
		    if (!achei){
			  printf("\n\n\tNao existe paciente cadastrado com esse nome: %s\n\n",nome);
			  printf("\n\tDigite Novamente !\n\n");
			}

		}while(!achei);

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
	           fprintf(arq2,"\n\nPacientes cadastrados com esse nome\n\n");
	           fprintf(arq2,"==========================================================================\n");
	           fprintf(arq2,"Cod. Nome\tEndereco\tCpf\t   tel.\t    \n");
	           fprintf(arq2,"==========================================================================\n\n");
	           fprintf(arq2,"--------------------------------------------------------------------------\n");

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
				     fprintf(arq2,"%04d %-10s %-10s %-10s %-12d \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone);
                	 fprintf(arq2,"--------------------------------------------------------------------------\n");
				     achei = 1;
				 }
			   }
	           fprintf(arq2,"==========================================================================\n\n");

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
		    printf("\n\tOpcao Invalida!!!\n\n");
            printf("\tDeseja Realizar Outra Pesquisa ?\n\n");
            printf("\tDigite novamente:\n\n\t\t 1-Sim \n\t\t 2- Nao).\n");
      		scanf("%d", &num2);
		}
	system("cls");
	}while(num2==1);
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
	 printf(" %04d %-30s %-10s %-10d     \n",c.codigo, c.nome, c.especialidade, c.crm);
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

/*char validaCPF(){

    int soma, resultado, numero, contador;
    char digito10, digito11, cpf[12];


       do{

            fflush(stdin);
            system("cls");
            printf("Digite o CPF apenas com os 11 numeros: \n");
            gets(cpf);
            soma=0;
     for(contador=0; contador<9; contador++){
        numero=cpf[contador]-48;
        soma = soma+(numero*(10-contador));
        }
        resultado = 11-(soma%11);
        if((resultado == 10)|| (resultado ==11)){
            digito10 = '0';
        }else{
            digito10 = resultado+48;
        }
        soma =0;
        for(contador=0; contador<10; contador++){
        numero=cpf[contador]-48;
        soma = soma+(numero*(11-contador));
        }
        resultado=11-(soma%11);
            if((resultado == 10)|| (resultado ==11)){
                digito11 = '0';
            }else{
                digito11 = resultado+48;
            }
       }while((digito10!=cpf[9])&&(digito11!=cpf[10]));

       return(cpf);

}*/








