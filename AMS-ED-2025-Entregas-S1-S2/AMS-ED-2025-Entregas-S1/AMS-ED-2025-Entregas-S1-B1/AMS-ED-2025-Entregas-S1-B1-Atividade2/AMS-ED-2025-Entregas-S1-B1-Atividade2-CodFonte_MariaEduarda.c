/*----------------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados                    */
/*                         Id da Atividade: Atividade B1-2                          */
/*             Objetivo: Programa de  seleção para RESIDÊNCIA MÉDICA                */
/*                                                                                  */
/*                                  Autor: Maria Eduarda Torres Pereira             */
/*                                                                   Data:08/03/2025*/
/*----------------------------------------------------------------------------------*/

#include <stdio.h>

#define MAX_CANDIDATOS 50

//Isso aqui é a estrutura para guardar os dados do candidato :D
struct Cand {
    char nomeal[100];
    float ntPE[4];
    float ntAC[5];
    float ntPP[10];
    float ntEB[3];
    float ntfinal;
};

// Funçãozinha para calcular a média das notas centrais :D
float calcularNota(float *notas, int qtdnotas) {
    float soma = 0.0, maior = notas[0], menor = notas[0];
    
    for (int i = 0; i < qtdnotas; i++) {
        soma += notas[i]; //Lembrar que aqui soma todas as notas
        if (notas[i] > maior) maior = notas[i]; // aqui pega a maior nota
        if (notas[i] < menor) menor = notas[i]; // aqui pega a menor nota
    }
    
    return (soma - maior - menor) / (qtdnotas - 2);
}

void inserirCand(struct Cand *candidatos) {
    printf("Insira o nome do candidato: ");
    scanf(" %[^\n]", candidatos->nomeal);
    getchar();
    
    printf("\nDigite as 4 notas da Prova Escrita (PE):\n");
    for(int i = 0; i < 4; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &candidatos->ntPE[i]);
    }
    
    printf("\nDigite as 5 notas da Análise Curricular (AC):\n");
    for(int i = 0; i < 5; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &candidatos->ntAC[i]);
    }
    
    printf("\nDigite as 10 notas da Prova Prática (PP):\n");
    for(int i = 0; i < 10; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &candidatos->ntPP[i]);
    }
    
    printf("\nDigite as 3 notas da Entrevista em Banca (EB):\n\n");
    for(int i = 0; i < 3; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &candidatos->ntEB[i]);
    }
    
    float PE = calcularNota(candidatos->ntPE, 4);
    float AC = calcularNota(candidatos->ntAC, 5);
    float PP = calcularNota(candidatos->ntPP, 10);
    float EB = calcularNota(candidatos->ntEB, 3);
    
    candidatos->ntfinal = (PE * 0.3) + (AC * 0.1) + (PP * 0.4) + (EB * 0.2);
}



/*Funçãozinha para ordenar os candidatos pela nota final :D
Como funciona:
Ao verificar cada um dos candidatos em cada vetor, vendo se a nota final 
do candidato sucessor é maior ou menor que ele...
Caso for menor, haverá uma troca nos indices.
temp para armazenar temporariamente o candidato atual
candidato[j] é substituido pelo candidato[j + 1]
e o candidato[j + 1] é substituido pelo temp

Esse processo se repete com a quantidade de candidatos inseridos
*/ 
void ordenarCandidatos(struct Cand *candidatos, int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (candidatos[j].ntfinal < candidatos[j + 1].ntfinal) {
                struct Cand temp = candidatos[j];
                candidatos[j] = candidatos[j + 1];
                candidatos[j + 1] = temp;
            }
        }
    }
}

// Funçãozinha para mostrar os TOP 5 candidatos :D
void top5(struct Cand *candidatos, int total) {
    int qtd = (total < 5) ? total : 5;
    printf("\n===== TOP %d Candidatos =====\n", qtd);
    for (int i = 0; i < qtd; i++) {
        printf("\n%dº Lugar: %s", i + 1, candidatos[i].nomeal);
        printf("\nNota Final: %.2f\n", candidatos[i].ntfinal);
    }
}

int main() {
    struct Cand candidatos[MAX_CANDIDATOS];
    int totalCan;

    printf("Quantos candidatos deseja inserir? (Max. %d): ", MAX_CANDIDATOS);
    scanf("%d", &totalCan);

    if (totalCan > MAX_CANDIDATOS)
    {
        printf("Número de candidatos inválido!!!");
    }
    else
    {
        for (int i = 0; i < totalCan; i++) {
        printf("\n== Candidato %d ==\n", i + 1);
        inserirCand(&candidatos[i]);
    }
    
    ordenarCandidatos(candidatos, totalCan);
    top5(candidatos, totalCan);
    
    }
    
    return 0;
}
