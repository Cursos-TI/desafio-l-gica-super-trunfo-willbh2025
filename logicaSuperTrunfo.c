#include <stdio.h>

int main() {
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

    // Variáveis calculadas
    float densidade1, densidade2, pibPerCapita1, pibPerCapita2;

    // Entrada de dados carta 1
    printf("Cadastro da carta 1:\n");
    printf("Informe o Estado (letra de A a H): ");
    scanf(" %c", &estado1);

    printf("Informe o codigo da carta (ex: A01, B03): ");
    scanf("%s", codigo1);

    printf("Informe o nome da Cidade: ");
    scanf("%s", cidade1);

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
    scanf("%s", cidade2);

    printf("Informe a populacao da cidade: ");
    scanf("%lu", &populacao2);

    printf("Informe a Area da cidade (em km2): ");
    scanf("%f", &area2);

    printf("Informe o PIB da cidade (em bilhoes de reais): ");
    scanf("%f", &pib2);

    printf("Informe o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos derivados
    densidade1 = (float)populacao1 / area1;
    densidade2 = (float)populacao2 / area2;
    pibPerCapita1 = pib1 / populacao1;
    pibPerCapita2 = pib2 / populacao2;

    // Menu de seleção de atributos
    int attr1, attr2;
    printf("\n=== ESCOLHA O PRIMEIRO ATRIBUTO ===\n");
    printf("1. População\n2. Área\n3. PIB\n4. Densidade Demográfica\n5. PIB per Capita\n6. Pontos Turísticos\n");
    printf("Opção (1-6): ");
    scanf("%d", &attr1);

    // Validação primeiro atributo
    if(attr1 < 1 || attr1 > 6) {
        printf("Atributo inválido!\n");
        return 1;
    }

    // Menu dinâmico para segundo atributo
    printf("\n=== ESCOLHA O SEGUNDO ATRIBUTO ===\n");
    if(attr1 != 1) printf("1. População\n");
    if(attr1 != 2) printf("2. Área\n");
    if(attr1 != 3) printf("3. PIB\n");
    if(attr1 != 4) printf("4. Densidade Demográfica\n");
    if(attr1 != 5) printf("5. PIB per Capita\n");
    if(attr1 != 6) printf("6. Pontos Turísticos\n");
    printf("Opção (1-6, exceto %d): ", attr1);
    scanf("%d", &attr2);

    // Validação segundo atributo
    if(attr2 < 1 || attr2 > 6 || attr2 == attr1) {
        printf("Atributo inválido!\n");
        return 1;
    }

    // Obtenção dos valores dos atributos
    float c1_a1, c1_a2, c2_a1, c2_a2;
    // Primeiro atributo
    switch(attr1) {
        case 1: c1_a1 = populacao1; c2_a1 = populacao2; break;
        case 2: c1_a1 = area1;      c2_a1 = area2;      break;
        case 3: c1_a1 = pib1;       c2_a1 = pib2;       break;
        case 4: c1_a1 = densidade1; c2_a1 = densidade2; break;
        case 5: c1_a1 = pibPerCapita1; c2_a1 = pibPerCapita2; break;
        case 6: c1_a1 = pontosTuristicos1; c2_a1 = pontosTuristicos2; break;
    }
    // Segundo atributo
    switch(attr2) {
        case 1: c1_a2 = populacao1; c2_a2 = populacao2; break;
        case 2: c1_a2 = area1;      c2_a2 = area2;      break;
        case 3: c1_a2 = pib1;       c2_a2 = pib2;       break;
        case 4: c1_a2 = densidade1; c2_a2 = densidade2; break;
        case 5: c1_a2 = pibPerCapita1; c2_a2 = pibPerCapita2; break;
        case 6: c1_a2 = pontosTuristicos1; c2_a2 = pontosTuristicos2; break;
    }

    // Comparação individual
    int resultado_attr1, resultado_attr2;
    // Atributo 1
    if(attr1 == 4) { // Densidade Demográfica: menor vence
        resultado_attr1 = (c1_a1 < c2_a1) ? 1 : (c1_a1 > c2_a1) ? 2 : 0;
    } else {
        resultado_attr1 = (c1_a1 > c2_a1) ? 1 : (c1_a1 < c2_a1) ? 2 : 0;
    }
    // Atributo 2
    if(attr2 == 4) { // Densidade Demográfica: menor vence
        resultado_attr2 = (c1_a2 < c2_a2) ? 1 : (c1_a2 > c2_a2) ? 2 : 0;
    } else {
        resultado_attr2 = (c1_a2 > c2_a2) ? 1 : (c1_a2 < c2_a2) ? 2 : 0;
    }

    // Soma dos atributos
    float soma_c1 = c1_a1 + c1_a2;
    float soma_c2 = c2_a1 + c2_a2;

    // Resultado final
    int vencedor;
    if(soma_c1 > soma_c2) vencedor = 1;
    else if(soma_c2 > soma_c1) vencedor = 2;
    else vencedor = 0;

    // Exibição dos resultados
    printf("\n=== RESULTADO FINAL ===\n");
    printf("Carta 1: %s (%s, %s)\n", cidade1, codigo1, &estado1);
    printf("Carta 2: %s (%s, %s)\n", cidade2, codigo2, &estado2);

    printf("\nAtributos comparados:");
    printf("\n1. %s (%s)", 
        (attr1 == 1) ? "População" :
        (attr1 == 2) ? "Área" :
        (attr1 == 3) ? "PIB" :
        (attr1 == 4) ? "Densidade Demográfica" :
        (attr1 == 5) ? "PIB per Capita" : "Pontos Turísticos",
        (attr1 == 4) ? "menor vence" : "maior vence"
    );
    printf("\n2. %s (%s)", 
        (attr2 == 1) ? "População" :
        (attr2 == 2) ? "Área" :
        (attr2 == 3) ? "PIB" :
        (attr2 == 4) ? "Densidade Demográfica" :
        (attr2 == 5) ? "PIB per Capita" : "Pontos Turísticos",
        (attr2 == 4) ? "menor vence" : "maior vence"
    );

    printf("\n\nValores por carta:");
    printf("\n%s: %.2f | %.2f", cidade1, c1_a1, c1_a2);
    printf("\n%s: %.2f | %.2f", cidade2, c2_a1, c2_a2);

    printf("\n\nSoma dos atributos:");
    printf("\n%s: %.2f", cidade1, soma_c1);
    printf("\n%s: %.2f", cidade2, soma_c2);

    printf("\n\n=== VENCEDOR ===\n");
    if(vencedor == 0) {
        printf("Empate técnico!\n");
    } else {
        printf("Carta %d: %s\n", vencedor, (vencedor == 1) ? cidade1 : cidade2);
    }

    return 0;
}
