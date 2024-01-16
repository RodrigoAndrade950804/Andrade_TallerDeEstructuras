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

void getalumno(struct alumno *alumno)
{
    printf("Nombre: ");
    fgets(alumno->nombre, sizeof(alumno->nombre), stdin);
    printf("Edad: ");
    scanf("%d", &alumno->edad);
    printf("Promedio: ");
    scanf("%f", &alumno->promedio);
    fflush(stdin);
}

void putalumno(const struct alumno *alumno)
{
    printf("Nombre: %s", alumno->nombre);
    printf("Edad: %d\n", alumno->edad);
    printf("Promedio: %.2f\n", alumno->promedio);
}
