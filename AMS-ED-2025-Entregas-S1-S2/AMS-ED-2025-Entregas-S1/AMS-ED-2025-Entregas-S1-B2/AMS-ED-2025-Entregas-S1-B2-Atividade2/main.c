#include <stdio.h>


void bubbleSort(int num[], int qntd){
    int i, j, temp;

    for(i = 0; i < qntd - 1; i++){
        for(j = 0; j < qntd - 1 - i; j++){
            if(num[j] > num[j + 1]){
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int qntd;
    
    printf("Insira a quantidade de números que deseja ordenar:\n");
    scanf("%d", &qntd);
    
    int num[qntd];
    int indice;
    
    for(indice = 0; indice < qntd; indice++){
        printf("Nº %d: ", indice + 1);
        scanf("%d", &num[indice]);
    }
    
    printf("\nOs números inseridos antes da organização:\n");
    for(indice = 0; indice < qntd; indice++){
        printf("%d ", num[indice]);
    }
    
    bubbleSort(num, qntd);
    
    printf("\n\nOs números inseridos pós organização:\n");
    for(indice = 0; indice < qntd; indice++){
        printf("%d ", num[indice]);
    }

    return 0;
}
