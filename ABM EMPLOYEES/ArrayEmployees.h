#include "fecha.h"
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


int initializeEmployee(eEmployee user[], int quantity);
/** \brief
 *
 * \param user eEmployee
 * \return void
 *
 */
void printEmployee(eEmployee user);
/** \brief
 *
 * \param user[] eEmployee
 * \param quantity int
 * \return int
 *
 */

int printEmployees(eEmployee user[], int quantity);

/** \brief
 *
 * \param user[] eEmployee
 * \param quantity int
 * \return int
 *
 */

int initEmployee(eEmployee user[], int quantity);

/** \brief
 *
 * \param user[] eEmployee
 * \param quantity int
 * \param id int
 * \return int
 *
 */
int addEmployee(eEmployee user[], int quantity, int id);
/** \brief
 *
 * \param user[] eEmployee
 * \param quantity int
 * \param id int
 * \return int
 *
 */
int findEmployeeById(eEmployee user[], int quantity, int id);
/** \brief
 *
 * \param user[] eEmployee
 * \param quantity int
 * \return int
 *
 */
int modifyEmployee(eEmployee user[], int quantity);
/** \brief
 *
 * \param user[] eEmployee
 * \param quantity int
 * \param criterionLastName int
 * \param criterionSector int
 * \return int
 *
 */
int sortEmployees(eEmployee user[], int quantity, int criterionLastName, int criterionSector);
/** \brief
 *
 * \param user[] eEmployee
 * \param quantity int
 * \return int
 *
 */
int removeEmployee(eEmployee user[], int quantity);
/** \brief
 *
 * \param user[] eEmployee
 * \param quantity int
 * \return int
 *
 */
int informationSalary(eEmployee user[], int quantity);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
