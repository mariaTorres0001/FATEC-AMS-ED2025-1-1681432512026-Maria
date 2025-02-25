#include <stdio.h>

void aplicadesc(float *ptrvlrprod, float *ptrvlrprodcdesc, float *ptrporcdesc)
{
    *ptrvlrprodcdesc = *ptrvlrprod * (1 - (*ptrporcdesc / 100));
}

int main()
{

    float vlrprod, vlrprodcdesc, porcdesc;
    char rsp;

    printf("Insira o valor do produto: ");
    scanf("%f", &vlrprod);

    printf("Deseja aplicar algum desconto ao valor do produto? (s/n)");
    scanf(" %c", &rsp);

    if (rsp == 's' || rsp == 'S')
    {
        printf("Aplique o porcentual do desconto (não é necessário o '%'): ");
        scanf("%f", &porcdesc);

        aplicadesc(&vlrprod, &vlrprodcdesc, &porcdesc);

        printf("Valor original do produto: R$%.2f\n", vlrprod);

        printf("Valor com o desconto: R$%.2f\n", vlrprodcdesc);

        printf("Desconto de: %.0f", porcdesc);
        
        printf("%\n");
    }
    else if (rsp == 'n' || rsp == 'N')
    {
        printf("Valor original do produto: R$%.2f\n", vlrprod);
    }
    else
    {
        printf("Resposta inválida!!!");
    }

    return 0;
}
