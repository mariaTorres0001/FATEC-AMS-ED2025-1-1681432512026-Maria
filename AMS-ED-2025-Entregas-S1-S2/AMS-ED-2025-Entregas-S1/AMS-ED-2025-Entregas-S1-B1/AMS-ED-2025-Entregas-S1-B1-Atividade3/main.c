/*----------------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados                    */
/*                         Id da Atividade: Atividade B1-3                          */
/*             Objetivo: Criar um sistema de comandas			            */
/*                                                                                  */
/*                                  Autor: Maria Eduarda Torres Pereira             */
/*                                                                   Data:16/03/2025*/
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Comanda
{
    int num_pedido;
    char nome_cliente[100];
    char desc_prato[100];
    int qntd;
    char status_pedido[50];
    struct Comanda *prox;
} Comanda;

Comanda *criarLista()
{
    return NULL;
}

Comanda *inserirpedido(Comanda *lista, int num_pedido, const char *nome_cliente, const char *desc_prato, int qntd, const char *status_pedido)
{
    Comanda *novo = (Comanda *)malloc(sizeof(Comanda));
    if (!novo)
    {
        printf("Erro ao alocar memória.\n");
        return lista;
    }

    novo->num_pedido = num_pedido;
    strcpy(novo->nome_cliente, nome_cliente);
    strcpy(novo->desc_prato, desc_prato);
    novo->qntd = qntd;

    if (strcmp(status_pedido, "1") == 0)
    {
        strcpy(novo->status_pedido, "Pendente");
    }
    else if (strcmp(status_pedido, "2") == 0)
    {
        strcpy(novo->status_pedido, "Entregue");
    }
    else if (strcmp(status_pedido, "3") == 0)
    {
        strcpy(novo->status_pedido, "Cancelado");
    }
    else
    {
        strcpy(novo->status_pedido, "Desconhecido");
    }

    novo->prox = lista;
    return novo;

}

Comanda *obterpedido(Comanda *lista, int num_pedido)
{
    Comanda *atual = lista;
    while (atual != NULL)
    {
        if (atual->num_pedido == num_pedido)
        {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

void alterarStatus(Comanda *lista, int num_pedido, const char *status_novo)
{
    Comanda *atual = lista;
    while (atual != NULL)
    {
        if (atual->num_pedido == num_pedido)
        {
            if (strcmp(status_novo, "1") == 0)
            {
                strcpy(atual->status_pedido, "Pendente");
            }
            else if (strcmp(status_novo, "2") == 0)
            {
                strcpy(atual->status_pedido, "Entregue");
            }
            else if (strcmp(status_novo, "3") == 0)
            {
                strcpy(atual->status_pedido, "Cancelado");
            }
            else
            {
                printf("Status inválido.\n");
            }
            return;
        }
        atual = atual->prox;
    }
}

Comanda *deletarpedido(Comanda *lista, int num_pedido)
{
    Comanda *atual = lista;
    Comanda *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->num_pedido == num_pedido)
        {
            if (anterior == NULL)
            {
                lista = atual->prox;
            }
            else
            {
                anterior->prox = atual->prox;
            }
            free(atual);
            return lista;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Pedido não encontrado.\n");
    return lista;
}

void liberarlista(Comanda *lista)
{
    Comanda *atual = lista;
    Comanda *proximo;

    while (atual != NULL)
    {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}

int main()
{
    Comanda *lista = criarLista();

    int n_ped;
    char nm_cli[100];
    char desc_pt[100];
    int qtd;
    char status[10];
    int opcao = 6;

    while (opcao != 0)
    {
        
        printf("\n|============ MENU ============|\n");
        printf("| 1 - Inserir pedido           |\n");
        printf("| 2 - Alterar status do pedido |\n");
        printf("| 3 - Deletar pedido           |\n");
        printf("| 4 - Obter pedido             |\n");
        printf("| 0 - Sair                     |\n");
        printf("|==============================|\n\n");
        
        printf("Digite o número referente a tarefa: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        
            printf("\n======== Inserir Pedido ========\n");
            printf("Insira o número do pedido: ");
            scanf("%d", &n_ped);
            
            printf("Insira o nome do cliente: ");
            scanf("%s[^\n]", nm_cli);
            getchar();
            
            printf("Insira o nome do prato: ");
            scanf("%[^\n]", desc_pt);
            getchar();
            
            printf("Insira a quantidade: ");
            scanf("%d", &qtd);
            
            printf("Insira o status do pedido (1 - Pendente, 2 - Entregue, 3 - Cancelado): ");
            scanf("%s[^\n]", status);
            getchar();
            
            lista = inserirpedido(lista, n_ped, nm_cli, desc_pt, qtd, status);
            
            break;
            
            
        case 2:
        
            printf("\n=== Alterar Status do Pedido ===\n");
            printf("Digite o número do pedido: ");
            scanf("%d", &n_ped);
            
            printf("Insira o novo status (1 - Pendente, 2 - Entregue, 3 - Cancelado): ");
            scanf("%s", status);
            
            alterarStatus(lista, n_ped, status);
            
            break;
            
            
        case 3:
            printf("\n======== Deletar Pedido ========\n");
            printf("Digite o número do pedido: ");
            scanf("%d", &n_ped);
            
            lista = deletarpedido(lista, n_ped);
            
            break;
            
            
        case 4:
            printf("\n========= Obter Pedido =========\n");
            printf("Digite o número do pedido: ");
            scanf("%d", &n_ped);
            
            Comanda *pedido = obterpedido(lista, n_ped);
            
            if (pedido)
            {
                printf("\n========== PEDIDO Nº%d ========== \n", pedido->num_pedido);
                printf("Cliente: %s\n", pedido->nome_cliente);
                printf("Prato: %s\n", pedido->desc_prato);
                printf("Quantidade: %d\n", pedido->qntd);
                printf("Status: %s\n", pedido->status_pedido);
            }
            else
            {
                printf("\n Pedido não encontrado.\n");
            }
            
            break;
            
            
        case 0:
        
            printf("\n Saindo...\n");
            liberarlista(lista);
            break;
        
        default:
            printf("Opção inválida!\n");
        }
    }
    
    return 0;
    
}
