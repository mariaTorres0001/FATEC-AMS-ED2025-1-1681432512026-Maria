#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
 
#define TAMANHO 5
/*
*---------------------------------------------------------------------*
*              FATEC-São Caetano do Sul                               *
*              Estrutura de Dados                                     *
*              Id da Atividade: Exemplo-Fila                          *
*              Objetivo: Demonstrar a implementação de fila           *
*                                                                     *
*              Autor: Maria Eduarda Torres Pereira                    *
*              Data: 22/04/2025                                       *
*---------------------------------------------------------------------*/
 
struct tfila {
    int dados[TAMANHO];
    int ini;
    int fim;
};
 
struct tfila fila;
int op;
 
/*
*---------------------------------------------------------------------*
*                    Procedure principal                              *
*---------------------------------------------------------------------*/
 
int main(){
    op = 1;
    fila.ini = 0;
    fila.fim = 0;
 
    while (op != 0) {
        system("cls");
        fila_mostrar();
        menu_mostrar();
    } //Saida do loop while
    return(0);
}
 
 
/*---------------------------------------------------------------------*
*        Adicionar um elemento no final da Fila                       *
*---------------------------------------------------------------------*/
 
void Inserir_Fila(){
    if (verificaFilaCheia() == 1){
        printf("\nA fila está cheia, volte outro dia!\n\n");
        exit(1);
    } else {
        fila.dados[fila.fim] = obterDadosTela();
        fila.fim++;
    }
}
 
/*---------------------------------------------------------------------*
*        Retirar o primeiro elemento da Fila                          *
*---------------------------------------------------------------------*/
 
void excluir_Fila() {
    if (verificaFilaVazia() == 1){
        printf("\nFila vazia...\n\n");
        exit(1);
    } else {
        int i;
        for (i = 0; i < TAMANHO; i++)
            fila.dados[i] = fila.dados[i + 1];
 
        fila.dados[fila.fim] = 0;
        fila.fim--;
    }
}
 
/*---------------------------------------------------------------------*
*        Mostrar o conteúdo da Fila                                   *
*---------------------------------------------------------------------*/
 
void fila_mostrar() {
    int i;
    printf("[ ");
    for (i = 0; i < TAMANHO; i++)
        printf("%d ", fila.dados[i]);
    printf("]\n\n");
}
 
/*---------------------------------------------------------------------*
*        Mostrar o menu de opções                                     *
*---------------------------------------------------------------------*/
 
void menu_mostrar() {
    printf("\nEscolha uma opção:\n");
    printf("1 - Incluir na Fila\n");
    printf("2 - Excluir da Fila\n");
    printf("0 - Sair\n\n");
    scanf("%d", &op);
        switch (op) {
        case 1:
            Inserir_Fila();
            break;
        case 2:
            excluir_Fila();
            break;
        } //Saida do switch
}
 
/*---------------------------------------------------------------------*
*        Solicitar dados de entrada                                   *
*---------------------------------------------------------------------*/
 
int obterDadosTela(){
    int dadoInformado;
    printf("\nDigite o valor a ser inserido: ");
    scanf("%d", &dadoInformado);
    return dadoInformado;
}
 
int verificaFilaCheia(){
    if (fila.fim == TAMANHO){
        return 1;
    } else {
        return 0;
    }
}
 
int verificaFilaVazia(){
    if (fila.ini == fila.fim){
        return 1;
    } else {
        return 0;
    }
}