//--- AUTHOR ---//
/*
###################################
        GABRIEL F MAGALHAES
###################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 200

struct cliente {
    char nome[50];
    char escolaridade[20];
    float renda;
};

typedef struct cliente Cliente;

int Le_Vetores(Cliente cliente[MAX_CLIENTES], int *num){
    char c;
    do {
        printf("Digite o nome do cliente %d: ", *num+1);
        gets(cliente[*num].nome);

        printf("Digite a escolaridade do/da %s (Fundamental/Medio/Superior): ", cliente[*num].nome);
        gets(cliente[*num].escolaridade);

        printf("Digite a renda do/da %s: ", cliente[*num].nome);
        scanf("%f", &cliente[*num].renda);
        fflush(stdin);

        printf("\nDeseja cadastrar mais clientes? (C/c) para continuar ou qualquer tecla para parar: ");
        scanf("%c", &c);
        fflush(stdin);

        (*num)++;
    } while((c == 'c' || c == 'C') && *num < MAX_CLIENTES);
    return *num;
}

void Renda_Superior_5000(Cliente cliente[MAX_CLIENTES], Cliente nomes_5mil[MAX_CLIENTES], int num, int *cont) {
    int i;
    for(i = 0; i < num; i++) {
        if((strcmpi(cliente[i].escolaridade,"medio") == 0 )&& cliente[i].renda > 5000) {
           nomes_5mil[*cont] = cliente[i];
           (*cont)++;
        }
    }
    printf("\nNumero total de clientes com renda maior que 5.000,00 e escolaridade nivel medio: %d\n", *cont);
}

void Maior_e_Menor_Renda(Cliente cliente[MAX_CLIENTES], int num, int *pos_maior, int *pos_menor) {
    int i;
    float menor_renda, maior_renda;

    for(i = 0; i < num; i++) {
        if(i == 0){
            maior_renda = cliente[i].renda;
            *pos_maior = i;

            menor_renda = cliente[i].renda;
            *pos_menor = i;
        }
        else{
            if(menor_renda > cliente[i].renda){
                menor_renda = cliente[i].renda;
                *pos_menor = i;
            }
            if(maior_renda < cliente[i].renda){
                maior_renda = cliente[i].renda;
                *pos_maior = i;
            }
        }
    }
}

 void Exibe_Nomes(Cliente nomes_5mil[MAX_CLIENTES], int cont) {
    int i;
    if(cont > 0){
        printf("\n\nPessoas que possuem uma renda acima de 5.000,00 e nivel de escolaridade medio\n");
        for(i = 0; i < cont; i++) {
           printf("Nome: %s\n", nomes_5mil[i].nome);
        }
    }
    else {
       printf("\n\nNenhuma pessoa possui renda acima de 5.000,00 e nivel de escolaridade medio\n\n");
    }
 }
 int main()
 {
    Cliente cliente[MAX_CLIENTES];
    Cliente nomes_5mil[MAX_CLIENTES];

    int num; //TOTAL DE CLIENTES CADASTRADOS
    int cont; //TOTAL DE CLIENTES COM RENDA ACIMA DE 5 MIL e ESCOLARIDADE MEDIO
    int pos_maior, pos_menor;

    int *pNum;
    int *pCont;
    int *pPosMaior, *pPosMenor;

    pNum = &num;
    pCont = &cont;
    pPosMaior = &pos_maior;
    pPosMenor = &pos_menor;

    Le_Vetores(cliente, pNum);
    Renda_Superior_5000(cliente, nomes_5mil, num, pCont);
    Maior_e_Menor_Renda(cliente, num, pPosMaior, pPosMenor);
    printf("\nCliente com a maior renda na posicao: %d", pos_maior);
    printf("\nCliente com a menor renda na posicao: %d", pos_menor);
    Exibe_Nomes(nomes_5mil, cont);

    return 0;
}
