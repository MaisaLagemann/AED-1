#include <stdio.h>

int main()
{

    int numeroEstudantes, contador;
    float primeiraNota, segundaNota, terceiraNota, mediaPonderada;

    scanf("%d", &numeroEstudantes);

    for (contador = 0; contador < numeroEstudantes; contador++)
    {

        scanf("%f %f %f", &primeiraNota, &segundaNota, &terceiraNota);

        mediaPonderada = ((primeiraNota * 2) + (segundaNota * 3) + (terceiraNota * 5)) / 10;
        printf("%.1f\n", mediaPonderada);
    }

    return 0;
}