#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



// cadastrar, alterar, excluir, exibir
int c = 0;
char limpar;


typedef struct{
    char cod[8];
    char rua[50];
    char bairro[30];
    int numero;
    char cidade[20];

} Endereco;

typedef struct{
    int cod;
    char nome[50];
    char cpf [11];
    Endereco end;

}Cliente;

int menu(void){
    int opcao;
    do{
        printf("1 - Cadastrar\n");
        printf("2 - Editar\n");
        printf("3 - Buscar\n");
        printf("4 - Exibir\n");
        printf("5 - Excluir\n");
        printf("6 - Sair\n");

        printf("Digite a opcao: ");
        scanf("%i", &opcao);

    }while(opcao < 1 || opcao > 7);

    return opcao;
}

int cadastrar (int c, Cliente cli[]){ //funfando
    int x, i, y = 1;
    printf("Quantos cadastros deseja efetuar: ");
    scanf("%i", &x);

    for(i = c; i < c+x; i++){
//        for(int j = 0; j <= i; j++){
//
//            do{
//                printf("\n\nDigite o codigo do cliente: ");
//                scanf("%i", &cli[i].cod);
//            }while(cli[i].cod <= 0 && cli[i].cod == cli[j].cod);
//        }

        cli[i].cod = y;
        printf("\n\nCodigo do cliente: %i\n", y);
        y++;

        printf("Digite o nome do cliente: ");
        fflush(stdin);
        gets(cli[i].nome);
        fflush(stdin);

        printf("Digite o CPF: ");
        fflush(stdin);
        gets(cli[i].cpf);
        fflush(stdin);

        printf("Digite o CEP: ");
        gets(cli[i].end.cod);

        printf("Digite a rua: ");
        fflush(stdin);
        gets(cli[i].end.rua);


        printf("Digite o bairro: ");
        fflush(stdin);
        gets(cli[i].end.bairro);


        printf("Digite o numero: ");
        scanf("%i", &cli[i].end.numero);

        printf("Digite a cidade: ");
        fflush(stdin);
        gets(cli[i].end.cidade);

    }
    return i;

}

void exibirTodos (Cliente cli[]){ // funfando

    printf("\n\n");
    for(int i = 0; i < 100; i++){

        if(cli[i].cod != 0){


            //printf("Posicao vetor: %i\n", i);
            printf("Cod: %i \nNome: %s \nCPF: %s\nCEP: %s\nRua: %s\nBairro: %s\nNumero: %i\nCidade: %s\n\n\n", cli[i].cod, cli[i].nome, cli[i].cpf, cli[i].end.cod, cli[i].end.rua, cli[i].end.bairro, cli[i].end.numero, cli[i].end.cidade);

        }
    }

    fflush(stdin);
    scanf("%c", &limpar);

}

void editar (Cliente cli[]){ // funfando
    int x = 0, ed = 0, i;
    bool achou = false;

    for(i = 0; i < 100; i++){
        do{
            printf("Digite o codigo do usuario que deseja alterar:");
            scanf("%i", &x);

            if(cli[i].cod == x){
                achou = true;
            }

        }while(x < 0 && achou == false);

        if(cli[i].cod == x){
            do{

                printf("\n\n1 - Codigo\n");
                printf("2 - Nome\n");
                printf("3 - CPF\n");
                printf("4 - Endereco\n");
                printf("5 - Sair\n");
                printf("O que deseja editar: ");
                scanf("%i", &ed);

                switch(ed){

                    case 1:
                        printf("\n\nDigite o novo codigo: ");
                        scanf("%i", &cli[i].cod);
                        break;
                    case 2:
                        printf("Digite o novo nome: ");
                        fflush(stdin);
                        gets(cli[i].nome);
                        break;
                    case 3:
                        printf("Digite o novo CPF: ");
                        fflush(stdin);
                        gets(cli[i].cpf);
                        break;
                    case 4:
                        printf("Digite o novo CEP: ");
                        fflush(stdin);
                        gets(cli[i].end.cod);

                        printf("Digite o nova Rua: ");
                        fflush(stdin);
                        gets(cli[i].end.rua);

                        printf("Digite o bairro: ");
                        fflush(stdin);
                        gets(cli[i].end.bairro);

                        printf("Digite o novo numero: ");
                        scanf("%i", &cli[i].end.numero);

                        printf("Digite a nova cidade: ");
                        fflush(stdin);
                        gets(cli[i].end.cidade);
                        break;

                }



            }while(ed != 5);


        }
        break;
    }

     system("cls");
    buscar(i, cli);


}


void buscar (int i, Cliente cli[]){ //funfando
    bool achei = false;
    int a, x;
    for(int j = 0; j < 100; j++){
        if(cli[j].cod == i){
            achei = true;
            printf("--------------Resultado busca----------------\n");
            printf("Cod: %i \nNome: %s \nCPF: %s\nCEP: %s\nRua: %s\nBairro: %s\nNumero: %i\nCidade: %s\n\n\n", cli[j].cod, cli[j].nome, cli[j].cpf, cli[j].end.cod, cli[j].end.rua, cli[j].end.bairro, cli[j].end.numero, cli[j].end.cidade);
            break;
        }
    }

    if(!achei){
        printf("Codigo nao encontrado\n\n");
        printf("Ver clientes cadastrados: \t1 - Sim\t2 - Nao\n");

        scanf("%i", &a);


        if(a == 1){
            system("cls");
            exibirTodos(cli);
        }

    }

    fflush(stdin);
    scanf("%c", &limpar);



}

int excluir (Cliente cli[]){ // funfando

    int x, i;
    printf("Digite o codigo do cliente que deseja excluir: ");
    scanf("%i", &x);

    for(i = 0; i < 100; i++){

        if(cli[i].cod == x){

            for(int j = i+1; j < 100; j++){
                cli[j-1] = cli[j];
            }
        }
    }

    c--;

    return c;

}

int main(){

    Cliente cli[100];


    for(int i = 0; i < 100; i++){
        cli[i].cod = 0;
    }

    int op,x;

do{
    op = menu();
    switch (op) {

        case 1:
            system("cls");
            c = cadastrar(c, cli);
            break;


        case 2:
            system("cls");
            editar(cli);
            break;

        case 3:
            system("cls");
            printf("\nDigite o codigo do produto para buscar: ");
            scanf("%i", &x);
            for(int i = 0; i < 100; i++){
                if(cli[i].cod == x){
                    break;
                }
            }
            buscar(x, cli);
            break;

        case 4:
            system("cls");
            exibirTodos(cli);
            break;

        case 5:
            system("cls");
            c = excluir(cli);
            break;

    }

    system("cls");

}while (op != 6);

    return 0;
}



