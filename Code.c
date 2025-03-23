#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define qttdPessoas 20

int cadastro = 0;
typedef struct {
    int birthDay;
    int birthMonth;
    int birthYear;
} nasc;

typedef struct {
    int id;
    char name[50];
    char sexo[20];
    int age;
    nasc birthDate;
} pessoa;

pessoa pessoas[qttdPessoas];

void menuAtualizar();
void alterarIdade(pessoa *c);
void alterarSexo(pessoa *c);
void alterarNome(pessoa *c);
void alterarDataNasc(pessoa *c);
void mostrarMenu();
void cadastrarPessoa(pessoa *c);
void salvarArquivo(pessoa *c);
void exibirPessoa(pessoa *c);
void lerArquivo(pessoa *c);
void excluirCadastro(pessoa *c);
void atualizarCadastro(pessoa *c);

int main(){
    int option = -1;
    while(option != 0){
        mostrarMenu();
        scanf("%d", &option);
        switch(option){
            case 1: 
                cadastrarPessoa(pessoas);
                break;
            case 2:
                exibirPessoa(pessoas);
                break;
            case 3:
                excluirCadastro(pessoas);
                break;
            case 4:
                atualizarCadastro(pessoas);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default: 
                printf("Opcao Invalida! Informe um caractere valido.\n");
                break;
        }
    }
    return 0;
}

void cadastrarPessoa(pessoa *c) {
    lerArquivo(c);
    if (cadastro >= qttdPessoas) {
        printf("Limite de cadastros atingido!\n");
        return;
    }

    system("cls");

    printf("Cadastro ID - %d:\n", cadastro + 1); // Registra o ID da Pessoa
        c[cadastro].id = cadastro + 1;

    printf("Informe o nome:\n"); // Registra o nome do Pessoa
        scanf(" %49[^\n]s", c[cadastro].name);
        getchar();

    printf("Informe a Data de Nascimento:\n"); // Registra a data de nascimento
    do{
        printf("Dia:");
        scanf("%i", &c[cadastro].birthDate.birthDay); // Recebe o dia de nascimento e valida se esta dentro de 0 a 31 dias
        getchar();
        if(c[cadastro].birthDate.birthDay < 0 || c[cadastro].birthDate.birthDay > 31){
            printf("Dia de nascimento invalido! Informe uma data valida!\n"); 
        } 
    } while (c[cadastro].birthDate.birthDay < 0 || c[cadastro].birthDate.birthDay > 31); 
        printf("Mes:");
        scanf("%i", &c[cadastro].birthDate.birthMonth); // Recebe o mes de nascimento e valida se esta dentro de 0 a 12 meses
        do{
        getchar();
        if(c[cadastro].birthDate.birthMonth < 0 || c[cadastro].birthDate.birthMonth > 12){ 
            printf("Mes de nascimento invalido! Informe uma data valida!\n"); 
        } 
    } while (c[cadastro].birthDate.birthMonth < 0 || c[cadastro].birthDate.birthMonth > 12); 

    do{
        printf("Ano:");
        scanf("%i", &c[cadastro].birthDate.birthYear); // Recebe o ano de nascimento e valida se esta dentro de 1900 a 2025
        getchar();
        if((c[cadastro].birthDate.birthYear < 1900) || (c[cadastro].birthDate.birthYear > 2025)){
            printf("Ano de nascimento invalido! Informe uma data valida!\n"); 
        } 
    } while (c[cadastro].birthDate.birthYear < 1900 || c[cadastro].birthDate.birthYear > 2025);

    do {
        printf("Informe a idade:\n");
        scanf("%i", &c[cadastro].age);
        getchar();
        if((c[cadastro].age > 120) || (c[cadastro].age < 0)){ 
            printf("Idade invalida! Informe uma idade valida!\n");
        }
    } while (c[cadastro].age > 120 || c[cadastro].age < 0);

    printf("Selecione o novo sexo da pessoa [M]Masculino [F]Feminino [O]Nao Informar: ");
    char condition;
    scanf(" %c", &condition); 
    
    switch (condition) {
        case 'M':
            strcpy(c[cadastro].sexo, "Masculino");
            break;
        case 'F':
            strcpy(c[cadastro].sexo, "Feminino");
            break;
        case 'O':
            strcpy(c[cadastro].sexo, "Nao Informado");
            break;
        default:
            strcpy(c[cadastro].sexo, "Nao Informado");
            break;
    }
    cadastro++;
    salvarArquivo(pessoas);
    system("cls");
}

