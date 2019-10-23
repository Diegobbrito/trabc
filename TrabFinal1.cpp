/*Trabalho Final da disciplina de Linguagem de Programação*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define tamCli 200
#define tamDVD 200
#define arquivoClientes "clientes.dat"
#define arquivoDVDs "dvd.dat"
#define arqLista
typedef struct
{
	int dia;
	int mes;
	int ano;

}dt;

typedef struct
{
    int codigo;
	char nome[30];
    char endereco[50];
	char cpf[15];
	char nomeContato[30];
	int telefoneContato;
    int telefone;
}cliente;

typedef struct
{
    int codigo;
	char titulo[30];
	char genero[10];
    char duracao[10];
    dt data_lanc;
}dvd;

void cadastraCliente(void);
void cadastraDvd(void);
void consultaClientes (void);
void consultaClienteNome(void);
void consultaClienteCPF(void);
void consultaDVDs(void);
void consultaDVDCodigo(void);
void consultaDVDTitulo(void);
int main(){
    int op;
	do {
		printf("\n\n\t-------------------------------\n");
		printf("\t   Escolha uma das opcoes      \n");
		printf("\t-------------------------------\n");
		printf("\n\t1- Cadastrar Clientes\n");
		printf("\n\t2- Cadastrar DVDs\n");
		printf("\n\t3- Mostrar todos os Clientes Cadastrados\n");
                printf("\n\t4- Consultar Clientes por Nome\n");
		printf("\n\t5- Consultar Clientes por CPF\n");
		printf("\n\t6- Mostrar todos os DVDs Cadastrados\n");
		printf("\n\t7- Consultar DVDs por Codigos\n");
		printf("\n\t8- Consultar DVDs por Titulo\n");
		printf("\n\t0- Sair do programa\n\n");
		printf("\tEscola uma Opcao: ");
		scanf("%d", &op);
		switch(op){
		    case 1:
			        system ("cls");
					cadastraCliente();
		         break;
		    case 2:
					system ("cls");
					cadastraDvd();
		         break;
		    case 3:
					system ("cls");
					consultaClientes();
		         break;
		    case 4:
			        system ("cls");
					consultaClienteNome();
		         break;
		    case 5:
			        system ("cls");
					consultaClienteCPF();
		         break;
		    case 6:
			        system ("cls");
					consultaDVDs();
		         break;
		    case 7:
			        system ("cls");
					consultaDVDCodigo();
		         break;
		    case 8:
			        system ("cls");
					consultaDVDTitulo();
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

void cadastraCliente(void)
{

	FILE * arq;
	cliente x;
    char aux[15];
    char aux2[15];
    char cpf[15];
    int i=0,j=0;
    int a = 0, num=0;
    do{
		do{
		   printf("\n\n\t     Cadastro de Novo Cliente\n\n");
		   if ((arq = fopen(arquivoClientes, "a+b")) == NULL) {
				fprintf(stderr, "\n\tImpossivel abrir o arquivo %s!\n", arquivoClientes);
		   }
		   fseek(arq, 0, SEEK_SET);
		   a=0;
		   printf("\nCPF: ");
		   fflush(stdin);
		   gets(cpf);
		   while(fread(&x, sizeof(cliente), 1, arq) > 0) {
			if(strncmp(cpf,x.cpf, strlen(cpf)) == 0){
			  a=a+1;
		    }
	       }
		   if(a > 0){
			  printf("\n\n\tJa existe um cliente cadastrado com esse cpf: %s\n\n",cpf);
			  printf("\n\tCPF Invalido !!!\n\n");
		   }
		}while(a > 0);
	        fseek(arq, 0, SEEK_END);
		x.codigo= ftell(arq) / sizeof(cliente) + 1;
		printf("\tCodigo do Cliente: %d\n\n", x.codigo);
		printf("\n\nCPF: %s \n",cpf);
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

	    printf("\nNome do Contato: ");
		fflush(stdin);
		gets(x.nomeContato);

	    printf("\nTelefone do Contato: ");
		fflush(stdin);
		gets(aux2);
		x.telefoneContato=atoi(aux2);

		fwrite(&x, sizeof(cliente), 1, arq);
	    system("cls");
	    printf("\n\n\tCliente Cadastrado Com Sucesso!\n\n");
	    fclose(arq);

        printf("\n\tDeseja Cadastrar outro Cliente ?\n\n\t1 - Sim\n\n\t2 - Nao\n\n ");
 	    scanf("%d", &num);
		  while(num < 0 || num > 2){
			  	system ("cls");
			  	printf("\n\tOpcao Invalida!!\n\n");
                printf("\n\tDeseja Cadastrar outro Cliente ?\n\n");
                printf("\n\tDigite novamente:\n\n\n\t\t1 - Sim\n\n\t\t2 - Nao\n");
  		        scanf("%d", &num);
				system("cls");
	      }
	}while(num==1);
}

void cadastraDvd(void)
{
	FILE * arq;
	dvd x;
	int num=0;
	do{

		printf("\n\n\t     Cadastro de novo DVD \n\n");
		if ((arq = fopen(arquivoDVDs, "ab")) == NULL) {
			fprintf(stderr, "\n\tImpossivel abrir o arquivo %s!\n", arquivoDVDs);
		}
		fseek(arq, 0, SEEK_END);

		x.codigo = ftell(arq) / sizeof(dvd) + 1;

	       system("cls");
	       printf("Cadastro de DVDs\n\n");

	       printf("Codigo: %d\n\n", x.codigo);
	       printf("\nTitulo: ");
	       fflush(stdin);
		   gets(x.titulo);
	       printf("\nGenero: ");
	       gets(x.genero);
	       printf("\nDuracao: ");
	       gets(x.duracao);
	 	   printf("\nData do Lancamento (ddmmaaaa): ");
		   scanf("%02d %02d %4d", &x.data_lanc.dia, &x.data_lanc.mes, &x.data_lanc.ano);

		   fwrite(&x, sizeof(dvd), 1, arq);
    	   system("cls");
		   printf("\n\n\tDVD Cadastrado Com Sucesso!\n\n");

		   fclose(arq);

			printf("\n\tDeseja Cadastrar outro DVD ?\n\n\t1- Sim\n\n\t2- Nao\n\n ");
			scanf("%d", &num);
			while(num < 0 || num > 2){
  		  	     system ("cls");
				 printf("\n\tOpcao Invalida!!\n\n\tDigite novamente:\n\n\t\t1-Sim\n\n\t\t2- Nao\n");
		         scanf("%d", &num);
           }
	}while(num==1);
}

void consultaClientes (void)
{
system("cls");

FILE * arq;
FILE * arq2;
int num=0;

cliente c;

	if ((arq = fopen(arquivoClientes, "rb")) == NULL) {
		fprintf(stderr, "\n\tNao existe nenhum cliente cadastrado!\n\n\n");
		printf("\n\ns");
        system("pause");
		return;
	}

	if((arq2 = fopen(arqLista"TodosClientes.txt", "w")) == NULL) {
		fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n", arqLista"TodosClientes.txt");
        printf("\n\n");
		system("pause");
		return;
	}

	printf("\n\nClientes Cadastrados\n\n");
	printf("==========================================================================\n");
	printf("Cod. Nome\tEndereco\tCpf\t   tel.\t  Contato    \tTel.Cot.    \n");
	printf("==========================================================================\n\n");
	printf("--------------------------------------------------------------------------\n");
	while (fread(&c, sizeof(cliente), 1, arq) > 0) {

     printf("%04d %-10s %-15s %-10s %-10d %-10s %-12d \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone,c.nomeContato,c.telefoneContato);

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
    	fprintf(arq2,"\n\nClientes Cadastrados\n\n");
	    fprintf(arq2,"==========================================================================\n");
	    fprintf(arq2,"Cod. Nome\tEndereco\tCpf\t   tel.\t  Contato  \tTel.Cot.    \n");
     	fprintf(arq2,"--------------------------------------------------------------------------\n");
      	while (fread(&c, sizeof(cliente), 1, arq) > 0) {
            fprintf(arq2,"%04d %-10s %-10s %-10s %-12d %-10s %-12d \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone,c.nomeContato,c.telefoneContato);
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
void consultaClienteNome(void){
system("cls");

FILE * arq;
FILE * arq2;

cliente c;
int num=0,num2=0;
char nome[50];
int achei = 0;

int i=0,j=0;

	do{
		if ((arq = fopen(arquivoClientes, "rb")) == NULL) {
			fprintf(stderr, "\n\tNao existe nenhum cliente cadastrado!\n");
			printf("\n\n");
			system("pause");
            return;
		}
		if((arq2 = fopen(arqLista"PesquisaClienteNome.txt", "w")) == NULL) {
			fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n", arqLista"PesquisaClienteNome.txt");
			printf("\n\n");
            system("pause");
            return;
		}
		printf("\n\n\t     Pesquisa de clientes por nome\n\n");
	    do{
			printf("\tNome do Cliente: ");
			scanf(" %50[^\n]", nome);
		    printf("\n\n");
			rewind(arq);
	        printf("\n\nClientes cadastrados com esse nome:%s\n\n",nome);
	        printf("==========================================================================\n");
	        printf("Cod. Nome\tEndereco\tCpf\t   tel.\t  Contato    \tTel.Cot.    \n");
	        printf("==========================================================================\n\n");
	        printf("--------------------------------------------------------------------------\n");

			while(fread(&c, sizeof(cliente), 1, arq) > 0)
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
                   printf("%04d %-10s %-15s %-10s %-10d %-10s %-12d \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone,c.nomeContato,c.telefoneContato);
	           printf("--------------------------------------------------------------------------\n");
			achei = 1;
			  }
			}
	        printf("==========================================================================\n\n");
		    if (!achei){
			  printf("\n\n\tNao existe cliente cadastrado com esse nome: %s\n\n",nome);
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
	           fprintf(arq2,"\n\nClientes cadastrados com esse nome\n\n");
	           fprintf(arq2,"==========================================================================\n");
	           fprintf(arq2,"Cod. Nome\tEndereco\tCpf\t   tel.\t  Contato    \tTel.Cot.    \n");
	           fprintf(arq2,"==========================================================================\n\n");
	           fprintf(arq2,"--------------------------------------------------------------------------\n");

			   while(fread(&c, sizeof(cliente), 1, arq) > 0)
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
				     fprintf(arq2,"%04d %-10s %-10s %-10s %-12d %-10s %-12d \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone,c.nomeContato,c.telefoneContato);
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

void consultaClienteCPF(void){
system("cls");

FILE * arq;
FILE * arq2;

cliente c;
int num=0,num2=0;
char cpf[15];
int achei = 0;
int i=0,j=0;

	do{
		if ((arq = fopen(arquivoClientes, "rb")) == NULL)
        {
			fprintf(stderr, "\n\tErro: Nao existe nenhum cliente cadastrado!\n");
		    printf("\n\n");
        	system("pause");
            return;
		}
		if((arq2 = fopen(arqLista"PesquisaClienteCPF.txt", "w")) == NULL)
        {
			fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n", arqLista"PesquisaClienteCPF.txt");
			printf("\n\n");
            system("pause");
    		return;
		}
		printf("\n\n\t   Consultar Cliente por cpf    \n\n");
	 do{
			printf("\tCPF do Cliente: ");
			fflush(stdin);
			gets(cpf);
		    printf("\n\n");

			rewind(arq);

			printf("\n\n\t\tCliente com esse cpf: %s\n\n",cpf);
	        printf("==========================================================================\n");
	        printf("Cod. Nome\tEndereco\tCpf\t   tel.\t  Contato    \tTel.Cot.    \n");
	        printf("==========================================================================\n\n");
	        printf("--------------------------------------------------------------------------\n");

			while(fread(&c, sizeof(cliente), 1, arq) > 0)
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
                printf("%04d %-10s %-15s %-10s %-10d %-10s %-12d \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone,c.nomeContato,c.telefoneContato);
                printf("--------------------------------------------------------------------------\n");
				achei = 1;
 			  }
			}
	        printf("==========================================================================\n");

		    if (!achei){
			  printf("\n\n\tNao existe cliente cadastrado com  esse CPF: %s\n\n",cpf);
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
			   fprintf(arq2,"\n\n\t\t\t\t\tCliente com esse CPF: %s\n\n",cpf);
	           fprintf(arq2,"================================================================================\n");
	           fprintf(arq2,"Cod. Nome\tEndereco\tCpf\t   tel.\t  Contato    \tTel.Cot.    \n");
	           fprintf(arq2,"================================================================================\n\n");
	           fprintf(arq2,"--------------------------------------------------------------------------------\n");
			while(fread(&c, sizeof(cliente), 1, arq) > 0)
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
 			    fprintf(arq2," %04d %-20s %-20s %-15s %-12d %-20s %-12d  \n",c.codigo,c.nome,c.endereco,c.cpf,c.telefone,c.nomeContato,c.telefoneContato);
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

void consultaDVDs (void){

system("cls");

FILE * arq;
FILE * arq2;
int num=0;

dvd c;

	if ((arq = fopen(arquivoDVDs, "rb")) == NULL) {
		fprintf(stderr, "\n\tErro: Nao existe nenhum DVD cadastrado!\n\n\n");
		printf("\n\n");
        system("pause");
		return;
	}
	if((arq2 = fopen(arqLista"TodosDVDs.txt", "w")) == NULL) {
		fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n", arqLista"TodosDVDs.txt");
		printf("\n\n");
        system("pause");
		return;
	}
	printf("\n\n\t\t\t\tDVDs cadastrados\n\n");
	printf("=========================================================================\n");
	printf(" Cod.: Titulo:                       Genero:    Duracao:    Data Lanc.:  \n");
	printf("=========================================================================\n\n");
	printf("-------------------------------------------------------------------------\n");
	while (fread(&c, sizeof(dvd), 1, arq) > 0) {
	 printf(" %04d %-30s %-10s %-10s  %02d/%02d/%04d   \n",c.codigo, c.titulo, c.genero, c.duracao, c.data_lanc.dia,c.data_lanc.mes,c.data_lanc.ano);
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

			fprintf(arq2,"\n\n\t\t\t\tDVDs cadastrados\n\n");
			fprintf(arq2,"=========================================================================\n");
			fprintf(arq2," Cod.: Titulo:                       Genero:    Duracao:    Data Lanc.:  \n");
			fprintf(arq2,"=========================================================================\n\n");
			fprintf(arq2,"-------------------------------------------------------------------------\n");
			while(fread(&c, sizeof(dvd), 1, arq) > 0) {
			  fprintf(arq2," %04d %-30s %-10s %-10s  %02d/%02d/%04d   \n",c.codigo, c.titulo,c.genero, c.duracao, c.data_lanc.dia,c.data_lanc.mes,c.data_lanc.ano);
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

void consultaDVDCodigo(void){

	FILE * arq;
	FILE * arq2;
	dvd c;
	int codigo,num=0,num2=0;

	int achei = 0;
	int i=0,j=0;


	do{

		if ((arq = fopen(arquivoDVDs, "rb")) == NULL) {
			fprintf(stderr, "\n\tErro: Nao existe nenhum DVD cadastrado!\n");
      		printf("\n\n");
            system("pause");
			return;
		}

		if((arq2 = fopen(arqLista"PesquisaDVDCodigo.txt", "w")) == NULL) {
			fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n",arqLista"PesquisaDVDCodigo.txt");
            printf("\n\n");
			system("pause");
    		return;
		}

	 do{
			printf("\tCodigo do DVD: ");
			fflush(stdin);
			scanf("%d", &codigo);
		    printf("\n\n");

			rewind(arq);

			printf("\n\n\t\t\t\tDVD cadastrado com o codigo: %d\n\n",codigo);
			printf("=========================================================================\n");
			printf(" Cod.: Titulo:                       Genero:    Duracao:    Data Lanc.:  \n");
			printf("=========================================================================\n\n");
			printf("-------------------------------------------------------------------------\n");
			while(fread(&c, sizeof(dvd), 1, arq) > 0) {

				if( codigo == c.codigo){
		 			printf(" %04d %-30s %-10s %-10s  %02d/%02d/%04d   \n",c.codigo, c.titulo, c.genero, c.duracao,
					  c.data_lanc.dia,c.data_lanc.mes,c.data_lanc.ano);
					printf("-------------------------------------------------------------------------\n");

						 achei = 1;
				}
			}
			printf("\n=========================================================================\n\n");

		    if (!achei){

			  system ("cls");
			  printf("\n\n\tNao existe DVDs cadastrados com esse titulo: %d\n\n",codigo);
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
				fprintf(arq2,"\n\n\t\t\t\tDVD cadastrado com o codigo: %d\n\n",codigo);
				fprintf(arq2,"=========================================================================\n");
				fprintf(arq2," Cod.: Titulo:                       Genero:    Duracao:    Data Lanc.:  \n");
				fprintf(arq2,"=========================================================================\n\n");
				fprintf(arq2,"-------------------------------------------------------------------------\n");
			    while(fread(&c, sizeof(dvd), 1, arq) > 0)
                {
					if( codigo == c.codigo){
		 			fprintf(arq2," %04d %-30s %-10s %-10s  %02d/%02d/%04d   \n",c.codigo, c.titulo, c.genero, c.duracao,c.data_lanc.dia,c.data_lanc.mes,c.data_lanc.ano);
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
void consultaDVDTitulo(void){

	FILE * arq;
	FILE * arq2;
	dvd c;
	char titulo[30];
	int codigo,num=0,num2=0;
	int achei = 0;
	int i=0,j=0;

	do{

		if ((arq = fopen(arquivoDVDs, "rb")) == NULL) {
			fprintf(stderr, "\n\tNao existe nenhum DVD cadastrado!\n");
			printf("\n\n");
            system("pause");
			return;
		}

		if((arq2 = fopen(arqLista"PesquisaDVDTitulo.txt", "w")) == NULL) {
			fprintf(stderr, "\n\tErro de abertura do arquivo %s!\n", arqLista"PesquisaDVDTitulo.txt");
			printf("\n\n");
            system("pause");
            return;
		}

		printf("\n\n\t    Consulta de DVDs \n\n");
	 do{

			printf("\tTitulo do DVD: ");
			fflush(stdin);
			gets(titulo);
		    printf("\n\n");

			rewind(arq);


				printf("\n\n\t\t\t\tConsulta de DVD por Titulo %s\n\n",titulo);
				printf("=========================================================================\n");
				printf("Cod.: Titulo:                       Genero:    Duracao:    Data Lanc.: \n");
				printf("=========================================================================\n\n");
				printf("-------------------------------------------------------------------------\n");

					while(fread(&c, sizeof(dvd), 1, arq) > 0) {
					  for(i=0;i< (strlen(titulo));i++){
					  	titulo[i]=toupper(titulo[i]);
						  for(j=0;j<(strlen(c.titulo));j++){
					  		c.titulo[j]=toupper(c.titulo[j]);
					  	  }
					  }
						if(strncmp(titulo,c.titulo, strlen(titulo)) == 0){
			 			 printf(" %04d %-30s %-10s %-10s  %02d/%02d/%04d  \n",c.codigo, c.titulo, c.genero, c.duracao,c.data_lanc.dia,c.data_lanc.mes,c.data_lanc.ano);
        				 printf("-------------------------------------------------------------------------\n");
					     achei = 1;
						}
					}
				printf("\n=========================================================================\n\n");
			    if (!achei){
				  system ("cls");
				  printf("\n\n\tNao existe DVD cadastrado com esse titulo: %d\n\n",codigo);
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
					fprintf(arq2,"\n\n\t\t\t\tConsulta DVD por titulo %d\n\n",titulo);
					fprintf(arq2,"=========================================================================\n");
					fprintf(arq2,"Cod.: Titulo:                       Genero:    Duracao:    Data Lanc.: \n");
					fprintf(arq2,"=========================================================================\n\n");
					fprintf(arq2,"-------------------------------------------------------------------------\n");

					while(fread(&c, sizeof(dvd), 1, arq) > 0)
                    {
					  for(i=0;i< (strlen(titulo));i++)
                      {
					  	titulo[i]=toupper(titulo[i]);
						  for(j=0;j<(strlen(c.titulo));j++)
                          {
					  		c.titulo[j]=toupper(c.titulo[j]);
					  	  }
					  }
					  if(strncmp(titulo,c.titulo, strlen(titulo)) == 0)
                      {
			 			 fprintf(arq2," %04d %-30s %-10s %-10s  %02d/%02d/%04d   \n",c.codigo, c.titulo, c.genero, c.duracao,c.data_lanc.dia,c.data_lanc.mes,c.data_lanc.ano);
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
