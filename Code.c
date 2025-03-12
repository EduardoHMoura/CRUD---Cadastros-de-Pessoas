#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define qttdPessoas 2

typedef struct {
    char nome[50];
    char sexo[20];
    int idade;
    int dia_nasc, mes_nasc, ano_nasc;
} pessoa;

void cadastrarPessoa(pessoa *c, int tam);
void exibirPessoa(pessoa *c, int tam);

int main(){
    
}

void cadastrarPessoa(pessoa *c, int tam) {
    int cadastro = 1; 
    for(int i = 0; i < tam; i++) {
        
        printf("Cadastro ID - %i:\n", cadastro++);
        printf("Informe o nome:\n");
        scanf("%49[^\n]s", c[i].nome);
        getchar();
        
        printf("Informe a idade:\n");
        scanf("%i", &c[i].idade);
        getchar();
                    
		printf("Informe a Data de Nascimento:\n");
		printf("Dia:");
		scanf("%i",&dia_nasc);
		printf("Mes:");
		scanf("%i",&mes_nasc);
		printf("Ano:");
		scanf("%i",&ano_nasc);

		printf("Selecione o sexo da pessoa [M]Masculino [F]Feminino [P]Prefiro nC#o Informar: ");
		scanf(" %c", &sexo);

		switch (sexo) {
		    
		case 'M':
			strcpy(pessoa[i].sexo, "Masculino");
			break;
		case 'F':
		    strcpy(pessoa[i].sexo, "Feminino");
	        break;
		case 'P':
		    strcpy(pessoa[i].sexo, "Prefiro NC#o Informar");
		    break;
		default:
		    strcpy(cads[i].sexo, "Desconhecido");
		    break;
		}
	}
        system("cls");
}

void exibirPessoa(pessoa *c, int tam) {

    for(int i = 0; i < tam; i++) {
        printf("\nCadastro ID - %i:\n", i + 1);
        printf("Nome: %s\n", c[i].nome);
        printf("Idade: %d\n", c[i].idade);
        printf("Sexo: %s\n", c[i].sexo);
    }
}