void exibirPessoa(pessoa *c) {
    lerArquivo(c);
    if (cadastro == 0) {
        printf("Nenhum cadastro realizado!\n");
        return;
    }
    lerArquivo(c);
    for(int i = 0; i < cadastro; i++) {
        printf("\nCadastro ID - %i:\n", i + 1);
        printf("Nome: %s\n", c[i].name);
        printf("Data de nascimento: %d/%d/%d\n", c[i].birthDate.birthDay, c[i].birthDate.birthMonth, c[i].birthDate.birthYear);
        printf("Idade: %d Anos\n", c[i].age);
        printf("Sexo: %s\n", c[i].sexo);
    }
}

void excluirCadastro(pessoa *c) {
    int idProcurado;
    lerArquivo(c);
    int qttdExcluir;
    if(cadastro <= 0){
        printf("Sem registros para exclusao!\n");
        return;
    }
    printf("Informe a quantidade de registros que deseja excluir:\n");
    scanf("%i", &qttdExcluir);

    if(qttdExcluir > cadastro){
        printf("Nao e possivel excluir esta quantidade de registros! Quantidade de cadastros menor que a informada!\n"); 
    } else { 
        for(int exc = 0; exc < qttdExcluir; exc++){
            printf("Digite o ID do cadastro que deseja excluir: \n");
            scanf("%d", &idProcurado);
    int encontrado = 0;

    for (int i = 0; i < cadastro; i++) {
        if (c[i].id == idProcurado) {
            for (int j = i; j < cadastro - 1; j++) {
                c[j] = c[j + 1];
                c[j].id = j + 1; 
            }
            cadastro--;
            salvarArquivo(pessoas);
            printf("Cadastro excluido com sucesso!\n\n");
            encontrado = 1;
            break;
            }
        }

            if (encontrado == 0) {
                printf("Item com o ID %d nao encontrado nos cadastros.\n\n", idProcurado);
            }
        }
    }
}

void atualizarCadastro(pessoa *c) {
    int option;
    int idProcurado;
    menuAtualizar();
    scanf(" %i", &option);
    switch (option){

    case 1:
    lerArquivo(c);
    printf("Digite o ID do cadastro que deseja atualizar: ");
    scanf("%d", &idProcurado);

    int encontrado = 0;
    for (int i = 0; i < cadastro; i++) {
        if (c[i].id == idProcurado) {
            printf("Novo nome: ");
            scanf(" %[^\n]", c[i].name);
            salvarArquivo(pessoas);
            
            printf("Selecione o novo sexo da pessoa [M]Masculino [F]Feminino [O]Outro: ");
            char condition;
            scanf(" %c", &condition); 
            
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
            salvarArquivo(pessoas);
            do{
                printf("Informe a nova idade:\n");
                scanf("%i", &c[i].age);
                salvarArquivo(pessoas);
                getchar();
                if((c[cadastro].age > 120) || (c[cadastro].age < 0)){
                    printf("Idade invalida! Informe uma idade valida!\n");
                }
            } while (c[cadastro].age > 120 || c[cadastro].age < 0);

            printf("Informe a nova Data de Nascimento:\n");
            do{
                printf("Dia:");
                scanf("%i", &c[i].birthDate.birthDay);
                salvarArquivo(pessoas);
                getchar();
                if(c[cadastro].birthDate.birthDay < 0 || c[cadastro].birthDate.birthDay > 31){
                    printf("Dia de nascimento invalido! Informe uma data valida!\n"); 
                } 
            } while (c[cadastro].birthDate.birthDay < 0 || c[cadastro].birthDate.birthDay > 31);
            salvarArquivo(pessoas);
            do{
                printf("Mes:");
                scanf("%i", &c[i].birthDate.birthMonth);
                salvarArquivo(pessoas);
                getchar();
                if(c[cadastro].birthDate.birthMonth < 0 || c[cadastro].birthDate.birthMonth > 12){
                    printf("Mes de nascimento invalido! Informe uma data valida!\n"); 
                } 
            } while (c[cadastro].birthDate.birthMonth < 0 || c[cadastro].birthDate.birthMonth > 12);
            do{
                printf("Ano:");
                scanf("%i", &c[i].birthDate.birthYear);
                salvarArquivo(pessoas);
                getchar();
                if((c[i].birthDate.birthYear < 1900) || (c[i].birthDate.birthYear > 2025)){
                    printf("Ano de nascimento invalido! Informe uma data valida!\n"); 
                } 
            } while (c[i].birthDate.birthYear < 1900 || c[i].birthDate.birthYear > 2025);

            printf("Cadastro atualizado com sucesso!\n\n");
            encontrado = 1;
            break;
        }
        salvarArquivo(pessoas);
    }

    if (encontrado == 0) {
        printf("Cadastro com o ID %d nao encontrado nos registros.\n\n", idProcurado);
    }
        break;
    case 2: 
    alterarDataNasc(pessoas);
    break;

    case 3:
    alterarNome(pessoas);
    break;

    case 4:
    alterarSexo(pessoas);
    break;

    case 5:
    alterarIdade(pessoas);
    break;
    case 0:
    printf("Retornando ao menu...");
        break;

    default:
    printf("Opcao invalida! Retornando ao menu!\n");
        break;
    }

}

