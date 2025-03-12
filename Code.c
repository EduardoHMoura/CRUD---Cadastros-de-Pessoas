#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define qttdPessoas 2

typedef struct {
	int birthDay;
	int birthMonth;
	int birthYear;
} nasc;

typedef struct {
    char name[50];
    char sexo[20];
    int age;
	nasc birthDate;
} pessoa;

pessoa pessoas[qttdPessoas];

void cadastrarPessoa(pessoa *c, int tam);
void exibirPessoa(pessoa *c, int tam);

int main(){
    pessoa pessoas[qttdPessoas];
    cadastrarPessoa(pessoas, qttdPessoas);
	exibirPessoa(pessoas, qttdPessoas);
return 0;
}

void cadastrarPessoa(pessoa *c, int tam) {
    int cadastro = 1; 
    for(int i = 0; i < tam; i++) {

        system("cls");
        printf("Cadastro ID - %i:\n", cadastro++);
        printf("Informe o nome:\n");
        scanf(" %49[^\n]s", c[i].name);
        getchar();
		printf("Informe a Data de Nascimento:\n");
		printf("Dia:");
		scanf("%i",&c[i].birthDate.birthDay);
		printf("Mes:");
		scanf("%i",&c[i].birthDate.birthMonth);
		printf("Ano:");
		scanf("%i",&c[i].birthDate.birthYear);
		getchar();

        printf("Informe a idade:\n");
        scanf("%i", &c[i].age);
        getchar();
		

        printf("Selecione o sexo da pessoa [M]Masculino [F]Feminino [O]Outro: ");
        char condition;
        scanf(" %c", &condition);  // Lendo apenas um caractere corretamente
        
        switch (condition) {
            case 'M':
                strcpy(c[i].sexo, "Masculino");
                break;
            case 'F':
                strcpy(c[i].sexo, "Feminino");
                break;
            case 'O':
                strcpy(c[i].sexo, "Outro");
                break;
            default:
                strcpy(c[i].sexo, "Nao Informado");
                break;
        }
        system("cls");
    }
}
void exibirPessoa(pessoa *c, int tam) {

    for(int i = 0; i < tam; i++) {
        printf("\nCadastro ID - %i:\n", i + 1);
        printf("Nome: %s\n", c[i].name);
	printf("Data de nascimento: %d/%d/%d\n", c[i].birthDate.birthDay,c[i].birthDate.birthMonth, c[i].birthDate.birthYear);
        printf("Idade: %d Anos\n", c[i].age);
        printf("Sexo: %s\n", c[i].sexo);
    }
}

