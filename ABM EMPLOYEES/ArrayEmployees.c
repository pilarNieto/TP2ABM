#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "showMenu.h"
#include "utn.h"
#include "ArrayEmployees.h"

void printEmployee(eEmployee user)
{
    printf("%5d   %8s    %7s     %3.2f    %4d  %02d/%02d/%d\n"
           , user.id
           , user.name
           , user.lastName
           , user.salary
           , user.sector
           , user.birthDay.day
           , user.birthDay.month
           , user.birthDay.year);

}

int printEmployees(eEmployee user[], int quantity)
{
    int error = 1;
    int flag = 0;

    if( user != NULL && quantity > 0)
    {
        system("cls");
        printf("==============================================================\n");
        printf("   ID     NOMBRE    APELLIDO     SALARIO     SECTOR    FECHA \n");
        printf("===============================================================\n");
        for(int i=0; i<quantity; i++)
        {
            if(user[i].isEmpty == 0)
            {
                printEmployee(user[i]);
                flag = 1;
            }
        }
        if( flag == 0)
        {
            printf("******No se han ingresado empleados en la lista******\n");
        }
        printf("\n\n");

        error = 0;
    }
    return error;
}//

int initEmployee(eEmployee user[], int quantity)
{
    int error = 1;
    if (user!=NULL && quantity > 0)
    {
        for(int i=0; i<quantity; i++)
        {
            user[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

int searchFree(eEmployee user[], int quantity)//CUMPLE LA FUNCIÓN DE BUSCAR UN CAMPO VACIO
{
    int index = -1;// DEVUELVE MENOS UNO SI EL VECTOR ESTÁ LLENO
    for(int i = 0; i<quantity; i++)
    {
        if(user[i].isEmpty==1)
        {
            index = i;
            break;//SI NO HACE BREAK VA A RECORRER TODO EL ARRAY
        }
    }

    return index;
}


int addEmployee(eEmployee user[], int quantity, int id)
{

    system("cls");
    printf("=====================================================\n");
    printf("                     ALTA  EMPLEADOS                 \n");
    printf("=====================================================\n");

    int error = 1;
    int index;

    eEmployee newEmployee;

    if (user!=NULL && quantity > 0 && id >0)
    {
        index = searchFree(user, quantity);
        if(index == -1)
        {
            printf("No es posible ingresar más usuarios, el sistema esta completo.\n");
        }
        else
        {
            newEmployee.id = id;
            newEmployee.isEmpty = 0;

            utn_getNombre(newEmployee.name, 20, "\nIngrese el nombre del empleado:\n", "\n*Error reingrese el nombre*", 3);

            utn_getNombre(newEmployee.lastName,20, "\nIngrese el apellido del empleado:\n", "\n*Error reingrese el nombre*", 3);

            utn_getNumeroFlotante(&newEmployee.salary,"\nIngrese el salario del empleado:\n","\n*Error reingrese el salario*",0,9999999999,3);

            showMenuSector();
            utn_getNumero(&newEmployee.sector, "\nIngrese la opción del sector al que pertenece el empleado:\n","\n*Error, sector invalido Reingrese*", 0, 6, 3);
            showMenuSector();

            printf("Ingrese fecha de ingreso al sistema dd/mm/aa\n");
            scanf("%d/%d/%d", &newEmployee.birthDay.day, &newEmployee.birthDay.month, &newEmployee.birthDay.year);


            user[index] = newEmployee;
            error = 0;
        }

    }
    return error;
}

int findEmployeeByIde(eEmployee user[], int quantity, int id)
{
    int index = -1;
    for(int i = 0; i<quantity; i++)
    {
        if(user[i].id == id && user[i].isEmpty==0)
        {
            index = i;
            break;
        }
    }

    return index;
}

int removeEmployee(eEmployee user[], int quantity)
{
    int error = 1;
    int id;
    int index;
    int confirm;
    if (user!=NULL && quantity > 0 )
    {
        system("cls");
        //printEmployees(user, quantity);
        printf("=====================================================\n");
        printf("            BAJA DE EMPLEADOS       \n");
        printf("=====================================================\n");
        printf(">>>> Ingrese el id del empleado a dar de baja:\n");
        scanf("%d", &id);

        index = findEmployeeByIde(user, quantity, id);

        if(index == -1)
        {
            printf("No hay un empleado con el ID ingresado. Verifique.\n\n");
        }
        else
        {
            printEmployee(user[index]);
            printf("Confirma dar de baja este empleado: 1. [SI] 2. [NO] \n");
            fflush(stdin);
            scanf("%d", &confirm);
            if(confirm == 1)
            {
                user[index].isEmpty = 1;
                error=0;
            }
            else
            {
                error = 2;
                //printf("Usted a cancelado la baja de este empleado.\n\n");
            }
        }
    }

    return error;
}

int modifyEmployee(eEmployee user[], int quantity)
{
    int error = 1;
    int id;
    int index;
    int confirm;
    char newName[20];
    char newLastName[20];
    float newSalary;
    int newSector;
    eDate newDate;

    if (user!=NULL && quantity > 0 )
    {
        system("cls");
        //printEmployees(user, quantity);
        printf("=====================================================\n");
        printf("          MODIFICACION DE DATOS EMPLEADOS              \n");
        printf("=====================================================\n");
        printf(">>>> Ingrese el id del empleado al que le va a modificar datos:\n");
        scanf("%d", &id);

        index = findEmployeeByIde(user, quantity, id);

        if(index == -1)
        {
            printf("No hay un empleado con el ID ingresado. Verifique.\n\n");
        }
        else
        {
            printEmployee(user[index]);

          printf("Ingrese la opcion del item que desea modificar\n");
            int option;
            printf("    1. Nombre.\n");
            printf("    2. Apellido.\n");
            printf("    3. Salario.\n");
            printf("    4. Salario.\n");
            printf("    5. Fecha.\n");
            scanf("%d", &option);
            switch (option)
            {
            case 1:
                printf("Ingrese el nuevo nombre: \n");
                scanf("%s", newName);
                break;
            case 2:
                printf("Ingres de nuevo el apellido: \n");
                scanf("%s", newLastName);
                break;
            case 3:
                printf("Ingres el nuevo salario: \n");
                scanf("%f", &newSalary);
                break;
            case 4:
                printf("Ingrese el nuevo sector: \n");
                scanf("%d", &newSector);
                break;
            case 5:
                printf("Ingrese la  nueva fecha: \n");
                scanf("%d/%d/%d\n", &newDate.day, &newDate.month, &newDate.year);

                break;
            }
            printf("Confirma modificar este dato?: 1. [SI] 2. [NO] \n");
            fflush(stdin);
            scanf("%d", &confirm);
            if(confirm == 1)
            {
                if(option == 1)
                {
                    user[index].name[index]= newName;
                }
                if(option == 2)
                {
                    user[index].lastName[index] = newLastName;
                }
                if(option == 3)
                {
                    user[index].salary = newSalary;
                }
                if(option == 4)
                {
                    user[index].sector = newSector;
                }
                if(option == 5)
                {
                    user[index].birthDay = newDate;
                }

                error=0;
            }
            else
            {
                error = 2;
                //printf("Usted a cancelado la baja de este empleado.\n\n");
            }
        }
    }

    return error;
}

int sortEmployees(eEmployee user[], int quantity, int criterionLastName, int criterionSector)
{
    int error = 1;
    eEmployee auxEmployee;
    system("cls");
    printf("=====================================================\n");
    printf("             ORDENAMIENTO  EMPLEADOS                 \n");
    printf("=====================================================\n");

    if(user != NULL && quantity >0 && criterionLastName >= 0 &&criterionLastName <= 1
            && criterionSector >= 0 && criterionSector <= 1)
    {
        for(int i=0; i-quantity -1; i++)
        {
            for(int j=i+1; j<quantity; j++)
            {
                if( (user[i].lastName > user[j].lastName && criterionLastName)
                        || (user[i].lastName < user[j].lastName && !criterionLastName)
                        || (user[i].lastName == user[j].lastName && user[i].sector > user[j].sector && criterionSector)
                        || (user[i].lastName == user[j].lastName && user[i].sector < user[j].sector && !criterionSector))
                {
                    auxEmployee = user[i];
                    user[i] = user[j];
                    user[j] = auxEmployee;
                }
            }
            error = 0;
        }
    }
    return error;
}
int informationSalary(eEmployee user[], int quantity)
{
    int error = 1;
    float average;
    float accumSalary = 0;
    int countEmployeesActive = 0;
    int higherAverageSalary = 0;

    for (int i=0; i<quantity; i++)
    {
        if (user[i].isEmpty == 0)
        {
            accumSalary = accumSalary + user[i].salary;
            countEmployeesActive++;
        }
    }
    average=(float)accumSalary/countEmployeesActive;

    for (int i = 0; i < quantity; i++)
    {
        if (user[i].salary > average)
        {
            higherAverageSalary++;
        }

    }

    if()
    system("cls");
    printf("====================================================================\n");
    printf("                        INFORME DE SALARIOS                          \n");
    printf("=====================================================================\n");
    printf(" >> La nomina total activa es de: %.2f\n", accumSalary);
    printf(" >> El salario promedio de los empleados activos es de: %.2f\n", average);
    printf(" >> La cantidad de empleados que superan el promedio es de: %d\n", higherAverageSalary);


    return error;
}
