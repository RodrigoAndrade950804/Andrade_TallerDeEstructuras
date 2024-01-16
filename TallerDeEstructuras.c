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
