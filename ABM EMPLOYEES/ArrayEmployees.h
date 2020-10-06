#include "fecha.h"
#include "utn.h"
#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[20];
    char lastName[20];
    float salary;
    int sector;
    eDate birthDay;
    int isEmpty;
} eEmployee;

#endif // ARRAYEMPLOYEES_H_INCLUDED


int initEmployee(eEmployee user[], int quantity);
/** \brief indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 *
 * \param Pointer to array of employees
 * \ param len int Array length
 * \ return int Return (1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
void printEmployee(eEmployee user);
/** \brief prints a single employee of the array
 *
 * \param user[] eEmployee
 * \param quantity int
 * \return int Return (1) if Error  - (0) if Ok
 *
 */

int printEmployees(eEmployee user[], int quantity);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int Return (1) if Error  - (0) if Ok
 *
 */

int searchFree(eEmployee user[], int quantity);

/** \brief free search is responsible for looking for a free space in the structure to be used
 *
 * \param user[] eEmployee
 * \param quantity int
 * \param id int
 * \return int Return (1) if Error  - (0) if Ok
 *
 */
int addEmployee(eEmployee user[], int quantity, int id);
/**  add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (1) if Error  - (0) if Ok
 *
 */
int sortEmployees(eEmployee user[], int quantity, int criterionLastName, int criterionSector);
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (1) if Error  - (0) if Ok
 *
 */

int removeEmployee(eEmployee user[], int quantity);

/** \brief Remove a Employee by Id (makes a logical low)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (1) if Error ] - (0) if Ok
 *
 */


int informationSalary(eEmployee user[], int quantity);

 /** \brief This function gives the possibility of informing the user salaries and ordering
  by the criteria of surname and sector as chosen
*
* \param list eEmployee
*
* \return Return employee index position or (1) if [Invalid length or NULL
        pointer received or employee not found]
 * \param user[] eEmployee
 * \param quantity int
 *
 *
   */

int findEmployeeByIde(eEmployee user[], int quantity, int id);
 /** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (1) if [Invalid length or NULL
        pointer received or employee not found]
 * \param user[] eEmployee
 * \param quantity int
 * \param id int
 * \return int Return (1) if Error ] - (0) if Ok
 *
   */

/** \brief modifies employees through a menu gives the user the possibility to do it according to the choice of the option
 *
 * \param user[] eEmployee
 * \param quantity int
 * Return (1) if Error ] - (0) if Ok
 *
 */
int modifyEmployee(eEmployee user[], int quantity);


