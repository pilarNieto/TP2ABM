#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int showMenu()
{
    int option;
    system("cls");
    printf("=====================================================\n");
    printf("    ALTA  ,  BAJA   Y   MODIFICACION  DE  EMPLEADOS  \n");
    printf("=====================================================\n");
    printf(" >>>> Ingrese el la opcion que desea realizar: \n\n");
    printf("    1. Ingresar nuevo empleado.\n");
    printf("    2. Eliminar empleado de lista activa.\n");
    printf("    3. Modificar datos del empleado.\n");
    printf("    4. Mostrar Listado de empleados.\n");
    printf("    5. Ordenar empleados.\n");
    printf("    6. Informes\n");
    printf("    7. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &option);


    return option;
}

int showMenuSector()
{
    int optionSector;
    system("cls");
    printf("=====================================================\n");
    printf("           SECTORES DE LA EMPRESA                    \n");
    printf("=====================================================\n");
    printf("    1. GERENCIA.\n");
    printf("    2. TESORERIA.\n");
    printf("    3. RECURSOS HUMANOS.\n");
    printf("    4. ATENCION AL CLIENTE.\n");
    printf("    5. VENTAS.\n");
    printf("Ingrese opcion: ");
    scanf("%d", &optionSector);


    return optionSector;
}
int showMenuModifify()
{
   int optionModify;
    printf("    1. Nombre.\n");
    printf("    2. Apellido.\n");
    printf("    3. Salario.\n");
    printf("    4. Salario.\n");
    printf("    5. Fecha.\n");
    printf("Ingrese opcion: ");
    scanf("%d", &optionModify);
}