void mostrarMenu() {

    printf("\n\t|=======================|\n");
    printf("\t|MENU:                  |\n");
    printf("\t|[1] Adicionar Cadastro |\n");
    printf("\t|[2] Listar Cadastros   |\n");
    printf("\t|[3] Excluir Cadastro   |\n");
    printf("\t|[4] Atualizar Cadastro |\n");
    printf("\t|[0] Sair               |\n");
    printf("\t|=======================|\n");
    printf("\tEscolha uma opcao>> \n\n");
}

void salvarArquivo(pessoa *c) {
    FILE *arq = fopen("cadastros.txt", "w+");
    if (arq) {
        for (int i = 0; i < cadastro; i++) {
            fprintf(arq, "ID: %d\n", c[i].id);
            fprintf(arq, "Nome: %s\n", c[i].name);
            fprintf(arq, "Data de Nascimento: %d/%d/%d\n", c[i].birthDate.birthDay, c[i].birthDate.birthMonth, c[i].birthDate.birthYear);
            fprintf(arq, "Idade: %d\n", c[i].age);
            fprintf(arq, "Sexo: %s\n", c[i].sexo);
            fprintf(arq, "\n-------------------------\n");
        }
        fclose(arq);
    } else {
        printf("ERRO: Não foi possível abrir o arquivo.\n\n");
    }
}

void lerArquivo(pessoa *c) {
    FILE *arq = fopen("cadastros.txt", "r");
    cadastro = 0; 
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo 'cadastros.txt'!\n");
        return;
    } 
    while (fscanf(arq, "ID: %d\n", &c[cadastro].id) == 1) {
        fscanf(arq, "Nome: %49[^\n]\n", c[cadastro].name);
        fscanf(arq, "Data de Nascimento: %d/%d/%d\n", &c[cadastro].birthDate.birthDay, &c[cadastro].birthDate.birthMonth, &c[cadastro].birthDate.birthYear);
        fscanf(arq, "Idade: %d\n", &c[cadastro].age);
        fscanf(arq, "Sexo: %19[^\n]\n", c[cadastro].sexo);
        fscanf(arq, "\n-------------------------\n");

        cadastro++; 

        if (cadastro >= qttdPessoas) {
            break;
        }
    }
    fclose(arq);
}

void alterarIdade(pessoa *c){
    int idProcurado;
    lerArquivo(c);
    printf("Digite o ID do cadastro que deseja atualizar: ");
    scanf("%d", &idProcurado);

    int encontrado = 0;
    for (int i = 0; i < cadastro; i++) {
        if (c[i].id == idProcurado) {

            do{
                printf("Informe a nova idade:\n");
                scanf("%i", &c[i].age);
                salvarArquivo(pessoas);
                getchar();
                if((c[cadastro].age > 120) || (c[cadastro].age < 0)){
                    printf("Idade invalida! Informe uma idade valida!\n");
                }
            } while (c[cadastro].age > 120 || c[cadastro].age < 0);

            printf("Cadastro atualizado com sucesso!\n\n");
            encontrado = 1;
            break;
        }
    }
    if (encontrado == 0) {
        printf("Cadastro com o ID %d nao encontrado nos registros.\n\n", idProcurado);
    }

}

