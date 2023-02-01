#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
    int  anno_de_nacimiento, dia_de_nacimiento, edad;
    int mes_de_nacimiento, meses;
   
    // Solicita el día de nacimiento
    printf ("Ingresa el valor de dia de nacimiento: ");
    scanf ("%d", &dia_de_nacimiento);
    (void) getchar ();

    // Solicita el mes de nacimiento
    printf ("Ingresa el valor de mes de nacimiento: ");
    scanf ("%d", &mes_de_nacimiento);
    (void) getchar ();

    // Solicita el anno de nacimiento
    printf ("Ingresa el valor de anno de nacimiento: ");
    scanf ("%d", &anno_de_nacimiento);
    (void) getchar ();

   // variables para almacenar los componentes de fecha actual
    int day, month, year;
 
    // `time_t` es un tipo de tiempo aritmético
    time_t now;
 
    // Obtener la hora actual
    // `time()` devuelve la hora actual del sistema como un valor `time_t`
    time(&now);
 

    // localtime convierte un valor de `time_t` a la hora del calendario y
    // devuelve un puntero a una estructura `tm` con sus miembros
    // rellenado con los valores correspondientes
    struct tm *local = localtime(&now);
 
   
    day = local->tm_mday;            // obtener el día del mes (1 a 31)
    month = local->tm_mon + 1;      // obtener el mes del año (0 a 11)
    year = local->tm_year + 1900;   // obtener el año desde 1900
 
    
 
    // imprime la fecha actual
    printf("Hoy es: %02d/%02d/%d\n", day, month, year);
    
    edad=year-anno_de_nacimiento;

    if(mes_de_nacimiento>month||(mes_de_nacimiento==month&dia_de_nacimiento>day))
        edad=edad-1;
    printf ("Valor de edad: %d\n", edad);
    putchar ('\n');

    if(edad > 65){
        printf ("Usted es candidato para la vacuna \n");
    }else if(edad == 64 && month - mes_de_nacimiento ){
        printf ("Usted está en lista de espera \n");
    }else{  
         printf ("Usted no es candidato para la vacuna \n");
    }

    system ("pause");
    return EXIT_SUCCESS;
}
