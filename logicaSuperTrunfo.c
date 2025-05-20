#include <stdio.h>

int main() {
    // Variáveis para atributos calculados
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;

    // Variáveis carta 1
    char estado1;
    char codigo1[20];
    char cidade1[50];
    unsigned long int populacao1;
    float area1, pib1;
    int pontosTuristicos1;

    // Variáveis carta 2
    char estado2;
    char codigo2[20];
    char cidade2[50];
    unsigned long int populacao2;
    float area2, pib2;
    int pontosTuristicos2;

    // Entrada de dados carta 1
    printf("Cadastro da carta 1:\n");
    printf("Informe o Estado (letra de A a H): ");
    scanf(" %c", &estado1);

    printf("Informe o codigo da carta (ex: A01, B03): ");
    scanf("%s", codigo1);

    printf("Informe o nome da Cidade: ");
    scanf(" %s", cidade1);

    printf("Informe a populacao da cidade: ");
    scanf("%lu", &populacao1);

    printf("Informe a Area da cidade (em km2): ");
    scanf("%f", &area1);

    printf("Informe o PIB da cidade (em bilhoes de reais): ");
    scanf("%f", &pib1);

    printf("Informe o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos1);

    // Entrada de dados carta 2
    printf("\nCadastro da carta 2:\n");
    printf("Informe o Estado (letra de A a H): ");
    scanf(" %c", &estado2);

    printf("Informe o codigo da carta (ex: B02): ");
    scanf("%s", codigo2);

    printf("Informe o nome da Cidade: ");
    scanf(" %s", cidade2);

    printf("Informe a populacao da cidade: ");
    scanf("%lu", &populacao2);

    printf("Informe a Area da cidade (em km2): ");
    scanf("%f", &area2);

    printf("Informe o PIB da cidade (em bilhoes de reais): ");
    scanf("%f", &pib2);

    printf("Informe o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos
    densidade1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    densidade2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    // Menu interativo
    int atributoEscolhido;
    printf("\n=== MENU SUPER TRUNFO ===");
    printf("\n1. Comparar População");
    printf("\n2. Comparar Área");
    printf("\n3. Comparar PIB");
    printf("\n4. Comparar Densidade Demográfica");
    printf("\n5. Comparar PIB per Capita");
    printf("\n6. Sair");
    printf("\nEscolha uma opção (1-6): ");
    scanf("%d", &atributoEscolhido);

    char* nomeAtributo;
    float valor1, valor2;
    int menorVence = 0;

    switch(atributoEscolhido) {
        case 1:
            nomeAtributo = "População";
            valor1 = populacao1;
            valor2 = populacao2;
            break;
        case 2:
            nomeAtributo = "Área";
            valor1 = area1;
            valor2 = area2;
            break;
        case 3:
            nomeAtributo = "PIB";
            valor1 = pib1;
            valor2 = pib2;
            break;
        case 4:
            nomeAtributo = "Densidade Demográfica";
            valor1 = densidade1;
            valor2 = densidade2;
            menorVence = 1;
            break;
        case 5:
            nomeAtributo = "PIB per Capita";
            valor1 = pibPerCapita1;
            valor2 = pibPerCapita2;
            break;
        case 6:
            printf("\nJogo encerrado!\n");
            return 0;
        default:
            printf("\nOpção inválida!\n");
            return 1;
    }

    // Exibe comparação
    printf("\n\n=== COMPARAÇÃO FINAL ===");
    printf("\nCritério: %s", nomeAtributo);
    
    if (menorVence) {
        printf("\n%s: Menor valor vence", nomeAtributo);
        printf("\nCarta 1: %.2f\nCarta 2: %.2f", valor1, valor2);
        
        if (valor1 < valor2) {
            printf("\nVencedor: Carta 1 (%s)\n", cidade1);
        } else if (valor2 < valor1) {
            printf("\nVencedor: Carta 2 (%s)\n", cidade2);
        } else {
            printf("\nEmpate!\n");
        }
    } else {
        printf("\n%s: Maior valor vence", nomeAtributo);
        printf("\nCarta 1: %.2f\nCarta 2: %.2f", valor1, valor2);
        
        if (valor1 > valor2) {
            printf("\nVencedor: Carta 1 (%s)\n", cidade1);
        } else if (valor2 > valor1) {
            printf("\nVencedor: Carta 2 (%s)\n", cidade2);
        } else {
            printf("\nEmpate!\n");
        }
    }

    return 0;
}
