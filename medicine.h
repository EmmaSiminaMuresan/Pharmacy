/***********************************************************************************************************/
/* medicine.h - Header file for pharmacy stock operations                                                  */
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
extern struct medicine;
extern struct pharmacy_med;


/* Function prototypes: */
extern void add_product();
extern void read(FILE *);
extern void insert_list_prescription();
extern void insert_quick_list();
extern void search_ql(int ,const int);
extern void search_p(int ,const int);


#endif // MEDICINE_H_INCLUDED

