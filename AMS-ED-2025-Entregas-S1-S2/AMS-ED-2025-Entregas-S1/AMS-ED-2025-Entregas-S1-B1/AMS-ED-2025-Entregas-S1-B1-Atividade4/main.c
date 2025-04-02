/*----------------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados                    */
/*                         Id da Atividade: Atividade B1-4                          */
/*             Objetivo: Calcular RPN (Notão polonesa reversa)                      */
/*                                                                                  */
/*                                  Autor: Maria Eduarda Torres Pereira             */
/*                                                                   Data:31/03/2025*/
/*----------------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 4 

typedef struct {
    double itens[MAX];
    int topo;
} Pilha;


Pilha *criar_pilha() {
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

int cheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void push(Pilha *p, double dado) {
    if (cheia(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->itens[++p->topo] = dado;
}

double pop(Pilha *p) {
    if (vazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return 0;
    }
    return p->itens[p->topo--];
}

double top(Pilha *p) {
    if (vazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return 0;
    }
    return p->itens[p->topo];
}


double calcular_rpn(char *rpn, char *saida) {
    Pilha *pilha = criar_pilha();
    char *separador = strtok(rpn, " ");
    char operacao[100] = "";
    double x, y, resultado;

    while (separador != NULL) {
        if (isdigit(separador[0]) || (separador[0] == '-' && isdigit(separador[1]))) {
            double numero = atof(separador);
            push(pilha, numero);
            sprintf(operacao + strlen(operacao), "%.2f ", numero);
        } else {
            if (pilha->topo < 1) {
                printf("Erro: Expressão inválida!\n");
                return 0;
            }
            x = pop(pilha);
            y = pop(pilha);

            switch (separador[0]) {
                case '+': resultado = x + y; break;
                case '-': resultado = x - y; break;
                case '*': resultado = x * y; break;
                case '/': 
                    if (y == 0) {
                        printf("Erro: Divisão por zero!\n");
                        return 0;
                    }
                    resultado = x / y;
                    break;
                default:
                    printf("Erro: Operador inválido!\n");
                    return 0;
            }
            push(pilha, resultado);
            sprintf(operacao + strlen(operacao), "(%.2f %c %.2f) ", x, separador[0], y);
        }
        separador = strtok(NULL, " ");
    }

    if (pilha->topo != 0) {
        printf("Erro: Expressão inválida!\n");
        return 0;
    }

    resultado = pop(pilha);
    strcpy(saida, operacao);
    free(pilha);
    return resultado;
}

int main() {
    char rpn[100], saida[100];
    printf("Digite a expressão em Notação Polonesa Inversa (RPN) utilizando espaço para cada operado e operador: ");
    fgets(rpn, 100, stdin);
    rpn[strcspn(rpn, "\n")] = 0;

    double resultado = calcular_rpn(rpn, saida);
    printf("Resultado: %.2f\n", resultado);
    printf("Fórmula algébrica: %s\n", saida);
    return 0;
}