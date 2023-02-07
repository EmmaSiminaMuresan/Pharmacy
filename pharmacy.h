/***********************************************************************************************************/
/* pharmacy.h - Header file for the activities that the employee can do in the pharmacy stock              */
/* Copyright: 2020                                                                                         */
/* License: Technical University of Cluj-Napoca                                                            */
/* Author: Muresan Emma Simina <siminamuresan2002@gmail.com>, Sucala Paula Ilinca <sucala.ilinca@gmail.com>*/
/* Version: 31.12.2020                                                                                     */
/***********************************************************************************************************/

#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED


/* Headers required by the following definitions/declarations: */
#include <stdlib.h>
#include <stdio.h>


/* Global variables declarations: */
int SIZE;
int SIZE_C;
float suma;


/* Used structures */
extern struct quantity;
extern struct pharmacy_med;


/* Function prototypes: */
extern void display_sch_farmacy();
extern void employee();
extern void client_employee();
extern void no_stock();
extern void stock_display();


#endif // PHARMACY_H_INCLUDED