void alterarDataNasc(pessoa *c){
    int idProcurado;
    lerArquivo(c);
    printf("Digite o ID do cadastro que deseja atualizar: ");
    scanf("%d", &idProcurado);

    int encontrado = 0;
    for (int i = 0; i < cadastro; i++) {
        if (c[i].id == idProcurado) {
            
            do{
                printf("Dia:");
                scanf("%i", &c[i].birthDate.birthDay);
                salvarArquivo(pessoas);
                getchar();
                if(c[cadastro].birthDate.birthDay < 0 || c[cadastro].birthDate.birthDay > 31){
                    printf("Dia de nascimento invalido! Informe uma data valida!\n"); 
                } 
            } while (c[cadastro].birthDate.birthDay < 0 || c[cadastro].birthDate.birthDay > 31);
            do{
                printf("Mes:");
                scanf("%i", &c[i].birthDate.birthMonth);
                salvarArquivo(pessoas);
                getchar();
                if(c[cadastro].birthDate.birthMonth < 0 || c[cadastro].birthDate.birthMonth > 12){
                    printf("Mes de nascimento invalido! Informe uma data valida!\n"); 
                } 
            } while (c[cadastro].birthDate.birthMonth < 0 || c[cadastro].birthDate.birthMonth > 12);
            do{
                printf("Ano:");
                scanf("%i", &c[i].birthDate.birthYear);
                salvarArquivo(pessoas);
                getchar();
                if((c[cadastro].birthDate.birthYear < 1900) || (c[cadastro].birthDate.birthYear > 2025)){
                    printf("Ano de nascimento invalido! Informe uma data valida!\n"); 
                } 
            } while (c[cadastro].birthDate.birthYear < 1900 || c[cadastro].birthDate.birthYear > 2025);
            printf("Cadastro atualizado com sucesso!\n\n");
            encontrado = 1;
            break;
        }
    }
    if (encontrado == 0) {
        printf("Cadastro com o ID %d nao encontrado nos registros.\n\n", idProcurado);
    }
}

void alterarNome(pessoa *c){
    int idProcurado;
    lerArquivo(c);
    printf("Digite o ID do cadastro que deseja atualizar: ");
    scanf("%d", &idProcurado);

    int encontrado = 0;
    for (int i = 0; i < cadastro; i++) {
        if (c[i].id == idProcurado) {
            
            printf("Novo nome: ");
            scanf(" %[^\n]", c[i].name);
            salvarArquivo(pessoas);
            printf("Cadastro atualizado com sucesso!\n\n");
            encontrado = 1;
            break;
        }
    }
    if (encontrado == 0) {
        printf("Cadastro com o ID %d nao encontrado nos registros.\n\n", idProcurado);
    }

}

void alterarSexo(pessoa *c){
    int idProcurado;
    lerArquivo(c);
    printf("Digite o ID do cadastro que deseja atualizar: ");
    scanf("%d", &idProcurado);

    int encontrado = 0;
    for (int i = 0; i < cadastro; i++) {
        if (c[i].id == idProcurado) {
            
            printf("Selecione o novo sexo da pessoa [M]Masculino [F]Feminino [O]Outro: ");
            char condition;
            scanf(" %c", &condition); 
            
            switch (condition) {
                case 'M':
                    strcpy(c[i].sexo, "Masculino");
                    salvarArquivo(pessoas);
                    break;
                case 'F':
                    strcpy(c[i].sexo, "Feminino");
                    salvarArquivo(pessoas);
                    break;
                case 'O':
                    strcpy(c[i].sexo, "Outro");
                    salvarArquivo(pessoas);
                    break;
                default:
                    strcpy(c[i].sexo, "Nao Informado");
                    salvarArquivo(pessoas);
                    break;
            }
            printf("Cadastro atualizado com sucesso!\n\n");
            encontrado = 1;
            break;
        }
    }
    if (encontrado == 0) {
        printf("Cadastro com o ID %d nao encontrado nos registros.\n\n", idProcurado);
    }
}

void menuAtualizar(){
    printf("\n\t|==================================|\n");
    printf("\t|Qual informacao deseja alterar?   |\n");
    printf("\t|[1] Todo o cadastro               |\n");
    printf("\t|[2] Data de nascimento do cadastro|\n");
    printf("\t|[3] Nome do cadastro              |\n");
    printf("\t|[4] Sexo do cadastro              |\n");
    printf("\t|[5] Idade do cadastro             |\n");
    printf("\t|[0] Sair                          |\n");
    printf("\t|==================================|\n");
    printf("\tEscolha uma opcao>> \n\n");
}
