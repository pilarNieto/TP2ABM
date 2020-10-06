#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "ArrayEmployees.h"

#define ASC 1
#define DESC 0
#define TAM 1000

int showMenu();
int showMenuSector();
int main()
{
    char seguir = 's';
    char confirm;
    int nextId = 1000;
    int answer;
    eEmployee list[TAM];

    if(initEmployee(list, TAM)==0)
    {
        printf("Personas inicializadas con exito!\n");
    }
    else
    {
        printf("Ha ocurrido un problema al inicializar personas\n");
    }

    do
    {
        switch(showMenu())
        {

        case 1:
            if(addEmployee(list, TAM, nextId)==0)
            {
                nextId++;
                printf("*****ALTA REALIZADA*****\n");
            }
            else
            {
                printf("*****NO FUE POSIBLE REALIZAR EL ALTA****\n");
            }
            break;

        case 2:
            answer = removeEmployee(list, TAM);

            if(answer==0)
            {
                printf("*********BAJA EXISTOSA**********\n\n");
            }
            else if(answer == 2)
            {
                printf("***LA BAJA SE HA CANCELADO POR EL USUARIO*********\n\n");
            }
            else
            {
                printf("********SE HA PRODUCIDO UN ERROR EN LA BAJA********\n\n");
            }
            break;
        case 3:
            answer = modifyEmployee(list, TAM);

            if(answer==0)
            {
                printf("*********BAJA EXISTOSA**********\n\n");
            }
            else if(answer == 2)
            {
                printf("***LA BAJA SE HA CANCELADO POR EL USUARIO*********\n\n");
            }
            else
            {
                printf("********SE HA PRODUCIDO UN ERROR EN LA BAJA********\n\n");
            }
            break;
        case 4:
            system("cls");
            printEmployees(list, TAM);
            break;
        case 5:
            if(sortEmployees(list, TAM, ASC, ASC))
            {
                printf("***HUBO UN PROBLEMA AL REALIZAR ORDENAMIENTO*********\n\n");
            }
            else
            {
                printf("*********SE HA REALIZADO EL ORDENAMIENTO**********\n\n");
            }

            break;
        case 6:
            informationSalary(list, TAM);
            break;
        case 7:
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirm);
            confirm = tolower(confirm);
            if(confirm == 's')
            {
                seguir = 'n';
            }

            break;
        default:
            printf("Opcion invalida!!!\n");

        }

        system("pause");

    }
    while( seguir == 's');

    return 0;

}

