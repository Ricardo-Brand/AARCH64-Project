
#include <stdio.h>
#include <string.h>
#include "functions.h"

int main(){
    int a, b;
    double a1, b1;
    char operador[3];

    strcpy(operador, ""); 

    printf("Escolha um operador matematico que desejar:\n");
    printf("Adicao: '+'\n");
    printf("Subtracao: '-'\n");
    printf("Divisao: '/'\n");
    printf("Multiplicacao: '*'\n");
    printf("Potencia: '**'\n");
    printf("Raiz Quadrada: '//'\n\n");
    printf("Digite: ");
    scanf("%2s", operador);

    if (strcmp(operador, "+") == 0) {
        printf("\nO formato dessa conta sera: 'a + b' \n");
        printf("Digite o valor de 'a': ");
        scanf("%d", &a);
        printf("\nDigite o valor de 'b': ");
        scanf("%d", &b);
        printf("\nTotal: %d\n", add(a,b));

    } 
    else if (strcmp(operador, "-") == 0) {
        printf("\nO formato dessa conta sera: 'a - b' \n");
        printf("Digite o valor de 'a': ");
        scanf("%d", &a);
        printf("\nDigite o valor de 'b': ");
        scanf("%d", &b);
        printf("\nTotal: %d\n", sub(a,b));

    } 
    else if (strcmp(operador, "*") == 0) {
        printf("\nO formato dessa conta sera: 'a * b' \n");
        printf("Digite o valor de 'a': ");
        scanf("%d", &a);
        printf("\nDigite o valor de 'b': ");
        scanf("%d", &b);
        printf("\nTotal: %d\n", mul(a,b));

    } 
    else if (strcmp(operador, "/") == 0) {
        printf("\nO formato dessa conta sera: 'a / b' \n");
        printf("Digite o valor de 'a': ");
        scanf("%lf", &a1);
        printf("\nDigite o valor de 'b': ");
        scanf("%lf", &b1);
        if(b1 == 0){
            printf("Conta matematica invalida, pois o divisor eh igual a 0\n");
            return 1;
        }
        printf("\nTotal: %.2lf\n", divi(a1,b1));

    } 
    else if (strcmp(operador, "//") == 0) {
        printf("\nEssa conta será a raiz quadrada de 'a'\n");
        printf("Digite o valor de 'a': ");
        scanf("%lf", &a1);
        if(a1 <= 0){
            printf("Por favor insira um numero maior que zero!!!\n");
            return 1;
        }
        printf("\nTotal: %.2lf\n", raiz(a1));

    } 
    else if (strcmp(operador, "**") == 0) {
        printf("\nO formato dessa conta sera: base = 'a' , expoente = 'b' \n");
        printf("Digite o valor de 'a': ");
        scanf("%lf", &a1);
        printf("\nDigite o valor de 'b': ");
        scanf("%d", &b);
        printf("\nTotal: %lf\n", power(a1,b));

    } 
    else {
        printf("\nOperador inválido!\n");
    }

    return 0;
}