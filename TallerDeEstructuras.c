// Crear un programa que permita al usuario el ingreso y presentación de datos de n alumnos : 'get' 'put' 'fflush'.
// Debe usar las siguientes funciones: 'gets()', 'puts()', 'fflush()'.
//  Se agrega la libreria
#include <stdio.h>

// Se agregan fuentes
#define ROJO_T "\x1b[31m"
#define AZUL_T "\x1b[34m"
#define VERDE_T "\x1b[32m"
#define Amarillo_T "\x1b[33m"
#define RESET_T "\x1b[0m"

// Se incorpora la estructura alumno
struct Alumno
{
    int matricula;
    char nombre[50];
    char direccion[50];
    char carrera[50];
    float promedio;
};

// Se declaran la funcion void que no devuelve ningun valor
// Se asigna los nombres de las funciones getAlumno y putAlumno
// Se agrega declaración de un parámetro de la función, struct indica que la función espera recibir un puntero a una estructura de tipo Alumno
// Se agrega declaración de un parámetro de la función, const para decir que la funcion no modificara a Alumno

void getAlumno(struct Alumno *alumno);
void putAlumno(const struct Alumno *alumno);

int main()
{
    int n;

    printf(RESET_T "Ingrese número de alumnos: " RESET_T);
    scanf("%d", &n);
    while (getchar() != '\n'); // Limpiar el búfer de entrada

    // Declarar un arreglo de estructuras Alumno
    struct Alumno alumnos[n];

    // Ingreso de datos alumnos
    for (int i = 0; i < n; i++)
    {
        printf(VERDE_T "\nIngresar datos del alumno %d:\n" RESET_T, i + 1);
        getAlumno(&alumnos[i]);
    }

    // Impresion de datos
    printf(RESET_T "\n\tDatos de los alumnos:\n");
    for (int i = 0; i < n; i++)
    {
        printf(Amarillo_T "\n \t Alumno %d:\n", i + 1);
        putAlumno(&alumnos[i]);
    }

    return 0;
}

// Se especifica lo que va a hacer función getAlumno
void getAlumno(struct Alumno *alumno)
{
    printf(ROJO_T "Matricula: " AZUL_T);
    scanf("%d", &alumno->matricula);
    while (getchar() != '\n'); // Limpiar el búfer de entrada

    printf(ROJO_T "Nombre: " AZUL_T);
    fgets(alumno->nombre, sizeof(alumno->nombre), stdin);
    printf(ROJO_T "Direccion: " AZUL_T);
    fgets(alumno->direccion, sizeof(alumno->direccion), stdin);
    printf(ROJO_T "Carrera: " AZUL_T);
    fgets(alumno->carrera, sizeof(alumno->carrera), stdin);
    printf(ROJO_T "Promedio: " AZUL_T);
    scanf("%f", &alumno->promedio);
    while (getchar() != '\n'); // Limpiar el búfer de entrada
}

// Se especifica lo que va a hacer función putAlumno
void putAlumno(const struct Alumno *alumno)
{
    printf(ROJO_T "\tMatricula: " AZUL_T "%d\n", alumno->matricula);
    printf(ROJO_T "\tNombre: " AZUL_T "%s", alumno->nombre);
    printf(ROJO_T "\tDireccion: " AZUL_T "%s", alumno->direccion);
    printf(ROJO_T "\tCarrera: " AZUL_T "%s", alumno->carrera);
    printf(ROJO_T "\tPromedio: " AZUL_T "%.2f\n" RESET_T, alumno->promedio);
}