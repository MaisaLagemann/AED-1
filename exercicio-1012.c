#include <stdio.h>

int main()
{
    double baseTriangulo, alturaTriangulo, raioCirculo;
    double areaTriangulo, areaCirculo, areaTrapezio, areaQuadrado, areaRetangulo;
    const double PI = 3.14159;

    if (scanf("%lf %lf %lf", &baseTriangulo, &alturaTriangulo, &raioCirculo) != 3)
    {
        printf("Erro na entrada de dados.\n");
        return 1;
    }

    areaTriangulo = (baseTriangulo * raioCirculo) / 2.0;
    areaCirculo = PI * raioCirculo * raioCirculo;
    areaTrapezio = ((baseTriangulo + alturaTriangulo) * raioCirculo) / 2.0;
    areaQuadrado = alturaTriangulo * alturaTriangulo;
    areaRetangulo = baseTriangulo * alturaTriangulo;

    printf("TRIANGULO: %.3f\n", areaTriangulo);
    printf("CIRCULO: %.3f\n", areaCirculo);
    printf("TRAPEZIO: %.3f\n", areaTrapezio);
    printf("QUADRADO: %.3f\n", areaQuadrado);
    printf("RETANGULO: %.3f\n", areaRetangulo);

    return 0;
}
