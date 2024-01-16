#include <stdio.h>

#define ROJO_F "\x1b[41m"
#define AZUL_T "\x1b[34m"
#define VERDE_T "\x1b[32m"
#define RESET_T "\x1b[0m"

struct alumno
{
    char nombre[50];
    int edad;
    float promedio;
};

void getalumno(struct alumno *alumno);
void putalumno(const struct alumno *alumno);

int main()
{
    int n;

    printf("Ingrese el numero de alumnos: ");
    scanf("%d", &n);
    fflush(stdin);

    struct alumno alumnos[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nIngresar datos para el alumno %d:\n", i + 1);
        getAlumno(&alumnos[i]);
    }

    printf("\nDatos de los alumnos:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nDatos del alumno %d:\n", i + 1);
        putAlumno(&alumnos[i]);
    }

    return 0;
}

