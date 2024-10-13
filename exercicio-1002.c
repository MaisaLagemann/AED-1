#include <stdio.h>

int main() {

    double raio;
    double pi = 3.14159;
    double area;

    scanf("%lf", &raio);
    area = pi * raio * raio;
    printf("A=%.4f\n", area);
    
    return 0;
}
