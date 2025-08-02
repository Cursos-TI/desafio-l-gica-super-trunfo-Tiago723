#include <stdio.h>
#include <string.h>

#define MAX 50

// Estrutura de uma carta
typedef struct {
    char estado[MAX];
    int codigo;
    char cidade[MAX];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

// Função para cadastrar carta
void cadastrarCarta(Carta *carta) {
    printf("\n=== Cadastro de Carta ===\n");
    printf("Estado: ");
    scanf(" %[^\n]", carta->estado);
    printf("Código da carta: ");
    scanf("%d", &carta->codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta->cidade);
    printf("População: ");
    scanf("%d", &carta->populacao);
    printf("Área (km²): ");
    scanf("%f", &carta->area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta->pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

// Função para exibir carta
void exibirCarta(Carta carta) {
    printf("\n--- Carta ---\n");
    printf("Estado: %s\n", carta.estado);
    printf("Código: %d\n", carta.codigo);
    printf("Cidade: %s\n", carta.cidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
}

// Nível Novato - comparação simples
void compararSimples(Carta c1, Carta c2, int atributo) {
    printf("\nComparando com base no atributo selecionado...\n");
    switch (atributo) {
        case 1: // População
            if (c1.populacao > c2.populacao)
                printf("Vencedor: %s (Maior população)\n", c1.cidade);
            else if (c2.populacao > c1.populacao)
                printf("Vencedor: %s (Maior população)\n", c2.cidade);
            else
                printf("Empate na população!\n");
            break;
        case 2: // Área
            if (c1.area > c2.area)
                printf("Vencedor: %s (Maior área)\n", c1.cidade);
            else if (c2.area > c1.area)
                printf("Vencedor: %s (Maior área)\n", c2.cidade);
            else
                printf("Empate na área!\n");
            break;
        case 3: // PIB
            if (c1.pib > c2.pib)
                printf("Vencedor: %s (Maior PIB)\n", c1.cidade);
            else if (c2.pib > c1.pib)
                printf("Vencedor: %s (Maior PIB)\n", c2.cidade);
            else
                printf("Empate no PIB!\n");
            break;
        case 4: // Pontos turísticos
            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("Vencedor: %s (Mais pontos turísticos)\n", c1.cidade);
            else if (c2.pontosTuristicos > c1.pontosTuristicos)
                printf("Vencedor: %s (Mais pontos turísticos)\n", c2.cidade);
            else
                printf("Empate nos pontos turísticos!\n");
            break;
        case 5: { // Densidade Populacional
            float dens1 = c1.populacao / c1.area;
            float dens2 = c2.populacao / c2.area;
            if (dens1 < dens2)
                printf("Vencedor: %s (Menor densidade populacional)\n", c1.cidade);
            else if (dens2 < dens1)
                printf("Vencedor: %s (Menor densidade populacional)\n", c2.cidade);
            else
                printf("Empate na densidade populacional!\n");
            break;
        }
        default:
            printf("Atributo inválido.\n");
    }
}

// Nível Mestre - comparação dupla com operador ternário
void compararDupla(Carta c1, Carta c2, int atr1, int atr2) {
    printf("\n=== Comparação Avançada ===\n");
    int pontos1 = 0, pontos2 = 0;

    // Função auxiliar usando operador ternário
    int compara(float a, float b, int invertido) {
        return invertido ? (a < b ? 1 : (a > b ? -1 : 0)) : (a > b ? 1 : (a < b ? -1 : 0));
    }

    float v1a = 0, v2a = 0;
    float v1b = 0, v2b = 0;
    int inv1 = 0, inv2 = 0;

    // Primeiro atributo
    switch (atr1) {
        case 1: v1a = c1.populacao; v2a = c2.populacao; break;
        case 2: v1a = c1.area; v2a = c2.area; break;
        case 3: v1a = c1.pib; v2a = c2.pib; break;
        case 4: v1a = c1.pontosTuristicos; v2a = c2.pontosTuristicos; break;
        case 5: v1a = c1.populacao / c1.area; v2a = c2.populacao / c2.area; inv1 = 1; break;
    }

    // Segundo atributo
    switch (atr2) {
        case 1: v1b = c1.populacao; v2b = c2.populacao; break;
        case 2: v1b = c1.area; v2b = c2.area; break;
        case 3: v1b = c1.pib; v2b = c2.pib; break;
        case 4: v1b = c1.pontosTuristicos; v2b = c2.pontosTuristicos; break;
        case 5: v1b = c1.populacao / c1.area; v2b = c2.populacao / c2.area; inv2 = 1; break;
    }

    pontos1 += compara(v1a, v2a, inv1) == 1 ? 1 : 0;
    pontos2 += compara(v1a, v2a, inv1) == -1 ? 1 : 0;
    pontos1 += compara(v1b, v2b, inv2) == 1 ? 1 : 0;
    pontos2 += compara(v1b, v2b, inv2) == -1 ? 1 : 0;

    if (pontos1 > pontos2)
        printf("Vencedor: %s (ganhou em mais atributos)\n", c1.cidade);
    else if (pontos2 > pontos1)
        printf("Vencedor: %s (ganhou em mais atributos)\n", c2.cidade);
    else
        printf("Empate nos atributos escolhidos.\n");
}

// Menu interativo
void menu(Carta c1, Carta c2) {
    int opcao;
    do {
        printf("\n=== MENU ===\n");
        printf("1 - Comparar 1 atributo (nível Novato)\n");
        printf("2 - Comparar 2 atributos (nível Mestre)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                printf("\nEscolha o atributo:\n");
                printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n");
                int escolha;
                scanf("%d", &escolha);
                compararSimples(c1, c2, escolha);
                break;
            }
            case 2: {
                printf("\nEscolha dois atributos para comparar:\n");
                printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n");
                int a1, a2;
                printf("Primeiro atributo: "); scanf("%d", &a1);
                printf("Segundo atributo: "); scanf("%d", &a2);
                compararDupla(c1, c2, a1, a2);
                break;
            }
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opção inválida!\n");
        }

    } while (opcao != 0);
}

int main() {
    Carta carta1, carta2;

    printf("Cadastro da primeira carta:\n");
    cadastrarCarta(&carta1);

    printf("\nCadastro da segunda carta:\n");
    cadastrarCarta(&carta2);

    printf("\nCartas cadastradas:");
    exibirCarta(carta1);
    exibirCarta(carta2);

    menu(carta1, carta2);

    return 0;
}
